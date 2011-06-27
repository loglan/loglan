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

#include <dos.h>
#include "graf\graf.h"


static union REGS r;

#ifndef NO_PROTOTYPES
static char *normalize(char *);
static int mouse(int,word *,word *,word *);
#else
static char *normalize();
static int mouse();
#endif



static char *normalize(addr)	/* Normalize segmented address */
    char *addr;
{
    union{
        char *address;
        unsigned int words[2];
    } conv;
    conv.address = addr;
#if !WORD_32BIT
    conv.words[1] += conv.words[0] / 16;
    conv.words[0] %= 16;
#endif
    return (conv.address);
}



static int mouse(func, bx, cx, dx)	/* Call mouse driver INT 33H */
int func;
word *bx, *cx, *dx;
{
    union REGS r;
    r.x.ax = func;
    r.x.bx = *bx;
    r.x.cx = *cx;
    r.x.dx = *dx;
    int86(0x33, &r, &r);
    *bx = (int) r.x.bx;
    *cx = (int) r.x.cx;
    *dx = (int) r.x.dx;
    return(r.x.ax);
}

