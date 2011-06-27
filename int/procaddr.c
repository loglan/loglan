#include        "depend.h"
#include        "genint.h"
#include        "int.h"
#include	"process.h"
#include	"intproto.h"

#include	<assert.h>

#define ldnode(addr)		((word) (addr & 0xFF))
#define ldpix(addr)		((word) ((addr >> 8) & 0xFF))
#define staddr(node, pix)	((word) ((pix << 8) | node))


/*
	These are converters from global to process pointers in memory
	to global process pointers in message.
	M denotes memory in which pair (pointer,object) exists or has to exist.
	We want to create object denoting remote process instead of
	dummy pointer without object.
	The object will be like an arrayof integer of size 2.
        arr[1..3] : arr[1]=node, arr[2]=pix.
*/

void obj2mess(M,obj,mess)
   word *M;
   virtaddr *obj;
   procaddr *mess;
{
#ifdef OBJECTADDR
   word am;
   if( obj->mark != M[obj->addr+1] ){
      mess->node=-1;
      mess->pix =-1;
      mess->mark=-1;
   }else{
      am=M[obj->addr];
      mess->node=M[am+2];
      mess->pix =M[am+3];
      mess->mark=M[am+4];
   }
#else
   mess->node=ldnode(obj->addr);
   mess->pix =ldpix (obj->addr);
   mess->mark=obj->mark;
#endif
}

void mess2obj(p,mess,obj)
   procdescr *p;
   procaddr *mess;
   virtaddr *obj;
{

#ifdef OBJECTADDR

   word am;
   word *currM=M;
   word currpix=thispix;

   extern int compactify_allowed;
   compactify_allowed=0;

   transfer(p-process);

   hash_find(mess,obj);
/*
   newarry(1,4,APROCESS,obj,&am);
   M[am+2]=mess->node;
   M[am+3]=mess->pix;
   M[am+4]=mess->mark;
*/

   transfer(currpix);
   M=currM;

   compactify_allowed=1;

#else

   obj->addr=staddr(mess->node,mess->pix);
   obj->mark=mess->mark;

#endif

}



bool isprocess(v) virtaddr *v; {

#ifdef OBJECTADDR

   word am=M[v->addr];
/* assert(v->mark<=M[v->addr+1]);*/
   if( v->mark!=M[v->addr+1] )   return 0;
   else                          return ( M[am+1]==APROCESS );

#else

   return ( v->mark < 0 );

#endif

}



#ifdef OBJECTADDR

/* hash entry is a word pointing to dictionary or 0 if empty */

#ifndef NO_PROTOTYPES
static int hash_check_item( word, procaddr * );
static void hash_new_item( virtaddr *, procaddr * );
static int hash_mess( procaddr * );
static int hash_2( int );
#else
static int hash_check_item();
static void hash_new_item();
#endif

void hash_create(p,size) procdescr *p; int size;{
   /* create hash table for p process */
   int i;
   if( p->hash!=NULL )  free( p->hash );
   p->hash_size = size;
   p->hash = mallocate(size);
   if( p->hash==NULL )  errsignal(RTEMEMOV);
   for( i=0; i<p->hash_size; i++ )  p->hash[i]=0;
}


/* find pointer in hash table, add if not exists */

void hash_find(mess,obj) procaddr *mess; virtaddr *obj; {
   int i,first,jump;
   word am;
   first=hash_mess( mess );
   jump=hash_2(first);
   for( i=first; thisp->hash[i]!=0; ){
      if( hash_check_item(thisp->hash[i],mess) ){
         obj->addr=thisp->hash[i];
         obj->mark=M[thisp->hash[i]+1];
         return;
      }
      i=(i+jump)%thisp->hash_size;
      if( i==first ){
         int *curhash=thisp->hash;
         int cursize=thisp->hash_size;
errsignal(RTEMEMOV); /* the rest is not debugged yet */
         thisp->hash_size = cursize*3-1;
         thisp->hash = mallocate(thisp->hash_size);
         if( thisp->hash==NULL )  errsignal(RTEMEMOV);
         for( i=0; i<thisp->hash_size; i++ )  thisp->hash[i]=0;
         for( i=0; i<cursize; i++ ){
            if( curhash[i]!=0 ){
               virtaddr obj;
               procaddr mess;
               obj.addr=curhash[i];
               obj.mark=M[curhash[i]+1];
               obj2mess(M,&obj,&mess);
               hash_set(&mess,curhash[i]);
            }
         }
         hash_new_item( obj, mess );
         hash_set( mess, obj->addr );
         return;
      }
   }
   /* not exists yet */
   hash_new_item( obj, mess );
   thisp->hash[i]=obj->addr;
}

void hash_set(mess,ah) procaddr *mess; word ah;{
   int i,first,jump;
   word am;
   first=hash_mess( mess );
   jump=hash_2(first);
   for( i=first; thisp->hash[i]!=0; ){
      assert( !hash_check_item(thisp->hash[i],mess) );
      i=(i+jump)%thisp->hash_size;
      if( i==first ) errsignal(RTEMEMOV);
   }
   /* not exists yet */
   assert( thisp->hash[i]==0 );
   thisp->hash[i]=ah;
}

#endif


static int hash_check_item( ah, mess )  word ah; procaddr *mess; {
   word am=M[ah];
   return ( mess->node==M[am+2] && mess->pix==M[am+3] && mess->mark==M[am+4] );
}

static void hash_new_item( obj, mess )  virtaddr *obj; procaddr *mess; {
   word am;
   newarry(1,4,APROCESS,obj,&am);
   M[am+2]=mess->node;
   M[am+3]=mess->pix;
   M[am+4]=mess->mark;
}

static int hash_mess( mess ) procaddr *mess;{
   word hash=mess->pix;
   hash *= abs( mess->mark );
   hash += mess->node;
   return hash % (thisp->hash_size);
}

static int hash_2( hash_1 ) int hash_1;{
   return thisp->hash_size -2 - ( hash_1 % ( thisp->hash_size -2 ) );
}

