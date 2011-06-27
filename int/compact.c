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

#include        "depend.h"
#include        "genint.h"
#include        "int.h"
#include	"process.h"
#include	"intproto.h"

#include <assert.h>


#ifndef NO_PROTOTYPES

static word get_pointer(word,word);
static void phase1(void);
static void phase2(void);
static void phase2a(void);
static void phase3(void);
static void phase4(void);
static void phase5(void);
static void phase6(void);
static void curtain(void);
static void heap_walk(word);
static void nonefy(virtaddr *);
static void relocate(virtaddr *);
static void traverse(word,void (*)(virtaddr *));
static void what_we_have(virtaddr *);

#else

static word get_pointer();
static void phase1();
static void phase2();
static void phase2a();
static void phase3();
static void phase4();
static void phase5();
static void phase6();
static void curtain();
static void heap_walk();
static void nonefy();
static void relocate();
static void traverse();
static void what_we_have();

#endif


#ifdef CDBG
FILE *ff;
static void what_we_have(va) virtaddr *va; {
    fprintf(ff,"   pointer offset %d:|va=%d,va_m=%d,M[va]=%d,M[va+1]=%d|\n",
            ((word*)va)-M,va->addr,va->mark,M[va->addr],M[va->addr+1]);
    fflush(ff);
}
#endif


/*
 * Memory compactifier - a play in 6 acts
 */

static word nleng;                      /* free memory before compact. */
static word curah;			/* to preserve ah of current object */

/* One of the actions for traverse: see below;
 * converts none to absolute none, i.e. (0, 0)
 */


static void nonefy(va) virtaddr *va; {

#ifdef CDBG
    if(va->addr==0 && va->mark!=0){
        fprintf(ff,"nonefy:|va=%d,va_m=%d,M[va]=%d,M[va+1]=%d|\n",
                va->addr,va->mark,M[va->addr],M[va->addr+1]);
        fflush(ff);
    }
#endif

#ifndef OBJECTADDR
    if(!isprocess(va))
#else
    assert( va->mark >= 0  );
/*    assert( va->mark <= M[ va->addr+1 ]   );*/
#endif
#ifdef CDBG
        fprintf(ff,"nonefy:|va=%d,va_mark=%d,am=%d,mark=%d|\n",
                va->addr,va->mark,M[va->addr],M[va->addr+1]);
        fflush(ff);
#endif
    if( va->mark != M[ va->addr+1 ]   )     /* if NONE */
    {

#ifdef CDBG
        fprintf(ff,"		set to NONE\n"); fflush(ff);
#endif
        va->addr = 0;
        va->mark = 0;
    }
    assert( va->addr != 1 );
} /* end nonefy  */


/* One of the actions for traverse; update the virtual address to
 * correspond to its dictionary entry after compactification.
 */

static void relocate(va) virtaddr *va; {
#ifndef OBJECTADDR
    if(!isprocess(va)){
#endif
    va->addr = M[ va->addr+1 ];	/* new ah (after compression) */
    va->mark = 0;			/* clear mark */
#ifndef OBJECTADDR
    }
#endif
} /* end relocate */


/* Traverse all the virtual variables of object am and perform action
 * on each of them. Skip references to processes (see nonefy() and
 * relocate()).
 */

static void traverse(am, action)
   word am;
#ifndef NO_PROTOTYPES
   void (*action)(virtaddr *);
#else
   void (*action)();
#endif
{
    word t1, t2, t3, length;
    protdescr *ptr;

    t1 = am+M[ am ];                    /* LWA+1 of the object */
    length = M[ am+PROTNUM ];           /* prototype number */
    if (length == AINT || length == AREAL || length == AVIRT ||
        length == FILEOBJECT
#ifdef OBJECTADDR
        || length == APROCESS
#endif
       )
    {
        if (length == AVIRT)		/* ARRAYOF <reference> */
            for (t2 = am+3;  t2 < t1;  t2 += 2)
                (*action)((virtaddr *)(M+t2));
    }
    else                                /* neither an array nor a file */
    {
        ptr = prototype [ length ];
        switch (ptr->kind)              /* compute the number of the system */
                                        /* virtual variables */
        {
            case RECORD    : length = 0;  t3 = 0;        break;
            case COROUTINE : length = 3;  t3 = CL;       break;
            case PROCESS   : length = 5;  t3 = disp2off; break;
            case FUNCTION  :
            case PROCEDURE : length = 2;  t3 = RPCDL+1;  break; /* PS */
	    case HANDLER   : length = 2;  t3 = SIGNR;    break;
            default        : length = 2;  t3 = STATSL;   break;
        }

	/* action for system reference variables */
        for (t2 = length;  t2 >= 1;  t2-- )
            (*action)((virtaddr *)(M+t1+offset[ t2 ]));

	/* action for temporary reference variables */
	t1 = am+M[ am ]+t3;
	for (t2 = am+ptr->span;  t2 < t1;  t2 += 2)
	    (*action)((virtaddr *)(M+t2));

	/* action for user reference variables */
        t1 = ptr->reflist;
        for (t2 = t1+ptr->lthreflist-1;  t2 >= t1;  t2-- )
            (*action)((virtaddr *)(M+am+M[ t2 ]));
    }
} /* end traverse */


/* Mark killed objects by substituting prototype number by a special value.
 * This way we will be able to tell apart the killed objects without
 * recalling to the dictionary or to the list of killed objects.
 */

static void phase1()
{
    word t1, t2, t3, phead;

    nleng = thisp->lastitem-thisp->lastused-1; /* free memory before comp. */
    M[ 1 ] = 0;                         /* for proper update of none */
    phead = thisp->prochead;		/* head of current process */
    M[ phead+M[ phead ]+SL ] = 0;	/* make SL of head look like none */
    t1 = thisp->headk2;                 /* flag killed objects */
    while (t1 != 0)                     /* special list for appetite=2 */
    {
        t2 = t1+SHORTLINK;
        t1 = M[ t2 ];
        M[ t2 ] = SKILLED;		/* flag object killed */
    }
    t1 = thisp->headk;                  /* now other killed objects */
    while (t1 != thisp->lower)
    {
        t2 = t1;
        while (t2 != 0)
        {
            t3 = t2+SHORTLINK;
            t2 = M[ t3 ];
            M[ t3 ] = SKILLED;		/* flag object killed */
        }
        t1 = M[ t1+LONGLINK ];		/* goto other size list */
    }
} /* end phase1 */


/* Step thru the memory area containing objects. For each object not being
 * killed detect all its virtual variables pointing to none and convert
 * them to absolute none i.e. (0, 0).
 */

static void phase2()
{
    word t1;

    nonefy( &(thisp->procref ) );

    t1 = thisp->lower+1;                /* FWA of object area */
    while (t1 <= thisp->lastused)
    {

#ifdef CDBG
        fprintf(ff,"OBJECT am=%d,SIZE=%d,TYPE=%d\n",t1,M[t1],M[t1+1]);
        fflush(ff);
        if (M[ t1+1 ] != SKILLED) traverse(t1,what_we_have);
#endif

        if (M[ t1+1 ] != SKILLED)       /* an active object */
            traverse(t1, nonefy);
        t1 += M[ t1 ];			/* next object address */
    }
} /* end phase2 */


/* garbage collection */

/* Find x-th pointer in am.
 * Skip references to processes.
 */

static word get_pointer(am,x) word am,x; {

    word t1, t2, t3, length, va;
    protdescr *ptr;

    t1 = am+M[ am ];                    /* LWA+1 of the object */
    length = M[ am+PROTNUM ];           /* prototype number */

#ifdef CDBG
    fprintf(ff,"|get_pointer(am=%d,x=%d)lenght=%d|",am,x,length);
    fflush(ff);
#endif

    if (length == AINT || length == AREAL || length == AVIRT ||
        length == FILEOBJECT
#ifdef OBJECTADDR
        || length == APROCESS
#endif
       )
    {
        if(length == AVIRT)		/* ARRAYOF <reference> */
            for(t2 = am+3;  t2 < t1;  t2 += 2){
#ifndef OBJECTADDR
                if(isprocess((virtaddr *)(M+t2))) continue;
#endif
                if(M[t2]==0){ assert( M[t2+1]==0 ); continue; }
#ifdef CDBG
                fprintf(ff,"ARR");
                fflush(ff);
#endif
                if(x==0){
#ifdef CDBG
                    fprintf(ff,"=%d|\n",t2);
                    fflush(ff);
#endif
                    return t2;
                }
                x--;
            }
    }
    else                                /* neither an array nor a file */
    {
        ptr = prototype [ length ];
        switch (ptr->kind)              /* compute the number of the system */
                                        /* virtual variables */
        {
            case RECORD    : length = 0;  t3 = 0;        break;
            case COROUTINE : length = 3;  t3 = CL;       break;
            case PROCESS   : length = 5;  t3 = disp2off; break;
            case FUNCTION  :
            case PROCEDURE : length = 2;  t3 = RPCDL+1;  break; /* PS */
	    case HANDLER   : length = 2;  t3 = SIGNR;    break;
            default        : length = 2;  t3 = STATSL;   break;
        }

	/* system reference variables */
        for(t2 = length;  t2 >= 1;  t2-- ){
            va=t1+offset[ t2 ];
#ifndef OBJECTADDR
            if(isprocess((virtaddr *)(M+va))) continue;
#endif
            if(M[va]==0){ assert( M[va+1]==0 ); continue; }
            if(x==0){
#ifdef CDBG
                fprintf(ff,"=%d|\n",va);
                fflush(ff);
#endif
                return va;
            }
            x--;
        }

	/* temporary reference variables */
	t1 = am+M[ am ]+t3;
	for(t2 = am+ptr->span;  t2 < t1;  t2 += 2){
#ifndef OBJECTADDR
            if(isprocess((virtaddr *)(M+t2))) continue;
#endif
            if(M[t2]==0){ assert( M[t2+1]==0 ); continue; }
            if(x==0){
#ifdef CDBG
                fprintf(ff,"=%d|\n",t2);
                fflush(ff);
#endif
                return t2;
            }
            x--;
        }

	/* user reference variables */
        t1 = ptr->reflist;
        for(t2 = t1+ptr->lthreflist-1;  t2 >= t1;  t2-- ){
            va=am+M[ t2 ];
#ifndef OBJECTADDR
            if(isprocess((virtaddr *)(M+va))) continue;
#endif
            if(M[va]==0){ assert( M[va+1]==0 ); continue; }
            if(x==0){
#ifdef CDBG
                fprintf(ff,"=%d|\n",va);
                fflush(ff);
#endif
                return va;
            }
            x--;
        }
    }

#ifdef CDBG
    fprintf(ff,"=-1|\n");
    fflush(ff);
#endif

    return -1;
}

static void heap_walk(curr_ah) word curr_ah;{
   word aux,prev_ah=1; /* 1 is special value not expected in anyone virtaddr */
   word level=0;

#ifdef CDBG
   fprintf(ff,"|prev_ah=%d|\n",prev_ah);
   fflush(ff);
#endif

   for(;;){
      word am=get_pointer(M[curr_ah],M[curr_ah+1]);
      M[curr_ah+1]++;
      if(am >= 0){
         if(M[ M[am] +1] >0){
#ifdef CDBG
            fprintf(ff,"Object %d->%d invited.\n",M[am],M[M[am]]);
            fflush(ff);
#endif
            continue;
         }

         /*** go ahead ***/
         level++;
         aux=M[am];
         M[am]=prev_ah;
         prev_ah=curr_ah;
         curr_ah=aux;
#ifdef CDBG
         fprintf(ff,"|curr_ah set to %d|\n",curr_ah);
         fflush(ff);
#endif
         continue;
      }
      if(prev_ah > 1){
         /*** go back ***/
#ifdef CDBG
         fprintf(ff,"going back (prev_ah=%d)(lvl=%d)\n",prev_ah,level);
         fflush(ff);
#endif
         level--;
         aux=curr_ah;
         curr_ah=prev_ah;
         am=get_pointer(M[prev_ah],M[prev_ah+1]-1);
         prev_ah=M[am];
#ifdef CDBG
         if(level==0)
            fprintf(ff,"|prev_ah set to %d,next set to %d|\n",prev_ah,aux);
         fflush(ff);
#endif
         M[am]=aux;
         continue;
      }
      assert( prev_ah==1 );
      assert( level == 0 );
      break;  /*** now all 'invited' objects have its mark >0 ***/
   }
}

static void phase2a()
{
    word t1,c1_ah;

    /*** generation number already is not needed so we reset it ***/

    t1 = thisp->upper-1;
    while(t1 >= thisp->lastitem){
       if( M[t1] == c1 ) c1_ah=t1;
       M[ t1+1 ] = 0;
       t1-=2;
    }

#ifdef CDBG
    fprintf(ff,"first phase of walk |from=%d,to=%d,procah=%d|\n",
            thisp->lastitem,
            thisp->upper-1,
            thisp->procref.addr);
    fflush(ff);
#endif

    heap_walk(thisp->procref.addr);

#ifdef CDBG
    fprintf(ff,"second phase of walk c1_ah=%d,c1=%d\n",c1_ah,c1);
    fflush(ff);
#endif

    heap_walk(c1_ah);

    if( thisp->blck1 != 0 )
       heap_walk(thisp->blck1);

    /*** Mark objects not traversed like SKILLED ***/

    t1 = thisp->freeitem;		/* head of free item list */
    while (t1 != 0)
    {
        word t2;
        t2 = M[ t1 ];
        M[ t1 ]= 0-1;			/* mark not to set object SKILLED */
        t1 = t2;			/* next free item */
    }

    t1 = thisp->upper-1;                /* last dictionary item pointer */
    while (t1 >= thisp->lastitem)
    {
        if (M[ t1+1 ]  == 0 ){     	/* entry not traversed - so killed */

#ifdef CDBG
            fprintf(ff,"MARKING dict. entry %d -> %d like SKILLED\n",t1,M[t1]);
            fflush(ff);
#endif

            M[ t1+1 ] = MAXMARKER;
            if( M[ t1 ] > 0 )   M [ M[ t1 ] +1 ] = SKILLED;
					/* mark SKILLED if not set yet */
        }
        t1 -= 2;
    }
} /* end phase2a */



/* For each free dictionary item set its mark to unusable status.
 */

static void phase3()
{
    word t1;

    t1 = thisp->freeitem;		/* head of free item list */
    while (t1 != 0)
    {
        M[ t1+1 ] = MAXMARKER;		/* flag item unusable */
        t1 = M[ t1 ];			/* next free item */
    }
} /* end phase3 */


/* Step thru the dictionary and virtually remove all unusable items.
 * For each active item (after phase3 we have only active and unusable
 * items) its mark is set to the new address of this item (after
 * forthcomming compression). Moreover the contents of locations am and
 * (old) ah are interchanged.
 */

static void phase4()
{
    word t1, t2, t3;

    t1 = thisp->upper-1;                /* last dictionary item pointer */
    t2 = t1;                            /* initialize new address */
    while (t1 >= thisp->lastitem)
    {
        if (M[ t1+1 ] == MAXMARKER)     /* entry killed - don't decrement t2 */
            M[ t1+1 ] = 0;
        else
        {
            M[ t1+1 ] = t2;             /* store new ah */;
            t2 -= 2;
            t3 = M[ t1 ];               /* am */
            M[ t1 ] = M[ t3 ];          /* save (am) in (old ah) */
            M[ t3 ] = t1;               /* move old ah to (am) */
        }
        t1 -= 2;
    }
} /* end phase4 */


/* The memory area of objects is traversed once again. Now the killed
 * objects are removed and the remaining ones compressed. For each active
 * object its virtual variables are relocated, their marks cleared, their
 * ah's set to the proper new values. The contents of locations am and ah
 * are interchanged back.
 */

static void phase5()
{
    word t1, t2, t3, t4, t5;

    t2 = t1 = thisp->lower+1;
    while (t1 <= thisp->lastused)       /* traverse object area */
    {
        t5 = M[ t1 ];                   /* old ah saved by phase4 */
        if (M[ t1+1 ] == SKILLED){      /* ignore this object */
#ifdef CDBG
            fprintf(ff,"OBJECT am=%d,SIZE=%d,TYPE=%d\n",t1,M[t1],M[t1+1]);
            fflush(ff);
#endif
            t1 += t5;                   /* t5=appetite in this case */
        }
        else
        {
#ifdef CDBG
            fprintf(ff,"OBJECT am=%d,SIZE=%d,TYPE=%d\n",t1,M[t1],M[t1+1]);
            fflush(ff);
#endif
            t3 = M[ t5 ];               /* appetite saved by phase4 */
            M[ t2 ] = t3;               /* send it to the new am */
            for (t4 = 1;  t4 < t3;  t4++ )   /* copy the object into new am */
                M[ t2+t4 ] = M[ t1+t4 ];
#ifdef CDBG
            traverse(t2,what_we_have);
#endif

	    /* Update global absolute pointer to current object : */
            if (t1 == c1)		/* locate am of current */
            {
                c1 = t2;
                curah = M[ t5+1 ];	/* new ah of current */
            }
            if (t1 == M[ temporary ])
                M[ temporary ] = t2;

            M[ t5 ] = t2;               /* make (ah) looking ok */
            traverse(t2, relocate);     /* relocate virtual variables */
#ifdef CDBG
            fprintf(ff,"   --> am=%d,SIZE=%d,TYPE=%d\n",t2,M[t2],M[t2+1]);
            fflush(ff);
            traverse(t2,what_we_have);
#endif
            t1 += t3;
            t2 += t3;
        }
    }
    thisp->lastused = t2-1;


    /* Update global absolute pointers to objects : */

    relocate(&(thisp->procref ));

    {
       virtaddr v;
       v.addr=thisp->blck1;
       v.mark=0;
       relocate(&v);
       thisp->blck1=v.addr;
    }

} /* end phase5 */


/* The dictionary is compressed. The unusable entries are moved out and
 * the remaining ones are moved up to the positions indicated by their
 * marks.
 * If pointers to processes are implemented as objects we have to rebuild
 * has table of these pointers too.
 */

static void phase6()
{
    word t1, t2, t3;

#ifdef OBJECTADDR
    hash_create(thisp,thisp->hash_size);
#endif

    t1 = thisp->upper+1;
    for (t2 = t1-2;  t2 >= thisp->lastitem;  t2 -= 2)  /* compress dictionary */
    {
        t3 = M[ t2+1 ];
        if (t3 != 0)                    /* this is new ah */
        {
            M[ t3 ] = M[ t2 ];
            M[ t3+1 ] = 0;              /* clear mark */
            t1 = t3;
#ifdef OBJECTADDR
            {
               virtaddr vt3;
               vt3.addr=t3;
               vt3.mark=0;
               if( isprocess(&vt3) ){
                  virtaddr obj;
                  procaddr mess;
                  obj.addr=t3;
                  obj.mark=0;
                  obj2mess(M,&obj,&mess);
                  /* force to create item - we not need it yet */
                  hash_set(&mess,t3);
               }
            }
#endif
        }
    }
    thisp->lastitem = t1;

    thisp->prochead = M[ thisp->procref.addr ];
    thisp->blck2 = M[ thisp->blck1 ];

} /* end phase6 */


/* System invariants are recovered, e.g. display is rebuilt to reflect the
 * new physical addresses.
 */

static void curtain()
{
    word t1, phead;

    phead = thisp->prochead;
    t1=M[ c1 + PROTNUM ];
    c2 = c1+prototype[ t1 ]->span;
    t1 = phead+M[ phead ];		/* first free after process head */
    display = t1+dispoff;		/* display address */
    display2 = t1+disp2off;		/* indirect display */
    M[ t1+SL ] = DUMMY;			/* restore head's SL */
    loosen();				/* rebuild DISPLAY */
    update(c1, curah);
    if (infmode){
       fprintf(stderr,
      "\n(COMPACTIFIER used for process %d,%ld words reclaimed,now %ld free)\n",
                       thispix,
                       (long) (thisp->lastitem-thisp->lastused-1-nleng),
                       (long) (thisp->lastitem-thisp->lastused-1));
       fflush(stderr);
    }
#ifdef CDBG
       fprintf(ff,
        "(COMPACTIFIER used for process %d,%ld words reclaimed,now %ld free)\n",
                   thispix,
                   (long) (thisp->lastitem-thisp->lastused-1-nleng),
                   (long) (thisp->lastitem-thisp->lastused-1));
       fflush(ff);
#endif
    thisp->freeitem = 0;
    thisp->headk2 = 0;
    thisp->headk = thisp->lower;
    M[ 1 ] = 1;				/* absolute none */
    ic = lastic;			/* re-decode current instruction ! */
    decode();
    if (opcode == 3 /*LRAISE*/) ic++;	/* skip address after LRAISE */
} /* end curtain */


void compactify()                       /* Compactification */
{
#ifdef CDBG
    ff=fopen("trace","a");
    fprintf(ff,"----------------------------------------\n");
    fprintf(ff,"COMPACTIFY (thisp=%d)\n",thispix);
    fprintf(ff,"c1=%d,c2=%d,templ=%d\n",
               thisp->c1,thisp->c2,thisp->template.addr);
    fprintf(ff,"back=%d,back.mark=%d,backam=%d,backam.mark=%d\n",
               thisp->backobj.addr,thisp->backobj.mark,
               M[thisp->backobj.addr],M[thisp->backobj.addr+1]);
    fprintf(ff,"blck1=%d,blck2=%d\n",thisp->blck1,thisp->blck2);
    fflush(ff);
#endif

    phase1();
    phase2();
    phase2a();  /* garbage collection */
/*  phase3();   if only compactifier is needed uncomment this statement */
/*              and comment statement phase2a()                         */
    phase4();
    phase5();
    phase6();
    curtain();

#ifdef CDBG
    fprintf(ff,"----------------------------------------\n");
    fflush(ff);
    fclose(ff);
#endif

} /* end compactify */


