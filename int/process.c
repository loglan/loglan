#include "depend.h"
#include "genint.h"
#include "int.h"
#include "process.h"
#include "intproto.h"

#if DLINK
#  include "dlink.h"
#elif TCPIP
#  include "tcpip.h"
#endif

#include <assert.h>


/* Process management */

procdescr process[ MAXPROCESS ];     /* process descriptor table         */
procdescr *thisp;                    /* pointer to current process descr */
word thispix;                        /* current process index            */
queue ready;                         /* Round-Robin queue                */
bool network;                        /* TRUE if operating in network     */
message globmsgqueue[ MAXMSGQUEUE ]; /* queue of waiting messages        */
int msgready = 0;                    /* number of waiting messages       */
int msghead = 0, msgtail = 0;        /* pointers to message queue        */
word ournode;                        /* this machine node number         */
word console;                        /* console node number              */
bool remote = FALSE;                 /* TRUE if remote node              */
bool reschedule = TRUE;              /* TRUE if must re-schedule         */



#ifndef NO_PROTOTYPES
static void ansprot(message *);
static void localkill(message *);
void transfer(word);
static void backcreate(message *);
static void createprocess(message *);
static void localerror(message *);
static void killprocess(word);
static void mkglobal(word);
word pix, ref;
#else
static void ansprot();
static void localkill();
void transfer();
static void backcreate();
static void createprocess();
static void localerror();
static void killprocess();
static void mkglobal();
#endif



#if OS2
PGINFOSEG ginf;                         /* pointer to Global Info Segment */
#endif


#if USE_ALARM
#  include <signal.h>
#  ifndef NO_PROTOTYPES
      static void signal_catch( void );
#  else
      static void signal_catch();
#  endif
   static void signal_catch(){   reschedule=TRUE;   }
#endif


void init_scheduler(){
#if USE_ALARM
   signal(SIGALRM,signal_catch);
   alarm(1);
#endif
}

void schedule()                      /* Choose next ready process to exec */
{                                    /* STRONGLY machine dependent        */
#if USE_ALARM
    if(reschedule){
        alarm(0);
        signal(SIGALRM,signal_catch);
        alarm(1);
#elif USE_CLOCK
    static char last;
    char c;
    c = clock() >> 5;                   /* the most expensive method */
    if (reschedule || c != last)        /* context switch is needed  */
    {
        last = c;
#elif MSDOS && ( WORD_16BIT || DWORD_16BIT ) /* DOS real memory model */
    static char last;
    char c;
    static char *clk = (char *) 0x0040006CL;
    c = *clk >> 1;
    if (reschedule || c != last)        /* context switch is needed */
    {
        last = c;
#elif OS2
    static char last;
    char c;
    c = ginf->hundredths >> 3;
    if (reschedule || c != last)        /* context switch is needed */
    {
        last = c;
#else
#error Scheduler time counting method not implemented !
#endif

#if TCPIP
        while (qempty(ready)){    /* wait for event if no processes  */
            tcpip_poll( -1 );     /* wait for message until arrives  */
            trapmsg();
        }
#else
        while (qempty(ready))     /* wait for event if no processes  */
            trapmsg();
#endif
        ready = qrotate(ready);        /* find another ready process */
        transfer(pfront(ready));       /* transfer control to it     */
        reschedule = FALSE;
    }
}


void transfer(pix)           /* Context switch to another process */
word pix;
{
    word apt;

    if (pix == thispix) return;         /* optimized for case of one process */

    if( thisp != NULL )            /* previous process is alive */
    {
        thisp->ic = ic;            /* store previous context */
        thisp->c1 = c1;
        thisp->c2 = c2;
    }

    thispix = pix;               /* and load new context */
    thisp = &process[ thispix ];
    ic = thisp->ic;
    c1 = thisp->c1;
    c2 = thisp->c2;
    M = thisp->M;
    param = thisp->param;
    apt = thisp->prochead+M[ thisp->prochead ];
    display = apt+dispoff;
    display2 = apt+disp2off;
}


void activate(pix)               /* Resume process on this node */
word pix;
{
    process[ pix ].status = EXECUTING;  /* flag process as ready to execute */
    ready = pinsert(ready, pix);        /* insert into ready queue */
    reschedule = TRUE;           /* force context switch */
#   ifdef RPCDBG
    fprintf(stderr,"activate process %d\n",pix);
#   endif
}


void passivate(newstatus)             /* Passivate process */
int newstatus;
{
    thisp->status = newstatus;   /* change to some wait status */
    ready = qremove(ready);         /* remove from ready queue */
    reschedule = TRUE;           /* force context switch */
#   ifdef RPCDBG
    fprintf(stderr,"passivate process %d to state %d\n",thispix,newstatus);
#   endif
}


/* Copy parameters from object to message or vice versa. */


void moveparams(pix, am, msg, par1, dir)
   word pix, am;
   message *msg;
   int par1, dir;
{
   protdescr *ptr;
   procdescr *p;
   word i, tpd, ap, pd, prim, offset;
   char *cp;
   bool cflag, convert;

   p = &process[ pix ];
   ptr = prototype[ p->M[ am+PROTNUM ] ];
   cp = (char *) msg->params;

   for (i = 0;  i < ptr->lthparlist;  i++)      /* loop through parameters */
   {

      offset = M[ ptr->parlist+i ];
      tpd = M[ ptr->pfdescr+i ];        /* type description of param */
      pd = M[ tpd ];

      if (par1 == PARIN)
         cflag = ( pd==PARIN || pd==PARINOUT || pd==FORMFUNC || pd==FORMPROC );
      else
         cflag = ( pd==PAROUT || pd==PARINOUT );

      if (cflag)
      {
         if (pd == FORMFUNC || pd == FORMPROC)
         {
            ap = APFMPROC;
            convert = TRUE;
         }
         else
            if (M[ M[ tpd+2 ] ] == CLASSTYPE)
            {
               ap = APREF;
               convert = TRUE;
            }
            else
            {
               prim = M[ tpd+2 ]-ipradr;
               ap = primapet[ prim ];
               convert = (prim == 4 || prim == 5); /* process or coroutine */
            }

         ap *= sizeof(word);       /* param appetite in bytes */

         switch (dir)           /* copy parameter in right direction */
         {

            case LOADPAR :

               /* we always load parameters from OUR process */
               assert(pix==thispix);

               if (convert){
                  procaddr pa;
                  {
                     word ah=M[am+offset];
                     if( !isprocess((virtaddr*)(M+am+offset)) &&
                         M[ ah+1 ] == M[ am+offset+1 ]
                        )
                        if (prototype[ M[ M[ ah ]+PROTNUM ] ]->kind == PROCESS)
                        {
                           pa.node = ournode;
                           pa.pix  = pix;
                           pa.mark = thisp->mark;
                        }
                       else
                         /*pat  errsignal(RTENONGL); */ /* only process may be global */
                    /*pat*/ obj2mess(p->M,(virtaddr*)(p->M+am+offset),&pa);
                     else
                        obj2mess(M,(virtaddr*)(M+am+offset),&pa);
                  }
/*
                  mkglobal(am+offset);
                  obj2mess(p->M,(virtaddr*)(p->M+am+offset),&pa);
*/
                  moveblock((char *)&pa, cp, ap=sizeof(procaddr));
               }else
                  moveblock((char *) &p->M[ am+offset ], cp, ap);
               break;


            case SAVEPAR :

               if (convert){
                  procaddr pa;
                  ap=sizeof(procaddr);
                  moveblock(cp,(char *)&pa, ap);
                  mess2obj(p,&pa,(virtaddr*)(p->M+am+offset));
               }else
                  moveblock(cp, (char *) &p->M[ am+offset ], ap);
               break;

         }

         cp += ap;
         assert(cp-msg->params <= sizeof(msg->params));
      }
   }
}


word getnode(am)                     /* Determine node number for process */
word am;
{
    protdescr *ptr;
    word p;
    int i;

    p = prototype[ M[ am+PROTNUM ] ]->preflist;
    while (prototype[ M[ p ] ]->kind != PROCESS)  p++;
    ptr = prototype[ M[ p ] ];
    if (ptr->lthpreflist == 1) i = 0;
    else i = prototype[ M[ p-1 ] ]->lthparlist;
    return (M[ am+M[ ptr->parlist+i ] ]);
}


void resume(virt)                  /* Perform RESUME instruction */
virtaddr *virt;
{
    message msg;

    if (isprocess(virt))               /* is it process realy ? */
    {
        msg.control.type = RESUME;
        obj2mess( M, virt, &msg.control.receiver );
        sendmsg( &msg);  /* request remote resume */
    }
    else errsignal(RTEILLRS);     /* illegal RESUME */
}


static void createprocess(msg)           /* Create new process */
message *msg;
{
    word i, prot;

    for (i = 0;  i < MAXPROCESS;  i++)  /* find unused process descr. */
        if (!process[ i ].used && process[ i ].mark != -MAXMARKER) break;
    if (i == MAXPROCESS) senderr(RTETMPRC, &(msg->control.sender) );
    if (process[ i ].M == NULL)         /* memory not allocated yet */
    {
        process[ i ].M = mallocate(memorysize+1);
        if (process[ i ].M == NULL) senderr(RTEMEMOV, &msg->control.sender);
        moveblock((char *) process[ 0 ].M, (char *) process[ i ].M,
                  freem * sizeof(word));
    }
    prot = msg->control.par;       /* process prototype number */
    initprocess(i, prot, &msg->control.sender);
    moveparams(i, process[ i ].prochead, msg, PARIN, SAVEPAR);
    process[ i ].status = GENERATING;   /* execute process until RETURN */
    ready = pinsert(ready, i);
    reschedule = TRUE;
}


static void killprocess(pix)         /* Release process descriptor */
word pix;
{
    qfree(process[ pix ].msgqueue);
    qfree(process[ pix ].rpcwait);
    sfree(process[ pix ].rpcmask);

    process[ pix ].used = FALSE;        /* mark descriptor as unused */
    process[ pix ].mark--;           /* decrement marker */

    if( pix == thispix )
    {
        thispix = -1;
        thisp = NULL;
    }
}


static void localkill(msg)
message *msg;
{
    word pix;

    pix = msg->control.receiver.pix;

#   if RPCDBG
    fprintf( stderr, "kill process %d\n", pix );
#   endif

    if (process[ pix ].mark == msg->control.receiver.mark)      /* not none */
    {
        if (process[ pix ].status != STOPPED)  /* is process suspended ? */
            senderr(RTEILLKL, &msg->control.sender);
        killprocess(pix);
    }
}


void endprocess(status)                /* Terminate current process */
int status;
{
    int i;

    passivate(STOPPED);
#   if RPCDBG
    fprintf( stderr, "terminate process %d\n", thispix );
#   endif
    killprocess(thispix);
    if( ournode != console )   longjmp(contenv, 1);
    for (i = 0;  i < MAXPROCESS;  i++)
        if (process[ i ].used) longjmp(contenv, 1);
    endrun(status);
}


static void backcreate(msg)
message *msg;
{
    word pix, am;
    procdescr *p;

    pix = msg->control.receiver.pix;
    p = &process[ pix ];

    am = p->M[ p->template.addr ];      /* template physical address */
    p->M[ temporary ] = am;
    moveparams(pix, am, msg, PAROUT, SAVEPAR);

                                               /*store new process address */
    mess2obj(p,&(msg->control.sender),&(p->backobj));

    activate(pix);               /* end of waiting for NEW */
}


void senderr(exception, virt)
int exception;
procaddr *virt;
{
    message msg;

    msg.control.type = ERRSIG;
    msg.control.receiver=*virt;
    msg.control.par = exception;
    sendmsg(&msg);           /* send error message */
    longjmp(contenv, 1);        /* continue from next instruction */
}


static void localerror(msg)
message *msg;
{
    word pix;
    int s;

    pix = msg->control.receiver.pix;
    s = process[ pix ].status;
    if (process[ pix ].mark == msg->control.receiver.mark && s != STOPPED)
    {
        if (s == WAITFORNEW || s == WAITFORRPC) activate(pix);
        while (pfront(ready) != pix)
            ready = qrotate(ready);
        transfer(pfront(ready));
        errsignal(msg->control.par);
    }
}


void askprot(virt)               /* Ask for prototype of object */
virtaddr *virt;
{
    word am;
    message msg;

    if (isprocess(virt))               /* send question to remote process */
    {
        obj2mess( M, virt, &msg.control.receiver );
        msg.control.type = ASKPRO;
        sendmsg( &msg );
        passivate(WAITASKPRO);
    }
    else
    {
        if (member(virt, &am))
            M[ temporary ] = M[ am+PROTNUM ];
        else errsignal(RTEREFTN);
    }
}


static void ansprot(msg)               /* Answer with prototype of process */
message *msg;
{
    message msg1;
    word pix;

    pix = msg->control.receiver.pix;
    if (process[ pix ].mark == msg->control.receiver.mark)      /* not none */
    {
        msg1.control.receiver = msg->control.sender;
        msg1.control.type = PROACK;
        msg1.control.par = process[ pix ].prot;
        sendmsg( &msg1 );
    }
    else senderr(RTEREFTN, &msg->control.sender);
}


/* Message send/receive handling : */

void msginterrupt(msg)           /* Receive message interrupt handler */
   message *msg;
{
   moveblock((char *)msg, (char *)&globmsgqueue[ msgtail ],
             (word) sizeof(message));
   msgtail = (msgtail+1) % MAXMSGQUEUE;
   msgready++;
#if DLINK
   if (msgready < MAXMSGQUEUE-1)        /* leave one place for own message */
      net_attention();
#endif
}


void sendmsg(msg)                  /* Send message via net */
message *msg;
{
    msg->control.sender.node = ournode;
    msg->control.sender.pix  = thispix;
    msg->control.sender.mark = thisp->mark;
    if(
       msg->control.receiver.node == ournode
       ||
       msg->control.receiver.node == 0
      )
                        /* simulate receive message interrupt */
    {
#if DLINK
        net_ignore();               /* disable attention */
#endif
        msg->control.receiver.node == ournode;
        msginterrupt(msg);         /* call directly interrupt handler */
    }
    else
    {
#if DLINK
        if (!network) errsignal(RTEINVND);    /* send message by net */
        while (net_send((int) msg->control.receiver.node, msg)) ;
#elif TCPIP
        if (!network) errsignal(RTEINVND);    /* send message by net */
        tcpip_send( msg );
#else
        errsignal(RTEINVND);
#endif
    }
}


void trapmsg()                  /* Check for waiting message */
{
    message *msg;
    procdescr *p;
    word pix;

#if TCPIP
    /* check for message on TCPIP socket & move to queue        */
    if (msgready < MAXMSGQUEUE-1)      /* there is place for new message */
        if( tcpip_poll( 0 ) )          /* check for message              */
            if ( tcpip_recv( globmsgqueue + msgtail ) ){
                msgtail = (msgtail+1) % MAXMSGQUEUE;
                msgready++;
            }
#endif

    if (msgready > 0)      /* at least one message is waiting */
    {
#if DLINK
        net_ignore();               /* disable attention for a moment */
#endif
        msg = &globmsgqueue[ msghead ];    /* get first message from queue */
        msghead = (msghead+1) % MAXMSGQUEUE;
        switch(msg->control.type)
        {
            case ERRSIG :
               localerror(msg);
               break;

            case RESUME :
               pix = msg->control.receiver.pix;
               if (process[ pix ].mark != msg->control.receiver.mark)
                   senderr(RTEREFTN, &msg->control.sender);
               if (process[ pix ].status != STOPPED)
                   senderr(RTEILLRS, &msg->control.sender);
               activate(pix);
               break;

            case CREATE :
               createprocess(msg);
               break;

            case CREACK :
               backcreate(msg);
               break;

            case KILLPR :
               localkill(msg);
               break;

            case RPCALL :
               rpc1(msg);
               break;

            case RPCACK :
               rpcend(msg);
               break;

            case ASKPRO :
               ansprot(msg);
               break;

            case PROACK :
               pix = msg->control.receiver.pix;
               p = &process[ pix ];
               p->M[ temporary ] = msg->control.par;
               activate(pix);
               break;

            default     :
               fprintf( stderr, " Invalid message\n" );
               senderr(RTESYSER, &msg->control.sender);
        }
        msgready--;
#if DLINK
        if (msgready < MAXMSGQUEUE-1)   /* leave one place for own message */
            net_attention();     /* attention back on */
#endif
    }
}


static void mkglobal(ref)            /* Make global a process reference */
    word ref;
{
    word ah;
    ah = M[ ref ];
    if (!isprocess((virtaddr*)(M+ref)) && M[ ah+1 ] == M[ ref+1 ])
        if (prototype[ M[ M[ ah ]+PROTNUM ] ]->kind == PROCESS)
        {
            virtaddr va;
            procaddr pa;
            pa.node = ournode;
            pa.pix  = pix;
            pa.mark = thisp->mark;
            mess2obj(thisp,&pa,&va);
            M[ ref ]   = va.addr;
            M[ ref+1 ] = va.mark;
#ifdef RPCDBG
fprintf(stderr,"mkglobal REAL (thisp=%d) isprocess:node=%d pix=%d mark=%d\n",thispix,pa.node,pa.pix,pa.mark);fflush(stderr);
#endif
        }
        else errsignal(RTENONGL);        /* only process may be global */
}



/*
void show_m( char *s, message *msg ){
   char *n;
   switch(msg->control.type)
   {
       case ERRSIG : n = "ERRSIG"; break;
       case RESUME : n = "RESUME"; break;
       case CREATE : n = "CREATE"; break;
       case CREACK : n = "CREACK"; break;
       case KILLPR : n = "KILLPR"; break;
       case RPCALL : n = "RPCALL"; break;
       case RPCACK : n = "RPCACK"; break;
       case ASKPRO : n = "ASKPRO"; break;
       case PROACK : n = "PROACK"; break;
       default     : n = "??????"; break;
   }
   printf( "message %s type %s from %d:%d:%d to %d:%d:%d\n",
           s, n,
           msg->control.sender.node,
           msg->control.sender.pix,
           msg->control.sender.mark,
           msg->control.receiver.node,
           msg->control.receiver.pix,
           msg->control.receiver.mark
         );
   fflush( stdout );
}
*/

