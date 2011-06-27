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
		 tel.  ++33 59923154    fax. ++33 59841696

=======================================================================
*/

#include        "depend.h"
#include        "genint.h"
#include        "int.h"
#include        "process.h"
#include        "intproto.h"

#include <stdio.h>

/* File I/O routines */

void loadfile(status, ftype, am, fp)    /* Load parameters of current file */
word status;                            /* expected status of file */
word *ftype;                            /* file type */
word *am;                               /* file object address */
FILE **fp;                              /* file stream pointer */
{
    word s;
    virtaddr virt;

    loadvirt(virt, currfile);
    if (member(&virt, am))              /* file object exists */
    {
	s = M[ *am+FSTAT ];             /* check status */
	if (status != s && status != UNKNOWN) errsignal(RTEILLIO);
	*ftype = M[ *am+FTYPE ];
	*fp = MF(*am+FFILE);
    }
    else errsignal(RTEREFTN);           /* file not opened yet */
} /* end loadfile */


/* Open file object
 */

void genfileobj(ftemp, ftyp, fnam, virt, am)
bool ftemp;                             /* TRUE iff file is temporary */
word ftyp;                              /* file type */
char *fnam;                             /* file name */
virtaddr *virt;                         /* output virtual address */
word *am;                               /* output physical address */
{
    word t1;

    request((word) APFILE, &t1, am);    /* generate file object */
    virt->addr = t1;
    virt->mark = M[ t1+1 ];
    M[ *am+PROTNUM ] = FILEOBJECT;
    M[ *am+FSTAT ] = UNKNOWN;
    M[ *am+FTEMP ] = lbool(ftemp);
    M[ *am+FTYPE ] = ftyp;
    MN(*am+FNAME) = fnam;
} /* end genfileobj */


void reset(am)                          /* Prepare file for reading */
word am;
{
    FILE *fp;

    if (M[ am+FSTAT ] != UNKNOWN)       /* first close file if opened */
	if (fclose(MF(am+FFILE))) errsignal(RTEIOERR);
    switch ((int) M[ am+FTYPE ])
    {
	case TEXTF  :                   /* open text file for reading */
		fp = fopen(MN(am+FNAME), "r");
		M[ am+FSTAT ] = READING;
		break;
	
	case CHARF  :                   /* open binary file for reading */
	case INTF   :
	case REALF  :
		fp = fopen(MN(am+FNAME), BINARYREAD);
		M[ am+FSTAT ] = READING;
		break;
	
	case DIRECT :                   /* open existing file for update */
		fp = fopen(MN(am+FNAME), DIRECTOLD);
		M[ am+FSTAT ] = UPDATING;
		break;
    }
    if (fp == NULL)
    {
	M[ am+FSTAT ] = UNKNOWN;
	errsignal(RTECNTOP);
    }
    MF(am+FFILE) = fp;                  /* store stream pointer */
} /* end reset */

	
void rewrite(am)                        /* Prepare file for writing */
word am;
{
    FILE *fp;

    if (M[ am+FSTAT ] != UNKNOWN)       /* first close file if opened */
	if (fclose(MF(am+FFILE))) errsignal(RTEIOERR);

    switch ((int) M[ am+FTYPE ])
    {
	case TEXTF  :                   /* open text file for writing */
		fp = fopen(MN(am+FNAME), "w");
		M[ am+FSTAT ] = WRITING;
		break;
	
	case CHARF  :                   /* open binary file for writing */
	case INTF   :
	case REALF  :
		fp = fopen(MN(am+FNAME), BINARYWRITE);
		M[ am+FSTAT ] = WRITING;
		break;
	
	case DIRECT :                   /* create new file for update */
		fp = fopen(MN(am+FNAME), DIRECTNEW);
		M[ am+FSTAT ] = UPDATING;
		break;
    }
    if (fp == NULL)
    {
	M[ am+FSTAT ] = UNKNOWN;
	errsignal(RTECNTOP);
    }
    MF(am+FFILE) = fp;                  /* store stream pointer */
} /* end rewrite */


void delete(virt)                       /* Delete file */
virtaddr *virt;
{
    word am;

    if (member(virt, &am))
    {
	if (M[ am+FSTAT ] != UNKNOWN)   /* first close file if opened */
	    if (fclose(MF(am+FFILE))) errsignal(RTEIOERR);
	if (unlink(MN(am+FNAME))) errsignal(RTEIOERR);  /* delete file */
	free(MN(am+FNAME));             /* free memory used by file name */
	disp(virt);                     /* and kill file object */
    }
    else errsignal(RTEREFTN);
} /* end delete */


char *tempfilename()                    /* Generate temporary file name */
{
    char *cp;
    static int tempcnt = 0;

    cp = ballocate(10);
    if (cp == NULL) errsignal(RTEMEMOV);
    sprintf(cp, "LOG%05d", tempcnt++);
    return (cp);
} /* end tempfilename */


bool testeof(fp)                        /* Test for end of file */
FILE *fp;
{
    int ch;

    ch = getc(fp);
    ungetc(ch, fp);
    return (ch == EOF);
} /* end testeof */


bool testeoln(fp)                       /* Test for end of line */
FILE *fp;
{
    int ch;

    ch = getc(fp);
    ungetc(ch, fp);
    return (ch == '\n');
} /* end testeoln */


void readln(fp)                         /* Skip to end of line */
FILE *fp;
{
    int ch;

    while ((ch = getc(fp)) != '\n' && ch != EOF) ;
} /* end readln */


static char str[10];
word readint(fp)                        /* Read integer */
FILE *fp;
{
    long i=0L;
    int j=0,c=0;
    int bool=0;
    while(c<'0' || c>'9'){
       if(c=='-') bool=1;
       else bool=0;
       c=fgetc(fp);
       if(c==EOF){
	  errsignal(RTEBADFM);
	  goto END;
       }
    }
    
    do{
       i=10*i+(c-'0');
       j++;
       c=fgetc(fp);
    }while(c>='0' && c<='9');
    if(c!=EOF) ungetc(c,fp);
    if (j == 0 ) errsignal(RTEBADFM);
 END:
    if(bool)
      return(-i);
    else
     return (i);
} /* end readint */


double readreal(fp)                     /* Read real */
FILE *fp;
{
    double r;

    if (fscanf(fp, "%lf", &r) != 1) errsignal(RTEBADFM);
    return (r);
} /* end readreal */


void writeint(n, field, fp)             /* Write integer */
word n, field;
FILE *fp;
{
/* PS&MM   static char format[ 32 ];

    sprintf(format,"%%%dld",(int)field); */
    if (fprintf(fp, "%*ld", (int)field, (long) n) == 0) errsignal(RTEIOERR);
} /* end writeint */


void writereal(r, field1, field2, fp)   /* Write real */
double r;
word field1, field2;
FILE *fp;
{
/* PS&MM   char format[ 32 ];

    sprintf(format, "%%%d.%dlf", (int) field1, (int) field2);
    if (fprintf(fp, format, r) == 0) errsignal(RTEIOERR);
*/
    if (fprintf(fp,"%*.*lf", (int)field1, (int)field2, r) == 0)
       errsignal(RTEIOERR);
} /* end writereal */


void writestring(offset, field, fp)     /* Write string */
word offset;
word field;
FILE *fp;
{
    word len, addr;
    char *cp;

    addr = strings+offset;
    len = M[ addr ];
    cp = (char *) &M[ addr+1 ];         /* pointer to first char of string */
    while (len-- > 0 && field-- != 0)
	if (putc(*cp++, fp) == EOF) errsignal(RTEIOERR);
} /* end writestring */


word directio(buf, len, action, fp)     /* Perform direct access read/write */
virtaddr *buf;                          /* buffer array */
word len;                               /* number of bytes to transfer */
#ifndef NO_PROTOTYPES
int (*action)(char *,int,int,FILE *);   /* fread() or fwrite() */
#else
int (*action)();                        /* fread() or fwrite() */
#endif
FILE *fp;                               /* stream pointer */
{
    word am, t1, result;
    int n;

    if (member(buf, &am))               /* file not none */
    {
	if (fseek(fp, 0L, 1)) errsignal(RTEIOERR);      /* seek to current */
							/* position required */
	len = min(len, (M[ am ]-3)*sizeof(word));       /* check appetite */
	result = 0;                     /* number of bytes transfered */
	t1 = am+3;                      /* address in memory for transfer */
	while (len >= IOBLOCK)          /* transfer full blocks */
	{
	    n = (*action)((char *) &M[ t1 ], 1, IOBLOCK, fp);
	    result += n;
	    if (n != IOBLOCK) return(result);
	    len -= IOBLOCK;
	    t1 += IOBLOCK/sizeof(word);
	}
	if (len > 0)                    /* transfer last unfilled block */
	{
	    n = (*action)((char *) &M[ t1 ], 1, (int) len, fp);
	    result += n;
	}
	return(result);
    }
    else errsignal(RTEREFTN);
} /* end directio */

