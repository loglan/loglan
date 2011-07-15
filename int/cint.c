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

#include "depend.h"
#include "genint.h"
#include "int.h"
#include "process.h"
#include "intproto.h"

#if DLINK
#include "dlink.h"
#elif TCPIP
#include "tcpip.h"
#endif


/* IIUW LOGLAN-82 Executor                                            */
/* Written in PASCAL by P.Gburzynski and A.Litwiniuk.                 */
/* Modified by J.Findeisen, T.Przytycka, D.Szczepanska, B.Ciesielski. */
/* Hand translated to C by B. Ciesielski.                             */


#ifndef NO_PROTOTYPES
static void load(char *);
static void initiate(int,char **);
int main(int,char **);
#else
static void load();
static void initiate();
int main();
#endif


/* Macro to decode addressing modes : */
#define getargument(a, argnr)                                       \
    switch (eop->args[ argnr ])                                     \
    {                                                               \
        case GLOBAL     : a = M[ ic++ ];             break;         \
        case LOCAL      : a = c1+M[ ic++ ];          break;         \
        case TEMPLOCAL  : a = c2+M[ ic++ ];          break;         \
        case REMOTE     : a = M[ M[ ic+1 ] ]+M[ ic ];  ic+=2; break;\
        case INDIRECT   : a = M[ M[ ic++ ] ];                 break;\
        case IMMEDIATE  : a = ic++;                           break;\
        case CONSTANT  : a = M[ ic++ ];                       break;\
        case DOTACCESS : a = M[ display+M[ ic+1 ] ]+M[ ic ];  ic += 2; break;\
        case NOARGUMENT : return;                          \
    }


static void load(_filename)     /* Load code and prototypes from file */
   char *_filename;
{
    FILE *fp;
    char *cp;
    word n, left;
    char filename[100]; /* should suffice on all systems */

    strcpy( filename, _filename );

    M = mallocate(memorysize+1);        /* allocate main memory array */
    if (M == NULL) abend("Memory size too large (use /m option)\n");

    addext(filename, ".ccd");
    if ((fp = fopen(filename, BINARYREAD)) == NULL)
        abend("Cannot open .ccd file\n");

    ic = 0;              /* read static data and code */
    left = memorysize+1;               /* from .ccd file */
    do
    {
        if (left == 0) abend("Memory size too small (use /m option)\n");
        n = min(IOBLOCK/sizeof(word), left);
        n = fread((char *) &M[ ic ], sizeof(word), (int) n, fp);
        ic += n;
        left -= n;
    } while (n != 0);      /* now ic = number of words read */

    fclose(fp);
    /* Get various addresses passed by GENERATOR */
    ipradr    = M[ ic-5 ];           /* primitive type desctriptions */
    temporary = M[ ic-4 ];           /* global temporary variables */
    strings   = M[ ic-3 ];           /* string constants */
    lastprot  = M[ ic-2 ];           /* last prototype number */
    freem     = M[ ic-1 ];           /* first free word in memory */

    /* Read prototypes from .pcd file */
    addext(filename, ".pcd");
    if ((fp = fopen(filename, BINARYREAD)) == NULL)
        abend("Cannot open .pcd file\n");
    for (n = MAINBLOCK;  n <= lastprot;  n++ )
    {
        cp = ballocate(sizeof(protdescr));
        if (cp == NULL) abend("Memory size too large (use /m option)\n");
        prototype[ n ] = (protdescr *) cp;
        if (fread(cp, sizeof(protdescr), 1, fp) != 1)
            abend("Cannot read .pcd file\n");
    }
    fclose(fp);

    /* Open trace file */
    if (debug)
    {
        addext(filename, ".trd");
        if ((tracefile = fopen(filename, "w")) == NULL)
            abend("Cannot open .trd file\n");
    }
} /* end load */


static void initiate(argc, argv)        /* Establish configuration parameters */
int argc;
char **argv;
{
    long m;
    int c;
    char *filename=NULL;
/*
    fprintf(stderr,"\n LOGLAN-82  Concurrent Executor  Version 4.51\n");
    fprintf(stderr," January 21, 1993\n");
    fprintf(stderr,
            " (C) Copyright Institute of Informatics University of Warsaw\n");
    fprintf(stderr," (C) Copyleft LITA  Universite de Pau\n");

#if DLINK
    fprintf(stderr," D-LINK version 3.21\n\n");
#elif TCPIP
    fprintf(stderr," TCPIP version 0.9\n\n");
#else
    fprintf(stderr,"\n");
#endif
    fflush(stderr);
*/
#if DLINK
    ournode = net_logon(msginterrupt);
    if (ournode >= 0)      /* network driver installed */
        network = TRUE;
    else                          /* network driver not installed */
    {
        network = FALSE;
        ournode = 0;                  /* only node 0 is available */
    }
#else
    network = FALSE;
    ournode = 0;
#endif
    argc--,argv++;

    for( ; argc>0; argc--,argv++ ){
       if( filename != NULL )  usage();
       if( (*argv)[0]=='-' )
          switch( (*argv)[1] ){

             case 'i' :
               infmode = TRUE;
               break;

             case 'd' :
               debug = TRUE;
               break;

             case 'r' :
#if DLINK
               if (!network)
               abend("D-Link Network Driver Version 3.21 must be installed\n");
                argv++,argc--;
                if( argc==0 )  usage();
               if( sscanf( *argv, "%d", &c ) != 1 )  usage();
               if( c < 0 || c >= 255 || c == ournode )
                   abend("Invalid console node number\n");
               console = c;
               remote = TRUE;
#elif TCPIP
               argv++,argc--;
               if( argc==0 )  usage();
               if( sscanf( *argv, "%d", &c ) != 1 )  usage();
               if( c < 0 || c >= 255 )
                   abend("Invalid my console node number\n");
               ournode = console = c;
               argv++,argc--;
               if( argc==0 )  usage();
               /* here we test if we are remote */
               /* master will have number of slaves to wait for */
               /* slave - internet full address of master */
               if( strchr(*argv,':') ){
                   /* internet address of master nn.nn.nn.nn:port */
                   remote = TRUE;
                   tcpip_connect_to_master( *argv );
               }else{
                   /* # of slaves to wait for */
                   if( sscanf( *argv, "%d", &c ) != 1 )  usage();
                   if( c < 0  ||  c >= 254  )  usage();
                   tcpip_wait_for_slaves( c );
                   remote = FALSE;
               }
               puts("");
               network = TRUE;
#else
               usage();
#endif
               break;

             case 'm' :
                argv++,argc--;
                if( argc==0 )  usage();
               if (sscanf( *argv, "%ld", &m ) != 1) usage();
               if (m <= 0 || m > MAXMEMSIZE)
                   abend("Invalid memory size specified\n");
               memorysize = m;
               break;

             default :
           usage();
           break;

          }     /*  end of switch */
       else{  /* this is not option */
          if( filename != NULL )  usage();
          filename = *argv ;
       }
    }  /* end of for */

    if( filename!=NULL )
       load(filename);                     /* load code and prototypes */
    else
       usage();
}


void decode(){
    extopcode *eop;
    eop = (extopcode *)(M+ic);   /* pointer to extended opcode in M */
    lastic = ic;                     /* save ic for possible redecoding */
    ic += APOPCODE;
    opcode = ((int) eop->opcode ) & 0xFF ;
    getargument(a1, 0);
    getargument(a2, 1);
    getargument(a3, 2);
}


int main(argc, argv)
int argc;
char **argv;
{
    initiate(argc, argv);             /* initialize executor */
    runsys();              /* initialize running system */
    init_scheduler();
    setjmp(contenv);         /* set label for continue long jump */
    while (TRUE)                     /* repeat until exit() is called */
    {
        schedule();         /* reschedule current process */
        decode();               /* fetch instruction */
        execute();            /* and execute it */
    }
    return 0;
} /* end main */

