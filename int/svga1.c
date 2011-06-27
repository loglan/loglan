#include <grx.h>
#include <mousex.h>
#include "eventque.h"

int Couleur,Fond,CurX,CurY;
int Coul[4],Pal;
int MOUSE_PRESENT =0;

MouseEvent *evt;
EventQueue *q;
char *ret;

void mousenit(int mo,int ke)
{
  MouseEventMode(1);
  MouseInit();
  evt=(MouseEvent *)malloc(sizeof(MouseEvent));
  MouseEventEnable(ke,mo);
  MOUSE_PRESENT=1;
}

void mouseshow(void)
{
 MouseDisplayCursor();
}

void mousehide(void)
{
 MouseEraseCursor();
}

int mouse(v,p,h,l,r,c)
unsigned int *v,*p,*h,*l,*r,*c;
{
 EventRecord e;
 MouseEvent *ev1;
 short result=0;

 *v=0,*p=0,*h=0,*l=0,*r=0,*c=0;

 ev1=evt;
 evt=(MouseEvent *)calloc(1,sizeof(MouseEvent));
 MouseGetEvent(M_EVENT | M_POLL | M_NOPAINT,evt);
 *p=evt->kbstat; *l=evt->key;
 *h=evt->x;      *v=evt->y;
 *r=evt->flags;  *c=evt->buttons;
 if(ev1->kbstat!=evt->kbstat || ev1->key!=evt->key || ev1->x!=evt->x ||
    ev1->y!=evt->y || ev1->flags!=evt->flags || ev1->buttons!=evt->buttons)
  result=1;
 free(ev1);
 return(result);
}

void afficheinteger(int x,int y,int valeur,int cf,int ce)
{
 char tst[20];

 sprintf(tst,"%i",valeur);
 GrTextXY(x,y,tst,ce,cf);
 CurX+=8*strlen(tst);
 if(CurX>GrMaxX())
  {
  CurX=0;
  CurY+=14;
  }
}



int readcara(int posx,int posy,int col_f,int col_e)
{
 char *t="_\0";
 int a;

 while(!kbhit())
  {
  GrHLine(posx,posx+8,posy+13,col_f);
  delay(200);
  GrHLine(posx,posx+8,posy+13,col_e);
  delay(100);
  }
 GrHLine(posx,posx+8,posy+13,col_f);
 a=getxkey();
 if(!a)
  return(getxkey());
 else
  return(a);
}


void beep(void)
{
 printf("%c\n",7);
}

int affiche_chaine(int x,int y,int lg,char *txtd,char *txtf,int av,int *ll,int col_e,int col_f)
{
 int larg;
 char cara[2];


 if(!av)
  {
  for(sprintf(&cara[0],"%c\0",*txtf),larg=0;txtf>=txtd;txtf--) /* affiche arriere */
   {
   GrTextXY(x+lg-larg,y,&cara[0],col_e,col_f);
   larg+=8;
   sprintf(&cara[0],"%c\0",*(txtf-1));
   if((lg-larg-8)<0)
    break;
   }
  if(txtf<=txtd)
   {
   *ll-=6;
   return(1);
   }
  else
   return(0);
  }
 else
  {
  for(sprintf(&cara[0],"%c\0",*txtd),larg=0;txtd<=txtf;txtd++) /* affiche avant */
   {
   GrTextXY(x+larg,y,&cara[0],col_e,col_f);
   larg+=8;
   sprintf(&cara[0],"%c\0",*(txtd+1));
   if((lg-larg-8)<0)
    break;
   }
  if(txtd<=txtf)
   return(0);
  else
   return(1);
  }
}

int gscanfnum(int x,int y,int lg,int min,int max,int deft,int col_f,int col_e,int col_c)
{

 char t[10],a;
 int larg=0,flg=0;
 char *ptd,*ptc;
 int i;
 int cpt=0;
 short chgt=0;
 short signe=0;  /* par defaut 0(+) sinon 1(-) */

 ptc=ptd=&t[0];
 GrFilledBox(x,y,x+lg,y+14,col_f);
 sprintf(t,"%lu\0",deft);
 while(*ptc!='\0') ptc++;
 GrTextXY(x+lg-strlen(t)*8,y,t,col_e,col_f);
 do
  {
  a=readcara(x+lg-8,y,col_f,col_c);
  switch(a)
   {
   case 8:
    if(ptc>ptd)
     {
     ptc--;
     cpt--;
     if(flg)
      larg-=8;
     *(ptc)='\0';
     }
    else
     {
     larg=0;
     ptc=ptd;
     beep();
     }
    break;
   case 13:
    if(ptc==ptd)
     {
     *ptc='\0';
     a=11;
     }
    break;
   case 43:
    signe=0;
    chgt=1;
    if(cpt==0)
     *ptc='\0';
    break;
   case 45:
    signe=1;
    chgt=1;
    if(cpt==0)
     *ptc='\0';
    break;
   default:
    if(cpt<10)
     {
     if((a<='9') && (a>='0'))
      {
      *(ptc++)=a;
      cpt++;
      *ptc='\0';
      }
     }
    else
     beep();
    break;
   }
  GrFilledBox(x,y,x+lg,y+14,col_f);
  affiche_chaine(x,y,lg,ptd,ptc,flg,&larg,col_e,col_f);
  if(chgt)
   if(signe)
     GrTextXY(x,y,"-",col_e,col_f);
   else
     GrTextXY(x,y,"+",col_e,col_f);
  }
 while((a!=13) && (a!=27));
 if(a==13)
  {
  i=atol(t);
  if(signe)
   i=-i;
  if((i<=max) && (i>=min))
   return(i);
  else
   {
   beep();
   return(gscanfnum(x,y,lg,min,max,deft,col_f,col_e,col_c));
   }
  }
 else
  return(gscanfnum(x,y,lg,min,max,deft,col_f,col_e,col_c));
}


/******************************************************************************/
char *gschar(int x,int y,int lg,int *lgmax,char *defaut,int col_f,int col_e,int col_c)
{

 char *ptd,*ptc,a;
 int larg=0,flg=1;

 ptd=(char *)malloc(*lgmax);
 ptc=ptd;
 GrFilledBox(x,y,x+lg*8,y+14,col_f);
 GrTextXY(x,y,defaut,col_e,col_f);
 do
  {
  a=readcara((larg<(lg-1)*8) ? (x+larg) : (x+(lg-1)*8),y,col_f,col_c);
  switch(a)
   {
   case 8:
    if(ptc>ptd)
     {
     ptc--;
     if(flg)
      larg=(larg-8)>0 ? larg-8 : 0;
     *(ptc)='\0';
     }
    else
     {
     larg=0;
     ptc=ptd;
     beep();
     }
    break;
   case 13:
    break;
   default :
    if(((ptc-ptd)/sizeof(char))<=*lgmax)
     {
     *(ptc++)=a;
     *ptc='\0';
     if(flg)
      larg+=8;
     }
    else
     beep();
   }
  GrFilledBox(x,y,x+lg*8,y+14,col_f);
  flg=affiche_chaine(x,y,(lg-1)*8,ptd,ptc,flg,&larg,col_e,col_f);
  }
 while((a!=13) && (a!=27));
 if((a==27) || (ptd==ptc))
  {
  ptc=ptd=defaut;
  while(*ptc!='\0') ptc++;
  }
 else
  *ptc='\0';
 GrFilledBox(x,y,x+lg*8,y+14,col_f);
 affiche_chaine(x,y,lg*8,ptd,ptc,1,&larg,col_e,col_f);
 *lgmax=(ptc>ptd)? ptc-ptd+1 : 0;
 return(ptd);
}
