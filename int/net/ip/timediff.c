#include "sock.h"

char m[100];
int sock;

char *host;


#ifndef NO_PROTOTYPES
int main(int argc,char **argv);
#endif

static int bytes_received=0;
static char title[100];


static void usage(s) char *s;{
   printf("usage: %s host\n",s);
   exit(0);
}


static int host_time( host )
   char *host;
{
   int size=0;
   int time;
   int sock = sock_open( SOCK_STREAM, "tcp", host, "time", 0, AS_CLIENT );
   if( sock>=0 ){
      size=sock_cli_recv(sock,&time,sizeof(int));
      close( sock );
   }
   if( size == sizeof(int) ) return ntohl(time);
   else return 0;
}


int main(argc,argv) int argc; char** argv; {

   int uid=getuid();

   if( argc != 2 )  usage(argv[0]);
   host = argv[1];

   printf("STARTED\n");

   for(;;sleep(60*15)){

      int local,remote,i;
      long diff;
      struct timeval delta,olddelta;
      struct timeval time_before,time_after;

      errno=0;

      for( i=0; i<3; i++ ){

         if( gettimeofday(&time_before,NULL) ){
            perror("gettimeofday:");
            if( uid!=0 )  return 1;
            continue;
         }

         local = host_time( "localhost" );
         remote= host_time( host        );

         if( gettimeofday(&time_after ,NULL) ){
            perror("gettimeofday:");
            if( uid!=0 )  return 1;
            continue;
         }

         diff  = (time_after.tv_sec - time_before.tv_sec)*1000;
         diff -= time_before.tv_usec/1000;
         diff += time_after .tv_usec/1000;
         if( diff >=0  &&  diff < 300 )  break;

      }

      if( i==3 ){
         printf("transaction too long ( %dms ) or errors in time\n",diff);
         fflush(stdout);
         fflush(stderr);
         if( uid==0 )
            continue;
      }

      if( remote==0 ){
         printf("error in connect to %s\n",host);
         fflush(stdout);
         fflush(stderr);
         if( uid!=0 )  return 1;
         continue;
      }
      if( local==0 ){
         printf("error in connect to %s\n","localhost");
         fflush(stdout);
         fflush(stderr);
         if( uid!=0 )  return 1;
         continue;
      }

      delta.tv_sec=remote-local;
      delta.tv_usec=0;

      if( delta.tv_sec!=0 ){
         if( delta.tv_sec >  1 ) delta.tv_sec =  1;
         else
         if( delta.tv_sec < -1 ) delta.tv_sec = -1;
         else{
            if( delta.tv_sec == 1 ) delta.tv_usec =  500000;
            else                    delta.tv_usec = -500000;
            delta.tv_sec = 0;
         }
         if( uid==0 )
         if( adjtime(&delta,&olddelta)<0 ) perror("adjtime error:");
      }

      {
         extern char *ctime();
         extern time_t time();
         time_t t=time(NULL);
         char *c=ctime(&t);
         if( c[strlen(c)-1]=='\n' )  c[strlen(c)-1]='\0';
         if( remote > local )
            printf("at %s(%dms) time on %s is %u s forward\n",
                   c,diff,host,remote-local);
         if( remote < local )
            printf("at %s(%dms) time on %s is %u s late\n",
                   c,diff,host,local-remote);
         if( uid != 0  &&  remote == local )
            printf("at %s(%dms) time on %s is equal\n",c,diff,host);
      }

      fflush(stdout);
      fflush(stderr);

      if( uid!=0 )  return 0;

   }

   return 0;
}

