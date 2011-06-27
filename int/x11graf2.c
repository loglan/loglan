/*     Loglan82 Compiler&Interpreter
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

#define send_par(par) theMessage.data.s[cnt++]=(short)(param[par].xword);
#define send_shrt(wd) theMessage.data.s[cnt++]=(short)(wd);
#define send_word(wd) theMessage.data.s[cnt++]=(short)((wd)&0xffff); \
                      theMessage.data.s[cnt++]=(short)(((wd)>>16)&0xffff);


#define send_sig			\
   theMessage.type=ClientMessage;	\
   theMessage.format = 16;		\
   theMessage.message_type = nrproc;	\
   XSendEvent(theDisplay,theWindow,True,NoEventMask,&theMessage);	\
   XFlush(theDisplay);

#define nxtev do XNextEvent( theDisplay, &retEv );	\
              while( retEv.type!=ClientMessage );	\
              cnt = 0;

#define rec_par(par) param[par].xword=(int)(retEv.xclient.data.s[cnt++]);
#define rec_shrt(sh) sh  = (int)(retEv.xclient.data.s[cnt++]);
#define rec_word(wd) wd  = (int)(retEv.xclient.data.s[cnt++]) & 0xffff; \
                     wd |= (int)(retEv.xclient.data.s[cnt++]) << 16;



        case GRON :
                if ((theDisplay = XOpenDisplay(NULL)) == NULL){
                   fprintf (stderr,"\nint:  Can't open display\n");
                   exit(1);
                }
                myWindow = XCreateWindow(
                              theDisplay,
                              RootWindow(theDisplay,DefaultScreen(theDisplay)),
                              0,0,1,1,0,
                              CopyFromParent,InputOnly,CopyFromParent,
                              0,NULL
                           );
                if( (child_no=fork())==0 ){
                   char me[16];
                   sprintf(me,"%d",(int)myWindow);
                   execlp("herc","herc",me,NULL);
                }
		graphmode = TRUE;
                curx=cury=0;
                nxtev
                rec_word(theWindow);
		break;
		
	case GROFF :
		if( graphmode == FALSE )  break;
		send_sig
                child_no=0;
		graphmode = FALSE;
		break;
	
	case CLS :
		send_sig
		break;
	

	case PUSHXY :
                xystack[stackptr].x = curx;
                xystack[stackptr].y = cury;
                xystack[stackptr].fcol = fcol;
                xystack[stackptr].bcol = bcol;
                xystack[stackptr].style= style;

                stackptr++;
                if( stackptr == 16 ) stackptr--;

		break;


	case POPHXY :

                stackptr--;
                if( stackptr < 0 ){
                   stackptr = 0;
                   break;
                }

                curx = xystack[stackptr].x;
                cury = xystack[stackptr].y;
                fcol = xystack[stackptr].fcol;
                bcol = xystack[stackptr].bcol;
                style= xystack[stackptr].style;

                cnt = 0;
                nrproc = COLOR;
		send_shrt(fcol)
		send_sig

                cnt = 0;
                nrproc = BORDER;
		send_shrt(bcol)
		send_sig

                cnt = 0;
                nrproc = STYLE;
		send_shrt(style)
		send_sig

		break;


	case POINT :
		send_par(0)
		send_par(1)
		send_sig
	case MOVE :
                curx=param[0].xword;
                cury=param[1].xword;
		break;
		
	case DRAW :
		send_shrt(curx)
		send_shrt(cury)
		send_par(0)
		send_par(1)
		send_sig
                curx=param[0].xword;
                cury=param[1].xword;
		break;
		
	case INXPOS :
                param[0].xword = curx;
		break;
	
	case INYPOS :
                param[0].xword = cury;
		break;
	
        case HFILL :
        case VFILL :
		send_shrt(curx)
		send_shrt(cury)
		send_par(0)
		send_sig
		break;
		
        case HASCII :
		send_shrt(curx)
		send_shrt(cury)
		send_par(0)
		send_sig
		if( param[0].xword != 0 )  curx += 8;
		break;
		
        case COLOR :
                fcol = param[0].xword;
		send_par(0)
		send_sig
		break;
		
        case BORDER :
                bcol = param[0].xword;
		send_par(0)
		send_sig
		break;
		
        case STYLE :
                bcol = param[0].xword;
		send_par(0)
		send_sig
		break;
		
	case INPIX :
		send_par(0)
		send_par(1)
		send_sig
                curx=param[0].xword;
                cury=param[1].xword;
                nxtev
		rec_par(2)
		break;

	case OUTSTRING :
                {
		   char *s= (char *)(M + strings + param[ 0 ].xword + 1);
                   int signs=M[ strings + param[ 0 ].xword ];
                   nrproc=HASCII;
                   while( signs-- ){
                      word sign=0;
                      cnt = 0;
		      send_shrt(curx)
		      send_shrt(cury)
                      send_shrt(sign)
		      send_sig
                      sign = (word)(*s);
                      cnt = 0;
		      send_shrt(curx)
		      send_shrt(cury)
                      send_shrt(sign)
		      send_sig
                      s++;
                      curx+=8;
                   }
                }
		break;

	case GETMAP :
                {
                   word map;
                   word x=param[0].xword;
                   word y=param[1].xword;
                   word w = x - curx + 1;
                   word h = y - cury + 1;
                   x = curx;
                   y = cury;
                   if( w <= 0 ){ w=-w; x-=w; }
                   if( h <= 0 ){ h=-h; y-=h; }
                   send_shrt(x)
		   send_shrt(y)
                   send_shrt(w)
		   send_shrt(h)
		   send_sig
                   nxtev
		   rec_word(map)
		   newarry((word) 1, 3, (word)AINT, &param[ 2 ].xvirt, &am);
		   M[ am+3 ] = map;
		   M[ am+4 ] = w;
		   M[ am+5 ] = h;
		}
		break;

	case PUTMAP :
	case ORMAP :
	case XORMAP :
		if (member(&param[ 0 ].xvirt, &am)){
                   send_word( M[ am+3 ] )
                   send_shrt(curx)
		   send_shrt(cury)
                   send_shrt( M[ am+4 ] )
                   send_shrt( M[ am+5 ] )
		   send_sig
		}else errsignal(RTEREFTN);
		break;
		
/*
	case PATERN :
		patern((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword,
		       (int *) &param[ 2 ].xword, (int *) &param[ 3 ].xword);
		break;
		
        case INTENS :
		intens((int *) &param[ 0 ].xword);
		break;
		
        case PALETT :
		pallet((int *) &param[ 0 ].xword);
		break;
		
	case VIDEO :
		if (member(&param[ 0 ].xvirt, &am))
		    if (M[ am ] >= 0x8000L/sizeof(word))
			video(normalize((char *) &M[ am+3 ]));
		    else errsignal(RTEILLAB);
		else errsignal(RTEREFTN);
		break;

	case HPAGE :
		i = (int) param[ 1 ].xword;
		if (i == 0) graphmode = FALSE;
		else
		    if (i == 1) graphmode = TRUE;
		hpage((int *) &param[ 0 ].xword, &i,
		      (int *) &param[ 2 ].xword);
		break;

	case NOCARD :
		param[ 0 ].xword = nocard(NULL);
		break;
*/
	
	case TRACK :
                send_par(0)
                send_par(1)
                send_sig
                nxtev
                rec_shrt( curx )
                rec_shrt( cury )
		break;

	case INKEY :
             if( child_no == 0 ) param[ 0 ].xword = inkey();
             else
             {
                int keycode;
		send_sig
                nxtev
		rec_word(keycode)
		param[ 0 ].xword = keycode;
             }
             break;

/*
	case HFONT :
		hfont((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword);
		break;
				
	case HFONT8 :
		param[ 0 ].xword = 0;
		param[ 1 ].xword = 0;
		hfont8((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword);
		break;
*/

	case CIRB :
             {
                double alfa,beta,aspect,abs; word kolb,wwyp;

		send_par(0)
		send_par(1)
                param[2].xword *= 2;
		send_par(2)
                alfa = (double)(param[3].xreal);
                beta = (double)(param[4].xreal);
                kolb = param[5].xword;
                wwyp = param[6].xword;

                aspect = (double)(param[7].xword) / (double)(param[8].xword);
                aspect *= (double)(param[2].xword);

                alfa = alfa / M_PI * 180.0 * 64.0 ;
                beta = beta / M_PI * 180.0 * 64.0 ;

                abs = alfa - beta;
                if( abs < 0.0 )  abs = -abs;
                if( abs < 0.0001 )
                   beta+=360.0*64.0;

                send_shrt( (unsigned)aspect )
                send_shrt( (unsigned)alfa   )
                send_shrt( (unsigned)beta   )
		send_sig
             }
		break;

/* MOUSE */

	case INIT :
		param[ 0 ].xbool = 2;
		param[ 1 ].xbool = lbool(1);
		break;
	
	case STATUS :
		send_sig
                nxtev
		rec_par(0)
		rec_par(1)
		rec_par(2)
		rec_par(3)
		rec_par(4)
		break;
	
	case GETPRESS :
	case GETRELEASE :
                send_par(0)
		send_sig
                nxtev
		rec_par(1)
		rec_par(2)
		rec_par(3)
		rec_par(4)
		rec_par(5)
		rec_par(6)
		break;
	
	case SHOWCURSOR :
	case HIDECURSOR :
	case SETPOSITION :
	case SETWINDOW :
	case DEFCURSOR :
	case SETSPEED :
	case SETMARGINS :
	case SETTHRESHOLD :
		break;

	case GETMOVEMENT :
                send_sig
                nxtev
                rec_par(0)
                rec_par(1)
		break;

