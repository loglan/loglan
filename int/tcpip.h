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

#ifndef __TCPIP_H__
#define __TCPIP_H__

#ifndef NO_PROTOTYPES
void tcpip_connect_to_master( char * ); /* nn.nn.nn.nn:port address */
void tcpip_wait_for_slaves( int );      /* slaves number            */
void tcpip_send( message * );
bool tcpip_poll( int miliseconds );     /* < 0  ->  blocks indefinitely */
bool tcpip_recv( message * );
#else
void tcpip_connect_to_master();
void tcpip_wait_for_slaves();
void tcpip_send();
bool tcpip_poll();
void tcpip_recv();
#endif

#define PORT 3600

#endif


