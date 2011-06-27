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

/**********************************************************/
/*             auxiliary functions for GEN                */
/*   Written according to NEW m & ipmem declarations      */
/*   Last modified : May-08-89                            */
/**********************************************************/

#ifndef NO_PROTOTYPES

int next(void);

    /* M^ [ FIRSTLABEL..MEMLIMIT ] IS USED FOR HANDLING LABELS */
    /* FOR LABEL L :                                           */
    /*  M^ [ MEMLIMIT-L+1 ] < 0                                */
    /*          -->  = - VALUE OF ALREADY DEFINED LABEL        */
    /*  M^ [ MEMLIMIT-L+1 ] > 0                                */
    /*          -->  = HEAD OF UNSATISFIED REFERENCES LIST     */



/**********************************************************/

void deflabel(int);
void begunit(int);
void uselabel(address);
void endunit(void);

int locspace(app);
void locrelease(address,app);

 /* returns offset of the new temporary variable allocated in global area */
 /*   indexed 1..maxcomtemp                                               */

 /* returns offset of the new temporary variable allocated within local area */
 /* indexed -maxloctemp .. -1         for non-reference     or               */
 /*                   0 .. maxreftemp for reference values                   */

/*  extern void locrelease(address n, app ap);  */
/* releases temporary variable of appetite ap allocated at address n */
/* within local area                                                 */


void force(argnr,addrmode,address,address);
void forceconst(argnr);
void forceprot(argnr);
void argument(argnr);

   /* void force(argnr n, addrmode m, address o1, address o2); */
   /* forces the n-th argument to be of m-mode with parameters o1,o2 */

   /* void forceconst(argnr n)  ;*/
   /* forces the n-th argument to be a constant */

  /*  extern void forceprot(argnr n);  */
   /* forces the n-th argument to be a prototype number as a constant */

  /* extern void argument(argnr n);  */
/* puts the description of the n-th argument into args[n] */
/* for temporary variables with no next use and not live  */
/*  the corresponding is released                         */

 /* static void result(argnr n);  */
 /* puts the desription of n-th argument ( being defined ) into args[n].   */
 /* for the temporary value the new space is assigned                      */

void emit(void);

void defaultargs(void);
   /* prepares default descriptions of arguments */

void esac(void);
 /* produces a description of 'case' */


#else


int next();
void deflabel();
void begunit();
void uselabel();
void endunit();
int locspace();
void locrelease();
void force();
void forceconst();
void forceprot();
void argument();
void emit();
void defaultargs();
void esac();

#endif

