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

/*****************************************************************
 *                                                               *
 *  Package of the I/O routines to be called from FORTRAN, VAX   *
 *    according to the Standard of VAX-11 Procedure Calls.       *
 *              For the LOGLAN-82 VAX/VMS Compiler               *
 *                                                               *
 *               (C) Andrzej I. Litwiniuk (AIL)                  *
 *                   Institute of Informatics                    *
 *                   University of Warsaw                        *
 *                                                               *
 *                    Version 1988.10.17                         *
 *                                                               *
 *****************************************************************/

#if WSIZE==4
	typedef long word;
#elif WSIZE==2
	typedef short word;
#else
 Define WSIZE to 2 or 4 !
#endif

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "f2c.h"

FILE *file_arr[30]={NULL};
static char *file_names[30]={NULL};

void ffopen_(stream,name,one) /* open file for binary reading */
word *stream;
char *name;
long one;
{
   FILE *f=fopen(name,"rb"); /* read binary */
   if (f == NULL) { printf("file %s cannot be opened\n",name); exit(1); }
   file_arr[*stream]=f;
}

void ffcreat_(stream,name,one) /* open a new file for binary writing */
word *stream;
char *name;
long one;
{
   FILE *f=fopen(name,"wb"); /* write binary */
   if (f == NULL) { printf("file %s cannot be opened\n",name); exit(1); }
   file_arr[*stream]=f;
   if( file_names[*stream] != NULL )  free( file_names[*stream] );
   file_names[*stream]=(char *)malloc( strlen(name)+1 );
   strcpy( file_names[*stream], name );
}

static int tmp_files[10];
static int tmp_cnt=0;
static void clean_tmp()
{
   int i;
   for( i=0; i<tmp_cnt; i++ ){
      fclose( file_arr[ tmp_files[i] ] );
      unlink( file_names[ tmp_files[i] ] );
   }
}

void ffcrtmp_(stream) /* open a temporary file for binary writing */
word *stream;
{
   extern char *tempnam();
   char *tmp=tempnam(NULL,"logl");
   FILE *f=fopen(tmp,"w+b");
/*   FILE *f=tmpfile(); /* temporary file opened for update */
   if (f == NULL) { perror("temporary file cannot be opened"); exit(1); }
   file_arr[*stream]=f;
   file_names[*stream]=strdup(tmp);
   tmp_files[ tmp_cnt++ ] = *stream;
/*   unlink(tmp);*/
/* A.S. 18-03-94  atexit( clean_tmp );  */
}

void ffclose_(stream) word *stream; {
   if(file_arr[*stream]!=NULL) fclose(file_arr[*stream]);
}
void ffunlink_(stream) word *stream; {
   if( file_names[*stream] != NULL )
      unlink( file_names[*stream] );
}

void ffseek_(stream,offset) word *stream,*offset; {
   fseek(file_arr[*stream],(long)(*offset),0);
}

void ffread_(stream,mloc,bytes) word *stream,*mloc,*bytes; {
   *bytes=fread((char *)mloc,1,(int)(*bytes),file_arr[*stream]);
}

void fferror_(code) word *code;{
   fprintf(stderr," I/O Error number %d\n",(int)(*code));
   abort();
}

void ffwrite_ints__(stream,mloc,ints) word *stream,*mloc,*ints;{
   word l=31;
   if( fwrite((char *)mloc,sizeof(word),(int)(*ints),file_arr[*stream]) != (int)(*ints) )
      fferror_(&l);
}

void ffwrite_(stream,mloc,bytes) word *stream,*mloc,*bytes; {
   word l=30;
   if( fwrite((char *)mloc,1,(int)(*bytes),file_arr[*stream]) != (int)(*bytes) )
      fferror_(&l);
}

void ffwrite_char__(stream,mloc,chars)
   word *stream;
   char *mloc;
   long chars;
{
   word l=29;
   if( fwrite(mloc,1,(int)chars,file_arr[*stream]) != (int)chars)
      fferror_(&l);
}

void ffwrint_(unit,item) word *unit,*item;{
   word l=28;
   if(file_arr[*unit]==NULL) fferror_(&l);
   fprintf(file_arr[*unit],"%6.6d",(int)(*item));
}

void ffwrhex_(unit,item) word *unit,*item;{
   word l=27;
   if(file_arr[*unit]==NULL) fferror_(&l);
   fprintf(file_arr[*unit],"%04.4x",(int)(*item));
}

void nextch_(unit,ch) word *unit,*ch;{
   FILE *f=file_arr[*unit];
   *ch=(word)getc(f);
   if(*ch == EOF ) *ch = 2;
   if(*ch ==  26 ) *ch = 2;
   if(*ch == '\n') *ch = 1;
/*   if(*ch == '\r') *ch = 1; */
   if(*ch == '\r') *ch = ' ';
}

void frdchr_(unit,c,count) word *unit; char *c; long count;{
   FILE *f=file_arr[*unit];
   int i;
  skip_nl:
   i=getc(f);
   if(i== EOF) i = 2;
   if(i==  26) i = 2;
   if(i=='\r') i = 1;
   if(i=='\n') goto skip_nl;
   *c=(char)i;
}

static int reclen=512;

void openf_(itab,ident) word *itab,*ident;{
   itab[0]=0;
   itab[1]=*ident;
   ffcrtmp_(ident);
   reclen=256*sizeof(word);
}

void get_(itab,item) word *itab,*item;{
   word recnr,offset,len;
   itab[0]++;
   recnr=itab[0]-1;
   offset=recnr*reclen;
   ffseek_(itab+1,&offset);
   len = reclen;
   ffread_(itab+1,item,&len);
   if(len!=reclen){
      len=30;
      fferror_(&len);
   }
}

void seek_(itab,number) word *itab,*number;{
   itab[0]=*number;
}

void closf_(itab) int *itab;{
   ffclose_(itab+1);
}

void put_(itab,item) word *itab,*item;{
   word recnr,offset;
   itab[0]++;
   recnr=itab[0]-1;
   offset=recnr*reclen;
   ffseek_(itab+1,&offset);
   ffwrite_(itab+1,item,&reclen);
}


