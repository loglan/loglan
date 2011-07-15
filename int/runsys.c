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


/* Initialize memory structures for objects, main object and a few goodies
 * more.
 */

void runsys()
{
    word apt, i;
    procaddr father;

    for (i = 0;  i < MAXPROCESS;  i++ ) /* initialize process descriptors */
    {
        process[ i ].used = FALSE;     /* not used */
        process[ i ].mark = -1;               /* initial mark for processes */
        process[ i ].M = NULL;         /* memory not allocated */
        process[ i ].hash = NULL;
    }
    process[ 0 ].M = M;                /* always contains code */
    dispoff = VIRTSC-(lastprot+1);      /* DISPLAY offset in process object */
    disp2off = dispoff-(lastprot+1);    /* indirect DISPLAY offset */
    ready = qinit();         /* initialize Round-Robin queue */
    ranset();              /* init pseudo-random no. generator */

#if OS2
    {
        SEL gsel, lsel;
        DosGetInfoSeg(&gsel, &lsel);
        ginf = MAKEPGINFOSEG(gsel);
    }
#endif

    if (!remote)                     /* create main process */
    {
        father.node = 0;     /* dummy DL for generated process */
        father.pix  = 0;
        father.mark = 0;
        thispix = 0;                       /* current process index */
        thisp = &process[ thispix ];       /* current process descr pointer */
        initprocess((word) 0, (word) MAINBLOCK, &father);
        mainprog = thisp->prochead;        /* am of main */
        c1 = thisp->c1;            /* pointers to current object */
        c2 = thisp->c2;
        ic = thisp->ic;         /* instruction counter */
        param = thisp->param;           /* parameter vector */
        apt = mainprog+M[ mainprog ];      /* LWA+1 of main */
        display = apt+dispoff;         /* DISPLAY in main */
        display2 = apt+disp2off;   /* indirect DISPLAY in main */
        mnoff = 2;                /* offset of variable mainprog */
        storevirt(thisp->procref, mainprog+mnoff);  /* init variable main */
        M[ apt+STATSL ]++;         /* flag main included in SL chain */
        thisp->status = STOPPED;
        activate(thispix);         /* activate main process */
    }
    else  /* remote */
    {
        thispix = 1;                  /* a dirty trick: set junk current */
        thisp = &process[ thispix ];       /* process for first transfer() */
    }                     /* (must save 'context' somewhere) */
#if DLINK
    net_attention();
#endif
}


void initprocess(pix, prot, father)     /* Initialize process descriptor */
word pix, prot;
procaddr *father;
{
    procdescr *p;
    protdescr *ptr;
    word i, j, ah, am, apt;

#ifdef RPCDBG
fprintf(stderr,"new process(n,p,m) (%d,%d,%d)",0,pix,process[pix].mark);
fprintf(stderr," from (%d,%d,%d)\n",father->node,father->pix,father->mark);
#endif

    p = &process[ pix ];
#ifdef OBJECTADDR
    hash_create(p,119);
#endif
    p->used = TRUE;            /* process descriptor is used */
    p->prot = prot;            /* prototype number */
    p->freeitem = 0;         /* null list of free dictionary items */
    p->upper = memorysize-1;       /* highest memory address */
    p->lower = freem;      /* lowest address for data */
    p->headk = p->lower;               /* head of killed objects list */
    p->M[ p->headk ] = MAXAPPT;         /* maximum appetite sentinel */
    p->headk2 = 0;
    ah = p->upper-1;         /* dict. item for process itself */
    p->lastitem = ah;      /* first word used by dictionary */
    ptr = prototype[ prot ];
    if (p->upper - p->lower - ptr->appetite < 512)
        if (prot == MAINBLOCK)
            abend("Memory size too small (use /m option)\n");
        else errsignal(RTEMEMOV);

    /* generate process object */
    p->lastused = p->lower+ptr->appetite;
    am = p->lower+1;
    p->M[ am ] = ptr->appetite;
    p->M[ am+PROTNUM ] = prot;
    for (i = PROTNUM+1;  i < ptr->appetite;  i++)
        p->M[ am+i ] = 0;
    p->M[ ah   ] = am;
    p->M[ ah+1 ] = 0;
    p->prochead = am;
    p->procref.addr = ah;
    p->procref.mark = 0;
    p->c1 = am;                      /* initialize current object ptrs */
    p->c2 = am+ptr->span;
    apt = am+ptr->appetite;
    p->M[ apt+CHD ] = ah;             /* initialize coroutine head ptr */
    p->M[ apt+CHD+1 ] = 0;
    p->M[ apt+SL ] = DUMMY;         /* dummy SL for process */
    p->M[ 1 ] = 1;               /* absolute none */
    for (i = MAINBLOCK;  i <= lastprot;  i++)  /* initialize DISPLAY */
        p->M[ apt+dispoff+i ] = 0;
    p->M[ apt+disp2off+MAINBLOCK ] = DUMMY;     /* dummmy entry for MAIN */
    j = ptr->preflist;           /* set DISPLAY entries for process */

    for (i = j+ptr->lthpreflist-1;  i >= j;  i--)
    {
        p->M[ apt+dispoff+M[ i ] ] = am;       /* physical address */
        p->M[ apt+disp2off+M[ i ] ] = ah;      /* indirect address */
    }

    {
       virtaddr v;
       mess2obj( p, father, &v );
       p->M[ apt+DL ] = v.addr;
       p->M[ apt+DL+1 ] = v.mark;
    }

    p->msgqueue = qinit();
    p->rpcwait = qinit();
    p->rpcmask = sinit();
    pushmask(pix);               /* initialy all RPCs are disabled */
    p->trlnumber = 0;      /* trace line number */
    i = ptr->preflist;           /* search for executable prefix */
    while (prototype[ p->M[ i ] ]->kind == RECORD) i++;
    p->ic = prototype[ M[ i ] ]->codeaddr;  /* first instruction address */
#if RPCDBG
fprintf(stderr,"first instruction address %d of new process %d\n", p->ic, pix );
#endif
    p->force_compactification=FALSE;
}


bool member(virt, am)
virtaddr *virt;
word *am;
{
    *am = M[ virt->addr ];
    return (virt->mark == M[ virt->addr+1 ]);
}


void update(am, ah)                     /* Update DISPLAY */
word am, ah;
{
    word t1, t2, t3, t4, t5, t6;
    protdescr *ptr;

    while (TRUE)
    {
        t1 = am+M[ am ];
        M[ t1+STATSL ]++;               /* flag object included in SL */
        ptr = prototype[ M[ am+PROTNUM ] ];
        t2 = ptr->preflist;
        t3 = t2+ptr->lthpreflist-1;
        for (t4 = t3;  t4 >= t2;  t4-- )
        {
            t6 = M[ t4 ];
            t5 = display+t6;
            if (M[ t5 ] == 0)           /* entry to be updated */
            {
                M[ t5 ] = am;
                M[ display2+t6 ] = ah;
            }
        }
        ah = M[ t1+SL ];
        if (ah == DUMMY) break;
        if (M[ ah+1 ] != M[ t1+SL+1 ])  errsignal(RTESLCOF);
        am = M[ ah ];
    }
}


void loosen()                           /* Loosen DISPLAY */
{
    word t1, t2, t3;
    protdescr *ptr;

    t1 = c1;
    while (TRUE)
    {
        ptr = prototype[ M[ t1+PROTNUM ] ];
        t2 = ptr->preflist;
        for (t3 = t2+ptr->lthpreflist-1;  t3 >= t2;  t3-- )
            M[ display+M[ t3 ] ] = 0;
        t3 = t1+M[ t1 ];
        M[ t3+STATSL ]--;               /* flag object removed from SL */
        t1 = M[ t3+SL ];                /* ah of SL */
        if (t1 == DUMMY) break;         /* still not main */
        t1 = M[ t1 ];                   /* am of SL */
    }
}


static int tracecnt = 0;               /* To count trace messages in line */

void trace(lineno)                      /* Trace the program if debug mode */
word lineno;
{
    thisp->trlnumber = lineno;
    if (debug && lineno > 0)
    {
        tracecnt++;
        if (tracecnt == MAXTRACNT)      /* change line */
        {
            tracecnt = 0;
            fprintf(tracefile, "\n");
        }
        fprintf(tracefile, "%6ld", (long) lineno);
    }
    trapmsg();                       /* check for waiting message */
    rpc2();              /* check for RPC message */
}


void endrun(status)
int status;
{
    fflush(stdout);

/*    fprintf(stderr, "\n\nEnd of LOGLAN-82 program execution\n");fflush(stderr);*/
#if DLINK
    net_logoff();
#endif
    if (debug) fclose(tracefile);
    exit(status);
}


