#include        "depend.h"
#include        "genint.h"
#include        "int.h"
#include	"process.h"
#include	"intproto.h"


/* Queue management */
/* Single linked circular lists with queue represented as pointer to rear */

queue qinit()				/* Initialize empty queue */
{
    return (NULL);
} /* end qinit */


stack push(q, e)			/* Insert element into the queue */
stack q;
selem e;
{
    stack p;

    p = (stack) ballocate(sizeof(struct queuelem));
    if (p == NULL) errsignal(RTEMEMOV);
    p->elem = e;
    if (q == NULL)
    {
	p->next = p;			/* the lonely element of the queue */
	q = p;
    }
    else
    {
	p->next = q->next;		/* insert at rear */
	q->next = p;
    }
    return(q);
} /* end push */


qelem qfront(q)				/* Get first element of the queue */
queue q;
{
    if (qempty(q)){
       fprintf( stderr, "getting first element from empty queue\n");
       errsignal(RTESYSER);
    }
    return (q->next->elem);
} /* end qfront */


queue qremove(q)			/* Remove front element from the queue */
queue q;
{
    queue p;

    if (qempty(q)){
       fprintf( stderr, "removing first element from empty queue\n");
       errsignal(RTESYSER);
    }
    p = q->next;
    q->next = q->next->next;
    if (p == q) q = NULL;		/* removing last element of the queue */
    free(p);
    return(q);
} /* end qremove */


queue qdelete(q, e)			/* Delete arbitrary element */
queue q;
qelem e;
{
    queue p, r, s;

    if (qempty(q)) return(q);
    r = q;
    p = r->next;
    while (p->elem != e)
    {
        if (p == q) return(q);
        r = p;
        p = p->next;
    }
    r->next = p->next;
    if (r == p) s = NULL;
    else
        if (p == q) s = r;
        else s = q;
    free(p);
    return(s);
} /* end qdelete */


queue qrotate(q)			/* Remove front and insert at rear */
queue q;
{
    if (qempty(q)){
       fprintf( stderr, "rotating empty queue\n");
       errsignal(RTESYSER);
    }
    return (q->next);
} /* end qrotate */


void qfree(q)
queue q;
{
    while (!qempty(q))
    {
    	free(qfront(q));
	q = qremove(q);
    }
} /* end qfree */
