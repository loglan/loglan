#include "sock.h"

#ifndef NO_PROTOTYPES
static int get_crc( char *data, int data_size );
#else
static int get_crc();
#endif


static char buffer[8192];   /* shouldn't be bigger message */


int sock_cli_crc_send( sock, m, size ) int sock,size; void *m; {
   *(int *)buffer = htonl(get_crc( m, size ));
   bcopy( m, buffer+sizeof(int), size );
   return sock_cli_send( sock, buffer, size+sizeof(int) );
}

int sock_cli_crc_recv( sock, m, size ) int sock,size; void *m; {
   int recv_size;
   recv_size = sock_cli_recv(sock, buffer, size+sizeof(int) );
   if( recv_size == 0 ) return 0;
   else
   if( recv_size < sizeof(int) ) return -1;
   else{
      recv_size-=sizeof(int);
      bcopy( buffer+sizeof(int), m, recv_size );
      if( get_crc(m,recv_size)!=ntohl(*(int *)buffer) )
         return -1;  /* error */
      else
         return recv_size;
   }
}

int sock_srv_crc_send( sock, m, size, addr, namelen )
   int sock,size,namelen;
   void *m;
   struct sockaddr_in *addr;
{
   *(int *)buffer = htonl(get_crc( m, size ));
   bcopy( m, buffer+sizeof(int), size );
   return sock_srv_send( sock, buffer, size+sizeof(int) , addr, namelen );
}

int  sock_srv_crc_recv( sock, m, size, addr, namelen )
   int sock,size,*namelen;
   void *m;
   struct sockaddr_in *addr;
{
   int recv_size;
   recv_size = sock_srv_recv(sock, buffer, size+sizeof(int), addr, namelen );
   if( recv_size == 0 ) return -1;
   else
   if( recv_size < sizeof(int) ) return -1;
   else{
      recv_size-=sizeof(int);
      bcopy( buffer+sizeof(int), m, recv_size );
      if( get_crc(m,recv_size)!=ntohl(*(int *)buffer) )
         return -1;  /* error */
      else
         return recv_size;
   }
}



static int get_crc( data, data_size ) char *data; int data_size; {
   int i;
   unsigned long crc=0L;
   for( i=0; i<data_size; i++,data++ ){
      crc ^= (unsigned long)(unsigned char)(*(char *)data);
      if( crc&1 )
         crc = ( crc<<1 ) | 1;
      else
         crc = ( crc<<1 );
   }
   return crc;
}

