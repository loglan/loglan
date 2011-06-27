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

/*
            OUTHLINE(dlugosc,bufor)
            
                     Procedura OUTHLINE wywoluje HASCII dlugosc razy,
            wypisujac na ekran znaki, ktorych kody zawarte sa w buforze.
            Przed narysowaniem kazdego znaku wywolywane jest HASCII(0).
*/

#include "graf.h"

void pascal outhli( length, buf )
   int *length;
   char *buf;
{
   int l = (*length) % 0x10000;
   int zero = 0;
   while( l-- > 0 )
   {
      hascii( &zero );
      hascii( (int *)(buf++) );
   }
}
            

