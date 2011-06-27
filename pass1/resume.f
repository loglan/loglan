C    Loglan82 Compiler&Interpreter
C     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw
C     Copyright (C)  1993, 1994 LITA, Pau
C     
C     This program is free software; you can redistribute it and/or modify
C     it under the terms of the GNU General Public License as published by
C     the Free Software Foundation; either version 2 of the License, or
C     (at your option) any later version.
C     
C     This program is distributed in the hope that it will be useful,
C     but WITHOUT ANY WARRANTY; without even the implied warranty of
C     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
C     GNU General Public License for more details. File: LICENSE.GNU
C  ===============================================================     

CBC B.Ciesielski  added concurrent statements
CBC 1987.04.15  1. RESUME same as ATTACH, opcode 220
CBC 1987.04.24  2. added missing STORAGE:2 metacommand
CBC 1987.11.18  3. added procedure SCONC
C
      SUBROUTINE SRESUM
C------------------------------------------------------
C
C     NA CZUBKU JEST ARGUMENT RESUME. BADA TYP,GENERUJE KOD,
C     ZDEJMUJE ZE STOSU.
C
C     ##### OUTPUT CODE : 220 .
C
C     ##### DETECTED ERROR(S) : 477
C
C............. /STOS/ .....
      IMPLICIT INTEGER (A-Z)
      COMMON /STOS/ BOTTOM,VALTOP,VLPREV,STCKAG,STCKA0,STCKAP(14),
     X		    APETYT(4),LSTLSE,LSTFOR,KIND,PHADR,LASTPR,FSTOUT,
     X		    CONSNR(8),LSTSAF,LSTEMP,TEMPNR,LSTWRD,QRECNR,WB,
     X		    RESULT,FRSTTS,UNIT,INNER,LSTWILL,TEST,ARG,ATLINE,
     X		    FILE,FLARGS,FLMODF,FLREADY,ICOUNT,OCOUNT
	     LOGICAL LSTWILL,FLREADY,TEST
C
      COMMON/OPTION/OPTMEM,OPTOPT,OPTIND,OPTTYP,OPTTRC,OPTCSC,OPTCSF
      LOGICAL OPTOPT,OPTTYP,OPTTRC
C
      LOGICAL	INSYS,	OWN
      COMMON /BLANK/ IOP(4),
     X	      P,
     X	      TLDIM, TLBAS,  IDL, OBJL,
     X	      TRDIM, TRBAS,  IDR, OBJR,
     X	      TRESLT,
     X	      CONVL, CONVR,
     X	      NRPAR,
     X	      IX (261),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      NRINT , NRRE  , NRBOOL, NRCHR , NRCOR , NRPROC, NRTEXT,
     X	      NRUNIV, NATTR , NRNONE, NBLSYS, NBLUS , NEMPTY, INSYS ,
     X	      LOCAL,  OWN,    OBJECT,
     X	      IPMEM(5000)
      REAL   STALER(100)
      INTEGER STACK(5000)
      EQUIVALENCE(STALER(1),IPMEM(1) )
      EQUIVALENCE(STACK(1),IPMEM(1))
C
C
      INTEGER ELEM
C.........
      CALL SVALUE
      IF(STACK(VALTOP).EQ.0)RETURN
      IF(STACK(VALTOP-3).GT.0)GO TO 500
      ELEM=STACK(VALTOP-4)
      ELEM=IAND(IPMEM(ELEM),15)
      IF(ELEM.GT.7 .AND. ELEM.LT.13 .OR. ELEM.EQ.2)GO TO 500
      ELEM=STACK(VALTOP-2)
C     RESUME( NONE ) ?
      IF(STACK(VALTOP).EQ.1)ELEM=LMEM-3
C			    = ATS NONE
      CALL QUADR2(220,ELEM)
      RETURN
C     NIEPOPRAWNY TYP ARGUMENTU RESUME
  500 CALL SERROR(477)
      RETURN
      END

      subroutine sconc(action)
      IMPLICIT INTEGER (A-Z)
      COMMON /STOS/ BOTTOM,VALTOP,VLPREV,STCKAG,STCKA0,STCKAP(14),
     X		    APETYT(4),LSTLSE,LSTFOR,KIND,PHADR,LASTPR,FSTOUT,
     X		    CONSNR(8),LSTSAF,LSTEMP,TEMPNR,LSTWRD,QRECNR,WB,
     X		    RESULT,FRSTTS,UNIT,INNER,LSTWILL,TEST,ARG,ATLINE,
     X		    FILE,FLARGS,FLMODF,FLREADY,ICOUNT,OCOUNT
	     LOGICAL LSTWILL,FLREADY,TEST
C
      LOGICAL	INSYS,	OWN
      COMMON /BLANK/ IOP(4),
     X	      P,
     X	      TLDIM, TLBAS,  IDL, OBJL,
     X	      TRDIM, TRBAS,  IDR, OBJR,
     X	      TRESLT,
     X	      CONVL, CONVR,
     X	      NRPAR,
     X	      IX (261),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      NRINT , NRRE  , NRBOOL, NRCHR , NRCOR , NRPROC, NRTEXT,
     X	      NRUNIV, NATTR , NRNONE, NBLSYS, NBLUS , NEMPTY, INSYS ,
     X	      LOCAL,  OWN,    OBJECT,
     X	      IPMEM(5000)
      REAL   STALER(100)
      INTEGER STACK(5000)
      EQUIVALENCE(STALER(1),IPMEM(1) )
      EQUIVALENCE(STACK(1),IPMEM(1))
c
c generate proper opcode
      call quadr1(action)
c process next identifier
100   call snext
      if (wb .ne. 28) goto 200
      call snext
c check if procedure or function
      ind = mident(wb)
      elem = swhat(ind)
      if (elem .ne. 11 .and. elem .ne. 12) goto 110
c output prototype address
      call quadr1(ind)
      goto 100
110   call serror(478)
      goto 100
c end of identifier list
200   call quadr1(0)
c generate ACCEPT2 if necessary
      if (action .eq. 225) call quadr1(226)
      return
      end

