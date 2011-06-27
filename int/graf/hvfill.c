     /* Loglan82 Compiler&Interpreter
     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw
     Copyright (C)  1993, 1994 LITA, Pau
     
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.
     
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
     
=======================================================================
*/

#include "graf.h"


void pascal hfill( col )
   int *col;
{
   int x = inxpos(NULL);
   int y = inypos(NULL);
   draw( col, &y );
   move( &x, &y );
}


void pascal vfill( row )
   int *row;
{
   int x = inxpos(NULL);
   int y = inypos(NULL);
   draw( &x, row );
   move( &x, &y );
}


