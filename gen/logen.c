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
#include <unistd.h>

#ifndef NO_PROTOTYPES

static void code(void);
static void putstmode(stmode,int *);
static void segments(void);

#else

static void code();
static void putstmode();
static void segments();

#endif

/* cas dodalem deklaracje zmiennej qcurr */
/* DO CELOW URUCHOMIENIOWYCH */
static address zmienna;
int qcurr;

static void putstmode(s,i) stmode s; int *i;{
  (*i) &= 255 ; /* CLEAR LEFT BYTE */;
  s  <<= 8 ;
  (*i) |= s ;
}

void makeproclist(){
   int p, len ;

   len  =  0  ;
   do
   {
     p  =  next() ;
     if (p)
     {
       len ++ ;
       if (p > 0)
         proclist[ len ]  =  ipmem[ p-1 ] ;
       else
         proclist[ len ]  =  -ipmem[ -p-1 ] ;
     }
   } while ( ! ( (p == 0) || (len == MAXPROCLIST) )) ;
   
   if (p)
     generror(PROCLTL) ;
   
     tuple[ qcurr ].arg[ 1 ]  =  len ;
}




static void segments(){
 /* COMPLETES THE QUADRUPLES SEGMENT */
 /* LABEL 100 ; EXIT AT END-MARKER */
        bool stop ; /* segment completed */
/*!!*/   static int op    ; /* opcode */ /* static for debugging purposes */
/*!!*/   static  int a, b  ; /* first and second argument */
     int trck2 ;
/*     int n ; */
     quadruple * curr ; /* gsg for PASCAL WITH translation */

 while (TRUE)  /* EXIT ONLY AT END-MARKER */
 {
   stop = FALSE ; /* COMPLETE THE SEGMENT */
   qcurr = 1 ;
   do      /*  WITH tuple[ qcurr ] DO BEGIN */
   { curr = tuple + qcurr ; /* gsg PASCAL WITH statement translation */

     op = next() ;  /* Fetch operator */

#if (TALK > 15)
     printf("                                op = %d\n", op) ;
#endif
if( op==210 || op==211 ){ printf("|opcode %d|\n",op); getchar(); }
    if ( (op <= 194) || (op >= 220) )
    {

      stop = ( ((172 <= op) && (op <= 176)) || ((178 <= op) && (op <= 227)) ) ;
      /* op in  [172..176, 178..227] */
      curr->opcode = op ;
      /* Now fetch arguments */
      switch (opdescr[ op ])
      {
        case 0 : break ;

        case 1 :
        case 2 :
        case 8 : curr->arg[ 1 ] = next() ;
                 break ;

        case 3 :
        case 5 :
        case 9 :
       case 11 :
       case 15 : curr->arg[ 1 ] = next() ; 
                 curr->arg[ 2 ] = next() ;
                 break ;

        case 4 :
        case 6 :
        case 7 :
        case 10 :
        case 12 :
        case 13 :
        case 14 : curr->arg[ 1 ] = next() ; 
                  curr->arg[ 2 ] = next() ; 
                  curr->arg[ 3 ] = next() ;
                  break ;
      
      } /* switch */
 
     if ( ((223 <= op) && (op <= 225)) || (op == 227) ) /*op in [223..225,227]*/
        makeproclist() ;
      qcurr ++ ;
    }
    else  /* op in 195..219 */
      if (op == 200)
        goto label100 ; /* end-marker */
      else /* SPECIAL CARE OPCODES */
      {
        a = next() ;
        ipmem[ a + 2 ] = 0 ;
        if ((op < 201 ) || (op > 204))
        { 
          b = next() ; 
          ipmem[ a+1 ] = b ;
        }
        else
          ipmem[ a+1 ] = 0 ;
               /* SET DEFAULT VALUES */
               /*SLOCAL = FALSE; SLIVE = FALSE; SMODE = TEMPVAR; SAP = APINT; */
        putslocal(FALSE,notrick) ;
        putslive(FALSE,notrick) ;
        putstmode(TEMPVAR, &notrick) ; 
        putsap(APINT,notrick) ;
        
        switch (op)
        {       /* TEMPORARY VARIABLES */
               case 201 : break ;

               case 202 : putsap(APFMTYPE,notrick) ; /* == apreal */
                          break ;

               case 203 : putsap(APFMPROC,notrick) ;
                          break ;

               case 204 :  /* reference */
                           putsap(APVIRT,notrick) ;
                           putslocal(TRUE,notrick) ;
                           break ;

               /* declared variables */
               case 205 : putstmode(VARGLOB, &notrick) ;
                          putsap(apet(b),notrick) ;
                          putslive(TRUE,notrick) ;
                          break ;

               case 206 : putstmode(VARMID, &notrick) ;  
                          putsap(apet(b),notrick) ;
                          putslive(TRUE,notrick) ;
                          break ;
 
               case 207 : putstmode(VARLOC, &notrick) ;  
                          putsap(apet(b),notrick) ;
                          putslive(TRUE,notrick) ;
                          break ;
 
               /* real or integer constant */
               case 197 : putstmode(REALCONST, &notrick) ; 
                          putsap(APREAL,notrick) ;
                          break ;

               case 198 :
               case 199 : putstmode(INTCONST, &notrick) ;
                          break ;

               /* temporary but live */
                case 195 :
                case 208 : putslocal(TRUE,notrick) ;
                           if (op==195)
                           { /* move&save */
                             trck2   = ipmem[ b ] ;
                             putsap(sap(trck2),notrick) ;
                           }
                          else /* live temporary */
                            putslive(TRUE,notrick) ;
                          curr->opcode =  60  ; /* #limove */
                           /* proper opcode will be chosen further */
                          curr->arg[ 1 ] = a ;
                          curr->arg[ 2 ] = b ;
                          qcurr ++ ;
                          break ;
        } /* switch */

        ipmem[ a ] = notrick ;
      } /* SPECIAL CARE OPCODES */
   } while ( ! (stop || (qcurr > QMAX)) ) ;

   qlast = qcurr - 1 ;
   if (! stop) 
     generror(STSEQTL) ;
   back() ; /* establish 'next-use' information */
   gen() ;
} /* while true */
 label100: ; /* end-marker : all has been done */

}



static void code(){
     /* TRANSFORMS L-CODE TO L'-CODE BY REDUCTION OF NUMBER OF OPCODES */
     /* ALLOCATES TEMPORARY VARIABLES                                    */

  /* INSERT 'NONE' INTO THE SYMBOL TABLE */
  /*cdsw&ail  NONE = LMEM-3 ;  */
   none  =  addrnone ;
 /* WITH TRICK.STI DO {  */ /* CTRP
                 SAP = APVIRT ;
                   SMODE = REALCONST ;
                   SLOCAL = TRUE ;
                   SLIVE = TRUE ;
                   } ;  */
  putsap(APVIRT,notrick) ;
  putstmode(REALCONST,&notrick) ;
  putslocal(TRUE,notrick) ;
  putslive(TRUE,notrick) ;
  ipmem [ none   ]  =  notrick ;
  ipmem [ none+1 ]  =  0 ; /* --> m [realbase] */
  ipmem [ none+2 ]  =  0 ;


 /* CLEAR THE DICTIONARY OF LABELS */

/*  memset(m + fre, (char) 0, (MEMLIMIT - fre + 1) * sizeof(address)) ;  */
   for(zmienna = fre; zmienna <= MEMLIMIT; zmienna ++)
     m[zmienna] = 0 ;
  /* zerowanie pamieci */
  /* n = MEMLIMIT ;*/

  segments() ;

 /* END OF CODE PREPARING */
}

 
void main(argc,argv) int argc; char *argv[];{

/*
  log = fopen("gen.log", "w") ;
  if (log == NULL)
    printf("cannot open dump file\n") ;
*/
  base = 0 ;

  m = (address *) calloc(sizeof(address), MEMLIMIT + 1) ;

/*   puts("") ;
   puts(" LOGLAN-82  Compiler  Version 4.00") ;
   puts(" January 10, 1993") ;
   puts(" (C)Copyright  Institute of Informatics, University of Warsaw") ;
   puts(" (C)Copyleft   LITA Universite de Pau");
   puts("\n Pass Two\n") ; fflush(stdout);
*/
   if(argc < 2){ printf("Usage : %s filename\n",argv[0]); exit(8); }
#if (TALK >= 1)
   puts("Setting files...") ; fflush(stdout);
#endif
   setfiles(argv[1]) ;
#if (TALK >= 1)
  puts("Files set");fflush(stdout);
#endif
  fre  =  2 ;                      /* SKIP TWO WORDS RESERVED FOR DUMMY VIRT. */
  m[fre++]  =  0 ; /* dsw*//* free == currfile */
  m[fre++]  =  0 ; /* place for file virtual address */ /*dsw*/
  strings  =  fre ;                    /* START STRING AREA */
#if (TALK >= 1)
  puts("Putting strings...") ; fflush(stdout);
#endif
  putstrings() ;                         /* WRITE STRINGS INTO MEMORY */
  realbase  =  fre ;                     /* BASE FOR REAL CONSTANTS */
#if (TALK >= 1)
  puts("Initiating...") ; fflush(stdout);
#endif
  initiate() ;                           /* READ IPMEM AND OTHER VARIABLES */
#if (TALK >= 3)
  {
     long seek=ftell(lfile);
     dump_lcode(argv[1]);
     fseek(lfile,seek,SEEK_SET);
  }
#endif
#if (TALK >= 1)
  puts("Putting reals...") ; fflush(stdout);
#endif
  putreals() ;                           /* WRITE REAL CONSTANTS INTO MEMORY */
#if (TALK >= 1)
  puts("Generating prototypes...") ; fflush(stdout);
#endif
  genprot() ;
  /* PROTOTYPES ARE NUMBERED MAINBLOCK..LASTPROT */
 
temporary  =  base+fre ;
fre  +=  MAXCOMTEMP + 1 ;

/* mb removed some unimportant comments to improve readability ; cf text2.gen */

#if (TALK >= 1)
 puts("Outputing...") ; fflush(stdout);
#endif
#if (TALK >= 70)
 for(zmienna = 0; zmienna < fre ; zmienna ++)
   printf("M DUMP WORD # %lu VALUE %lu\n",
          (unsigned long int)zmienna,(unsigned long int)(m[zmienna]));
#endif

 out() ;                                   /*CBC*/


/* fre == 0 */

#if (TALK >= 1)
 puts("Code preparation...") ; fflush(stdout);
#endif
 code() ; /* CODE PREPARING */


#if (TALK >= 1)
 puts("Putting debug info...") ; fflush(stdout);
#endif

/*
 ts3(argv[1]);
*/

#if (TALK >= 1)
 puts("Putting prototypes...") ; fflush(stdout);
#endif

 outprot() ; /* PUT PROTOTYPES ONTO THE FILE */

/* fclose(log) ;*/
/* *((int *)0xccL) = 0x1445 ;*/

#if (TALK >= 1)
 puts("Generation ok.") ; fflush(stdout);
#endif

}


