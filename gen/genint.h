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

#if GEN
#define word address
#endif


/* Appetites of values : */
#define APINT           1     /* integer,boolean,string,char */
#define APREAL          sizeof(real)/sizeof(word)    /* real */
#define APVIRT          4     /*  TO TELL APART A VIRTUAL ADDRESS            */
                              /*   (ANY REFERENCE TYPE)  FROM ANY OTHER TYPE */
#define APREF           2     /* ACTUAL SIZE OF REFERENCE TYPE               */
#define APFMTYPE        2     /* FORMAL TYPE VALUE                           */
#define APFMPROC        3     /* FORMAL PROCEURE OR FUNCTION VALUE, = APREF+1*/
#define APOPCODE	(sizeof(extopcode)+sizeof(word)-1)/sizeof(word)


typedef int bool;
#define FALSE           0
#define TRUE            1


/* Values identifying types and formal parameters : */

#define FORMFUNC        7       /* parameter "function" */
#define FORMPROC        8       /* parameter "procedure" */
#define FORMTYPE        9       /* parameter "type", also formal type */
#define PARIN           11      /* parameter "input" */
#define PAROUT          12      /* parameter "output" */
#define PARINOUT        16      /* parameter "inout" */
#define PUREPROCESS     13      /* type PROCESS */
#define PURECOROUTINE   14      /* type COROUTINE */
#define PRIMITIVETYPE   15      /* simple type */
#define CLASSTYPE       17      /* class type */
#define FILETYPE        18      /* file type */


/* Values to identify kinds of array elements : */

#define AINT            -1      /* arrayof integer */
#define AREAL           -3      /* arrayof real */
#define AVIRT           -2      /* arrayof reference */
#define APROCESS        -4      /* process reference implemented as arrayof */
#define FILEOBJECT      -11     /* file object */
#define SKILLED         -99     /* killed object, only for compactification */


#define DUMMY           -1      /* dummy unit or prefix : SL for main block */
#define MAINBLOCK       0       /* main block prototype number */
#define MAXPROT         500     /* limit for the number of prototypes */


/* L-code instruction addressing modes : */

#define GLOBAL          0       /* M[ N ]                */
#define LOCAL           1       /* M[ c1+N ]             */
#define TEMPLOCAL       2       /* M[ c2+N ]             */
#define REMOTE          3       /* M[ M[ K ]+N ]         */
#define INDIRECT        4       /* M[ M[ N ] ]           */
#define IMMEDIATE       5       /* N                     */
#define CONSTANT        6       /* M[ N ]                */
#define DOTACCESS       7       /* M[ M[ display+K ]+N ] */
#define NOARGUMENT      8       /* ------                */


/* Prototype kind : */

#define CLASS           0
#define RECORD          1
#define COROUTINE       2
#define PROCESS         3
#define BLOCK           4
#define PREFBLOCK       5
#define FUNCTION        6
#define PROCEDURE       7
#define HANDLER         8

#if GEN
#define LRECORD    RECORD
#define LFUNCTION  FUNCTION
#define LPROCEDURE PROCEDURE
#endif


#if GEN
typedef   int   protaddr ;   /* mainblock..maxprot ; mainblock = 0; */
                             /* INDIRECT ADDRESS OF PROTOTYPE       */
typedef   int   dprotaddr ;  /* PROTADDR + DUMMY                    */
typedef   int   protkind ;
#else
#define protaddr  int
#define dprotaddr int
#define protkind  int
#endif


/* Prototype : */

typedef struct {
    dprotaddr slprototype ;   /* PROTOTYPE OF SYNTACTIC FATHER */
                              /* OR DUMMY FOR THE MAIN BLOCK   */
    word codeaddr;            /* address of code */
    word appetite;            /* object's total length */
    word span;                /* distance from beginning of object to */
                              /* temporary reference variables */
    word reflist;             /* beginning and length of table with */

    int lthreflist;           /* offsets of reference values in object; */
                              /* without SL, DL, CL and temporary values */
    word parlist;             /* beginning and length of table with */
    int lthparlist;           /* offsets of parameters */

    word preflist;            /* beginning and length of table with */
    int lthpreflist;          /* prototype numbers of prefix sequence */

    word lastwill;            /* lastwill code address */
    word handlerlist;         /* list of handlers, 0 if empty */
    word virtlist;            /* address of table for conversion: */
                              /*     virtual number --> prototype */

    /* only for processes : */
    protaddr  maskbase ;      /* lowest procedure prototype number */
    int       masksize ;      /* size of RPC mask for that process */

    /* for procedures and functions */
    int virtnumber;           /* virtual number or -1 if not virtual */

    /* for all : */
    protkind  kind ;          /* kind of unit */

    /* only for procedures, functions and processes : */
    word pfdescr;             /* address of table with parameters descr. addresses */

    /* only for functions : */
    int nrarray;
    word finaltype;  /* type of result */

} protdescr,*pointprdsc;


