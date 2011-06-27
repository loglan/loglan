/* Header for queue management module */

typedef lword qelem;
typedef qelem selem;
struct queuelem { qelem elem;
		  struct queuelem *next;
		};
typedef struct queuelem *queue;
typedef queue stack;

#ifndef NO_PROTOTYPES
queue qinit(void);
stack push(stack,selem);
qelem qfront(queue);
queue qremove(queue);
queue qdelete(queue,qelem);
queue qrotate(queue);
void qfree(queue);
#else
queue qinit();
stack push();
qelem qfront();
queue qremove();
queue qdelete();
queue qrotate();
void qfree();
#endif

#define qinsert(q, e)	(((queue) push((stack) (q), (selem) (e)))->next)
#define qempty(q)	((q) == NULL)
#define pinsert(q, p)	(qinsert(q, (qelem) (p)))
#define pfront(q)	((word) qfront(q))
#define minsert(q, m)	(qinsert(q, (qelem) (m)))
#define mfront(q)	((message *) qfront(q))
#define mdelete(q, m)	(qdelete(q, (qelem) (m)))
#define mpush(q, m)	((queue) push((stack) q, (selem) m))
#define sfree(s)	qfree((queue) s)
#define sinit		qinit
#define pop(s)		((stack) qremove((queue) s))
#define top(s)		((selem) qfront((queue) s))
