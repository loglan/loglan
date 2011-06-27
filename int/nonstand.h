/* Standard class IIUWGRAPH graphics primitives

GRON:procedure(mode:integer) 
GROFF:procedure 
CLS:procedure 
POINT:procedure(x, y:integer) 
MOVE:procedure(x, y:integer) 
DRAW:procedure(x, y:integer) 
HFILL:procedure(x:integer) 
VFILL:procedure(y:integer) 
COLOR:procedure(color:integer) 
STYLE:procedure(style:integer) 
PATERN:procedure(p1, p2, p3, p4:integer) 
INTENS:procedure(intens:integer) 
PALLET:procedure(p:integer) 
BORDER:procedure(b:integer) 
VIDEO:procedure(buffer:arrayof integer) 
HPAGE:procedure(p, q, r:integer) 
NOCARD:function:integer 
PUSHXY:procedure 
POPXY:procedure 
INXPOS:function:integer 
INYPOS:function:integer 
INPIX:function(x, y:integer):integer 
GETMAP:function(x, y:integer):arrayof integer 
PUTMAP:procedure(arrayof integer) 
ORMAP:procedure(arrayof integer) 
XORMAP:procedure(arrayof integer) 
TRACK:procedure(x, y:integer) 
INKEY:function:integer 
HASCII:procedure(ch:integer) 
HFONT:procedure(off, seg:integer) 
HFONT8:procedure(output off, seg:integer) 
OUTSTRING:procedure(s:string) 
CIRB:procedure(x, y, r:integer, alpha, beta:real, b, i, p, q:integer)

*/

#define GRON		100
#define GROFF		101
#define CLS		102
#define POINT		103
#define MOVE		104
#define DRAW		105
#define HFILL		106
#define VFILL		107
#define COLOR		108
#define STYLE		109
#define PATERN		110
#define INTENS		111
#define PALETT		112
#define BORDER		113
#define VIDEO		114
#define HPAGE		115
#define NOCARD		116
#define PUSHXY		117
#define POPHXY		118
#define INXPOS		119
#define INYPOS		120
#define INPIX		121
#define GETMAP		122
#define PUTMAP		123
#define ORMAP		124
#define XORMAP		125
#define TRACK		126
#define INKEY		127
#define HASCII		128
#define HFONT		129
#define HFONT8		130
#define OUTSTRING	131
#define CIRB		132


/* Standard class MOUSE mouse support

INIT:function(output butttons:integer):boolean 
SHOWCURSOR:procedure 
HIDECURSOR:procedure 
STATUS:procedure(output x,y:integer, l,r,c:boolean) 
SETPOSITION:procedure(x, y:integer) 
GETPRESS:procedure(b:integer; output x,y,p:integer, l, r, c:boolean)
GETRELEASE:procedure(b:integer; output x,y,p:integer, l, r, c:boolean)
SETWINDOW:procedure(l, r, t, b:integer) 
DEFCURSOR:procedure(select, p, q:integer) 
GETMOVEMENT:procedure(output x, y:integer) 
SETSPEED:procedure(x, y:integer) 
SETMARGINS:procedure(l, r, t, b:integer) 
SETTHRESHOLD:procedure(t:integer) 

*/


#define INIT		200
#define SHOWCURSOR	201
#define HIDECURSOR	202
#define STATUS		203
#define SETPOSITION	204
#define GETPRESS	205
#define GETRELEASE	206
#define SETWINDOW	207
#define DEFCURSOR	210
#define GETMOVEMENT	211
#define SETSPEED	215
#define SETMARGINS	216
#define SETTHRESHOLD	219
