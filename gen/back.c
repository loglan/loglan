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

static void rsnuse(argnr);
static void ptnuse(argnr);

#else

static void rsnuse();
static void ptnuse();

#endif


static void rsnuse(n) argnr n;{

  /* if no next use - replace by 'nop' and exit to 55 */

  qaddr0 nextuse ;
  int notrick ;
  quadruple * curr ; /* gsg for PASCAL WITH translation */


  notrick  = ipmem[ tuple[ qcurr ].arg[ n ] ]  ;
/*   with tuple[ qcurr ] do begin */
  {  curr = tuple + qcurr ; /* gsg PASCAL WITH translation */

     nextuse = ipmem[ (curr->arg)[ n ] + 2 ]  ;
     (curr->nxtuse)[ n ] = nextuse ;
     if ( (nextuse == 0)  &&  (! slive(notrick)) )
     {
       if ((curr->opcode) >  5)   /* #lslopen */
       {
         (curr->opcode) = 195 ;
         nouse  =  TRUE ;
       }
     }
     else
     { ipmem[ (curr->arg)[ n ] + 2 ] = 0 ;
       if (ctpoint < nextuse)
       { /* set slocal */
         putslocal(TRUE, notrick) ;
         ipmem[ (curr->arg)[ n ] ] = notrick ;
       }
     }
   } /* with */
 } /* rsnuse */



static void ptnuse(n) argnr n;{
  qaddr0 nextuse ;
  int notrick ;
  quadruple * curr ; /* gsg for PASCAL WITH translation */

/*  with tuple[ qcurr ] do */
  { curr = tuple + qcurr ; /* gsg PASCAL WITH translation */
    nextuse = ipmem[ (curr->arg)[ n ] + 2 ] ;
    ipmem[ (curr->arg)[ n ] + 2 ] = qcurr ;
    (curr->nxtuse)[ n ] = nextuse ;
    if (ctpoint < nextuse)
    { /* set slocal */
      notrick = ipmem[ (curr->arg)[ n ] ] ;
      putslocal(TRUE,notrick) ;
      ipmem[ (curr->arg)[ n ] ] = notrick ;
    }
  } /* with */
} /* ptnuse */


void back()

 /* SCANS DOWN THE QUADRUPLES TABLE TO ESTABLISH 'NEXT USE' INFORMATION */
 /* OPERATIONS YIELDING NOT REFERENCED RESULTS ARE REPLACED BY 'NOP'==195*/
 /* IF VALUE IS USED AFTER CONTROL TRANSMISSION, THE ATTRIBUTE 'SLOCAL' */
 /*     IS SET.                                                         */

/* LABEL 55 ; */  /* EXIST FROM RSNUSE IF NO NEXT USE */

 { quadruple * curr ; /* gsg for PASCAL WITH translation */
   
   
   /* Back */

   ctpoint = qlast + 1 ;
   qcurr = qlast ;
               /*  FOR QCURR = QLAST DOWNTO 1 */
   while (qcurr > 0) /* DO WITH TUPLE [ QCURR ] DO */
   {   curr = tuple + qcurr ; /* PASCAL WITH translation */
       nouse  =  FALSE ;
       switch ( opdescr[ curr->opcode ] )
       {  case 0 :
	  case 1 : break ;

          case 2 :
	  case 3 :
	  case 4 : ptnuse(1) ;
                   break ;
	      
          case 5 :
	  case 6 : ptnuse(1) ;
	           ptnuse(2) ; 
	           if ( curr->opcode <= 160 ) 
	             ctpoint = qcurr ;
	           break ;
	      
          case 7 : ptnuse(1) ; 
	           ptnuse(2) ; 
	           ptnuse(3) ;
	           break ;
	      
          case 8 :
	  case 9 :
	  case 10 : rsnuse(1) ;
	            break ;
	       
          case 11 :
	  case 12 : rsnuse(1) ;
	            if ( nouse )
	              goto label55 ;
                    ptnuse(2) ;
	            break ;
	       
          case 13 : rsnuse(1) ;
	            if ( nouse )
	              goto label55 ;
                    ptnuse(2) ;
                    ptnuse(3) ;
                    break ;
                
          case 14 :
	  case 15 : rsnuse(1) ;
	            if ( nouse )
	              goto label55 ;
                    rsnuse(2) ;
	            if ( nouse )
	               goto label55 ;
                    if ( curr->opcode > 3 )
	              ptnuse(3) ;
                    break ;
               
       } /* switch */
       label55 :  ;
       qcurr-- ;
   } /* while */
 } /* back */



