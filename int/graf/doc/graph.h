(* --------------------------------------------------------- *)
(*       HERCULES GRAPHICS FOR MICROSOFT PASCAL              *)
(*                                                           *)
(*            External subprograms header                    *)
(*$list-,$symtab-                                            *)
type ads_of_byte = ads of byte;

procedure GRON(consts imode: integer); external;
procedure GROFF; external;
procedure CLS; external;
procedure POINT(consts ix,iy: integer); external;
procedure MOVE(consts ix,iy: integer); external;
procedure DRAW(consts ix,iy: integer); external;
procedure HFILL(consts maxx: integer); external;
procedure VFILL(consts maxy: integer); external;
procedure COLOR(consts c: integer); external;
procedure STYLE(consts s: integer); external;
procedure PATERN(consts p1, p2, p3, p4: integer); external;
procedure INTENS(consts i: integer); external;
procedure PALLET(consts p: integer); external;
procedure BORDER(consts b: integer); external;
procedure VIDEO(ads_of_buffer: ads_of_byte); external;
procedure HPAGE(consts page, mode, clear: integer); external;
function  NOCARD(consts idummy: integer): integer; external;
procedure PUSHXY; external;
procedure POPXY; external;
function  INXPOS(consts idummy: integer): integer; external;
function  INYPOS(consts idummy: integer): integer; external;
function  INPIX(consts x,y: integer): integer; external;
procedure GETMAP(consts x,y: integer; ads_of_array: ads_of_byte); external;
procedure PUTMAP(ads_of_array: ads_of_byte); external;
procedure ORMAP(ads_of_array: ads_of_byte); external;
procedure XORMAP(ads_of_array: ads_of_byte); external;
procedure TRACK(consts x,y: integer); external;
function  INKEY(consts idummy: integer): integer; external;
procedure HASCII(consts ic: integer); external;
procedure HFONT(consts seg, offs: integer); external;
procedure HFONT8(vars seg, offs: integer); external;
procedure OUTHLI(consts n:integer; ads_of_buffer: ads_of_byte); external;
procedure INHLIN(vars n:integer;ads_of_buffer: ads_of_byte); external;
procedure MKWNDW(consts x,y,icols,ilines: integer; ads_of_window: ads_of_byte;
                 consts iwndwsize,iborder: integer); external;
procedure BURY(ads_of_window: ads_of_byte); external;
procedure EXPOSE(ads_of_window: ads_of_byte; consts x,y: integer); external;
procedure OUTWLI(ads_of_window: ads_of_byte; consts n: integer;
                   ads_of_buffer: ads_of_byte); external;
procedure INWLIN(ads_of_window: ads_of_byte; vars n: integer;
                  ads_of_buffer: ads_of_byte); external;
procedure SWINDO(rw, iw: ads_of_byte; consts scale: integer); external;
procedure RWINDO(rw: ads_of_byte; consts scale: integer); external;
procedure RMOVE(consts rx,ry: real); external;
procedure RDRAW(consts rx,ry: real); external;
procedure CIRB(consts ix,iy,ir: integer; consts alfa, beta: real;
               consts cbord, bcint: integer;
               consts p, q: integer); external;
procedure RCIRB(consts ix,iy,ir: real; consts alfa, beta: real;
               consts cbord, bcint: integer;
               consts p, q: integer); external;
(*$list+                                                     *)
(* --------------------------------------------------------- *)

