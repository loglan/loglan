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


void pascal draw( _col, _row )
   int *_col,*_row;
{
   int X1 = inxpos(NULL);
   int Y1 = inypos(NULL);
   int X2 = *_col;
   int Y2 = *_row;
   int pos_slope;

   int dX, dY,                                       /* vector components */
       row, col,
       final,                                  /* final row or col number */
       G,                           /* used to test for new row or column */
       inc1,             /* G increment when row or column doesn't change */
       inc2;                /* G increment when row or column does change */

   if( X2 < X1 )
   {
      X1 = *_col;
      Y1 = *_row;
      X2 = inxpos(NULL);
      Y2 = inypos(NULL);
   }

   dX = X2 - X1;   dY = Y2 - Y1;                 /* find vector component */
   pos_slope = (dX > 0);                            /* is slope positive? */
   if (dY < 0) pos_slope = !pos_slope;
   if (abs(dX) > abs(dY)) {                          /* shallow line case */
      if (dX > 0) {              /* determine start point and last column */
         col = X1; row = Y1; final = X2;
      } else {
         col = X1; row = Y2; final = X1;
      }
      inc1 = 2*abs(dY);             /* determine increments and initial G */
      G = inc1 - abs(dX);
      inc2 = 2 * (abs(dY) - abs(dX));
      if (pos_slope)
         while (col<=final) {     /* step thru cols. checking for new row */
            point( &col, &row );
            col++;
            if (G >= 0) {                     /* it's time to change rows */
               row++;  G+= inc2;      /* positive slope, so inc thru rows */
            } else                                /* stay at the same row */
               G += inc1;
         } /* while */
      else
         while (col<=final) {        /* step thru cols, check for new row */
            point( &col, &row );
            col++;
            if (G > 0) {                       /* time to change the rows */
               row--;  G+= inc2;         /* negative slope, dec thru rows */
            } else
               G += inc1;                         /* stay at the same row */
         } /* while */
   } /* if |dX| > |dY| */  else {
      if (dY > 0) {                 /* steep line case, angle > 45 degree */
         col = X1; row = Y1; final = Y2; /* find start point and last row */
      } else {
         col = X2; row = Y2; final = Y1;
      }
      inc1 = 2 * abs(dX);           /* determine increments and initial G */
      G = inc1 - abs(dY);
      inc2 = 2 * (abs(dX) - abs(dY));
      if (pos_slope)
         while (row <= final) {  /* step thru rows - check for new column */
            point( &col, &row );
            row++;
            if (G >= 0) {                  /* it's time to change columns */
               col++;  G+= inc2;      /* pos. slope, increment thru cols. */
            } else
               G += inc1;                      /* stay at the same column */
         } /* while */
     else
         while (row <= final) {/* step thru rows, checking for new column */
            point( &col, &row );
            row++;
            if (G > 0) {                   /* it's time to change columns */
               col--;  G+= inc2;  /* neg slope, so decrement thru columns */
            } else
               G += inc1;                      /* stay at the same column */
         } /* while */
   } /* if |dY| > |dX| */

   move( _col, _row );
}



