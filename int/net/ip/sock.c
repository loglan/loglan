#include "sock.h"


#ifndef FD_SET
#define BITS_PER_INT 32
#define FD_SET(f,fds) (fds)->fds_bits[(f)/BITS_PER_INT]|=(1<<((f)%BITS_PER_INT))
#define FD_ZERO(fds) { (fds)->fds_bits[0]=0; (fds)->fds_bits[1]=0; }
#endif



#ifdef BZERO
void bzero( buf, size ) char *buf; int size; {
   while( --size >= 0 )
      buf[size]='\0';
}
void bcopy( from, to, size ) char *from,*to; int size; {
   while( --size >= 0 )
      to[size]=from[size];
}
#endif



#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffffUL
#endif


int sock_open( socket_type, protocol, host, service, port, as_server )
   char *host;
   char *service;
   char *protocol;
   int socket_type,port;
   int as_server;
{
   int fd;
   unsigned long inaddr;
   struct sockaddr_in my_addr,it_addr,*srv_addr;
   struct servent *sp;
   struct hostent *hp;
   struct protoent *pp;

   bzero((char *)&my_addr,sizeof(my_addr));
   bzero((char *)&it_addr,sizeof(it_addr));

   my_addr.sin_family=AF_INET;
   it_addr.sin_family=AF_INET;

   my_addr.sin_port=htons(0);
   it_addr.sin_port=htons(0);

   my_addr.sin_addr.s_addr=htonl(INADDR_ANY);
   it_addr.sin_addr.s_addr=htonl(INADDR_ANY);

   if( as_server )
      srv_addr = &my_addr;
   else
      srv_addr = &it_addr;

   if( (pp=getprotobyname(protocol)) == NULL ){
      fprintf(stderr,"protocol %s unknown\n",protocol);
      return -1;
   }

   if( service != NULL ){
      if( (sp=getservbyname(service,protocol)) == NULL ){
         fprintf(stderr,"port_open:unknown service %s/%s\n",service,protocol);
         return -1;
      }
      srv_addr->sin_port = sp->s_port;
   }

   if( port>0 )
      srv_addr->sin_port = htons( port );

   if( host!=NULL )
      if( (inaddr = inet_addr(host)) != INADDR_NONE ){
         /* it is dotted-decimal address */
         bcopy((char *)&inaddr,(char *)&(srv_addr->sin_addr),sizeof(inaddr));
      } else {
         if( (hp = gethostbyname(host)) == NULL ){
            fprintf(stderr,"port_open:host name error %s\n",host);
            return -1;
         }
         bcopy(hp->h_addr,(char *)&(srv_addr->sin_addr),hp->h_length);
      }

   if( (fd = socket(AF_INET,socket_type,pp->p_proto)) < 0 ){
      perror("port_open:can't create socket");
      errno=0;
      return -1;
   }

   if( bind( fd, (struct sockaddr *)&my_addr, sizeof(my_addr) ) < 0 ){
      perror("port_open:bind error");
      errno=0;
      return -1;
   }

   if( !as_server )
      if( connect( fd, (struct sockaddr *)&it_addr, sizeof(it_addr) ) < 0 ){
         perror("port_open:connect error");
         errno=0;
         return -1;
      }

   return fd;
}


int sock_cli_send( sock, m, size ) int sock,size; void *m; {
   if( send(sock, m, size, 0) < 0) {
      perror("cli:send failed");
      errno=0;
      return -1;
   }
   return 0;
}



int sock_poll( sock, ms )  int sock,ms; {
   struct timeval timeout;
   fd_set rd_fds;
   int nfds;
   FD_ZERO(&rd_fds);
   timeout.tv_sec  = ms/1000;
   timeout.tv_usec = (ms%1000)*1000;
   if( sock>=0 )   /* sock==-1 means we only sleep */
      FD_SET(sock,&rd_fds);
   nfds = select(sock+1,&rd_fds,NULL,NULL,&timeout);
   errno=0;
   return ( nfds == 1 );
}


static int cli_recv_timeout = 2000 /* miliseconds */;

void set_cli_recv_timeout( ms )  int ms; {  /* set timeout to miliseconds */
   cli_recv_timeout = ms;
}

int  sock_cli_recv( sock, m, size ) int sock,size; void *m; {
   int recv_size;
   int nfds;
   nfds = sock_poll(sock,cli_recv_timeout);
   if( nfds==0 ){  errno=0;  return 0;  }   /* timeout */
   if( nfds<0 ){
      perror("cli:select failed");
      errno=0;
      return -1;
   }
   if( (recv_size=recv(sock, m, size, 0)) < 0) {
      perror("cli:recv failed");
      errno=0;
      return -1;
   }
   return recv_size;
}


static int srv_send_wait_time = 1;

void set_srv_send_delay( ms )  int ms; {  /* set delay to miliseconds */
   srv_send_wait_time = ms;
}

int sock_srv_send( sock, m, size, addr, namelen )
   int sock,size,namelen;
   void *m;
   struct sockaddr_in *addr;
{
   sock_poll(-1,srv_send_wait_time);
   if( sendto(sock,m,size,0,addr,namelen) <= 0) {
      perror("srv:send failed");
      errno=0;
      return -1;
   }
   return 0;
}

int  sock_srv_recv( sock, m, size, addr, namelen )
   int sock,size,*namelen;
   void *m;
   struct sockaddr_in *addr;
{
   int recv_size;
   if( (recv_size=recvfrom(sock, m, size, 0, addr, namelen )) < 0) {
      perror("srv:recvfrom");
      errno=0;
      return -1;
   }
   return recv_size;
}


