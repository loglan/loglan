#include        "queue.h"


/* Process management definitions : */

#define MAXPROCESS       64  /* maximum number of processes on one node */
#define MAXMSGQUEUE      16 /* maximum number of waiting messages */

#if DLINK
#define MSGLENGTH        80   /* message length defined by D-Link driver */
#elif TCPIP
#define MSGLENGTH       256   /* message length defined by me (PS) */
#else
#define MSGLENGTH       256   /* message length defined by me (PS) */
#endif


/* Process state : */

#define GENERATING      0    /* during generation of process object */
#define STOPPED         1      /* non-active process (suspended by STOP) */
#define EXECUTING       2     /* active process (ready to execute) */
#define WAITFORNEW      3    /* waiting for NEW of another process */
#define WAITFORRPC      4    /* waiting for remote procedure call */
#define ACCEPTING       5     /* during execution of ACCEPT statement */
#define WAITASKPRO      6    /* waiting for process prototype */

/* Process descriptor : */

typedef struct
{
    bool used;           /* TRUE if in use by some process */
    word mark;           /* process mark for proper detecting of none */
    int status;                /* process state */
    word prot;           /* process prototype number */
    memory M;      /* pointer to memory array */
    union value param[ MAXPARAM ];
    word ic;         /* instruction counter */
    word trlnumber;         /* trace line number */
    word lower;                /* first word of object area */
    word upper;                /* last word in memory */
    word lastused;           /* last word used by objects */
    word lastitem;           /* first word used by dictionary */
    word freeitem;           /* head of free dictionary item list */
    word headk;                /* head of killed object list for size > 2 */
    word headk2;               /* head of killed object list for size = 2 */
    word prochead;         /* am of process object */
    virtaddr procref;    /* process object virtual address */
    virtaddr template;   /* remote process or procedure template */
    word c1, c2;               /* pointers to current object */
    virtaddr backobj;     /* adress of object just left */
    word blck1, blck2;          /* used for LBLOCK1, LBLOCK2, LBLOCK3 */
    queue msgqueue;         /* queue of messages for this process */
    queue rpcwait;           /* queue of disabled RPC messages */
    stack rpcmask;           /* stack of set of enabled remote procedures */
    bool force_compactification; /* next allocate will forace compact... */
    word *hash;                /* table of pointers to processes in process */
    word hash_size;
} procdescr;


/* Message type : */

#define ERRSIG   0       /* error signal */
#define RESUME   1       /* resume request */
#define CREATE   2       /* create new process request */
#define CREACK   3       /* create process acknowledge */
#define KILLPR   4       /* kill process */
#define RPCALL   5       /* remote procedure call request */
#define RPCACK   6       /* remote procedure return */
#define ASKPRO   7       /* ask for process prototype */
#define PROACK   8       /* answer with process prototype */

typedef struct {
    word node;
    word pix;
    word mark;
} procaddr;

struct ctrlmsg
{
    procaddr sender;       /* address of the sender and */
    procaddr receiver;   /* receiver of the message */
    int type;      /* message type */
    int par;         /* prototype or error signal number */
};

#define MAXPROCPAR      (MSGLENGTH-sizeof(struct ctrlmsg))

typedef struct
{
    struct ctrlmsg control;
    char params[ MAXPROCPAR ];
} message;

/* Direction of copying of parameters (for moveparams()) : */

#define LOADPAR         0
#define SAVEPAR         1

typedef char *mask;

extern procdescr process[];     /* process descriptor table              */
extern procdescr *thisp;        /* pointer to current process descriptor */
extern word thispix;            /* current process index                 */
extern queue ready;             /* Round-Robin queue of ready processes  */
extern bool network;            /* TRUE if operating in D-Link network   */
extern message globmsgqueue[];  /* queue of waiting messages             */
extern int msgready;            /* number of waiting messages            */
extern int msghead, msgtail;    /* pointers to message queue             */
extern word ournode;            /* this machine node number              */
extern word console;            /* console node number                   */
extern bool remote;             /* TRUE if remote node                   */
extern bool reschedule;         /* TRUE if rescheduling is mandatory     */

#if OS2
extern PGINFOSEG ginf;          /* pointer to Global Info Segment */
#endif



#ifndef NO_PROTOTYPES
void obj2mess(word *,virtaddr *,procaddr*);
void mess2obj(procdescr *,procaddr *,virtaddr*);
bool isprocess(virtaddr *);
void hash_find(procaddr *,virtaddr *);
void hash_create(procdescr *,int);
void hash_set(procaddr *,word);
#else
void obj2mess();
void mess2obj();
bool isprocess();
void hash_find();
void hash_create();
void hash_set();
#endif

