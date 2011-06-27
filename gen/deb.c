/*     Loglan82 Compiler&Interpreter
     Copyright (C) 1993 Institute of Informatics, University of Warsaw
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

#include <stdio.h>
#include "glodefs.h"


#ifndef NO_PROTOTYPES

static long hash_search(char *);
static int ord(char);

#else

static long hash_search();
static int ord();

#endif



/* ===================== for debugger ======================== */
/*        files organization :                                 */
/* fil21 ( .DEB ) :                                            */
/*       hash(maxhash),						*/
/*       idict(maxidict), ind, prot(ind)                       */
/* dfile ( .DCD ) :                                            */
/*       hash(maxhash),						*/
/*       idict(maxidict), protbreakl, ind, prot(ind)           */

#define maxhash 8000
#define maxidict 500

static int idict[maxidict];  /* dictionary of prototypes */
static int *prot;	   /* array of prototypes  */
static int ind; 	/* last used in PROT */

void db3(){
  /* put dispnr and offset into prototypes */
   int i=0,j,pr,prz,el;

   while( i < maxidict ){

      if( idict[i] != 0 ){

	/* pr - address of zero word of the prototype */
	 pr = idict[i];
	/* dispnr */
	 prot[pr+3] = i;
	/* hash table of prototype */
	 for( j = pr+5 ; j <= pr+12 ; j++){

	    el = prot[j];
            prz = prot[el];
	   /* el - address of zero word of list element */
    	    while( prz != -100 ){

	       if( prot[el+1] % 8 < 4 ){     /* not not taken */

		  prz = prot[el+2];
		 /* prz - address of debugger protype */
		  if( prz < -15 ){ 		/* variable or constant */

		     prz = -prz;
		     if( prot[prz] == 5 )	 /* variable */
			prot[prz+3] = ipmem[prot[prz+3] - 2];
	          }
	       }
	       el = el+3;
	       prz = prot[el];  /* next element */
	    } /* while */
         } /* for */
      }
      i++;
   } /* while */
}

long hash[8000];

void  ts3( fname )  char *fname; {

   /* wpisuje dispnr i offset do prototypow debuggera */
   /* czyta prototypy z pliku fil21, pisze na dfile */

   FILE *fil21;		/* input - prototypes from TS2 */

   char fnameaux[30];
   long position;

   strcpy( fnameaux, fname );
   fil21 = fopen( strcat( fnameaux, ".deb" ) , "rw" );
   fseek( fil21, maxhash * sizeof(int) ,0 );
   fread( idict, sizeof(*idict), maxidict, fil21 );
   fread( &ind, sizeof(ind), 1, fil21 );
  /* reading  PROT */
   position = ftell( fil21 );
   prot=(int *)calloc(ind+1,sizeof(int));
   fread( prot+1, sizeof(int), ind*4, fil21 ); 
  /* changing prototypes  */
   db3();
  /* writing  PROT */
   fseek( fil21, position, 0 );
   fwrite( prot+1, sizeof(int), ind*4, fil21 );
fseek( fil21, 0L, 0);
fread( hash, 8000, sizeof(long), fil21 );
printf("searching do for begin aaa ala i nikldksjkehtr");getchar();
printf("#%ld",hash_search("do"));getchar();
printf("#%ld",hash_search("for"));getchar();
printf("#%ld",hash_search("begin"));getchar();
printf("#%ld",hash_search("aaa"));getchar();
printf("#%ld",hash_search("ala"));getchar();
printf("#%ld",hash_search("i"));getchar();
printf("#%ld",hash_search("niksehfkertk"));getchar();
   fclose( fil21 );
   free(prot);
}

/* ======================================================== */

#define BYTE 64
#define M 1009

static long hash_search (str) char *str;{

   long name[21];
   int result;
   int i=0;
   int H;   /* do poszukiwan po hash */
   int N;   /* do przechodzenia po name */

 /*  pakowanie nazwy do poszukiwan w hash */

   for( i=0; i<20 && *str!='\0'; i++ )
      if( i % 2 == 0 )   name[ i/2 ] = ord( *( str++ ) );
      else               name[ i/2 ] = name[ i/2 ] * BYTE + ord( *( str++ ) );

   name[ (i+1)/2 ]= -1 ;
   i= i/2 + i%2;
   H = ( name[0] % M ) * 2;

   for(;;){
printf("comparing name H=%d,name[0]=%d",H,name[0]);getchar();

      N=0;
      result = H;

      while( hash[ H+1 ]  <0  &&  hash[ H ] == name[ N ] ){
printf("Nth pare OK %d",N);getchar();

         H = - hash[ H+1 ] - 1;
         N++;

      }

      if( hash[ H ] != name[ N ] ){

         while( hash[ H+1 ] <0 )   H = - hash[ H+1 ] - 1;
         if( hash[ H+1 ] == 0 )  return -1;
         H = hash[ H+1 ] - 1;
         continue;

      }

      if( name[ N+1 ] == -1 )  return result;
      if( hash[ H+1 ] ==  0 )  return -1;

      H = hash[ H+1 ] - 1;

   }

} 


static int ord_tab[]={
63,63,63,63,63,63,63,63,36,63,63,63,37,
36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,
63,43,63,63,63,63,44,52,53,48,39,
42,40,38,41,0,1,2,3,4,5,6,7,8,9,47,45,50,49,51,63,63,
10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35,63,63,63,63,46,
63,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35
};

static int ord(c) char c;{
   if( c>122 )  return 63;
   return ord_tab[ c-1 ];
}


