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


static int do_rs( socket_type, protocol, host, service )
   int socket_type;
   char *host,*service,*protocol;
{
   int size=0;
   int sock = sock_open( socket_type, protocol, host, service, 0, AS_CLIENT );
   if( sock>=0 ){
      if( !sock_cli_send( sock, m, 1 ) ){
         size=sock_cli_recv(sock,m,sizeof(m));
         if( size>=0 )
            printf("packet size %d\n",size);
      }
      close( sock );
   }
   return ( size > 0 );
}


int main(argc,argv) int argc; char** argv; {

   int  size;

   if( argc != 2 )  usage(argv[0]);
   host = argv[1];
   printf("ask for time on %s\n",host);

   set_cli_recv_timeout( 5000 );

   if( do_rs( SOCK_DGRAM, "udp", host, "time" ) )
      printf("time on %s is %u s\n",host,ntohl(*(int *)m));

   if( do_rs( SOCK_DGRAM, "udp", host, "daytime" ) )
      printf("daytime on %s is %s\n",host,m);

   if( do_rs( SOCK_STREAM, "tcp", host, "time" ) )
      printf("time on %s is %u s\n",host,ntohl(*(int *)m));

   if( do_rs( SOCK_STREAM, "tcp", host, "daytime" ) )
      printf("daytime on %s is %s\n",host,m);

   if( do_rs( SOCK_STREAM, "tcp", host, "ntp" ) )
      printf("daytime on %s is %s\n",host,m);

   return 0;
}

