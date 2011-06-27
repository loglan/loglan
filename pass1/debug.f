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

      subroutine ts1
      implicit integer(a-z)
c  wolana po it1
c  wpisuje do tablicy prs nazwe i numer linii prototypu
c  prs(2*i-1) = nazwa, prs(2*i) = numer linii prototypu i
c  prototypy liczone od isfin do lpmem
      common /debpr/ prs(600)
      common /BLANK/ com(278),
     x		lmem,lpmem,irecn,isfin,
     x		com1(20),
     x		mem(5000)

      do 100 i=isfin,lpmem
      k = mem(i)
      p = mem(k)
c  k - adres slowa zerowego prototypu o numerze i
      j = i-isfin+1
c  nazwa
      prs(2*j-1) = -100
c blok i handler nie maja nazwy
      if(p.ne.1.and.p.ne.8) prs(2*j-1) = mem(k+10)
c  numer linii
      prs(2*j) = mem(k+9)
100   continue
      call dsw
      return
      end

      subroutine TS2
      implicit integer(a-z)
c   przebieg wolany po DSW
c   wypelnia prototypy debuggera prawie do konca
c   DISPNR(3) i dla zmiennych OFFSET (3) = adres prototypu kompilacjnego
c
c  -----------------------------------------------------
c		     BUDOWA PROTOTYPOW
c
c   -1	   nazwa modulu ( hash ze scannera)
c    0		  case
c    1	   SL - numer prot. debuggera w IDICT
c    2	   numer linii z poczatkien definicji
c    3		 dispnr
c    4	   prefiks - numer prot. debuggera w IDICT
c    5	     mala tablica hash nazw atrybutow
c    .	       (jak w DSW)
c   12
c   13	   elementy listy hash i prototypy zmiennych
c   .	      i stalych
c   .
c  ----------------------------------------------------
c
c		     ZMIENNA
c
c    0		  case
c    1	   liczba array of
c    2	   typ - numer prototypu debuggera w IDICT
c    3	   offset
c    4	   SL - numer prototypu debuggera w IDICT
c
c   UWAGA: typ: typ formalny = -10, typ prymitywny = -typ kompilacyjny
c		typ uniwersalny = 0, typ process/coroutine = -typ komp.
c
c  ---------------------------------------------------
c
c		    STALA
c
c    0		   case
c    1	   typ - numer prototypu ( dla typu prymitywnego = -typ komp.)
c    2	   adres stalej w tablicy stalych
c
c   UWAGA: procedura, funkcja i typ formalny nie maja prototypow, ale
c	   wystepuja w tablicy hash (malej)
c
c  --------------------------------------------------
c
c   CASE:    1 - block, 2 - klasa, 3 - procedura, 4 - funkcja
c	     5 - zmienna
c	     7 - funkcja form., 8 - proc. form,
c	     9 - stala
c	     10 - process, 11 - coroutina, 12 - rekord
c	     14 - handler, 15 - sygnal
c
c  --------------------------------------------------
c
c		  ELEMENT LISTY HASH
c
c   0	nazwa ze scannera
c   1		     NT/H/C  - 3 bity
c   2	numer prototypu debuggera: dla unitow - w IDICT, dla zmiennych
c				    i stalych = -adres bezp. protrotypu
c		     proc/fun/typ formalny = -7,-8,-10
c
c ----------------------------------------------------

c-------------------------------------------------------
c    budowa pliku 21:
c	  hash(8000), idict(500), ind,prot(ind)
c-------------------------------------------------------

      common /BLANK/ com(8000)
      call deb2
      call AL1
      return
      end

      subroutine deb2
c  glowna procedura tworzaca prototypy debuggera
      implicit integer (a-z)
      logical btest
      common /BLANK/ com(278),
     x		lmem,lpmem,irecn,isfin,
     x		com2(7),
     x		nrcor, nrproc,
     x		com3(5),
     x		nblus,
     x		com1(5),
     x		mem(8000)

      common /pr/ prot(5000),ind
c   prot - tablica na prototypy debuggera
c   ind - ostatnie zajete miejsce w tablicy

      common/debpr/prs(600)
c prs zawiera nazwy i numery linii kolejnych prototypow
c  prs(2*i-1) = nazwa, prs(2*i) = nr. linii prot. i-tego
c  prototypy liczone sa od isfin do lpmem

      dimension  idict(500),chang(500)
cps   dimension  idict(300),chang(300)
c  idict(i) - adres w prot prototypu o numerze disp. i-1
c  chang(i) - numer z parsera prototypu o numerze w idict=i

      data  idict/500*0/
cps   data  idict/300*0/

c  curr - pierwsze wolne miejsce w tablicy prot
c  zw - miejsce slowa zerowego biezacego prototypu

       ind = 0
       curr = 1
c przepelnienie ?
       if(lpmem-isfin+1 .gt. 500) call mdrop(199)
cps    if(lpmem-isfin+1 .gt. 300) call mdrop(199)

c-------  budowa tablicy chang
      p = nblus
      i = 1
10    continue
      k = mem(p)
c  pomijamy formalne i sygnaly
      if(btest(k,4).or.btest(k,5)) go to 11
      if(btest(k,7)) go to 11
      chang(i) = findnr(p)
      i = i+1
 11   p = mem(p+2)
      if(p.ne.0) go to 10
c-----------

      k = nblus
      i = 1
c-----------  glowna petla
5000   continue
c  k - adres slowa zerowego prototypu kompilacyjnego
       call zerow(k,case1)
c  sygnal nie ma prototypu
       if(case1.eq.15) go to 5001
c  formalne tez nie maja prototypow
       if(case1.eq.7.or.case1.eq.8.or.case1.eq.-10) go to 5001
       zw = curr+1
       idict(i) = zw
       call getm(4)
c  wypelnienie pierwszych 4-ech slow opisu
c  nazwa
       j = chang(i)
       prot(curr) = prs(2*j-1)
c  case
       prot(zw) = case1
c  SL
       p = mem(k-1)
       prot(zw+1) = findsc(p)-1
c  numer linii
       prot(zw+2) = prs(2*j)
       call getm(10)
       curr = curr+14
       if(case1.eq.14) go to 12
c  handler nie ma prefiksu
       id = mem(k+21)
	j = findsc(id)
       if(j.eq.0) go to 12
       prot(zw+4) = j-1
  12   prot(zw+3) = k
c  k - ident. opisu wstawiany w miejsce przyszlego dispnr
c  wypelniamy tablice hash'u
c  curr - teraz bedzie oznaczlo pierwsze wolne miejsce do tworzenia
c	  elementow listy

	curr1 = curr
	do 101 j=5,12
	prot(zw+j) = curr
	t = k+j+5
	l = mem(t)
  102	if(l.eq.0) go to 151
c  miejsce na element listy
	curr = curr+3
	call getm(3)
	l = mem(l+3)
	go to 102
  151	call getm(1)
	curr = curr+1
 101	continue

c   teraz beda wypelniane elementy listy i tworzone nowe prototypy
c   curr - pierwsze wolne miejsce do tworzenia prototypow
c   curr1 - wskaznik do chodzenia po elementach listy

	do 100 j=5,12
	t = k+j+5
	l = mem(t)
 30	if(l.eq.0) go to 150
c  l - poiter do nastepnego elementu listy
c  element listy hash'u
c  nazwa ze scannera
	prot(curr1) = mem(l)
c  NT/H/C
	prot(curr1+1) = mem(l+1)
	id = mem(l+2)
c  id opisu w ipmem
	call zerow(id,case)
	if(case.eq.7.or.case.eq.8.or.case.eq.-10.or.case.eq.15) goto 250
	if(case.eq.5) go to 200
	if(case.eq.9) go to 400

c  unit - nie bedzie nowego opisu
	prot(curr1+2) = findsc(id)-1
	go to 90

c  zmienna
 200	t = mem(l+1)
	if(btest(t,2)) go to 300
c  nowy opis zmiennej
	prot(curr1+2) = -curr
c  adres bezposredni prototypu debuggera
	call getm(5)
c  wpisanie  numeru opisu do mem(l+1)
	mem(l+1) = curr*8
c  case
	prot(curr) = case
	prot(curr+1) = mem(id-4)
c    process/ coroutine systemowe ?
	p = mem(id-3)
	t = -p
	if(p.eq.nrproc.or.p.eq.nrcor) go to 240
	call zerow(p,t)
	if(t.ne.2.and.t.lt.10) go to 240
c  typ klasowy - nie prymitywny i nie formalny
	t = findsc(mem(id-3))-1
 240	prot(curr+2) = t
c  id prototypu w ipmem zamiast offsetu
	prot(curr+3) = id
c  sl
	prot(curr+4) = findsc(mem(id-1))-1
	curr = curr+5
	go to 90
c  zmienna not taken
300	t = ishft(t,-8)
	prot(curr1+2) = -t
	go to 90

c  stala - nowy opis
 400   call getm(3)
       prot(curr1+2) = -curr
c  -adres bezposredni prototypu debuggera
       prot(curr) = case
c  typ prymitywny
       call zerow(mem(id-3),t)
       prot(curr+1) = t
c  ident. stalej w tablicy stalych
       prot(curr+2) = mem(id-1)
       curr = curr+3
       go to 90

c  proc/fun/typ formalne - nie ma prototypu
 250   if(case.ne.-10) case = -case
       prot(curr1+2) = case

c  nastepny element listy
 90    curr1 = curr1+3
       l = mem(l+3)
       go to 30
c  straznik
 150   curr1 = curr1+1
 100   continue

       i = i+1
5001   continue
       k = mem(k+2)
       if(k.ne.0) go to 5000
c-------------------- koniec wypelniania prototypow

c  skasowanie zapamietanej uprzednio w MEM informacji dla zmiennych

      id = X'0007'
      do 111 i = isfin, lpmem
      k = mem(i)
      do 112 j = 1,8
      t = k+j+9
      l = mem(t)
 110  if(l.eq.0) go to 112
c  wyzerowanie bitow 3-15
      mem(l+1) = iand(mem(l+1),id)
      l = mem(l+3)
      go to 110
 112  continue
 111  continue

c  wypisanie idict
      call out(idict,500)
cps   call out(idict,300)
c  wypisanie ind - ostatnie zajete miejsce w prot
      call out(ind,1)
c  wypisanie prot do miejsca ind
      call out(prot,ind)
      return
      end

      subroutine getm(n)
      implicit integer(a-z)
      common /pr/ prot(5000), ind
c  sprawdza, czy jest jeszcze miejsce w PROT
c  ind - ostatnie zajete
      ind = ind+n
      if(ind.le.5000) return
c  przepelnienie - za duzo prototypow
      call mdrop(41)
      return
      end

      subroutine out(tab,n)
      implicit integer(a-z)
      dimension tab(n)
      call ffwrite_ints(21, tab, n)
      return
      end

      subroutine zerow(kk,id)
      implicit integer(a-z)
      logical btest
      common /BLANK/ com(302), mem(6890)
c  odkodowuje slowo zerowe o adresie kk, wynik na id (case)
c  dla typow prymitywnych wynik = -kk
c  dlA typu uniwersalnego wynik = 0

      k = mem(kk)
c  uniwersalny ?
      if(k.eq.4) go to 300
c  prymitywny ?
      if(btest(k,3)) go to 5
      if(btest(k,1).and..not.btest(k,2)) go to 10
      if(btest(k,2).and..not.btest(k,1).and..not.btest(k,0)) go to 100
      if(btest(k,2).and.btest(k,0).and..not.btest(k,1)) go to 30
      if(btest(k,1).and.btest(k,2).and.btest(k,0)) go to 40
      if(btest(k,2).and.btest(k,1).and..not.btest(k,0)) go to 90
      if(.not.btest(k,2).and..not.btest(k,1).and.btest(k,0)) go to 100

c  typ prymitywny
5     id = -kk
      return
c   klasa lub rekord
 10   id = 12
      if(btest(k,0)) id = 2
      return
c  process
 30   id = 10
      return
c  coroutine
 40   id = 11
      return
c  typ formalny
 90   id = -10
      return
c  stala
 150  id = 9
      return
c  zmienna
 140  id = 5
      return
c  block
 160  id = 1
      return
c  funkcja formalna
 110  id = 7
      return
c  proc. formalna
 120   id = 8
      return
c   funkcja
 170  id = 4
      return
c   procedura
 180  id = 3
      return
c  handler
 190  id = 14
      return
c  sygnal
 155  id = 15
      return
c  nie typ
100   continue
      if(btest(k,7).and..not.btest(K,6).and..not.btest(k,5).and.
     x btest(k,4))go to 140
      if(btest(k,7)) go to 200
      if(btest(k,6)) go to 140
      if(btest(k,5).and..not.btest(k,4)) go to 110
      if(btest(k,5).and.btest(k,4)) go to 120
      if(.not.btest(k,5)) go to 220
c  stala/signal
 200  continue
      if(.not.btest(k,6).and..not.btest(k,5).and..not.btest(k,4))
     x go to 150
      if(.not.btest(k,6).and.btest(k,5).and.btest(k,4)) go to 155
c procedura/funkcja/blok
 220  continue
      if(.not.btest(k,10).and..not.btest(k,9)) go to 160
      if(.not.btest(k,10).and.btest(k,9)) go to 170
      if(btest(k,10).and..not.btest(k,9).and..not.btest(k,8))
     x go to 180
      if(btest(k,10).and.btest(k,9).and.btest(k,8)) go to 190
c  typ uniwersalny
300   id=0
      return
      end

      integer function findnr(id)
      implicit integer(a-z)
      common /BLANK/ com(278),
     x		lmem,lpmem,irecn,isfin,
     x		com1(20),
     x		mem(7890)
      if(id.eq.0) go to 1010
      do 1000 i = isfin,lpmem
      k = mem(i)
c  adres slowa zerowego
      if(k.ne.id) go to 1000
      findnr = i-isfin+1
      return
1000  continue
1010  findnr = 0
      return
      end

      integer function findsc(id)
      implicit integer(a-z)
      common /BLANK/ com(278),
     x		com2(18),
     x		nblus,
     x		com1(5),
     x		mem(7890)
      logical btest
      p = nblus
      i = 1
 100  continue
      if(p.eq.0) go to 120
      k = mem(p)
c  formalne i sygnaly sa pomijane w numeracji
c  formalne
      if(btest(k,4).or.btest(k,5)) go to 111
c  sygnal
      if(btest(k,7)) go to 111
      if(id.eq.p) go to 110
      i = i+1
111   p = mem(p+2)
      go to 100
120   findsc = 0
      return
110   findsc = i
      return
      end

