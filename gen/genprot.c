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

static bool vtype(address,int);
static void addressing(void);
static void param(int,int);
static void p2(int,int,address);
static void par2(address,int);
static void putaddr(int,int);
static void parproc(int);
static void parfunc(int);
static void partype(int);
static void signoffst(int);
static void offsets(void);
static void rpcmask(void);

#else

static bool vtype();
static void addressing();
static void param();
static void p2();
static void par2();
static void putaddr();
static void parproc();
static void parfunc();
static void partype();
static void signoffst();
static void offsets();
static void rpcmask();

#endif



static bool vtype(i,ip) address i; int ip;{

/* PUTS THE TYPE OF ITEM DESCRIBED AT ADDRESS IP IN IPMEM  TO THE CELLS
   m[ I ],m[ I+1 ]   / NUMBER OF ARRAYOF,FINAL TYPE/ .
   ASSIGNES TRUE TO REF IF THE TYPE IS A REFERENCE TYPE AND FALSE OTHERWISE.
   IF THERE IS NO DESCRIPTION FOR THE TYPE YET,"I" IS ADDED TO THE LIST
              OF UNSATISFIED REFERENCES  */

  int        ft ; /* final type */
  address    fft ;
  int        n  ;
  bool   ref;
  fft = 0 ;
  m[ i ] = ipmem[ ip - 4 ] ;
LOG(i);  
  ft = ipmem[ ip-3 ] ;
  ref = FALSE ;

  /* PRIMITIVE TYPE ? */
  if (ft==nrint)  /* integer */
    fft = ipradr + TINT ;
  else
  if (ft==nrre)  /* real */
    fft = ipradr + TREAL ;
  else
  if (ft==nrbool)  /* boolean */
    fft = ipradr + TBOOLEAN ;
  else
  if (ft==nrchr)  /* char */  
    fft = ipradr + TCHAR ;
  else
  if (ft == nrtext)  /* string */
    fft = ipradr + TSTRING ;
  else                   /* REFERENCE TYPE */
    ref = TRUE;
          
          
  if (ref || (ipmem[ip-4] > 0) )
  { 
    ref = TRUE ;

    if (ft==nrcor)
      fft=ipradr + TCOROUT ;
    else
    if (ft==nrproc)
      fft = ipradr + TPROCESS ;
    else
    if( (ipmem[ft] % 16) == 11 ) /*file*/
      fft = ipradr + TFILE ;
    else
    if (fft == 0)
    { /* CLASS OR FORMAL TYPE */
      if (ipmem[ ft+2 ] < 0)
        fft = -ipmem[ ft+2 ] ;
      else /* UNKNOWN YET, ADD TO LIST OF UNSATISFIED REFERENCES */
      {      
        n = -ipmem[ft-2] ; 
        ipmem[ft-2] = -(i+1) ; 
        fft = -n; 
      } /* else */
    } /* CLASS OR FORMAL TYPE */
  } /* REFERENCE TYPE */

  m[ i + 1 ] = fft ;
LOG(i + 1);  
  return(ref) ;
} /* VTYPE */





static void param(ia, parkind) int  ia,parkind;{
 /* PREPARES A DESCRIPTION OF INPUT, OUTPUT OR INOUT PARAMETER */
  bool        aux ;  /*  auxilliary */
  pointprdsc  curr ;

  /* IA = PARAMETER ADDRESS IN IPMEM */
  /*    WITH PROTOTYPE[ LASTPROT ] ^ DO */
  { curr = prototype[ lastprot ] ;
    reserve(3);
    m[ fre ]=parkind;
LOG(fre);  

    aux = vtype(fre+1,ia);

    if (aux)
    { /* REFERENCE TYPE */
      addtolist(&(listofref[ lastprot ]), ia);
      curr->lthreflist++ ;
    } 

    longaddtolist(&(listofpar[ lastprot ]), fre + base) ;
    curr->lthparlist++ ;
    fre += 3 ;
  }
}

static void p2(pk,pda,ndscr) int pk,pda; address ndscr;{

   /* CREATES DESCRIPTION OF PAR. INPUT,OUTPUT OR INOUT
       OF FORMAL PROCEDURE OR FUNCTION  */

  reserve(3) ;
  m [ ndscr ] = fre + base ;
LOG(ndscr);  
  m [ fre ] = pk ;
LOG(fre);  

  vtype(fre + 1, pda) ;
  fre += 3 ;  /* mb */
}



static void par2(am,ip) address am; int ip;{

  /* MAKES DESCRIPTIONS FOR FORMAL PARAMETERS OF void OR FUNCTION
     BEING A PARAMETER ITSELF .
            AM = ADDRESS OF THIS UNIT DESCRIPTION IN M,
            IP = ADDRESS IN IPMEM                             */

  int          pda;
  address      n,ndscr ;
  pointprdsc   curr ;

/*   WITH PROTOTYPE[ LASTPROT ] ^ DO */
  { curr = prototype[lastprot] ;

    longaddtolist(&listofpar[ lastprot ],am+base);
    curr->lthparlist++ ;
    addtolist(&listofref[ lastprot ],ip) ;
     curr->lthreflist++ ;
  } /* with */ ;

  m [ am + 2 ]=ipmem[ ip + 4 ];
LOG(am + 2);  
  /* number of parameters including 'result' */
  m [ am + 1 ] = fre + base ;
LOG(am + 1);  

  if( m [ am+2 ] != 0)
  { /* NOT EMPTY PARAMETERS LIST */
    reserve(m [ am+2 ]) ;
    fre += m [ am+2 ] ;

    for (n=0; n<=m[ am+2 ]-1; n++)
    {
      pda = ipmem[ ipmem[ ip+3 ] + n ] ;
      /* PARAMETER ADDRESS IN IPMEM */
      ndscr = m [ am+1 ] - base + n ;

      switch(itemkind(pda))
      {
        case  IFMPROC : m [ ndscr ] = ipradr + TPROC2;
                        LOG(ndscr);
                        break;

        case  IFMFUNC : m [ ndscr ] = ipradr + TFUNC2;
                        LOG(ndscr);
                        break;

        case  IFMTYPE : reserve(2);
                        m [ ndscr ] = fre +base ;
                        LOG(ndscr);         
                        m [ fre ] = FORMTYPE;
                        LOG(fre);
                        m [ fre + 1 ] = -1;
                        LOG(fre + 1);
                        backpatch(pda,fre);
                        fre += 2;
                        break;
       case   IPARIN  : p2(PARIN, pda,ndscr) ;
            break ;
       case   IVAR : ;
             /* BECAUSE OF THE BUG IN COMPILER : 'RESULT' NOT DESCRIBED */
             /*  CORRECTLY, SHOULD BE TREATED AS OUTPUT PARAMETER     */

       case   IPAROUT : p2(PAROUT, pda, ndscr);
                        break;

       case   IPARINOUT : p2(PARINOUT, pda, ndscr);
                          break;
      } /* switch */
    } /* for */
  } /* NOT EMPTY PARAMETER LIST */;
} /* PAR2 */;



static void parproc(ia) int ia;{    /* FORMAL PROCEDURE DESCRIPTION */
  reserve(3);
  m [ fre ] = FORMPROC ;
LOG(fre);
  fre += 3 ;
  par2(fre-3, ia) ;
}


static void parfunc(ia) int ia;{        /* FORMAL FUNCTION DESCRIPTION */
  address n;
  reserve(5);
  m [ fre ] = FORMFUNC;
LOG(fre);
  fre += 5;
  n = fre;
  par2(n-5,ia);
  vtype(n-2,ia);
}


static void partype(ia) int ia;{        /* FORMAL TYPE PARAMETER */
  reserve(3);

  m [ fre ] = FORMTYPE ;
LOG(fre);
  m [ fre + 1 ] = lastprot ; /* sl */
LOG(fre + 1);
  m [ fre + 2 ] = offset ;
LOG(fre + 2);
  backpatch(ia,fre + base) ;

  /*  WITH PROTOTYPE[ LASTPROT ] ^ DO */
    longaddtolist(&listofpar[ lastprot ],fre + base) ;
    prototype[lastprot]->lthparlist++ ;

  fre += 3 ;
}


static void putaddr(ap,a) int ap,a;{

      /* PUT PROTOTYPE AND OFFSET INTO ATTRIBUTE DESCRIPTION AT "A" IN IPMEM */

  ipmem[ a - 2 ] = offset ;
  ipmem[ a - 1 ] = lastprot ;

  if(ap == APVIRT) offset += APREF ;
  else             offset += ap ;
}


static void offsets(){

 /* COMPUTE OFFSETS FOR ALL ATTRIBUTES,  */
 /* COMPUTE OFFSETS FOR ALL ATTRIBUTES,  */
 /*          LINK PARAMETERS,            */
 /*          LINK REFERENCE ATTRIBUTES   */

  int         p, n, a ;
  pointprdsc  curr ;
  {
    curr = prototype[lastprot] ;
    offset = curr->appetite; /* total length of attributes from prefix,if any */

    /* GO THRU THE LIST OF ATTRIBUTES */
    for (p = ipmem[ curr->codeaddr + 6 ] ; /* first element */
         p != 0 ;
         p = ipmem[ p+1 ]  /* next element */){

      /* LIST ELEMENT : POINTER TO ATTRIBUTE DESCRIPTION,  */
      /*                     POINTER TO THE NEXT ELEMENT */

      a = ipmem[ p ] ; /* attribute address in ipmem */
      switch (itemkind(a)){

        case  IFMPROC  :  parproc(a) ;
                          putaddr(APFMPROC, a) ;
                          break ;

        case  IFMFUNC  :  parfunc(a) ;
                          putaddr(APFMPROC, a) ;
                          break ;

        case   IFMTYPE  :   partype(a) ;
                            putaddr(APFMTYPE, a) ;
                            break ;

        case   IPARIN :     param(a, PARIN) ;
                            putaddr(apet(a), a) ;
                            break ;

        case   IPAROUT  :   param(a, PAROUT) ;
                            putaddr(apet(a), a) ;
                            break ;

        case   IPARINOUT :  param(a, PARINOUT) ;
                            putaddr(apet(a), a) ;
                            break ;

        case   IVAR :  n = apet(a) ;
                       if (n == APVIRT)
                       {
                         addtolist(&listofref[ lastprot ], a) ;
                         curr->lthreflist++ ;
                         n = APREF ;
                        }

                        putaddr(n, a) ;
                        break ;
        default : break ;
        /*  IBLOCK, IPREFBLOCK, IHANDLER, ISIGNAL :  IMPOSSIBLE */

        /*   ICLASS,IRECORD,ICOROUT,IPROCESS,IFUNC,IPROC,ICONST: NOP */

      } /* switch */

    } /* for */

    curr->appetite = offset ;
  } /* WITH */

} /* OFFSETS */




static void signoffst(s) int s;{

         /* COMPUTES THE OFFSETS OF PARAMETERS OF */
         /* THE SIGNAL DESCRIBED IN IPMEM AT S    */

  int  offset  ;
  int  p ;
  int  param ; /* POINTER TO PARAMETER DESCRIPTION */
  int  ap ;

  offset = APINT + APINT;

  /* GO THRU THE LIST OF ATTRIBUTES */
  for( p = ipmem[ s+6 ] ; /* first element */
       (p != 0) ;
       p = ipmem[ p+1 ] /* next element */)

  {
    /* LIST ELEMENT : POINTER TO ATTRIBUTE DESCRIPTION */
    /*                POINTER TO THE NEXT ELEMENT      */
    param = ipmem[ p ] ;        /* attribute address in ipmem */

    switch(itemkind(param))
    {
      case  IFMPROC   : ;
      case  IFMFUNC   : ap = APFMPROC ;
                        break ;

      case  IFMTYPE   : ap = APFMTYPE ;
                        break ;
             default  :
             /* IPARIN,IPAROUT,IPARINOUT */
                        ap = apet(param) ;
                        if (ap == APVIRT)
                          ap = APREF ;
                        break ;
    } /* switch */

           ipmem[ param-2 ] = offset ;
           offset += ap ;
  } /* for */
} /* SIGNOFFST */


static void addressing()

    /* FOR EACH UNIT ( IN TOPOLOGICAL ORDER ) :                             */
    /*   - NEW PROTOTYPE IS CREATED,                                        */
    /*         ( FOR CLASS ALSO CLASS TYPE DESCRIPTION )                    */
    /*   - UNIT'S ATTRIBUTES ARE ASSIGNED OFFSETS                           */
    /*   - REFERENCE VARIABLES ( INCLUDING FORMAL PROCEDURES ) ARE LINKED   */
    /*                 INTO LIST                                            */
    /*   - PARAMETERS ARE LINKED INTO LIST                                  */
    /*         ( THEIR DESCRIPTIONS ARE ALSO PRODUCED )                     */

{
  int  pip ;            /* PROTOTYPE IN IPMEM */
  protaddr  nextunit ;
  protkind  pkind[ IFMFUNC + 1 ] ; /* AUXILIARY, READ-ONLY */ 
  logitem   it ;

  pointprdsc  curr;  /* for translation of Pascal's WITH */

  for (it = ICLASS; it <= IFMFUNC ; it++)
         pkind[  it  ] = it;

       /* START FROM THE MAIN BLOCK */
  nextunit = MAINBLOCK ;
  pip = nblus; /* main block in ipmem */

  do /* GET UNIT FROM THE LIST OF ALL UNITS */
  {
    it = itemkind(pip);
    if ( (it == ICLASS) || (it == IRECORD) || (it == ICOROUT) 
      || (it == IPROCESS) || (it == IBLOCK) || (it == IPREFBLOCK)
      || (it == IFUNC) || (it == IPROC) || (it == IHANDLER) )
      { /* REAL UNIT */

           if (nextunit > MAXPROT) 
             generror(TMPROT) ;
      /* mb removed case which did the same in every case */
      /* in doubts cf. Pascal version */
     prototype[ nextunit ] =  (pointprdsc) new(prototype[ nextunit ]) ; 

         /* WITH PROTOTYPE[ NEXTUNIT ] ^ DO */
        { curr = prototype[nextunit] ;
          curr->codeaddr = pip ;  /* pointer to the description in ipmem */
          curr->kind = pkind[ it ] ;
        }

        nextunit++ ;
      } /* OF REAL UNIT */
    else
      if (it == ISIGNAL)
        signoffst(pip) ;

      pip = ipmem[ pip+2 ] ; /* move on to the next unit */
  }  
  while (pip != 0) ;            /* END OF LIST.             */

  lastprot = MAINBLOCK ;

  do
  {
    pdescr() ;  /* make prototype's description       */
    offsets();  /* compute offsets for all attributes */
    lastprot++ ;
  }
  while (lastprot != nextunit) ;

  lastprot = nextunit-1;
} /* ADDRESSING */


static void rpcmask(){
 pointprdsc *prot ;

 for (prot = prototype; prot <= &prototype[lastprot]; prot++)
 {
   if ((*prot)->kind == PROCESS) 
     {
      (*prot)->maskbase = MAINBLOCK ;
       (*prot)->masksize = (lastprot + 7) / 8 ;
     }
  }
}       
     
  

   void genprot(){

                    /* PROTOTYPES CREATING */

     out() ;
     primdescr() ;  /* primitive types descriptions           */
     addressing() ; /* offsets, prototypes without lists      */
     lists() ;      /* preflist, parlist, virtlist, descrlist */
     handlers() ;   /* handlers lists                         */
    
/*CBC Force unit kind of main to be PROCESS (instead of BLOCK) ...*/
     prototype[ MAINBLOCK ]->kind = PROCESS ;

/*CBC Added computing of base and size of RPC mask */
    rpcmask() ;
/*...CBC*/

} /* GENPROT */


