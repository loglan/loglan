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

#ifdef GEN
#undef GEN
#endif

#if UNIX
#include "../gen/genint.h"
#else
#include "..\gen\genint.h"
#endif

/* Variables : */

extern protdescr *prototype[];
extern word ipradr;         /* address of primitive type descriptions */
extern word temporary;          /* address of global temporary variables */
extern word strings;            /* base for string constants */
extern word lastprot;           /* the last used prototype number */
extern word freem;           /* first free cell in M */
extern word currfile;     /* current file virtual address */

