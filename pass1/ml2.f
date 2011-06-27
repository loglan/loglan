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

      SUBROUTINE ML2
C*****************************************************************************
C	      ETAP KONCZACY KOMPILACJE
C	      ZADANIA:
C		-PRZESORTOWANIE SYGNALIZACJI BLEDOW
C		-LISTING PROGRAMU ZRODLOWEGO Z WSTAWIONYMI SYGNALIZACJAMI
C		-W PRZYPADKU BLEDOW : ABORTOWANIE KOMPILATORA
C
C*****************************************************************************
C
C	      OPIS W DOKUMENTACJI:	  J.I.3
C	      WERSJA Z DNIA:		  19.01.82
C	      DLUGOSC KODU:	  615
C..........................................................................
C
      IMPLICIT INTEGER (A-Z)
C
      LOGICAL  ERRFLG
      COMMON /STREAM/  ERRFLG, LINE, IBUF2(265), IBUF3(7), JUNK(260)
      COMMON /BLANK/ IOP(4), ERRLINE, ERRCNT,
     X		COM(272),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      XFIL(17),
     X	      IPMEM(5000)
      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
      integer*4 bufln1, bufln2
      INTEGER*2 ERRSGN
      COMMON /ERRS/  ERRSGN(3, 426)
C
      COMMON /MSTA/ MLFREE, WNFREE, WNSTK, AL1BLK, AL1STK,
     X		    AL2BLK, AL2SYM, AL2OTH, WNBLK, TLP, TLM,
     X		    WNSUS, TOTMEM
C
      LOGICAL BTEST
       dimension dig(4)
cdsw	BYTE JFNAME
	COMMON /JF/JFNAME(72),JF
cbc
      integer*2 bigbuf
      common /combuf/ ind, length, bigbuf(16000)
cbc
      integer*4 offset
      character ch
       character jfname
       character*72 nam
       equivalence(jfname(1),nam)

cdeb --------------------- added =----------------
      common /debug/deb,breakt(500),brnr,maxbr
      logical deb
cdeb ---------------------------------------

      pagesz = 60
      pagenr = 0
      linpg = 60
C------ PRZYGOTOWANIE WYDRUKOW STATYSTYK
      TOTMEM = LMEM+302
      TOTMEM = IAND(ISHFT(TOTMEM, -10), 63)
      MLFREE = IOP(4)+1
      WNFREE = IPMEM(ISFIN-2)
      WNSTK = IPMEM(ISFIN-1)
      WNSUS = (LPMEM-ISFIN) + WNSTK + 9
      WNBLK = IPMEM(ISFIN-8)
      AL1BLK = IPMEM(ISFIN-3)
      AL1STK = IPMEM(ISFIN-4)
C     AL2BLK = IPMEM(ISFIN-5)
C     AL2SYM = IPMEM(ISFIN-6)
C     AL2OTH = IPMEM(ISFIN-7)
      TLP = LPMEM
      TLM = LMEM

      offset = 0
      call ffseek(16,offset) 
      length = 0
      ind = 1

      do 117 i=1,4
      call frdchr(16, ch)
117   dig(i) = ichar(ch)
      call dec(i,dig)
      LUN = 0
      IF(.NOT.(BTEST(I,15)))	GOTO 9999
      LUN = 13
      jfname(jf+1) = 'l'
      jfname(jf+2) = 's'
      jfname(jf+3) = 't'
        
c  unit 13 - listing  (sequential)
      call ffcreat(13,nam)
C ---
9999	  IF(ERRFLG)GO TO 1000
C*******GDY PROGRAM  JEST POPRAWNY
C ---
      IF (LUN.EQ.0) GOTO 2500
C ---
      LPMF = 1
C     WSTAWIENIE STRAZNIKA DO TABLICY SYGNALIZACJI BLEDOW
cdsw&bc      ERRSGN(1,1) = 10000
      ERRSGN(1,1) = 32000
c
      LPML = 1
      GOTO  2000
C
C*******GDY PROGRAM NIEPOPRAWNY
C	      -PRZYGOTOWANIE DO LACZENIA LISTINGU I SYGNALIZACJI BLEDOW
 1000 LPMF = 1
      DO  100 I =1, 425
cdsw&bc	ERRSGN(1, I) = 10000
	ERRSGN(1, I) = 32000
  100 CONTINUE
      LPML = 0
C   ... SCIAGNIECIE TABLICY HASH'U
      CALL  MGHASH
C   ... SCIAGNIECIE  I POSORTOWANIE SYGNALIZACJI BLEDOW
      CALL  MGERR
C   ... SKLEJENIE SYGNALIZACJI PARSERA ODWOLUJACYCH SIE DO TEJ
C	SAMEJ LINII
       CALL  MFLTR
C
C***************  LISTOWANIE PROGRAMU
2000  CALL  MLSTSC
C------ PRZYGOTOWANIE ZAKONCZENIA KOMPILACJI
2500  CONTINUE
C------ PROGRAM POPRAWNY
      IF (.NOT. ERRFLG) GOTO 7770
C------ PROGRAM NIEPOPRAWNY
3000  IF (ERRCNT .EQ. 0)	GOTO  3100
      call ffputnl(0)
      call ffputi (0,ERRCNT,4)
      call ffputcs(0,' error(s) detected')
      call ffputnl(0)
3100  IF (IOP(1) .LE. 7)    GOTO  3200
      call ffputcs(0,' Fatal Error:  Source program abandoned')
      call ffputnl(0)
3200  CONTINUE
7770  CONTINUE

      call closf(ibuf3)
      
      call ffclose(15)
      if (errflg) call ffunlink(15)
      call ffclose(16)
C  16 is temporary file and will be automatically deleted after exit, but ...
      call ffunlink(16)
      call ffclose(17)
cdeb ------------------ added --------------
c deletion of the file 21 (for debugger )
      if(.not.deb) go to 10
      deb = .false.
      call ffclose(21)
      if (errflg) call ffunlink(21)
10    continue
cdeb
cvax  STOP 
      END

cdsw ------------  added  -------------------------------
      subroutine dec(num,dig)
      implicit integer (a-z)
      dimension dig(4)
c  zamienia 4 cyfry hexadecymalne wpisane w dig na liczbe num
c
      do 10 i=1,4
      a = iand(dig(i),X'00ff')
      if(a.ge.ichar('a').and. a.le.ichar('f') ) go to 100
      if(a.ge.ichar('A').and.a.le.ichar('F')) go to 99
      a = a-ichar('0')
      go to 110
 100  a = a-ichar('a')+10
      go to 110
 99   a = a-ichar('A')+10
 110  dig(i) = a
 10   continue
      num = dig(4)
      num = ior(num,ishft(dig(1),12))
      num = ior(num,ishft(dig(2),8))
      num = ior(num,ishft(dig(3),4))
      return
      end



      SUBROUTINE  MLSTSC
C--------------PROCEDURA LISTUJACA TEKST ZRODLOWY (SOURCE) I
C	      WSTAWIAJACA DO NIEGO SYGNALIZACJE BLEDOW
C
C	      OPIS W DOKUMENTACJI:	    J.III.1
C	      WERSJA Z DNIA:		    19.01.82
C	      DLUGOSC KODU:	  420
C..........................................................................
C
      IMPLICIT INTEGER (A-Z)
      LOGICAL  MREADLN, MREADSG
      LOGICAL  PRINT1, PRINT2
C	      PRINT1, PRINT2 - FLAGI DRUKOWANIA LINII W BUFORACH BUFLN
C
      COMMON /BLANK/ IOP(4), ERRLINE, ERRCNT,
     X		COM(272),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      XFIL(17),
     X	      IPMEM(5000)
      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
      integer*4 bufln1, bufln2
      INTEGER*2 ERRSGN
      COMMON /ERRS/  ERRSGN(3, 426)
C
C-------------
      ERRLINE = ERRSGN(1, LPMF)
      NR = ERRSGN(2, LPMF)
      ID = ERRSGN(3, LPMF)
C......WCZYTANIE PIERWSZEJ LINII LISTINGU
      PRINT2 = MREADLN(PRINT1)
      LN1 = LN2
      LGTH1 = LGTH2
      DO  100  I=1, (LGTH1+3)/4
	BUFLN1(I) = BUFLN2(I)
  100 CONTINUE
C********************************
C     WCZYTYWANIE KOLEJNYCH LINII
 1000 IF (MREADLN(PRINT2) )    GOTO  5000
C	      --SKOK, GDY SKONCZYL SIE TEKST ZRODLOWY, W BUFLN1 JEST JEGO
C		OSTATNIA LINIA
C     --- SPRAWDZENIE, CZY LINIA W BUFLN2 NIE ZAWIERA LINII Z SYGNALI-
C	   ZACJA BLEDU Z PARSERA
      IF (LN1 .NE. LN2)    GOTO  2000
C     ---DRUKOWANIE LINII Z BUFLN1 Z INFORMACJA O TYM, ZE ZA NIA
C		  BEDA SYGNALIZACJE BLEDOW
C     (W CZASIE DRUKOWANIA BUFLN2 JEST PRZEPISYWANY DO BUFLN1)
      CALL  PSLINE(.TRUE.)
      PRINT1 = PRINT2
C     ---CZYTANIE I KOMPRESJA LINII Z SYGNALIZACJAMI BLEDOW Z PARSERA
C	 - PIERWSZA LINIA ZNAJDUJE SIE W BUFLN1
      IF (MREADSG(PRINT2))    GOTO  5000
C	 W BUFLN1 JEST SKOMPRESOWANA LINIA Z SYGNALIZACJAMI
C	 O ILE NIE MA SKOKU - W BUFLN2 JEST NOWA LINIA TEKSTU ZRODLOWEGO
C	 SKOK - GDY SKONCZYL SIE TEKST ZRODLOWY
C	 WYDRUKOWANIE OSTATNIEJ LINII Z SYGNALIZACJA BLEDOW PARSERA
	 CALL  PSLINE (.FALSE.)
	 GOTO  3100
C
 2000 IF (LN2 .GT. ERRLINE)    GOTO  3000
C     ---NOWA LINIA POPRZEDZA SYGNALIZACJE BLEDOW
      IF (PRINT1)    CALL  PSLINE(.FALSE.)
      IF (PRINT1)    GOTO  2500
C     ...SKOPIOWANIE BUFORA (NIE MUSI BYC W PSLINE)
	LN1 = LN2
	LGTH1 = LGTH2
	DO 2100 I=1, (LGTH1+3)/4
	  BUFLN1(I) = BUFLN2(I)
 2100	CONTINUE
 2500 PRINT1 = PRINT2
      GOTO  1000
C     ---NOWA LINIA WYSTEPUJE ZA SYGNALIZACJA BLEDOW
 3000 CALL  PSLINE(.TRUE.)
      PRINT1 = PRINT2
C     ---WYPISANIE SYGNALIZACJI BLEDOW ODNOSZACYCH SIE DO WYDRUKOWANEJ
C	 LINII
 3100 CALL  PERSGN(ERRLINE, NR, ID)
 3150 LPMF = LPMF+1
      ERRLINE = ERRSGN(1, LPMF)
cdsw&bc  added check for guard - ERRLINE = 32000
      if (errline .eq. 32000) goto 8000
c
      NR = ERRSGN(2, LPMF)
      ID = ERRSGN(3, LPMF)
      IF (NR .EQ. -1)	 GOTO  3150
C	   SKOK - GDY TA SYGNALIZACJA ZOSTALA POMINIETA PRZEZ FILTROWANIE
      IF (ERRLINE .LT. LN1)    GOTO  3100
C	 SKOK GDY NASTEPNA SYGNALIZACJA ODNOSI SIE DO LINII JUZ WYDRUKOWANEJ
C     ...LINIA ZA SYGNALIZACJA BLEDOW TEZ MUSI BYC DRUKOWANA
      PRINT1 = .TRUE.
      GOTO  1000
C-----------------------------
C     ZAKONCZENIE LISTINGU - W BUFLN1 JEST OSTATNIA LINIA
cdsw&bc 5000 IF (ERRLINE .EQ. 10000)	 GOTO  7000
 5000 IF (ERRLINE .EQ. 32000)	 GOTO  7000
C	      --JEST TO PSEUDOSYGNALIZACJA (STRAZNIK)
      CALL  PSLINE(.TRUE.)
C     ---WYPISANIE RESZTY SYGNALIZACJI BLEDOW
 6000 IF (NR .NE. -1)	 CALL  PERSGN(ERRLINE, NR, ID)
      LPMF = LPMF+1
      ERRLINE = ERRSGN(1, LPMF)
cdsw&bc      IF (ERRLINE .EQ. 10000)	 GOTO  8000
      IF (ERRLINE .EQ. 32000)	 GOTO  8000
      NR = ERRSGN(2, LPMF)
      ID = ERRSGN(3, LPMF)
      GOTO  6000
C     ---WYPISANIE OSTATNIEJ LINII Z LISTINGU, GDY ZA NIA NIE MA
C	 SYGNALIZACJI BLEDOW
 7000 IF (PRINT1)    CALL  PSLINE(.FALSE.)
 8000 RETURN
      END

      SUBROUTINE  PERSGN(LINE, NR, ID)
C--------------PROCEDURA DRUKUJACA SYGNALIZACJE BLEDOW
C	      LINE - NUMER LINII Z BLEDEM
C	      NR - NUMER BLEDU
C	      ID - IDENTYFIKATOR
C
C	      OPIS W DOKUMENTACJI:	   J.III.6
C	      WERSJA Z DNIA:		   19.01.82
C	      DLUGOSC KODU:	  4865
C.....................................................................
C	      !!!!!! UWAGA !!!!!!
C	      PO FORTRANIE (PRZED ASSEMBLACJA) DOLACZYC
C	      ZAWARTOSC DECKU  MPERSGNASS PRZED 'END'
C		-- ZAWIERA ON INICJALIZACJE TABLIC SYGNALIZACJI
C	      BLEDOW
C
      IMPLICIT INTEGER (A-Z)
      character itab(8)
      equivalence (itab(1),nameid(1))

      LOGICAL BTEST
      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
      integer*4 bufln1, bufln2

      DIMENSION NAMEID(2)
      integer*4 nameid

      DO 201 I=1,8
201   ITAB(I)=' '

      LINPG = LINPG + 1
      IF (LINPG .GT. PAGESZ)	CALL PGINIT

C     ---DRUKOWANIE SYGNALIZACJI
202   IF (ID .EQ. 0)	GOTO  400
      IF (ID .LT. 0)	GOTO  300
C     ---ODKODOWANIE NAZWY
      IF (.NOT. BTEST(ID, 0))	 GOTO  400
C	  -- W TYM PRZYPADKU NIE JEST TO IDENTYFIKATOR LECZ SLOWO KLUCZOWE
      call naswa(id,itab)
      GOTO  400

C     ---ODKODOWANIE ZNAKU
300   nameid(1) = -id-1
400   continue 

      CALL listing_error_line( lun, line, nr, NR, nameid(1) )
      RETURN
      END


      SUBROUTINE  MFLTR
C-----------------PROCEDURA FILTRUJE SYGNALIZACJE BLEDOW - SKLEJA
C		  SYGNALIZACJE O TYM SAMYM NUMERZE POCHODZACE Z
C		  PARSERA I ODNOSZACE SIE DO TEJ SAMEJ LINII TEKSTU
C		  ZRODLOWEGO
C
C	      OPIS W DOKUMENTACJI:	     J.II.4
C	      WERSJA Z DNIA:		     19.01.82
C	      DLUGOSC KODU:	  202
C........................................................................
C
      IMPLICIT INTEGER (A-Z)
C
      COMMON /BLANK/ IOP(4), ERRLINE, ERRCNT,
     X		COM(272),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      XFIL(17),
     X	      IPMEM(5000)
      INTEGER*2 ERRSGN
      COMMON /ERRS/  ERRSGN(3, 426)
C
C
C		  IER100 - ZAWIERA OSTATNIE LINIE TEKSTU W
C			    KTORYCH SYGNALIZOWANO BLAD Z PRZEDZIALU
C			    101-143
C		  IER200 - ANALOGICZNIE DLA PRZEDZIALU 201-212
      INTEGER*2 IER100(43), IER200(12)
      DATA IER100 /43*0/, IER200 /12*0/
C
C
      DO 1000 I=LPMF,LPML
C     ...NRERR - NUMER BLEDU
	NRERR = ERRSGN(2,I)
	IF(NRERR .LE. 100)    GOTO  1000
	IF (NRERR .GE. 213)    GOTO  1000
	IF ( (NRERR .GE. 144) .AND. (NRERR .LE. 200) )	  GOTO	1000
C	      TE SYGNALIZACJE NIE PODLEGAJA SKLEJANIU
C     ...NRLINE - NUMER LINII
	NRLINE = ERRSGN(1,I)
	IF (NRERR .GT. 200)    GOTO  500
C     ---TU BLAD Z PRZEDZIALU 101-143
	  NRERR = NRERR-100
	  IF (IER100(NRERR) .NE. NRLINE)    GOTO  100
C	  BLAD JUZ SYGNALIZOWANY
	    ERRSGN(2,I) = -1
	    GOTO    1000
C	  ZAPAMIETANIE LINII Z TA SYGNALIZACJA
  100	  IER100(NRERR) = NRLINE
	    GOTO  1000
C     ---TU BLAD Z PRZEDZIALU 201-212
  500	NRERR= NRERR-200
	IF (IER200(NRERR) .NE. NRLINE)	  GOTO	600
C	  BLAD JUZ SYGNALIZOWANY
	  ERRSGN(2,I) = -1
	  GOTO	1000
C	  ZAPAMIETANIE LINII
  600	  IER200(NRERR) = NRLINE
C
 1000 CONTINUE
      RETURN
      END
      LOGICAL FUNCTION	MREADSG(PRINTER)
C----------------------FUNKCJA CZYTA ORAZ WYKONUJE KOMPRESJE LINII
C		       ZAWIERAJACYCH SYGNALIZACJE BLEDOW PARSERA.
C		      WARUNEK WEJSCIOWY: BUFLN1 ZAWIERA OSTATNIA
C		       LINIE (PIERWSZA Z SYGNALIZACJA BLEDOW PAR-
C		       SERA)
C		       BUFLN2 JEST PUSTY
C		      WARUNEK WYJSCIOWY: BUFLN1 ZAWIERA OSTATNIA
C		       SKOMPRESOWANA LINIE Z SYGNALIZACJAMI
C		       BUFLN2 KOLEJNA LINIE TEKSTU ZRODLOWEGO
C		       LUB JEST PUSTY (GDY TEKST SIE SKONCZYL)
C		       WARTOSC FUNKCJI .TRUE. OZNACZA ZE TEKST
C		       ZRODLOWY SIE SKONCZYL
C
C
C	      OPIS W DOKUMENTACJI:	    J.III.5
C	      WERSJA Z DNIA:		    19.01.82
C	      DLUGOSC KODU:	   402
C..........................................................................
C
      IMPLICIT INTEGER (A-Z)
      LOGICAL MREADLN
      LOGICAL PRINTER
C		PRINTER FLAGA DRUKOWANIA LINII Z BUFLN2
C
      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
       integer*4 bufln1, bufln2
C ---
      character bln1(120), bln2(120)
      EQUIVALENCE (BLN1(1),BUFLN1(1)),(BLN2(1),BUFLN2(1))
C ---
C
C
C
      MREADSG = .TRUE.
 1000 CONTINUE
      DO 1 I=LGTH1-2,LGTH1
      BLN1(I-3) = BLN1(I)
1     CONTINUE
      LGTH1 = LGTH1 - 3
	BLN1(LGTH1+1)= ' '
	BLN1(LGTH1+2)=' '
	BLN1(LGTH1+3)=' '
C-----LINIA W BUFLN1 JEST SKOMPRESOWANA
C     WCZYTANIE KOLEJNEJ LINII DO BUFLN2
	IF (MREADLN(PRINTER))	 RETURN
C	 POWROT, GDY BYLA TO OSTATNIA LINIA (MREADSG = .TRUE.)
	IF (LN1 .NE. LN2)    GOTO  9000
C	 --LINIA W BUFLN2 NIE JEST SYGNALIZACJA BLEDU - SKOK
C     ---NOWA LINIA Z SYGNALIZACJA BLEDU
C	 SPRAWDZENIE, CZY  ?  W BUFLN2 JEST DALEJ NIZ WYNOSI
C	 DLUGOSC LINII W BUFLN1, TZN. CZY LINIE MOGA BYC SKLEJONE
	 IF (LGTH1 .LT. (LGTH2-6))    GOTO  3000
C	 ----TU LINIE NIE MOGA BYC SKLEJONE
C	   WYDRUKOWANIE LINII Z BUFLN1 Z PRZESLANIEM ZAWARTOSCI BUFORA
C	   BUFLN2 DO BUFLN1 I PRZEJSCIE DO KOMPRESJI NOWEJ SYGNALIZACJI
	    CALL  PSLINE(.FALSE.)
	    GOTO  1000
C	 ---DOKLEJANIE LINII Z BUFLN2 DO BUFLN1
3000  DO 3200 I=LGTH1+1,LGTH2
      BLN1(I) = BLN2(I)
 3200	CONTINUE
	LGTH1 = LGTH2
	GOTO  1000
C------ZAKONCZENIE
 9000 MREADSG = .FALSE.
      RETURN
      END


      SUBROUTINE NASWA(L,ITAB)
C
C  PARAMETR L - NUMER IDENTYFIKATORA Z TABLICY HASH
C
C	      OPIS W DOKUMENTACJI:	   J.III.6
C	      WERSJA Z DNIA:		   19.01.82
C	      DLUGOSC KODU:	   120
C.....................................................................
      IMPLICIT INTEGER (A-Z)
      COMMON /BLANK/ COM(302),HASH(8000),M,I,K 
      
      character itab(8)
      I=L
      J=1
      IF (HASH(I).LE.0) RETURN
5     IF (HASH(I).LT.61) GOTO 10
C  DWA ZNAKI W SLOWIE
      K=ISHFT(HASH(I),-6)
      itab(j) = char(snak(k))
      J=J+1
C  JEDEN ZNAK
10    K=IAND(HASH(I),63)
      itab(j) = char(snak(k))
      J=J+1
      I=HASH(I+1)
      IF (I.GE.0) RETURN
      I=-I
      GOTO 5
      END
      

      INTEGER FUNCTION SNAK(K)
      IMPLICIT INTEGER (A-Z)
      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
       integer*4 bufln1, bufln2
      IF (K.EQ.60) K=0
      IF (K.GT.9) GOTO 10
C  CYFRA - KOD MIEDZY 0 A 9
      SNAK = K + ICHAR('0')
      RETURN
10    IF (K.GT.35) GOTO 20
C  LITERA - KOD MIEDZY 10 A 35
      SNAK = ICHAR('A') + K - 10
      RETURN
C  LACZNIK - UNDERSCORE
20    SNAK = ICHAR('_')
      RETURN
      END
      SUBROUTINE  MGHASH
C--------------SCIAGNIECIE TABLICY NAZW (HASH'U) SCANNERA DO
C	      SYGNALIZACJI BLEDOW
C
C	      OPIS W DOKUMENTACJI:	     J.II.1
C	      WERSJA Z DNIA:		     19.01.82
C	      DLUGOSC KODU:	   330
C......................................................................
C
      IMPLICIT INTEGER (A-Z)
C
      LOGICAL  ERRFLG
      COMMON /STREAM/  ERRFLG, LINE, IBUF2(265), IBUF3(7), JUNK(260)
      COMMON /BLANK/ IOP(4), ERRLINE, ERRCNT,
     X		COM(272),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      XFIL(17),
     x        hash(8000)
cdsw X	      IPMEM(5000)
      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
      integer*4 bufln1, bufln2
C
      CALL  SEEK(IBUF3, 0)
      do 100 i=1,8000,256
      call get(ibuf3,hash(i))
  100 CONTINUE
      RETURN
      END


      SUBROUTINE  PSLINE (WSIGN)
C--------------DRUKUJE LINIE TEKSTU ZRODLOWEGO PRZECHOWYWANA
C	      W BUFLN1.
C	      WSIGN - .TRUE. - OZNACZA, ZE DO LINII BEDZIE ODNO-
C	      SILA SIE ROWNIEZ INFORMACJA O BLEDZIE, W ZWIAZKU Z TYM
C	      LINIA TA NIE POWINNA BYC OSTATNIA LINIA NA STRONIE
C
C	      OPIS W DOKUMENTACJI:	  J.III.3
C	      WERSJA Z DNIA:		  19.01.82
C	      DLUGOSC KODU:	  153
C.....................................................................
C
      IMPLICIT INTEGER (A-Z)
      LOGICAL  WSIGN
C
      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
      integer*4 bufln1, bufln2
cailvax
c     Maximal record length for the printer is 132 characters (VAX).
c     Hence only 114 characters remain for the source line.
      character buf(114)
      equivalence (buf(1),bufln1(1))

      LINPG = LINPG + 1
      IF (LINPG .GT. PAGESZ)	GOTO  2000
C	    --SKONCZYLA SIE STRONA
      IF (WSIGN .AND. (LINPG .EQ. PAGESZ) )    GOTO  2000
C	    --NA STRONIE NIE ZMIESCI SIE LINIA RAZEM Z SYGNA-
C	      LIZACJA, ROZPOCZECIE NOWEJ STRONY

1000  k = lgth1
      if (k .gt. 114) k = 114

cailvax  that's a pity those 6 characters are truncated
cvax ---------- added

      call ffputcs(lun,'    ')
      call ffputi (lun,ln1,6)
      call ffputcs(lun,'      ')
      call ffputs (lun,buf,k)
      call ffputnl(lun)

      LN1 = LN2
      LGTH1 = LGTH2
      LGTH2 = (LGTH2+3)/4
      DO  1100 I=1, LGTH2
      BUFLN1(I) = BUFLN2(I)
 1100 CONTINUE
      RETURN
 2000 CALL  PGINIT
      GOTO  1000
      END



      SUBROUTINE  PGINIT
C--------------ROZPOCZECIE NOWEJ STRONY LISTINGU
C
C	      OPIS W DOKUMENTACJI:	   J.III.2
C	      WERSJA Z DNIA:		   19.01.82
C	      DLUGOSC KODU:	  162
C.......................................................................

      IMPLICIT INTEGER (A-Z)

      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
      integer*4 bufln1, bufln2

      COMMON /BLANK/ IP(1)

      IF (LUN.EQ.2) RETURN
      PAGENR = PAGENR + 1
      LINPG = 1

      call ffputnl(LUN)
      call ffputff(LUN)
      call ffputcs(LUN,'  IIUW   LOGLAN-82')
      call ffputcs(LUN,'  UNIX Compiler - Ver. Oct 88')
      call ffputspaces(LUN,15)
      call ffputcs(LUN,'PAGE ')
      call ffputi (LUN,PAGENR,7)
      call ffputnl(LUN)

      RETURN
      END



      SUBROUTINE  MGERR
C--------------SCIAGNIECIE ZE STRUMIENIA 2  SYGNALIZACJI BLEDOW,
C	      POSORTOWANIE ICH WZGLEDEM NUMEROW LINII W TEKSCIE
C	      ZRODLOWYM (PROCEDURA  MSERR)
C	      POSORTOWANE SYGNALIACJE ZNAJDUJA SIE W TABLICY
C	      ERRSGN  (COMMON /ERRS/) OD MIEJSCA LPMF DO LPML
C	      DOPUSZCZALNA LICZBA SYGNALIZACJI	425 - INACZEJ PRZE-
C	      PELNIENIE  10
C
C	      ZMIENIONE  (WSZYSTKO BYLO DO DUPY)     P.G.
C	      ========= 		=======
C
C........................................................................
C
      IMPLICIT INTEGER (A-Z)
C
      LOGICAL  ERRFLG
      COMMON /STREAM/  ERRFLG, LINE, IBUF2(265), IBUF3(7), JUNK(260)
      COMMON /BLANK/ IOP(4), ERRLINE, ERRCNT,
     X		COM(272),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      XFIL(17),
     X	      IPMEM(5000)
      INTEGER*2 ERRSGN
      COMMON /ERRS/  ERRSGN(3, 426)
C
C	      BUDOWA STRUMIENIA  2
C	SLOWA 1-7 -BUFOR DLA PROCEDUR ZAPISU I ODCZYTU (OPIS STRUMIENIA)
C	SLOWO 8 -NUMER AKTUALNIE ZAPISYWANEGO BLOKU
C	SLOWO 9 -INDEKS PIERWSZEJ WOLNEJ POZYCJI BLOKU AKTUALNIE TWORZO-
C	      NEGO
C	SLOWO 10 -LICZBA TROJEK WPISANYCH DO BLOKU
C	SLOWA 10-265 -AKTUALNIE TWORZONY BLOK (TROJKI ZAPISYWANE OD SLO-
C	      WA 11)
C
      LPMF = IBUF2(8)*85
      ERRCNT = LPMF + (IBUF2(9) - 11)/3
C	      ERRCNT - LICZBA SYGNALIZACJI BLEDOW
      LPML = ERRCNT
      IF (ERRCNT .GT. 425)    GOTO  2000
C	      --SKOK GDY LICZBA SYGNALIZACJI BLEDOW PRZEKRACZA
C	      DOPUSZCZALNA
C
C --- SYTUACJA NORMALNA - LICZBA SYGNALIZACJI BLEDOW JEST DOPUSZCZALNA
      IF (ERRCNT .EQ. LPMF)    GOTO  200
C ... PRZEPISANIE TROJEK SYGNALIZACJI BLEDOW Z BUFORA  IBUF2
C	DO TABLICY ERRSGN
      K = IBUF2(9) - 1
      DO  100  I=11, K, 3
	LPMF = LPMF+1
	ERRSGN(1, LPMF) = IBUF2(I)
	ERRSGN(2, LPMF) = IBUF2(I+1)
	ERRSGN(3, LPMF) = IBUF2(I+2)
  100 CONTINUE
C
C...WCZYTANIE SYGNALIZACJI BLEDOW ZE STRUMIENIA 2
  200 CALL  SEEK(IBUF2, 0)
      K =  IBUF2(8)
C	      ... K LICZBA BLOKOW
      IF (K .EQ. 0)    GOTO  5000
 1000 LPMF = 0
      DO  1200	I=1, K
	CALL  GET(IBUF2, IBUF2(10)  )
	DO  1100  J=11, 265, 3
	  LPMF = LPMF+1
	  ERRSGN(1, LPMF) = IBUF2(J)
	  ERRSGN(2, LPMF) = IBUF2(J+1)
	  ERRSGN(3, LPMF) = IBUF2(J+2)
 1100	CONTINUE
 1200 CONTINUE
C  ... PRZEJSCIE DO CZESCI SORTUJACEJ
      GOTO  5000
C
C
C-----SYTUACJA PRZEKROCZENIA DOPUSZCZALNEJ LICZBY SYGNALIZACJI
C     -WCZYTANIE PIERWSZYCH 425 SYGNALIZACJI, TJ. 8 BLOKOW
C      SYG. 500 BEDZIE OPISYWAC PRZEKROCZENIE TABLICY SYGNALIZACJI
C
 2000 IOP(1) = 1
      K = IBUF2(8)
      CALL  SEEK(IBUF2, K)
      CALL PUT(IBUF2, IBUF2(10) )
      CALL  SEEK(IBUF2, 0)
      LPMF = 0
      DO  2200	I=1,5
	CALL  GET(IBUF2, IBUF2(10))
	DO  2100 J=11, 265, 3
	  LPMF = LPMF+1
	  ERRSGN(1,LPMF) = IBUF2(J)
	  ERRSGN(2, LPMF) = IBUF2(J+1)
	  ERRSGN(3, LPMF) = IBUF2(J+2)
 2100	CONTINUE
 2200 CONTINUE
      ERRSGN(1, 425) = 9999
      ERRSGN(2, 425) = 10
      ERRSGN(3, 425) = 0
      LPML = 425
C
C
C*******SORTOWANIE SYGNALIZACJI BLEDOW
 5000 CALL  MSERR
cdsw&bc      ERRSGN(1,LPML+1) = 10000
      ERRSGN(1,LPML+1) = 32000
      CALL  CLOSF(IBUF2)
      RETURN
      END



      LOGICAL FUNCTION	MREADLN (PRINTF)
C--------------PROCEDURA WCZYTUJE LINIE WSTEPNIE UTWORZONEGO
C	      LISTINGU (ZE STRUMIENIA 1) DO BUFORA  BUFLN2
C	      PRINTF - FLAGA LISTOWANIA LINII, MA WARTOSC
C		       .TRUE. GDY LINIE NALEZY WYDRUKOWAC
C	      //DODATKOWO MREADLN  MA WARTOSC .TRUE., GDY NAPOTKANY
C	      JEST KONIEC PLIKU
C
C	      OPIS W DOKUMENTACJI:	    J.III.4
C	      WERSJA Z DNIA:		    19.01.82
C	      DLUGOSC KODU:	   225
C..........................................................................
C
      IMPLICIT INTEGER (A-Z)
      LOGICAL  PRINTF
C
      COMMON /BLANK/ IOP(4), ERRLINE, ERRCNT,
     X		COM(272),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      XFIL(17),
     X	      IPMEM(5000)
C
      COMMON /LYST/ PAGESZ, PAGENR, LINPG,
     X		    LN1, LGTH1, BUFLN1(30),
     X		    LN2, LGTH2, BUFLN2(30),
     X		    LUN
      integer*4 bufln1,  bufln2
      character bufln3(120)
      equivalence (bufln2(1), bufln3(1))
      character ch
      character bln2(4)
      integer*4 bufelem
      dimension dig(4)
      EQUIVALENCE(BUFELEM,BLN2(1))

      DATA BS / '    ' /

      MREADLN = .FALSE.
      do 118 i=1,4
      call frdchr(16, ch)
      dig(i) = ichar(ch)
      if (dig(i) .eq. 2) goto 1000
118   continue
      call dec(ln2,dig)
      call frdchr(16, ch)
      pfg = ichar(ch)-48
      do 119 i=1,120
      call frdchr(16, bufln3(i))
      if (ichar(bufln3(i)) .eq. 1) goto 121
119   continue
121   continue
      do 122 j=i, 120
122   bufln3(j) = ' '
cdsw&bc
      LGTH2 = 1
      DO 2 I=2,30
      IF (BUFLN2(I).NE.BS) LGTH2 = I
2     CONTINUE
      PRINTF = (PFG.NE.0) .AND. (LUN.EQ.13)
	 BUFELEM = BUFLN2(LGTH2)
      LGTH2 = 4*LGTH2
	DO 10 I=4,1,-1
	IF(BLN2(I).NE.' ')RETURN
10	LGTH2 = LGTH2-1
	RETURN
C---------KONIEC TEKSTU ZRODLOWEGO
 1000 MREADLN = .TRUE.
      RETURN
      END



      SUBROUTINE  MSERR
C--------------PROCEDURA SORTOWANIA SYGNALIZACJI BLEDOW.
C	       ALGORYTM:
C		- SORTOWANIE PRZEZ WTLACZANIE BLOKOW ZAWIERAJACYCH
C		- (GOWNO - ZWYKLY BUBBLE SORT)	 P.G.
C
C.....................................................................
C
      IMPLICIT INTEGER (A-Z)
      COMMON /BLANK/ IOP(4), ERRLINE, ERRCNT,
     X		COM(272),
     X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  ,
     X	      XFIL(17),
     X	      IPMEM(5000)
      INTEGER*2 ERRSGN
      COMMON /ERRS/  ERRSGN(3, 426)
C
      A=LPML-1
      LPMF=1
      IF(A.LE.0)RETURN
      DO 1000 I=1,A
      MAX=19999
      DO 999 J=I,LPML
      IF(ERRSGN(1,J).GT.MAX)GO TO 999
      MAX=ERRSGN(1,J)
      IMAX=J
999   CONTINUE
      J=ERRSGN(1,I)
      ERRSGN(1,I)=ERRSGN(1,IMAX)
      ERRSGN(1,IMAX)=J
      J=ERRSGN(2,I)
      ERRSGN(2,I)=ERRSGN(2,IMAX)
      ERRSGN(2,IMAX)=J
      J=ERRSGN(3,I)
      ERRSGN(3,I)=ERRSGN(3,IMAX)
      ERRSGN(3,IMAX)=J
1000  CONTINUE
      RETURN
      END

