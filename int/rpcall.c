#include        "depend.h"
#include        "genint.h"
#include        "int.h"
#include	"process.h"
#include	"intproto.h"


#ifndef NO_PROTOTYPES
static bool isenabled(word,word);
static bool rpcready(word);
static void bitaccess(word,word,int *,char *);
static void dupmask(word);
#else
static bool isenabled();
static bool rpcready();
static void bitaccess();
static void dupmask();
#endif


void rpc1(msg)				/* preprocess RPC request */
message *msg;
{
    word pix, prot;
    procdescr *p;
    message *msg1;

    pix = msg->control.receiver.pix;
    p = &process[ pix ];
    if (p->mark != msg->control.receiver.mark)
    	senderr(RTEREFTN, &msg->control.sender);
    msg1 = (message *) ballocate(sizeof(message));
    if (msg1 == NULL) errsignal(RTEMEMOV);
    moveblock((char *) msg, (char *) msg1, (word) sizeof(message));
    prot = msg->control.par;
    if (isenabled(pix, prot))
    {
        p->msgqueue = minsert(p->msgqueue, msg1);
	if (p->status == ACCEPTING) activate(pix);
    }
    else p->rpcwait = minsert(p->rpcwait, msg1);
}


void rpc2()
{
    if (rpcready(thispix)) rpc3();
}


void rpc3()				/* Actual remote procedure call */
{
    word prot, ah, am;
    message *msg;

    msg = mfront(thisp->msgqueue);	/* remove first RPC message (enabled) */
#   ifdef RPCDBG
    fprintf(
             stderr, "rpc(thisp=%d) from: node=%d, pix=%d, mark=%d\n",
             thispix,
             msg->control.sender.node,
             msg->control.sender.pix,
             msg->control.sender.mark
           );
#   endif
    thisp->msgqueue = qremove(thisp->msgqueue);
    pushmask(thispix);			/* disable all procedures */
    prot = msg->control.par;

    slopen(prot, &thisp->procref, &ah, &am);	/* open procedure object */

    {
       virtaddr v;
       mess2obj( thisp, &(msg->control.sender), &v );
       storevirt( v, am+M[ am ]+RPCDL );	 /* set up remote DL */
    }

    moveparams(thispix, am, msg, PARIN, SAVEPAR);

    go(ah, am);				/* transfer control to procedure */

    free(msg);

}


void rpcend(msg)			/* After return from RPC */
message *msg;
{
    word pix, am;
    procdescr *p;

    pix = msg->control.receiver.pix;
#ifdef RPCDBG
fprintf(stderr,"activate after rpc(thisp=%d)\n",pix);fflush(stderr);
#endif
    p = &process[ pix ];
    am = p->M[ temporary ];		/* template physical address */
    moveparams(pix, am, msg, PAROUT, SAVEPAR);
    activate(pix);			/* resume process waiting for RPC */
}


static void bitaccess(pix, prot, bytenr, bitmask)
word pix, prot;
int *bytenr;
char *bitmask;
{
    int bitnr;

    bitnr = prot-prototype[ process[ pix ].prot ]->maskbase;
    *bytenr = bitnr / 8;
    *bitmask = (char)(unsigned char)( 1 << (bitnr % 8) );
}


void enable(pix, prot)			/* Enable remote procedure */
word pix, prot;
{
    mask m;
    int bytenr;
    char bitmask;

    m = top(process[ pix ].rpcmask);
    bitaccess(pix, prot, &bytenr, &bitmask);
    m[ bytenr ] |= bitmask;
}


void disable(pix, prot)			/* Disable remote procedure */
word pix, prot;
{
    mask m;
    int bytenr;
    char bitmask;

    m = top(process[ pix ].rpcmask);
    bitaccess(pix, prot, &bytenr, &bitmask);
    m[ bytenr ] &= ~ bitmask;
}


static bool isenabled(pix, prot)		/* Check if RPC allowed */
word pix, prot;
{
    mask m;
    int bytenr;
    char bitmask;

    m = top(process[ pix ].rpcmask);
    bitaccess(pix, prot, &bytenr, &bitmask);
    return( m[ bytenr ] & bitmask );
}


void pushmask(pix)			/* Push empty RPC mask onto stack */
word pix;
{
    mask m;
    int i, size;

    size = prototype[ process[ pix ].prot ]->masksize;
    m = (mask) ballocate(size);
    if (m == NULL) errsignal(RTEMEMOV);
    for (i = 0;  i < size;  i++ )  m[ i ] = '\0';	/* disable all */
    process[ pix ].rpcmask = push(process[ pix ].rpcmask, m);
}


static void dupmask(pix)		/* Duplicate RPC mask from stack top */
word pix;
{
    mask m;
    int size;

    size = prototype[ process[ pix ].prot ]->masksize;
    m = (mask) ballocate(size);
    if (m == NULL) errsignal(RTEMEMOV);
    moveblock(top(process[ pix ].rpcmask), m, (word) size);
    process[ pix ].rpcmask = push(process[ pix ].rpcmask, m);
}


void popmask(pix)			/* Pop RPC mask from stack (restore) */
word pix;
{
    mask m;

    m = top(process[ pix ].rpcmask);
    process[ pix ].rpcmask = pop(process[ pix ].rpcmask);
    free((char *) m);
}


void evaluaterpc(pix)		/* Check if any waiting RPC is enabled */
word pix;
{
    queue q;
    message *msg;

    q = process[ pix ].rpcwait;
    if (!qempty(q))
    {
    	do
    	{
    	    msg = mfront(q);
    	    if (isenabled(pix, msg->control.par))
	    {
		process[ pix ].msgqueue = mpush(process[ pix ].msgqueue, msg);
		process[ pix ].rpcwait = mdelete(process[ pix ].rpcwait, msg);
		return;
	    }
	    q = qrotate(q);
	} while (q != process[ pix ].rpcwait);
    }
}


void rpc_accept(length)			/* Accept remote procedure call */
word length;
{
    int i;

    dupmask(thispix);
    for (i = 0;  i < length;  i++)
    	enable(thispix, virtprot(M[ ic++ ]));
    evaluaterpc(thispix);
    if (!rpcready(thispix))
        passivate(ACCEPTING);
}


static bool rpcready(pix)
word pix;
{
    procdescr *p;
    message *msg;
    word prot;

    p = &process[ pix ];
    while (!qempty(p->msgqueue))
    {
        msg = mfront(p->msgqueue);
        prot = msg->control.par;
        if (isenabled(pix, prot))  return(TRUE);
	p->msgqueue = qremove(p->msgqueue);
	p->rpcwait = minsert(p->rpcwait, msg);
    }
    return(FALSE);
}


word virtprot(prot)			/* Get actual prototype for virtual */
word prot;
{
    bool sign;
    word virtnr;

    sign = (prot < 0);
    prot = absolute(prot);
    virtnr = prototype[ prot ]->virtnumber;
    if (virtnr != -1) prot = M[ prototype[ thisp->prot ]->virtlist+virtnr ];
    if (sign) return(-prot);  else return(prot);
}


