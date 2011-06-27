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

#include <assert.h>
#include "glodefs.h"

#ifndef NO_PROTOTYPES

static void makereflist (protaddr);
static void makeprefseq (protaddr);
static void makeparlist (protaddr);
static void makevirtlist(protaddr);
static void makeit  (int,protaddr);

#else

static void makereflist();
static void makeprefseq();
static void makeparlist();
static void makevirtlist();
static void makeit();

#endif

logitem itemkind (i)
              /* strongly implementation dependent, */
              /*  given the address in symbol table */
              /*  returns the kind of loglan item   */
              /*  ctp */

int i ;
{ 
   int         n ;
   csti    trick ;

       n = ipmem [ i ] ;

/*       WITH TRICK DO */
       {
         trick.t=iand(n,15);                   /* 000f */
         /* bits 12..15 in 16-bits word */
       
         trick.zp=ishft(iand(n,15*16),-4);        /* 00f0 */
         /* bits  8..11 in 16-bits word */
       
         trick.s=ishft(iand(n,7*256),-8); /* 0700 */

         /* bits  5.. 7 in 16-bits word */

         switch(trick.t)
         {
     case 2 : return(IRECORD) ;

     case 3 : return(ICLASS) ;

     case 5 : return(IPROCESS) ;

     case 6 : return(IFMTYPE) ;

     case 7 : return(ICOROUT) ;

     default :
     /*  4,8,9,10,11,12,13,14,15 */ break;

     case 1 : switch(trick.zp)
                   {
           case 2  : return(IFMFUNC) ;

             case 3  : return(IFMPROC);

           case 5  : return(IPARIN);

           case 6  : return(IPAROUT);

           case 7  : return(IVAR);

           case 8  : return(ICONST);

           case 9  : return(IPARINOUT);

           case 11 : return(ISIGNAL);



           case 0 : switch(trick.s)
                              {
            case 0 : return(IBLOCK);

            case 1 : return(IPREFBLOCK);

            case 2 : return(IFUNC);

            case 4 : return(IPROC);

            case 7 : return(IHANDLER);


            default /* 3,5,6*/ : break ;
               } /* switch trick.s */
                          default :
           /* 1,4,10,12,13,14,15 */ break ;

         } /* switch trick.zp */
    } /* switch trick.t */;
       } /* WITH */

} /* itemkind */



void reserve(n) address n;{ /* TEST IF THERE IS AT LEAST N EMPTY CELLS IN 'M' */
  if((fre + n) > MEMLIMIT)  generror(TLDESCR); 
}



static void makereflist(prot) protaddr prot;{
/* PREPARES THE TABLE WITH OFFSETS OF REFERENCE VARIABLES */
/* FOR THE PROTOTYPE PROT                                 */

  pointer       elem ;
  int           n ;
  bool          anytodo ;
  dprotaddr     pref ;
  pointprdsc    curr ;  /* cmb */

  curr = prototype[ prot ] ;
  if (curr->lthreflist > 0){
    anytodo = TRUE ;
    pref = prefix[ prot ] ;

    if (pref != DUMMY)  /* prefixed unit */
      if(( prototype[ pref ]->span != 0 )
          && ( prototype[ pref ]->lthreflist == curr->lthreflist )){

         /* prefix already processed and the same reference attributes */

         anytodo = FALSE ;
         curr->reflist = prototype[ pref ]->reflist ;
      }

    if(anytodo){
      reserve(curr->lthreflist) ;
      elem = listofref[ prot ] ;

      /* COPY THESE OFFSETS */
      for (n = curr->lthreflist-1; n>=0; n--)
      {
        m [ fre+n ] = ipmem[ (elem->ip) - 2 ] ; /* offset */
LOG(fre + n);     
        elem = elem->prevelem ;
      } /* COPYING */

      curr->reflist = fre + base ;
      fre += curr->lthreflist ;

    } /* NOT DONE YET */
  } /* IF NON EMPTY REFLIST  */
}

   
   
static void makeprefseq(prot) protaddr prot;{
  int        n ;
  dprotaddr  pa  ;
  pointprdsc curr ;

/*         WITH PROTOTYPE[ PROT ]^ DO */

  curr = prototype[ prot ] ;
  reserve(curr->lthpreflist) ;
  pa = prot ;
    
  for (n = (curr->lthpreflist) - 1; n >= 0 ; n--)
  {
    m[ fre + n ] = pa ;
LOG(fre + n);     
    pa = prefix[ pa ] ;
  }
       
  curr->preflist = fre + base ;
  fre += curr->lthpreflist ;
   
}



static void makeparlist(prot) protaddr prot;{
/* PREPARES TABLES WITH PARAMETERS OFFSETS AND DESCRIPTION ADDRESSES
   FOR PROTOTYPE PROT */

  longpointer  elem ;
  int          ip , /* address in ipmem */
               n ;
  dprotaddr    pref;
  bool         anytodo ;
  pointprdsc   curr ;

/*         WITH PROTOTYPE[ PROT ] ^ DO */
{  curr = prototype[ prot ] ;
  if (curr->lthparlist > 0)
  {
    /* TABLE WITH PARAMETERS OFFSETS */
    reserve(curr->lthparlist) ;
    curr->parlist = fre + base ;

    if (curr->kind == HANDLER)
    {
      /* NO PARAMETER LIST IN IPMEM, USE ATTRIBUTE LIST*/
      ip = ipmem[(curr->codeaddr) + 6 ] ;
                                          /* FIRST ELEM. OF ATTRIBUTE LIST */
      for (n = 0; (n <=(curr->lthparlist-1 )); n++)
      {
   m[ fre + n ] = ipmem[(ipmem[ ip ])-2 ] ; /* offset */
LOG(fre + n);     


         ip = ipmem[ ip+1 ]; /* next */
       } /* FOR */;

       fre += curr->lthparlist;
     } /* IF HANDLER */

     else /* not handler */
     {
       anytodo = TRUE;
       pref = prefix[ prot ];

       if (pref != DUMMY)
       if (( prototype[ pref ]->span != 0 ) /* prefix already processed */
        && ( prototype[ pref ]->lthparlist == curr->lthparlist ))
                  /* the same parameters */
        {
          curr->parlist=prototype[ pref ]->parlist;
          anytodo=FALSE;
        } 

    if (anytodo)
         {
           /* COPY THESE OFFSETS USING PARAMETERS LIST FROM IPMEM */
      ip=ipmem[ curr->codeaddr+3 ]; /* first parameter indirect address */

           for (n=0;n <= (curr->lthparlist) - 1; n++)
             m [ fre + n ] = ipmem[ ipmem[ ip+n ] - 2 ]; /* offset */
LOG(fre + n - 1);     

           fre += curr->lthparlist;
          } /* mb if anytodo (?) */

               /* FOR PROCEDURE OR FUNCTION PREPARE TABLE WITH PARAMETERS
                                                     DESCRIPTIONS ADDRESSES */
          if( (curr->kind == LFUNCTION) || (curr->kind == LPROCEDURE)
              || (curr->kind == PROCESS) )
          {
            reserve(curr->lthparlist);
            curr->pfdescr=fre+base;
            elem = listofpar[ prot ];

            for (n=curr->lthparlist-1; n >= 0; n--)
            {
              m [ fre + n ] = elem->ip; /* description's address */
LOG(fre + n);     
              elem=elem->prevelem;
            } /* for */

             fre += curr->lthparlist;
          } /* FUNCTION,PROCEDURE,PROCESS */
        } /* NOT HANDLER */
      }  /* mb if lthparlist>0 ?? */
    } /* WITH */

  } /* makeparlist */

static void makeit(ipr,prot)
 int       ipr ;
 protaddr  prot ;
  /* mb  added passing ipr,prot as parameters rather than globals  */
   /* for the ipmem prototype 'ipr' creates the table with virtuals
      prototypes numbers and assignes its address to virtlist of
      'prot' . */
{
  int    k,l,f ;

  l=ipmem[ ipr+25 ]; /* length */
  f=ipmem[ ipr+24 ]; /* first element address */
  reserve(l);
  prototype[ prot ]->virtlist=fre + base;
  for (k=0; k<=l-1; k++)
    m[ fre+k ]=ipmem[ (ipmem[ f+k ])-1  ]; /* virtual's prototype */
LOG(fre + k);     
   fre+=l;
   } /* makeit */

static void makevirtlist(prot) protaddr prot;{
 /* MAKES A TABLE WITH PROTOTYPES NUMBERS FOR VIRTUAL */
 /* PROCEDURES OR FUNCTIONS (IF NOT MADE YET).        */
 /* PROPAGATES ITS ADDRESS THRU THE PREFIX SEQUENCE.  */

 int  ipr ;
 address     n ;
 pointprdsc curr;
 
  {
   curr = (prototype[prot]);
   ipr = (int)(curr->codeaddr); /* address in ipmem */
   if( ((curr->kind  == CLASS) || (curr->kind == LRECORD) ||
          (curr->kind ==COROUTINE) || (curr->kind ==PROCESS) ||
       (curr->kind == PREFBLOCK) || (curr->kind ==LFUNCTION) ||
       (curr->kind ==LPROCEDURE))    /* VIRTUALS ALLOWED */
      && (curr->virtlist == 0) /* not processed yet */
      && (ipmem[ ipr + 25 ] != 0))
   { /* not empty virtuals list */
   while (ipmem[ ipr + 25 ] < 0)
       /* LIST INHERITED FROM PREFIX, GO THERE */
        ipr=ipmem[ ipr + 21 ];
   /* THE OWN LIST OF IPR */
   n = prototype[ ipmem[ ipr - 1 ] ]->virtlist ;
   if (!n)  /* TABLE NOT MADE YET */
      makeit(ipr, prot) ;
   else
    { curr->virtlist = n ;}
   /* PROPAGATE IT UP THE PREFIX SEQUENCE TILL THE OWNER OF THE LIST */
   ipr=(int)(curr->codeaddr); /* ipmem address for prot */
   while (ipmem[ ipr+25 ] < 0)
     {
      ipr = (int)(ipmem[ ipr+21 ]); /* prefix */
      prototype[ ipmem[ ipr-1 ] ]->virtlist = curr->virtlist;
     }
   } /* VIRTUALS ALLOWED AND EXIST, UNIT NOT PROCESSED */
   } /* WITH */
 } /* MAKEVIRTLIST */

void lists(){

  /* PREPARATION OF : REFLIST, PARLIST, PARDESCRLIST, PREFLIST */
  /* UNITS ARE PROCESSED IN A REVERSED ORDER                   */

  protaddr    pr ;
  dprotaddr   prfx ;
  pointprdsc  pref ;
  address     n ;
  pointprdsc  curr ; /* gsg auxiliary for the Pascal WITH */

  for(pr = lastprot; pr >=  MAINBLOCK; pr--){
   curr = prototype[pr] ;
   if(curr->span == 0){              /* ALREADY PROCESSED ? */
                                     /* NOT PROCESSED YET   */
     makeparlist(pr) ;
     if(curr->kind == LFUNCTION){    /* SUPPLEMENT FUNCTION TYPE */
       n = m[ curr->pfdescr - base + curr->lthparlist - 1 ] - base; /* result */
       curr->nrarray = m[ n+1 ] ;
       curr->finaltype = m[ n+2 ] ;
     } /* SUPPLEMENT OF FUNCTION TYPE */

     makereflist(pr) ;
     makeprefseq(pr) ;
     curr->span = 1 ; /* ==> processed */

     /* GO UP THE PREFIX SEQUENCE */
     prfx = prefix[ pr ] ;

     while (prfx != DUMMY)
     {  pref = prototype[ prfx ] ;
 
        if (pref->span != 0)
          prfx = DUMMY ; /* FORCE EXIT */
        else
        { /* prefix not processed yet */
          pref->span = 1 ; /* ==> processed */
          pref->reflist = curr->reflist ;
          pref->parlist = curr->parlist ;
          pref->preflist = curr->preflist ;
/*CBC added copying of PFDESCR (formal parameter description list) */
          pref->pfdescr = curr->pfdescr ;
          prfx = prefix[ prfx ] ;
        } /* PREFIX NOT PROCESSED */
      } /* WHILE */

   } /* NOT PROCESSED */
     
   makevirtlist(pr) ;
 } /* for */

} /* Lists */


void handlers(){
  protaddr prot;
  address  pip,listfrompref;
  int      h;

  for (prot = MAINBLOCK; prot <= lastprot; prot++)
  /*    WITH PROTOTYPE[  PROT  ] ^ DO */
  {  if (prototype[prot]->kind == HANDLER)  /* SURELY NO OWN HANDLERS */
       prototype[prot]->handlerlist = 0 ;
     else
     {
       if (prototype[prot]->lthpreflist == 1)  /* NO PREFIX */
         listfrompref = 0 ;
       else
         listfrompref = prototype[ prefix[ prot ] ]->handlerlist ;

       pip = prototype[prot]->codeaddr ; /* prototype in ipmem */

       if (ipmem[ pip + 19 ] == 0)  /* NO OWN HANDLERS */
         prototype[prot]->handlerlist = listfrompref ;
       else
       { /* mb own handlers  possible */
         reserve( 3 * ( ipmem[ pip + 19 ]) ) ;
         prototype[prot]->handlerlist = fre + base ;
         h = ipmem[ pip + 20 ] ;
         /* first element of handler list in ipmem */
  
         do
         { 
           m[ fre ] = ipmem[ h ] ; /*signal identifier */
LOG(fre);     
           m[ fre + 1 ] = ipmem[ (int)(ipmem[ h + 1 ]) - 1 ] ;
LOG(fre + 1); 
      
           /* handler prototype */
           m[ fre + 2 ] = fre + 3 + base ; /* next */
LOG(fre + 2);     
           h = ipmem[ h + 2 ] ;
           fre += 3 ;
         } while (h) ;
  
         m[ fre - 1 ] = listfrompref ;
LOG(fre - 1);     

       } /* else */
     } /* OWN HANDLERS */
  } /* for */
} /* HANDLERS */



void primdescr(){
/* DESCRIPTIONS OF PRIMITIVE TYPES */

  /*printf("primdescr: fre = %d\n", fre) ;  */
  assert(fre == 0 && base > 0);
  ipradr =base + fre ;
  m[  fre + TINT  ] = PRIMITIVETYPE ;
  m[  fre + TREAL  ] = PRIMITIVETYPE ;
  m[  fre + TBOOLEAN ] = PRIMITIVETYPE ;
  m[  fre + TCHAR  ]   = PRIMITIVETYPE ;
  m[  fre + TCOROUT  ] = PURECOROUTINE ;
  m[  fre + TPROCESS  ]= PUREPROCESS ;
  m[  fre + TSTRING  ] = PRIMITIVETYPE ;
  m[  fre + TFUNC2  ]  = FORMFUNC ;
  m[  fre + TPROC2  ]  = FORMPROC ;
  m[  fre + TFILE   ]  = FILETYPE ; /*DSW*/
    
  /*dsw*/ /* fre=fre+TPROC2+1; */

  fre = fre + TFILE + 1 ; /*dsw*/

  /* STORE ADDRESSES OF THESE TYPES DESCRIPTIONS */
    
  /*DSW&BC...*/
  if (ipradr + TFILE > MAXINT - 1) generror(TLDESCR) ;

  ipmem[ nrint + 2  ] = -(ipradr + TINT) ;
  ipmem[ nrre + 2   ] = -(ipradr + TREAL) ;
  ipmem[ nrbool + 2 ] = -(ipradr + TBOOLEAN) ;
  ipmem[ nrchr + 2  ] = -(ipradr + TCHAR) ;
  ipmem[ nrcor + 2  ] = -(ipradr + TCOROUT) ;
  ipmem[ nrproc + 2 ] = -(ipradr + TPROCESS) ;
  ipmem[ nrtext + 2 ] = -(ipradr + TSTRING) ;
   
} /* PRIMDESCR */

       
       
void addtolist(head, i)    /* gsg ATTENTION !!! head is "var" parameter !!! */
/* ADD THE NEW ELEMENT WITH VALUE "I" TO THE LIST
   REFERED BY "HEAD" */
/* head is passed by reference - it is an "inout" parameter */
/* so it is pointer to pointer to first item                */
   
pointer *  head ;  /* i.e  item  **head */
int i ;
{
  pointer elem ;
       
  elem = *head ;
  (*head) = (pointer) new(*head) ;
  (*head)->ip = i ;
  (*head)->prevelem = elem ;
      
} /* ADDTOLIST */

      
void longaddtolist(head, i)   /* gsg ATTENTION !!! head is "var" parameter !!! */
/* ADD THE NEW ELEMENT WITH VALUE "I" TO THE LIST
   REFERED BY "HEAD" */
longpointer * head ;
address i ;
{
  longpointer  elem ;

  elem = (*head) ;
  (*head) = (longpointer) new(*head);
  (*head)->ip = i ;
  (*head)->prevelem = elem ;
      
} /* longaddtolist */


void backpatch(i, a) int i; address a;{

/* SATISFY REFERENCES (IF ANY) TO THE TYPE WITH IPMEM ADDRESS I           */
/*         WITH THE VALUE A .                                             */
/* IPMEM(I+2) >= 0    ==> NO DESCRIPTION YET,                             */
/*                        IF IPMEM(I-2) >= 0 THEN NOT REFERED YET,        */
/*                        OTHERWISE = -LINK TO THE FIRST ELEMENT OF LIST  */
/* IPMEM(I+2) < 0     ==> DESCRIPTION ALREADY MADE                        */
/*                    AT ADDRESS = -IPMEM(I+2)                            */

  address n,k;

  /*DSW&BC...*/   if(a > MAXINT - 1) generror(TLDESCR);

  /* ANY REFERENCES ? */
  if(ipmem[ i - 2 ] < 0){ 
    n = -ipmem[ i - 2 ];
    ipmem[ i - 2 ] = 0;

    while (n > 0){
      k = n; 
      n = - m[n];
      m[ k ] = a;
      LOG(k);
    }
  }
  ipmem[ i + 2 ] = -a ; /* DESCR. ALREADY MADE */
}


void pdescr(){
/* FILLS THE PROTOTYPE OF UNIT.                        */
/*   FOR THE CLASS ALSO CREATES CLASS TYPE DESCRIPTION */

  pointprdsc  prfx ; /* POINTER TO PREFIX DESCRIPTION      */
  int         ip ;   /* ADDRESS IN IPMEM                   */
  pointprdsc  curr ; /* gsg translation of the Pascal WITH */
   
  /*  WITH PROTOTYPE[  LASTPROT  ]^ DO */
  {  curr = prototype[ lastprot ] ;
     ip = curr->codeaddr ;
      
     if (lastprot == MAINBLOCK)
       curr->slprototype = DUMMY ;
     else
       curr->slprototype = ipmem[ ipmem[ip-1]-1 ] ; /*PROTOTYPE NUMBER FOR SL*/
 
     ipmem[ ip - 1 ] = lastprot ;
     curr->appetite = APINT + APINT ; /* 2 CELLS: OBJECT'S APPETITE, */
                                      /*           PROTOTYPE ADDRESS */
     curr->span = 0 ;
     listofref[ lastprot ] = NULL ;
     curr->lthreflist = 0 ;
     listofpar[ lastprot ] = NULL ;
     curr->lthparlist = 0 ;
     curr->preflist = 0 ;
     curr->lthpreflist = 1 ;
     curr->lastwill = 0 ;
     curr->handlerlist = 0 ;
     curr->virtlist = 0 ;

     /*CBC added virtual number ...*/
     if (iand(ipmem[ ip ], 8 * 256) != 0)  /* virtual ? 0800 */
       curr->virtnumber = ipmem[ ip + 27 ] ;  /* yes, store virtual number */
     else
       curr->virtnumber = -1 ;               /* no, flag that not virtual */
     /*...CBC*/

     prefix[ lastprot ] = DUMMY ;
     
     if ( (curr->kind  == CLASS) || (curr->kind == LRECORD) ||
          (curr->kind ==COROUTINE) || (curr->kind ==PROCESS) ||
          (curr->kind == PREFBLOCK) || (curr->kind ==LFUNCTION) ||
          (curr->kind ==LPROCEDURE) )

     { /* POSSIBLY PREFIXED */
       if (ipmem[ ip + 21 ] != 0)
       { /* PREFIXED UNIT */
         prefix[ lastprot ] = ipmem[ ipmem[ ip + 21 ] - 1 ] ;
         prfx = prototype[ prefix[ lastprot ] ] ;
         curr->lthpreflist = prfx->lthpreflist + 1 ;
         listofref[ lastprot ] = listofref[ prefix[ lastprot ] ] ;
         curr->lthreflist = prfx->lthreflist ;
         listofpar[ lastprot ] = listofpar[ prefix[ lastprot ] ] ;
         curr->lthparlist = prfx->lthparlist ;
         curr->appetite = prfx->appetite ;
       } /* PREFIXED UNIT */

       if ( (curr->kind  == CLASS) || (curr->kind == LRECORD) ||
          (curr->kind ==COROUTINE) || (curr->kind ==PROCESS)      )
       { /* CREATE CLASS TYPE */
         reserve(2) ;
         backpatch(ip, fre + base) ;
         m[ fre++ ] = CLASSTYPE ;
LOG(fre - 1);     
         m[ fre++ ]= lastprot ;
LOG(fre - 1);     
         
       } /* CLASS TYPE */
     } /* POSSIBLE PREFIXED */
  } /* WITH */
       
} /* PDESCR */


