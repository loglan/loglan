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

        case GRON :
		gron((int *) &param[ 0 ].xword);
		graphmode = TRUE;
		break;
		
	case GROFF :
		groff();
		graphmode = FALSE;
		break;
	
	case CLS :
		cls();
		break;
	
	case POINT :
		point((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword);
		break;
		
	case MOVE :
		move((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword);
		break;
		
	case DRAW :
		draw((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword);
		break;
		
        case HFILL :
		hfill((int *) &param[ 0 ].xword);
		break;
		
        case VFILL :
		vfill((int *) &param[ 0 ].xword);
		break;
		
        case COLOR :
		color((int *) &param[ 0 ].xword);
		break;
		
        case STYLE :
		style((int *) &param[ 0 ].xword);
		break;
		
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
		
        case BORDER :
		border((int *) &param[ 0 ].xword);
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
	
	case PUSHXY :
		pushxy();
		break;
		
	case POPHXY :
		popxy();
		break;
		
	case INXPOS :
		param[ 0 ].xword = inxpos(NULL);
		break;
	
	case INYPOS :
		param[ 0 ].xword = inypos(NULL);
		break;

	case INPIX :
		param[ 2 ].xword = inpix((int *) &param[ 0 ].xword,
					 (int *) &param[ 1 ].xword);
		break;
	
	case GETMAP :
		t1 = abs(param[ 0 ].xword-inxpos(NULL))+1;  /* cols */
		t2 = abs(param[ 1 ].xword-inypos(NULL))+1;  /* rows */
		t1 = (4+t1*t2+sizeof(word)-1)/sizeof(word); /* no. of words, pixel=byte */
		newarry((word) 1, t1, (word)AINT, &param[ 2 ].xvirt, &am);
		getmap((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword,
		       normalize((char *) &M[ am+3 ]));
		break;
	
	case PUTMAP :
		if (member(&param[ 0 ].xvirt, &am))
		    putmap(normalize((char *) &M[ am+3 ]));
		else errsignal(RTEREFTN);
		break;
		
	case ORMAP :
		if (member(&param[ 0 ].xvirt, &am))
		    ormap(normalize((char *) &M[ am+3 ]));
		else errsignal(RTEREFTN);
		break;
		
	case XORMAP :
		if (member(&param[ 0 ].xvirt, &am))
		    xormap(normalize((char *) &M[ am+3 ]));
		else errsignal(RTEREFTN);
		break;
	
	case TRACK :
		track((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword);
		break;

	case INKEY :
		param[ 0 ].xword = inkey(NULL);
		break;

	case HASCII :
		hascii((int *) &param[ 0 ].xword);
		break;

	case HFONT :
		hfont((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword);
		break;
				
	case HFONT8 :
		param[ 0 ].xword = 0;
		param[ 1 ].xword = 0;
		hfont8((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword);
		break;
	
	case OUTSTRING :
		t1 = strings+param[ 0 ].xword;
		outhli((int *) &M[ t1 ], (char *) &M[ t1+1 ]);
		break;

	case CIRB :
	        r1 = param[ 3 ].xreal;
		r2 = param[ 4 ].xreal;
		cirb((int *) &param[ 0 ].xword, (int *) &param[ 1 ].xword,
		     (int *) &param[ 2 ].xword, &r1, &r2,
		     (int *) &param[ 5 ].xword, (int *) &param[ 6 ].xword,
		     (int *) &param[ 7 ].xword, (int *) &param[ 8 ].xword);
		break;

/* MOUSE */

	case INIT :
		ax = mouse(0, &param[ 0 ].xword, &cx, &dx);
		param[ 1 ].xbool = lbool(ax);
		break;
	
	case SHOWCURSOR :
		mouse(1, &bx, &cx, &dx);
		break;
	
	case HIDECURSOR :
		mouse(2, &bx, &cx, &dx);
		break;
	
	case STATUS :
		mouse(3, &bx, &param[ 0 ].xword, &param[ 1 ].xword);
		param[ 2 ].xbool = lbool(bx & 0x01);
		param[ 3 ].xbool = lbool(bx & 0x02);
		param[ 4 ].xbool = lbool(bx & 0x04);
		break;
	
	case SETPOSITION :
		mouse(4, &bx, &param[ 0 ].xword, &param[ 1 ].xword);
		break;
	
	case GETPRESS :
	case GETRELEASE :
		i = ( nrproc == GETPRESS ? 5 : 6 );
		bx = param[ 0 ].xword;
		ax = mouse(i, &bx, &param[ 1 ].xword, &param[ 2 ].xword);
		param[ 4 ].xbool = lbool(ax & 0x01);
		param[ 5 ].xbool = lbool(ax & 0x02);
		param[ 6 ].xbool = lbool(ax & 0x04);
		param[ 3 ].xword = bx;
		break;
	
	case SETWINDOW :
		mouse(7, &bx, &param[ 0 ].xword, &param[ 1 ].xword);
		mouse(8, &bx, &param[ 2 ].xword, &param[ 3 ].xword);
		break;
	
	case DEFCURSOR :
		mouse(10, &param[ 0 ].xword, &param[ 1 ].xword,
		          &param[ 2 ].xword);
		break;

	case GETMOVEMENT :
		mouse(11, &bx, &param[ 0 ].xword, &param[ 1 ].xword);
		break;

	case SETSPEED :
		mouse(15, &bx, &param[ 0 ].xword, &param[ 1 ].xword);
		break;

	case SETMARGINS :
		r.x.ax = 16;
		r.x.cx = param[ 0 ].xword;
		r.x.dx = param[ 2 ].xword;
		r.x.si = param[ 1 ].xword;
		r.x.di = param[ 3 ].xword;
		int86(0x33, &r, &r);
		break;
		
	case SETTHRESHOLD :
		mouse(19, &bx, &cx, &param[ 0 ].xword);
		break;


