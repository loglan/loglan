#include "sock.h"
#include "srv.h"
#include <sys/stat.h>

struct sockaddr_in it;
int sock, namelen, seq = 0;

#ifndef NO_PROTOTYPES
int main(int argc,char **argv);
#endif

int main(argc,argv) int argc; char** argv; {
   msg m;

   if( argc>1 ){
      set_srv_send_delay( atoi(argv[1]) );
      printf("delay set to %d ms\n",atoi(argv[1]));
   }

   fclose(stdin);

   {
      int retval=fork();
      if( retval<0 )  perror("fork failed"),exit(0);
      if( retval>0 )  exit(0);
   }

   setpgrp();
   freopen("srv.log","a",stdout);
   freopen("srv.log","a",stderr);

   sock = sock_open( SOCK_DGRAM, "udp", NULL, NULL, PORT, AS_SERVER );
   if( sock < 0 ){
      perror("sockopen");
      fflush(stdout);
      fflush(stderr);
      exit(10);
   }

   if (fork())  exit(0);

   for ( ;; ) {

      int namelen = sizeof(it);
      int size;

      fflush(stdout);
      fflush(stderr);

      size=sock_srv_crc_recv(sock, &m, sizeof(m), &it, &namelen );

      if( size>0 )   /* there was no error & I'm not interested in 0 size */
      switch( ntohl(m.req) ){

         case RQ_FILE_SIZE  :
                    {
                       struct stat status;
                       if( stat(m.data,&status) ) status.st_size=0;
                       m.req=htonl(0);
                       printf("file %s size %d\n",m.data,status.st_size);
                       fflush(stdout);
                       fflush(stderr);
                       *(int*)(m.data)=htonl(status.st_size);
                       sock_srv_crc_send(sock,&m,HEAD+sizeof(int),&it,namelen);
                    }
                    break;

         case RQ_FILE :
                    {
                       FILE *f=fopen(m.data+2*sizeof(int),"rb");
                       int size,cnt=0;
                       int packets = ntohl(((int *)m.data)[1]);
                       int seek=ntohl(((int *)m.data)[0]);
                       int errors=0;
                       if( f==NULL ) break;
                       printf("file %s from %d %d packets\n",
                              m.data+2*sizeof(int),seek,packets);
                       fflush(stdout);
                       fflush(stderr);
                       fseek(f,DATA_PIECE*seek,0);
                       while( (size=fread(m.data,1,DATA_PIECE,f)) > 0 ){
                          m.req=htonl(seek++);
                          cnt++;
                          if(sock_srv_crc_send(sock,&m,HEAD+size,&it,namelen)<0)
                             errors++;
                          else
                             errors=0;
                          if( errors>=10 ) break;
                          if( cnt==packets )  break;
                       }
                       fclose(f);
                       while( sock_poll( sock, 0 ) )
                          sock_srv_crc_recv(sock,&m,sizeof(m),&it,&namelen);
                    }
                    break;

         default:
                    printf("srv:unknown req %d\n",ntohl(m.req));

      }
   }

   return 0;
}

