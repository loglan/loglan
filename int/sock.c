     /* Loglan82 Compiler&Interpreter
     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw
     Copyright (C)  1993, 1994 LITA, Pau
     
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.
     
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
     
             You should have received a copy of the GNU General Public License
             along with this program; if not, write to the Free Software
             Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 contacts:  Andrzej.Salwicki@univ-pau.fr

or             Andrzej Salwicki
                LITA   Departement d'Informatique
                Universite de Pau
                Avenue de l'Universite
                64000 Pau   FRANCE
		 tel.  ++33 59923154	fax. ++33 59841696

=======================================================================
*/

#include <assert.h>

#include "depend.h"
#include "genint.h"
#include "int.h"
#include "process.h"
#include "intproto.h"

#include "sock.h"
#include "tcpip.h"


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


#define init_addr(addr)                       \
   bzero((char *)&(addr),sizeof(addr));       \
   (addr).sin_family=AF_INET;                 \
   (addr).sin_port=htons(0);                  \
   (addr).sin_addr.s_addr=htonl(INADDR_ANY);



int host_addr( host, buf )  char *host; struct sockaddr_in *buf; {

   long inaddr;
   int port;
   struct hostent *hp;
   char *addr;

   init_addr( *buf );

   addr = strchr( host, ':' );
   if( addr == NULL )
      port = PORT;
   else
   {
      *addr = '\0';
      addr++;
      if( *addr!='\0' )
         if( sscanf( addr, "%d", &port ) != 1 )  usage();
         else;
      else
         port = PORT;
   }

   buf->sin_port = htons( port );

                                          /* try dotted-decimal address */
   if( (inaddr = inet_addr(host)) == INADDR_NONE ){
      if( (hp = gethostbyname(host)) == NULL )
         return -1;
      assert( hp->h_length == sizeof( inaddr ) );
      bcopy( (char *)( hp->h_addr ), (char *)&( buf->sin_addr ), sizeof( inaddr ) );
   }

   return 0;
}



int sock_open( socket_type, protocol, service, port )
   char *service;
   char *protocol;
   int socket_type,port;
{
   int fd;
   struct sockaddr_in my_addr;
   struct servent *sp;
   struct protoent *pp;

   init_addr( my_addr );

   if( (pp=getprotobyname(protocol)) == NULL )
      return -1;

   if( service != NULL ){
      if( (sp=getservbyname(service,protocol)) == NULL )
         return -1;
      my_addr.sin_port = sp->s_port;
   }

   if( port>0 )
      my_addr.sin_port = htons( port );

   if( (fd = socket(AF_INET,socket_type,pp->p_proto)) < 0 )
      return -1;

   if( bind( fd, (struct sockaddr *)&my_addr, sizeof(my_addr) ) < 0 )
      return -1;

   return fd;
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
   if( ms >= 0 )
      nfds = select(sock+1,&rd_fds,NULL,NULL,&timeout);
   else
      nfds = select(sock+1,&rd_fds,NULL,NULL,NULL);
   errno=0;
   return ( nfds == 1 );
}



static int send_wait_time = 0;

void set_send_delay( ms )  int ms; {  /* set delay to miliseconds */
   send_wait_time = ms;
}

int sock_send( sock, buf, size, addr )
   int sock,size;
   void *buf;
   struct sockaddr_in *addr;
{
   int namelen = sizeof( *addr );
   if( send_wait_time > 0 )
      sock_poll( -1, send_wait_time );
   if( sendto( sock, buf, size, 0, addr, namelen ) <= 0 ){
      fprintf(
              stderr,
              "socket send to %s:%d\n",
              inet_ntoa( addr->sin_addr ),
              (int)ntohs( addr->sin_port )
             );
      perror("send error");
      abend("send error");
   }
   return 0;
}

int  sock_recv( sock, buf, size, addr )
   int sock,size;
   void *buf;
   struct sockaddr_in *addr;
{
   int recv_size;
   int namelen = sizeof( struct sockaddr_in );
   if( ( recv_size = recvfrom( sock, buf, size, 0, addr, &namelen ) ) < 0 ){
      perror("recv");
      return -1;
   }
   if( namelen != sizeof( struct sockaddr_in ) ){
      printf("str sockaddr_in %d namelen %d\n",sizeof(struct sockaddr_in),namelen);
      printf("addr %s\n",inet_ntoa(addr->sin_addr));
      abend("strenge message");
   }
   return recv_size;
}



