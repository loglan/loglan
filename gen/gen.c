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

#include "glodefs.h"


void gen()
{ address aftraise ;
  addrmode md ;
  address t1, t2 ;
  b32b16c trick ;
  int i ;
  quadruple * curr1 ;
  args_struct * curr2 ;
  int l ;

  for (qcurr = 1; qcurr <= qlast; qcurr++)
  { curr1 = tuple + qcurr ; /* gsg for PASCAL WITH translation */
    /* gsg WITH beginning */   
       defaultargs();
       switch (curr1->opcode) {


/*CBC... Fixed bug - added calls of ARGUMENT to release global temporary
         variables in case of no further references to them */

case      1   /* #LOPENRC */:
               forceprot(3);
               emit();
               argument(1);
               argument(2);
               break;

case      2   /* #LBACKADDR */:
               emit();
               argument(1);
               argument(2);
               break;

/*...CBC*/
case    3   /* #LRAISE */:
               emit();
               aftraise = fre; 
               fre++; /* this cell is to be filled further */
               break;
            
case   11 : 
              curr1->opcode = 60 ; /* #limove */ 
              force(2,IMMEDIATE,(address)0,(address)0); 
              emit() ;
              break;
case   12 : 
              curr1->opcode= 61 ; /* #lvmove */ 
              force(2,GLOBAL,realbase /* none */,(address)0);
              emit() ;
              break;
            
case   13 :  
              curr1->opcode= 60 ; /* #limove */ 
              force(2,GLOBAL,temporary,(address)0); 
              emit() ;
              break;
             
            /* M [ TEMPORARY ] STANDS FOR ANY REGISTER */
case   15 : /* #LTHIS */  
case   20 :  /* #LVIRTDISPL */

              forceprot(2); 
              emit() ;
              break;


 case  16 : 
              curr1->opcode= 60 ; /* #limove */ 
              forceprot(2); 
              args[ 2 ].mode=IMMEDIATE; 
              emit() ;
              break ;

case  21   /* #LSTATTYPE */: 
              args[ 3 ].off1= - ipmem[ args[ 3 ].off1 + 2 ];
              emit() ;
              break;

case   22 :  /* FETCH FORMAL TYPE THROUGH THE DISPLAY */
              curr1->opcode= 61 ; /* #lvmove */
              force(2,DOTACCESS, ipmem[ curr1->arg[ 3 ]-2 ] /*offset*/,
                 ipmem[ curr1->arg[ 3 ]-1 ] /* +display */ /*prot*/);
              args[ 3 ].mode=NOARGUMENT; 
              emit() ;
              break;
             

case   23 : 
             notrick =ipmem[ curr1->arg[ 1 ] ];
             switch(sap(notrick))
             {
               case   APINT : break;
               case   APVIRT : curr1->opcode = 25 ; /* #lvparout */
                               break;
               case   APREAL : curr1->opcode=24 ; /* #lrparout */
                               break;
             } /* switch */
             emit() ;
             break;
        
case  29 :
case  30 :
case 133 : generror(NOTIMPL);
           break;

case  32 :
           curr1->opcode = 113 ; /* #liadd */ 
           force(3,IMMEDIATE,(address)1,(address)0);
           emit()  ;
           break ;

case  37 :
case  39 : 
          curr1->opcode= 113 ; /* #liadd */ 
          args[ 3 ].mode=IMMEDIATE; 
          emit() ;
          break ;
       
case  38 :  /* MOVE & SAVE */
               notrick  =ipmem[ curr1->arg[ 1 ] ] ;
               switch(sap(notrick))
               {
                 case   APINT : curr1->opcode= 60 ; /* #limove */
                                break ;
                 case  APREAL : curr1->opcode= 62 ; /* #lrmove */
                                break ;
                 case  APVIRT : curr1->opcode= 61 ; /* #lvmove */
                                break ;
               } /* switch */
               emit();
               break ;

case    54   /* #LLOADT */: 
               forceprot(3);
               emit();
               m[ fre ]=ipmem[ curr1->arg[ 3 ]-2 ]; /* offset */
               fre+=APINT;
               break ;
       
case    53 :  /* SHIFT BY CONSTANT NUMBER OF POSITIONS */
               curr1->opcode= 116 ; /* #lshift */
               args[ 3 ].mode=IMMEDIATE;
               emit();
               break ;

case   55 :  /* #LIS */
case   56 :  /* #LIN */
case   57 :  /* #LQUA */
        
              /*WITH ARGS[ 3 ] DO */
              curr2 = args + 3 ;
              curr2->off1 = 
                                  - ipmem[ curr2->off1 + 2 ];
                    /* ADDRESS OF TYPE DESCRIPTION */
                emit() ;
                break ;

case  149   /* #LQUATEST */:
            
              args[ 2 ].off1= - ipmem[ args[ 2 ].off1 + 2 ];
              /* ADDRESS OF TYPE DESCRIPTION */
              emit() ;
            break ;

case       60   /* #LIMOVE */:

              notrick  = ipmem[ curr1->arg[ 1 ] ];
              switch (sap(notrick)) {
                    case APINT : break ;
                   case APREAL : curr1->opcode = 62 ; /* #LRMOVE */ break ;
                   case APVIRT : curr1->opcode = 61 ; /* #LVMOVE */ break ;
                 case APFMPROC : curr1->opcode = 63 ; /* #LFPMOVE */ break ;
              } /* CASE */;
              emit() ;
            break ;
     
       case 61 : 
              curr1->opcode= 60 ; /* #limove */ 
         args[ 2 ].mode=INDIRECT; 
         emit(); 
       break ;
     
      case 62 :  
             curr1->opcode= 61 ; /* #lvmove */ 
        args[ 2 ].mode=INDIRECT; 
        emit(); 
      break ;

      case 63 : 
             curr1->opcode= 63 ; /* #lfpmove */ 
        args[ 2 ].mode=INDIRECT;
        emit(); 
      break ;

      case 64 :  
             curr1->opcode= 115 ; /* #limult */ 
        force(3,IMMEDIATE,(address)2,(address)0); 
        emit() ;
      break ;
     
      case 65 :  
             curr1->opcode= 115 ; /* #limult */ 
        force(3,IMMEDIATE,(address)3,(address)0); 
        emit() ;
      break ;

      case 66 :  
             curr1->opcode= 115 ; /* #limult */ 
        force(3,IMMEDIATE,(address)4,(address)0);
        emit() ;
      break ;
     
      case 67 : 
             curr1->opcode= 115 ; /* #limult */ 
        force(3,IMMEDIATE,(address)5,(address)0);
        emit() ;
      break ;

      case 68 : 
             curr1->opcode= 115 ; /* #limult */ 
             force(3,IMMEDIATE,(address)6,(address)0); 
             emit() ;
           break ;
     
      case 69 :  
             curr1->opcode= 115 ; /* #limult */ 
        force(3,IMMEDIATE,(address)7,(address)0); 
        emit() ;
      break ;

      case 70 : 
             curr1->opcode= 115 ; /* #limult */ 
        force(3,IMMEDIATE,(address)8,(address)0); 
        emit() ;
      break ;

      case 71 :  
             curr1->opcode= 115 ; /* #limult */ 
        force(3,IMMEDIATE,(address)9,(address)0); 
        emit() ;
      break ;

      case 72 :  
             curr1->opcode= 115 ; /* #limult */ 
        force(3,IMMEDIATE,(address)10,(address)0); 
        emit() ;
      break ;

      case 73 : 
             curr1->opcode= 117 ; /* #lidive */ 
        force(3,IMMEDIATE,(address)8,(address)0);
        emit() ;
      break ;

      case 74 : 
             curr1->opcode= 117 ; /* #lidive */
        force(3,IMMEDIATE,(address)4,(address)0); 
        emit() ;
      break ;

      case 75 :  
             curr1->opcode= 117 ; /* #lidive */ 
        force(3,IMMEDIATE,(address)2,(address)0); 
        emit() ;
      break ;
    
      case 76 : 
      case 77 :
      case 78 :
      case 79 :
      case 80 :
      case 81 :
            
             curr1->opcode = 106 + /* #liequal */(curr1->opcode-76); 
        force(3,IMMEDIATE,(address)0,(address)0); 
        emit() ;
      break ;

      case 84 : 
             curr1->opcode= 60 ; /* #limove */
               args[ 2 ].mode=REMOTE; args[ 2 ].off2=args[ 2 ].off1; args[ 2 ].off1=ipmem[ curr1->arg[ 3 ]-2 ];
             args[ 3 ].mode=NOARGUMENT;
             emit();
           break ;

      case 85 :  
             curr1->opcode= 61 ; /* #lvmove */
          args[ 2 ].mode=REMOTE; 
          args[ 2 ].off2=args[ 2 ].off1; 
          args[ 2 ].off1=ipmem[ curr1->arg[ 3 ]-2 ];
             args[ 3 ].mode=NOARGUMENT;
             emit();
           break ;

       case 86 : 
              curr1->opcode= 63 ; /* #lfpmove */
                args[ 2 ].mode=REMOTE;
      args[ 2 ].off2=args[ 2 ].off1;
      args[ 2 ].off1=ipmem[ curr1->arg[ 3 ]-2 ];
              args[ 3 ].mode=NOARGUMENT;
              emit();
            break ;

       case 88 :
       case 89 :
       case 90 :
       case 91 :
       case 92 :
       case 93 :
             
         curr1->opcode= 106 + /* #liequal */(curr1->opcode-88); 
              args[ 3 ].mode=IMMEDIATE; 
         emit() ;
       break ;

       case 94 :
       case 95 :
       case 96 :
       case 97 :
       case 98 :
       case 99 :
             
         curr1->opcode= 106 + /* #liequal */(curr1->opcode-94); 
         args[ 3 ].mode=IMMEDIATE; 
         emit() ;
       break ;
     
      case 137 :  
              curr1->opcode= 60 ; /* #limove */
              force(1,REMOTE,ipmem[ curr1->arg[ 2 ]-2 ],args[ 1 ].off1);
              force(2,IMMEDIATE,(address)0,(address)0);
              emit();
            break ;

      case 138 : 
              curr1->opcode= 61 ; /* #lvmove */
              force(1,REMOTE,ipmem[ curr1->arg[ 2 ]-2 ],args[ 1 ].off1);
              force(2,GLOBAL,realbase,(address)0); /* none */
              emit();
            break ;

      case 139 : if (curr1->arg[2] == -45) { /* file address */
              curr1->opcode = 61; 
              args[2] = args[1];
              force(1,GLOBAL,(address)CURRFILE,(address)0);
              emit() ;
            } else   /*dsw*/  
            {
              curr1->opcode= 60 ; /* #limove */ 
              args[ 2 ]=args[ 1 ];
              force(1,GLOBAL,temporary,(address)0); emit() ;
             }
            break ;

      case 140 :
      case 158 :
      case 176 :
      case 179 :
      case 195 :  break ;

      case 141 : 
              notrick  =ipmem[ curr1->arg[ 1 ] ];
              locrelease(args[ 1 ].off1, sap(notrick));
            break ;

      case 145 :
              notrick  =ipmem[ curr1->arg[ 1 ] ];
              switch (sap(notrick)) {
                case APINT : break ;
                case APVIRT : curr1->opcode= 147 ; /* #lvparinp */ break ;
                case APREAL : curr1->opcode=148 ; /* #lrparinp */ break ;
              } /* case */
              emit();
            break ;
     
      case 147 :  
              curr1->opcode= 60 ; /* #limove */
              args[ 1 ].mode=INDIRECT;
              force(2,IMMEDIATE,(address)0,(address)0);
              emit();
            break ;
 
      case 148 : 
              curr1->opcode= 61 ; /* #lvmove */
              args[ 1 ].mode=INDIRECT;
              args[ 2 ].mode=GLOBAL;
              args[ 2 ].off1=realbase; /* none */
              emit();
            break ;
      
      case 150   /* #lstype */:
            args[ 2 ].off1= - ipmem[ args[ 2 ].off1 + 2 ];
         emit() ;
       break ;

      case 152   /* #liftrue */ :
      case 151   /* #liffalse */ :
      case 182   /* #ljump */:
            
              emit();
              fre -- ; 
              uselabel(m[ fre ]);
              fre ++ ;
            break ;

      case 153 :  /* kill after raise */
              m[ aftraise ]= fre + base;
              curr1->opcode= 143 ; /* #lkill */
              emit();
            break ;
      
      case 161 : 
              curr1->opcode= 60 ; /* #limove */
              args[ 1 ].mode=INDIRECT; 
              emit();
            break ;

      case 162 :  
              curr1->opcode= 61 ; /* #lvmove */ 
              args[ 1 ].mode=INDIRECT; 
              emit();
            break ;

      case 163 :  
              curr1->opcode= 63 ; /* #lfpmove */ 
              args[ 1 ].mode=INDIRECT; 
              emit() ;
              break ;

      case 164 :  
              curr1->opcode= 60 ; /* #limove */
              args[ 1 ].mode=REMOTE;
              args[ 1 ].off2=args[ 1 ].off1;
              args[ 1 ].off1=ipmem[ curr1->arg[ 3 ]-2 ]; /* offset */
              args[ 3 ].mode=NOARGUMENT;
              emit();
            break ;

      case 165 : 
              curr1->opcode= 61 ; /* #lvmove */
              args[ 1 ].mode=REMOTE;
              args[ 1 ].off2= args[ 1 ].off1;
              args[ 1 ].off1=ipmem[ curr1->arg[ 3 ]-2 ]; /* offset */
              args[ 3 ].mode=NOARGUMENT;
              emit();
            break ;
    
      case 166 : 
              curr1->opcode= 63 ; /* #lfpmove */
              args[ 1 ].mode=REMOTE;
              args[ 1 ].off2=args[ 1 ].off1;
              args[ 1 ].off1=ipmem[ curr1->arg[ 3 ]-2 ]; /* offset */
              args[ 3 ].mode=NOARGUMENT;
              emit(); 
            break ;
   
     case 174 : /* lastwill */
             /* printf("fre = %d , base = %d\n", fre, base) ;*/
             prototype[ unitt ]->lastwill = fre + base;
             t1=locspace(APVIRT);
             t2=locspace(APINT);
             curr1->opcode=2;              /* lbackaddr */
             force(1, TEMPLOCAL, t1, (address)0);
             force(2, TEMPLOCAL, t2, (address)0);
             emit();
             locrelease(t2, APINT);
             curr1->opcode=146;            /* lgkill */
             force(1, TEMPLOCAL, t1, (address)0);
             force(2, NOARGUMENT, (address)0, (address)0);
             emit();
             locrelease(t1, APVIRT);
             break ;
  
    case 175 : 
             curr1->opcode= 182 ; /* #ljump */
             force(1,CONSTANT,
                  prototype[ ipmem[ curr1->arg[ 1 ]-1 ] ]->lastwill,(address)0);
             emit();
             break ;

    case 178 :  /* inner */
                emit();

#if SMALL || HUGE
            ipmem[ ipunit ] = fre + base; /* ADDRESS OF AFTER INNER STATEMENT */
#elif LARGE
            trick.t.b32 = fre+base;
            ipmem[ ipunit   ] = trick.f.r16;
            ipmem[ ipunit+1 ] = trick.f.l16;
#endif

            mapdscr[ unitt ] = (tmpmapdscr *) new(mapdscr[ unitt ]);
/*          mapdscr[ unitt ]->map = ltmpmap ; */
            for(l = 0; l <= MAXLOCTEMP; l++)
              mapdscr[unitt]->map[l] = ltmpmap[l] ;
            break ;
   
    case 181 : deflabel(curr1->arg[ 1 ]);
               break ;

    case 183 :    /* JUMP AFTER INNER */
                curr1->opcode= 182 ; /* #LJUMP */

#if SMALL || HUGE
            args[ 1 ].off1 = ipmem[ curr1->arg[ 1 ] ];
#elif LARGE
            trick.f.r16 = ipmem[ curr1->arg[1]   ];
            trick.f.l16 = ipmem[ curr1->arg[1]+1 ];
            args[ 1 ].off1 = trick.t.b32;
#endif

            emit();
            break ;

    case 184 : begunit(curr1->arg[ 1 ]);
          break ;

    case 185 : endunit() ;
          break ;

    case 186 :  /* BLOCK */
       /* EXTRA : 186,174,176 */
            args[ 1 ].off1=ipmem[ curr1->arg[ 1 ]-1 ];
            emit(); /* open object for block */
            curr1->opcode=174;
            args[ 1 ].mode=NOARGUMENT;
            emit(); /* TRANSMIT CONTROL */
            curr1->opcode=176;
            emit(); /* KILL BLOCK OBJECT */
       break ;

     case 189 :  /* CASE */
             curr1->opcode=195;
             args[ 3 ].mode=NOARGUMENT;
             emit();
             fre -- ;
             uselabel(curr1->arg[ 2 ]);     /* ADDRESS OF 'CASE' DESCRIPTION */
             fre ++ ;
             break ;

    case 190 : esac() ;
               break ;

    case 223 : /* #LENABLE */ 
    case 224 : /* #LDISABLE */
    case 225 : /* #LACCEPT1 */
    case 227 : /* #LBACKRPC */

            forceconst(1);
            emit();
            if (fre+ curr1->arg[ 1 ] >= firstlabel)
              generror(MEMOVF);
            for (i=1; i <= curr1->arg[ 1 ]; i++)
              m[ fre + i - 1 ] = proclist[ i ];
            fre += curr1->arg[ 1 ];
            break ;

/*CBC... */
/* 2 ,*/ /* #LBACKADDR */
/*...CBC*/
    case 31 : /* #LSIGN */
    case  4 : /* #LOPEN */
    case 5 :  /* #LSLOPEN */
    case 33 : /* #LLOWER */
    case 34 :
    case 35 : /* #LUPPER */ 
    case 36 :
    case 41 : /* #LCOPY */
    case 42 : /* #LNOT */
    case 43 : /* #LRCVAVIRT */
    case 44 : /* #LVIRTDOT */ 
    case 45 :
    case 46 : /* #LADDRPH */
    case 47 : /* #LADDRPH2 */
    case 48 : /* #LIABS */
    case 49 : /* #LINEG */
    case 50 : /* #LRABS */
    case 51 : /* #LRNEG */
    case 52 : /* #LPARAMADDR */
    case 58 : /* #LIFIX */
    case 59 : /* #LFLOAT */
    case 40 : /* #LGETTYPE */
    case 87 : /* #LMDFTYPE */
    case 82 : /* # LEQNONE */
    case 83 : /* #LNENONE */
    case 100 : /* #LOR */
    case 101 : /* #LAND */
    case 131 : /* #LXOR */
    case 116 : /* #LSHIFT */
    case 102 : /* #LARRAY */
    case 103 : 
    case 104 :
    case 105 : /* #LFARRAY */
    case 112 : /* #LCOMBINE */
    case 106 : /* #LIEQUAL */
    case 107 : /* #LINEQUAL */
    case 108 : /* #LILT */
    case 109 : /* #LILE */
    case 110 : /* #LIGT */
    case 111 : /* #LIGE */
    case 113 : /* #LIADD */
    case 114 : /* #LISUB */
    case 115 : /* #LIMULT */
    case 117 : /* #LIDIVE */
    case 118 : /* #LIMODE */
    case 119 : /* #LRADD */
    case 120 : /* #LRSUB */
    case 121 : /* #LRMULT */
    case 122 : /* #LRDIVE */
    case 125 : /* #LREQ */
    case 126 : /* #LRNE */
    case 127 : /* #LRLT */
    case 128 : /* #LRLE */
    case 129 : /* #LRGT */
    case 130 : /* #LRGE */
    case 123 : /* #LEQREF */
    case 124 : /* #LNEREF */
    case 132 : /* #LCALLPROCSTAND */
    case 143 : /* #LKILL */
    case 144 : /* #LHEADS */
    case 146 : /* #LGKILL */
    case 159 : /* #LGO */
    case 160 : /* #LGOLOCAL */
    case 170 : /* #LDTYPE */
    case 172 : /* #LTERMINATE */
    case 173 : /* #LWIND */
    case 177 : /* #LTRACE */
    case 180 : /* #LBACKHD */
    case 191 : /* #LBACKBL */
    case 193 : /* #LBACK */
    case 194 : /* #LFIN */
    case 192 : /* #LBACKPR */
    case 220 : /* #LRESUME */          /*CBC*/
    case 221 : /* #LSTOP */            /*CBC*/
    case 222 : /* #LKILLTEMP */        /*CBC*/
    case 226 : /* #LACCEPT2 */         /*CBC*/
    case 228 : /* #LASKPROT */         /*CBC*/
    case 240 : /* #LSTEP */            /*CDSW&BC*/
    case 188 : /* #LATTACH */
    case 187 :  /* #LDETACH */ 
             emit(); /* NO EXTRA TREATMENT */
             break ;

    } /* switch opcode */
   } /* for */
 } /* GEN */

