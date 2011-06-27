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

#include "nonstand.h"

typedef int word;

#include <X11/cursorfont.h>
#include <X11/keysym.h>

/*#include <X11/Xos.h>*/
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

#include <X11/MwmUtil.h>

#include <stdio.h>
#include <math.h>
#include <ctype.h>

XSizeHints    theHints;
Display       *theDisp;
int           theDepth, theScreen, dispcells;
Colormap      theCmap;
Window        rootW, window, father;
GC            theGC;
unsigned long fcol,bcol,white,black,style=1;
Font          mfont;
XFontStruct   *mfinfo;
Visual        *theVisual;
XImage        *theImage;
XClientMessageEvent toFatherEv;
XEvent event;
Cursor theCursor;

int iWIDE,iHIGH;
int mouse_x=0,mouse_y=0,mouse_l=0,mouse_r=0,mouse_c=0,
                        mouse_l_prs=0,mouse_r_prs=0,mouse_c_prs=0,
                        mouse_l_p_x=0,mouse_r_p_x=0,mouse_c_p_x=0,
                        mouse_l_p_y=0,mouse_r_p_y=0,mouse_c_p_y=0,
                        mouse_l_rel=0,mouse_r_rel=0,mouse_c_rel=0,
                        mouse_l_r_x=0,mouse_r_r_x=0,mouse_c_r_x=0,
                        mouse_l_r_y=0,mouse_r_r_y=0,mouse_c_r_y=0;
int tracking=0;
#define END_OF_TRACK -9999

Pixmap pixmap;

#define get_shrt(w)  w=(int)(*(pars++));
#define get_word(w)  w=((int)(pars[0])&0xffff)|((int)pars[1]<<16); pars+=2;

#define put_shrt(w)  toFatherEv.data.s[cnt++] = (short)(w);
#define put_word(w)  toFatherEv.data.s[cnt++] = (short)((w) & 0xffff); \
                     toFatherEv.data.s[cnt++] = (short)(((w) >> 16) & 0xffff);
#define snd_father   toFatherEv.type=ClientMessage;	\
                     toFatherEv.format = 16;		\
                     XSendEvent(theDisp,father,False,NoEventMask,&toFatherEv); \
                     XFlush(theDisp);

#ifndef NO_PROTOTYPES
void RealiseCmd(int,short *);
#else
void RealiseCmd();
#endif


static char *application_name="IIUWGRAPH";


#define QSIZE 256
static KeySym keycodes[QSIZE];
static int keyhead=0,keytail=0;

main(argc, argv)
    int   argc;
    char *argv[];
{
   int w=0;
   int i;
   int events=0;

   father = atoi(argv[1]);

   for( i=2; i<argc; i++ )  argv[i-1]=argv[i];
   argc--;

   if ((theDisp = XOpenDisplay(NULL)) == NULL){
      fprintf (stderr,"\n%s:  Can't open display\n", argv[0]);
      exit(1);
   }

   theScreen = DefaultScreen(theDisp);
   theDepth  = DefaultDepth(theDisp, theScreen);
   rootW     = RootWindow(theDisp,theScreen);
   fcol=white= WhitePixel(theDisp,theScreen);
   bcol=black= BlackPixel(theDisp,theScreen);
   theVisual = DefaultVisual(theDisp,theScreen);
   theCmap   = XCreateColormap(theDisp,rootW,theVisual,AllocNone);
   dispcells = DisplayCells(theDisp, theScreen);
   theCursor = XCreateFontCursor(theDisp,XC_arrow);

   iWIDE = 720;  iHIGH = 348;

   if ((mfinfo = XLoadQueryFont(theDisp,"fixed"))==NULL){
      fprintf (stderr,"\n%s:  Can't open 'fixed' font\n", argv[0]);
      exit(1);
   }
   mfont=mfinfo->fid;

   theHints.width =iWIDE;
   theHints.height=iHIGH;
   theHints.flags=PSize;
   window = XCreateSimpleWindow(theDisp,rootW,10,10,iWIDE,iHIGH,3,fcol,bcol);

   XSetStandardProperties(theDisp,window,"HERCULES","HERCULES",
                          None,argv,argc,theHints);
   XDefineCursor(theDisp,window,theCursor);

   XChangeProperty(theDisp,window,XA_WM_CLASS,XA_STRING,8,PropModeReplace,
                   application_name,strlen(application_name));

   {
      struct {
         long	flags;
         long	functions;
         long	decorations;
         int	input_mode;
      } hints;
      Atom a=XInternAtom(theDisp,_XA_MWM_HINTS,False);
      hints.flags       =   MWM_HINTS_FUNCTIONS;
      hints.functions   =   MWM_FUNC_CLOSE | MWM_FUNC_MOVE;
      hints.decorations =   0;
      hints.input_mode  =   0;
      XChangeProperty(theDisp,window,a,a,32,PropModeReplace,&hints,4);
   }

   theGC = XCreateGC(theDisp,window,0,0);
   XSetFont(theDisp,theGC,mfont);
   XSetForeground(theDisp,theGC,fcol);
   XSetBackground(theDisp,theGC,bcol);

   XSelectInput(theDisp,window,
                ExposureMask |
                KeyPressMask |
                PointerMotionMask |
                ButtonPressMask |
                ButtonReleaseMask
               );
   XMapRaised(theDisp,window);

   pixmap = XCreatePixmap(theDisp,window,iWIDE,iHIGH,theDepth);

   for(;;){

      XNextEvent(theDisp,&event);

      switch (event.type){

         case Expose:
            {
               int x=event.xexpose.x;
               int y=event.xexpose.y;
               int w=event.xexpose.width;
               int h=event.xexpose.height;
               int cnt=0;
               XCopyArea(theDisp,pixmap,window,theGC,x,y,w,h,x,y);
               if( events==0 ){
                  put_word(window);
                  snd_father
               }
               events=1;
            }
            break;

         case ClientMessage:
            RealiseCmd( (int)(event.xclient.message_type),event.xclient.data.s);
            break;

         case MappingNotify:
            if( event.xmapping.request == MappingModifier  ||
                event.xmapping.request == MappingKeyboard )
            XRefreshKeyboardMapping(&event);
            break;

         case KeyPress:
            {
               KeySym key;
               char ch;
               int i=XLookupString( &(event.xkey), &ch, 1, &key, NULL );

               if( i>0 )
                  if( ch == '\177' )   keycodes[ keytail++ ] = -83;
                  else                 keycodes[ keytail++ ] = (int)ch;
               else
               if( key == NoSymbol )  break;
               else
               if( IsModifierKey( key ) )  break;
               else
               {
                  int to_return = 0;
                  switch( key ){
                     case XK_F1    : to_return = -59; break;
                     case XK_F2    : to_return = -60; break;
                     case XK_F3    : to_return = -61; break;
                     case XK_F4    : to_return = -62; break;
                     case XK_F5    : to_return = -63; break;
                     case XK_F6    : to_return = -64; break;
                     case XK_F7    : to_return = -65; break;
                     case XK_F8    : to_return = -66; break;
                     case XK_F9    : to_return = -67; break;
                     case XK_F10   : to_return = -68; break;
                     case XK_Home  : to_return = -71; break;
                     case XK_Left  : to_return = -75; break;
                     case XK_Up    : to_return = -72; break;
                     case XK_Right : to_return = -77; break;
                     case XK_Down  : to_return = -80; break;
                     case XK_End   : to_return = -79; break;
                     case XK_Insert: to_return = -82; break;
                     case XK_Break : to_return =  -3; break;
                     case XK_Prior : to_return = -73; break;
                     case XK_Next  : to_return = -81; break;
                  }
                  if( to_return!=0 )   keycodes[ keytail++ ] = to_return;
                  else break;
               }

               if( keytail == QSIZE ) keytail = 0;
               if( keytail == keyhead ){
                  keytail -- ;
                  if( keytail < 0 )  keytail = QSIZE ;
               }
            }
            break;

         case MotionNotify:
         case ButtonPress:
         case ButtonRelease:
            mouse_x = event.xmotion.x;
            mouse_y = event.xmotion.y;
            if( event.type == ButtonPress ){
               switch( event.xbutton.button ){
                  case Button1 : mouse_l=1; mouse_l_prs++;
                                 mouse_l_p_x = mouse_x;
                                 mouse_l_p_y = mouse_y;
                                 if( tracking ){
                                    tracking = 0;
                                    RealiseCmd( END_OF_TRACK, NULL );
                                 }
                                 break;
                  case Button2 : mouse_c=1; mouse_c_prs++;
                                 mouse_c_p_x = mouse_x;
                                 mouse_c_p_y = mouse_y;
                                 break;
                  case Button3 : mouse_r=1; mouse_r_prs++;
                                 mouse_r_p_x = mouse_x;
                                 mouse_r_p_y = mouse_y;
                                 break;
               }
            }
            if( event.type == ButtonRelease ){
               switch( event.xbutton.button ){
                  case Button1 : mouse_l=0; mouse_l_rel++;
                                 mouse_l_r_x = mouse_x;
                                 mouse_l_r_y = mouse_y;
                                 break;
                  case Button2 : mouse_c=0; mouse_c_rel++;
                                 mouse_c_r_x = mouse_x;
                                 mouse_c_r_y = mouse_y;
                                 break;
                  case Button3 : mouse_r=0; mouse_r_rel++;
                                 mouse_r_r_x = mouse_x;
                                 mouse_r_r_y = mouse_y;
                                 break;
               }
            }
            break;

      } /* end of switch */

   } /* end of for */

}



word cmd=0,w,h,x,y,curx,cury,kolb,wwyp,p,q,r,color;
word alfa,beta,aspect;
char c;
XImage *image;
XImage *XGetImage();



void RealiseCmd( cmd, pars ) int cmd; short *pars; {

   int i=1;
   int cnt=0;

   switch( cmd ){

      case CLS :
         XSetForeground(theDisp,theGC,bcol);
         XFillRectangle(theDisp,pixmap,theGC,0,0,iWIDE,iHIGH);
         XFillRectangle(theDisp,window,theGC,0,0,iWIDE,iHIGH);
         XSetForeground(theDisp,theGC,fcol);
         break;

      case GROFF :
         XFreePixmap(theDisp,pixmap);
         XDestroyWindow(theDisp,window);
         XCloseDisplay(theDisp);
         exit(0);
         break;

      case INKEY :
         {
            int keycode=0;
            if( keyhead != keytail ){
               keycode  = keycodes[ keyhead++ ];
               if( keyhead == QSIZE )  keyhead = 0;
            }
            put_word(keycode)
            snd_father
         }
         break;

      case POINT :
         get_shrt( x );
         get_shrt( y );
         XDrawPoint(theDisp,pixmap,theGC,x,y);
         XDrawPoint(theDisp,window,theGC,x,y);
         break;

      case DRAW :
         get_shrt( curx );
         get_shrt( cury );
         get_shrt( x );
         get_shrt( y );
         XDrawLine(theDisp,pixmap,theGC,curx,cury,x,y);
         XDrawLine(theDisp,window,theGC,curx,cury,x,y);
         break;

      case CIRB :
         get_shrt( x );
         get_shrt( y );
         get_shrt( r );
         get_shrt( aspect );
         get_shrt( alfa );
         get_shrt( beta );
         XDrawArc(theDisp,pixmap,theGC,x,y,r,aspect,alfa,beta);
         XDrawArc(theDisp,window,theGC,x,y,r,aspect,alfa,beta);
         break;

      case HFILL :
         get_shrt( curx );
         get_shrt( cury );
         get_shrt( x );
         XDrawLine(theDisp,pixmap,theGC,curx,cury,x,cury);
         XDrawLine(theDisp,window,theGC,curx,cury,x,cury);
         break;

      case VFILL :
         get_shrt( curx );
         get_shrt( cury );
         get_shrt( y );
         XDrawLine(theDisp,pixmap,theGC,curx,cury,curx,y);
         XDrawLine(theDisp,window,theGC,curx,cury,curx,y);
         break;

      case INPIX :
         get_shrt( x );
         get_shrt( y );
         image=XGetImage(theDisp,pixmap,x,y,1,1,0x7fffffffL,ZPixmap);
         color = XGetPixel(image,0,0);
         XDestroyImage(image);
         put_word(color)
         snd_father
         break;

      case GETMAP :
         {
            Pixmap map;
            get_shrt( x );
            get_shrt( y );
            get_shrt( w );
            get_shrt( h );
            if( w>iWIDE ) w=iWIDE;
            if( h>iHIGH ) h=iHIGH;
            map = XCreatePixmap(theDisp,window,w,h,theDepth);
            XCopyArea(theDisp,pixmap,map,theGC,x,y,w,h,0,0);
            put_word(map)
            snd_father
         }
         break;

      case PUTMAP :
      case XORMAP :
      case  ORMAP :
         {
            Pixmap map;
            switch( cmd ){
               case XORMAP: XSetFunction(theDisp,theGC,GXxor); break;
               case  ORMAP: XSetFunction(theDisp,theGC,GXor ); break;
            }
            get_word( map );
            get_shrt( curx );
            get_shrt( cury );
            get_shrt( w );
            get_shrt( h );
            if( w>iWIDE ) w=iWIDE;
            if( h>iHIGH ) h=iHIGH;
            XCopyArea(theDisp,map,pixmap,theGC,0,0,w,h,curx,cury);
            XCopyArea(theDisp,map,window,theGC,0,0,w,h,curx,cury);
            if( cmd != PUTMAP )  XSetFunction(theDisp,theGC,GXcopy);
         }
         break;

      case COLOR :
         get_shrt( color );
         if( color == 0 )  fcol = black ;
         else              fcol = white ;
         XSetForeground(theDisp,theGC,fcol);
         break;

      case BORDER :
         get_shrt( color );
         if( color == 0 )  bcol = black ;
         else              bcol = white ;
         XSetBackground(theDisp,theGC,bcol);
         break;

      case STYLE :
      {
         static char style_2[]={ 6, 3 };
         static char style_3[]={ 4, 6 };
         static char style_4[]={ 2, 3 };
         static char style_5[]={ 2, 9 };

         get_shrt( style );
         switch( style ){
            case 0:
               XSetForeground(theDisp,theGC,bcol);
               XSetLineAttributes(theDisp,theGC,0,LineSolid,CapButt,JoinMiter);
               break;
            case 1:
               XSetForeground(theDisp,theGC,fcol);
               XSetLineAttributes(theDisp,theGC,0,LineSolid,CapButt,JoinMiter);
               break;
            case 2:
               XSetLineAttributes(theDisp,theGC,0,LineDoubleDash,
                                  CapButt,JoinMiter);
               XSetDashes(theDisp,theGC,0,style_2,2);
               break;
            case 3:
               XSetLineAttributes(theDisp,theGC,0,LineDoubleDash,
                                  CapButt,JoinMiter);
               XSetDashes(theDisp,theGC,0,style_3,2);
               break;
            case 4:
               XSetLineAttributes(theDisp,theGC,0,LineDoubleDash,
                                  CapButt,JoinMiter);
               XSetDashes(theDisp,theGC,0,style_4,2);
               break;
            case 5:
               XSetLineAttributes(theDisp,theGC,0,LineDoubleDash,
                                  CapButt,JoinMiter);
               XSetDashes(theDisp,theGC,0,style_5,2);
               break;
            }
         }
         break;

      case HASCII :
         get_shrt( curx );
         get_shrt( cury );
         get_shrt( r );
         if( r==0 ){
            XSetForeground(theDisp,theGC,bcol);
            XFillRectangle(theDisp,pixmap,theGC,curx,cury,8,8);
            XFillRectangle(theDisp,window,theGC,curx,cury,8,8);
            XSetForeground(theDisp,theGC,fcol);
         }else{
            c = (char)r;
            XDrawString(theDisp,pixmap,theGC,curx,cury+8,&c,1);
            XDrawString(theDisp,window,theGC,curx,cury+8,&c,1);
         }
         break;

      case STATUS :
         put_shrt(mouse_x)
         put_shrt(mouse_y)
         put_shrt(mouse_l)
         put_shrt(mouse_r)
         put_shrt(mouse_c)
         snd_father
         break;

      case GETPRESS :
      case GETRELEASE :
         {
            int button;
            get_shrt(button);
            if( cmd == GETPRESS )
               switch( button ){

                  case 0:
                          put_shrt( mouse_l_p_x );
                          put_shrt( mouse_l_p_y );
                          put_shrt( mouse_l_prs );
                          mouse_l_prs=0;
                          break;

                  case 1:
                          put_shrt( mouse_r_p_x );
                          put_shrt( mouse_r_p_y );
                          put_shrt( mouse_r_prs );
                          mouse_r_prs=0;
                          break;

                  case 2:
                          put_shrt( mouse_c_p_x );
                          put_shrt( mouse_c_p_y );
                          put_shrt( mouse_c_prs );
                          mouse_c_prs=0;
                          break;

                  default:put_shrt( 0 );
                          put_shrt( 0 );
                          put_shrt( 0 );
                          break;

               }
            else
               switch( button ){

                  case 0:
                          put_shrt( mouse_l_r_x );
                          put_shrt( mouse_l_r_y );
                          put_shrt( mouse_l_rel );
                          mouse_l_rel=0;
                          break;

                  case 1:
                          put_shrt( mouse_r_r_x );
                          put_shrt( mouse_r_r_y );
                          put_shrt( mouse_r_rel );
                          mouse_r_rel=0;
                          break;

                  case 2:
                          put_shrt( mouse_c_r_x );
                          put_shrt( mouse_c_r_y );
                          put_shrt( mouse_c_rel );
                          mouse_c_rel=0;
                          break;

                  default:put_shrt( 0 );
                          put_shrt( 0 );
                          put_shrt( 0 );
                          break;

               }
            put_shrt(mouse_l)
            put_shrt(mouse_r)
            put_shrt(mouse_c)
            snd_father
         }
         break;

      case GETMOVEMENT :
         {
            static int x=0,y=0;
            put_shrt(mouse_x-x)
            put_shrt(mouse_y-y)
            snd_father
            x = mouse_x;
            y = mouse_y;
         }
         break;

      case TRACK:
         {
            int x,y;
            get_shrt( x )   /* these parameters are not used */
            get_shrt( y )
            tracking = 1;
            /* now we wait to point and press left button */
         }
         break;

      case END_OF_TRACK:
         put_shrt( mouse_x )
         put_shrt( mouse_y )
         snd_father
         break;

      default :
         fprintf(stderr,"UKNOWN COMMAND for HERCULES emulation - %d\n",cmd);
         fflush(stderr);
         XFreePixmap(theDisp,pixmap);
         XDestroyWindow(theDisp,window);
         XCloseDisplay(theDisp);
         exit(7);

   }

}

