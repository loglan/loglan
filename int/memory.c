#include        "depend.h"
#include        "genint.h"
#include        "int.h"
#include	"process.h"
#include	"intproto.h"

/* Memory management routines */

#ifndef NO_PROTOTYPES
static void compandtake(word, word *, word *, word *, bool);
static void sinsert(word);
#else
static void compandtake();
static void sinsert();
#endif


int compactify_allowed=1;
#define space 400 /* words */


void request(app, ah, am)
word app, *ah, *am;
{
    word t2, t4, t5;
    bool wascompactified, found;

    if (app >= MAXAPPT) errsignal(RTEMEMOV);
    wascompactified = FALSE;

    if( compactify_allowed && thisp->force_compactification ){
         compactify();
         thisp->force_compactification=FALSE;
         wascompactified=TRUE;
    }

    if (thisp->freeitem != 0)           /* reserve dictionary item */
    {
        *ah = thisp->freeitem;
        thisp->freeitem = M[ *ah ];
    }
    else
    {
        *ah = thisp->lastitem-2;
        if (*ah <= thisp->lastused + space)     /* cannot take free item */
        {
            if( compactify_allowed )
                if( !wascompactified ) compactify(),wascompactified=TRUE;
                else ;
            else
                thisp->force_compactification=TRUE;
            *ah = thisp->lastitem-2;
            if (*ah <= thisp->lastused) errsignal(RTEMEMOV);
        }

        thisp->lastitem = *ah;
        M[ *ah+1 ] = 0;                 /* clear mark */
    }                                   /* now we have a free dict. item */


    if (app == 2 && thisp->headk2 != 0)    /* special case app=2 */
    {
        *am = thisp->headk2;
        thisp->headk2 = M[ *am+SHORTLINK ];
    }
    else
    {
        word t1 = thisp->headk;
        found = FALSE;
        t4 = 0;
        while (t1 != thisp->lower && !found)
        {
            t2 = M[ t1 ];
            if (t2 == app) found = TRUE;
            else
                if (t2-app >= 2) found = TRUE;
                else
                {
                    t4 = t1;
                    t1 = M[ t1+LONGLINK ];
                }
        }
        if( found ) {
            t5 = M[ t1+SHORTLINK ];
            if (t5 != 0) M[ t5+LONGLINK ] = M[ t1+LONGLINK ];
            else t5 = M[ t1+LONGLINK ];
            if (t4 == 0) thisp->headk = t5;  else M[ t4+LONGLINK ] = t5;
            *am = t1;
            if (t2 > app)           /* at least two extra words */
            {
                t5 = t1+app;
                M[ t5 ] = t2-app;
                sinsert(t5);
            }
        }
        else
        if ( thisp->lastitem - thisp->lastused > app + space )
        {
            *am = thisp->lastused+1;
            thisp->lastused += app;
        }
        else
        {
            M[ *ah ] = thisp->freeitem;        /* return dictionary item */
            thisp->freeitem = *ah;
            if( compactify_allowed )
                if( !wascompactified ) compactify();
                else ;
            else
                thisp->force_compactification=TRUE;
            *ah = thisp->lastitem-2;           /* reserve dictionary item */
            thisp->lastitem = *ah;
            M[ *ah+1 ] = 0;                    /* clear mark */
            if ( thisp->lastitem - thisp->lastused > app ) {
                *am = thisp->lastused+1;
                thisp->lastused += app;
            }
            else
                errsignal(RTEMEMOV);
        }
    }

    M[ *am ] = app;
    for (t2 = *am+1;  t2 < *am+app;  t2++ ) M[ t2 ] = 0;
    M[ *ah ] = *am;

}


static void sinsert(am)                        /* Dispose of a memory item. */
word am;
{
    word t1, t2, t3, t4;

    t1 = M[ am ];                       /* appetite */
    if (t1 == 2)                        /* a special list should be used */
    {
        M[ am+SHORTLINK ] = thisp->headk2;
        thisp->headk2 = am;
    }
    else
    {
        t2 = thisp->headk;
        t4 = 0;
        while (TRUE)                    /* look for a proper place */
        {
            t3 = M[ t2 ];               /* appetite */
            if (t1 == t3)               /* an entry with matching appetite */
            {
                M[ am+SHORTLINK ] = M[ t2+SHORTLINK ];
                M[ t2+SHORTLINK ] = am;
                break;
            }
            else
                if (t1 < t3)
                {
                    M[ am+LONGLINK ] = t2;
                    M[ am+SHORTLINK ] = 0;
                    if (t4 == 0) thisp->headk = am;
                    else M[ t4+LONGLINK ] = am;
                    break;
                }
                else
                {
                    t4 = t2;
                    t2 = M[ t2+LONGLINK ];
                }
        }
    }
}


void disp(virt)                         /* Simple kill. */
virtaddr *virt;
{
    word t1, t2;

    t1 = M[ virt->addr+1 ];
    if (t1 == virt->mark)		/* not none */
    {
        t1++;                           /* advance mark */
        t2 = M[ virt->addr ];           /* am */
        M[ virt->addr+1 ] = t1;
        if (t1 != MAXMARKER)            /* mark still usable */
        {
            M[ virt->addr ] = thisp->freeitem;
            thisp->freeitem = virt->addr;
        }                               /* now dictionary item is released */
        if (t2+M[ t2 ]-1 == thisp->lastused)   /* on the boundary */
            thisp->lastused = t2-1;
        else sinsert(t2);
    }
} /* end disp */


word memavail()				/* Compute available memory size */
{
    word t1, t2, avail;

    avail = thisp->lastitem-thisp->lastused-1;	/* contiguos memory */
    t1 = thisp->headk2;			/* go through killed 2 list */
    while (t1 != 0)
    {
    	avail += 2;
    	t1 = M[ t1+SHORTLINK ];
    }
    t1 = thisp->headk;
    while (t1 != thisp->lower)		/* go through killed object list */
    {
    	t2 = t1;
    	while (t2 != 0)
	{
	    avail += M[ t2 ];
	    t2 = M[ t2+SHORTLINK ];
	}
	t1 = M[ t1+LONGLINK ];
    }
    t1 = thisp->freeitem;		/* go through free item list */
    while (t1 != 0)
    {
    	avail += 2;
    	t1 = M[ t1 ];
    }
    return(avail);
} /* end memavail */
