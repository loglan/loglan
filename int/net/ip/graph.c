#include <stdio.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <math.h>

#include "graph.h"


static int child_no=0;
static int fcol=1,bcol=0;

static Display *theDisplay;
static Window myWindow,theWindow;
static XClientMessageEvent theMessage;
static XEvent retEv;

static void send_sig(nrproc) int nrproc; {
   theMessage.type=ClientMessage;
   theMessage.format = 16;
   theMessage.message_type = nrproc;
   XSendEvent(theDisplay,theWindow,True,NoEventMask,&theMessage);
   XFlush(theDisplay);
}

static void nxtev(){
   do XNextEvent( theDisplay, &retEv );
   while( retEv.type!=ClientMessage );
}




void graph_on(x,y,title) int x,y; char *title; {

   if ((theDisplay = XOpenDisplay(NULL)) == NULL){
      fprintf (stderr,"\ngraph:  Can't open display\n");
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
      char xs[16];
      char ys[16];
      sprintf(me,"%d",(int)myWindow);
      sprintf(xs,"%d",x);
      sprintf(ys,"%d",y);
      execlp("./graph","graph",me,xs,ys,title,NULL);
   }

   nxtev();
   theWindow = (int)(retEv.xclient.data.l[0]);
}
		

void graph_off(){
   send_sig(GRAPH_CMD_END);
   child_no=0;
}


void graph_point( x,c ) int x,c; {
   theMessage.data.l[0]=x;
   theMessage.data.l[1]=c;
   send_sig(GRAPH_CMD_POINT);
}

void graph_board( size ) int size; {
   theMessage.data.l[0]=size;
   send_sig(GRAPH_CMD_LINE);
}

