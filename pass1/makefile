#############################################################################

WSIZE=4   # 2 for 16-bit system, 4 for 32-bit system

#CPPMEM=-DLMEMSIZE=32000 -DLPMEMSIZE=22000      # 16-bit version
CPPMEM= -DLMEMSIZE=70000 -DLPMEMSIZE=48000       # 32-bit VAX & MSDOS GCC
#CPPMEM=-DLMEMSIZE=100000 -DLPMEMSIZE=70000     # 32-bit UNIX

WORDS_IN_REAL=1 # 2 on 16-bit, 1 on 32-bit
DISABLE_H=1     # 0=enable H option on 16-bit, 1=disable on 32-bit

# MSC version
#CPP=cl -EP
#CC=cl -AH -Oelsgc -Fo$*.o

# GCC under MSDOS version i.e. DJ GNU C++
#CPP=cpp -P
#CC=gcc -O -m486

# UNIX version
CPP=gcc -x c -E -P                     # GNU cpp
#CPP=/lib/cpp -P                        # MICROSOFT cpp
#CC=cc -I. -Oactl -CSON                 # UNIX SCO
#CC=cc -I. -Od                          # UNIX SCO -    with respect to
#                                       #               MICROSOFT compiler
#CC=cc -I. +Np650 -DNO_PROTOTYPES       # UNIX HP
#CC=cc -I. -DNO_PROTOTYPES              # SUN SPARC
CC=gcc -O                              # GCC


target : loglan


#############################################################################



.SUFFIXES:
.SUFFIXES: .o .ff
.SUFFIXES: .o .f
.SUFFIXES: .o .c

SHELL=/bin/sh

OBJ=al11.o al12.o al13.o \
    debug.o dsw.o hash.o ifun.o it0.o it1.o \
    memfil.o resume.o scan.o spgrec.o \
    wan1.o wan2.o wan3.o \
    ml2.o ml3.o \
    main.o stdio.o

F2C=f2c -I$(WSIZE) -NL400 

#F2C=f2c -I$(WSIZE)
CCPARS=-I. -DWSIZE=$(WSIZE)



loglan16.exe : $(OBJ)
	link /e /farcalls @msdos.lnk

loglan32.exe : $(OBJ)
	$(CC) -o loglan.out @unix.lnk
	strip loglan.out
	aout2exe loglan.out
	rm loglan.out

loglan : $(OBJ)
	$(CC) $(OBJ) -lf2c -lm -o loglan
	strip loglan
#	mv loglan $(HOME)/bin


.ff.o :
	$(CPP) $(CCPARS) $(CPPMEM) --traditional-cpp -DWORDS_IN_REAL=$(WORDS_IN_REAL) -DDISABLE_H=$(DISABLE_H) $*.ff > $*.f
	$(F2C) $*.f
	rm $*.f
	$(CC) $(CCPARS) -c $*.c
#	rm $*.c

.f.o :
	$(F2C) $*.f
	$(CC) $(CCPARS) -c $*.c
	rm $*.c
	
.c.o :
	$(CC) $(CPPMEM) $(CCPARS) -c $*.c

clean:
	-rm -f *.o
	-rm -f loglan.exe
	-rm -f loglan
	-rm -f loglan.out
	-rm -f state.rst

install:
	cp loglan /usr/bin/

al11.o : al11.ff blank.h blank2.h option.h stos.h
al12.o : al12.ff blank.h blank2.h option.h stos.h
al13.o : al13.ff blank.h blank2.h option.h stos.h
it0.o  : it0.ff  blank.h blank2.h option.h stos.h

