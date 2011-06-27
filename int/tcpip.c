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

#include "depend.h"
#include "genint.h"
#include "int.h"
#include "process.h"

#include "sock.h"
#include "tcpip.h"

#include <assert.h>


static int sock;

static int slaves=0;
static struct addr {
   int console;
   struct sockaddr_in addr;
} *phone_book;


#define MAX_NODES 256
static int node2book[ MAX_NODES ];    /* only 256 nodes - can be changed */


static void sock_recv_from( void *, int, struct sockaddr_in * );
static void sock_recv_from( buf, buflen, from_addr )
   int buflen;
   void *buf;
   struct sockaddr_in *from_addr;
{
   struct sockaddr_in addr;
   int retval;
   for(;;){
      if( ( retval = sock_recv( sock, buf, buflen, &addr ) ) < 0 )
         perror("receive"),abend("no answer from master");
      if(
         from_addr->sin_port != addr.sin_port
         ||
         from_addr->sin_addr.s_addr != addr.sin_addr.s_addr
         ||
         buflen != retval
        )
         fprintf( stderr, "unexpected message from %s:%d length %d\n",
                inet_ntoa( from_addr->sin_addr ),
                (int)ntohs( from_addr->sin_port ),
                retval
               );
      else
         break;
   }
}

                                                 /* nn.nn.nn.nn:port address */
void tcpip_connect_to_master( addr )  char *addr; {

   char *host = addr;
   int namelen;
   int aux;
   struct sockaddr_in m_address;

   for( aux = 0; aux < MAX_NODES; aux++ )
      node2book[ aux ] = -1;

   if( host_addr( host, &m_address ) < 0 ){
      perror("invalid host name:");
      usage();
   }

   sock = sock_open( SOCK_DGRAM, "udp", NULL, 0 ); /* any port */
   if( sock < 0 )  perror("can't open any socket"),exit(10);

   {
      struct sockaddr_in addr;
      int namelen = sizeof(struct sockaddr_in);
      getsockname( sock, &addr, &namelen );
      fprintf( stderr, "socket opened on %s:%d\n",
              inet_ntoa(addr.sin_addr),
              (int)ntohs(addr.sin_port)
            );
   }

   aux = htonl( console );
   sock_send( sock, &aux, sizeof(aux), &m_address );
   fprintf(
           stderr, "waiting for acknowledge from %s:%d\n",
           host, (int)ntohs( m_address.sin_port )
          );

   sock_recv_from( &aux, sizeof(aux), &m_address );
   slaves = ntohl( aux );
   fprintf( stderr, "answer from master: %d interpreters\n", slaves );

   phone_book = (struct addr *)calloc( slaves, sizeof( struct addr ) );
   if( phone_book==NULL )  abend("can't allocate table of addresses");

   sock_recv_from( &aux, sizeof(aux), &m_address );
   phone_book[0].console = ntohl( aux );
   phone_book[0].addr = m_address;

   fprintf( stderr, "master console %d at %s:%d\n",
           phone_book[0].console,
           inet_ntoa(phone_book[0].addr.sin_addr),
           (int)ntohs(phone_book[0].addr.sin_port)
         );

   node2book[ phone_book[ 0 ].console ] = 0;

   {
      int i;
      for( i=1; i<slaves; i++ ){  /* on 0 will be master */

         sock_recv_from( &aux, sizeof(aux), &m_address );
         phone_book[i].console = ntohl( aux );
         sock_recv_from(
                        &(phone_book[i].addr),
                        sizeof(struct sockaddr_in),
                        &m_address
                       );
         fprintf( stderr, "interpreter %d connected at %s:%d\n",
                 phone_book[i].console,
                 inet_ntoa(phone_book[i].addr.sin_addr),
                 (int)ntohs(phone_book[i].addr.sin_port)
               );
         node2book[ phone_book[ i ].console ] = i;

      }
   }
   fprintf( stderr, "\nprogram started\n\n" );
}




void tcpip_wait_for_slaves( _slaves )  int _slaves; {

   int aux;
   int slave_console;
   struct sockaddr_in slave_address;
   int namelen = sizeof(struct sockaddr_in);

   for( aux = 0; aux < MAX_NODES; aux++ )
      node2book[ aux ] = -1;

   slaves = _slaves+1;

   phone_book = (struct addr *)calloc( slaves, sizeof( struct addr ) );
   if( phone_book==NULL )  abend("can't allocate table of addresses");

   sock = sock_open( SOCK_DGRAM, "udp", NULL, PORT );
   if( sock < 0 )  perror("master socket"),abend("can't install master");

   phone_book[0].console = console;
   getsockname( sock, &(phone_book[0].addr), &namelen );
   assert( namelen == sizeof( struct sockaddr_in ) );

   fprintf( stderr, "waiting for %d slaves on console %d at %s:%d\n",
           _slaves,
           phone_book[0].console,
           inet_ntoa(phone_book[0].addr.sin_addr),
           (int)ntohs(phone_book[0].addr.sin_port)
         );

   node2book[ console ] = 0;

   while( _slaves > 0 ){

      if( sock_recv( sock , &slave_console, sizeof(slave_console), &slave_address ) < 0 )
         perror("server receive"),abend("can't connect slave");

      fprintf( stderr, "slave %d connected at %s:%d\n",
              ntohl(slave_console),
              inet_ntoa(slave_address.sin_addr),
              (int)ntohs(slave_address.sin_port)
            );

      slave_console = ntohl( slave_console );

      phone_book[_slaves].console = slave_console;
      phone_book[_slaves].addr    = slave_address;

      if( node2book[ slave_console ] != -1 ){
         fprintf( stderr, "node %d already bound\n", slave_console );
         abend("exiting");
      }
      node2book[ slave_console ] = _slaves;

      _slaves--;

   }

   fprintf( stderr, "all slaves notified - sending acknowledges\n" );

   {
      int i,j;
      for( i=1; i<slaves; i++ ){

         aux = htonl(slaves);
         sock_send( sock, &aux, sizeof(aux), &(phone_book[i].addr) );

         aux = htonl(console);
         sock_send( sock, &aux, sizeof(aux), &(phone_book[i].addr) );

         for( j=1; j<slaves; j++ ){
            aux = htonl(phone_book[j].console);
            sock_send( sock, &aux, sizeof(aux), &(phone_book[i].addr) );
            sock_send(
                      sock,
                      &(phone_book[j].addr),
                      sizeof(struct sockaddr_in),
                      &(phone_book[i].addr)
                    );
         }
      }
   }

   fprintf( stderr, "\nprogram started\n\n" );
}


void tcpip_send( msg )  message *msg; {
   int node = msg->control.receiver.node;
   int ix = node2book[ node ];
   if( ix == -1 ){
      fprintf( stderr, "tcpip send message to not existing node %d\n", node );
      abend("exiting");
   }
/*
   fprintf( stderr, "tcpip send message to node %d indx %d\n", node, ix );
*/
   sock_send(
             sock,
             msg,
             sizeof( message ),
             &( phone_book[ ix ].addr )
            );
}

bool tcpip_poll( ms )  int ms; {
   return sock_poll( sock, ms );
}

bool tcpip_recv( msg )  message *msg; {
   int retval;
   struct sockaddr_in addr;
   if( ( retval = sock_recv( sock, msg, sizeof( message ), &addr ) ) < 0 ){
      perror("receive");
      return FALSE;
   }
/*
   if( retval == sizeof( message ) )
      fprintf(stderr,"tcpip recv message from node %d\n",msg->control.sender.node);
   else
      fprintf(stderr,"tcpip recv incorrect message from node %d\n",msg->control.sender.node);
*/
   return ( retval == sizeof( message ) );
}



