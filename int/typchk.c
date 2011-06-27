     /* Loglan82 Compiler&Interpreter
     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw
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

#include        "depend.h"
#include        "genint.h"
#include        "int.h"
#include        "process.h"
#include        "intproto.h"

/* Type checking routines */


/* Determine if prot occurs in the prefix sequence of object am
 */

#ifndef NO_PROTOTYPES
static bool pref(word,word);
static bool typep0(word,word,bool,word *,word *);
static bool prefh(word,word);
static bool typef(word,word,word,word);
#else
static bool pref();
static bool typep0();
static bool prefh();
static bool typef();
#endif


static bool pref(am, prot)
word am, prot;
{
    word t1, t2;
    protdescr *ptr;

    t1 = M[ am+PROTNUM ];
    if (t1 != AINT && t1 != AVIRT && t1 != AREAL && t1 != FILEOBJECT)
    {                                   /* neither array nor file */
        ptr = prototype[ t1 ];
        t1 = ptr->preflist;
        t2 = t1+ptr->lthpreflist;
        while (t1 < t2)
        {
            if (prot == M[ t1 ]) return (TRUE);
            t1++;
        }
    }
    return (FALSE);
} /* end pref */


void qua(virt, tp)                      /* Validate qualification of object */
virtaddr *virt;
word tp;
{
    if (virt->mark != M[ virt->addr+1 ]) errsignal(RTEREFTN);
    if (M[ tp ] != CLASSTYPE) errsignal(RTEINCQA);
    if (!pref(M[ virt->addr ], M[ tp+1 ])) errsignal(RTEINCQA);
} /* end qua */


bool inl(virt, tp)                      /* Determine if A in B */
virtaddr *virt;
word tp;
{
    if (virt->mark != M[ virt->addr+1 ])
        return (TRUE);                  /* none is in everything */
    else
        if (M[ tp ] != CLASSTYPE) return (FALSE);
        else return (pref(M[ virt->addr ], M[ tp+1 ]));
} /* end inl */


bool is(virt, tp)                       /* Determine if A is B */
virtaddr *virt;
word tp;
{
    if (virt->mark != M[ virt->addr+1 ] || M[ tp ] != CLASSTYPE)
        return (FALSE);
    else return (M[ M[ virt->addr ]+PROTNUM ] == M[ tp+1 ]);
} /* end is */


/* Check correctness of an especially clumsy assignment statement
 */

void typref(virt, tp)
virtaddr *virt;
word tp;
{
    word t1, t2, t3;
    int knd;

    if (virt->mark == M[ virt->addr+1 ])   /* none always allowed */
    {
        t3 = M[ virt->addr ];           /* am of right hand side */
        t1 = M[ t3+PROTNUM ];
        if (t1 == AINT || t1 == AREAL || t1 == AVIRT) errsignal(RTEINCAS);
        t2 = M[ tp ];                   /* right hand side type */
        if (t2 == FILETYPE)
        {
            if (t1 != FILEOBJECT) errsignal(RTEINCAS);
        }
        else
            if (t2 == PURECOROUTINE || t2 == PUREPROCESS)
            {
                if (t2 == PURECOROUTINE) knd = COROUTINE;
                else knd = PROCESS;
                if (prototype[ t1 ]->kind != knd) errsignal(RTEINCAS);
            }
            else
            {
                if (t2 != CLASSTYPE) errsignal(RTEINCAS);
                if (!pref(t3, M[ tp+1 ])) errsignal(RTEINCAS);
            }
    }
} /* end typref */


/* Check correctness of a dynamic assignment
 */

void typed(ldim, lt, rdim, rt, virt)
word ldim, lt, rdim, rt;
virtaddr *virt;
{
    if (ldim != rdim) errsignal(RTEINCAS);
    if (ldim == 0) typref(virt, lt);
    else
        if (lt != rt) errsignal(RTEINCAS);
} /* end typed */


/* Search the SL chain of object am to find the nearest Y such that Y in A.
 * prot = prototype number of A
 */

word loadt(am, prot)
word am, prot;
{
    word t1, t2, t3, t4;

    while( !pref(am, prot) )
    {
        t1 = am+M[ am ]+SL;
        t2 = M[ t1 ];                   /* try next object in chain */
        t3 = M[ t1+1 ];
        t4 = M[ t2+1 ];
        if( t3 != t4 )   errsignal( RTEFTPMS );
        am = M[ t2 ];
    }
    return (am);
}


/* Compute type of a formal parameter - see also typep (below). */

static bool typep0(am, pdaddr, protp, dim, tp)
word am, pdaddr;
bool protp;
word *dim, *tp;
{
    word t1;
    protdescr *ptr;

    if (protp)                          /* prototype number on input */
    {
        ptr = prototype[ pdaddr ];
        *dim = ptr->nrarray;
        *tp = ptr->finaltype;
    }
    else                                /* type address on input */
    {
        *dim = M[ pdaddr+1 ];
        *tp = M[ pdaddr+2 ];
    }
    if (M[ *tp ] != FORMTYPE) return (TRUE);
    else
    {
        t1 = M[ *tp+1 ];                /* SL prototype number */
        if (t1 == DUMMY) return (FALSE);
        else                            /* undefined */
        {
            *tp = loadt(am, t1)+M[ *tp+2 ];
            *dim += M[ *tp ];           /* accumulate dim */
            *tp = M[ *tp+1 ];
            return (TRUE);             /* AIL 1989.02.02 */
        }
    }
} /* end typep0 */


void typep(am, nr, dim, tp)             /* Compute type of formal parameter */
word am, nr;
word *dim, *tp;
{
    if (!typep0(am, M[ prototype[ M[ am+PROTNUM ] ]->pfdescr+nr ],
                FALSE, dim, tp)) errsignal(RTESYSER);
} /* end typep */


/* Auxiliary function for heads, almost the same as pref.
 */

static bool prefh(tp, prot)
word tp, prot;
{
    word t1, t2;
    protdescr *ptr;

    ptr = prototype[ M[ tp+1 ] ];
    t2 = ptr->preflist;
    t1 = t2+ptr->lthpreflist-1;
    do
    {
        if (M[ t1 ] == prot) return (TRUE);
        else t1--;
    } while (t1 >= t2);
    return (FALSE);
} /* end prefh */


/* Check compatibility of generalized types, used by heads only.
 */

static bool typef(dima, ta, dimb, tb)
word dima, ta, dimb, tb;
{
    word t1, t2;
    int knd;

    if (dima != dimb) errsignal(RTEINCHS);  /* incompatible headers */
    if (ta != tb)                       /* types different somehow */
    {
        if (dima != 0) errsignal(RTEINCHS); /* dim must be 0 now */
        t1 = M[ ta ];
        t2 = M[ tb ];
        if (t1 == PRIMITIVETYPE || t1 == FILETYPE) errsignal(RTEINCHS);
        if (t2 == PRIMITIVETYPE || t2 == FILETYPE) errsignal(RTEINCHS);
        if (t1 != PURECOROUTINE && t1 != PUREPROCESS)
        {
            if (t2 == PURECOROUTINE || t2 == PUREPROCESS) return (TRUE);
            else
            {
                if (!prefh(ta, M[ tb+1 ]))
                {
                    if (!prefh(tb, M[ ta+1 ])) errsignal(RTEINCHS);
                    else return (TRUE);
                }
            }
        }
        else                            /* something pure */
        {
            if (t1 != t2)
            {
                /*  AIL : t1 below replaced with t2, 1989.02.02 */
              /*  if (t1 == PURECOROUTINE || t1 == PUREPROCESS) */
                if (t2 == PURECOROUTINE || t2 == PUREPROCESS)
                    knd = RECORD;       /* used as junk */
                else knd = prototype[ M[ tb+1 ] ]->kind;

                if ((t1 == PURECOROUTINE && knd != COROUTINE) ||
                    (t1 == PUREPROCESS   && knd != PROCESS))
                {
                    if ((t1 != PURECOROUTINE) ||
                        (knd != PROCESS && t2 != PUREPROCESS))
                        return (TRUE);
                }
            }
        }
    }
    return (FALSE);
} /* end typef */


/* Verify the compatibility of formal/actual procedure (function) heads.
 */

void heads(virt, nr)
virtaddr *virt;
word nr;
{
    word i, j, fp, gp, oba, g, slen, dim, t1, t2, tp, ftv;
    protdescr *ptr;
    bool junk;
    word x[ MAXHDLEN+1 ], y[ MAXHDLEN+1 ];
    /* The two arrays declared above may be dynamically generated as objects */
    /* upon entry to heads. In fact heads was implemented this way in the    */
    /* original LOGLAN running system on MERA-400                            */
    
    oba = M[ virt->addr ];
    ptr = prototype[ M[ oba+PROTNUM ] ];
    fp = M[ ptr->pfdescr+nr ];		/* parameter description pointer */
    slen = M[ fp+2 ];			/* length of its desclist */
    if (slen > MAXHDLEN) errsignal(RTEFHTLG);
    ftv = oba+M[ ptr->parlist+nr ];	/* type value pointer */
    g = M[ ftv ];
    if (M[ ftv+1 ] == M[ g+1 ])		/* not none */
        g = M[ g ];			/* am of SL */
    else errsignal(RTESLCOF);		/* SL chain cut off */
    gp = M[ ftv+2 ];			/* prototype number of g */
    ptr = prototype[ gp ];
    t2 = M[ fp ];			/* t2 = F-kind */
    if (ptr->kind == FUNCTION)
    {
        if (t2 != FORMFUNC) errsignal(RTEINCHS);
	junk = typep0(g, gp, TRUE, &dim, &tp);
	junk = typep0(oba, fp+2, FALSE, &t1, &t2);
	if (typef(dim, tp, t1, t2)) errsignal(RTEINCHS);
    }
    else
        if (t2 != FORMPROC) errsignal(RTEINCHS);
    if (slen != ptr->lthparlist)	/* incompatible lengths */
        errsignal(RTEINCHS);
    t1 = M[ fp+1 ]-1;			/* oba descriptlist */
    t2 = ptr->pfdescr-1;		/* g   descriptlist */
    for (i = 1;  i <= slen;  i++ )	/* verify second order lists */
    {
        x[ i ] = DUMMY;			/* mark entry as empty */
        y[ i ] = DUMMY;
	fp = M[ t1+i ];			/* first type pointer */
	gp = M[ t2+i ];			/* second type pointer */
	tp = M[ fp ];			/* first type ordinal */
	if (tp != M[ gp ]) errsignal(RTEINCHS);
	if (tp == FORMTYPE)
	{
	    x[ i ] = fp;		/* save pointers to formal types */
	    y[ i ] = gp;
	}
	else
	{
	    if (tp == PARIN || tp == PAROUT || tp == PARINOUT)
	    {
        /*  AIL 1989.02.02 */
	    /*    if (typep0(oba, fp, FALSE, &dim, &tp)) */
	        if (! typep0(oba, fp, FALSE, &dim, &tp))
		{			/* undefined yet */
					/* search preceding formals */
		    for (j = 1;  j <= i;  j++ )
		        if (x[ j ] == M[ fp+2 ])
			    break;
		    if (j > i) errsignal(RTEINCHS);
		    if (y[ j ] != M[ gp+2 ]) errsignal(RTEINCHS);
		}
		else			/* already defined */
		{
		    for (j = 1;  j <= i;  j++ )
		        if (y [ j ] == M[ gp+2 ])
			    errsignal(RTEINCHS);
		    junk = typep0(g, gp, FALSE, &j, &ftv);
		    junk = typef(dim, tp, j, ftv);
		}
	    }
	}
    }
}

