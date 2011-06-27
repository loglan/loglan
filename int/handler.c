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
		 tel.  ++33 59923154    fax. ++33 59841696

=======================================================================
*/

#include "depend.h"
#include "genint.h"
#include "int.h"
#include "process.h"
#include "intproto.h"

/* Handler routines */

/* pataud le 13/10/94
#if !NO_GRAPH || !DJE
#if MSDOS
#include "graf\graf.h"
#else
#include "graf/graf.h"
#endif
#endif
*/

void errsignal(exception)
int exception;
{
    word signum, ah, am;

    signum = scot[ exception ];
    if (signum != -1)                   /* attempt to call a handler */
    {
	raise_signal(signum, (word) 0, &ah, &am);
	if (ic != 0)                    /* continue execution */
	{
	    go(ah, am);
	    longjmp(contenv, 1);
	}
    }

#if MSDOS && !NO_GRAPH && !DJE
    {
	extern bool graphmode;

	if (graphmode) groff();
	graphmode = FALSE;
    }
#endif

    putc('\n', stderr);
    switch (exception)
    {
	case RTESLCOF: fprintf(stderr, " SL CHAIN CUT OFF");                    break;
	case RTEUNSTP: fprintf(stderr, " UNIMPLEMENTED STANDARD PROCEDURE");    break;
	case RTEILLAT: fprintf(stderr, " ILLEGAL ATTACH");                      break;
	case RTEILLDT: fprintf(stderr, " ILLEGAL DETACH");                      break;
	case RTECORTM: fprintf(stderr, " COROUTINE TERMINATED");                break;
	case RTECORAC: fprintf(stderr, " COROUTINE ACTIVE");                    break;
	case RTEINVIN: fprintf(stderr, " ARRAY INDEX ERROR");                   break;
	case RTEILLAB: fprintf(stderr, " INCORRECT ARRAY BOUNDS");              break;
	case RTEINCQA: fprintf(stderr, " IMPROPER QUA");                        break;
	case RTEINCAS: fprintf(stderr, " ILLEGAL ASSIGNMENT");                  break;
	case RTEFTPMS: fprintf(stderr, " FORMAL TYPE MISSING");                 break;
	case RTEILLKL: fprintf(stderr, " ILLEGAL KILL");                        break;
	case RTEILLCP: fprintf(stderr, " ILLEGAL COPY");                        break;
	case RTEINCHS: fprintf(stderr, " INCOMPATIBLE HEADERS");                break;
	case RTEHNDNF: fprintf(stderr, " HANDLER NOT FOUND");                   break;
	case RTEMEMOV: fprintf(stderr, " MEMORY OVERFLOW");                     break;
	case RTEFHTLG: fprintf(stderr, " FORMAL LIST TOO LONG");                break;
	case RTEILLRT: fprintf(stderr, " ILLEGAL RETURN");                      break;
	case RTEREFTN: fprintf(stderr, " REFERENCE TO NONE");                   break;
	case RTEDIVBZ: fprintf(stderr, " DIVISION BY ZERO");                    break;
	case RTESYSER: fprintf(stderr, " SYSTEM ERROR");                        break;
	case RTEILLIO: fprintf(stderr, " ILLEGAL I/O OPERATION");               break;
	case RTEIOERR: fprintf(stderr, " I/O ERROR");                           break;
	case RTECNTOP: fprintf(stderr, " CANNOT OPEN FILE");                    break;
	case RTEBADFM: fprintf(stderr, " INPUT DATA FORMAT BAD");               break;
	case RTEILLRS: fprintf(stderr, " ILLEGAL RESUME");                      break;
	case RTETMPRC: fprintf(stderr, " TOO MANY PROCESSES ON ONE MACHINE");   break;
	case RTEINVND: fprintf(stderr, " INVALID NODE NUMBER");                 break;
	case RTENEGST: fprintf(stderr, " NEGATIVE STEP VALUE");                 break;
	case RTENONGL: fprintf(stderr, " REFERENCE TO GLOBAL NON PROCESS OBJECT FROM PROCESS");                 break;
	default      : fprintf(stderr, " UNRECOGNIZED ERROR");
    }
    if (thisp->trlnumber < 0) thisp->trlnumber = - thisp->trlnumber;
    if (thisp->trlnumber != 0)
	fprintf(stderr, "\n AT LINE: %ld\n", (long) thisp->trlnumber);
    endprocess(4);
} /* end errsignal */


void raise_signal(signal, skip, ahnew, amnew)   /* Raise exception */
word signal, skip;
word *ahnew, *amnew;
{
    word t1, t2, t3, t4, t5, virts;
    protdescr *ptr;

    t1 = 0;                             /* handler for others = no */
    t2 = M[ display2+M[ c1+PROTNUM ] ]; /* ah of current */
    t3 = c1;                            /* am of current */
    t5 = 0;                             /* flag handler not found */
    do
    {
	ptr = prototype[ M[ t3+PROTNUM ] ]; /* prototype of current */
	t4 = ptr->handlerlist;
	if (t4 != 0)                    /* any handlers ? */
	{
	    do
	    {
		t5 = M[ t4 ];           /* signal number */
		if (t5 != signal)
		{
		    if (t5 == 0 && t1 == 0) t1 = t4;
		    t4 = M[ t4+2 ];
		}
	    } while (t5 != signal && t4 != 0);
	}
	if (t5 != signal)               /* look in DL or SL */
	{
	    if (t1 != 0) t4 = t1;       /* handler for others found */
	    else
	    {
		t4 = t3+M[ t3 ];
		if (ptr->kind == HANDLER)
		    t2 = M[ t4+SL ];    /* use SL for handlers */
		else
		    t2 = M[ t4+DL ];    /* or DL for other goodies */
		if (t2 == 0)            /* handler not found */
		{
		    if (signal <= MAXSYSSN)
		    {                   /* system signal */
			ic = skip;
			if (ic != 0) longjmp(contenv, 1);
			else return;
		    }
		    else errsignal(RTEHNDNF);
		}
		t3 = M[ t2 ];
	    }
	}
	else t1 = 0;
    } while (t1 == 0 && t5 != signal);

    virts = thisp->prochead+M[ thisp->prochead ]+VIRTSC;
    M[ virts ] = t2;                    /* compactification possible */
    M[ virts+1 ] = M[ t2+1 ];
    t3 = M[ t4+1 ];                     /* prototype number of handler */
    t5 = prototype[ t3 ]->appetite;
    if (t1 != 0)                        /* others */
    {
	request(t5, ahnew, amnew);
	M[ *amnew+M[ *amnew ]+SIGNR ] = 0;
    }
    else
    {
	if (signal == scot[ RTEMEMOV ] &&
	    thisp->lastitem-thisp->lastused-1 < t5)
	{
	    scot[ RTEMEMOV ] = -1;      /* make memov look like abort */
	    errsignal(RTEMEMOV);
	}
	request(t5, ahnew, amnew);
	M[ *amnew+M[ *amnew ]+SIGNR ] = signal;
    }
    M[ *amnew+PROTNUM ] = t3;           /* provide system attributes */
    t5 = *amnew+M[ *amnew ];
    M[ t5+SL ] = M[ virts ];
    M[ t5+SL+1 ] = M[ virts+1 ];
    t2 = M[ display2+M[ c1+PROTNUM ] ]; /* ah of current */
    M[ t5+DL ] = t2;
    M[ t5+DL+1 ] = M[ t2+1 ];
    if (t1 != 0)                        /* skip */
    {
	ic = skip;
	go(*ahnew, *amnew);
    }
} /* end raise_signal */


void wind()
{
    word t1, t2;

    t1 = M[ M[ c1+M[ c1 ]+SL ] ];       /* am of handlers' SL */
    t2 = c1;                            /* current */
    while (TRUE)
    {
	t2 = M[ M[ t2+M[ t2 ]+DL ] ];   /* am of DL */
	if (t2 == t1) break;
	M[ t2+M[ t2 ]+LSC ] = prototype[ M[ t2+PROTNUM ] ]->lastwill;
    }
    back(&thisp->backobj, &M[ temporary ], (word) 0);
} /* end wind */


void term()
{
    word t1;

    t1 = M[ M[ c1+M[ c1 ]+SL ] ];       /* am of handlers' SL */
    M[ t1+M[ t1 ]+LSC ] = prototype[ M[ t1+PROTNUM ] ]->lastwill;
    wind();
} /* end term */


/* This wraps up the above series of the handler procedures.
 */

void backhd(virt, am)
virtaddr *virt;
word *am;
{
    if (M[ c1+M[ c1 ]+SIGNR ] <= MAXSYSSN)
	errsignal(RTEILLRT);            /* illegal return */
    else
	back(virt, am, (word) 0);
} /* end backhd */

