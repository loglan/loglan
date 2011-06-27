     /* Loglan82 Compiler&Interpreter
     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw
     Copyright (C)  1993, 1994 LITA, Pau
     
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.
     
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
     
=======================================================================
*/

#include "graf.h"

#define isign(k, i)	(((i) >= 0) ? (k) : -(k))
#define iabs(i)		((i) >= 0 ? (i) : -(i))
#define sqr(x)		((x)*(x))
#define min0(x, y)	((x) < (y) ? (x) : (y))
#define max0(x, y)	((x) > (y) ? (x) : (y))

#define alf(i)		alf_[i]
#define ix(i)		ix_[i]
#define iy(i)		iy_[i]
#define sx(i)		sx_[i]
#define sy(i)		sy_[i]
#define d(i)		d_[i]
#define min(i)		min_[i]
#define max(i)		max_[i]
#define mx(i)		mx_[i]
#define mx1(i)		mx1_[i]
#define incr1(i)	incr1_[i]
#define incr2(i)	incr2_[i]
#define ip(i)		ip_[i]
#define sj(i)		sj_[i]
#define sc(i)		sc_[i]
#define bl(i)		bl_[i]
#define bxy(i)		bxy_[i]
#define bp(i)		bp_[i]
#define g(i,j)		g_[i][j]
#define go(i,j)		go_[i][j]

#define logical		int
#define FALSE		0
#define TRUE		1
#define INT(x)		((int) (x))
#define FLOAT(x)	((float) (x))
#define SIN(x)		sin((double) (x))
#define COS(x)		cos((double) (x))
#define SQRT(x)		sqrt((double) (x))

int pa = 3, qa = 4;
float asp = 0.75;

void pascal cirb(xi, yi, ri, alfa, beta, cbord, bcint, p, q)
int *xi, *yi, *ri;
float *alfa, *beta;
int *cbord, *bcint, *p, *q;
{
    extern void pascal wyc47();
    
    wyc47(*xi, *yi, (double) *ri, (double) *alfa, (double) *beta,
          *cbord, *bcint, pa*(*p), qa*(*q), (double) 1.0);
}

/***********************************************************************
void pascal rcirb(xr, yr, r, alfa, beta, cbord, bcint, p, q)
float *xr, *yr, *r, *alfa, *beta;
int *cbord, *bcint, *p, *q;
{
    extern void pascal wyc47();
    extern float mix, miy, sxx, syy;
    extern int mii, maj;
    
    wyc47(mii+INT(sxx*(*xr-mix)), maj-INT(syy*(*yr-miy)), (double) *r,
          (double) *alfa, (double) *beta,
          *cbord, *bcint, pa*(*p), qa*(*q), (double) sxx);
}
***********************************************************************/

void pascal wyc47(ir, jr, r, alfa, beta, cbord, bcint, p, q, cx)
int ir, jr;
double r, alfa, beta;
int cbord, bcint, p, q;
double cx;
{
        extern  double sin(), cos(), sqrt();
    	extern  void pascal move(),  pascal hfill(), pascal pushxy(),
	             pascal popxy(), pascal color(), pascal style();

	float   alfj,qasp,pr,a,s,c;
	float   alf(2+1);
	long    p1,q1,p2,q2,p4,q4,u,v,w,d1;
	int     i,j,j1,j2,j3,k,l,n,m,m1,m2,ri,x,y,py,px1,
                px2,sxi,sy1,sy2,xi,dj,dxj,dyj,inc1,
                pa,qa;
	int     ix(2+1),iy(2+1),sx(2+1),sy(3+1),d(2+1),min(5+1),max(5+1),
	        mx(2+1),mx1(2+1),incr1(2+1),incr2(2+1),ip(2+1),sj(2+1),
		sc(3+1),g(3+1,2+1),go(3+1,2+1);
	logical bl(2+1),bxy(2+1),bp(3+1);
	logical bc;
	static int one = 1;

	qasp=asp*FLOAT(q);
	a=cx*r;
	ri=INT(a);
	pr=a*FLOAT(p);
	q1=q*q;
	q2=2*q1;
	q4=2*q2;
	p1=p*p;
	p2=2*p1;
	p4=2*p2;
	for (i=1; i <= 3; i++)
	{
	   bp(i)=FALSE;
	   for (j=1; j <= 2; j++)
	   {
	      go(i,j)=3;
 	      g(i,j)=3;
	   }
	}
 	sj(1)=1;
 	sj(2)=-1	   ;
	if(alfa == beta) {
	   n=2;
	   sc(1)=1;
	   sc(2)=-1;
	   bp(3)=TRUE;
	   bl(1)=TRUE;
	   bl(2)=TRUE;
	   goto L45;
	}
	alf(1)=alfa;
	alf(2)=beta;

	for (j=1; j <= 2; j++)
	{
	   alfj=alf(j);
	   c=COS(alfj);
	   s=SIN(alfj);
	   a=pr/SQRT(sqr(p*c)+sqr(qasp*s));
	   m=INT(a*c);
	   sx(j)=isign(1,m);
	   ix(j)=m;
	   m=-INT(a*asp*s);
	   sy(j)=isign(1,m);
	   iy(j)=iabs(m);
 	}

	sy1=sy(1);
	sy2=sy(2);
	sc(1)=sy1;
	sc(2)=sy2;
	if (sy1 >= 0) {
	   j1=1;
	   j2=2;
	} else {
	   j1=2;
	   j2=1;
	}

	if (sy1 == sy2) {
	   m=sy1*(ix(2)-ix(1));
	   if (isign(1,m) > 0) {
	      n=1;
	      bp(2)=TRUE;
	      bp(3)=TRUE;
	      g(1,1)=j1;
	      g(1,2)=j2;
	      go(1,1)=j1;
	      go(1,2)=j2;
	   } else {
	      n=3;
	      sc(3)=-sy1;
	      g(1,2)=j2;
	      g(2,1)=j1;
	      go(1,2)=j2;
	      go(2,1)=j1;
	   }
	} else {
	   n=2;
	   bp(3)=TRUE;
	   g(1,j1)=1;
	   g(2,j1)=2;
	   go(1,j1)=1;
	   go(2,j1)=2;
	}

	bl(1)=FALSE;
	bl(2)=FALSE;

	for (j=1; j <= 2; j++)
	{
	   dxj=iabs(ix(j));
	   ix(j)=dxj;
	   dyj=iy(j);
	   ip(j)=0;
	   if (dyj > dxj) {
	      bxy(j)=TRUE;
	      m=2*dxj;
	      d(j)=m-dyj;
	      incr2(j)=2*(dxj-dyj);
	   } else {
	      bxy(j)=FALSE;
	      m=2*dyj;
	      d(j)=m-dxj;
	      incr2(j)=2*(dyj-dxj);
	   }
 	   incr1(j)=m;
 	}


 L45:	u=0;
	v=ri*p4;
	d1=q2-p1*(2*ri-1);
	x=ri;
	min(3)=x;
	max(3)=x;
	bc=FALSE;
	y=0;


 L300:	for (j=1; j <= 2; j++)
 	{
 	   if (bl(j)) continue;
 	   dj=d(j);
 	   xi=ip(j);
 	   min(j)=xi;
 	   m=ix(j);
 	   if (bxy(j)) {
 	      max(j)=xi;
 	      if (dj > 0) {
 	         d(j)=dj+incr2(j);
 	         if (xi >= m) bl(j)=TRUE;
 	         ip(j)=xi+1;
	      } else {
	          d(j)=dj+incr1(j);
	      }
	   } else {
	      inc1=incr1(j);
 L40:	      if (dj > 0) {
 	         d(j)=dj+incr2(j);
 	         ip(j)=xi+1;
 	         max(j)=xi;
	      } else {
	         dj=dj+inc1;
	         xi=xi+1;
	         if (xi >= m) {
	            dj=1;
	            bl(j)=TRUE;
	         }
	         goto L40;
	      }
	   }
	   if (y == iy(j)) bl(j)=TRUE;
 	}


	for (i=1; i <= n; i++)
 	{
 	   if (bp(i)) continue;
 	   j1=g(i,1);
 	   j2=g(i,2);
 	   if (j1 != 3) {
 	      j3=j1;
 	      l=1;
 	   } else {
 	      j3=j2;
 	      l=2;
 	   }
 	   j=j1+j2;
 	   sy(3)=sc(i);
 	   if ((j == 4 || j == 5) && bl(j3)) {
	      m=ix(j3);
 	      if (sy(j3) == sj(j3)*sx(j3)) {
 	         bp(i)=TRUE;
 	         min(j)=m;
 	         max(j)=max0(max(3),m);
 	         if (j1 != 3) {
 	            j2=j;
 	         } else {
 	            j1=j;
 	         }
 	      } else {
 	         g(i,l)=3;
 	         sc(i)=sy(j3);
 	         min(j3)=min0(min(j3),min(3));
 	      }
 	   } else {
 	      if (j == 3) {
 	         for (l=1; l <= 2; l++)
		 {
 	            j=g(i,l);
 	            if (bl(j)) {
 	               g(i,l)=3;
  	               sc(i)=sy(j);
 	               min(j)=min0(min(j),min(3));
	            }
		 }
 	      }
 	   }

	   j=j1;
	   for (l=1; l <= 2; l++)
	   {
	      m1=max(j);
	      m2=min(j);
	      if (j < 3) {
	         sxi=sx(j);
	      } else {
	         sxi=-sj(l);
	         if (j == 3) {
	            k=go(i,l);
	            if (k < 3) {
	               m1=min0(m1,max(k));
	               m2=min0(m1,m2);
	            }
	         }
	      }
	      if (sxi > 0) {
	         mx(l)=ir+m2;
	         mx1(l)=ir+m1;
	      } else {
	         mx(l)=ir-m1;
	         mx1(l)=ir-m2;
	      }
	      j=j2;
	   }

	   py=jr+sy(j3)*y;
	   if (bcint != 0) {
	      px1=mx1(1)+1;
	      px2=mx(2)-1;
	      if (px1 <= px2) {
	         move(&px1,&py);
	         hfill(&px2);
	      }
	   }
	   pushxy();
	   color(&cbord);
	   style(&one);
	   move(&mx(1),&py);
	   hfill(&mx1(1));
	   move(&mx(2),&py);
	   hfill(&mx1(2)) ;
	   popxy();
	}

	if (x == 0) return;


	if (bp(1) && bp(2) && bp(3)) return;
	if (bc) goto L240;

 	u=u+q4;
 	if (d1 < 0) {
 	   d1=d1+u+q2;
	} else {
	   v=v-p4;
	   w=u-v;
	   if (w > 0) {
	      bc=TRUE;
	      w=w/2-v;
	   }
	   d1=d1+w+q2;
	   x=x-1;
	}
	y=y+1;
	min(3)=x;
	max(3)=x;
	if (bc) goto L250;
	goto L300;

 L240:	max(3)=x;
	y=y+1;
 L250:	v=v-p4;
 	x=x-1;
 	if (d1 > 0) {
 	   d1=d1-v+p2;
	} else {
	   u=u+q4;
	   d1=d1+u-v+p2;
	   min(3)=x+1;
	   goto L300;
	}
	if (x > 0) goto L250;
	min(3)=x;
	goto L300;
}


