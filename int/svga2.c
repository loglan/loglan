case GRON:      switch (param[0].xword)
		{
		 case 0:  GrSetMode(GR_width_height_graphics,
				    640,480,16);
			  Res_graph_X=640;
			  Res_graph_Y=480;
			  break;
		 case 1:  GrSetMode(GR_width_height_graphics,
				    640,480,256);
			  Res_graph_X=640;
			  Res_graph_Y=480;
			  break;
		 case 2:  GrSetMode(GR_width_height_graphics,
				    800,600,16);
			  Res_graph_X=800;
			  Res_graph_Y=600;
			  break;
		 
		 case 3:  GrSetMode(GR_width_height_graphics,
				    800,600,256);
			  Res_graph_X=800;
			  Res_graph_Y=600;
			  break;
		 case 4:  GrSetMode(GR_width_height_graphics,
				    1024,768,16);
			  Res_graph_X=1024;
			  Res_graph_Y=768;
			  break;
		 case 5:  GrSetMode(GR_width_height_graphics,
				    1024,768,256);
			  Res_graph_X=1024;
			  Res_graph_Y=768;
			  break;
		 case 6:  GrSetMode(GR_width_height_graphics,
				    1280,1024,16);
			  Res_graph_X=1280;
			  Res_graph_Y=1024;
			  break;
		 case 7:  GrSetMode(GR_width_height_graphics,
				    1280,1024,256);
			  Res_graph_X=1280;
			  Res_graph_Y=1024;
			  break;
		 case 8:  GrSetMode(GR_width_height_graphics,
				    1600,1280,16);
			  Res_graph_X=1600;
			  Res_graph_Y=1280;
			  break;
		 case 9:  GrSetMode(GR_width_height_graphics,
				    1600,1280,256);
			  Res_graph_X=1600;
			  Res_graph_Y=1280;
			  break;
		 default: GrSetMode(GR_width_height_graphics,
				    320,200,256);
			  Res_graph_X=320;
			  Res_graph_Y=200;
		}
		GrClearScreen(0);
		break;

case POINT:     CurX=param[0].xword;
		CurY=param[1].xword;
		GrPlot(CurX,CurY,Couleur);
		break;

case INPIX:     CurX=param[0].xword;
		CurY=param[1].xword;
		param[2].xword=GrPixel(CurX,CurY);
		break;

case MOVE:      CurX=param[0].xword;
		CurY=param[1].xword;
		break;

case COLOR:     Couleur=param[0].xword;
		break;

case PALETT:    Coul[Pal++]=param[0].xword;
		if (Pal==4)
		{
		 GrSetColor(Coul[0],Coul[1],Coul[2],Coul[3]);
		 Pal=0;
		}
		break;

case GROFF:     if(MOUSE_PRESENT) MouseUnInit();
		GrSetMode(GR_80_25_text);
		break;

case DRAW:      GrLine(CurX,CurY,param[0].xword,param[1].xword,Couleur);
		CurX=param[0].xword;
		CurY=param[1].xword;
		break;

case HFILL:     GrHLine(CurX,param[0].xword,CurY,Couleur);
		CurX=param[0].xword;
		break;

case VFILL:     GrVLine(CurX,CurY,param[0].xword,Couleur);
		CurY=param[0].xword;
		break;

case CLS:       GrClearScreen(Fond);
		break;

case BORDER:    Fond=param[0].xword;
		break;

case INXPOS:    param[0].xword=CurX;
		break;

case INYPOS:    param[0].xword=CurY;
		break;

case OUTSTRING:
		{
		 char *Texte= (char *)(M + strings + param[ 2 ].xword + 1);
		 if(param[0].xint==-1) ax=CurX;
		 else ax=param[0].xint;
		 if(param[1].xint==-1) bx=CurY;
		 else bx=param[1].xint;
		 if(param[3].xint==-1) cx=Couleur;
		 else cx=param[3].xint;
		 if(param[4].xint==-1) dx=Fond;
		 else dx=param[4].xint;
		 GrTextXY(ax,bx,Texte,cx,dx);
		 if(param[0].xint==-1 && param[1].xint==-1)
		  {
		  CurX+=8*strlen(Texte);
		  if(CurX>GrMaxX())
		   {
		   CurX=0;
		   CurY+=14;
		   }
		  }
		}
		break;

case HASCII:
		{
		 char *Texte=(char *)&param[ 0 ].xword;
		 GrTextXY(CurX,CurY,Texte,Couleur,Fond);
		 CurX+=8;
		 if (CurX>GrMaxX())
		 {
		  CurX=0;
		  CurY+=14;
		 }
		}
		break;

case INKEY:
		{
		 int Touche;

		 Touche=kbhit();
		 if (Touche)
		  param[0].xword=getkey();
		 else
		  param[0].xword=0;
		}
		break;

case GETMAP :   {
		 int w,h;
		 GrContext *Destination;

		 w=abs(param[0].xword-CurX)+1;
		 h=abs(param[1].xword-CurY)+1;
		 newarry((word)1,3,(word)AINT,&param[2].xvirt,&am);
		 Destination=GrCreateContext(w,h,
					     NULL,NULL);
		 M[am+3]=(int)Destination;
		 M[am+4]=w;
		 M[am+5]=h;
		 GrBitBlt(Destination,0,0,
			  NULL,CurX,CurY,param[0].xword,param[1].xword,
			  GrWRITE);
		}
		break;

case PUTMAP :   if (member(&param[0].xvirt,&am))
		 GrBitBlt(NULL,CurX,CurY,
			  (GrContext *)M[am+3],0,0,M[am+4],M[am+5],GrWRITE);
		else
		 errsignal(RTEREFTN);
		break;

case ORMAP :    if (member(&param[0].xvirt,&am))
		 GrBitBlt(NULL,CurX,CurY,
			  (GrContext *)M[am+3],0,0,M[am+4],M[am+5],GrOR);
		else
		 errsignal(RTEREFTN);
		break;

case XORMAP :   if (member(&param[0].xvirt,&am))
		 GrBitBlt(NULL,CurX,CurY,
			  (GrContext *)M[am+3],0,0,M[am+4],M[am+5],GrXOR);
		else
		 errsignal(RTEREFTN);
		break;

case INTENS :   {
		word am1,am2;
		int  i;
		int pt1[30][2];

		if(member(&param[1].xvirt,&am1) && member(&param[2].xvirt,&am2))
		 {
		 if(param[0].xint>30) param[0].xint=30;
		 for(i=0;i<param[0].xint;i++)
		  {
		  pt1[i][0]=M[am1+3+i];
		  pt1[i][1]=M[am2+3+i];
		  }
		 if(param[4].xint!=0)
		  GrFilledPolygon(param[0].xint,pt1,param[3].xint);
		 else
		  GrPolygon(param[0].xint,pt1,param[3].xint);
		 }
		else
		 errsignal(RTEREFTN);
		}
		break;

case PATERN :
		if(param[5].xint!=0)
		 GrFilledBox(param[0].xint,param[1].xint,param[2].xint,param[3].xint,param[4].xint);
		else
		 GrBox(param[0].xint,param[1].xint,param[2].xint,param[3].xint,param[4].xint);
		break;
case TRACK :    afficheinteger(param[0].xint,param[1].xint,param[2].xint,param[3].xint,
			       param[4].xint);
		break;
case HFONT :    param[9].xint=gscanfnum(param[0].xint,param[1].xint,param[2].xint*8,
				   param[3].xint,param[4].xint,param[5].xint,
				   param[6].xint,param[7].xint,param[8].xint);
		break;

case HFONT8 :   {
		 char *Texte= (char *)(M + strings + param[ 4 ].xword + 1);

		 ret=gschar(param[0].xint,param[1].xint,param[2].xint,&param[3].xint,
			   Texte,param[5].xint,param[6].xint,param[7].xint);

		 newarry((word) 0, param[3].xint-2,(word) AINT,&param[8].xvirt,&ax);
		 ax+=3;
		 while(*ret!='\0')
		  M[ax++]=*(ret++);
		}
		break;

case CIRB :     {
		ax=param[0].xint-param[2].xint; /* x */
		bx=param[1].xint-param[3].xint; /* y */
		cx=param[2].xint*2;             /* rax */
		dx=param[3].xint*2;             /* ray */
		if(param[7].xint!=0)
		 GrFilledEllipseArc(ax,bx,cx,dx,param[4].xint,param[5].xint,
				    param[6].xint);
		else
		 GrEllipseArc(ax,bx,cx,dx,param[4].xint,param[5].xint,
			      param[6].xint);
		}
		break;
/* MOUSE */

case INIT :     mousenit(param[0].xint,param[1].xint);
		break;

case SHOWCURSOR :
		mouseshow();
		break;

case HIDECURSOR :
		mousehide();
		break;

case STATUS :
		break;

case SETPOSITION :
		MouseWarp(param[0].xint,param[1].xint);
		break;

case GETPRESS :
case GETRELEASE :
	    
		ax=mouse(&v,&p,&h,&l,&r,&c);
		param[ 5 ].xint = c;
		param[ 4 ].xint = r;
		param[ 3 ].xint = l;
		param[ 2 ].xint = p;
		param[ 1 ].xint = v;
		param[ 0 ].xint = h;
		/* parametre en retour*/
		if(ax)
		 param[ 6 ].xbool = TRUE;
		else
		 param[ 6 ].xbool = FALSE;
		break;

case SETWINDOW :
		MouseSetLimits(param[0].xint,param[1].xint,param[2].xint,param[3].xint);
		break;

case DEFCURSOR :
		break;

case GETMOVEMENT :
		MouseEventEnable(param[1].xint,param[0].xint);
		break;

case SETSPEED :
		MouseSetSpeed(param[0].xint);
		break;

case SETTHRESHOLD :
		break;

