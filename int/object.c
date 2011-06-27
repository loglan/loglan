#include	"depend.h"
#include	"genint.h"
#include	"int.h"
#include	"process.h"
#include	"intproto.h"

/* object management routines */


void openrc(prot, virt, addr)		/* Open new field for a record. */
word prot;
virtaddr *virt;
word *addr;
{
    word t1;

    request(prototype[ prot ]->appetite, &t1, addr);
    M[ *addr+PROTNUM ] = prot;
    virt->addr = t1;
    virt->mark = M[ t1+1 ];
} /* end openrc */


void slopen(prot, sladr, ah, am)
word prot;
virtaddr *sladr;
word *ah, *am;
{
    word t1, t2, virts;

    virts = thisp->prochead+M[ thisp->prochead ]+VIRTSC;
    storevirt(*sladr, virts);		/* preserve for compactifier */
    t1 = prototype[ prot ]->appetite;

    request(t1, ah, am);		/* open field */

    M[ *am+PROTNUM ] = prot;
    t1 = *am+t1;			/* LWA+1 of object */
    M[ t1+SL ] = M[ virts ];		/* prepare SL pointer */
    M[ t1+SL+1 ] = M[ virts+1 ];
    t2 = M[ display2+M[ c1+PROTNUM ] ]; /* ah of current */
    M[ t1+DL ] = t2;
    M[ t1+DL+1 ] = M[ t2+1 ];

} /* end slopen */


void openobj(prot, ah, am)
word prot;
word *ah, *am;
{
    virtaddr v1;
    word t1;

    t1 = M[ display2+prototype[ prot ]->slprototype ];
    v1.addr = t1;			/* ah of SL */
    v1.mark = M[ t1+1 ];
    slopen(prot, &v1, ah, am);
} /* end openobj */


void newarry(low, up, kind, virt, am)	/* Reserve room for array */
word low, up, kind;
virtaddr *virt;
word *am;
{
    word ap;

    switch ((int) kind)
    {
	case AINT     :  ap = APINT;   break;
	case AREAL    :  ap = APREAL;  break;
	case AVIRT    :  ap = APREF;   break;
	case APROCESS :  ap = APINT;   break;
    }
    low *= ap;
    up *= ap;
    if (up < low) errsignal(RTEILLAB);	/* illegal array bounds */
    low -= 3;
    request(up-low+ap, &virt->addr, am);
    M[ *am+1 ] = kind;
    M[ *am+2 ] = low;
    virt->mark = M[ virt->addr+1 ];
} /* end newarry */


void gkill(virt)			/* Generalized killer */
virtaddr *virt;
{
    word t1, t2, t3;
    virtaddr vt;
    protdescr *ptr;
    message msg;

    if (isprocess(virt))		/* kill remote process */
    {
	msg.control.type = KILLPR;
        obj2mess( M, virt, &msg.control.receiver );
	sendmsg( &msg);/* send remote kill request */
    }
    else
	if (virt->mark == M[ virt->addr+1 ])
	{
	    t1 = M[ virt->addr ];	/* am */
	    t2 = M[ t1+PROTNUM ];
	    if (t2 == AINT || t2 == AREAL || t2 == AVIRT)
		disp(virt);		/* simple kill for array */
	    else
		if (t2 == FILEOBJECT)
		{   /* First close file if opened */
		    if (M[ t1+FSTAT ] != UNKNOWN)
			if (fclose(MF(t1+FFILE))) errsignal(RTEILLIO);
		    /* Delete file if temporary */
		    if (M[ t1+FTEMP ] == LTRUE)
			if (unlink(MN(t1+FNAME))) errsignal(RTEILLIO);
		    free(MN(t1+FNAME));
		    disp(virt);
		}
		else			/* more than array or file */
		{
		    ptr = prototype[ t2 ];
		    if (ptr->kind == RECORD)
			disp(virt);
		    else
		    {
			t3 = t1;
			do
			{
			    t3 += M[ t3 ];   /* LWA of object */
			    if (M[ t3+STATSL ] != 0) errsignal(RTEILLKL);
			    t3 = M[ t3+DL ]; /* next object in DL */
			    if (t3 == 0) errsignal(RTEILLKL);
			    t3 = M[ t3 ];    /* am of DL */
			} while (t3 != t1);
			do		/* kill DL chain */
			{
			    t3 += M[ t3 ];
			    loadvirt(vt, t3+DL);
			    disp(virt);
			    virt->addr = vt.addr;
			    virt->mark = vt.mark;
			    t3 = M[ virt->addr ];
			} while (M[ virt->addr+1 ] == virt->mark);
		    }
		}
	}
} /* end gkill */


/* Copy object to a new object and locate it by fresh.
 */

void copy(old, fresh)
virtaddr *old, *fresh;
{
    word t1, t2, t3, virts;
    protdescr *ptr;
    bool notrecord;

    if (M[ old->addr+1 ] != old->mark)
    {					/* fine copy for none */
	fresh->addr = 0;
	fresh->mark = 0;		/* note M[ 1 ] <> 0 */
    }
    else				/* not none */
    {
	t1 = M[ old->addr ];		/* am of old */
	notrecord = FALSE;		/* assume it is a record */
	t2 = M[ t1+PROTNUM ];
	if (t2 != AINT && t2 != AREAL && t2 != AVIRT && t2 != FILEOBJECT)
	{				/* if not array nor file */
	    ptr = prototype[ t2 ];
	    if (ptr->kind != RECORD)	/* our assumption was wrong */
	    {
		notrecord = TRUE;
		t3 = t1+M[ t1 ]+DL;
		if (M[ t3 ] != old->addr || M[ t3+1 ] != old->mark)
		    errsignal(RTEILLCP); /* non-terminated object */
	    }
	}
	virts = thisp->prochead+M[ thisp->prochead ]+VIRTSC;
	storevirt(*old, virts); 	/* preserve for compactification */
	request(M[ t1 ], &t2, &t3);	/* book field */
	fresh->addr = t2;		/* ah */
	fresh->mark = M[ fresh->addr+1 ];
	t1 = M[ M[ virts ] ];
	for (t2 = 1;  t2 < M[ t1 ]; t2++ )
	    M[ t3+t2 ] = M[ t1+t2 ];
	if (notrecord)
	{
	    storevirt(*fresh, t3+M[ t3 ]+DL);	/* loop up DL */
	    M[ t3+M[ t3 ]+STATSL ] = 0;	/* not in any SL chain */
	}
    }
} /* end copy */
