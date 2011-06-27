#/*     Loglan82 Compiler&Interpreter
#     Copyright (C) 1993 Institute of Informatics, University of Warsaw
#     Copyright (C)  1993, 1994 LITA, Pau
#     
#     This program is free software; you can redistribute it and/or modify
#     it under the terms of the GNU General Public License as published by
#     the Free Software Foundation; either version 2 of the License, or
#     (at your option) any later version.
#     
#     This program is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
#     
#             You should have received a copy of the GNU General Public License
#             along with this program; if not, write to the Free Software
#             Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# contacts:  Andrzej.Salwicki@univ-pau.fr
#
# or             Andrzej Salwicki
#                LITA   Departement d'Informatique
#                Universite de Pau
#                Avenue de l'Universite
#                64000 Pau   FRANCE
#                tel.  ++33 59923154    fax. ++33 59841696
#
#=======================================================================
#*/
#
# switches SMALL/LARGE/HUGE switch between :
# 16-bit small, 16-bit large and 32-bit memory models

SHELL=/bin/sh
OBJ=gen.o mainvar.o genio.o lists.o genprot.o oxen.o back.o logen.o deb.o lcode.o

#change this according to your system

#CC=cl -Oelsgc -DSMALL -DTALK=0 -AC -Fo$*.o     # MSC small
#CC=cl -Oelsgc -DLARGE -DTALK=0 -AC -Fo$*.o     # MSC large
CC=gcc -O -DHUGE -DTALK=20                       # GCC
#CC=gcc -DHUGE -DNO_PROTOTYPES -DTALK=0          # SUN
#CC=cc -Oactl -CSON -W2 -DHUGE -DTALK=0         # SCO

target : gen

# UNIX 32-bit version
gen : $(OBJ)
	$(CC) $(OBJ) -o gen
	strip gen
#	cp gen $(HOME)/bin

# GCC version HUGE 32-bit memory
gen32.exe : $(OBJ)
	$(CC) $(OBJ) -o gen.out
	aout2exe gen.out
	rm gen.out

# MSC version LARGE 16-bit memory
gen.exe : $(OBJ)
	link /e $(OBJ)

# MSC version SMALL 16-bit memory
hgen.exe : $(OBJ)
	link /e $(OBJ)

.c.o :
	$(CC) -c $*.c

clean :
	rm *.o gen


