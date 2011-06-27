#include <stdio.h>
#include <rpc/rpc.h>
#include "srvr.h"

void dispatch();

#define MAXPROCS 64

#define disable(p) (mask&=~(1<<(sockets[p])))
#define enable(p)  (mask|= (1<<(sockets[p])))
int sockets[MAXPROCS];
unsigned int mask=0xffffffff;


main(){
   SVCXPRT *transp;

   int i;
   for(i=0;i<MAXPROCS;i++) sockets[i]=-1;

   transp = svcudp_create(RPC_ANYSOCK);
   if( transp == NULL ){
      fprintf(stderr,"could not create an RPC1 server\n");
      exit(1);
   }
   pmap_unset(SRVRPROG,SRVRVERS);
   if(!svc_register(transp,SRVRPROG,SRVRVERS,dispatch,IPPROTO_UDP)){
      fprintf(stderr,"could not register service 1\n");
      exit(1);
   }
   sockets[0]=transp->xp_sock;

   transp = svcudp_create(RPC_ANYSOCK);
   if( transp == NULL ){
      fprintf(stderr,"could not create an RPC2 server\n");
      exit(1);
   }
   pmap_unset(SRVRPROG,SRVRVERS+1);
   if(!svc_register(transp,SRVRPROG,SRVRVERS+1,dispatch,IPPROTO_UDP)){
      fprintf(stderr,"could not register service 2\n");
      exit(1);
   }
   sockets[1]=transp->xp_sock;

   disable(1);

   svc_run();
   fprintf(stderr,"should never reach this point!\n");
}

void dispatch(rqstp,transp) struct svc_req *rqstp; SVCXPRT *transp; {
   char *s=NULL;
   static int sem=0;
   static int cnt=0;
   switch( rqstp->rq_proc ){

      case NULLPROC:
         printf("nullproc\n");
         if(!svc_sendreply(transp,xdr_void,0)){
            fprintf(stderr,"could not reply to RPC NULL call\n");
            exit(1);
         }
         return;

      case RENDERSTR:
         sem++;
         if(sem>1){ printf("ERROR sem=%d\n",sem); exit(1); }
         enable(0);
         if(cnt>50) enable(1);
         if(!svc_getargs(transp,xdr_wrapstring,&s)){
            fprintf(stderr,"could not decode arguments in RPC render call\n");
            exit(1);
         }
         printf("got:%s\n",s);
         if(!svc_sendreply(transp,xdr_void,0)){
            fprintf(stderr,"could not reply to RPC render call\n");
            exit(1);
         }
         if(rqstp->rq_vers-SRVRVERS==1)
            if((cnt%9)==2)
               disable(0);
         cnt++;
         sem--;
         break;

      case SRVR_END:
         if(!svc_sendreply(transp,xdr_void,0)){
            fprintf(stderr,"could not reply to RPC END call\n");
            exit(1);
         }
         svc_unregister(SRVRPROG,rqstp->rq_vers);
         svc_destroy(transp);
         printf("server %d closed\n",rqstp->rq_vers-SRVRVERS);

      default :
         svcerr_noproc(transp);
         return;

   }
   svc_freeargs(transp,xdr_wrapstring,&s);
}


void svc_run()
{
   int readfds;
   for(;;){
      readfds=svc_fds&mask;
/*      printf("sel:svc_fds=%x\n",svc_fds);*/
      if( svc_fds == 0 ){
         printf("server has no services - closing\n");
         exit(0);
      }
      switch( select(32,&readfds,NULL,NULL,NULL) ){

      case -1: perror("rstat: select");
               return;

      case 0:  break;

      default:
/*             printf(" req:svc_fds=%x\n",readfds);*/
               svc_getreq(readfds);
      }
   }
}

