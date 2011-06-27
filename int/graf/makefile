#     /* Loglan82 Compiler&Interpreter
#     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw
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
# =======================================================================


COMMON=hlineio.o draw.o hvfill.o cirb.o gpmap.o hercules.o

CC=gcc -O -Dpascal= -DWORD_32BIT
CCc=$(CC) -c

#CC=cl -AL -Olsg
#CCc=$(CC) -Fo$*.o -c

.c.o :
	$(CCc) $*.c

hgc386.a : $(COMMON)
	ar rv hgc386.a $(COMMON)


