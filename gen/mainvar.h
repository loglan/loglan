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

#if DEBUG
  extern FILE * log ;
#endif  
      /* DATA STRUCTURES COPIED FROM LOGLAN COMPILER */


extern int nblus ;	/* ADDRESS OF MAIN BLOCK IN IPMEM            */
extern int nrint ;	/* ADDRESS OF TYPE INTEGER IN IPMEM          */
extern int nrre  ;	/* ADDRESS OF TYPE REAL IN IPMEM             */
extern int nrbool;	/* ADDRESS OF TYPE BOOLEAN IN IPMEM          */
extern int nrchr ;	/* ADDRESS OF TYPE CHAR IN IPMEM             */
extern int nrtext ;	/* ADDRESS OF TYPE STRING IN IPMEM           */
extern int nrcor ;	/* ADDRESS OF TYPE COROUTINE IN IPMEM        */
extern int nrproc ;	/* ADDRESS OF TYPE PROCESS IN IPMEM          */
extern int lpmem ;	/* THE LAST INDEX BELOW REAL CONSTANTS       */
extern int irecn ;	/* LAST INDEX OF REAL CONSTANT AREA          */
extern int lmem ;	/* ACTUAL (I.E. FROM COMPILER) SIZE OF IPMEM */
extern int addrnone ;

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

extern address    base  ;           /* TOTAL LENGTH OF JUST PRODUCED CODE;
                                       TO BE ADDED  TO  INDEX IN "SMALL" M */
extern address    realbase ;               /* BASE FOR REAL CONSTANTS */

extern dprotaddr  prefix[ MAXPROT + 1 ]  ; /* PROTOTYPE NUMBER OF PREFIX */
                                    /* OR DUMMY IF PREFIX ABSENT  */



   /* TYPES OF SOME OBJECTS  BELONGING TO THE ADDRESS TYPE HAVE BEEN CHANGED */
   /* TO INTEGER. THIS HAS BEEN FORCED DUE TO THE REQUIREMENTS OF THE PASCAL */
   /* COMPILER  ACCESSIBLE ON SIEMENS  WHICH DEMANDS THAT  THE PROCEDURE AND */
   /* FUNCTION PARAMETERS PASSED BY VARIABLE HAVE STRICTLY THE SAME TYPE  AS */
   /* THEIR FORMAL CORRESPONENTS.                                            */ 
/* from addressing taken offset : */
extern address offset;
extern int opdescr[];

extern protaddr lastprot;
extern address ipradr;
extern pointprdsc prototype[];
extern pointer listofref[];
extern longpointer listofpar[];
extern protaddr unitt ;
extern int ipunit ;
extern int loctmp ;
extern int reftmp ;
extern tmpmap ltmpmap ;
extern tmpmapdscr * mapdscr[] ;
extern bool rtmpmap[] ;
extern bool gtmpmap[] ;
extern qaddr0 qcurr ;
extern qaddr ctpoint ;
extern bool nouse ;
extern qaddr qlast ;
extern int notrick ;
extern address temporary ;
extern protaddr proclist[] ;
extern int none ;
extern address strings ;
extern int n ;
extern FILE * lfile ;
extern FILE * pfile ;
extern FILE * cfile ;

