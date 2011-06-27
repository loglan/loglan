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

#include	"depend.h"
#include	"genint.h"
#include	"int.h"
#include	"process.h"
#include	"intproto.h"

/* Transfer of control routines */

#ifndef NO_PROTOTYPES
static void att2(virtaddr *, word, word);
static void back1(word, word, virtaddr *, word *);
#else
static void att2();
static void back1();
#endif

/* Transfer control to the newly created object.
 */

void go(ah, am)
word ah, am;
{
    protdescr *ptr;
    word pnum, plen, node, apt;
    message msg;

    ptr = prototype[ M[ am+PROTNUM ] ];
    apt = am+M[ am ];
    if (ptr->kind == PROCESS)		/* new process creation */
    {
	thisp->template.addr = ah;	/* save template address */
	thisp->template.mark = M[ ah+1 ];
	msg.control.type = CREATE;
	msg.control.par = M[ am+PROTNUM ];
	moveparams(thispix, am, &msg, PARIN, LOADPAR);
	msg.control.receiver.pix = 0;		/* pix  will create receiver */
	msg.control.receiver.mark= 0;		/* mark will create receiver */
	msg.control.receiver.node = getnode(am);	/* node we decided  */
	sendmsg( &msg);	/* send create request */
#       ifdef RPCDBG
        fprintf(
                stderr, "send new process from %d to node %d\n",
                thispix,
                msg.control.receiver.node
               );
#       endif
	passivate(WAITFORNEW);		/* and wait for return from process */
    }
    else
	if (isprocess((virtaddr*)(M+apt+SL)))	/* remote procedure call */
	{
	    thisp->backobj.addr = ah;	/* save template address */
	    thisp->backobj.mark = M[ ah+1 ];
	    thisp->M[ temporary ] = am;	/* physical address also */
            {
               virtaddr v;
               loadvirt( v, apt+SL );
               obj2mess( M, &v, &msg.control.receiver );
#              ifdef RPCDBG
               fprintf(
                        stderr, "send rpc from process %d to (%d,%d,%d)\n",
                        thispix,
                        msg.control.receiver.node,
                        msg.control.receiver.pix,
                        msg.control.receiver.mark
                      );
#              endif
            }
	    msg.control.type = RPCALL;
	    msg.control.par = M[ am+PROTNUM ];
	    moveparams(thispix, am, &msg, PARIN, LOADPAR);
	    sendmsg( &msg);	/* send RPC request */
	    passivate(WAITFORRPC);	/* and wait for RP return */
	}
	else
	{
	    M[ c1+M[ c1 ]+LSC ] = ic;	/* save local control */
	    loosen();			/* release DISPLAY */
	    update(am, ah);		/* update DISPLAY */
	    c1 = am;			/* new current */
	    c2 = c1+ptr->span;
	    pnum = ptr->preflist;
	    plen = ptr->lthpreflist;
	    while (TRUE)		/* search for executable prefix */
		if (plen <= 1)
		{
		    ic = ptr->codeaddr;
		    break;
		}
		else
		{
		    ptr = prototype[ M[ pnum ] ];
		    plen--;
		    pnum++;
		    if (ptr->kind != RECORD) plen = 0;
		}
	}
}


/* Transfer control to a local unprefixed procedure, function, block,
 * class or coroutine.
 */

void goloc(ah, am)
word ah, am;
{
    word t1;
    protdescr *ptr;

    M[ c1+M[ c1 ]+LSC ] = ic;		/* save local control */
    c1 = am;				/* new current */
    t1 = M[ am+PROTNUM ];
    ptr = prototype[ t1 ];
    c2 = am+ptr->span;
    ic = ptr->codeaddr;
    M[ display+t1 ] = am;		/* simulate update display */
    M[ display2+t1 ] = ah;
    M[ am+M[ am ]+STATSL ]++;
}


void backbl(virt, am)			/* Return from block. */
virtaddr *virt;
word *am;
{
    word t1;

    t1 = M[ c1+PROTNUM ];
    virt->addr = M[ display2+t1 ];
    virt->mark = M[ virt->addr+1 ];	/* prepare old address */
    *am = c1;				/* am of old */
    M[ display+t1 ] = 0;		/* simulate loosen */
    t1 = c1+M[ c1 ];
    M[ t1+STATSL ]--;			/* remove from SL chain */
    c1 = M[ t1+SL ];			/* return up along SL */
    if (c1 == DUMMY) endprocess(0);	/* return from main */
    c1 = M[ c1 ];			/* am of new current */
    c2 = c1+prototype[ M[ c1+PROTNUM ] ]->span;
    ic = M[ c1+M[ c1 ]+LSC ];
    storevirt(*virt, *am+M[ *am ]+DL);	/* force DL consistency */
}


static void back1(at1, at2, virt, am)	/* Common code for some backs below. */
word at1, at2;
virtaddr *virt;
word *am;
{
    word t1;

    loosen();
    if (at1 == 0) endprocess(0);
    t1 = M[ c1+PROTNUM ];
    virt->addr = M[ display2+t1 ];	/* ah of old */
    virt->mark = M[ virt->addr+1 ];
    *am = c1;				/* am of old */
    storevirt(*virt, at2);		/* loop up DL */
    at2 = M[ at1 ];			/* am of DL */
    update(at2, at1);
    c1 = at2;
    c2 = c1 + prototype[ M[ c1+PROTNUM ] ]->span;
    ic = M[ c1+M[ c1 ]+LSC ];
}


/* Return from classes, coroutines and by end from procedures.
 */

void back(virt, am, length)
virtaddr *virt;
word *am;
word length;
{
    word t1, t2, plist;
    int i;
    protdescr *ptr;
    message msg;

    t2 = c1+M[ c1 ];
    t1 = M[ t2+DL ];			/* ah of DL */
    ptr = prototype[ M[ c1+PROTNUM ] ]; /* prototype of current */
    if (ptr->kind == PROCESS)		/* RETURN in process */
    {
#       ifdef RPCDBG
        fprintf( stderr, "return from process %d\n", thispix );
#       endif
	if (M[ c1+PROTNUM ] == MAINBLOCK) endprocess(0);
        {
           virtaddr v;
           loadvirt( v, t2+DL );
           obj2mess( M, &v, &msg.control.receiver ); /* father process */
        }
	msg.control.type = CREACK;
	moveparams(thispix, c1, &msg, PAROUT, LOADPAR);
	sendmsg(&msg);			/* send create acknowledge */
	M[ t2+DL ] = 0; 		/* cut DL of new process head */
	passivate(STOPPED);		/* and suspend new process */
    }
    else
	if (ptr->kind == COROUTINE)
	{
	    if (t1 != 0)		/* nothing if detached */
	    {
		M[ t2+LSC ] = ic;
		back1(t1, t2+DL, virt, am);
	    }
	}
	else
	{
            plist = ic;			/* save begining of prototype list */
	    if (ptr->lthpreflist==1 && t1==M[t2+SL] && M[t2+DL+1]==M[t2+SL+1])
                backbl(virt, am);
	    else
                back1(t1, t2+DL, virt, am);

/*
#           ifdef RPCDBG
            fprintf(
                     stderr, "back (thisp=%d) from %s to %s\n",
                     thispix,
                     (
                       (ptr->kind==PROCEDURE) ?
                         "PROCEDURE"          :
                       (ptr->kind==FUNCTION)  ?
                         "FUNCTION"           :
                         "???"
                     ),
                     isprocess((virtaddr*)(M+t2+RPCDL)) ? "PROCESS" : "OBJECT"
                   );
#           endif
*/
	    if ((ptr->kind == PROCEDURE || ptr->kind == FUNCTION) &&
	   	isprocess((virtaddr*)(M+t2+RPCDL)))
	    {
                {
                   virtaddr v;
                   loadvirt( v, t2+RPCDL );
                   obj2mess( M, &v, &msg.control.receiver ); /* remote DL */
                }
#               ifdef RPCDBG
                fprintf(
                         stderr, "send rpc ack from process %d to (%d,%d,%d)\n",
                         thispix,
                         msg.control.receiver.node,
                         msg.control.receiver.pix,
                         msg.control.receiver.mark
                       );
#               endif
		msg.control.type = RPCACK;
		moveparams(thispix, *am, &msg, PAROUT, LOADPAR);
		sendmsg(&msg);		/* send RP return - acknowledge */
  		gkill(virt);		/* kill procedure object manualy */
  		popmask(thispix);	/* restore RPC mask from stack */
  		for (i = 0;  i < length;  i++)	  /* and modify it */
  		{
  		    t1 = virtprot(M[ plist++ ]);  /* prototype number */
  		    if (t1 > 0) enable(thispix, t1);
  		    else disable(thispix, -t1);
  		}
  		evaluaterpc(thispix);	/* check for enabled RPCs */
	    }
	}
}


/* Return, end in procedures and functions without prefix.
 */

void backpr(virt, am)
virtaddr *virt;
word *am;
{
    word t1, t2, t3;

    t2 = c1+M[ c1 ]+DL; 		/* DL pointer of current */
    t1 = M[ t2 ];			/* ah of DL */
    t3 = c1+M[ c1 ]+SL; 		/* SL pointer */
    if (t1 == M[ t3 ] && M[ t2+1 ] == M[ t3+1 ]) backbl(virt, am);  /* SL=DL */
    else back1(t1, t2, virt, am);
}


void fin(backic, virt, am)		/* End in classes and coroutines. */
word backic;
virtaddr *virt;
word *am;
{
    word t1, t2, knd;

    knd = prototype[ M[ c1+PROTNUM ] ]->kind;
    if (knd != COROUTINE && knd != PROCESS)
	back(virt, am, (word) 0); 	/* a class - exit as above */
    else
    {
	ic = backic;			/* backspace ic */
	t2 = c1+M[ c1 ];
	t1 = M[ t2+DL ];		/* ah of DL */
	if (t1 == 0)
	{
	    if (M[ t2+SL ] == DUMMY) endprocess(0);
	    ic = 0;			/* coroutine terminated */
	    *am = 0;
	    detach();
	}
	else
	{
	    M[ t2+LSC ] = ic;
	    back1(t1, t2+DL, virt, am);
	}
    }
}


static void att2(virt, ax, at1)		/* Helper for attach/detach */
virtaddr *virt;
word ax, at1;
{
    word t1, t2, phead;

    t1 = M[ display2+M[ c1+PROTNUM ] ]; /* ah of current */
    t2 = at1+M[ at1 ]+DL;		/* DL of coroutine head */
    M[ t2 ] = t1;			/* loop up DL */
    M[ t2+1 ] = M[ t1+1 ];
    M[ c1+M[ c1 ]+LSC ] = ic;		/* preserve local control */
    loosen();
    phead = thisp->prochead;
    storevirt(*virt, phead+M[ phead ]+CHD);
    t2 = M[ ax+DL ];
    if (t2 == 0) errsignal(RTECORAC);	/* coroutine active */
    M[ ax+DL ] = 0;			/* cut DL of new coroutine head */
    c1 = M[ t2 ];
    update(c1, t2);
    c2 = c1+prototype[ M[ c1+PROTNUM ] ]->span;
    ic = M[ c1+M[ c1 ]+LSC ];
    if (ic == 0) errsignal(RTECORTM);	/* coroutine terminated */
}


void attach(virt)
virtaddr *virt;
{
    word t1, ax, phead, chead;
    int knd;

    if (M[ virt->addr+1 ] != virt->mark) errsignal(RTEILLAT);
    else ax = M[ virt->addr ];		/* am */
    t1 = M[ ax+PROTNUM ];
    if (t1 == AINT || t1 == AREAL || t1 == AVIRT || t1 == FILEOBJECT)
	errsignal(RTEILLAT);
    knd = prototype[ t1 ]->kind;
    if (knd != COROUTINE && knd != PROCESS) errsignal(RTEILLAT);
    ax = ax+M[ ax ];
    phead = thisp->prochead;
    chead = phead+M[ phead ]+CHD;
    if (virt->addr != M[ chead ] || virt->mark != M[ chead+1 ])
    {
	M[ ax+CL ] = M[ chead ];
	M[ ax+CL+1 ] = M[ chead+1 ];
	att2(virt, ax, M[ M[ chead ] ]);
    }
}


void detach()
{
    virtaddr virt;
    word t1, phead;

    phead = thisp->prochead;
    t1 = M[ M[ phead+M[ phead ]+CHD ] ]; /* am of coroutine head */
    loadvirt(virt, t1+M[ t1 ]+CL);	/* coroutine link */
    if (M[ virt.addr+1 ] != virt.mark) errsignal(RTEILLDT);
    att2(&virt, M[ virt.addr ]+M[ M[ virt.addr ] ], t1);
}


void inner(level)			/* Simulate execution of inner */
word level;
{
    word t1;
    protdescr *ptr;

    ptr = prototype[ M[ c1+PROTNUM ] ]; /* prototype of current */
    t1 = ptr->lthpreflist;
    if (t1 != level)
	if (level == t1-1) ic = ptr->codeaddr;
	else ic = prototype[ M[ ptr->preflist+level ] ]->codeaddr;
}


