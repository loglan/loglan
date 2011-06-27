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
     

=======================================================================
*/

#if WSIZE==4
	typedef long word;
#elif WSIZE==2
	typedef short word;
#else
 Define WSIZE to 2 or 4 !
#endif

char blank_[ (unsigned long)( 302 + LMEMSIZE ) * WSIZE ]; /* whole memory of compiler */


#include "stdio.h"
#include "signal.h"

#ifndef SIGIOT
#ifdef SIGTRAP
#define SIGIOT SIGTRAP
#else
#define SIGIOT SIGILL
#endif
#endif


static void sigdie(s, kill) register char *s; int kill; {
   /* print error message, then clear buffers */
   fflush(stdout);
   fflush(stderr);
   fprintf(stderr, "%s\n", s);
   fflush(stderr);

   if(kill) {
      /* now get a core */
      signal(SIGIOT, 0);
      abort();
   }
   else
      exit(1);
}

static void sigfdie(n){	sigdie("Floating Exception", 1);}
static void sigidie(n){	sigdie("IOT Trap", 1);		}
static void sigqdie(n){	sigdie("Quit signal", 1);	}
static void signdie(n){sigdie("Interrupt", 0);		}
static void sigtdie(n){	sigdie("Killed", 0);		}


int main(argc, argv) int argc; char **argv; {

   word parlen, i;
   char parbuf[128];

   signal(SIGFPE, sigfdie);	/* ignore underflow, enable overflow */
   signal(SIGIOT, sigidie);
#ifdef SIGQUIT
   if( (int)signal(SIGQUIT,sigqdie) & 01) signal(SIGQUIT, SIG_IGN);
#endif
   if( (int)signal(SIGINT, signdie) & 01) signal(SIGINT, SIG_IGN);
   signal(SIGTERM,sigtdie);

#ifdef pdp11
   ldfps(01200); /* detect overflow as an exception */
#endif

   parbuf[ 0 ] = '\0';
   for (i = 1; i < argc; i++)
   {
       strcat( parbuf, " " );
       strcat( parbuf, argv[i] );
   }
   parlen = strlen(parbuf);
   loglan_( &parlen, parbuf );

   return 0;
}

int  MAIN__( ) {  return 0; }
