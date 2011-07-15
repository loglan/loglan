SHELL=/bin/sh
#.SUFFIXES: .o .c

#############################################################################
# switches :
# OBJECTADDR - switch on special process addressing - object simulates
#              process pointer
# CDBG - turn on debugging of compactifier, compactifier appends to file
#        'trace' state of memory before & after the compactification,
#        also a history of compactification & process number is dumped
# RPCDBG - debugging of alien call, all actions : alien call, acknowledges,
#          passivations and returns are written to stderr
# NO_GRAPH -    nonstand.c defines only INKEY grom IIUWGRAPH
# DLINK    -    DLINK network version
# TCPIP    -    TCPIP network version - needs also OBJECTADDR
#
# switches depending on environment :
# TURBOC - if using BORLAND TURBO-C compiler
# MSDOS/OS2/UNIX - choose operating system
# USE_CLOCK - scheduler should use clock() function to measure time
# USE_ALARM - scheduler should use alarm() function to measure time
# WORD_16BIT/DWORD_16BIT/WORD_32BIT - choose memory model :
#        small 16-bit / large 16-bit / small 32-bit
#
# for DLINK use cinta.o ( cinta.asm )
# for TCPIP use tcpip.o sock.o
# for no network simply leave empty
# NETFILE=tcpip.o sock.o

#NETFILE=tcpip.o sock.o
NETFILE=

#CC=gcc -m486 -DDJE -DUSE_CLOCK -DWORD_32BIT -Dpascal=   
# MSDOS 32bit GNU CC

#CC=cl -AL -Olsg -DMSDOS -DDWORD_16BIT                  # MSDOS 16bit LARGE
#CC=cl -AL -Olsg -DMSDOS -DWORD_16BIT                   # MSDOS 16bit SMALL

UNIXPARS=-DUNIX -DWORD_32BIT -DUSE_ALARM -Dpascal=
UNIXPARSNG=$(UNIXPARS) 

#CC=cc $(UNIXPARSNG) -DNO_PROTOTYPES            # SUN,HP
#CC=rcc $(UNIXPARSNG) -O                        # SCO - AT&T C compiler
#CC=cc -W1 $(UNIXPARSNG)                        # SCO
#CC=cc -W1 $(UNIXPARSNG) -DOBJECTADDR           # SCO
#CC=cc -W1 $(UNIXPARSNG) -DOBJECTADDR -DTCPIP   # SCO TCPIP
CC=gcc $(UNIXPARSNG) -DOBJECTADDR -DXSIGHT      # GNU C+
#CC=cc -W1 $(UNIXPARS) -DSYSV -DXSIGHT          # SCO with X11 graphics
#CC=gcc -g $(UNIXPARS) -DSYSV -DXSIGHT          # SCO GCC with X11 graphics

CCc=$(CC)                                       # common version
#CCc=$(CC) -Fo$*.o                              # MSDOS MSC version

target : int

#############################################################################



OBJ= cint.o compact.o control.o util.o handler.o intdt.o        \
     memory.o object.o runsys.o standard.o                      \
     execute.o fileio.o nonstand.o process.o procaddr.o queue.o \
     rpcall.o typchk.o  $(NETFILE)

.c.o :
	$(CCc) -c $*.c
.s.o:
	as -o $*.o $*.s

hgcint.exe: $(OBJ) inkeydos.o graf\lib\hgcmsf4.lib
	link /e @link.lnk inkeydos.o, hgcint.exe, nul, graf\lib\hgcmsf4, ;

egaint.exe: $(OBJ) inkeydos.o graf\lib\egamsf4.lib
	link /e @link.lnk inkeydos.o, egaint.exe, nul, graf\lib\egamsf4, ;

cgaint.exe: $(OBJ) inkeydos.o graf\lib\mgcmsf4.lib
	link /e @link.lnk inkeydos.o, cgaint.exe, nul, graf\lib\mgcmsf4, ;

cga64int.exe: $(OBJ) inkeydos.o graf\lib\mgc64mf4.lib
	link /e @link.lnk inkeydos.o, cga64int.exe, nul, graf\lib\mgc64mf4, ;

int386.exe: $(OBJ)
	$(CC) @link.lnk -lm -lpc -lgrx -o svgaint
	strip svgaint
	coff2exe svgaint
	rm svgaint
#       move svgaint.exe ..\examp\svgaint.exe

int: $(OBJ) inkeyux.o
#	$(CC) $(OBJ) inkeyux.o -lm -lX11 -lmalloc -lsocket -o int
	$(CC) $(OBJ) inkeyux.o -lm -lX11 -o int
	strip int
#	mv int $(HOME)/bin

nonstand.o : nonstand.c  x11graf1.c x11graf2.c 

herc : herc.c
	$(CC) herc.c -lX11 -lmalloc -lsocket -o herc
	strip herc

clean :
	rm *.o
	rm int

install:
	cp int /usr/bin/int
