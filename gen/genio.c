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

#include "glodefs.h" 

#ifndef NO_PROTOTYPES

static void fputaddr(FILE *,address);
static int fgetint(FILE *);

#else

static void fputaddr();
static int fgetint();

#endif

int wordswritten = 0 ;

void setfiles(name) char *name;{
 char work[80];
 
 strcpy(work, name) ;
 strcat(work, ".lcd") ;
/* printf("Fopen lcd: %s\n", work); fflush(stdout); */
 lfile = fopen(work, "rb");
 if(lfile == NULL) 
 { puts(strcat("Couldn't open file ", work)) ;
   exit(8) ; 
 }
/* puts("lcd opened.");fflush(stdout);*/
 strcpy(work, name) ;
 strcat(work, ".pcd") ;
/* puts("Fopen pcd");fflush(stdout);*/
 pfile = fopen(work, "wb") ;
 
 strcpy(work, name) ;
 strcat(work, ".ccd") ;
 cfile = fopen(work, "wb") ;
 if(cfile == NULL) 
 { 
   printf("Couldn't open file %s for writing\n", work);
   exit(8) ; 
 }
} /* setfiles */
 


int next(){
   int i;

   if(!fread((char *)&i,sizeof(i),1,lfile)){
      printf("Unexpected EOF ! Aborting...\n");
      exit(8);
   }
   return i;
} /* next */

static int fgetint(f) FILE * f;{
   int c ;
   fread((char *)&c, sizeof(int), 1, f) ;
   return c ;
}

static void fputaddr(f,v) FILE *f; address v;{
   fwrite((char *)&v, sizeof(address), 1, f);
}
 
   /* Buffered version - not finished   
 static    address   buf[BUFSIZE] ;
 static  address * bufp = buf;
 static  int       n = 0;
 
 if(n==BUFSIZE)   */
 
void putstrings()
{
 int  cc, i, ch2 ;
 int c1, c2, start, nr=1 ;
 
     cc = fgetint(lfile);                    /* character count */

     while (cc != ENDOFSTRINGS)
     {
      m[ fre ] = cc;
       fre ++ ;
       start=fre;

       for (i = 1; i <= (cc / CHARSINAD + 1) ; i++ )
          /* extra 0 byte after string */
       {

#if SMALL || HUGE
        ch2 = fgetint(lfile) ;
        m[ fre ] = ch2;
#elif LARGE
        c1 = fgetint(lfile) ;
	c2 = fgetint(lfile) ;
        m[ fre ] = ( (long)c1 ) | ( ((long)c2) << 16 ) ;
#endif

         fre++ ;
       }

#if (TALK >= 2)
       if(fre!=start+1)
	 printf("string %d = %s\n", nr++, (char *)(&m[start]));
#endif

       cc = fgetint(lfile) ;
     }
   } /* putstrings */


void initiate()
   /* read ipmem and some variables from the blank common of the compiler */
{
  int tarr[302];
#ifdef DUMP
  int  k;
#endif
  fread((char *)tarr, sizeof(int), 302, lfile) ;
  

     lmem   = tarr[278] ;
     lpmem  = tarr[279] ;
     irecn  = tarr[280] ;
     nrint  = tarr[285] ;
     nrre   = tarr[286] ;
     nrbool = tarr[287] ;
     nrchr  = tarr[288] ;
     nrcor  = tarr[289] ;
     nrproc = tarr[290] ;
     nrtext = tarr[291] ;
     nblus  = tarr[296] ;
     addrnone = tarr[299] ;   /*cdsw&ail */

#if (TALK >= 2)
     printf("Initiate\n lmem = %d, lpmem = %d, irecn = %d\n",
	    lmem, lpmem, irecn);
     printf(" nrint = %d\n", nrint);
     printf(" nrre  = %d\n", nrre );
     printf(" nrbool= %d\n", nrbool);
     printf(" nrchr = %d\n", nrchr);
     printf(" nrcor = %d\n", nrcor);
     printf(" nrproc= %d\n", nrproc);
     printf(" nrtext= %d\n", nrtext);
     printf(" nblus = %d\n", nblus);
     printf(" addrnone = %d\n", addrnone);
#endif

     ipmem = (int *) calloc(lmem + 1, sizeof(int));
     fread( (char *)(ipmem + 1), sizeof(int), irecn, lfile);
   
#ifdef DUMP
   for (k = 1; k <= irecn; k++)
   {
     printf("%8d",ipmem[k]);
     if (k % 16 == 0) printf("\n");
   }
   exit(0);
#endif

 }


void putreals()
 /* WRITE REAL CONSTANTS TO MEMORY */
{
  int i  ;
  union 
  {
    float      r ;
    struct { int int1, int2 ; } p;
  }  trick1 ;

  union 
  {
    real   r ;
    struct { address int1, int2 ; } p;
  }  trick2 ;

  i = lpmem + 1 ;
  while (i <= irecn)
  {
#ifdef HUGE
#if (TALK >=2 )
    printf("real %10d:%18f\n",i,*(float *)&(ipmem[i]));
#endif
    m[ fre++ ] = ipmem[ i++ ] ; 
#else
    trick1.p.int1 = ipmem[ i++ ] ; 
    trick1.p.int2 = ipmem[ i++ ] ;
    trick2.r = trick1.r;
#if (TALK >=2 )
    printf("real %10d:%18f\n",i,trick1.r);
#endif
    m[ fre++ ] = trick2.p.int1;
    m[ fre++ ] = trick2.p.int2;
#endif
  }
}/* putreals */




void generror(err)
errtype err;
{
     switch (err)
     {
      case    TMPROT  : printf(" TOO MANY PROTOTYPES");
              break ;

      case     TLDESCR : printf(" DESCRIPTIONS TOO LONG");
              break ;

      case        MEMOVF  : printf(" MEMORY OVERFLOW ");
              break ;

      case        TMTEMP  : printf(" TOO MANY TEMPORARY VARIABLES NEEDED");
              break ;

      case        STSEQTL : printf(" STATEMENT SEQUENCE TOO LONG");
              break ;

      case        NOTIMPL : printf(" FUNCTION NOT IMPLEMENTED");
              break ;

      case        OBJTOLG : printf(" OBJECT TOO LONG");
              break ;

      case        PROCLTL : printf(" PROCEDURE LIST TOO LONG ") ;
              break ;
     } /* switch */

     exit(4);

   } /* generror */




void out(){
   /* PUT THE CONTENTS OF M^[  0 .. fre-1  ] ON THE FILE "CFILE" */
   /* 'BASE$ IS UPDATED AND 'fre' IS RESET TO ZERO              */

   address n,w;

#if (TALK > 2)     
   printf("Writing %4d words of code\n", fre) ;
#endif

   for (n=0; n <= fre-1; n++ ){
      w = m[ n ];
      fputaddr(cfile, w);
      wordswritten ++ ;
   }

   base += fre;
#if (TALK > 3)
   printf("base = %d\n", base) ;
   printf("fre = %d\n", fre) ;
#endif
   fre = 0;
}


void outprot()
{
  protaddr  n ;
  address   lp ;

  for (n = MAINBLOCK; n <= lastprot; n++)
    fwrite( (char *)(prototype[ n ]), sizeof(*(prototype[0])), 1, pfile);

  fputaddr(cfile,ipradr);
  fputaddr(cfile,temporary);
  fputaddr(cfile,strings);
  lp = lastprot;
  fputaddr(cfile, lp);
  fputaddr(cfile,base);
}


int apet(ip)           /* STRONGLY MACHINE DEPENDENT */
int ip ;
{
   return  ( iand( ishft( ipmem [ ip ],-14 ), 3 ) + 1 );
}


