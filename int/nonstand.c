#include "depend.h"
#include "genint.h"
#include "int.h"
#include "process.h"
#include "intproto.h"

#include "nonstand.h"

/* Call (non)standard procedures.
 * Almost totaly implementation dependent.
 */

bool graphmode = FALSE;			/* TRUE iff graphics mode active */


#ifndef NO_GRAPH
#  if DJE
#     include "svga1.c"
#  elif MSDOS
#     include "dosgraf1.c"
#  elif UNIX
#     include "x11graf1.c"
#  endif
#endif



void nonstandard(nrproc)		/* Call (non)standard procedure */
word nrproc;
{

   word am;
   int cnt=0;
   float r1, r2;
   word ax,bx,cx,dx,i,t1,t2;
   unsigned int v,p,h,l,r,c;
   unsigned int Res_graph_X,Res_graph_Y;

    switch ((int) nrproc)
    {


#ifndef NO_GRAPH
#  if DJE
#     include "svga2.c"	
#  elif MSDOS
#     include "dosgraf2.c"
#  elif OS2
#     include "os2graf2.c"
#  elif UNIX
#     include "x11graf2.c"
#  else only /*INKEY defined */
	  case INKEY:    
	        param[ 0 ].xword = inkey();
		     break;
#  endif
#endif

	default  :
		errsignal(RTEUNSTP);
    }
}

