
#include "graf.h"

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

void pascal getmap( x, y, buf )
   int *x,*y;
   char *buf;
{
 /* buffer : 2 bytes X size, 2 bytes Y size, and rows * columns of pixels */
   int i,j,x0,y0,x1,y1;
   int x00 = inxpos(NULL);
   int y00 = inypos(NULL);
   pushxy();
   if( *x < x00 )
   {
      x0 = *x;
      x1 = x00;
   }
   else
   {
      x1 = *x;
      x0 = x00;
   }
   if( *y < y00 )
   {
      y0 = *y;
      y1 = y00;
   }
   else
   {
      y1 = *y;
      y0 = y00;
   }
   ((short int *)buf)[0] = (short int)(x1-x0+1);
   ((short int *)buf)[1] = (short int)(y1-y0+1);
   buf += 4;
   for( j=y0; j<=y1; j++ )
      for( i=x0; i<=x1; i++ )
         *(buf++) = (char)inpix( &i, &j );
   popxy();
}


void pascal putmap( buf )
   char *buf;
{
   int x00 = inxpos(NULL);
   int y00 = inypos(NULL);
   int xw = ((short int *)buf)[0];
   int yw = ((short int *)buf)[1];
   int i,j;
   pushxy();
   buf += 4;
   for( j=y00; j<y00+yw; j++ )
      for( i=x00; i<x00+xw; i++ )
      {
         int c = (int)*buf;
         color( &c );
         point( &i, &j );
         buf++;
      }
   popxy();
}


void pascal  ormap( buf )
   char *buf;
{
   int x00 = inxpos(NULL);
   int y00 = inypos(NULL);
   int xw = ((short int *)buf)[0];
   int yw = ((short int *)buf)[1];
   int i,j;
   pushxy();
   buf += 4;
   for( j=y00; j<y00+yw; j++ )
      for( i=x00; i<x00+xw; i++ )
      {
         int c = inpix( &i, &j );
         c |= (int)*buf;
         color( &c );
         point( &i, &j );
         buf++;
      }
   popxy();
}


void pascal xormap( buf )
   char *buf;
{
   int x00 = inxpos(NULL);
   int y00 = inypos(NULL);
   int xw = ((short int *)buf)[0];
   int yw = ((short int *)buf)[1];
   int i,j;
   pushxy();
   buf += 4;
   for( j=y00; j<y00+yw; j++ )
      for( i=x00; i<x00+xw; i++ )
      {
         int c = inpix( &i, &j );
         c ^= (int)*buf;
         color( &c );
         point( &i, &j );
         buf++;
      }
   popxy();
}
	


