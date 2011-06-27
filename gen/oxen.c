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
/*   Last modified : Mar-01-90                            */
/**********************************************************/

#include <memory.h>
#include "glodefs.h"

address firstlabel;

 /*  static void globrelease(address n, app ap);  */
 /*  releases temporary variable with appetite ap and  */
 /*  address n within global area                     */


#ifndef NO_PROTOTYPES

static void globrelease(address,app);
static int globspace(app);
static void result(argnr);

#else

static void globrelease();
static int globspace();
static void result();

#endif



args_struct args[4];
    /* M^ [ FIRSTLABEL..MEMLIMIT ] IS USED FOR HANDLING LABELS */
    /* FOR LABEL L :                                           */
    /*  M^ [ MEMLIMIT-L+1 ] < 0                                */
    /*          -->  = - VALUE OF ALREADY DEFINED LABEL        */
    /*  M^ [ MEMLIMIT-L+1 ] > 0                                */
    /*          -->  = HEAD OF UNSATISFIED REFERENCES LIST     */


bool        gtmpmap[ TEMPGUARD + 1 ] ;
               /* MAP OF GLOBAL NON-REFERENCE TEMPORARY VARIABLES  */
               
bool        rtmpmap[ MAXREFTEMP + 1 ] ;
               /* MAP OF (LOCAL) REFERENCE TEMPORARY VARIABLES     */
               
tmpmap      ltmpmap ;
               /* MAP OF (LOCAL) NON-REFERENCE TEMPORARY VARIABLES */
               /* TRUE STANDS FOR AVAILABLE WORD, FALSE FOR OCCUPIED ONE */
               
int         loctmp ;   /* MAXIMAL NUMBER OF ALREADY USED WORDS FOR
                          LOCAL (NON-REFERENCE) TEMPORARY VARIABLES */
                          
int         reftmp ;   /* MAXIMAL NUMBER-1 OF ALREADY USED PAIRS OF WORDS
                          FOR REFERENCE TEMPORARY VARIABLES         */

tmpmapdscr *  mapdscr[ MAXPROT + 1 ] ;
                      /* FOR CLASS ONLY : MAP OF TEMPORARIES USED AT 'INNER' */

qaddr0 qcurr;
/**********************************************************/



void deflabel(lab)
int lab;
 /* DEFINES NEW LABEL AND SATISFIES REFERENCES (IF ANY) */
{
  address  n, k ;

  n = MEMLIMIT - lab + 1;
  if (n < firstlabel)
    if (n < fre)
      generror(MEMOVF) ;
    else
      firstlabel = n ;
  k = m [ n ] ;
  m [ n ] =  -(fre+base);
  while (k > 0)
  {
    n = m [ k ] ;
    m [ k ] = fre + base ;
    k = n ;
  }
} /* DEFLABEL */


void uselabel(lab) address lab;{
  address  n ;		/* MAINTAINS THE USE OF LABEL LAB AT ADDRESS fre */

  n = MEMLIMIT - lab + 1 ;
  if (n < firstlabel)
    if(n < fre)  generror(MEMOVF) ;
    else         firstlabel = n ;
  if (m [ n ] < 0) /* ALREADY DEFINED */ 
    m [ fre ] =  -m [ n ] ;
  else  /* ADD TO THE LIST OF UNSATISFIED REFERENCES */
  {
    m [ fre ] = m [ n ] ;
    m [ n ] = fre ;
  }

} /* USELABEL */



/* THE BEGINNING OF UNIT DESCRIBED AT 'IP' */

void begunit(ip) int ip;{
   int i,k;
   pointprdsc  prot = prototype[ipmem[ ip - 1 ]];

   unitt = ipmem[ ip-1 ] ;
   ipunit = ip ;

   prot = prototype[unitt] ;
   prot->codeaddr = fre + base;
   if (prot->lthpreflist > 1){  /* prefixed unit */

      k  =  prefix[ unitt ];
      /*  ltmpmap =  mapdscr[k]->map ;*/
      for (i=0; i<= MAXLOCTEMP; i++)  ltmpmap[i] = mapdscr[k]->map[i];

      loctmp =  mapdscr[k]->locsize ;
      reftmp =  mapdscr[k]->refsize ;

   }else{

      for (k = 1; k<= MAXLOCTEMP; k++)  ltmpmap[k] = TRUE;  /* index negated */
       
      /*     fillword(ltmpmap + 1, (char) TRUE, MAXLOCTEMP) ;

      k = MAXLOCTEMP ; */
     
      loctmp = 0 ;
      reftmp =  -1 ;
   } 

   for (k = 0; k <= MAXREFTEMP; k++)  rtmpmap[ k ] = TRUE ; 
      
   /*    memset(rtmpmap, (char) TRUE, MAXREFTEMP + 1) ;*/
    
   for (k = 1; k <= TEMPGUARD; k++)  gtmpmap[ k ] = TRUE ; 
      
   /*    memset(gtmpmap + 1, (char) TRUE, TEMPGUARD) ; */
    

   firstlabel = MEMLIMIT; /* IN FACT, MEMLIMIT+1 */

   m[0]=m[MEMLIMIT]=0;
   /* for (k = 0; k <= MEMLIMIT; k++)  m[k]=0;  */
   /* memset( (char *)m, 0, (MEMLIMIT + 1)*sizeof(m[0]) ); */
}

void endunit(){
  address systsize;
  pointprdsc prot;
  tmpmapdscr *mapd;

  out() ;
  /* with prototype[ unitt ] ^ do*/
  { prot = prototype[ unitt ] ;
   if(unitt != MAINBLOCK) 
   if ((prot->kind == CLASS) || (prot->kind == LRECORD)
    || (prot->kind == COROUTINE) || (prot->kind == PROCESS))
    /*with mapdscr[ unitt ]^ do*/
    { mapd = mapdscr[unitt] ;
      mapd ->locsize = loctmp ;
      mapd ->refsize = reftmp ;
    }
    switch(prot->kind)
    {
      case LRECORD : systsize = 0 ;
                     break ;
      case CLASS :
      case BLOCK :
      case PREFBLOCK : systsize = 2*(APREF+APINT) ;
                                                   /* sl, dl, lsc, status sl */
                       break ;
      case LFUNCTION :
      case LPROCEDURE : systsize = 3*APREF+2*APINT ; 
                                            /* sl, dl, rpcdl, lsc, status sl */
                        /*cbc add rpcdl field for procedures and functions...*/
                        break ;                    
      case COROUTINE : systsize =  3*APREF+2*APINT ;
                                             /* sl, dl, cl,  lsc, status sl  */
                       break ;
      case PROCESS : systsize =  5*APREF+2*APINT+2*(lastprot+1);
                  /* sl, dl, cl, chd, virtsc, lsc, statsl, display, display2 */
                     break;
      case HANDLER : systsize = 2*APREF+3*APINT ;
                                        /* sl, dl, lsc, status sl, signal nr */
                     break ;
    } /* switch */
    prot->span = prot->appetite + loctmp;
    prot->appetite = prot->span + (reftmp + 1) * APREF + systsize;
     if (prot->appetite > MAXAPPT)
       generror(OBJTOLG);
   } /* with prototype */;

   /* clear dictionary of labels */
   for(systsize =  firstlabel; systsize <= MEMLIMIT; systsize++)
     m [ systsize ] =  0 ; 
     
   /* memset(m+firstlabel, (char)0, (MEMLIMIT-firstlabel+1)*sizeof(address)); */
}
 
 
static int globspace(ap) app ap;{

 /* returns offset of the new temporary variable allocated in global area */
 /*   indexed 1..maxcomtemp                                               */

  int  n ;  /* 0..tempguard;*/
  
  n = 0 ;
  switch(ap)
  {
    case  1 : while (!gtmpmap[ ++n ]) ; /*not guarded */
              if (n > MAXCOMTEMP)
                generror(TMTEMP) ;
              else 
                gtmpmap[ n ] = FALSE;
              break ;
   case   2 : do
              {
                n++ ;
                n++ ;
              }
              while (!(gtmpmap[ n ] && gtmpmap[ n+1 ])) ;
            if (n >= MAXCOMTEMP )
              generror(TMTEMP) ;
            else
            {
              gtmpmap[ n ] = FALSE ;
              gtmpmap[ n + 1 ] = FALSE  ;
            }
            break ;
    case  3 : do
              n += 3 ;
            while(!(gtmpmap[ n ]  &&  gtmpmap[ n+1 ]  &&  gtmpmap[ n+2 ])) ;
            if (n > MAXCOMTEMP - 2)
              generror(TMTEMP) ;
            else
            {
              gtmpmap[ n ] = FALSE ; 
              gtmpmap[ n+1 ] = FALSE ;
              gtmpmap[ n+2 ] = FALSE ;
            }
            break ;
   } /* switch */;

   return(n) ;
 } /* globspace */

static void globrelease(n,ap) address n; app ap;{

 /* releases temporary variable with appetite ap and  */
 /*  address n within global area                     */

  gtmpmap[ n ] = TRUE;
  switch(ap) 
  {
    case  1 : break ;
    case  2 : gtmpmap[ n+1 ] = TRUE ;
              break ;
    case  3 : gtmpmap[ n+1 ] = TRUE ; 
              gtmpmap[ n+2 ] = TRUE ;
              break ;
  } /* switch */
}

int locspace (ap)
app  ap ;
 /* returns offset of the new temporary variable allocated within local area */
 /* indexed -maxloctemp .. -1         for non-reference     or               */
 /*                   0 .. maxreftemp for reference values                   */
 
/*   label 77;  exit when successed */
{
  int   n ;

  if (ap == APVIRT) /* REFERENCE */
  {/* reference variable, indexed 0..maxreftemp */
    n = 0;
    while ( !rtmpmap[ n ]  &&  (n < MAXREFTEMP))
     ++n ;
    if (rtmpmap[ n ])
    {
      rtmpmap[ n ] = FALSE;
      if (n > reftmp)
        reftmp = n ;
    }
    else
      generror(TMTEMP);
    return (n * APREF);
  }
  else
  { /* non-reference, indexed 1..maxloctemp */
    n = ap ;
    while (n <= MAXLOCTEMP)
    {  if (ltmpmap[ n ])
         switch (ap)
         { case 1 : ltmpmap[ n ] = FALSE ;
                    goto label77 ;


           case 2 : if (ltmpmap[ n-1 ])
                    { ltmpmap[ n ] = FALSE ;
                      ltmpmap[ n-1 ] = FALSE ;
                      goto label77 ;
                    }
                    break ;

           case 3 : if (ltmpmap[ n-1 ]  &&  ltmpmap[ n-2 ])
                    { ltmpmap[ n ] = FALSE ;
                      ltmpmap[ n-1 ] = FALSE ;
                      ltmpmap[ n-2 ] = FALSE ;
                      goto label77;
                    }
                    break ;
         } /* switch */

         /*dsw     else*/

         n += ap ;
    }  /* while */;
      /* exit on failure */
      generror(TMTEMP) ;

  label77 : /* found */
      if (n > loctmp)
        loctmp =  n ;
      return (-n) ;
  } /* non-reference */
} /*locspace */

void locrelease(n, ap)
address n;
app ap ;

/* releases temporary variable of appetite ap allocated at address n */
/*   within local area                                               */

{
  if (ap == APVIRT)                  /* reference variable */
    rtmpmap[ n / APREF ] = TRUE ;
  else{                              /* non-reference */
                                     /*cmb indices to ltmpmap negated cmb*/
    ltmpmap[ -n ] = TRUE ;
    switch( ap ){
       case 1 : break ;
       case 2 : ltmpmap[ -n - 1 ] = TRUE ;
                break ;
       case 3 : ltmpmap[ -n - 1 ] = TRUE ;
                ltmpmap[ -n - 2 ] = TRUE ;
                break ;
    }
  }
} /* locrelease */


 void force(n, m, o1, o2)
   /* FORCES THE N-TH ARGUMENT TO BE OF M-MODE WITH PARAMETERS O1,O2 */
argnr n ;
addrmode m ;
address o1, o2 ;

{ args_struct * curr ; /* gsg for PASCAL WITH translation */
  curr = args + n ; /* WITH ARGS[ N ] DO BEGIN */
  
  { curr->mode = m ;
    curr->off1 = o1 ; 
    curr->off2 = o2 ; 
  }
} /* force */
/**********************************************************/


 void forceconst(n)
   /* FORCES THE N-TH ARGUMENT TO BE A CONSTANT */
argnr n ;  
{ args_struct * curr ; /* gsg for PASCAL WITH translation */

  curr = args + n ;
/*  WITH ARGS[ N ] DO BEGIN */
  { curr->mode = CONSTANT ;
    curr->off1 = tuple[ qcurr ].arg[ n ] ;
  }
} /* forceconst */
/**********************************************************/



 void forceprot(n)
   /* FORCES THE N-TH ARGUMENT TO BE A PROTOTYPE NUMBER AS A CONSTANT */
argnr n ;
{ args_struct * curr ; /* gsg for PASCAL WITH translation */

  curr = args + n ;
/* WITH ARGS[ N ] DO BEGIN */
  { curr->mode = CONSTANT ;
    curr->off1 = ipmem[ tuple[ qcurr ].arg[ n ] - 1 ] ;
  }
} /* forceprot */
/**********************************************************/

 void argument(n)
/* PUTS THE DESCRIPTION OF THE N-TH ARGUMENT INTO ARGS[N] */
/* FOR TEMPORARY VARIABLES WITH NO NEXT USE AND NOT LIVE  */
/*  THE CORRESPONDING IS RELEASED                         */

argnr n ;
{
  address w1 ; /* ( + 1) WORD OF SYMBOL TABLE ITEM */
/*  qaddr0 nextuse ; */
  quadruple * curr1 ; /* gsg for PASCAL WITH translation */
  args_struct * curr2 ; /* gsg for PASCAL WITH translation */
  int  ad ;
    
  curr1 = tuple + qcurr ;
  curr2 = args + n ;
/* WITH TUPLE[ QCURR ] DO BEGIN */
  {
    ad = curr1->arg[n] ; 
    notrick  = ipmem[ ad ] ;
     w1 = ipmem[ ++ad ] ;
/*     WITH ARGS[ N ] DO BEGIN */ /*  WITH TRICK.STI DO */
     {
       switch (smode(notrick)) {
/*CBC Replaced global absolute addressing by dot access to MAIN block object */
/*CBC  VARGLOB : {  MODE = GLOBAL ; OFF1 = ipmem[ W1-2 ] + MAIN } */

        case VARGLOB : curr2->mode  =  DOTACCESS ;
                       curr2->off1 = ipmem[ w1-2 ] ;
                       curr2->off2 = MAINBLOCK ;
                       break ;

        case VARLOC  : curr2->mode = LOCAL ;
                       curr2->off1 = ipmem[ w1 - 2 ] ;
                       break ;

/*CBC Added new addressing mode for remote access through DISPLAY */
        case VARMID  : curr2->mode = DOTACCESS ;
                       curr2->off1 = ipmem[ w1 - 2 ] ;
                       curr2->off2 =  /* DISPLAY +  */ ipmem[ w1 - 1 ] ;
                       break ;

        case TEMPVAR : if (slocal(notrick))
                       {
                         curr2->mode = TEMPLOCAL ;
                         curr2->off1 = w1 ;
                         if ( (curr1->nxtuse[ n ]==0) && (! slive(notrick)) )
                           locrelease(w1, sap(notrick)) ;
                       } /* slocal */
                       else
                       {
                           curr2->mode = GLOBAL ;
                           curr2->off1 = w1 + temporary ;
                           if ((curr1->nxtuse[ n ]==0) && (! slive(notrick)) )
                             globrelease(w1, sap(notrick)) ;
                       } /* else */
                       break ;
                   
        case INTCONST : curr2->mode = IMMEDIATE ; 
                        curr2->off1 = w1 ;
                        break ;
   
       case REALCONST : curr2->mode = GLOBAL ; 
                        curr2->off1 = realbase + w1 ;
                        break ;

      } /* switch */
    } /* WITH ARGS */
  } /* WITH TUPLE */
} /* argument */
/**********************************************************/


static void result(n) argnr n;{

 /* PUTS THE DESRIPTION OF N-TH ARGUMENT ( BEING DEFINED ) INTO ARGS[N].   */
 /* FOR THE TEMPORARY VALUE THE NEW SPACE IS ASSIGNED                      */

  int w1 ; /* ( + 1) WORD OF SYMBOL TABLE ITEM */
  quadruple * curr1 ; /* gsg for PASCAL WITH translation */
  args_struct * curr2 ; /* gsg for PASCAL WITH translation */

  /*  int globspace(app) ; */

  curr1 = tuple + qcurr ;
  curr2 = args + n ;
/* WITH TUPLE[ QCURR ] DO BEGIN */
  { notrick   = ipmem[ curr1->arg[ n ] ] ;
    w1 = ipmem[ curr1->arg[ n ] + 1 ] ;
/*    WITH ARGS[ N ] DO BEGIN */ /* WITH TRICK.STI DO */
    {
       switch (smode(notrick)) {
/*CBC Replaced global absolute addressing by dot access to MAIN block object */
/*CBC  VARGLOB : {  MODE = GLOBAL ; OFF1 = (ipmem)[ W1-2 ] + MAIN } */
       case VARGLOB : curr2->mode  =  DOTACCESS ;
                      curr2->off1 = ipmem[ w1-2 ] ;
                      curr2->off2 = MAINBLOCK ;
                      break ;

       case VARLOC  : curr2->mode = LOCAL ;
                      curr2->off1 = ipmem[ w1-2 ] ;
                      break ;

/*CBC Added new addressing mode for remote access through DISPLAY */
       case VARMID  : curr2->mode = DOTACCESS ;
                      curr2->off1 = ipmem[ w1 - 2 ] ;
                      curr2->off2 =  /* DISPLAY +  */ ipmem[ w1 - 1 ] ;
                      break ;

       case TEMPVAR : /* ALLOCATE IT */
                 if (slocal(notrick))
                 { /* CANNOT USE GLOBAL TEMPORARIES */
                   args[ n ].mode = TEMPLOCAL ;
                   curr2->off1 = locspace(sap(notrick)) ;
                   ipmem[ curr1->arg[ n ] + 1 ] = curr2->off1 ;
                 }
                 else
                 { /* GLOBAL AREA MAY BE USED */
                   args[ n ].mode = GLOBAL ;
                   curr2->off1 = globspace(sap(notrick)) ;
                   ipmem[ curr1->arg[ n ] + 1 ] = curr2->off1 ;
                   curr2->off1 += temporary ;
                 }
                 break ;

       case INTCONST :
       case REALCONST : /* IMPOSSIBLE */
                        break ;
       } /* switch */
     } /* WITH ARGS */
  } /* WITH TUPLE */
} /* result */



 void emit()
{ ieopc trick ;
  argnr i ;
  args_struct * curr ; /* gsg for PASCAL WITH translation */
  
#if (TALK > 31)
   printf("on entrance to emit fre == %d\n", fre) ;
#endif
   for (i = 1; i <= 3 ; i++)
     trick.c2.eop.args[ i ] = (char)(args[ i ].mode) ;
   trick.c2.eop.args[ 0 ]  =  (char)(tuple[ qcurr ].opcode) ;  /* opcode */

#if SMALL
 m[ fre ] = trick.c0.int1f ;
 m[ fre + 1 ] = trick.c0.int2f ;
 LOG(fre);
 LOG(fre + 1);
#elif LARGE || HUGE
 m[ fre ]  =  trick.c1.intf ;
 LOG(fre);
#endif

#if (TALK > 15)
 printf(" emit  %d\n", trick.c2.eop.args[0]);
#endif

 fre += APOPCODE ;

 for (i = 1; i <= 3; i++) /* WITH ARGS[ I ] DO */
 { curr = args + i ; /* gsg PASCAL WITH translation */

   if (curr->mode != NOARGUMENT)
   { 
     m[ fre ] = curr->off1 ;
     fre += APINT ;
     if ( (curr->mode == REMOTE) || /*cbc*/ (curr->mode == DOTACCESS) )
     { 
       m[ fre ] = curr->off2 ;
       fre += APINT ;
     }
   }
 }
 if (fre >= firstlabel)
  generror(MEMOVF) ;
#if (TALK > 31)
    printf("on exit from emit fre == %d\n", fre) ;
#endif
} /* emit */


 void defaultargs()
   /* PREPARES DEFAULT DESCRIPTIONS OF ARGUMENTS */

{
  int d ;
  /*  void  result(argnr) ;  */

   for (d = 1; d <= 3; d++)
     args[ d ].mode = NOARGUMENT ;
   d = opdescr[tuple[qcurr].opcode ] ;  /*!!*/
   if (d < 8)
      /* NO RESULTS */
      switch (d)
      { case 0 : break ;

        case 1 : forceconst(1) ;
                 break ;

        case 2 : argument(1) ;
                 break ;

        case 3 : argument(1) ;
                 forceconst(2) ;
                 break ;

        case 4 : argument(1) ;
                 forceconst(2) ;
                 forceconst(3) ;
                 break ;

        case 5 : argument(1) ;
                 argument(2) ;
                 break ;

        case 6 :  argument(1) ;
                  argument(2) ;
                  forceconst(3) ;
                  break ;

        case 7 : argument(1) ;
                 argument(2) ;
                 argument(3) ;
                 break ;

      } /* switch */
   else
   { /* AT LEAST ONE RESULT */
     if (d < 14) /* 1 RESULT */
       switch (d)
       { case 8 : break ;

         case 9 : forceconst(2) ;
                  break ;

         case 10 : forceconst(2) ;
                   forceconst(3) ;
                   break ;

         case 11 : argument(2) ;
                   break ;

         case 12 : argument(2) ;
                   forceconst(3) ;
                   break ;

         case 13 : argument(2) ;
                   argument(3) ;
                   break ;

      } /* switch */

      else { /* 2 RESULTS */
        if (d == 14)
        if (tuple[qcurr].opcode >= 4)
          argument(3) ; /*!!*/
                           /* open , slopen */
        else forceconst(3) /* openrc , raise */  ;
        result(2) ;
      } /* 2 results */

      result(1) ;
    } /* at least one result */

 } /* defaultargs */


 void esac()
 /* PRODUCES A DESCRIPTION OF 'CASE' */
{
  int n,trick;
  int lab,labnr,othrlab;
  int val,valuee;
  address tofill ;
  
 /*  WITH TUPLE[ QCURR ] DO */
     {
       labnr = next() ;        /* number of labels                   */
       othrlab = next() ;      /* 'otherwise' label                  */
       deflabel(othrlab - 1) ;/* 'switch' description label           */
       m[ fre ] = next() ;    /* minimal value of 'switch' expression */
       tofill = fre + 1 ;     /* to be filled with the number of branches */
       fre += 2 ;
       val = 0 ;
       for (n = 1; n <= labnr; n++)
       {
         trick  = next() ;
         valuee  =  iand(ishft(trick,-8),255) ;
         lab  =  iand(trick,255) ;
         while (val < valuee)
         {
           uselabel(othrlab) ;
           fre ++ ;
           val ++ ;
         } /* while */
         uselabel(othrlab + lab) ;
         fre ++ ;
         val ++ ;
       } /* for */
       m[ tofill ] = val ;
     } /* with */
} /* esac */


