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

#ifndef __SOCK_H__
#define __SOCK_H__

#include <stdio.h>
#include <string.h>

#ifndef NO_PROTOTYPES
#include <stdlib.h>
#endif

#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>


#ifndef NO_PROTOTYPES
int host_addr( char * /* host name */, struct sockaddr_in * );
int  sock_open( int socket_type, char *protocol, char *service, int port );
int  sock_recv( int sock, void *buf, int size, struct sockaddr_in *addr );
int  sock_send( int sock, void *buf, int size, struct sockaddr_in *addr );
void set_send_delay  ( int miliseconds );
int  sock_poll( int sock, int miliseconds );
                   /* sock == -1       -> equivalent of sleep */
                   /* miliseconds < 0  -> waits indefinitely  */
#else
int  host_addr();
int  sock_open();
int  sock_srv_recv();
int  sock_srv_send();
void set_send_delay();
int  sock_poll();
#endif


#ifndef NO_PROTOTYPES
int  sock_crc_recv( int sock, void *m, int size, struct sockaddr_in *addr );
int  sock_crc_send( int sock, void *m, int size, struct sockaddr_in *addr );
#else
int  sock_srv_crc_recv();
int  sock_srv_crc_send();
#endif

#endif




