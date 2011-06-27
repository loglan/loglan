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

#include <stdio.h>

#if WSIZE==4
	typedef long word;
#elif WSIZE==2
	typedef short word;
#else
 Define WSIZE to 2 or 4 !
#endif

   
extern FILE *file_arr[];


#define sunit FILE *f=stdout; if((int)(*unit)!=0L) f=file_arr[*unit];


void ffputnl_(unit) word *unit;{
   sunit
   fprintf(f,"\n");
}
void ffputff_(unit) word *unit;{
   sunit
   fprintf(f,"\f");
}
void ffputspaces_(unit,count) word *unit,*count;{
   sunit
   fprintf(f,"%*s",(int)(*count),"");
}
void ffputi_(unit,i,count) word *unit,*i,*count;{
   sunit
   fprintf(f,"%*d",(int)(*count),(int)(*i));
}
void ffputcs_(unit,s,count) word *unit; long count; char *s;{
   sunit
   fprintf(f,"%*.*s",(int)count,(int)count,s);
}
void ffputs_(unit,s,count,one) word *unit,*count; char *s; long one;{
   sunit
   fprintf(f,"%*.*s",(int)(*count),(int)(*count),s);
}
void ffgets_(unit,s,count,one) word *unit,*count; char *s; long one;{
   FILE *f=stdin; if((int)(*unit)!=0) f=file_arr[*unit];
   fgets(s,(int)(*count),f);
}
void ffexit_(){ exit(0); }


