#include <stdio.h>
#include <rpc/rpc.h>
#include "srvr.h"
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

main(argc,argv) int argc; char **argv; {
   struct hostent *hp;
   struct timeval pertry_timeout,total_timeout;
   struct sockaddr_in server_addr;
   int addrlen;
   int sock=RPC_ANYSOCK;
   CLIENT *client;
   enum clnt_stat clnt_stat;
   int vers;

   if(argc < 3) fprintf(stderr,"usage:%s hostname version\n",argv[0]),exit(-1);
   vers=(int)atol(argv[2]);

   if((hp=gethostbyname(argv[1]))==NULL)
      fprintf(stderr,"cannot get addr for %s\n",argv[1]),exit(-1);

   pertry_timeout.tv_sec  = 10;
   pertry_timeout.tv_usec = 0;

   addrlen = sizeof( struct sockaddr_in );
   {
      int i;
      for( i=0; i<hp->h_length ; i++ )
         ((char *)(&server_addr.sin_addr))[i] = hp->h_addr[i];
   }

   server_addr.sin_family = AF_INET;
   server_addr.sin_port   = 0;

   total_timeout.tv_sec  = 20;
   total_timeout.tv_usec = 0;

   if((client=clntudp_create(&server_addr,SRVRPROG,SRVRVERS+vers,total_timeout,&sock))==NULL){
      perror("clntudp_create in stop");
      exit(-1);
   }

   clnt_stat=clnt_call(client,NULLPROC, xdr_void,NULL, xdr_void,NULL,
                       total_timeout);

   if( clnt_stat != RPC_SUCCESS ){
      clnt_perror( client, "rpc clnt call" );
      exit(-1);
   }

   clnt_stat=clnt_call(client,SRVR_END, xdr_void,NULL, xdr_void,NULL,
                       total_timeout);

   if( clnt_stat != RPC_SUCCESS ){
      clnt_perror( client, "rpc" );
      exit(-1);
   }

   clnt_destroy( client );
}
