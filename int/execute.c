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

#include <assert.h>


/* Execute one L-code instruction */


void execute()
{
    word t1, t2;
    int i;
    real r;
    virtaddr virt1, virt2, virt3;

#ifdef TRACE
    fprintf(stderr,"pix %d,ic %d,opcode %d\n",thispix,ic,opcode);fflush(stderr);
#endif

    switch (opcode)
    {
    	case 1   : /* LOPENRC */
		openrc(a3, &virt2, &t2);
		storevirt(virt2, a1);
		M[ a2 ] = t2;
		break;
	
	case 2   : /* LBACKADDR */
		storevirt(thisp->backobj, a1);
		M[ a2 ] = M[ temporary ];
		break;
	
	case 3   : /* LRAISE */
		ic++;			/* skip the address */
		raise_signal(a3, M[ ic-1 ], &t1, &t2);
		M[ a1 ] = t1;
		M[ a2 ] = t2;
		break;
	
	case 4   : /* LOPEN */
		openobj(M[ a3 ], &t1, &t2);
		M[ a1 ] = t1;
		M[ a2 ] = t2;
		break;
	
	case 5   : /* LSLOPEN */
		loadvirt(virt3, a3);
		slopen(M[ a3+APREF ], &virt3, &t1, &t2);
		M[ a1 ] = t1;
		M[ a2 ] = t2;
		break;

	case 15  : /* LTHIS */
		virt1.addr = M[ display2+a2 ];
		virt1.mark = M[ virt1.addr+1 ];
		storevirt(virt1, a1);
		break;

	case 20  : /* LVIRTDISPL */
		t2 = M[ display+a2 ];
		t1 = M[ t2+PROTNUM ];
		M[ a1 ] = M[ prototype[ t1 ]->virtlist+a3 ];
		break;

	case 21  : /* LSTATTYPE */
		M[ a1 ] = a2;
		M[ a1+1 ] = a3;
		break;

	case 23  : /* LIPAROUT */
		M[ a1 ] = param[ a3 ].xword;
		break;

	case 24  : /* LRPAROUT */
		MR(a1) = param[ a3 ].xreal;
		break;

	case 25  : /* LVPAROUT */
		storevirt(param[ a3 ].xvirt, a1);
		break;

	case 31  : /* LSIGN */
		if (M[ a2 ] == 0) M[ a1 ] = 0;
		else
		    if (M[ a2 ] < 0) M[ a1 ] = -1;
		    else M[ a1 ] = 1;
		break;
			
	case 33  : /* LLOWER */
	case 34  :
		loadvirt(virt2, a2);
		if (member(&virt2, &t1))
		{
		    switch ((int) M[ t1+PROTNUM ])
		    {
		        case AINT  :  t2 = APINT;   break;
			case AREAL :  t2 = APREAL;  break;
			case AVIRT :  t2 = APREF;   break;
		    }
		    M[ a1 ] = (M[ t1+2 ]+3)/t2;
		}
		else errsignal(RTEREFTN);
		break;
	
	case 35  : /* LUPPER */
	case 36  :
		loadvirt(virt2, a2);
		if (member(&virt2, &t1))
		{
		    switch ((int) M[ t1+PROTNUM ])
		    {
		        case AINT  :  t2 = APINT;   break;
			case AREAL :  t2 = APREAL;  break;
			case AVIRT :  t2 = APREF;   break;
		    }
		    M[ a1 ] = (M[ t1+2 ]+M[ t1 ])/t2-1;
		}
		else errsignal(RTEREFTN);
		break;
	
	case 40  : /* LGETTYPE */
		typep(M[ a2 ], a3, &virt1.addr, &virt1.mark);
		storevirt(virt1, a1);
		break;
	
	case 41  : /* LCOPY */
		loadvirt(virt2, a2);
		copy(&virt2, &virt1);
		storevirt(virt1, a1);
		break;
	
	case 42  : /* LNOT */
		M[ a1 ] = ~ M[ a2 ];
		break;

	case 43  : /* LRCVAVIRT */	/* recover virtual address from ah */
		virt1.addr = M[ a2 ];
		virt1.mark = M[ virt1.addr+1 ];
		storevirt(virt1, a1);
		break;

	case 44  : /* LVIRTDOT */
	case 45  :
		M[ a1 ] = M[ prototype[ M[ temporary ] ]->virtlist+a2 ];
		break;

	case 46  : /* LADDRPH */
	case 47  : /* LADDRPH2 */
		loadvirt(virt2, a2);
		if (!member(&virt2, &M[ a1 ])) errsignal(RTEREFTN);
		break;
	
	case 48  : /* LIABS */
		t2 = M[ a2 ];
		M[ a1 ] = absolute(t2);
		break;
	
	case 49  : /* LINEG */
		M[ a1 ] = -M[ a2 ];
		break;
	
	case 50  : /* LRABS */
		r = MR(a2);
                if( r < (real)0.0 )
		   r=(real)0.0-r;
		MR(a1) = r;
		break;
		
	case 51  : /* LRNEG */
		MR(a1) = -MR(a2);
		break;

	case 52  : /* LPARAMADDR */
	 	t2 = M[ a2 ];
		M[ a1 ] = t2+M[ prototype[ M[ t2+PROTNUM ] ]->parlist+a3 ];
		break;

	case 54  : /* LLOADT */
		t1 = M[ ic++ ];		/* offset */
		t2 = t1+loadt(M[ M[ a2 ] ], a3);  /* object address */
		loadvirt(virt1, t2);
		storevirt(virt1, a1);
		break;
	
	case 55  : /* LIS */
		loadvirt(virt2, a2);
		M[ a1 ] = lbool(is(&virt2, a3));
		break;
	
	case 56  : /* LIN */
		loadvirt(virt2, a2);
		M[ a1 ] = lbool(inl(&virt2, a3));
		break;
	
	case 57  : /* LQUA */
		loadvirt(virt2, a2);
		if (member(&virt2, &M[ a1 ]))
		    qua(&virt2, a3);
		else errsignal(RTEREFTN);
		break;

	case 58  : /* LIFIX */
		M[ a1 ] = (word)( MR(a2) );
		break;
	
	case 59  : /* LFLOAT */
		MR(a1) = (real)( M[ a2 ] );
		break;
	
	case 60  : /* LIMOVE */
		M[ a1 ] = M[ a2 ];
		break;
	
	case 61  : /* LVMOVE */
		loadvirt(virt1, a2);
		storevirt(virt1, a1);
		break;
 	
	case 62  : /* LRMOVE */		/* WARNING: these areas may overlap! */
		r = MR(a2);
		MR(a1) = r;
		break;

	case 63  : /* LFPMOVE */	/* WARNING: these areas may overlap! */
		loadvirt(virt1, a2);	/* MACHINE DEPENDENT */
		t1 = M[ a2+2 ];
		storevirt(virt1, a1);
		M[ a1+2 ] = t1;
		break;

	case 82  : /* LEQNONE */
		M[ a1 ]	= lbool(M[ a2+1 ] != M[ M[ a2 ]+1 ]);
		break;
		
	case 83  : /* LNENONE */
		M[ a1 ]	= lbool(M[ a2+1 ] == M[ M[ a2 ]+1 ]);
		break;
		
	case 87  : /* LMDFTYPE */	/* modify the formal type */
		loadvirt(virt1, a2);
		virt1.addr += a3;	/* number of "arrayof" */
		storevirt(virt1, a1);
		break;

	case 100 : /* LOR */
		M[ a1 ] = M[ a2 ] | M[ a3 ];
		break;
		
	case 101 : /* LAND */
		M[ a1 ] = M[ a2 ] & M[ a3 ];
		break;

	case 102 : /* LARRAY */
	case 103 :
	case 104 :
		loadvirt(virt2, a2);
		if (member(&virt2, &t2))
		{
		    t1 = M[ a3 ]-M[ t2+2 ];	/* index-lower+3 */
		    if (t1 < 3 || t1 >= M[ t2 ]) errsignal(RTEINVIN);
		    else M[ a1 ] = t2+t1;
		}
		else errsignal(RTEREFTN);
		break;
		
	case 105 : /* LFARRAY */	/* without any tests */
		t1 = M[ M[ a2 ] ];	/* physical address */
		M[ a1 ] = t1+M[ a3 ]-M[ t1+2 ];
		break;
		
	case 106 : /* LIEQUAL */
		M[ a1 ] = lbool(M[ a2 ] == M[ a3 ]);
		break;
				
	case 107 : /* LINEQUAL */
		M[ a1 ] = lbool(M[ a2 ] != M[ a3 ]);
		break;
				
	case 108 : /* LILT */
		M[ a1 ] = lbool(M[ a2 ] < M[ a3 ]);
		break;
				
	case 109 : /* LILE */
		M[ a1 ] = lbool(M[ a2 ] <= M[ a3 ]);
		break;
				
	case 110 : /* LIGT */
		M[ a1 ] = lbool(M[ a2 ] > M[ a3 ]);
		break;
				
	case 111 : /* LIGE */
		M[ a1 ] = lbool(M[ a2 ] >= M[ a3 ]);
		break;
				
	case 112 : /* LCOMBINE */
		loadvirt(virt2, a2);
		t1 = M[ a3 ];
		storevirt(virt2, a1);
		M[ a1+APREF ] = t1;
		break;
		
	case 113 : /* LIADD */
		M[ a1 ] = M[ a2 ]+M[ a3 ];
		break;
	
	case 114 : /* LISUB */
		M[ a1 ] = M[ a2 ]-M[ a3 ];
		break;
	
	case 115 : /* LIMULT */
		M[ a1 ] = M[ a2 ] * M[ a3 ];
		break;
	
	case 116 : /* LSHIFT */
		M[ a1 ] = shift(M[ a2 ], M[ a3 ]);
		break;
		
	case 117 : /* LIDIVE */
		if (M[ a3 ] == 0) errsignal(RTEDIVBZ);
		else M[ a1 ] = M[ a2 ] / M[ a3 ];
		break;
	
	case 118 : /* LIMODE */
		if (M[ a3 ] == 0) errsignal(RTEDIVBZ);
		else M[ a1 ] = M[ a2 ] % M[ a3 ];
		break;

	case 119 : /* LRADD */
		MR(a1) = MR(a2)+MR(a3);
		break;

	case 120 : /* LRSUB */
		MR(a1) = MR(a2)-MR(a3);
		break;

	case 121 : /* LRMULT */
		MR(a1) = MR(a2) * MR(a3);
		break;

	case 122 : /* LRDIVE */
		if (MR(a3) == (real)0.0) errsignal(RTEDIVBZ);
		else MR(a1) = MR(a2) / MR(a3);
		break;

	case 123 : /* LEQREF */
		loadvirt(virt2, a2);
		loadvirt(virt3, a3);
		if (member(&virt2, &t1))
		    M[ a1 ] = lbool(member(&virt3, &t2) && t1 == t2);
		else M[ a1 ] = lbool(!member(&virt3, &t2));
		break;
	
	case 124 : /* LNEREF */
		loadvirt(virt2, a2);
		loadvirt(virt3, a3);
		if (member(&virt2, &t1))
		    M[ a1 ] = lbool(!member(&virt3, &t2) || t1 != t2);
		else M[ a1 ] = lbool(member(&virt3, &t2));
		break;
				
	case 125 : /* LREQ */
		M[ a1 ] = lbool(MR(a2) == MR(a3));
		break;
				
	case 126 : /* LRNE */
		M[ a1 ] = lbool(MR(a2) != MR(a3));
		break;
				
	case 127 : /* LRLT */
		M[ a1 ] = lbool(MR(a2) < MR(a3));
		break;
				
	case 128 : /* LRLE */
		M[ a1 ] = lbool(MR(a2) <= MR(a3));
		break;
				
	case 129 : /* LRGT */
		M[ a1 ] = lbool(MR(a2) > MR(a3));
		break;
				
	case 130 : /* LRGE */
		M[ a1 ] = lbool(MR(a2) >= MR(a3));
		break;
				
	case 131 : /* LXOR */
		M[ a1 ] = M[ a2 ] ^ M[ a3 ];
		break;

	case 132 : /* LCALLPROCSTAND */
#if USE_ALARM
                alarm(0);     /* reschedule forced so alarm may be switched off */
#endif
      reschedule=TRUE;
		standard(a1);
		break;

	case 143 : /* LKILL */
		loadvirt(virt1, a1);
		disp(&virt1);
		break;

	case 144 : /* LHEADS */
		loadvirt(virt1, a1);
		heads(&virt1, a2);
		break;

	case 145 : /* LIPARINP */
		param[ a3 ].xword = M[ a1 ];
		break;
	
	case 146 : /* LGKILL */
		loadvirt(virt1, a1);
		gkill(&virt1);
		break;

	case 147 : /* LVPARINP */
		loadvirt(param[ a3 ].xvirt, a1);
		break;
	
	case 148 : /* LRPARINP */
		param[ a3 ].xreal = MR(a1);
		break;

	case 149 : /* LQUATEST */
		loadvirt(virt1, a1);
		qua(&virt1, a2);
		break;
	
	case 150 : /* LSTYPE */
		loadvirt(virt1, a1);
		typref(&virt1, a2);
		break;
	
	case 151 : /* LIFFALSE */
		if (M[ a1 ] == LFALSE) ic = a2;
		break;
	
	case 152 : /* LIFTRUE */
		if (M[ a1 ] == LTRUE) ic = a2;
		break;
	
	case 159 : /* LGO */
		go(M[ a2 ], M[ a1 ]);
		break;
	
	case 160 : /* LGOLOCAL */
		goloc(M[ a2 ], M[ a1 ]);
		break;

	case 170 : /* LDTYPE */
		loadvirt(virt1, a1);	/* left side type */
		loadvirt(virt2, a2);
		loadvirt(virt3, a3);	/* right side type */
		typed(virt1.addr, virt1.mark, virt3.addr, virt3.mark, &virt2);
		break;
		
	case 172 : /* LTERMINATE */
		term();
		break;
	
	case 173 : /* LWIND */
		wind();
		break;

	case 174 : /* LBLOCK2 */
		goloc(thisp->blck1, thisp->blck2);
		break;
	
	case 176 : /* LBLOCK3 */
		disp(&thisp->backobj);
		break;
			
	case 177 : /* LTRACE */
		trace(a1);
		break;

	case 178 : /* LINNER */
		inner(a1);
		break;

	case 180 : /* LBACKHD */
		backhd(&thisp->backobj, &M[ temporary ]);
		break;
	
	case 182 : /* LJUMP */
		ic = a1;
		break;

	case 186 : /* LBLOCK1 */
		openobj(a1, &thisp->blck1, &thisp->blck2);
		break;
		
	case 187 : /* LDETACH */
		detach();
		break;
	
	case 188 : /* LATTACH */
		loadvirt(virt1, a1);
		attach(&virt1);
		break;
		
	case 191 : /* LBACKBL */
		backbl(&thisp->backobj, &M[ temporary ]);
		break;
			
	case 192 : /* LBACKPR */
	     /* backpr(&thisp->backobj, &M[ temporary ]); */
		back(&thisp->backobj, &M[ temporary ], (word) 0);
		break;
			
	case 193 : /* LBACK */
		back(&thisp->backobj, &M[ temporary ], (word) 0);
		break;

	case 194 : /* LFIN */
		fin(ic-APOPCODE, &thisp->backobj, &M[ temporary ]);
		break;
	
	case 195 : /* LCASE */
		/* a2 = address of case description : */
		/* minimal value, number of branches, */
		/* remaining branches followed by "otherwise" code */
		t1 = M[ a1 ]-M[ a2 ];	/* in 0..number of branches-1 */
		if (t1 < 0 || t1 >= M[ a2+1 ])
		    ic = a2+2+M[ a2+1 ];  /* otherwise */
		else
		    ic = M[ a2+2+t1 ];	/* indirect jump */
		break;

	case 220 : /* LRESUME */
		loadvirt(virt1, a1);
		resume(&virt1);
		break;

	case 221 : /* LSTOP */
		passivate(STOPPED);
		break;

	case 222 : /* LKILLTEMP */
		disp(&thisp->template);
		break;

        case 223 : /* LENABLE */
        	for (i = 0;  i < a1;  i++)
        	    enable(thispix, virtprot(M[ ic++ ]));
        	evaluaterpc(thispix);
		break;

        case 224 : /* LDISABLE */
        	for (i = 0;  i < a1;  i++)
        	    disable(thispix, virtprot(M[ ic++ ]));
		break;

        case 225 : /* LACCEPT1 */
        	rpc_accept(a1);
		break;

	case 226 : /* LACCEPT2 */
		popmask(thispix);
		rpc3();
		break;

	case 227 : /* LBACKRPC */
		back(&thisp->backobj, &M[ temporary ], a1);
		break;

	case 228 : /* LASKPROT */
		loadvirt(virt1, a1);
		askprot(&virt1);
		break;

        case 240 : /* LSTEP */
		if (M[ a1 ] < 0) errsignal(RTENEGST);
		break;

	default  :
		fprintf( stderr, "Invalid opcode\n" );
		errsignal(RTESYSER);
		break;
    }

}


