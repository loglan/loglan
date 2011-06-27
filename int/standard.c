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

#include "depend.h"
#include "genint.h"
#include "int.h"
#include "process.h"
#include "intproto.h"

#include	<math.h>
#include	<time.h>

/* Call standard procedure */

void standard(nrproc)			/* Process call to a standard proc. */
word nrproc;
{
    word t1, t2, t3, t5, t6;
    double r;
    bool absent;
    int ch, n;
    long tim;
    char *cp;
    FILE *fp;
    
    absent = FALSE;

#ifdef TRACE
    fprintf( stderr, "standard procedure %d\n", nrproc );
#endif

    switch ((int) nrproc)
    {
        case 1   : /* new array */
	    	newarry(param[ 1 ].xword, param[ 0 ].xword, param[ 2 ].xword,
	                &param[ 3 ].xvirt, &param[ 4 ].xword);
		break;

	case 2   : /* rew */
	case 3   : /* avf */
	case 4   : /* bsf */
	case 5   : /* weo */
	case 6   : /* putrec */
	case 7   : /* getrec */
	case 8   : /* ass */
	case 9   : /* assin */
	case 10  : /* assout */
	    	absent = TRUE;
		break;
	
	case 11  : /* unpack:function(s:string):arrayof char */
		t1 = strings+param[ 0 ].xword+1;
		t6 = M[ t1-1 ];		/* length of the string */
		if (t6 > 0)		/* string not null */
		{
		    newarry((word) 1, t6, (word) AINT, &param[ 1 ].xvirt, &t5);
		    t5 += 3;
		    cp = (char *) &M[ t1 ];
		    while (t6-- > 0)  M[ t5++ ] = *cp++;
		}
		else			/* null string */
		{
		    param[ 1 ].xvirt.addr = 0;
		    param[ 1 ].xvirt.mark = 0;
		}
		break;
		
	case 12  : /* random:function:real */
		param[ 0 ].xreal = (real)prandom();
		break;
		
	case 13  : /* time:function:integer */
		time(&tim);
		param[ 0 ].xword = tim;
		break;
		
	case 14  : /* sqrt:function(x:real):real */
		param[ 1 ].xreal = (real)sqrt((double) param[ 0 ].xreal);
		break;

	case 15  : /* entier:function(x:real):integer */
		param[ 1 ].xword = entier((double) param[ 0 ].xreal);
		break;
	
	case 16  : /* round:function(x:real):integer */
		param[ 1 ].xword = entier((double) (param[ 0 ].xreal+0.5));
		break;
	
	case 17  : /* unused */
	case 18  : /* intrinsic procedure */
		absent = TRUE;
		break;

	case 19  : /* imin:function(x, y:integer):integer */
		param[ 2 ].xword = min(param[ 0 ].xword, param[ 1 ].xword);
		break;

	case 20  : /* imax:function(x, y:integer):integer */
		param[ 2 ].xword = max(param[ 0 ].xword, param[ 1 ].xword);
		break;

	case 21  : /* imin3:function(x, y, z:integer):integer */
		t1 = min(param[ 0 ].xword, param[ 1 ].xword);
		param[ 3 ].xword = min(t1, param[ 2 ].xword);
		break;

	case 22  : /* imax3:function(x, y, z:integer):integer */
		t1 = max(param[ 0 ].xword, param[ 1 ].xword);
		param[ 3 ].xword = max(t1, param[ 2 ].xword);
		break;

	case 23  : /* sin:function(x:real):real */
		param[ 1 ].xreal = (real)sin((double) param[ 0 ].xreal);
		break;

	case 24  : /* cos:function(x:real):real */
		param[ 1 ].xreal = (real)cos((double) param[ 0 ].xreal);
		break;

	case 25  : /* tan:function(x:real):real */
		r = cos((double) param[ 0 ].xreal);
		if (r == 0.0) errsignal(RTEDIVBZ);
		param[ 1 ].xreal = (real)sin((double) param[ 0 ].xreal) / r;
		break;
		
	case 26  : /* exp:function(x:real):real */
		param[ 1 ].xreal = (real)exp((double) param[ 0 ].xreal);
		break;

	case 27  : /* ln:function(x:real):real */
		param[ 1 ].xreal = (real)log((double) param[ 0 ].xreal);
		break;

	case 28  : /* atan:function(x:real):real */
		param[ 1 ].xreal = (real)atan((double) param[ 0 ].xreal);
		break;

	case 29  : /* endrun:procedure */
		endrun(0);
		break;

	case 30  : /* ranset:procedure(x:real) */
		ranset();
		break;
		
	case 31  : /* clock */
	case 32  : /* option */
	case 33  : /* lock */
	case 34  : /* unlock */
	case 35  : /* sched, boy! */
	case 36  : /* date */
	case 37  : /* execpar */
	case 38  : /* test&set */
		absent = TRUE;
		break;

	case 39  : /* eof */
		param[ 0 ].xbool = lbool(testeof(stdin));		
		break;
		
	case 40  : /* eof(f) */
		loadfile((word) UNKNOWN, &t1, &t2, &fp);
		t3 = M[ t2+FSTAT ];
		if (t3 == READING || t3 == UPDATING)
		    param[ 0 ].xbool = lbool(testeof(fp));
		else errsignal(RTEILLIO);
		break;
		
	case 41  : /* readln */
		readln(stdin);
		break;
		
	case 42  : /* readln(f) */
		loadfile((word) READING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		readln(fp);
		break;
		
	case 43  : /* readchar */
		param[ 0 ].xword = getc(stdin);
		break;
		
	case 44  : /* readchar(f) */
		loadfile((word) READING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		if ((ch = getc(fp)) == EOF) errsignal(RTEIOERR);
		param[ 0 ].xword = ch;
		break;
		
	case 45  : /* readint */
		param[ 0 ].xword = readint(stdin);
		break;
	
	case 46  : /* readint(f) */
		loadfile((word) READING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		param[ 0 ].xword = readint(fp);
		break;
	
	case 47  : /* readreal */
		param[ 0 ].xreal = (real)readreal(stdin);
		break;

	case 48  : /* readreal(f) */
		loadfile((word) READING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		param[ 0 ].xreal = (real)readreal(fp);
		break;

	case 49  : /* getchar(f) */
		loadfile((word) READING, &t1, &t2, &fp);
		if (t1 != CHARF) errsignal(RTEILLIO);
		if ((ch = getc(fp)) == EOF) errsignal(RTEIOERR);
		param[ 0 ].xword = ch;
		break;
	
	case 50  : /* getint(f) */
		loadfile((word) READING, &t1, &t2, &fp);
		if (t1 != INTF) errsignal(RTEILLIO);
		n = fread((char *) &param[ 0 ].xword, sizeof(word), 1, fp);
		if (n != 1) errsignal(RTEIOERR);
		break;
		
	case 51  : /* getreal(f) */
		loadfile((word) READING, &t1, &t2, &fp);
		if (t1 != REALF) errsignal(RTEILLIO);
		n = fread((char *) &param[ 0 ].xreal, sizeof(real), 1, fp);
		if (n != 1) errsignal(RTEIOERR);
		break;

	case 52  : /* getobject(f) */
		absent = TRUE;
		break;

	case 53  : /* putchar(f) */
		loadfile((word) WRITING, &t1, &t2, &fp);
		if (t1 != CHARF) errsignal(RTEILLIO);
		ch = (char) param[ 0 ].xword;
		if (putc(ch, fp) == EOF) errsignal(RTEIOERR);
		break;
	
	case 54  : /* putint(f) */
		loadfile((word) WRITING, &t1, &t2, &fp);
		if (t1 != INTF) errsignal(RTEILLIO);
		n = fwrite((char *) &param[ 0 ].xword, sizeof(word), 1, fp);
		if (n != 1) errsignal(RTEIOERR);
		break;
	
	case 55  : /* putreal(f) */
		loadfile((word) WRITING, &t1, &t2, &fp);
		if (t1 != REALF) errsignal(RTEILLIO);
		n = fwrite((char *) &param[ 0 ].xreal, sizeof(real), 1, fp);
		if (n != 1) errsignal(RTEIOERR);
		break;
	
	case 56  : /* putobject(f) */
	case 57  : /* putstring(f) */
		absent = TRUE;
		break;

	case 58  : /* writeln(f) */
		loadfile((word) WRITING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		if (putc('\n', fp) == EOF) errsignal(RTEIOERR);
		if (fflush(fp)) errsignal(RTEIOERR);
		break;
	
	case 59  : /* writeln */
		putc('\n', stdout);
		break;
	
	case 60  : /* writechar(f) */
		loadfile((word) WRITING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		if (putc((char) param[ 0 ].xword, fp) == EOF) 
		    errsignal(RTEIOERR);
		break;
	
	case 61  : /* writechar */
		putc((char) param[ 0 ].xword, stdout);
		break;
	
	case 62  : /* writeint(f) */
		loadfile((word) WRITING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		writeint(param[ 0 ].xword, param[ 1 ].xword, fp);
		break;
	
	case 63  : /* writeint */
		writeint(param[ 0 ].xword, param[ 1 ].xword, stdout);
		break;
	
	case 64  : /* writereal0(f) */
	case 66  : /* writereal1(f) */
	case 68  : /* writereal2(f) */
		loadfile((word) WRITING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		writereal((double) param[ 0 ].xreal, param[ 1 ].xword,
			  param[ 2 ].xword, fp);
		break;
	
	case 65  : /* writereal0 */
	case 67  : /* writereal1 */
	case 69  : /* writereal2 */
		writereal((double) param[ 0 ].xreal, param[ 1 ].xword,
			  param[ 2 ].xword, stdout);
		break;
	
	case 70  : /* writestring(f) */
		loadfile((word) WRITING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		writestring(param[ 0 ].xword, param[ 1 ].xword, fp);
		break;
	
	case 71  : /* writestring */
		writestring(param[ 0 ].xword, param[ 1 ].xword, stdout);
		break;

	case 72  : /* open temporary file */
		genfileobj(TRUE , param[ 1 ].xword, tempfilename(),
		           &param[ 0 ].xvirt, &t1);
		break;

	case 73  : /* open external file */
		genfileobj(FALSE, param[ 1 ].xword, asciiz(&param[ 2 ].xvirt),
		           &param[ 0 ].xvirt, &t1);
		break;
		
	case 74  : /* eoln */
		param[ 0 ].xbool = lbool(testeoln(stdin));		
		break;
							
	case 75  : /* eoln(f) */
		loadfile((word) READING, &t1, &t2, &fp);
		if (t1 != TEXTF) errsignal(RTEILLIO);
		param[ 0 ].xbool = lbool(testeoln(fp));		
		break;
		
	case 76  : /* this coroutine */
		loadvirt(param[ 0 ].xvirt,
			 thisp->prochead+M[ thisp->prochead ]+CHD);
		break;

	case 77  : /* this process */
                {
                   procaddr p;
                   virtaddr v;
                   p.node = ournode;
                   p.pix  = thispix;
                   p.mark = thisp->mark;
                   mess2obj( thisp, &p, &v );
		   param[ 0 ].xvirt = v;
                }
		break;

	case 78  : /* reset:procedure(f:file) */
		if (member(&param[ 0 ].xvirt, &t2))
		    reset(t2);
		else errsignal(RTEREFTN);
		break;
		
	case 79  : /* rewrite:procedure(f:file) */
		if (member(&param[ 0 ].xvirt, &t2))
		    rewrite(t2);
		else errsignal(RTEREFTN);
		break;
	
	case 80  : /* unlink:procedure(f:file) */
		delete(&param[ 0 ].xvirt);
		break;

	case 81  : /* seek:procedure(f:file, offset, base:integer) */
		storevirt(param[ 0 ].xvirt, currfile);
		loadfile((word) UPDATING, &t1, &t2, &fp);
		if (t1 != DIRECT) errsignal(RTEILLIO);
		if (fseek(fp, (long) param[ 1 ].xword, (int) param[ 2 ].xword))
		    errsignal(RTEIOERR);
		break;

	case 82  : /* getrec(f, a, n) */
		loadfile((word) UPDATING, &t1, &t2, &fp);
		if (t1 != DIRECT) errsignal(RTEILLIO);
		param[ 1 ].xword = directio(
                                            &param[ 0 ].xvirt,
		                            param[ 1 ].xword,
                                            (int (*)())fread,
                                            fp
                                           );
		break;
		
	case 83  : /* putrec(f, a, n) */
		loadfile((word) UPDATING, &t1, &t2, &fp);
		if (t1 != DIRECT) errsignal(RTEILLIO);
		param[ 1 ].xword = directio(
                                            &param[ 0 ].xvirt,
		                            param[ 1 ].xword,
                                            (int (*)())fwrite,
                                            fp
                                           );
		break;
	
	case 84  : /* position:function(f:file):real */
		storevirt(param[ 0 ].xvirt, currfile);
		loadfile((word) UPDATING, &t1, &t2, &fp);
		if (t1 != DIRECT) errsignal(RTEILLIO);
		param[ 1 ].xword =(int) ftell(fp);
		break;

	case 98  : /* memavail:function:integer */
		param[ 0 ].xword = memavail();
		break;

	case 99  : /* exec:function(c:arrayof char):integer */
		cp = asciiz(&param[ 0 ].xvirt);
		param[ 1 ].xword = system(cp);
		free(cp);
		break;
		
	default	 :
		nonstandard(nrproc);
		break;
    }
#   if TRACE
    fflush( stdout );
#   endif
    if (absent) errsignal(RTEUNSTP);
}


