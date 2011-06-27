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
      EQUIVALENCE(STALER(1),IPMEM(1))
      EQUIVALENCE(STACK(1),IPMEM(1))

