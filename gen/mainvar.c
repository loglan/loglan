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

      /* DATA STRUCTURES COPIED FROM LOGLAN COMPILER */
#if DEBUG
  FILE * log;
#endif
      /* compiler symbol table and memory */
int *  ipmem ;
address *  m ;     /* "SMALL" M , FOR PROTOTYPES  OR CODE  FOR ONE UNIT ONLY */

int  nblus ;              /* ADDRESS OF MAIN BLOCK IN IPMEM            */
int  nrint ;              /* ADDRESS OF TYPE INTEGER IN IPMEM          */
int  nrre  ;
                    /* ADDRESS OF TYPE REAL IN IPMEM             */
int  nrbool ;
                    /* ADDRESS OF TYPE BOOLEAN IN IPMEM          */
int  nrchr ;
                    /* ADDRESS OF TYPE CHAR IN IPMEM             */
int  nrtext ;
                    /* ADDRESS OF TYPE STRING IN IPMEM           */
int  nrcor ;
                    /* ADDRESS OF TYPE COROUTINE IN IPMEM        */
int  nrproc ;
                    /* ADDRESS OF TYPE PROCESS IN IPMEM          */
int  lpmem ;
                    /* THE LAST INDEX BELOW REAL CONSTANTS       */
int  irecn ;
                    /* LAST INDEX OF REAL CONSTANT AREA          */
int  lmem ;
                    /* ACTUAL (I.E. FROM COMPILER) SIZE OF IPMEM */
int  addrnone ;
                    /* dsw&ail*/

   /* INFORMATION ADDED INTO IPMEM :                                         */

   /* LOWER ADDRESSES ARE OCCUPIED BY COMPILER SYMBOL TABLE                  */
   /* UPPER ADDR. ARE USED IN 'CODE' FOR GENERATOR SYMBOL TABLE.             */
   /* EACH (GENERATOR) SYMBOL TABLE ITEM OCCUPIES 3 WORDS :                  */
   /*   (+0) = STITEM  ( --> CODE)                                           */
   /*   (+1) = VALUE OF CONSTANT                                             */
   /*       OR OFFSET OF TEMPORARY VARIABLE,                                 */
   /*       OR POINTER TO THE ATTRIBUTE DESCRIPTION IN COMP.SYM.TABLE        */
   /*   (+2) = NEXT USE (QADDR)                                              */

   /* PROCEDURE 'GENPROT' MODIFIES INFORMATION IN COMPILER SYMBOL TABLE.     */
   /* PROCEDURE 'CODE' NEED THE FOLLOWING EXTRA INFORMATION :                */

   /* FOR EACH UNIT:   (-1) = PROTADDR                                       */
   /*                  (+0) = ADDRESS OF 'AFTER INNER' STATEMENT             */
   /*                         ( STORED BY 'CODE' )                           */
   /* FOR EACH OBJECT ATTRIBUTE:                                             */
   /*                  (-2) = OFFSET                                         */
   /*                  (-1) = PROTADDR FOR THAT OBJECT                       */
   /* FOR EACH TYPE (CLASS TYPE, FORMAL TYPE OR PRYMITIVE TYPE):             */
   /*                  (+2) = - ADDRESS OF TYPE DESCRIPTION IN M             */

   /* MOREOVER, EXTRA INFORMATION IS STORED TO LINK REFERENCES TO THE TYPES  */
   /* ( --> BACKPATCH)                                                       */

address    base  ;                  /* TOTAL LENGTH OF JUST PRODUCED CODE;
                                       TO BE ADDED  TO  INDEX IN "SMALL" M */
address    realbase ;               /* BASE FOR REAL CONSTANTS */

dprotaddr  prefix[ MAXPROT + 1 ]  ; /* PROTOTYPE NUMBER OF PREFIX */
                                    /* OR DUMMY IF PREFIX ABSENT  */



   /* TYPES OF SOME OBJECTS  BELONGING TO THE ADDRESS TYPE HAVE BEEN CHANGED */
   /* TO INTEGER. THIS HAS BEEN FORCED DUE TO THE REQUIREMENTS OF THE PASCAL */
   /* COMPILER  ACCESSIBLE ON SIEMENS  WHICH DEMANDS THAT  THE PROCEDURE AND */
   /* FUNCTION PARAMETERS PASSED BY VARIABLE HAVE STRICTLY THE SAME TYPE  AS */
   /* THEIR FORMAL CORRESPONENTS.                            */ 

address offset;

/* Variables of code to follow */                 
/* qaddr0   qcurr ;  */     /* CURRENT QUADRUPLE */
qaddr    qlast ;       /* LAST QUADRUPLE   */
 
quadruple   tuple[ QMAX + 1 ] ;

protaddr    unitt ;    /* CURRENT UNIT */
int         ipunit ;   /* UNIT ADDRES IN  IPMEM */


int         notrick ;    /* FOR INTEGER <--> STITEM CONVERSION */

               /* M^ [ FIRSTLABEL..MEMLIMIT ] IS USED FOR HANDLING LABELS */
               /* FOR LABEL L :                                         */
               /*  M^ [ MEMLIMIT-L+1 ] < 0                                */
               /*          -->  = - VALUE OF ALREADY DEFINED LABEL         */
               /*  M^ [ MEMLIMIT-L+1 ] > 0                                */
               /*          -->  = HEAD OF UNSATISFIED REFERENCES LIST   */

int         none ;    /* ADDRESS OF 'NONE' IN SYMBOL TABLE */

int         n ;

 /*CBC added concurrent statements... */
protaddr   proclist[ MAXPROCLIST + 1 ] ;

/* mb vars from back to follow */

qaddr       ctpoint ;
bool        nouse ;



/*mb vars from gen to follow */

filename    file_name  ; /* text given by the user as a file name */

FILE *     lfile ;
                /* OUTPUT FROM LOGLAN COMPILER:                              */
                /*                                  STRINGS,                 */
                /*                                  SYMBOL TABLE,            */
                /*                                  L-CODE.                  */
                /*                                                           */
                /* PARTICULAR SECTIONS ARE SEPARATED BY '#' OCCURRING IN THE */
                /* FIRST POSITION OF LINE. ZEROS OCCURRING IN THE SYMBOL TA- */
                /* BLE ARE COMPRESSED (SEE GETITEM).                         */

/* TEMPORARY FILES: WRITEN BY GENERATOR, READ BY INTERPRETER */
FILE        * cfile ;              /* CODE AND LISTS FOR PROTOTYPES  */
FILE        * pfile ;              /* PROTOTYPES                     */

int         error ;                /* TRUE FOR FAILURE DURING GENERATION */

pointprdsc  prototype[MAXPROT + 1] ;

address     ipradr ;               /* BASE FOR PRIMITIVE TYPES DESCRIPTIONS */
address     temporary ;            /* ADDRESS OF GLOBAL TEMPORARY VARIABLES */
address     strings ;              /* BASE FOR STRING CONSTANTS             */
protaddr    lastprot ;             /* THE LAST USED PROTOTYPE NUMBER        */
address     fre ;                 /* FIRST FREE CELL IN M                  */



pointer listofref[ MAXPROT + 1 ] ;
                 /* LISTS OF REFERENCE ATTRIBUTES WITH POINTERS TO IPMEM */

longpointer listofpar[ MAXPROT + 1 ] ;
                 /* LISTS OF PRODUCED DESCRPTIONS OF FORMAL PARAMETERS   */

int opdescr[] = { 0,
 14, 15, 14, 14, 14,  0,  0,  0,  0,  0,
  8,  8,  9,  0,  9,  9,  0,  0,  0, 10,
 10, 10, 10, 10, 10, 10,  0,  0, 12, 11,
 11, 11, 11, 11, 11, 11, 12, 11, 12, 12,
 11, 11, 11,  9,  9, 11, 11, 11, 11, 11,
 11, 12, 12, 12, 12, 12, 12, 11, 11, 11,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
 11, 11, 11, 12, 12, 12, 12, 12, 12, 12,
 12, 12, 12, 12, 12, 12, 12, 12, 12, 13,
 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
 13,  1,  0,  0,  0,  0,  3,  3,  3,  2,
  2,  0,  2,  3,  4,  2,  2,  2,  3,  3,
  3,  3,  2,  0,  0,  0,  0,  2,  5,  5,
  5,  5,  5,  6,  6,  6,  0,  0,  0,  7,
  0,  0,  0,  0,  1,  0,  1,  1,  0,  0,
  1,  1,  1,  1,  0,  1,  0,  2,  4,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,
  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  2 };

