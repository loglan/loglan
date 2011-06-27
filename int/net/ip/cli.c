#include "sock.h"
#include "srv.h"
#include "graph.h"

msg m;
int sock;

char *host;
char *file;
char *dest;
FILE *fdest;


#ifndef NO_PROTOTYPES
int main(int argc,char **argv);
#endif

static int bytes_received=0;
static char title[100];


static void usage(s) char *s;{
   printf("usage: %s [-ms] host file [dest_file]\n",s);
   exit(0);
}


int main(argc,argv) int argc; char** argv; {

   int  file_size,file_packets,size,x,y;

   if( argc < 3  ||  argc > 5 )  usage(argv[0]);

   if( argv[1][0]=='-' ){
      int i;
      set_cli_recv_timeout( atoi(argv[1]+1) );
      printf("timeout set to %d ms\n",atoi(argv[1]+1));
      for( i=1; i<argc-1; i++ )  argv[i]=argv[i+1];
      argc--;
   }

   host = argv[1];
   file = argv[2];

   if( argc > 3 )
      dest = argv[3];
   else
      dest = file;

   do{

      printf("ask for %s:%s\n",host,file);

      sock = sock_open( SOCK_DGRAM, "udp", host, NULL, PORT, AS_CLIENT );
      if( sock<0 ) exit(10);
      m.req   = htonl( RQ_FILE_SIZE );
      strcpy( m.data, file );
      sock_cli_crc_send( sock, &m, HEAD+strlen(m.data)+1 );
      size = sock_cli_crc_recv( sock, &m, sizeof(m) );
      close( sock );

      if( size>0 ){
         file_size = ntohl(*(int *)(m.data));
         if( file_size < 0 )
            printf("file %s:%s not found\n",host,file),exit(0);
      }else
      if( size<0 )
         printf("error in packet\n");
      else
         printf("timed out\n");

   }while( size<=0 );

   fdest = fopen(dest,"wb");
   if( fdest==NULL ){
      printf("can't open file %s for writing\n",dest);
   }

   file_packets = (file_size+DATA_PIECE-1)/DATA_PIECE;

   {
      int i;
      for(i=0;i*i<file_packets;i++);
      x=i;
      y=i;
      if(i*i>file_packets){
         x=i;
         y=i;
         while(x*y>file_packets) y--;
         if(x*y<file_packets) y++;
      }
   }

   sprintf(title,"%s:%s(%d b,pkt=%d b)",host,file,file_size,DATA_PIECE);
   graph_on(x,y,title);
   graph_board(file_packets);

   {
      extern void *calloc();
      char *tab=calloc(1,file_packets);
      while( !get_part( tab , file_packets ) );
   }

   fclose(fdest);

   graph_off();

   printf("received %d bytes for file %s size %d\n",
          bytes_received,file,file_size
         );

   return 0;
}



int get_part( file_table , file_packets ) char *file_table; int file_packets; {

   int i=0,cnt=0,pos;
   int skip_dupls=0,after_skip=0;

   for( ; i<file_packets; i++ )
      if( file_table[i]=='\0' )
         break;

   pos = i;

   if( i == file_packets )  return 1;

   for( ; i<file_packets; i++ )
      if( file_table[i]!='\0' )
         break;
      else
         cnt++;

   after_skip = cnt;

   while( i < file_packets ){

      for( ; i<file_packets; i++ )
         if( file_table[i]=='\0' )
            break;
         else
            skip_dupls++;

      if( i==file_packets )  break;

      for( ; i<file_packets; i++ )
         if( file_table[i]!='\0' )
            break;
         else
            after_skip++;

      /* if now we add skip_dupls & after_skip we will have duplicates */
      /* but maybe with lower cost ! */

      if( skip_dupls < after_skip )
         cnt = skip_dupls + after_skip ;
      else
         break;

   }

   printf("ask for %d packets, seek from %d file %s:%s\n",cnt,pos,host,file);
   
   sock = sock_open(SOCK_DGRAM,"udp",host,NULL,PORT,AS_CLIENT);
   if( sock<0 ) exit(10);

   m.req   = htonl( RQ_FILE );
   ((int *)m.data)[0] = htonl( pos );		/* seek position */
   ((int *)m.data)[1] = htonl( cnt );		/* no of packets */
   strcpy(m.data+2*sizeof(int),file);
   sock_cli_crc_send(sock,&m,HEAD+2*sizeof(int)+strlen(m.data+2*sizeof(int))+1);

   for(;;){
      int packno;
      int size=sock_cli_crc_recv( sock, &m, sizeof(m) );
      if( size==0 ) break;  /* timeout */
      if( size>0 ) bytes_received += size;
      packno=ntohl(m.req);
      if( packno<0 || packno>=file_packets )  continue;
      if( file_table[packno]!='\0' ){
         continue;
      }
      if( size>0 ){
         size-=HEAD;
         fseek(fdest,packno*DATA_PIECE,0L);
         if( fwrite(m.data,size,1,fdest)!=1 ){
            printf("can't write file %s\n",file);
            exit(10);
         }
         graph_point(packno,GRAPH_COL_OK);
         file_table[packno]='\1';
      }else    /* error in packet */
         graph_point(packno,GRAPH_COL_ERROR);
   }

   close( sock );

   return 0;
}

