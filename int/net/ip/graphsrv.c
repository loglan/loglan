#include "graph.h"

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include <X11/cursorfont.h>

#ifndef NO_MWM
#include <X11/Xos.h>
#endif

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

#ifndef NO_MWM
#include <X11/MwmUtil.h>
#endif

XSizeHints    theHints;
Display       *theDisp;
int           theDepth, theScreen, dispcells;
Colormap      theCmap;
Window        rootW, window, father;
GC            theGC;
unsigned long fcol,bcol,white,black,grey,yellow,red,style=1;
XColor        exact_color,closest_color;
Font          mfont;
XFontStruct   *mfinfo;
Visual        *theVisual;
XImage        *theImage;
XClientMessageEvent toFatherEv;
XEvent event;
Cursor theCursor;

int iWIDE,iHIGH,xWIDE;
static int MARGIN=3;

Pixmap pixmap;

static void snd_father(){
   toFatherEv.type=ClientMessage;
   toFatherEv.format = 16;
   XSendEvent(theDisp,father,False,NoEventMask,&toFatherEv);
/*   XFlush(theDisp);*/
}

#ifndef NO_PROTOTYPES
void RealiseCmd(int,long *);
#else
void RealiseCmd();
#endif


static char *title;


main(argc, argv)
    int   argc;
    char *argv[];
{
   int w=0;
   int i;
   int events=0;

   father = atoi(argv[1]);

   iWIDE = atoi(argv[2])+2*MARGIN;
   iHIGH = atoi(argv[3])+2*MARGIN;
   xWIDE = atoi(argv[2]);
   title = argv[4];

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
   theCmap   = DefaultColormap(theDisp,theScreen);
   dispcells = DisplayCells(theDisp, theScreen);
   theCursor = XCreateFontCursor(theDisp,XC_watch);

   if(!XAllocNamedColor(theDisp,theCmap,"grey",&exact_color,&closest_color)) 
      grey = black;
   else
      grey = closest_color.pixel;

   if(!XAllocNamedColor(theDisp,theCmap,"yellow",&exact_color,&closest_color)) 
      yellow = white;
   else
      yellow = closest_color.pixel;

   if(!XAllocNamedColor(theDisp,theCmap,"red",&exact_color,&closest_color)) 
      red = black;
   else
      red = closest_color.pixel;

   if ((mfinfo = XLoadQueryFont(theDisp,"fixed"))==NULL){
      fprintf (stderr,"\n%s:  Can't open 'fixed' font\n", argv[0]);
      exit(1);
   }
   mfont=mfinfo->fid;

   theHints.width =iWIDE;
   theHints.height=iHIGH;
   theHints.flags=PSize;
   window = XCreateSimpleWindow(theDisp,rootW,10,10,iWIDE,iHIGH,3,fcol,bcol);

   XSetStandardProperties(theDisp,window,title,title,None,argv,argc,&theHints);
   XDefineCursor(theDisp,window,theCursor);

   XChangeProperty(theDisp,window,XA_WM_CLASS,XA_STRING,8,PropModeReplace,
                   title,strlen(title));

#ifndef NO_MWM
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
#endif

   theGC = XCreateGC(theDisp,window,0,0);
   XSetFont(theDisp,theGC,mfont);
   XSetForeground(theDisp,theGC,fcol);
   XSetBackground(theDisp,theGC,bcol);

   XSelectInput(theDisp,window, ExposureMask | KeyPressMask);
   XMapRaised(theDisp,window);

   pixmap = XCreatePixmap(theDisp,window,iWIDE,iHIGH,theDepth);

   XSetForeground(theDisp,theGC,bcol);
   XFillRectangle(theDisp,pixmap,theGC,0,0,iWIDE,iHIGH);
   XFillRectangle(theDisp,window,theGC,0,0,iWIDE,iHIGH);
   XSetForeground(theDisp,theGC,fcol);

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
                  toFatherEv.data.l[0] = window;
                  snd_father();
               }
               events=1;
            }
            break;

         case ClientMessage:
            RealiseCmd( (int)(event.xclient.message_type),event.xclient.data.l);
            break;

         case MappingNotify:
            if( event.xmapping.request == MappingModifier  ||
                event.xmapping.request == MappingKeyboard )
            XRefreshKeyboardMapping(&event);
            break;

      } /* end of switch */

   } /* end of for */

}



static int cmd=0,w,h,x,y,curx,cury,kolb,wwyp,p,q,r,color;
static char c;
static XImage *image;
XImage *XGetImage();



void RealiseCmd( cmd, pars ) int cmd; long *pars; {

   int size;

   switch( cmd ){

      case GRAPH_CMD_END:
         XFreePixmap(theDisp,pixmap);
         XDestroyWindow(theDisp,window);
         XCloseDisplay(theDisp);
         exit(0);
         break;


      case GRAPH_CMD_POINT:

         x     = pars[ 0 ];
         color = pars[ 1 ];

         if( color == GRAPH_COL_BACK	)  fcol = black ;
         else
         if( color == GRAPH_COL_OK	)  fcol = yellow ;
         else
         if( color == GRAPH_COL_BOARD	)  fcol = grey  ;
         else
         if( color == GRAPH_COL_ERROR	)  fcol = red   ;

         XSetForeground(theDisp,theGC,fcol);
         XDrawPoint(theDisp,pixmap,theGC,MARGIN+x%xWIDE,MARGIN+x/xWIDE);
         XDrawPoint(theDisp,window,theGC,MARGIN+x%xWIDE,MARGIN+x/xWIDE);
         break;


      case GRAPH_CMD_LINE:

        size = pars[ 0 ];
        XSetForeground(theDisp,theGC,grey);
        XFillRectangle(theDisp,pixmap,theGC,MARGIN,MARGIN,xWIDE,size/xWIDE);
        XFillRectangle(theDisp,window,theGC,MARGIN,MARGIN,xWIDE,size/xWIDE);
        if( size%xWIDE > 0 ){
           XDrawLine(theDisp,pixmap,theGC,
                     MARGIN,			MARGIN+size/xWIDE,
                     MARGIN+size%xWIDE-1,	MARGIN+size/xWIDE
                    );
           XDrawLine(theDisp,window,theGC,
                     MARGIN,			MARGIN+size/xWIDE,
                     MARGIN+size%xWIDE-1,	MARGIN+size/xWIDE
                    );
        }
        break;


      default :
         fprintf(stderr,"UKNOWN COMMAND - %d\n",cmd);
         fflush(stderr);
         XFreePixmap(theDisp,pixmap);
         XDestroyWindow(theDisp,window);
         XCloseDisplay(theDisp);
         exit(7);

   }
}

