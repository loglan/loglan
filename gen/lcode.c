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
     

=======================================================================
*/

#if TALK >= 3

#include <stdio.h>
#include <string.h>

#include "glodefs.h"
#include "mainvar.h"


void dump_lcode( name ) char *name;{

   FILE *fout;
   char outname[100];
   unsigned char opdescr[ 229 ];
   int args[ 3 ] , arg_no ;
   int  i, opcode, n ;

   strcpy(outname,name);
   fout=fopen(strcat(outname,".lco"),"w");
   if( fout==NULL ){
      fprintf(stderr,"Can't open file %s for writing\n",name);
      exit(10);
   }

   /* initiate opdescr */

   for( n=100; n<=131; n++ )  opdescr[ n ]=3;
   for( n=30 ; n<=83 ; n++ )  opdescr[ n ]=2;
   opdescr[ 29 ]=3;
   opdescr[ 37 ]=3;
   opdescr[ 39 ]=3;
   opdescr[ 40 ]=3;
   opdescr[ 44 ]=2;
   opdescr[ 45 ]=2;
   for( n=52 ; n<=57 ; n++ )  opdescr[ n ]=3;
   for( n=84 ; n<=99 ; n++ )  opdescr[ n ]=3;
   opdescr[ 11 ]=1;
   opdescr[ 12 ]=1;
   opdescr[ 13 ]=2;
   opdescr[ 15 ]=2;
   opdescr[ 16 ]=2;
   for( n=20 ; n<=26 ; n++ )  opdescr[ n ]=3;
   for( n=1  ; n<=5  ; n++ )  opdescr[ n ]=3;
   opdescr[ 2 ]=2;
   opdescr[ 132 ]=1;
   opdescr[ 145 ]=3;
   opdescr[ 137 ]=2;
   opdescr[ 138 ]=2;
   opdescr[ 139 ]=2;
   opdescr[ 144 ]=2;
   opdescr[ 149 ]=2;
   opdescr[ 150 ]=2;
   opdescr[ 151 ]=2;
   opdescr[ 152 ]=2;
   opdescr[ 140 ]=1;
   opdescr[ 141 ]=1;
   opdescr[ 143 ]=1;
   opdescr[ 146 ]=1;
   opdescr[ 147 ]=1;
   opdescr[ 148 ]=1;
   opdescr[ 153 ]=1;
   opdescr[ 158 ]=1;
   opdescr[ 159 ]=2;
   opdescr[ 160 ]=2;
   opdescr[ 161 ]=2;
   opdescr[ 162 ]=2;
   opdescr[ 163 ]=2;
   opdescr[ 164 ]=3;
   opdescr[ 165 ]=3;
   opdescr[ 166 ]=3;
   opdescr[ 170 ]=3;
   for( n=172 ; n<= 194 ; n++ )  opdescr[ n ]=0;
   opdescr[ 175 ]=1;
   opdescr[ 177 ]=1;
   opdescr[ 178 ]=1;
   opdescr[ 181 ]=1;
   opdescr[ 182 ]=1;
   opdescr[ 183 ]=1;
   opdescr[ 184 ]=1;
   opdescr[ 186 ]=1;
   opdescr[ 188 ]=1;
   opdescr[ 189 ]=3;
   opdescr[ 220 ]=1;
   opdescr[ 221 ]=0;
   opdescr[ 222 ]=0;
   opdescr[ 223 ]=0;
   opdescr[ 224 ]=0;
   opdescr[ 225 ]=0;
   opdescr[ 226 ]=0;
   opdescr[ 227 ]=0;
   opdescr[ 228 ]=1;
   for( n = 195 ; n<=219 ; n++ )  opdescr[ n ]=2;
   for( n = 201 ; n<=204 ; n++ )  opdescr[ n ]=1;


   while( 1 ) {

      opcode = next();
      arg_no = opdescr[ opcode ] ;
      for(i = 0 ; i < arg_no  ; i++)  args[ i ] = next();

      fprintf(fout,"  %3d    " , opcode );

      switch( opcode ) {

       case  13 :
         if(args[ 1 ] > 0 )
            fprintf(fout,"     t%-5d := R%1d",args[0],args[1]);
         else
            fprintf(fout,"     t%-5d := %5d(R6)",args[0],args[1]);
         break;

       case  23 :
         fprintf(fout,"     t%-5d := sp%-3d.par%02d",args[0],args[1],args[2]);
         break;

       case  37 :
         fprintf(fout,"     t%-5d := t%-5d + %d",args[0],args[1],args[2]);
         break;

       case  60 :
         fprintf(fout,"     t%-5d := t%-5d",args[0],args[1]);
         break;

       case  64 :
       case  65 :
       case  66 :
       case  67 :
       case  68 :
       case  69 :
       case  70 :
       case  71 :
       case  72 :
         fprintf(fout,"     t%-5d := %2d * t%-5d",args[0],opcode-62,args[1]);
         break;

       case 110 :
         fprintf(fout,"     t%-5d := ( t%-5d  > t-5d )",args[0],args[1],args[2]);
         break;

       case 132 :
         fprintf(fout,"     call sp%-3d",args[0]);
         break;

       case 139 :
         if( args[ 1 ] > 0 )
            fprintf(fout,"     R%1d   := t%-5d",args[1],args[0]);
         else
            fprintf(fout,"     %5d(R6)  := t%-5d",-args[1],args[0]);
         break;

       case 140 :
         fprintf(fout,"     nop");
         break;

       case 145 :
         fprintf(fout,"     sp%-3d.par%02d := t%-5d",args[1],args[2],args[0]);
         break;

       case 151 :
         fprintf(fout,"     if not t%-5d  goto L%-4d",args[0],args[1]);
         break;

       case 152 :
         fprintf(fout,"     if t%-5d  goto  L%-4d",args[0],args[1]);
         break;

       case 174 :
         fprintf(fout,"LASTWILL :");
         break;

       case 177 :
         fprintf(fout,"* line  %5d",-args[0]+1);
         break;

       case 179 :
         fprintf(fout," Entry point:");
         break;

       case 181 :
         fprintf(fout,"L%-4d :",args[0]);
         break;

       case 182 :
         fprintf(fout,"     jump  L%-4d",args[0]);
         break;

       case 184 :
         fprintf(fout,"BEGIN   M%05d",args[0]);
         break;

       case 185 :
         fprintf(fout,"END");
         break;

       case 191 :
         fprintf(fout,"     backbl");
         break;

       case 192 :
         fprintf(fout,"     backpr");
         break;

       case 193 :
         fprintf(fout,"     back");
         break;

       case 194 :
         fprintf(fout,"      fin");
         break;

       case 199 :
         fprintf(fout,"     iconst t%-5d = %5d",args[0],args[1]);
         break;

       case 200 :
         fprintf(fout,"END OF CODE" );
         break;

       case 201 :
         fprintf(fout,"     tempvar1  t%-5d",args[0]);
         break;

       case 202 :
         fprintf(fout,"     tempvar2  t%-5d",args[0]);
         break;

       case 203 :
         fprintf(fout,"     tempvar3  t%-5d",args[0]);
         break;

       case 204 :
         fprintf(fout,"     tempvar4  t%-5d",args[0]);
         break;

       case 205 :
         fprintf(fout,"     globvar   t%-5d   [ desc = &5d ]",args[0],args[1]);
         break;

       case 208 :
         fprintf(fout,"     livevar   t%-5d  := t%-5d",args[0],args[1]);
         break;

       case 223 :
       case 224 :
       case 225 :
       case 227 :
         {
            qcurr=1;
            makeproclist();
            fprintf(fout,"     proclist   ");
         }
         break;

       default  :
         for( i=0; i<arg_no; i++ ) fprintf(fout,"     %c = %5d ",'A'+i,args[i]);
         break;

      }

      fflush(fout);

      fprintf(fout,"\n");

      if( opcode>=172 && opcode<=176  ||  opcode>=178 && opcode<=194 )
         fprintf(fout,"---------------------------------------------------\n");

      if( opcode == 200 )  break ;	/* end-marker */

   }

   fclose(fout);

}

#endif

