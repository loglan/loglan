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
#include <string.h>

#ifndef NO_PROTOTYPES
#include <stdlib.h>
#endif


/*#define DEBUG  0  Defined for debugging time, undefine when ready */
/*#define LOG(i) fprintf(log,"%s #%d : m[%d]=%d\n",__FILE__,__LINE__,i+base,m[i])*/
#define LOG(i)

#define MAXINT 32767

#define new(s) calloc(1, sizeof(*s))
 /*cmb  It is calloc here, because we want untouched fields to be 0 */
 /*     rather than a random value                              cmb */

#if SMALL
#define MEMLIMIT 32000     /* small memory for main */
typedef float real;
typedef int address;       /* APOPCODE == 2 -  appetite of extended opcode  */

#elif LARGE
#define MEMLIMIT 16000
typedef long address;      /* APOPCODE == 1  */
typedef double real;

#elif HUGE
#define MEMLIMIT 32000
typedef long address;      /* APOPCODE == 1  */
typedef double real;

#else
#error Define one of SMALL/LARGE/HUGE
#endif


#define CHARSINAD ( sizeof(address) )     /* number of characters in word */


/*    compiler symbol table and memory    */
extern int *ipmem;
extern address *m;
extern address fre,base,firstlabel;

#define MEMORYSIZE 32000  /* CODE AND ALL RUNNING-SYSTEM DATA STRUCTURES      */
#define MAXCOMTEMP 100    /* NUMBER OF GLOBAL TEMPORARY VARIABLES             */
#define MAXLOCTEMP 100    /* LIMIT FOR THE NUMBER OF LOCAL TEMPORARY VARIABLES*/
#define MAXREFTEMP 30     /* LIMIT FOR THE NUMBER OF LOCAL TMP. REF.VARIABLES */
#define MAXAPPT    32767  /* MAXIMUM APPETITE (EASILY EXTENSIBLE)             */
#define MAXPARAM   10


/*     SIMPLE TYPES ARE DISTINGUISHED BY THEIR OFFSET FROM "IPRADR" */
#define TINT      0
#define TREAL     1
#define TBOOLEAN  2
#define TCHAR     3
#define TCOROUT   4
#define TPROCESS  5
#define TSTRING   6
#define TFUNC2    7 /* parameter "function" of parameter  */
#define TPROC2    8 /* parameter "procedure" of parameter */
#define TFILE     9


#define CURRFILE  2    /* constant address of a current file virtual address */

#define MAXNAME  70    /* file name length */


#define GEN 1
#include "genint.h"

typedef  int addrmode ;      /* gsg it was an enumeration */

typedef  char  argdescr[4] ;

typedef  struct {
   argdescr args ;    /* ARGS[0] IS OPCODE */
} extopcode ;         /* EXTENDED OPCODE   */

  /* mb think up removing record extopcode */

/************************************************************/
/*      b32b16c = record  32-bit integer
                case boolean of
                true :  ( b32 : longint
                false : ( r16 : integer
                          l16 : integer
                         )
                end; */

typedef union {
     struct { long int b32 ; } t ;
          struct { int r16, l16 ; }  f ;
        }  b32b16c ;

/*      ieopc   = record
                case integer of
                  0 : (int1,int2 : integer);
                  1 : (int : longint);
                  2 : (eop : extopcode  );
                end;         */

typedef union {
          struct { int int1f, int2f ; } c0 ;
     struct { long int intf ; }    c1 ;
     struct { extopcode eop ; }    c2 ;
   } ieopc ;
/************************************************************/
typedef     char filename[ MAXNAME + 1 ] ;


/* mb declarations from main to follow...*/

#define     ENDOFSTRINGS  -1       /* end of strings section marker */

typedef     int    errtype ;       /* gsg previously enumeration */
#define     TMPROT      0          /* TOO MANY PROTOTYPES                 */
#define     TLDESCR     1          /* DESCRIPTIONS TOO LONG               */
#define     MEMOVF      2          /* MEMORY OVERFLOW                     */
#define     TMTEMP      3          /* TOO MANY TEMPORARY VARIABLES NEEDED */
#define     STSEQTL     4          /* STATEMENT SEQUENCE TOO LONG         */
#define     NOTIMPL     5          /* FUNCTION NOT IMPLEMENTED            */
#define     OBJTOLG     6          /* OBJECT TOO LONG                     */
#define     PROCLTL     7          /* PROCEDURE LIST TOO LONG             */

typedef struct {
                  unsigned int ap : 2  ; /* 0..3 */
                  unsigned int l  : 1  ; /* 0..1 */
                  unsigned int ft : 1  ; /* 0..1 */
                  unsigned int v  : 1  ; /* 0..1 */
                  unsigned int s  : 3  ; /* 0..7 */
                  unsigned int zp : 4  ; /* 0..15 */
                  unsigned int t  : 4  ; /* 0..15 */

                }  csti ; /*     : SYMBOL TABLE ITEM, 16 bits long */


typedef union {
                int icstic_int ;
                csti cst ;

              }   icstic ;


   /* mb genprot declarations to follow */

typedef int logitem ;    /* loglan items */  /* gsg previously enumeration */
#define ICLASS        0
#define IRECORD       1
#define ICOROUT       2
#define IPROCESS      3
#define IBLOCK        4
#define IPREFBLOCK    5
#define IFUNC         6
#define IPROC         7
#define IHANDLER      8
#define IFMPROC       9
#define IFMFUNC       10
#define IFMTYPE       11
#define IPARIN        12
#define IPAROUT       13
#define IPARINOUT     14
#define IVAR          15
#define ICONST        16
#define ISIGNAL       17

typedef int logunit ; /* iclass .. ifmfunc */ /* LOGLAN UNITS TOGETHER WITH FORMAL */
                                              /* FUNCTION AND FORMAL PROCEDURE   */


        /* AUXILIARY */



typedef struct s1 {
                    int          ip ;          /* ADDRESS IN IPMEM */
                    struct s1 *  prevelem ;    /* PREVIOUS ELEMENT */

                  } listelem  ;  /* LIST OF PARAMETERS OR OF REFERENCE ATTRIBUTES */

typedef listelem *  pointer ;



typedef struct s2 {
                    address      ip ;        /* ADDRESS IN IPMEM */
                    struct s2 *  prevelem ;  /* PREVIOUS ELEMENT */

                  } longlistelem ; /* list of parameters or of reference attributes */

typedef longlistelem  * longpointer ;


/* mb declarations of code to follow */

#define  QMAX  2400          /* MAXIMAL LENGTH OF THE QUADRUPLES SEQUENCE */
#define  TEMPGUARD  103     /* = MAXCOMTEMP + MAXIMAL APPETITE           */

/*CBC added concurrent statements... */
#define  MAXPROCLIST  30    /* maximum length of procedure ident. list   */


typedef  int  qaddr ;       /* 1..QMAX */
typedef  int  qaddr0 ;      /* 0..QMAX */   /* 0 FOR NO NEXT USE */
typedef  int  argnr ;       /* gsg na razie int; moze wystarczy char ?; 1..3 */
typedef  int  app ;         /*  APINT..APVIRT */

typedef  struct {
                  int     opcode ;
                  int     arg[4] ;
                  qaddr0  nxtuse[4] ;
                } quadruple ;

extern quadruple tuple[];

typedef  int  stmode ;      /* gsg previously enumeration */
#define  VARGLOB       0    /* GLOBAL VARIABLE                        */
#define  VARLOC        1    /* LOCAL VARIABLE                         */
#define  VARMID        2    /* MIDDLE LEVEL VARIABLE                  */
#define  TEMPVAR       3    /* TEMPORARY VARIABLE                     */
#define  INTCONST      4    /* CONSTANT: INTEGER,CHAR,BOOLEAN,STRING  */
#define  REALCONST     5    /* REAL CONSTANT                          */


typedef    struct {
                    unsigned int  smode:4;
                    unsigned int    sap:3;
                            /* APPETITE, DISTINGUISHING REFERENCES         */
                    unsigned int  slive:1;
                            /* TRUE, IF USED OUTSIDE THE ADDRESSING SCOPE */
                    unsigned int slocal:1;
                             /* TRUE --> MUST BE ALLOCATED IN OBJECT      */
                             /* FALSE --> MAY BE ALLOCATED IN GLOBAL AREA    */

                  }  stitem ;  /* SYMBOL TABLE ITEM */
               /* totalling 9 bits , less then 1 word */


/*    ISTIC =*/ /* INTEGER <--> SYMBOL TABLE ITEM CONVERSION */
/*             RECORD*/
/*            CASE BOOLEAN OF*/
/*            TRUE : ( INT : INTEGER );*/
/*            FALSE: ( STI : STITEM  )*/
/*            END;*/

typedef   bool tmpmap[ MAXLOCTEMP + 1 ] ;

typedef   struct {
                   tmpmap map ;
                   int locsize ; /* 0..MAXLOCTEMP  */
                   int refsize ; /* -1..MAXREFTEMP */

                 } tmpmapdscr ;
#define ishft(i, n)    (( (n) > 0) ? ((i) << (n)) : ((i) >> -(n)))

#define  iand(i,j) ((int)((i) & (j)))

#define  ior(i,j)  ((int)((i) | (j)))

typedef struct {
   addrmode  mode ;
   address   off1 ;
   address   off2 ; /* FOR REMOTE ONLY */
} args_struct ;

extern args_struct args[4];


#define putsap(s, i) i = (i & 0xff03) | ((s) << 2)

#define sap(i) ((i) & 255) >> 2

#define putslive(b, i) ((b) ? (i |= 2) : (i &= -3))

#define slive(i) (bool)((i & 2) == 2)

#define putslocal(b, i) ((b) ? (i |= 1) : (i &= -2))

#define slocal(i) (bool)((i & 1) == 1)

#define smode(i) ((stmode)(i >> 8))

#include "mainvar.h"
#include "oxen.h"


#ifndef NO_PROTOTYPES

void out(void);
void outprot(void);
void back(void);
void backpatch(int,address);
void generror(errtype);
void addtolist(pointer *,int);
void longaddtolist(longpointer *,address);
void gen(void);
void genprot(void);
void handlers(void);
void initiate(void);
void lists(void);
void primdescr(void);
void pdescr(void);
void putreals(void);
void putstrings(void);
void setfiles(char *);
void reserve(address);
logitem itemkind(int);
int apet(int);
void dump_lcode(char *);
void makeproclist(void);

#else

void out();
void outprot();
void back();
void backpatch();
void generror();
void addtolist();
void longaddtolist();
void gen();
void genprot();
void handlers();
void initiate();
void lists();
void primdescr();
void pdescr();
void putreals();
void putstrings();
void setfiles();
void reserve();
logitem itemkind();
int apet();
void dump_lcode();
void makeproclist();

#endif

