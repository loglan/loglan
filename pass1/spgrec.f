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

      subroutine spgrec(action)
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
      logical conv
c      
c second parameter - buffer array
      flargs = 2
      call svalu2
c check if one-dimensional array 
      if (stack(vlprev-3) .ne. 1) goto 30
c check if primitive type
      n = stack(vlprev-4)
      if (n .ne. nrint .and. n .ne. nrre .and. n .ne. nrbool .and.
     *    n .ne. nrchr) goto 40
      call quadr4(145, svats(vlprev), action, 0)
c third parameter - byte count
c duplicate stack top
200   conv = .FALSE.
      elem = stack(valtop)
      call spush(elem)
      do 100 i=1, stckap(elem)
      stack(valtop-i+1)=stack(vlprev-i+1)
100   continue
      call svalue
c check if not array
      if (stack(valtop-3) .gt. 0) goto 20
c check if integer
      if (stack(valtop-4) .eq. nrint) goto 300
c not integer, check if real
      if (stack(valtop-4) .ne. nrre) goto 20
c real, convert to integer
      conv = .TRUE.
      call svint(valtop)
300   continue
      call quadr4(145, svats(valtop), action, 1)
      call spop
c check if variable or array element
      n = stack(valtop)
      if (n .ne. 3 .and. n .ne. 4) goto 10
      ats = tstemp(1)
c generate LCALLPROCSTAND
      call quadr2(132, action)
c read output parameter
      call quadr4(23, ats, action, 1)
      if ( .not. conv) go to 400
c convert to real      
      ats1 = tstemp(2)
      call quadr3(59, ats1, ats)
      ats = ats1
400   continue      
      call sstore(valtop, ats)
      call spop
      return
c error recovery
10    call serror(420)
      call spop
      return
20    call serror(478)
      call spop
      call spop
      return
30    call serror(416)
      goto 200
40    call serror(478)
      goto 200
      end

