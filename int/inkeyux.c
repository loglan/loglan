#include <stdio.h>
#include <signal.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include <termio.h>


#include "graf/graf.h"

#define KB_BACKSPACE	(int)'\b'	/* kb */
#define KB_ENTER	(int)'\r'	/* RT */
#define KB_TAB		(int)'\t'	/* TB */
#define KB_ESC		0x1b		/* EC */

#define KB_HOME		-71	/* kh or HM */
#define KB_END		-79	/* EN */
#define KB_UP		-72	/* ku or UP */
#define KB_DOWN		-80	/* kd */
#define KB_LEFT		-75	/* kl */
#define KB_RIGHT	-77	/* kr */
#define KB_PGUP		-73	/* PU */
#define KB_PGDN		-81	/* PD */
#define KB_BACK_TAB	-15	/* BT */
#define KB_INS		-82	/* al */
#define KB_DEL		-83	/* DL */

#define KB_F1		-59	/* k1 */
#define KB_F2		-60	/* k2 */
#define KB_F3		-61	/* k3 */
#define KB_F4		-62	/* k4 */
#define KB_F5		-63	/* k5 */
#define KB_F6		-64	/* k6 */
#define KB_F7		-65	/* k7 */
#define KB_F8		-66	/* k8 */
#define KB_F9		-67	/* k9 */
#define KB_F10		-68	/* k0 */

#define KB_STR_EXISTS       1	/* string exists in tree or his prefix  */
#define KB_TOO_MANY_STRINGS 2	
#define KB_NULL_STRING      3
#define KB_OUT_OF_MEMORY    4
#define KB_OK               0



#include "depend.h"
#include "genint.h"
#include "int.h"
#include "process.h"
#include "intproto.h"


#define TERMINAL 0
#define KEYBOARD 1

static char *capability,*capability_value;

typedef struct _tree_node *tree;    /* drzewo zawierajace ciagi znakow     */
struct _tree_node {                 /* odpowiadajace klawiszowi klawiatury */
   int key;
   tree way;
   int outkey;
};    

#ifndef NO_PROTOTYPES
static int tfirst(int);
static int tnext(void);
static void *___allocate_object(unsigned);
static void ___free_object(void *);
static char *object_str(char *);	/* allocate space and copy string */
static int __testkey(int*,int*);
static int getkey(void);
static int __inkey(void);
static void kbinit(void);
static tree new_tree_node(void);
static int _create_new_leaf(tree,int,unsigned char *,int);
static int inskey(int,char *);
#else
static int tfirst();
static int tnext();
static void *___allocate_object();
static void ___free_object();
static char *object_str();
static int __testkey();
static int getkey();
static int __inkey();
static void kbinit();
static tree new_tree_node();
static int _create_new_leaf();
static int inskey();
#endif





#define object_kill(i) (___free_object(i),(i)=NULL)
#define object_new(type) ((type *)___allocate_object(sizeof(type)))
#define object_dim(i,type) ((type *)___allocate_object((i)*sizeof(type)))




#define KB_NDEF 0xff /* KN - key suppressed by inkey() */

#define NODE_SIZE 100


#define QSIZE 256
static int cqueue[QSIZE];		/* implementacja kolejki */
static int qh=0,qt=0,qs=0;
static int bget(){
   int c;
   if( qs == 0 )  return -1;
   c = cqueue[ qh++ ];
   qh &= QSIZE - 1 ;
   qs--;
   return c;
}
static void bput( c )  int c; {
   if( qs == QSIZE )  return;
   cqueue[ qt++ ] = c;
   qt &= QSIZE - 1 ;
   qs++;
}
static int qq;
static int bfirst(){
   if( qs == 0 )  return -1;
   qq = qh + 1 ;
   qq &= QSIZE - 1 ;
   return  cqueue[ qh ];
}
static int bnext(){
   int c;
   if( qq == qt )  return -1;
   c = cqueue[ qq++ ];
   qq &= QSIZE - 1 ;
   return c;
}


static tree troot=NULL;

#ifndef NDEBUG
static FILE *f=NULL;
static void _show_tree(root,r) tree root;int r;{
   int i,j;
   for(i=0;(i<NODE_SIZE) && (root[i].key!=-1);i++){
      for(j=0;j<r;j++) fprintf(f,"i");
      fflush(f);
      fprintf(f,"%d ",root[i].key);fflush(f);
      if(root[i].way==NULL){
         fprintf(f,"%d\n",root[i].outkey);fflush(f);
      }else _show_tree(root[i].way,r+1);
   }
}
static void show_tree(){
   f=fopen("show_tree","a");
   if(f==NULL){printf("cant open");exit(7);}
   fprintf(f,"%lx\n",troot);fflush(f);
   _show_tree(troot,0);
   fprintf(f,"********************\n");
   fclose(f);
}
#endif


#define NO_CHARS	0
#define PART_SUBSTRING	1
#define SUBSTRING	2
#define STRING		3
#define NO_MATCH	4

static int __testkey(outkey,to_take) int *outkey,*to_take;
{
   int c,i;
   tree tact;

   tact=troot;
   c=bfirst();

   if(c==-1) return NO_CHARS; /* buffer empty - wait for char */

   *to_take=1;

   for(;;){
      for(i=0;i<NODE_SIZE;i++){
         if(tact[i].key==-1){ i=NODE_SIZE; break; }
         if(tact[i].key==c)
            if(tact[i].way!=NULL){
               c=bnext();
               (*to_take)++;
               if(c==-1){
                  *outkey=tact[i].outkey;
                  if(*outkey != -1)  return SUBSTRING;
                  else               return PART_SUBSTRING;
               }
               tact=tact[i].way;
               break;
            }
            else{
               *outkey = tact[i].outkey;
               return STRING;
            }
      }
      if( i==NODE_SIZE )   return NO_MATCH;
   } 
}


static void (*prev_fun)()=NULL;
static void alarm_fun(){}


static int getkey(){
   int c;
   prev_fun = signal( SIGALRM, alarm_fun );
   alarm(1);
   c = getchar();
   alarm(0);
   signal( SIGALRM, prev_fun );
   return c;
}



static int __inkey()
{
   int c,i,outkey,chars;
   if(troot==NULL){printf("Not initialized\n\r");exit(7);}

   alarm(0);

   for(;;){

      i=__testkey(&outkey,&chars);

      switch( i ){

         case NO_CHARS :
            c = getkey();
            if( c != -1 )   bput( c );
            else  return 0;
            break;

         case PART_SUBSTRING :
            c = getkey();
            if( c==-1 ) return bget();
            bput( c );
            break;

         case SUBSTRING :
            c = getkey();
            if( c==-1 ){
               while( chars-- )  bget();
               return outkey;
            }
            bput( c );
            break;

         case STRING :
            while( chars-- )  bget();
            return outkey;
            break;

         case NO_MATCH :
            return bget();
            break;
      }
   }
}


static struct termio term_state,term_new;

int inkey( dummy )
   void *dummy;
{  /* podaj znak z klawiatury - zapominanie KB_NDEF */
   static int first_time=1;
   int k;

   if( first_time ){  kbinit(); first_time=0; }

   ioctl(fileno(stdin),TCGETA,&term_state);  /* RAW MODE */
   term_new = term_state;
   term_new.c_lflag&=~(ISIG|ICANON|ECHO);   /* echo,canonical line processing */
                                            /* signal processing = OFF */
   term_new.c_iflag&=~(ICRNL|INLCR);        /* conversions OFF */
   term_new.c_oflag=0;
   term_new.c_cc[VEOF]='\1';                /* every char flushed immedietly */
   ioctl(fileno(stdin),TCSETA,&term_new);

   do k=__inkey(); while(k==KB_NDEF);

   ioctl(fileno(stdin),TCSETA,&term_state);  /* PREVIOUS MODE */

   return k;
}


static tree new_tree_node(){
   tree p;
   int i;
   p=(tree)object_dim(NODE_SIZE+1,struct _tree_node);
   p++;
   for(i=0;i<NODE_SIZE;i++){
      p[i].key=p[i].outkey=-1;
      p[i].way=NULL;
   }
   return p;
}


static int inskey(ch,str)
   int ch;
   char *str;
{
   tree tact=troot;
   int i;

   if(troot==NULL) return KB_OUT_OF_MEMORY;
   if(str==NULL || (!(*str))) return KB_NULL_STRING;

   for(;;){
      for(i=0;i<NODE_SIZE;i++){
         if(tact[i].key==-1){
            tact[i].key=(int)(*(str++));
            return _create_new_leaf(tact,i,str,ch);
         }
         if(tact[i].key==(int)(*str)){
            str++;
            if(tact[i].way==NULL)
               if( *str!='\0' )  return _create_new_leaf(tact,i,str,ch);
               else              return KB_STR_EXISTS;
            if( *str=='\0' ){
               tact[i].outkey=ch;
               return KB_OK;
            }
            tact=tact[i].way;
            break;
         }
      }
      if(i==NODE_SIZE) return KB_TOO_MANY_STRINGS;
   }
}


static int _create_new_leaf(tact,i,str,ch)
   tree tact;
   int i,ch;
   unsigned char *str;
{
   while(*str!='\0'){
      tact[i].way=new_tree_node();
      tact[i].way[-1].way=tact;
      tact=tact[i].way;
      i=0;
      tact[0].key=(int)(*(str++));
   } 
   tact[i].outkey=ch;
   return KB_OK;
}


static struct { int key; char capability[3]; } tab[]={

	{ KB_NDEF	, "KN" },
	{ KB_BACKSPACE	, "kb" },
	{ KB_ENTER	, "RT" },
	{ KB_HOME	, "kh" },
	{ KB_HOME	, "HM" },
	{ KB_END	, "EN" },
	{ KB_UP		, "ku" },
	{ KB_UP		, "UP" },
	{ KB_DOWN	, "kd" },
	{ KB_LEFT	, "kl" },
	{ KB_RIGHT	, "kr" },
	{ KB_PGUP	, "PU" },
	{ KB_PGDN	, "PD" },
	{ KB_BACK_TAB	, "BT" },
	{ KB_TAB	, "TB" },
	{ KB_ESC	, "EC" },
	{ KB_INS	, "al" },
	{ KB_DEL	, "DL" },
	{ KB_F1		, "k1" },
	{ KB_F2		, "k2" },
	{ KB_F3		, "k3" },
	{ KB_F4		, "k4" },
	{ KB_F5		, "k5" },
	{ KB_F6		, "k6" },
	{ KB_F7		, "k7" },
	{ KB_F8		, "k8" },
	{ KB_F9		, "k9" },
	{ KB_F10	, "k0" }
   };


static void kb_install(){
   int i;
   for(i=0;i<sizeof(tab)/sizeof(*tab);i++){
      if(tab[i].capability[0]!=capability[0]) continue;
      if(tab[i].capability[1]!=capability[1]) continue;
      if(capability_value==NULL) return;
      if(capability[2]!='='){
         if( capability_value!=NULL) object_kill(capability_value);
         return;
      }
      {
         int err = inskey(tab[i].key,capability_value);
         if(err==KB_OK) return;
         if(err==KB_STR_EXISTS || err==KB_NULL_STRING){
            object_kill(capability_value);
            return;
         }
         printf("Capability %2.2s cannot be inserted:",capability);
         if(err==KB_TOO_MANY_STRINGS) printf("too many strings\n\r");
         if(err==KB_OUT_OF_MEMORY   ) printf("out of memory\n\r");
         exit(7);
      }
      return;
   }
   if(capability_value!=NULL) object_kill(capability_value);
}


static void kbinit()                   /* inicjalizacja klawiatury  */
{                                      /* RAW MODE                  */
   char *s,*s1;
   int i,err;

   troot=new_tree_node();
   troot[-1].way=NULL;

   capability="DL=";
   capability_value=object_str("\177");
   kb_install();

   if(tfirst(KEYBOARD)==0){
      kb_install();
      while(tnext()==0){
         kb_install();
      }
   }

   if(tfirst(TERMINAL)==0){
      kb_install();
      while(tnext()==0){
         kb_install();
      }
   }

}




/*   FUNCTIONS for search through one TERMCAP entry   */


static char *termcap=NULL;
static char *keybcap=NULL;

#ifndef NO_PROTOTYPES
static char *envset(char *,char*);
static char *findchar(char *,char);
static int convert(char *,char *,int);
static int next_char(FILE *);
static int find_name(FILE *,char *);
#else
static char *envset();
static char *findchar();
static int convert();
static int next_char();
static int find_name();
#endif


static char *findchar(str,ch) char *str,ch;{
   if(str==NULL) return NULL;
   while( *str!='\0'  &&  *str!=ch )  str++;
   if(*str=='\0') return NULL;
   return str;
}

static char *tgetent(dev)
                            /* gets info from variable TERMCAP  */ 
                            /* or var INKEY  or file /etc/inkey */
int dev;{

 if(dev==TERMINAL){
   if(termcap==NULL)   termcap=envset("TERMCAP","termcap");
   if(termcap==NULL){
      fprintf(stderr,"\n\rfile [/etc/]termcap not found\n\r");
      fflush(stderr);exit(7);
   }
   return termcap;
 }else
 if(dev==KEYBOARD){
    if(keybcap==NULL)  keybcap=envset("INKEY","inkey");
    return keybcap;
 }else{ printf("bad device for tgetent \n\r"); exit(7); }
}




static char stat_value[100];

static int tfirst(dev)
   int dev;
{
   char *value;
   capability=tgetent(dev);
   if(capability==NULL) return 1;
   return tnext();
}
static int tnext(){
   char *value,*colon;
   do{
      capability=findchar(capability,':');
      if(capability==NULL) return 1;
      capability++;
      if(*capability=='\0') return 1;
   } while( capability[0]==' ' || capability[0]=='\t' );
   value=findchar(capability,'=');
   colon=findchar(capability,':');
   if( value==NULL || ( colon!=NULL && value!=NULL && colon<value ) ){
      capability_value=object_str("");
      return 0;
   }
   value++;
   if(*value=='\0') return 1;
   convert(stat_value,value,sizeof(stat_value));
   capability_value=object_str(stat_value);
   return 0;
}


static int convert(ptr,tptr,ptr_size) char *ptr,*tptr; int ptr_size; {
   int i;
   char c;
   while( (tptr!=NULL) && (*tptr!=':') && (*tptr!='\0') )
      switch(*tptr){
         case '\\':tptr++;
                   switch(*tptr){
                      case 'E' :tptr++;ptr_size--;*(ptr++)='\x1b';break;
                      case 'n' :tptr++;ptr_size--;*(ptr++)='\n';break;
                      case 'r' :tptr++;ptr_size--;*(ptr++)='\r';break;
                      case 't' :tptr++;ptr_size--;*(ptr++)='\t';break;
                      case 'b' :tptr++;ptr_size--;*(ptr++)='\b';break;
                      case 'f' :tptr++;ptr_size--;*(ptr++)='\f';break;
                      case '\\':tptr++;ptr_size--;*(ptr++)='\\';break;
                      case '^' :tptr++;ptr_size--;*(ptr++)='^';break;
                      default  :*ptr='\0';
                                for(i=0;i<3;i++){
                                   if(*tptr<'0' || *tptr>'7') return 1;
                                   *ptr*=8;
                                   *ptr+=*(tptr++)-'0';
                                }
                                ptr++; ptr_size--;
                   }
                   break;
         case '^': tptr++;
                   c=*(tptr++);
                   *(ptr++)=(char)((toupper(c))-'A'+1); ptr_size--;
                   break;
         default: *(ptr++)=*(tptr++); ptr_size--; 
      } 
   *ptr='\0';
   if( ptr_size<=0 ){
      fprintf(stderr,"buffer exceeded in convert(%s)",__FILE__);
      fflush(stderr);
      exit(7);
   }
   return 0;
}


/*     FUNCTIONS looking for entries in /ETC/TERMCAP      */



static char etcname[80];
static char termname[80];
static char *fname;


static char *envset(envname,envfile) char *envname,*envfile;{
   extern char *getenv();
   char *TERM=getenv("TERM");
   char *env=getenv(envname);
   char *str,*ptr;
   FILE *f;
   int c,continued=1;

   ptr=str=object_dim(32000,char);
   if(str==NULL){
      fprintf(stderr,"Out of memory.\n");
      fflush(stderr);
      exit(7);
   }

   if(TERM==NULL){
      fprintf(stderr,"\n\renvironment variable TERM not found\n\r");
      fflush(stderr);
      exit(7);
   }

   strcpy(termname,TERM);

   f=fopen(env,"r");
   if( f==NULL )  f=fopen(envfile,"r");  else  fname=env;
   if( f==NULL )  f=fopen(strcat(strcpy(etcname,"/etc/"),envfile),"r");
   else           fname=envfile;
   if( f==NULL )  return NULL;
   else           fname=etcname;

   while( continued ){

      char *rev,*tnm;

      if( find_name(f,termname)==0 )   return object_str(":");

      *(ptr++)=':';
      c=' ';
      do{
         c=next_char(f);
         if( c!='\0' ) *(ptr++)=(char)c;
      }while( c!='\0' );

      *(ptr)='\0';
      rev=ptr-1;
      while( rev>str && rev[-1]!=':' )  rev--;
      if( rev[0]=='t' && rev[1]=='c' ){
         ptr=rev-1;
         rev+=3;
         tnm=termname;
         while( *rev!=':' ) *(tnm++)=*(rev++);
         *tnm='\0';
         continued=1;
      }else  continued=0;

   }

   ptr=object_str(str);
   object_kill(str);
   return ptr;

}

static int find_name(f,termname) FILE *f; char *termname;{
   int i,c,lastc,found=0;
   fseek(f,0L,0);

   do{

      do{
         c=fgetc(f);
         if(c==EOF)  return 0;
         if(c=='#' || c=='\t' || c==':' || c=='\n')
            while(c!='\n'){
               lastc=c;
               c=fgetc(f);
               if(c==EOF)  return 0;
               if( lastc=='\\' ) c=' ';
            }
      }while(c=='\n');

      while( !found ){
         for(i=0;termname[i]!='\0';i++){
            if((char)c!=termname[i]) break;
            c=fgetc(f);
         }
         if( termname[i]=='\0' ){ found=1; break; }
         while( isalpha((char)c) )  c=fgetc(f);
         if( c=='|' )  c=fgetc(f);
         else{ ungetc('#',f); break; }
      }

   } while( !found );

   while(c!=':'){
      c=fgetc(f);
      if(c==EOF)  return 0;
   }

   return 1;
}


static int next_char(f) FILE *f;{
   int c;
   static int lastc='\0';
   if( lastc!='\0' ){
      c=lastc;
      lastc='\0';
      return c;
   }
   c=fgetc(f);
   if( c==EOF || c=='\n' )  return '\0';
   if( c=='\\' ){
      c=fgetc(f);
      if( c=='\n' ){
         while( c=='\n' || c=='\t' || c==':' || c==' ' )  c=fgetc(f);
         return c;
      }
      lastc=c;
      return '\\';
   }
   return c;
}




static void *___allocate_object(size) unsigned size;{
   char *p;
   extern void *calloc();
   if(size==0) return NULL;
   p=calloc(size,1);
   if( p==NULL ){
      printf("\r\n");
      printf("=======================================\r\n");
      printf("Memory overflow ... \r\n");
      printf("=======================================\r\n");
      fflush(stdout);
      system("stty sane");
      exit(7);
   }
   return (void *)p;
}

static void ___free_object(ff) void *ff;{
   assert(ff!=NULL);
   free((char *)ff);
}

static char *object_str(str) char *str;{
   char *buf=object_dim(strlen(str)+1,char);
   strcpy(buf,str);
   return buf;
}
