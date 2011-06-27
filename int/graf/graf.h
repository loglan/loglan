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

#ifndef NULL
#define NULL (void *)0
#endif


void pascal gron( int * );
void pascal groff( void );
void pascal cls( void );
void pascal point( int *, int * );
void pascal move( int *, int * );
void pascal draw( int *, int * );
void pascal hfill( int * );
void pascal vfill( int * );
void pascal color( int * );
void pascal style( int * );
void pascal patern( int *, int *, int *, int * );
void pascal intens( int * );
void pascal pallet( int * );
void pascal border( int * );
void pascal video( char * /* normalized */ );
void pascal hpage( int *, int *, int * );
int  pascal nocard( void * /* NULL */ );
void pascal pushxy( void );
void pascal popxy( void );
int  pascal inxpos( void * /* NULL */ );
int  pascal inypos( void * /* NULL */ );
int  pascal inpix( int *, int * );
	
void pascal getmap( int *, int *, char * /* normalized */ );
void pascal putmap( char * /* normalized */ );
void pascal  ormap( char * /* normalized */ );
void pascal xormap( char * /* normalized */ );
	
void pascal track( int *, int * );
int  pascal inkey( void * /* NULL */ );
void pascal hascii( int * );
void pascal hfont( int *, int * );
void pascal hfont8( int *, int * );
void pascal outhli( int *, char * );
void pascal cirb( int *, int *, int *, float *, float *, int *, int *, int *, int * );


