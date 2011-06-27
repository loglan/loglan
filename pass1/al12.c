/* al12.f -- translated by f2c (version 20090411).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer bottom, valtop, vlprev, stckag, stcka0, stckap[14], apetyt[4], 
	    lstlse, lstfor, kind, phadr, lastpr, fstout, consnr[8], lstsaf, 
	    lstemp, tempnr, lstwrd, qrecnr, wb, result, frstts, unit, inner;
    logical lstwill, test;
    integer arg, atline, file, flargs, flmodf;
    logical flready;
    integer icount, ocount;
} stos_;

#define stos_1 stos_

struct {
    integer optmem;
    logical optopt;
    integer optind;
    logical opttyp, opttrc;
    integer optcsc, optcsf;
} option_;

#define option_1 option_

struct {
    integer iop[4], p, tldim, tlbas, idl, objl, trdim, trbas, idr, objr, 
	    treslt, convl, convr, nrpar, ix[261], lmem, lpmem, irecn, isfin, 
	    lpmsys, lpml, lpmf, nrint, nrre, nrbool, nrchr, nrcor, nrproc, 
	    nrtext, nruniv, nattr, nrnone, nblsys, nblus, nempty;
    logical insys;
    integer local;
    logical own;
    integer object, ipmem[5000];
} blank_;

#define blank_1 blank_

struct {
    integer free;
} summary_;

#define summary_1 summary_

struct {
    integer mtp, mspr, mothers, mpar, masktp, nottp, mproces, mcor, merpf, 
	    mblock, mhand, mnotvir;
} masks_;

#define masks_1 masks_

struct {
    logical testc, tests, testh;
} test_;

#define test_1 test_

union {
    struct {
	integer errflg, line, ibuf2[265], ibuf3[7], junk[260];
    } _1;
    struct {
	logical errflg;
	integer line, ibuf2[265], ibuf3[7], junk[260];
    } _2;
} stream_;

#define stream_1 (stream_._1)
#define stream_2 (stream_._2)

struct {
    integer btsins, btstem;
} stacks_;

#define stacks_1 stacks_

struct {
    integer ind, length;
    shortint bigbuf[16000];
} combuf_;

#define combuf_1 combuf_

/* Table of constant values */

static integer c__150 = 150;
static integer c__1 = 1;
static integer c__170 = 170;
static integer c__0 = 0;
static logical c_true = TRUE_;
static integer c__52 = 52;
static integer c__4 = 4;
static integer c__43 = 43;
static integer c__144 = 144;
static integer c__58 = 58;
static integer c__408 = 408;
static integer c__59 = 59;
static integer c__550 = 550;
static integer c__199 = 199;
static integer c__554 = 554;
static integer c__197 = 197;
static logical c_false = FALSE_;
static integer c__2 = 2;
static integer c__21 = 21;
static integer c__222 = 222;
static integer c__453 = 453;
static integer c__450 = 450;
static integer c__54 = 54;
static integer c__143 = 143;
static integer c__145 = 145;
static integer c__132 = 132;
static integer c__47 = 47;
static integer c__85 = 85;
static integer c__23 = 23;
static integer c__15 = 15;
static integer c__87 = 87;
static integer c__60 = 60;
static integer c__16 = 16;
static integer c__3 = 3;
static integer c__228 = 228;
static integer c__20 = 20;
static integer c__40 = 40;
static integer c__195 = 195;
static integer c__504 = 504;
static integer c__158 = 158;
static integer c__13 = 13;
static integer c__8 = 8;
static integer c__18 = 18;
static integer c__256 = 256;
static integer c__6 = 6;
static integer c__553 = 553;
static integer c__80 = 80;
static integer c__302 = 302;

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* Subroutine */ int sparam_(void)
{
    /* Initialized data */

    static integer sparahex = 2048;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer k, n, ats, elem, apet;
    extern /* Subroutine */ int spop_(void);
    static integer param;
#define stack ((integer *)&blank_1 + 302)
    extern integer sapet_(integer *, integer *);
    extern /* Subroutine */ int svint_(integer *), quadr3_(integer *, integer 
	    *, integer *), quadr4_(integer *, integer *, integer *, integer *)
	    ;
    extern integer screal_(integer *);
    extern /* Subroutine */ int sphadr_(integer *);
    extern integer mpkind_(integer *);
    extern /* Subroutine */ int mparpf_(integer *, integer *, integer *, 
	    logical *);
    extern integer mpario_(integer *, integer *, integer *, integer *);
    static logical dcontr;
#define staler ((real *)&blank_1 + 302)
    static integer contrl, lnrpar;
    extern /* Subroutine */ int svalue_(void), svreal_(integer *);
    extern integer sconst_(integer *), sparst_(integer *), sparft_(integer *, 
	    integer *), sfprst_(integer *);
    extern /* Subroutine */ int mpartp_(integer *, integer *, integer *, 
	    integer *);
    extern integer stypst_(integer *), sprfld_(logical *);
    extern /* Subroutine */ int serror_(integer *);
    extern integer tstemp_(integer *);
    static integer parkind;
    extern /* Subroutine */ int savevar_(integer *);

/* ----------------------------------------------------------------------------- */

/*     WERSJA 1982.09.16 */

/*     OBSLUGUJE TRANSMISJE I KONTROLE PARAMETRU AKTUALNEGO. */
/*     NA CZUBKU STOSU JEST PARAMETR AKTUALNY, PONIZEJ WOLANA FUNKCJA, */
/*      PROCEDURA,KLASA,REKORD,BLOK PREFIKSOWANY. */
/*     PO OBSLUZENIU PARAMETRU ZDEJMUJE GO ZE STOSU. */
/*     NIE WOLA SNEXT. */

/*     UZYWANA ROWNIEZ DLA PROCEDUR I FUNKCJI STANDARDOWYCH. */
/* 	   / TYLKO PARAMETRY INPUT, OUTPUT, IN-OUT / . */


/*     KOLEJNOSC OBSLUGI PARAMETRU : */
/* 	 1) WOLA MPKIND OKRESLAJACE RODZAJ PARAMETRU : */
/* 	       0 - UNIWERSALNY */
/* 	       1 - INPUT */
/* 	       2 - OUTPUT */
/* 	       3 - TYPE */
/* 	       4 - FUNKCJA */
/* 	       5 - PROCEDURA */
/* 	       6 - IN-OUT */
/* 	   I PRZYPISUJE PARAM ADRES OPISU PAR.FORMALNEGO W IPMEM */

/* 	 2) JESLI PAR.FORMALNY JEST UNIWERSALNY LUB PAR.AKTUALNY JEST */
/* 	    UNIWERSALNY LUB NIEWLASCIWEGO RODZAJU, A PAR.FORM. <> "TYPE"  - */
/* 	      NIE ROBI NIC    /POZA SYGNALIZACJA BLEDU/ */

/* 	 3) DLA PAR. INPUT : WOLA MPARIO /BADA ZGODNOSC TYPOW/ ,GENERUJE KOD */
/* 	      EWENT. KONWERSJI LUB KONTROLI DYNAMICZNEJ I WPISUJE WARTOSC PAR. */
/* 	      AKTUALNEGO DO GENEROWANEGO POLA DANYCH /DLA STALYCH REPREZENTO- */
/* 	       WANYCH PRZEZ ZERA NIE WPISUJE NICZEGO/. */
/* 		DLA PROCEDURY,FUNKCJI STANDARDOWEJ NIE WPISUJE WARTOSCI */
/* 		 PARAMETRU, LECZ ZAMIENIA NA STOSIE PARAMETR I PROCEDURE */
/* 		 /FUNKCJE/ MIEJSCAMI, DZIEKI CZEMU PROCEDURA JEST NA STOSIE */
/* 		 NAD WSZYTKIMI JUZ PRZETWORZONYMI PARAMETRAMI INPUT. */


/* 	    DLA PAR. OUTPUT : WOLA MPARIO,ZABEZPIECZA ADRES ZMIENNEJ /ADR. */
/* 		TABLICY I INDEKS,ADR. PRZED KROPKA/ I TYP FORMALNY,WPISUJE */
/* 		OPIS PARAMETRU NA STOS I ZWIEKSZA LICZNIK PARAMETROW OUTPUT */
/* 		/JESLI BRAK MIEJSCA NA OPIS - NIE ZWIEKSZA/ */

/* 	    DLA PAR. TYPE : WOLA MPARTP / ZAWSZE! ,DLA PAR.AKT. NIEPOPRAWNEGO */
/* 		LUB UNIWERSALNEGO PODAJE NRUNIV/ I WPISUJE TYP DO POLA DANYCH */

/* 	    DLA PAR. FUNCTION,PROCEDURE : WOLA MPARPF , */
/* 		    USTAWIA KIND , WOLA SPRFLD /GENERUJACA PROTOTYP */
/* 		  WRAZ Z OTOCZENIEM/ */
/* 	     WPISUJE PROTOTYP I OTOCZENIE PAR.AKTUALNEGO DO POLA DANYCH, */
/* 	       EW. GENERUJE DYNAMICZNA	KONTROLE ZGODNOSCI NAGLOWKOW. */

/* 	    DLA PAR. IN-OUT : NAJPIERW OBSLUGUJE GO JAK PAR. OUTPUT, */
/* 		       A NASTEPNIE JAK PAR.INPUT */

/*     UZYWA: PHADR , NRPAR */


/*     # OUTPUT CODE : 43 , 52 , 144 , 150 , 161 , 162 , 163 , */
/* 			 164 , 165 , 166 , 170 . */

/*     ##### DETECTED ERROR(S) : 470 , 471 , 472 , 473 , 474 , 478 , 550 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */

/* CCCCCCCCCCCCCCCCCCCCC */
/*     PARAM = ADRES W IPMEM OPISU PARAMETRU FORMALNEGO */
/*     APET = LICZBA SLOW NA PARAMETR FORMALNY */
/*     CONTRL = INFORMACJA O KONWERSJI LUB KONTROLI DYNAMICZNEJ */
/*     ATS = ATS WARTOSCI PAR. LUB ADR.FIZYCZNY DLA NIEZNANEGO OFFSETU */
/*     PARKIND = RODZAJ PAR.FORMALNEGO, 1..7 ,=MPKIND( )+1 */
/*     ELEM = RODZAJ ELEMNTU Z CZUBKA STOSU */

/*     =.TRUE. JESLI KONIECZNA DYNAMICZNA KONTROLA NAGLOWKOW PROC.,FUNC. */

/* ............... */
    dcontr = FALSE_;
/*     RODZAJ PAR.AKTUALNEGO ? */
    elem = stack[stos_1.valtop - 1];
/*     RODZAJ PAR.FORMALNEGO ? */
    parkind = mpkind_(&param) + 1;
/*     JESLI PAR.AKTUALNY UNIWERSALNY-POMIN */
    if (elem == 0 && parkind != 4) {
	goto L9905;
    }
    switch (parkind) {
	case 1:  goto L9905;
	case 2:  goto L1000;
	case 3:  goto L2000;
	case 4:  goto L3000;
	case 5:  goto L4000;
	case 6:  goto L4000;
	case 7:  goto L2000;
    }



/* - - - - - - - - - - PAR. I N - O U T - - - - - - - */

/*     ZMIEN KWALIFIKACJE NA INPUT /KOD ODCZYTUJACY WARTOSC JUZ WYGENEROWANY/ */

L990:
    parkind = 2;


/* -------------------- PAR. I N P U T ------------ */
/*     CZY POPRAWNY PAR. AKTUALNY? */
L1000:
    if (elem < 6 || elem == 12) {
	goto L1003;
    }
/*     NIEPOPRAWNY PAR. AKTUALNY */
    param = 470;
    goto L9600;
L1003:
    lnrpar = blank_1.nrpar;
/*     PRZECHOWAJ NUMER PARAMETRU: NA CZUBKU MOZE BYC FUNKCJA BEZPARAMETROWA, */
/*     ODCZYT JEJ WARTOSCI MOZE ZNISZCZYC NRPAR */
    svalue_();
    blank_1.nrpar = lnrpar;
/*     SPRAWDZ ZGODNOSC TYPOW */
    contrl = mpario_(&stack[stos_1.valtop - 4], &stack[stos_1.valtop - 5], &
	    stack[stos_1.valtop - 2], &stack[stos_1.valtop - 7]);
    apet = sapet_(&blank_1.ipmem[param - 5], &blank_1.ipmem[param - 4]);
    if (contrl == 1) {
	svint_(&stos_1.valtop);
    }
    if (contrl == 2) {
	svreal_(&stos_1.valtop);
    }
    ats = stack[stos_1.valtop - 3];
/*     ATS WARTOSCI PARAMETRU */
/* .....FUNKCJA,PROCEDURA STANDARDOWA ? */
    if (stack[stos_1.vlprev - 5] < blank_1.lpmsys) {
	goto L1800;
    }
/*     NIE. */
    sphadr_(&stos_1.vlprev);
/*     CZY PAR.AKTUALNY JEST STALA? */
    if (elem == 1) {
	switch (apet) {
	    case 1:  goto L1007;
	    case 2:  goto L1008;
	    case 3:  goto L9905;
	    case 4:  goto L9905;
	}
    }

/*     PARAMETR NIE JEST STALA */
    apet = stos_1.apetyt[apet - 1];
    goto L1050;


/* .....PAR.AKTUALNY JEST STALA. JESLI REPREZENTOWANA PRZEZ ZERA - NIC NIE */
/* 	ROB /INICJALIZACJA POLA WPISALA ZERA/ */
/* ... APETYT 1 ( INTEGER,BOOLEAN,CHAR,STRING ) */
L1007:
    if (ats == 0) {
	goto L9905;
    }
/*     WSTAW STALA INTEGER,SKOCZ DO WPISANIA WARTOSCI PARAMETRU */
    ats = sconst_(&ats);
    goto L9750;
/* ... APETYT 2 ( REAL - TYP FORMALNY TU NIE WYSTAPI ) */
/* dsw&bc    1008 IF(STALER(ATS).EQ. 0.0)GO TO 9905 */
L1008:

/*     WSTAW STALA REAL, SKOCZ DO WPISANIA WARTOSCI */
    ats = screal_(&ats);
    goto L9750;


/* .....JESLI NIEPOTRZEBNA KONTROLA DYNAMICZNA - WPISZ WARTOSC */
L1050:
    if (contrl < 3 || option_1.opttyp) {
	goto L9750;
    }
    contrl += -2;

    blank_1.idr = stack[stos_1.valtop - 6];
/*     IDR = ZMODYFIKOWANY TYP FORMALNY PARAMETRU AKTUALNEGO LUB ZERO */

/*     CZY ZNANY OFFSET? /NIE,JESLI TO VIRTUAL LUB PARAMETR/ */
    if (stack[stos_1.vlprev - 4] >= 16384) {
	goto L1500;
    }


/* .....ZNANY OFFSET PARAMETRU. */

    switch (contrl) {
	case 1:  goto L1100;
	case 2:  goto L1200;
	case 3:  goto L1300;
	case 4:  goto L1400;
    }
/* .....KONTROLA DYNAMICZNA, OBA TYPY ZNANE */
L1100:
    quadr3_(&c__150, &ats, &blank_1.ipmem[param - 4]);
    goto L9800;
/* .....KONTROLA DYN.,TYP PAR.FORMALNEGO JEST FORMALNY,AKTUALNEGO ZNANY */
L1200:
    blank_1.idr = stypst_(&stos_1.valtop);
    goto L1400;
/* .....KONTROLA DYN.,TYP PAR.FORMALNEGO JEST ZNANY,AKTUALNEGO FORMALNY */
L1300:
    n = sparst_(&param);
    goto L1450;
/* .....KONTROLA DYN.,TYPY PAR.FORMALNEGO I AKTUALNEGO SA FORMALNE */
/* dsw 1400 N=SPARFT(PARAM) */
/* dsw  ----------------------- */
L1400:
    n = sparft_(&param, &c__1);
/* dsw  ------------------------ */
L1450:
    quadr4_(&c__170, &n, &ats, &blank_1.idr);
    goto L9800;


/* ..............NIEZNANY OFFSET PARAMETRU. */
/* 		     - TYP PAR.FORMALNEGO TRZEBA ODCZYTAC */
/*     IDL,IDR = TYPY PAR.FORMALNEGO I AKTUALNEGO */
L1500:
    sphadr_(&stos_1.vlprev);
    if (contrl < 3) {
	blank_1.idr = stypst_(&stos_1.valtop);
    }
    i__1 = sfprst_(&blank_1.nrpar);
    quadr4_(&c__170, &i__1, &ats, &blank_1.idr);
    goto L9700;

/* .........PARAMETR INPUT PROCEDURY, FUNKCJI STANDARDOWEJ. */
/*     ZAMIEN MIEJSCAMI OPISY PARAMETRU I FUNKCJI, TAK , BY FUNKCJA */
/* 	BYLA NAD SWOIMI ARGUMENTAMI.  / OBA OPISY ZAJMUJA PO 8 SLOW / */

L1800:
    for (k = 0; k <= 7; ++k) {
	blank_1.idr = stos_1.valtop - k;
	blank_1.idl = stos_1.vlprev - k;
	n = stack[blank_1.idr - 1];
	stack[blank_1.idr - 1] = stack[blank_1.idl - 1];
	stack[blank_1.idl - 1] = n;
/* L1810: */
    }
/*     NA CZUBKU JEST FUNKCJA,PROCEDURA STANDARDOWA */
/*     ZWIEKSZ LICZNIK PARAMETROW INPUT /SLOWO -2/ */
    ++stack[stos_1.valtop - 3];
/*     WPISZ NUMER PARAMETRU DO SLOWA -1 */
    stack[stos_1.vlprev - 2] = blank_1.nrpar;
    return 0;


/* -------------------- PAR. O U T P U T --------------- */

/*     CZY PAR. AKTUALNY TO LSE? */
L2000:
    if (elem > 2 && elem < 6) {
	goto L2005;
    }
/*     NIEPOPRAWNY PARAMETR /AKTUALNY/ OUTPUT */
    param = 471;
    goto L9600;
/*      O.K.	  SPRAWDZ ZGODNOSC TYPOW */
L2005:
    contrl = mpario_(&stack[stos_1.valtop - 4], &stack[stos_1.valtop - 5], &
	    stack[stos_1.valtop - 2], &stack[stos_1.valtop - 7]);
/*     ZABEZPIECZ ADRES ZMIENNEJ */
    savevar_(&stos_1.valtop);
/* .....WPISZ OPIS PARAMETRU AKTUALNEGO. CZY JEST MIEJSCE? */
    if (stos_1.fstout - stos_1.valtop >= 11) {
	goto L2110;
    }
/*      BRAK MIEJSCA NA STOSIE NA DODATKOWE INFORMACJE O PARAMETRZE. */
    param = 550;
    goto L9600;
/*     O.K. JEST MIEJSCE */
L2110:
/*     ZWIEKSZ LICZNIK PARAMETROW OUTPUT */
    ++stack[stos_1.vlprev - 4];
/*     POSTAC OPISU PARAMETRU OUTPUT: */
/* 	     OPIS ZAJMUJE 11 SLOW, OZNACZONYCH -9,..,0,+1 */
/* 	     SLOWA -9..0 ZAWIERAJA PRZEPISANY PAR.AKTUALNY */
/* 	      /DLA ZMIENNEJ I ELEM.TABLICY SLOWA -9,-8 POZOSTAJA */
/* 	       NIEWYKORZYSTANE/ */
/* 	     SLOWO -1 ZAMIAST NAZWY ZAWIERA ADRES W IPMEM OPISU PARAMETRU */
/* 		      FORMALNEGO */
/* 	     SLOWO +1 = NUMER PARAMETRU /NRPAR/ */
/* 	     SLOWO 0 W BITACH 9-11 INFORMACJE O KONTROLI /MPARIO(..)/ */

/*     WPISZ NUMER PARAMETRU */
    stack[stos_1.fstout - 2] = blank_1.nrpar;
/*     WPISZ RODZAJ ELEMENTU Z INFORMACJA O KONTROLI W BITACH 9-11 */
    stack[stos_1.fstout - 3] = elem + (contrl << 4);
/*     WPISZ ADRES OPISU PAR.FORMALNEGO */
    stack[stos_1.fstout - 4] = param;
/*     PRZEPISZ POZOSTALE 8 SLOW /BYC MOZE OSTATNIE 2 TO SMIECIE/ */
/*     APET,CONTRL = DOLNY,GORNY INDEKS */
    apet = stos_1.valtop - 2;
    contrl = stos_1.fstout - 4;
L2115:
    stack[contrl - 1] = stack[apet - 1];
    --apet;
    --contrl;
    if (contrl > stos_1.fstout - 12) {
	goto L2115;
    }
/*     SLOWA VALTOP-0,..,VALTOP-9 PRZEPISANE NA MIEJSCA FSTOUT-2,..,FSTOUT-11. */

    stos_1.fstout += -11;
    goto L9905;

/* -------------------- PAR. T Y P E --------------------- */

/*     CZY PAR.AKTUALNY TO NAZWA TYPU,REKORD,KLASA? */
L3000:
    if (elem < 7 || elem > 9) {
	goto L3800;
    }
/*     O.K. */
    mpartp_(&stack[stos_1.valtop - 4], &stack[stos_1.valtop - 5], &stack[
	    stos_1.valtop - 7], &stack[stos_1.valtop - 2]);
/*     POBIERZ TYP */
    ats = stack[stos_1.valtop - 3];
/*     =0 : KLASA,REKORD,TYP PIERWOTNY */
/*     >0 : ATS WARTOSCI PAR.TYPE LUB PARAMETRU TYPE */
    if (ats == 0) {
	ats = stypst_(&stos_1.valtop);
    }
    apet = 2;
    goto L9750;

/* .....UNIWERSALNY LUB NIEPOPRAWNY PARAMETR TYPE */
L3800:
    mpartp_(&c__0, &blank_1.nruniv, &c__0, &stack[stos_1.valtop - 2]);
    if (elem == 0) {
	goto L9905;
    }
    param = 472;
    goto L9600;

/* ------------- PAR. F U N C T I O N , P R O C E D U R E ------ */

/*     CZY PAR.AKTUALNY JEST FUNKCJA LUB PROCEDURA? */
L4000:
    if (elem == 11 || elem == 12) {
	goto L4010;
    }
/*     NIEPOPRAWNY PAR. AKTUALNY */
    param = 479 - parkind;
/*     = 473 LUB 474 */
    goto L9600;
/*     FUNKCJA LUB PROCEDURA. */
L4010:
    apet = stack[stos_1.valtop - 5];
/*      = ADRES OPISU FUNKCJI,PROCEDURY */
/*     CZY PAR.AKTUALNY JEST FUNKCJA,PROCEDURA STANDARDOWA ? */
    if (apet >= blank_1.lpmsys) {
	goto L4020;
    }
/*     NIESTETY, TAK. */
    param = 478;
    goto L9600;
L4020:
    mparpf_(&apet, &stack[stos_1.valtop - 2], &stack[stos_1.valtop - 7], &
	    dcontr);
/*     JAKIEGO RODZAJU? */
    stos_1.kind = 0;
/*     WEZ ZEROWE SLOWO OPISU */
    apet = blank_1.ipmem[apet - 1];
/*     VIRTUALNA,JESLI BIT 4 = 1 */
    if ((apet & sparahex) != 0) {
	stos_1.kind = 1;
    }
/*      LUB FORMALNA , JESLI BITY 8..11 = 2 LUB 3. WEZ TE BITY */
    apet = lbit_shift(apet, (ftnlen)-4) & 15;
    if (apet == 2 || apet == 3) {
	stos_1.kind = 2;
    }
/*     WYLICZ NUMER PROTOTYPU I OJCA SYNTAKTYCZNEGO PARAMETRU */
    ats = sprfld_(&c_true);
    apet = 3;
    goto L9750;



/* ------------------------------- */


/* .....WSPOLNA SYGNALIZACJA BLEDU. */
/*     PARAM= NUMER BLEDU */
L9600:
    serror_(&param);
    goto L9905;


/* .....WPISANIE WARTOSCI PARAMETRU Z NIEZNANYM OFFSETEM */
L9700:
    contrl = tstemp_(&c__1);
    sphadr_(&stos_1.vlprev);
/*     WEZ ADRES FIZYCZNY PARAMETRU */
    quadr4_(&c__52, &contrl, &stos_1.phadr, &blank_1.nrpar);
/*     WPISZ WARTOSC POD TEN ADRES */
    i__1 = apet + 160;
    quadr3_(&i__1, &contrl, &ats);
    goto L9900;

/* .....WPISANIE WARTOSCI. CZY ZNANY OFFSET? */
L9750:
    if (stack[stos_1.vlprev - 4] >= 16384) {
	goto L9700;
    }

/* .....WPISANIE WARTOSCI PARAMETRU ZE ZNANYM OFFSETEM */
L9800:
    sphadr_(&stos_1.vlprev);
    i__1 = apet + 163;
    quadr4_(&i__1, &stos_1.phadr, &ats, &param);
/*     WPISZ APET-SLOW DO POLA WSKAZANEGO PRZEZ ADRES FIZYCZNY PHADR */


/* .....JUZ PO WSZYSTKIM-LUB PARAMETR UNIWERSALNY. */
/*     CZY DYNAMICZNA KONTROLA NAGLOWKOW? */
L9900:
    if (! dcontr) {
	goto L9905;
    }
/*     TAK. ODTWORZ PELNY ADRES VIRTUALNY Z AH */
    apet = tstemp_(&c__4);
    quadr3_(&c__43, &apet, &stack[stos_1.vlprev - 3]);
    stack[stos_1.vlprev - 3] = apet;
    quadr3_(&c__144, &apet, &blank_1.nrpar);
    stos_1.phadr = 0;


/* ... JESLI TO IN-OUT ,TO POTRAKTUJ GO TERAZ JAK INPUT */
L9905:
    if (parkind == 7) {
	goto L990;
    }
    spop_();

    return 0;
} /* sparam_ */

#undef staler
#undef stack


/* Subroutine */ int svalu2_(void)
{
    /* Initialized data */

    static integer er[8] = { 452,451,451,0,450,0,453,454 };

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer k, ats, elem, apet;
#define stack ((integer *)&blank_1 + 302)
    static integer dswap;
    extern integer sapet2_(integer *);
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *), serro2_(
	    integer *, integer *), scallb_(void);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *), stypft_(integer *), sarray_(integer *),
	     smember_(integer *);

/* ----------------------------------------------------------------------------- */
/* dsw  procedura podzielona na svalue i svalue2 - entry usuniete */

/*     ENTRY SVALUE */


/*     SPRAWDZA,CZY ELEMENT Z CZUBKA STOSU /SVALUE/ LUB PONIZEJ /SVALU2/ */
/*     REPREZENTUJE WARTOSC I WYLICZA TE WARTOSC. */
/*     "UNIWERSALNY","STALA","WARTOSC" ZOSTAWIA BEZ ZMIAN. */
/*     "ZMIENNA","ELEMTABLICY","TABLICA STATYCZNA","FUNKCJA"/BEZPARAMETROWA/ */
/* 	ZASTEPUJE PRZEZ "WARTOSC" I JESLI SA TYPU FORMALNEGO TO POBIERA */
/*     TEN TYP.	NIE MODYFIKUJE GO O LICZBE ARRAY-OF. */
/*     POZOSTALE ZASTEPUJE PRZEZ "UNIWERSALNY" SYGNALIZUJAC BLAD. */

/* 	WEJSCIE SVALUE - DLA CZUBKA STOSU */
/* 	WEJSCIE SVALU2 - DLA ELEMENTU PONIZEJ CZUBKA */

/*     ##### OUTPUT CODE : 61 , 62 , 63 , 84 , 85 , 86 . */

/*     ##### DETECTED ERROR(S) : 450, 451, 452 , 453 , 454 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */

/* CCCCCCCCCCCCCCCCCCC */
/*      NUMERY BLEDOW "NIELEGALNE WYSTAPIENIE ... " */


    k = stos_1.vlprev;
/* L100: */
    elem = stack[k - 1] - 2;
/*     JESLI UNIWERSALNY,STALA,WARTOSC - KONIEC */
    if (elem <= 0) {
	return 0;
    }

/*     JESLI TYPU FORMALNEGO - WEZ TEN TYP */
    if (stack[k - 6] != 0) {
	stack[k - 6] = stypft_(&k);
    }

/*     ZMIENNA PROSTA? */
    if (elem == 1 && stack[k - 8] == 0) {
	goto L350;
    }
    if (elem > 3) {
	goto L600;
    }

/*     WEZ NOWY ATS NA WARTOSC,WYZNACZ APETYT */
    apet = sapet2_(&k);
/* vax  changed because of real appettite = 1 */
    dswap = apet;
    if (dswap == 2) {
	dswap = 1;
    }
    ats = tstemp_(&dswap);
    apet = stos_1.apetyt[apet - 1];
    switch (elem) {
	case 1:  goto L300;
	case 2:  goto L400;
	case 3:  goto L500;
    }
/* .....ZMIENNA PRZEZ KROPKE. ODCZYTAJ APET-SLOW. */
L300:
    i__1 = apet + 83;
    i__2 = smember_(&k);
    quadr4_(&i__1, &ats, &i__2, &stack[k - 3]);
/*     ZASTAP PRZEZ WARTOSC */
L340:
    stack[k - 3] = ats;
L350:
    stack[k - 1] = 2;
    return 0;

/* .....ELEM. TABLICY */
L400:
    i__1 = apet + 60;
    i__2 = sarray_(&k);
    quadr3_(&i__1, &ats, &i__2);
    goto L340;

/* .....TABLICA STATYCZNA */
L500:
/*     B R A K */
/* ........... */
/*     JESLI NA CZUBKU NIE FUNKCJA, TO BLAD */
L600:
    if (elem != 10) {
	goto L3000;
    }
/*     FUNKCJA. /BEZPARAMETROWA/ */
    scallb_();
/*     I TO WSZYSTKO. */
    return 0;

/* .....OBSLUGA BLEDOW */
L3000:
    elem = er[elem - 5];
    serro2_(&elem, &k);
/*     ZASTAP ELEMENT PRZEZ "UNIWERSALNY",ZACHOWAJ NAZWE. */
    stack[k - 1] = 0;
    return 0;
} /* svalu2_ */

#undef staler
#undef stack


/* Subroutine */ int svalue_(void)
{
    /* Initialized data */

    static integer er[8] = { 452,451,451,0,450,0,453,454 };

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer k, ats, elem, apet;
#define stack ((integer *)&blank_1 + 302)
    static integer dswap;
    extern integer sapet2_(integer *);
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *), serro2_(
	    integer *, integer *), scallb_(void);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *), stypft_(integer *), sarray_(integer *),
	     smember_(integer *);

/* ----------------------------------------------------------------------------- */
/* dsw  procedura podzielona na svalue i svalue2 - entry usuniete */

/*     ENTRY SVALUE */


/*     SPRAWDZA,CZY ELEMENT Z CZUBKA STOSU /SVALUE/ LUB PONIZEJ /SVALU2/ */
/*     REPREZENTUJE WARTOSC I WYLICZA TE WARTOSC. */
/*     "UNIWERSALNY","STALA","WARTOSC" ZOSTAWIA BEZ ZMIAN. */
/*     "ZMIENNA","ELEMTABLICY","TABLICA STATYCZNA","FUNKCJA"/BEZPARAMETROWA/ */
/* 	ZASTEPUJE PRZEZ "WARTOSC" I JESLI SA TYPU FORMALNEGO TO POBIERA */
/*     TEN TYP.	NIE MODYFIKUJE GO O LICZBE ARRAY-OF. */
/*     POZOSTALE ZASTEPUJE PRZEZ "UNIWERSALNY" SYGNALIZUJAC BLAD. */

/* 	WEJSCIE SVALUE - DLA CZUBKA STOSU */
/* 	WEJSCIE SVALU2 - DLA ELEMENTU PONIZEJ CZUBKA */

/*     ##### OUTPUT CODE : 61 , 62 , 63 , 84 , 85 , 86 . */

/*     ##### DETECTED ERROR(S) : 450, 451, 452 , 453 , 454 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */

/* CCCCCCCCCCCCCCCCCCC */
/*      NUMERY BLEDOW "NIELEGALNE WYSTAPIENIE ... " */

    k = stos_1.valtop;
/* L100: */
    elem = stack[k - 1] - 2;
/*     JESLI UNIWERSALNY,STALA,WARTOSC - KONIEC */
    if (elem <= 0) {
	return 0;
    }

/*     JESLI TYPU FORMALNEGO - WEZ TEN TYP */
    if (stack[k - 6] != 0) {
	stack[k - 6] = stypft_(&k);
    }

/*     ZMIENNA PROSTA? */
    if (elem == 1 && stack[k - 8] == 0) {
	goto L350;
    }
    if (elem > 3) {
	goto L600;
    }

/*     WEZ NOWY ATS NA WARTOSC,WYZNACZ APETYT */
    apet = sapet2_(&k);
/* vax  changed with real appetite = 1 */
    dswap = apet;
    if (dswap == 2) {
	dswap = 1;
    }
    ats = tstemp_(&dswap);
    apet = stos_1.apetyt[apet - 1];
    switch (elem) {
	case 1:  goto L300;
	case 2:  goto L400;
	case 3:  goto L500;
    }
/* .....ZMIENNA PRZEZ KROPKE. ODCZYTAJ APET-SLOW. */
L300:
    i__1 = apet + 83;
    i__2 = smember_(&k);
    quadr4_(&i__1, &ats, &i__2, &stack[k - 3]);
/*     ZASTAP PRZEZ WARTOSC */
L340:
    stack[k - 3] = ats;
L350:
    stack[k - 1] = 2;
    return 0;

/* .....ELEM. TABLICY */
L400:
    i__1 = apet + 60;
    i__2 = sarray_(&k);
    quadr3_(&i__1, &ats, &i__2);
    goto L340;

/* .....TABLICA STATYCZNA */
L500:
/*     B R A K */
/* ........... */
/*     JESLI NA CZUBKU NIE FUNKCJA, TO BLAD */
L600:
    if (elem != 10) {
	goto L3000;
    }
/*     FUNKCJA. /BEZPARAMETROWA/ */
    scallb_();
/*     I TO WSZYSTKO. */
    return 0;

/* .....OBSLUGA BLEDOW */
L3000:
    elem = er[elem - 5];
    serro2_(&elem, &k);
/*     ZASTAP ELEMENT PRZEZ "UNIWERSALNY",ZACHOWAJ NAZWE. */
    stack[k - 1] = 0;
    return 0;
} /* svalue_ */

#undef staler
#undef stack


/* Subroutine */ int svint_(integer *elem)
{
    /* Initialized data */

    static integer maxinteger = 2147483647;
    static integer mininteger = -2147483648;

    /* System generated locals */
    static real equiv_2[1];

    /* Local variables */
#define m ((shortint *)equiv_2)
    static integer n;
    static real x;
#define y (equiv_2)
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    serro2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* ----------------------------------------------------------------------------- */

/*     POMOCNICZA. ZASTEPUJE ELEMENT Z MIEJSCA ELEM STOSU /STALA, */
/*     WARTOSC,ZMIENNA/ TYPU REAL PRZEZ STALA LUB WARTOSC TYPU INTEGER. */
/*     GENERUJE KOD KONWERSJI. */
/*     W PRZYPADKU STALEJ REAL O WARTOSCI WYKRACZAJACEJ POZA ZAKRES LICZB */
/*      CALKOWITYCH SYGNALIZUJE ERROR 408  I ZASTEPUJE PRZEZ STALA INTEGER */
/* 	O TYM SAMYM ZNAKU I NAJWIEKSZYM MOZLIWYM MODULE. */

/*     ##### OUTPUT CODE : 58 . */

/*     ##### DETECTED ERROR(S) : 408 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */






/* ..... */
    stack[(1208 + (0 + (*elem - 4 - 1 << 2)) - 1208) / 4] = blank_1.nrint;
/*     CZY STALA? */
    if (stack[*elem - 1] != 1) {
	goto L100;
    }
/*     TAK */
    n = stack[*elem - 3];
/*     SPRAWDZ WARTOSC STALEJ */
    x = staler[n - 1];

    if (x < (real) mininteger || x > (real) maxinteger) {
	goto L200;
    }
/* JF	 STACK(ELEM-2)=IFIX(X) */
/* dsw  STACK(ELEM-2)= IIDINT(X) */
    stack[*elem - 3] = (integer) x;
    return 0;
/*     WARTOSC LUB ZMIENNA;    GENERUJ KONWERSJE */
L100:
    n = tstemp_(&c__1);
    quadr3_(&c__58, &n, &stack[*elem - 3]);
    stack[*elem - 3] = n;
    stack[*elem - 1] = 2;
    return 0;
/*     STALA REAL O WARTOSCI POZA ZAKRESEM LICZB CALKOWITYCH */
L200:
    serro2_(&c__408, elem);
/*     ZASTAP PRZEZ NAJWIEKSZA LICZBE CALKOWITA */
    n = maxinteger;
    if (x < 0.f) {
	n = mininteger;
    }
    stack[*elem - 3] = n;
    return 0;
} /* svint_ */

#undef staler
#undef stack
#undef y
#undef m


/* Subroutine */ int svreal_(integer *elem)
{
    /* System generated locals */
    real r__1;

    /* Local variables */
    static integer n;
    extern integer creal_(real *);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* ----------------------------------------------------------------------------- */

/*     POMOCNICZA. ZASTEPUJE ELEMENT /STALA,WARTOSC,ZMIENNA/ Z MIEJSCA */
/*     ELEM STOSU TYPU INTEGER PRZEZ STALA LUB WARTOSC TYPU REAL. */

/*     ##### OUTPUT CODE : 59 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



    stack[*elem - 5] = blank_1.nrre;
/*     CZY TO STALA? */
    if (stack[*elem - 1] != 1) {
	goto L100;
    }
/*     TAK */
    r__1 = (real) stack[*elem - 3];
    stack[*elem - 3] = creal_(&r__1);
    return 0;
/*     WARTOSC,ZMIENNA;	      GENERUJ KONWERSJE */
L100:
    n = tstemp_(&c__1);
    quadr3_(&c__59, &n, &stack[*elem - 3]);
    stack[*elem - 3] = n;
    stack[*elem - 1] = 2;
    return 0;
} /* svreal_ */

#undef staler
#undef stack


/* Subroutine */ int spush_(integer *elem)
{
    /* Local variables */
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int ffexit_(void);
#define staler ((real *)&blank_1 + 302)

/* ------------------------------------------------------------------------ */

/*     WSTAWIA NA STOS ELEMENT TYPU ELEM. USTAWIA VALTOP,VLPREV. */

/*     PRZY PRZEPELNIENIU STOSU PRZERYWA KOMPILACJE !!! */

/*     ( NA SKUTEK BRAKU NIELOKALNYCH SKOKOW NIE JEST MOZLIWY  ) */
/*     ( SKOK DO ETYKIETY 2000 W SPASS2 I KOMPILACJA KOLEJNYCH ) */
/*     ( MODULOW.					      ) */


/*     ##### DETECTED ERROR(S) : 550.   /PRZEPELNIENIE STOSU  / */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */

    stos_1.vlprev = stos_1.valtop;
    stos_1.valtop += stos_1.stckap[*elem - 1];
    if (stos_1.valtop >= stos_1.fstout) {
	goto L100;
    }
    stack[stos_1.valtop - 1] = *elem;
    return 0;
/* .....PRZEPELNIENIE STOSU */
L100:
    merr_(&c__550, &c__0);
/*     GO TO 2000   CHANGED TO COMMENT DUE TO A.I.L./P.G.     15.05.84 */
    ffexit_();
/*     FOR STACK BEING OVERLOADED  STOP THE COMPILATION */
/*     ' FATAL ERROR  ' */
    return 0;
} /* spush_ */

#undef staler
#undef stack


/* Subroutine */ int spop_(void)
{
    /* Local variables */
    static integer n;
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* -------------------------------------------------------------------------- */

/*     ZDEJMUJE 1 ELEMENT Z CZUBKA STOSU. USTAWIA VALTOP, VLPREV. */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */




    n = stos_1.fstout - stos_1.valtop - 1;
    if (n < summary_1.free) {
	summary_1.free = n;
    }

    stos_1.valtop = stos_1.vlprev;
    if (stos_1.valtop < stos_1.lstsaf) {
	stos_1.lstsaf = stos_1.valtop;
    }
    stos_1.vlprev = stack[stos_1.valtop - 1];
    stos_1.vlprev = stos_1.stckap[stos_1.vlprev - 1];
/*     =APETYT NOWEGO CZUBKA STOSU */
    stos_1.vlprev = stos_1.valtop - stos_1.vlprev;
    return 0;
} /* spop_ */

#undef staler
#undef stack


integer sconst_(integer *n)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    sstovf_(void);

/* ----------------------------------------------------------------------------- */

/*     POMOCNICZA. */
/*     ZWRACA NOWY ATS ATRYBUTU ZAWIERAJACEGO STALA O WARTOSCI N. */

/*     ##### OUTPUT CODE : 199 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */

/* ..... */
    stos_1.lstemp += -3;
    ret_val = stos_1.lstemp;
    quadr3_(&c__199, &ret_val, n);
    if (stos_1.frstts >= stos_1.lstemp) {
	sstovf_();
    }
    return ret_val;
} /* sconst_ */

integer creal_(real *x)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i__;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int serro2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* ---------------------------------------------------------------- */

/*     ZWRACA ADRES STALEJ X TYPU REAL W TABLICY STALYCH */

/*     ##### DETECTED ERROR(S) : 554 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



/* vax  data realsize/1/ */
/* vax  the size of real numbers on vax is 4 bytes ( = the size of integer) */
    i__ = blank_1.lpmem + 1;
L100:
    if (staler[i__ - 1] == *x) {
	goto L200;
    }
    ++i__;
/* ail      if (i .lt. irecn) goto 100 */
    if (i__ <= blank_1.irecn) {
	goto L100;
    }
/* ail  constant not found, i=irenc+1, append if enough room */
    if (blank_1.irecn + 1 > blank_1.ipmem[blank_1.lmem - 1]) {
	goto L300;
    }
    ++blank_1.irecn;
    staler[i__ - 1] = *x;
L200:
    ret_val = i__;
/* dsw&bc C		      = SIZE OF REAL VALUE (NUMBER OF WORDS) */
/* dsw&bc C     LPMEM=INDEKS OSTATNIEGO SLOWA PRZEZ STALYMI REAL */
/* dsw&bc C     IRECN=INDEKS OSTATNIEGO SLOWA ZAJETEGO PRZEZ STALE REAL */
/* dsw&bc       N=(IRECN / REALSIZE)+1 */
/* dsw&bc C	 = INDEKS PIERWSZEGO WOLNEGO MIEJSCA W STALER */
/* dsw&bc       CREAL=(LPMEM+REALSIZE-1)/REALSIZE+1 */
/* dsw&bc C	 = INDEKS PIERWSZEJ STALEJ W STALER */
/* dsw&bc C     USTAW WARTOWNIKA */
/* dsw&bc       STALER(N)=X */
/* dsw&bc   100 IF(STALER(CREAL).EQ.X)GO TO 200 */
/* dsw&bc       CREAL=CREAL+1 */
/* dsw&bc       GO TO 100 */
/* dsw&bc C     JEST? */
/* dsw&bc   200 IF(CREAL.LT.N)RETURN */
/* dsw&bc       IF(IRECN+REALSIZE .GT. IPMEM(LMEM))GO TO 300 */
/* dsw&bc       IRECN=IRECN+REALSIZE */
    return ret_val;
L300:
    serro2_(&c__554, &c__0);
    return ret_val;
} /* creal_ */

#undef staler
#undef stack


integer screal_(integer *n)
{
    /* Initialized data */

    static integer realsize = 1;

    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer k;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int sstovf_(void);

/* ---------------------------------------------------------------------------- */
/*     POMOCNICZA. */
/*     ZWRACA NOWY ATS ATRYBUTU ZAWIERAJACEGO STALA REAL O NUMERZE N */

/*     ##### OUTPUT CODE : 197 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



/* 		      = SIZE OF REAL VALUE (NUMBER OF WORDS) */
/*     LPMEM=INDEKS OSTATNIEGO SLOWA PRZEZ STALYMI REAL */
/* ..... */
    stos_1.lstemp -= 3;
    ret_val = stos_1.lstemp;
    k = (blank_1.lpmem + realsize - 1) / realsize + 1;
/*     K=INDEKS PIERWSZEJ STALEJ W STALER */
    k = realsize * (*n - k);
/* 	= OFFSET WZGLEDEM ETYKIETY "RECON" RUN-TIME-U. */
    quadr3_(&c__197, &ret_val, &k);
    if (stos_1.frstts >= stos_1.lstemp) {
	sstovf_();
    }
    return ret_val;
} /* screal_ */

#undef staler
#undef stack


integer swhat_(integer *ind)
{
    /* Initialized data */

    static struct {
	integer e_1[36];
	} equiv_2 = { 0, 0, 8, 9, 0, 9, 7, 9, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3,
		 1, 3, 14, 13, 13, 0, 0, 0, 0, 0, 10, 12, 12, 11, 11, 10, 13 }
		;


    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer k, l, n;
#define tt ((integer *)&equiv_2 + 1)
#define tt0 ((integer *)&equiv_2)
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* ---------------------------------------------------------------------------- */


/*     IND WSKAZUJE ZEROWE SLOWO OPISU ATRYBUTU /IND=MIDENT(NAZWA)/. */
/*     FUNKCJA ROZPOZNAJE RODZAJ ATRYBUTU I ZWRACA JAKO WYNIK : */
/* 		    0 - "UNIWERSALNY" */
/* 		    1 - "STALA" */
/* 		    3 - "ZMIENNA" */
/* 		    5 - "TABLICA STATYCZNA" */
/* 		    7 - "TYP FORMALNY" / "NAZWA TYPU"/ */
/* 		    8 - "REKORD" */
/* 		    9 - "KLASA" */
/* 		   11 - "PROCEDURA" */
/* 		   12 - "FUNKCJA" */
/* 		   13 - "SYGNAL" */
/* 		   14 - "OPERATOR" */

/*     W PRZYPADKU NIEPOPRAWNEGO OPISU ZWRACA UNIWERSALNY. */
/* ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



/* CCCCCCCCCCCCCCCCCCCCCCCC */
/*      = RODZAJ ATRYBUTU : */
/* 	  ELEMENTY 0..15 ODPOWIADAJA WARTOSCIOM 0..15 POLA "T" */
/* 	     "    16..27      "        "        5..16 POLA "ZP" */
/* 	     "    28..35      "        "        0..7  POLA "S" */

/* ............ */
    n = blank_1.ipmem[(1208 + (0 + (*ind - 1 << 2)) - 1208) / 4];
/* ... ODCZYTAJ POLE "T" , BITY 12..15 */
    k = n & 15;
    if (k != 1) {
	goto L200;
    }
/* ... NIE TYP. POLE "ZP" , BITY 8..11 */
    l = lbit_shift(n, (ftnlen)-4) & 15;
    if (l > 4) {
	goto L150;
    }
/* ... PROCEDURA,FUNKCJA, POLE "S" , BITY 5..7 */
    l = (lbit_shift(n, (ftnlen)-8) & 7) + 17;
L150:
    k = l + 11;
L200:
    ret_val = tt[k - 1];
    return ret_val;
} /* swhat_ */

#undef staler
#undef stack
#undef tt0
#undef tt


/* Subroutine */ int scallb_(void)
{
    /* Initialized data */

    static integer schx1 = 8192;
    static integer schx2 = 16384;

    /* Local variables */
    static integer n, bt, adr, ind, elem, prot;
#define stack ((integer *)&blank_1 + 302)
    static integer opkod;
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *), scalle_(void)
	    , mcallo_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer sprfld_(logical *), tstemp_(integer *);

/* ----------------------------------------- */

/*     WERSJA 1983.04.26 */

/*     POCZATEK WYWOLANIA. CZUBEK STOSU ZAWIERA REKORD,KLASE,FUNKCJE, */
/*     PROCEDURE,BLOK PREF,SYGNAL. */
/*     JESLI NA STOSIE JEST MODUL BEZ PELNEGO ADR.VIRTUALNEGO */
/*      /TYLKO ADR.POSREDNI , GDY LASTPR <> 0 / , TO ZASTEPUJE TEN ADRES */
/* 	 PRZEZ PELNY ADR.VIRTUALNY. */
/*     OTWIERA POLE DANYCH /PO WYZNACZENIU DYNAMICZNEGO PROTOTYPU WRAZ Z */
/*     OTOCZENIEM/ - O ILE NIE JEST TO PROCEDURA,FUNKCJA STANDARDOWA */
/*     PRZY BRAKU PARAMETROW FORMALNYCH / WB<>"(" / PRZECHODZI DO ZAKONCZENIA */
/*      WYWOLANIA /WOLA SCALLE/. UWAGA: DLA FUNKCJI BEZPARAMETROWEJ WOLA */
/* 	SCALLE NAWET DLA WB="(". */

/*     USTAWIA BITY 0-2 SLOWA -3 : */
/* 		 000 =	ZWYKLY,LOKALNY MODUL BEZ PREFIKSU, */
/* 		 001 =	NIELOKALNY LUB PREFIKSOWANY,ALE ZNANE OFFSETY, */
/* 		 010 =	NIEZNANE OFFSETY PARAMETROW /VIRTUAL LUB PARAMETR/ */
/* 	    INFORMACJA TA JEST UZYWANA PRZEZ SPARAM,SCALLE . */

/*     WOLANA PRZEZ SDPDA: DLA NAZWY LUB NAZWY PO KROPCE KLASY,REKORDU, */
/* 	   FUNKCJI,PROCEDURY,SYGNALU ORAZ DLA BLOKU PREF. */
/*     WOLANA PRZEZ SVALUE: GDY NAZWA LUB NAZWA PO KROPCE KLASY,REKORDU,FUNKCJI */
/*     WYSTAPILA PRZED "," LUB ")" . */

/*     DLA FUNKCJI (NIE-STANDARDOWEJ) GASI FLREADY. */

/*     ##### OUTPUT CODE : 1 , 3 , 4 , 5 , 43 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */


/* dsw  DATA SCALBHX1,SCALBHX2 /Z2000, Z4000 / */
/*      RODZAJ ELEMENTU,ADRES PROTOTYPU W IPMEM */
/* ................ */
    elem = stack[(1208 + (0 + (stos_1.valtop - 1 << 2)) - 1208) / 4];
    ind = stack[stos_1.valtop - 5];
    prot = ind;

/* ..... ROZPOCZNIJ KONTROLE PARAMETROW */
    mcallo_(&ind, &stack[stos_1.valtop - 2], &stack[stos_1.valtop - 7], &
	    stos_1.kind);
/* bc moved check for virtual address before check for standard procedure */
/*     CZY JEST NA STOSIE WYWOLANIE WYMAGAJACE ZABEZPIECZENIA ADR. WIRTUALNEGO */
    if (stos_1.lastpr == 0) {
	goto L200;
    }
/*     TAK. WEZ PELNY ADRES VIRTUALNY */
    n = tstemp_(&c__4);
    quadr3_(&c__43, &n, &stack[stos_1.lastpr - 3]);
    stack[stos_1.lastpr - 3] = n;
L200:
/* .....FUNKCJA,PROCEDURA STANDARDOWA ? */
    if (ind < blank_1.lpmsys) {
	goto L1000;
    }
/*     NIE. */
    stos_1.flready = FALSE_;
/* bc */
    stos_1.lastpr = stos_1.valtop;
    stos_1.phadr = tstemp_(&c__1);
    n = elem - 7;
/*     =RODZAJ ELEMENTU, 1..7 ZAMIAST 8..14 */
    bt = schx1;
/*     = BITY 0-1 KOPIOWANE DO SLOWA -1 , = ZNANE OFFSETY,NIELOKALNY LUB PREF. */
    switch (n) {
	case 1:  goto L220;
	case 2:  goto L260;
	case 3:  goto L350;
	case 4:  goto L240;
	case 5:  goto L240;
	case 6:  goto L230;
    }
/*      - OPERATOR TU NIE WYSTAPI */

/* .....REKORD */
L220:
    adr = tstemp_(&c__4);
    opkod = 1;
    goto L400;
/* .....SYGNAL */
L230:
    opkod = 3;
    prot = blank_1.ipmem[prot];
/*      = NUMER SYGNALU */
    goto L380;
/* .....PROCEDURA,FUNKCJA. VIRTUAL LUB PARAMETR ? */
L240:
    if (stos_1.kind == 0) {
	goto L260;
    }
    bt = schx2;
/* 		CZYLI NIEZNANE OFFSETY */
    goto L270;
/* .....KLASA, CD. PROCEDURY,FUNKCJI */
/*     LOKALNY BEZ PREFIKSU ? */
L260:
    if (blank_1.local == 2 && blank_1.ipmem[prot + 20] == 0 && stack[
	    stos_1.valtop - 8] == 0) {
	bt = 0;
    }
L270:
    if (stos_1.kind != 2 && stack[stos_1.valtop - 8] == 0) {
	goto L350;
    }
    opkod = 5;
    goto L360;
/* .....BLOK PREFIKSOWANY */
L350:
    opkod = 4;
L360:
    prot = sprfld_(&c_false);
/*      = WYZNACZONY DYNAMICZNIE PROTOTYP /BYC MOZE WRAZ Z OTOCZENIEM/ */
L380:
    adr = tstemp_(&c__1);
/* .....WSPOLNE OTWARCIE POLA DANYCH : OPENRC,RAISE,OPEN,SLOPEN */
/* 				 /OPKOD = 1,3,4,5/ */
L400:
    quadr4_(&opkod, &adr, &stos_1.phadr, &prot);
    stack[stos_1.valtop - 3] = adr;
    stack[stos_1.valtop - 4] = bt;
/*     OTWARCIE POLA DANYCH   DOSTARCZA AH I ADR.FIZYCZNEGO */
/* .....CZY SA PARAMETRY AKTUALNE ? */
L500:
    if (stos_1.wb == 36) {
	goto L550;
    }
/*     BRAK PAR.AKTUALNYCH, KONCZ WYWOLANIE */
L510:
    scalle_();
    return 0;
/*     DLA FUNKCJI BEZPARAMETROWEJ TEZ KONCZ WYWOLANIE */
L550:
    if (elem == 12 && blank_1.ipmem[ind + 3] == 1) {
	goto L510;
    }
    return 0;
/* .....PROCEDURA,FUNKCJA STANDARDOWA */
L1000:
    stack[stos_1.valtop - 3] = 0;
    stack[stos_1.valtop - 4] = 0;
/*     WYZEROWANE LICZNIKI PAR. INPUT I OUTPUT */
    goto L500;
} /* scallb_ */

#undef staler
#undef stack


/* Subroutine */ int scalle_(void)
{
    /* Initialized data */

    static integer scalehex = 8191;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static logical standard;
    static integer m, n, ind, ats, elem;
    extern /* Subroutine */ int spop_(void);
    static integer prot;
#define stack ((integer *)&blank_1 + 302)
    static integer opkod;
    extern integer svats_(integer *);
    extern /* Subroutine */ int snext_(void), quadr1_(integer *), quadr2_(
	    integer *, integer *), quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *), mcallc_(void)
	    , sphadr_(integer *), safest_(void);
#define staler ((real *)&blank_1 + 302)
    static integer contrl;
    extern integer tstemp_(integer *), stypft_(integer *), sfprst_(integer *),
	     sparft_(integer *, integer *);
    extern /* Subroutine */ int sstore_(integer *, integer *), serror_(
	    integer *);
    extern integer stypst_(integer *);
    extern /* Subroutine */ int sreslt1_(integer *), special_(void);
    extern integer sgetpar_(integer *, integer *);

/* ------------------------------------------------------------------------- */

/*     WERSJA 1984.04.10 */

/*     OBSLUGUJE ZAKONCZENIE WYWOLANIA REKORDU,KLASY,BLOKU PREF., */
/* 	 PROCEDURY,FUNKCJI,SYGNALU. */

/*     WOLANA : PRZY BRAKU PARAMETROW AKTUALNYCH PRZEZ SCALLB LUB */
/* 	   PO WYSTAPIENIU ")" PRZEZ SDPDA. */

/*     WOLA MCALLC. */
/*     ZABEZPIECZA STOS. */
/*     PRZEKAZUJE STEROWANIE. */
/*     ODCZYTUJE PARAMETRY OUTPUT I WARTOSC FUNKCJI. */
/*     SPRAWDZA DLA PROCEDURY ISTNIENIE "CALL" I ZJADA. /JESLI BRAK "CALL" */
/*      - ZASTEPUJE PRZEZ UNIWERSALNY/ */
/*     DLA SYGNALU SPRAWDZA ISTNIENIE "RAISE" I ZJADA /JESLI BRAK "RAISE" */
/*      - ZASTEPUJE  PRZEZ UNIWERSALNY. */
/*     REKORD,KLASE ZASTEPUJE PRZEZ WARTOSC / LUB ZDEJMUJE ZE STOSU */
/* 	JESLI WB = ZNACZNIK KONCA INSTRUKCJI LUB ETYKIETA /. */
/*     FUNKCJE ZASTEPUJE PRZEZ WARTOSC. */
/*     DLA BLOKU PREF.,PROCEDURY,SYGNALU OBNIZA STOS. */
/*     DLA FUNKCJI,PROCEDURY,SYGNALU,BLOKU PREF. USUWA POLE DANYCH. */


/*     DLA PROCEDURY,FUNKCJI STANDARDOWEJ GENERUJE : */
/* 	PRZEKAZANIE WARTOSCI PARAMETROW INPUT /OPKOD 145/ , */
/* 	PRZEKAZANIE STEROWANIA /OPKOD 132/ , */
/* 	ODCZYT PAR. OUTPUT I WARTOSCI FUNKCJI /OPKOD 23/ */
/* 	PRZEKAZANIE ODCZYTANYCH WARTOSCI PARAMETROW NA PAR.AKTUALNE */
/*      ORAZ ZDEJMUJE ZE STOSU PARAMETRY INPUT LEZACE POD FUNKCJA,PROCEDURA. */
/*      DODATKOWO, FUNKCJE ZASTEPUJE PRZEZ WARTOSC. */



/*     ##### OUTPUT CODE : 2 , 21 , 54 , 58 , 59 , 132 , 143 , 145 , */
/* 			     150 , 153 , 159 , 160 , 170 . */

/*     ##### DETECTED ERROR(S) : 450 , 453 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */




/*  **  **  **  **  **  **  **  **  **  **  **  **  **  **  **  **  **  **  ** */
/*   MASKI I WZORCE: */
/*    MTP - MASKA DO WYCINANIA INFORMACJI DOTYCZACYCH TYPOW ZE SLOWA ZEROWEGO */
/*    MOTHERS -	    --	   --	   --	   --	  --  INNYCH PROTOTYPOW */
/*    MPAR -    --    --    --	 --    --    --       ZMIENNYCH I PARAMETROW */
/*    MSPR - MASKA DLA SYSPREF  ( DLA PROTOTYPOW SYNTAKTYCZNYCH ) */
/*    MASKTP - ZAPRZECZENIE MASKI  MTP */
/*    NOTTP - WZORZEC DLA NIE-TYPU  ( 1 ) */
/*    MPROCES - WZORZEC DLA PROCESU  ( 5 ) */
/*    MCOR - WZORZEC DLA COROUTINY (7) */
/*    MERPF - MASKA DO WYKRYWANIA BLEDNYCH LIST PARAMETROW */
/*    MBLOCK - WZORZEC DLA BLOKU  ( 0 PRZY PRZECIECIU Z	MOTHERS ) */
/*    MNOTVIR - WZORZEC DO KASOWANIA BITU "VIRTUAL" */
/*    MHAND - WZORZEC DLA HANDLERA */

/* CCCCCCCCCCCCCCCCCCCCCCCCC */
/* 	ELEM - WSKAZUJE 0-SLOWO OPISU PARAMETRU NA STOSIE */
/* 	CONTRL - INFORMACJA O KONTROLI /MPARIO(..)+1/ */
/* 	IND - ADRES W IPMEM OPISU PAR.FORMALNEGO */
/* 	ATS - ATS WARTOSCI PAR.FORMALNEGO LUB WARTOSCI FUNKCJI */
/* 	STANDARD - .TRUE. DLA PROCEDURY,FUNKCJI STANDARDOWEJ */

/* ...... */
    mcallc_();
    stos_1.kind = 0;
/* .....FUNKCJA,PROCEDURA STANDARDOWA ? */
    standard = stack[stos_1.valtop - 5] < blank_1.lpmsys;
    if (standard) {
	goto L2000;
    }
/*     NIE. */
/*     JESLI REKORD - PRZESKOCZ */
    if (stack[stos_1.valtop - 1] == 8) {
	goto L50;
    }
/* .....ZABEZPIECZ STOS */
    safest_();
/* .....PRZEKAZ STEROWANIE */
    sphadr_(&stos_1.valtop);
    opkod = 160;
    if (stack[stos_1.valtop - 4] > 8191) {
	opkod = 159;
    }
/*     GOLOCAL LUB GO */
/*     PRZEKAZ STEROWANIE Z ADRESEM FIZYCZNYM I AH NOWEGO OBIEKTU */
    quadr3_(&opkod, &stos_1.phadr, &stack[stos_1.valtop - 3]);


/*     PO POWROCIE Z GENEROWANEGO OBIEKTU: */


    stos_1.phadr = tstemp_(&c__1);
    ats = tstemp_(&c__4);
    stack[stos_1.valtop - 3] = ats;
/*     NOWE ATS-Y NA ADR.FIZ. I VIRTUALNY */
    quadr3_(&c__2, &ats, &stos_1.phadr);


/*     CZY PROC. VIRTUALNA LUB FORMALNA? TAK,JESLI BIT 1 =1 W SLOWIE -3 */
    if (stack[stos_1.valtop - 4] >= 16384) {
	stos_1.kind = 1;
    }
/*      -OBOJETNE: FORMALNA CZY VIRTUALNA /CZY ZNANE OFFSETY/ */



/* .....JESLI SA PARAMETRY OUTPUT-ODCZYTAJ WARTOSCI */
L50:
    m = stack[stos_1.valtop - 4] & scalehex;
/*     M=LICZBA PARAMETROW OUTPUT */
    if (m == 0) {
	goto L500;
    }
/*     DLA PROCEDURY STANDARDOWEJ NAJPIERW ODCZYTAJ WARTOSCI WSZYSTKICH */
/* 	PARAMETROW */
    if (! standard) {
	goto L100;
    }
    elem = stos_1.fstout - 2;
    i__1 = m;
    for (n = 1; n <= i__1; ++n) {
/* 	ODCZYTAJ WARTOSC N-TEGO PAR.OUTPUT PROC.STANDARDOWEJ */
/* 	 I WPISZ ATS TEJ WARTOSCI DO SLOWA -8 */
	elem += 11;
	ind = stack[elem - 2];
	blank_1.nrpar = stack[elem];
/* L90: */
	stack[elem - 9] = sgetpar_(&ind, &stos_1.valtop);
    }

L100:

    i__1 = m;
    for (n = 1; n <= i__1; ++n) {
/* 	OBSLUZ N-TY PARAMETR OUTPUT /OD PRAWEJ DO LEWEJ/ */
	stos_1.fstout += 11;
	elem = stos_1.fstout - 2;
	contrl = (lbit_shift(stack[elem - 1], (ftnlen)-4) & 7) + 1;
	stack[elem - 1] &= 15;
/* 	ODCZYTANE I WYZEROWANE BITY 9-11 */
	ind = stack[elem - 2];
	blank_1.nrpar = stack[elem];
	if (standard) {
	    goto L102;
	}
/* 	ODCZYTAJ WARTOSC PARAMETRU OUTPUT */
	ats = sgetpar_(&ind, &stos_1.valtop);
	goto L103;
L102:
	ats = stack[elem - 9];

/* 	KONWERSJA LUB DYNAMICZNA KONTROLA */
L103:
	if (contrl > 3 && option_1.opttyp) {
	    goto L300;
	}

	blank_1.idr = stack[elem - 6];
	if (blank_1.idr == 0) {
	    goto L105;
	}
	blank_1.idr = stypft_(&elem);
/* 	IDR = TYP FORMALNY PAR.AKT. LUB ZERO */

L105:
	switch (contrl) {
	    case 1:  goto L300;
	    case 2:  goto L110;
	    case 3:  goto L120;
	    case 4:  goto L130;
	    case 5:  goto L140;
	    case 6:  goto L150;
	    case 7:  goto L160;
	}

/* 	KONWERSJA DO INTEGER */
L110:
	opkod = tstemp_(&c__1);
	quadr3_(&c__58, &opkod, &ats);
	ats = opkod;
	goto L300;

/* 	KONWERSJA DO REAL */
L120:
	opkod = tstemp_(&c__1);
	quadr3_(&c__59, &opkod, &ats);
	ats = opkod;
	goto L300;

/* 	KONTROLA DYN.,OBA TYPY STATYCZNE */
L130:
	quadr3_(&c__150, &ats, &stack[elem - 5]);
	goto L300;

/* .....ZNANY OFFSET? */
L140:
	if (stos_1.kind != 0) {
	    goto L165;
	}
	opkod = tstemp_(&c__2);
	quadr4_(&c__21, &opkod, &blank_1.ipmem[ind - 5], &blank_1.ipmem[ind - 
		4]);
	goto L200;
/* 	WSTAW TYP STATYCZNY PAR.AKTUALNEGO */
L150:
	blank_1.idr = stypst_(&elem);
/* 	ZNANY OFFSET? */
L160:
	if (stos_1.kind == 0) {
	    goto L170;
	}
/* 	NIEZNANY. ODCZYTAJ TYP PAR.FORMALNEGO */
L165:
	opkod = sfprst_(&blank_1.nrpar);
	goto L200;
/* 	ZNANY OFFSET */
/* dsw  170   OPKOD=SPARF2(IND) */
/* dsw  ---------------------------- */
L170:
	opkod = sparft_(&ind, &c__2);
/* dsw  ----------------------------- */

/* 	OPKOD=ATS ODCZYTANEGO TYPU FORMALNEGO PAR.FORMALNEGO. */
L200:
	quadr4_(&c__170, &blank_1.idr, &ats, &opkod);
/* 	ZAKONCZONA KONTROLA LUB KONWERSJA. */
/* 	PODSTAW WARTOSC PAR.OUTPUT NA PAR.AKTUALNY */
L300:
	sstore_(&elem, &ats);
/* 	ZAKONCZONA OBSLUGA KOLEJNEGO PARAMETRU OUTPUT */

/* L400: */
    }


L500:
    elem = stack[stos_1.valtop - 1] - 7;
/*      = RODZAJ ELEMENTU : 1..6 ZAMIAST 8..13 /OPERATOR TU NIE WYSTAPI/ */
    switch (elem) {
	case 1:  goto L600;
	case 2:  goto L600;
	case 3:  goto L800;
	case 4:  goto L700;
	case 5:  goto L900;
	case 6:  goto L650;
    }
/* .....KLASA,REKORD. ZASTAP PRZEZ WARTOSC */
L600:
    stack[stos_1.valtop - 1] = 2;
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 6] = 0;
/* bc kill template after return from process (opcode 222 LKILLTEMP) */
    prot = blank_1.ipmem[stack[stos_1.valtop - 5] - 1];
    if ((prot & masks_1.mtp) == masks_1.mproces) {
	quadr1_(&c__222);
    }
/* bc */
/*     JESLI NA WEJSCIU JEST POCZATEK INSTRUKCJI LUB ETYKIETA - ZDEJMIJ */
/*      ZE STOSU */
    if (stos_1.wb == 32 || stos_1.wb == 35 || stos_1.wb == 44) {
	spop_();
    }
    goto L1000;
/* .....SYGNAL. CZY JEST "RAISE" ? */
L650:
    if (stos_1.wb == 71) {
	goto L670;
    }
/*     BRAK RAISE - NIELEGALNE WYSTAPIENIE SYGNALU.ZASTAP PRZEZ UNIWERSALNY */
    serror_(&c__453);
    goto L720;
/*     ETYKIETA I USUNIECIE POLA DANYCH HANDLERA */
L670:
    snext_();
    blank_1.idl = 153;
    goto L810;
/* .....PROCEDURA. CZY JEST CALL? */
L700:
    if (stos_1.wb == 7) {
	goto L750;
    }
/*     BRAK CALL - NIELEGALNE WYSTAPIENIE PROCEDURY. ZASTAP PRZEZ UNIWERSALNY */
    serror_(&c__450);
L720:
    stack[stos_1.valtop - 1] = 0;
    goto L1000;

L750:
    snext_();
/*     PROCEDURA STANDARDOWA ? */
    if (stack[stos_1.valtop - 5] < blank_1.lpmsys) {
	goto L3000;
    }
/*     NIE. */
/* .....BLOK PREFIKSOWANY. OBNIZ STOS,USUN POLE DANYCH */
L800:
    blank_1.idl = 143;
L810:
    quadr2_(&blank_1.idl, &stack[stos_1.valtop - 3]);
    spop_();
    goto L1000;
/* .....FUNKCJA. ZASTAP PRZEZ WARTOSC */
/*     WEZ DLA RESULT: NUMER JAKO PARAMETRU, ADRES OPISU JAKO ATRYBUTU */
L900:
    n = stack[stos_1.valtop - 5];
/*     N=ADRES OPISU FUNKCJI W IPMEM */
/*     PARAMETRY SA NUMEROWANE OD ZERA, RESULT WYSTEPUJE JAKO OSTATNI. */
    blank_1.nrpar = blank_1.ipmem[n + 3] - 1;
    ind = blank_1.ipmem[n - 6];
    stos_1.result = sgetpar_(&ind, &stos_1.valtop);
/*      =  ATS ODCZYTANEJ WARTOSCI FUNKCJI */
/*     FUNKCJA STANDARDOWA ? */
    if (n < blank_1.lpmsys) {
	goto L4000;
    }
/*     NIE. */
/*     WSTAW TYP WARTOSCI */
    stack[stos_1.valtop - 4] = blank_1.ipmem[n - 5];
    stack[stos_1.valtop - 5] = blank_1.ipmem[n - 4];
/*     CZY TYPU FORMALNEGO? */
    stack[stos_1.valtop - 6] = 0;
    if ((blank_1.ipmem[n - 1] & 4096) == 0) {
	goto L950;
    }
/*     A WIEC FUNKCJA TYPU FORMALNEGO. ZWYKLA ? */
    if (stos_1.kind == 1) {
	goto L930;
    }
/*     TAK. IDAC PO SL-ACH OD POLA DANYCH ODCZYTAJ TEN TYP */
    n = tstemp_(&c__2);
    quadr4_(&c__54, &n, &stack[stos_1.valtop - 3], &stack[stos_1.valtop - 5]);
    goto L940;
/*     FUNKCJA FORMALNA LUB WIRTUALNA TYPU FORMALNEGO. ODCZYTAJ TEN TYP> */
L930:
    n = sfprst_(&blank_1.nrpar);
L940:
    stack[stos_1.valtop - 6] = n;

/*     ZASTAP PRZEZ WARTOSC */
L950:
    stack[stos_1.valtop - 1] = 2;
/*     USUN POLE DANYCH */
    quadr2_(&c__143, &stack[stos_1.valtop - 3]);
    stack[stos_1.valtop - 3] = stos_1.result;

/* ...............WSPOLNE ZAKONCZENIE.............. */
L1000:
    stos_1.phadr = 0;
    stos_1.lastpr = 0;
    return 0;

/* .....FUNKCJA,PROCEDURA STANDARDOWA. */
/* 	  WPISZ WARTOSCI PARAMETROW INPUT. */
L2000:
    opkod = stack[stos_1.valtop - 5];
    opkod = blank_1.ipmem[opkod + 1];
/*     = NUMER FUNKCJI STANDARDOWEJ */
/*     WYMAGA SPECJALNEGO TRAKTOWANIA ? */
    if (opkod > 0) {
	goto L2100;
    }
/*     TAK */
    special_();
    return 0;
/* ... NORMALNIE OBSLUGIWANA */
L2100:
    m = stos_1.valtop - (stack[stos_1.valtop - 3] << 3);
/*     = ADRES PIERWSZEGO PAR.INPUT */
/*     CZY SA / JESZCZE / PARAMETRY INPUT ? */
L2200:
    if (m >= stos_1.valtop) {
	goto L2400;
    }
/*     WPISZ WARTOSC PARAMETRU */
    i__1 = svats_(&m);
    quadr4_(&c__145, &i__1, &opkod, &stack[m - 2]);
    m += 8;
    goto L2200;

/* ... PRZEKAZ STEROWANIE */
L2400:
    quadr2_(&c__132, &opkod);
    goto L50;

/* .....ZAKONCZENIE DLA PROCEDURY STANDARDOWEJ. */
/* 	ZDEJMIJ ZE STOSU WRAZ Z PARAMETRAMI INPUT */
L3000:
    opkod = stack[stos_1.valtop - 3] + 1;
    if (opkod < 1) {
	goto L3150;
    }
    i__1 = opkod;
    for (m = 1; m <= i__1; ++m) {
	spop_();
/* L3100: */
    }
/* bc 3150 RETURN */
L3150:
    goto L1000;
/* bc */

/* .....ZAKONCZENIE DLA FUNKCJI STANDARDOWEJ. */
/*     ZASTAP FUNKCJE WRAZ Z PARAMETRAMI INPUT PRZEZ WARTOSC */
L4000:
    opkod = stack[stos_1.valtop - 3];
    if (opkod < 1) {
	goto L4150;
    }
    i__1 = opkod;
    for (m = 1; m <= i__1; ++m) {
	spop_();
/* L4100: */
    }
L4150:
    sreslt1_(&blank_1.ipmem[n - 4]);
    stack[stos_1.valtop - 4] = blank_1.ipmem[n - 5];
/* bc   RETURN */
    goto L1000;
/* bc */
} /* scalle_ */

#undef staler
#undef stack


/* Subroutine */ int special_(void)
{
    /* Initialized data */

    static integer args[7] = { 1,2,2,2,1,1,2 };
    static integer op[8] = { 42,100,101,116,60,60,131,53 };

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer n, nr, ind;
    extern /* Subroutine */ int spop_(void);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int sargmt_(void);
    extern integer tstemp_(integer *), sconst_(integer *);
    extern /* Subroutine */ int sresult_(integer *);

/* ---------------------------------------------------------------------------- */

/*     OBSLUGUJE WYWOLANIE FUNKCJI STANDARDOWYCH WYMAGAJACYCH */
/* 	SPECJALNEJ OBSLUGI : */

/*     NUMERY : */
/* 	-1   INOT */
/* 	-2   IOR */
/* 	-3   IAND */
/* 	-4   ISHFT */
/* 	-5   ORD */
/* 	-6   CHR */
/* 	-7   XOR */

/*     NA CZUBKU STOSU ZNAJDUJE SIE FUNKCJA,POD NIA ARGUMENTY. */
/*     PROCEDURA GENERUJE KOD I ZASTEPUJE NA STOSIE FUNKCJE WRAZ */
/*      Z PARAMETRAMI PRZEZ JEJ WARTOSC. */

/*     ##### OUTPUT CODE : 42 , 53 , 60 , 100 , 101 , 116 , 131 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



/*      = LICZBA ARGUMENTOW */
/*      = OPKOD DO WYPISANIA */



    ind = stack[(1208 + (0 + (stos_1.valtop - 4 - 1 << 2)) - 1208) / 4];
/*     = ADRES OPISU FUNKCJI */
    n = stack[stos_1.valtop - 3];
/*     = LICZBA PAR. INPUT NA STOSIE , <= ARGS( .. ) */
    nr = -blank_1.ipmem[ind + 1];
/*     = NUMER FUNKCJI, 1..7 */
    if (args[nr - 1] == 2) {
	goto L2000;
    }

/* .....JEDNOARGUMENTOWE. JEST ARGUMENT ? */
    if (n == 0) {
	goto L1500;
    }
    spop_();
/*     STALA? */
    if (stack[stos_1.valtop - 1] == 1) {
	goto L1700;
    }
/*     NIE */
    stos_1.result = tstemp_(&c__1);
    quadr3_(&op[nr - 1], &stos_1.result, &stack[stos_1.valtop - 3]);
/* ... ZASTAP CZUBEK PRZEZ WARTOSC TEJ FUNKCJI */
L1500:
    stack[stos_1.valtop - 1] = 2;
L1510:
    stack[stos_1.valtop - 3] = stos_1.result;
L1520:
    stack[stos_1.valtop - 2] = 0;
    stack[stos_1.valtop - 4] = blank_1.ipmem[ind - 5];
    stack[stos_1.valtop - 5] = blank_1.ipmem[ind - 4];
    stack[stos_1.valtop - 6] = 0;
    stack[stos_1.valtop - 7] = 0;
    return 0;
/* ... STALY ARGUMENT */
L1700:
    if (nr != 1) {
	goto L1520;
    }
    stos_1.result = ~ stack[stos_1.valtop - 3];
    goto L1510;


/* .....DWUARGUMENTOWE. CZY SA OBA ARGUMENTY ? */
L2000:
    blank_1.treslt = blank_1.ipmem[ind - 4];
    if (n == 2) {
	goto L2200;
    }
/*     NIE, 1 LUB 0 */
    if (n == 1) {
	spop_();
    }
    goto L1500;
/*     O.K. */
L2200:
    spop_();
    sargmt_();
    blank_1.idl = stack[stos_1.vlprev - 3];
    blank_1.idr = stack[stos_1.valtop - 3];
/*     = ATS-Y PIERWSZEGO I DRUGIEGO ARGUMENTU */
    switch (stos_1.arg) {
	case 1:  goto L2300;
	case 2:  goto L2400;
	case 3:  goto L2500;
	case 4:  goto L2450;
    }
/* ... OBA STALE */
L2300:
    switch (nr) {
	case 1:  goto L2320;
	case 2:  goto L2320;
	case 3:  goto L2330;
	case 4:  goto L2340;
	case 5:  goto L2301;
	case 6:  goto L2301;
	case 7:  goto L2370;
    }
L2301:
/*     IOR */
L2320:
    stos_1.result = blank_1.idl | blank_1.idr;
    goto L2350;
/*     IAND */
L2330:
    stos_1.result = blank_1.idl & blank_1.idr;
    goto L2350;
/*     ISHFT */
L2340:
    stos_1.result = lbit_shift(blank_1.idl, blank_1.idr);

L2350:
    sresult_(&c__1);
    return 0;
/*     XOR */
L2370:
    stos_1.result = blank_1.idl ^ blank_1.idr;
    goto L2350;

/* ... LEWY STALY,PRAWY NIE */
L2400:
    blank_1.idl = sconst_(&blank_1.idl);
L2450:
    stos_1.result = tstemp_(&c__1);
    quadr4_(&op[nr - 1], &stos_1.result, &blank_1.idl, &blank_1.idr);
L2460:
    sresult_(&c__2);
    return 0;

/* ... PRAWY STALY,LEWY NIE */
L2500:
    if (nr == 4) {
	goto L2600;
    }
/*     IOR,IAND,XOR */
    blank_1.idr = sconst_(&blank_1.idr);
    goto L2450;
/* ... ISHFT( .. , CONST ) */
L2600:
    nr = 8;
/* bc   IDR=IAND(IDR,31) */
    if (blank_1.idr != 0) {
	goto L2450;
    }
    stos_1.result = blank_1.idl;
    goto L2460;
} /* special_ */

#undef staler
#undef stack


integer stypst_(integer *elem)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer k, n;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr4_(integer *, integer *, integer *, 
	    integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* ----------------------------------------------------------------- */
/*     POMOCNICZA. */
/*     ZWRACA /NOWY/ ATS TYPU STATYCZNEGO ELEMENTU Z MIEJSCA ELEM  STOSU */
/*     I WSTAWIA TEN TYP */

/*     ##### OUTPUT CODE : 21 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */


/* ..... */
    ret_val = tstemp_(&c__2);
    n = stack[*elem - 4];
    k = stack[*elem - 5];
    quadr4_(&c__21, &ret_val, &n, &k);
    return ret_val;
} /* stypst_ */

#undef staler
#undef stack


/* Subroutine */ int sphadr_(integer *elem)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* ---------------------------------------------------------------------- */

/*     POMOCNICZA. */
/*     GWARANTUJE,ZE PHADR ZAWIERA ADR.FIZYCZNY GENEROWANEGO OBIEKTU. */
/*     JESLI PHADR=0,TO ODTWARZA ADR.FIZ. Z ADR.VIRT. ZE SLOWA -2 ELEMENTU */
/*      ELEM STOSU. */

/*     ##### OUTPUT CODE : 47 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */

/* ..... */
    if (stos_1.phadr != 0) {
	return 0;
    }
/*     ZATEM TRZEBA ODTWORZYC ADRES FIZYCZNY */
    stos_1.phadr = tstemp_(&c__1);
    quadr3_(&c__47, &stos_1.phadr, &stack[*elem - 3]);
/*     ODCZYTAJ ADR.FIZYCZNY Z VIRTUALNEGO BEZ MEMBER */
    return 0;
} /* sphadr_ */

#undef staler
#undef stack



integer sparft_(integer *ind, integer *numdsw)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer l, elem;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr4_(integer *, integer *, integer *, 
	    integer *);
#define staler ((real *)&blank_1 + 302)
    extern logical mloctp_(integer *, integer *);
    extern integer tstemp_(integer *);
    extern /* Subroutine */ int smodify_(integer *, integer *);

/* ----------------------------------------------------------------------------- */
/* dsw  dodatkowy parametr numdsw = 1 - wejscie sparft, = 2 - wejscie sparf2 */

/*     ENTRY SPARF2 */

/*     POMOCNICZA. */
/*     DLA WOLANEGO MODULU /ZNANE OFFSETY/ ZWRACA  ATS ZMODYFIKOWANEGO */
/*     TYPU FORMALNEGO PARAMETRU. */

/*     WEJSCIE SPARF2 : WOLANY MODUL JEST NA CZUBKU STOSU /Z SCALLE/ */
/*     WEJSCIE SPARFT : WOLANY MODUL JEST PONIZEJ CZUBKA /Z SPARAM/ */

/*     IND - ADRES OPISU PAR. FORMALNEGO W IPMEM */

/*     ##### OUTPUT CODE : 54 , 85 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */


/* ..... */
    elem = stos_1.vlprev;
/* dsw  GO TO 1 */
/* dsw  ------------------------ */
    if (*numdsw == 1) {
	goto L1;
    }
/* dsw  ------------------------ */

/* ----------------------- */
/* dsw  ENTRY SPARF2(IND) */
    elem = stos_1.valtop;
L1:
    ret_val = tstemp_(&c__2);
/*     CZY TEN TYP FORMALNY JEST ATRYBUTEM LOKALNYM? */
    l = blank_1.ipmem[*ind - 4];
    if (mloctp_(&l, &stack[elem - 5])) {
	goto L100;
    }
/*     NIE.ODCZYTAJ IDAC PO SL-ACH */
    quadr4_(&c__54, &ret_val, &stack[elem - 3], &l);
    goto L200;
/*     ATRYBUT LOKALNY */
L100:
    quadr4_(&c__85, &ret_val, &stos_1.phadr, ind);
/* .....ZMODYFIKUJ TYP */
L200:
    smodify_(&ret_val, &blank_1.ipmem[*ind - 5]);
/* dsw  SPARF2=SPARFT */
    return ret_val;
} /* sparft_ */

#undef staler
#undef stack


integer sgetpar_(integer *ind, integer *elem)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer k, apet;
#define stack ((integer *)&blank_1 + 302)
    extern integer sapet_(integer *, integer *);
    static integer dswap;
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* ------------------------------------------------------------------------- */

/*     POMOCNICZA. */
/*     ODCZYTUJE WARTOSC FUNKCJI LUB PARAMETRU OUTPUT /IND=ADRES OPISU */
/*      W IPMEM/ I ZWRACA /NOWY/ ATS TEJ WARTOSCI. */
/*     UZYWANA ROWNIEZ DLA ODCZYTU PAR.OUTPUT LUB WARTOSCI FUNKCJI */
/*      DLA PROCEDUR,FUNKCJI STANDARDOWYCH. */
/*     ELEM-MIEJSCE STOSU Z WOLANYM MODULEM */
/*     UZYWA NRPAR,PHADR. */

/*     ##### OUTPUT CODE : 23 , 52 , 61 , 62 , 63 , 84 , 85 , 86 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */


/* ..... */
    apet = sapet_(&blank_1.ipmem[*ind - 5], &blank_1.ipmem[*ind - 4]);
/* vax  changed because of real appetite = 1 */
    dswap = apet;
    if (dswap == 2) {
	dswap = 1;
    }
    ret_val = tstemp_(&dswap);
    apet = stos_1.apetyt[apet - 1];
/*     STANDARDOWA? */
    if (stack[*elem - 5] < blank_1.lpmsys) {
	goto L300;
    }
/* .....NIE */
/*     CZY ZNANY OFFSET? TAK,JESLI W SLOWIE -3 BIT 1 =0. */
    if (stack[*elem - 4] >= 16384) {
	goto L200;
    }
/*     ZNANY OFFSET. ODCZYTAJ APET-SLOW */
    i__1 = apet + 83;
    quadr4_(&i__1, &ret_val, &stos_1.phadr, ind);
    return ret_val;
/*     NIEZNANY OFFSET. WEZ ADRES FIZYCZNY PARAMETRU. */
L200:
    k = tstemp_(&c__1);
    quadr4_(&c__52, &k, &stos_1.phadr, &blank_1.nrpar);
/*     ODCZYTAJ APET-SLOW */
    i__1 = apet + 60;
    quadr3_(&i__1, &ret_val, &k);
    return ret_val;
/* .....PROCEDURA,FUNKCJA STANDARDOWA */
L300:
    apet = stack[*elem - 5];
    quadr4_(&c__23, &ret_val, &blank_1.ipmem[apet + 1], &blank_1.nrpar);
    return ret_val;
} /* sgetpar_ */

#undef staler
#undef stack


integer stypft_(integer *elem)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer n;
#define stack ((integer *)&blank_1 + 302)
    static integer opkod;
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern logical mloctp_(integer *, integer *);
    extern integer tstemp_(integer *), tsinse_(integer *, integer *), 
	    smember_(integer *);
    extern /* Subroutine */ int smodify_(integer *, integer *);

/* ----------------------------------------------------------------------------- */

/*     POMOCNICZA. */
/*     WYLICZA TYP FORMALNY ELEMENTU Z MIEJSCA ELEM STOSU /WARTOSC,ZMIENNA, */
/*      ELEM.TABLICY,TABL.STATYCZNA,FUNKCJA/ I ZWRACA ATS TEGO TYPU. */
/*     JESLI WB <> "(" MODYFIKUJE TEN TYP /ZWRACA ZMODYFIKOWANY/ */

/*     ##### OUTPUT CODE : 15 , 22 , 54 , 85 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */


/* ..... */
    n = stack[*elem - 1] - 1;
    switch (n) {
	case 1:  goto L200;
	case 2:  goto L300;
	case 3:  goto L200;
	case 4:  goto L300;
	case 5:  goto L199;
	case 6:  goto L199;
	case 7:  goto L199;
	case 8:  goto L199;
	case 9:  goto L199;
	case 10:  goto L199;
	case 11:  goto L300;
    }
L199:

/* .....WARTOSC LUB ELEMENT TABLICY. TYP JUZ JEST WYLICZONY */
L200:
    ret_val = stack[*elem - 6];
    goto L335;

/* .....ZMIENNA LUB TABLICA STATYCZNA. CZY PRZEZ KROPKE? */
L300:
    if (stack[*elem - 8] == 0) {
	goto L340;
    }
/*     PRZEZ KROPKE. CZY TYP FORMALNY JEST ATRYBUTEM TEGO POLA? */
    if (stack[*elem - 6] <= 0) {
	goto L310;
    }
/*     ZATEM TO ATRYBUT LOKALNY.WEZ JEGO ADR.FIZYCZNY */
    n = smember_(elem);
    opkod = 85;
/*     ="ODCZYTAJ 2 SLOWA" */
    goto L330;
/*     ODSZUKAJ TYP IDAC PO SL-ACH */
L310:
    n = stack[*elem - 8];
L320:
    opkod = 54;
/*     ="ODCZYTAJ TYP FORMALNY IDAC PO SL-ACH" */
L330:
    ret_val = tstemp_(&c__2);
    quadr4_(&opkod, &ret_val, &n, &stack[*elem - 5]);

/* .....JESLI WB <> "(" ZMODYFIKUJ TYP */
L335:
    if (stos_1.wb != 36) {
	smodify_(&ret_val, &stack[*elem - 4]);
    }
    return ret_val;

/*     PRZEZ DISPLAY. CZY TYP MOZNA ODCZYTAC PRZEZ DISPLAY? */
L340:
    if (stack[*elem - 6] > 0) {
	goto L350;
    }
/*     ZATEM TRZEBA ISC PO SL-ACH OD MIEJSCA DEKLARACJI ZMIENNEJ */
/*     SLOWO -5 = - SL TEJ ZMIENNEJ */
    n = tstemp_(&c__4);
    i__1 = -stack[*elem - 6];
    quadr3_(&c__15, &n, &i__1);
/*     N = ADR.VIRTUALNY POBRANY Z DISPLAYA */
    goto L320;
/*     TYP FORMALNY MOZNA ODCZYTAC POPRZEZ DISPLAY Z WARSTWY= STACK(ELEM-5) */
L350:
    ret_val = stack[*elem - 5];
    opkod = 22;
    n = stack[*elem - 6];
/*     CZY TYP JEST ATRYBUTEM LOKALNYM? */
    if (! mloctp_(&ret_val, &blank_1.p)) {
	goto L330;
    }
/*     TAK */
    ret_val = tsinse_(&ret_val, &c__2);
    goto L335;
} /* stypft_ */

#undef staler
#undef stack


/* Subroutine */ int smodify_(integer *n, integer *l)
{
    static integer k;
    extern /* Subroutine */ int quadr4_(integer *, integer *, integer *, 
	    integer *);
    extern integer tstemp_(integer *);

/* --------------------------------------------------------------- */

/*     POMOCNICZA. */
/*     N=ATS TYPU FORMALNEGO , L=LICZBA ARRAY OF */
/*     MODYFIKUJE TEN TYP O WLASCIWA LICZBE ARRAY-OF I ATS WYNIKOWEGO */
/*     TYPU PODSTAWIA NA N. */

/*     ##### OUTPUT CODE : 87 . */

    if (*l == 0) {
	return 0;
    }
/*     A WIEC TRZEBA MODYFIKOWAC */
    k = tstemp_(&c__2);
    quadr4_(&c__87, &k, n, l);
    *n = k;
    return 0;
} /* smodify_ */

/* Subroutine */ int sstore_(integer *elem, integer *ats)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer n, apet, adres;
#define stack ((integer *)&blank_1 + 302)
    extern integer sapet2_(integer *);
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer sarray_(integer *);
    extern /* Subroutine */ int scancel_(integer *);
    extern integer smember_(integer *);

/* ----------------------------------------------------------------------------- */

/*     GENERUJE PRZESLANIE WARTOSCI O ADRESIE ATS W TABLICY SYMBOLI NA */
/*     ELEMENT /ZMIENNA,ELEM.TABLICY,TABL.STATYCZNA/ Z MIEJSCA ELEM STOSU. */
/*     NIE DOKONUJE ZADNEJ KONTROLI. */
/*     NIE ZMIENIA STOSU. */
/*     LICZBA PRZESYLANYCH SLOW ZALEZY OD TYPU WARTOSCI ELEMENTU STOSU */

/*     ##### OUTPUT CODE : 60 , 161 , 162 , 163 , 164 , 165 , 166 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */


/* ..... */
    n = stack[*elem - 1] - 2;
    adres = stack[*elem - 3];
/*     WYLICZ APETYT */
    apet = sapet2_(elem);
    apet = stos_1.apetyt[apet - 1];
    switch (n) {
	case 1:  goto L300;
	case 2:  goto L400;
	case 3:  goto L500;
    }

/*     ZMIENNA. CZY PRZEZ KROPKE? */
L300:
    if (stack[*elem - 8] == 0) {
	goto L350;
    }
/*     TAK. */
    i__1 = apet + 163;
    i__2 = smember_(elem);
    quadr4_(&i__1, &i__2, ats, &adres);
    scancel_(&adres);
    return 0;
/*     ZMIENNA PRZEZ DISPLAY. */
L350:
    quadr3_(&c__60, &adres, ats);
/*      "MOVE" */
    return 0;

/* .....ELEM.TABLICY */
/*     WPISZ APET-SLOW POD ADRES FIZYCZNY ELEMENTU TABLICY */
L400:
    i__1 = apet + 160;
    i__2 = sarray_(elem);
    quadr3_(&i__1, &i__2, ats);

/*     TABLICA STATYCZNA */
L500:
/*     B R A K */
    return 0;
} /* sstore_ */

#undef staler
#undef stack


integer sarray_(integer *elem)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer k, n;
#define stack ((integer *)&blank_1 + 302)
    extern integer sapet2_(integer *);
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *), sconst_(integer *);

/* ----------------------------------------------------------------------------- */

/*     POMOCNICZA. */
/*     ZWRACA ATS ADRESU FIZYCZNEGO ELEMENTU TABLICY Z MIEJSCA ELEM STOSU */
/*     USUWA EWENTUALNY MINUS W SLOWIE -2 */

/*     ##### OUTPUT CODE : 64 , 65 , 102 , 103 , 104 , 105 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */


/* ..... */
    ret_val = tstemp_(&c__1);
    n = sapet2_(elem);
    k = stos_1.apetyt[n - 1];
    n = stack[*elem - 8];
/*     CZY INDEKS JEST STALA? */
    if (stack[*elem - 3] < 0) {
	goto L100;
    }
/* .....NIE. */
    if (k == 1) {
	goto L50;
    }
/*     POMNOZ INDEKS PRZEZ 2 LUB 3 */
    n = tstemp_(&c__1);
    i__1 = k + 62;
    quadr3_(&i__1, &n, &stack[*elem - 8]);
L50:
    i__1 = option_1.optind + 102 + option_1.optmem;
    quadr4_(&i__1, &ret_val, &stack[*elem - 3], &n);
    return ret_val;
/* .....INDEKS JEST STALA */
L100:
    i__1 = k * n;
    n = sconst_(&i__1);
    stack[*elem - 3] = -stack[*elem - 3];
    goto L50;
} /* sarray_ */

#undef staler
#undef stack


integer sapet2_(integer *elem)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer k, n;
#define stack ((integer *)&blank_1 + 302)
    extern integer sapet_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* ----------------------------------------------------------------------------- */

/*     POMOCNICZA. ZWRACA APETYT /1,3,4/ DLA STALEJ,ZMIENNEJ,WARTOSCI */
/*     Z MIEJSCA ELEM STOSU. */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */


    n = stack[*elem - 4];
    k = stack[*elem - 5];
    ret_val = sapet_(&n, &k);
    return ret_val;
} /* sapet2_ */

#undef staler
#undef stack


integer sapet_(integer *k, integer *n)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* ----------------------------------------------------------------------------- */

/*     POMOCNICZA. ZWRACA APETYT/1,2,4/ DLA WARTOSCI TYPU (K,N) */
/* 			 1 - INTEGER,BOOLEAN,STRING,CHAR */
/* 			 2 - REAL */
/* 			 4 - DOWOLNY TYP REFERENCYJNY */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



/*     TABLICOWY? */
    if (*k > 0) {
	goto L100;
    }
/*     = 1  ? */
    ret_val = 1;
    if (*n == blank_1.nrint) {
	return ret_val;
    }
    if (*n == blank_1.nrbool) {
	return ret_val;
    }
    if (*n == blank_1.nrchr) {
	return ret_val;
    }
    if (*n == blank_1.nrtext) {
	return ret_val;
    }
/*     REAL? */
    ret_val = 2;
    if (*n == blank_1.nrre) {
	return ret_val;
    }
/*     REFERENCYJNY */
L100:
    ret_val = 4;
    return ret_val;
} /* sapet_ */

#undef staler
#undef stack


integer smember_(integer *elem)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer n;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* --------------------------------------------------------------------------- */

/*     POMOCNICZA: ZWRACA /NOWY/ ATS ADRESU FIZYCZNEGO Z ADR.VIRT. ELEMENTU */
/*      Z MIEJSCA ELEM STOSU. */

/*     ##### OUTPUT CODE : 46 , 47  . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



    ret_val = tstemp_(&c__1);
    n = stack[*elem - 8];
    i__1 = option_1.optmem + 46;
    quadr3_(&i__1, &ret_val, &n);
    return ret_val;
} /* smember_ */

#undef staler
#undef stack


integer sprfld_(logical *param)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer n, ind, ats;
#define stack ((integer *)&blank_1 + 302)
    static integer opkod;
    extern /* Subroutine */ int quadr2_(integer *, integer *), quadr3_(
	    integer *, integer *, integer *), quadr4_(integer *, integer *, 
	    integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *), tsinse_(integer *, integer *), 
	    smember_(integer *);

/* ---------------------------------------------------------------------------- */

/*     ZWRACA /NOWY/ATS NUMERU PROTOTYPU LUB OJCA SYNT. I NUMERU PROTOTYPU. */
/*     PARAM=.TRUE. -UZYWANE PRZY PRZEKAZYWANIU PARAMETRU AKTUALNEGO */
/* 		/NA CZUBKU NA PEWNO FUNKCJA,PROCEDURA/ */
/* 	     DOSTARCZA OJCA SYNTAKTYCZNEGO I PROTOTYPU/SKLEJONE W 1 ARG./ */
/* 	     WOLANA PRZEZ SPARAM. */
/*     PARAM=.FALSE. -UZYWANE PRZY GENEROWANIU OBIEKTU KLASY,PROCEDURY,FUNKCJI */
/* 	     LUB BLOKU PREF. DOSTARCZA NUMERU PROTOTYPU /DLA PARAMETRU LUB */
/* 	     DOSTEPU PRZEZ KROPKE-ROWNIEZ OJCA SYNT./. */
/* 	     CZUBEK STOSU ZAWIERA KLASE,BLOK PREF,PROCEDURE,FUNKCJE. */
/* 	     WOLANA PRZEZ SCALLB. */

/*     NIE UZYWANA DLA PROCEDUR,FUNKCJI STANDARDOWYCH. */

/*     ##### OUTPUT CODE : 15 , 16, 20 , 44 , 45 , 86 , 112 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */

/* CCCCCCCCCCCCCCC */


/* ................. */
    ret_val = tstemp_(&c__1);
    ind = stack[stos_1.valtop - 5];
/*     IND=ADRES PROTOTYPU */
/* .....CZY TO PARAMETR,VIRTUAL CZY "ZWYKLY" PROTOTYP? */
    n = stos_1.kind + 1;
    switch (n) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
    }
/* .....ZWYKLY PROTOTYP.WSTAW JEGO NUMER. */
L100:
    quadr3_(&c__16, &ret_val, &stack[stos_1.valtop - 5]);
/*     DLA BLOKU PREF. TO JUZ WSZYSTKO */
    if (stack[stos_1.valtop - 1] == 10) {
	return ret_val;
    }
/*     CZY PRZEZ KROPKE? */
    if (stack[stos_1.valtop - 8] == 0) {
	goto L150;
    }
/*     TAK. */
L125:
    ats = stack[stos_1.valtop - 8];
/* .....SKLEJ ADRES VIRTUALNY /ATS/ I NUMER PROTOTYPU /SPRFLD/ W 1 ARGUMENT. */
L130:
    opkod = 112;
/*     OPKOD="SKLEJ W 1 ARG." */
    n = ret_val;
L135:
    ret_val = tstemp_(&c__3);
    quadr4_(&opkod, &ret_val, &ats, &n);
    return ret_val;
/* .....ZWYKLY PROTOTYP NIE PRZEZ KROPKE.JESLI NIE PARAMETR-KONIEC. */
L150:
    if (! (*param)) {
	return ret_val;
    }
/*     ZATEM PARAMETR.WEZ ADRES Z DISPLAYA. */
    ats = tstemp_(&c__4);
    quadr3_(&c__15, &ats, &blank_1.ipmem[ind - 2]);
    goto L130;
/* .....PROCEDURA,FUNKCJA VIRTUALNA. */
L200:
    if (stack[stos_1.valtop - 8] == 0) {
	goto L250;
    }
/*     WYZNACZ PRZEZ KROPKE PROTOTYP VIRTUALA */
/* bc split opcode 44,45 into 228 (LASKPROT) and 44,45 (LVIRTDOT) */
/* bc in order to call virtual from process properly */
/* bc   CALL QUADR4(44+OPTMEM,SPRFLD,STACK(VALTOP-7),IPMEM(IND+27)) */
    quadr2_(&c__228, &stack[stos_1.valtop - 8]);
    i__1 = option_1.optmem + 44;
    quadr3_(&i__1, &ret_val, &blank_1.ipmem[ind + 26]);
/* bc */
    goto L125;
/*     WYZNACZ PRZEZ DISPLAY PROTOTYP VIRTUALA */
L250:
    quadr4_(&c__20, &ret_val, &blank_1.ipmem[ind - 2], &blank_1.ipmem[ind + 
	    26]);
    goto L150;
/* .....PARAMETR. ODCZYTAJ */
L300:
    if (stack[stos_1.valtop - 8] == 0) {
	goto L350;
    }
/*     A WIEC PRZEZ KROPKE.WEZ ADRES FIZYCZNY POLA. */
    ats = smember_(&stos_1.valtop);
    n = ind;
    opkod = 86;
/*     OPKOD="WCZYTAJ 3 SLOWA Z POLA O ADR.FIZYCZNYM..." */
/*     ATS=ADR.FIZYCZNY,SPRFLD=ATS PARAMETRU */
    goto L135;
/*     PARAMETR PRZEZ DISPLAY */
L350:
    ret_val = tsinse_(&ind, &blank_1.local);
    return ret_val;
} /* sprfld_ */

#undef staler
#undef stack


integer sfprst_(integer *n)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    extern /* Subroutine */ int quadr4_(integer *, integer *, integer *, 
	    integer *);
    extern integer tstemp_(integer *);

/* ---------------------------------------------------- */

/*     POMOCNICZA. N=NUMER PARAMETRU. ODCZYTUJE TYP */
/*     /NIEZNANY W CZASIE KOMPILACJI/ N-TEGO PARAMETRU */
/*     PROCEDURY,FUNKCJI VIRTUALNEJ LUB FORMALNEJ,ZWRACA JEGO ATS. */

/*     ##### OUTPUT CODE : 40 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */



    ret_val = tstemp_(&c__2);
    quadr4_(&c__40, &ret_val, &stos_1.phadr, n);
    return ret_val;
} /* sfprst_ */

integer sparst_(integer *n)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr4_(integer *, integer *, integer *, 
	    integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* ----------------------------------------------------------------------- */

/*     POMOCNICZA.WSTAWIA TYP STATYCZNY PARAMETRU FORMALNEGO. */
/*     N=ADRES OPISU PARAMETRU W IPMEM */

/*     ##### OUTPUT CODE : 21 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



    ret_val = tstemp_(&c__2);
    quadr4_(&c__21, &ret_val, &blank_1.ipmem[*n - 5], &blank_1.ipmem[*n - 4]);
    return ret_val;
} /* sparst_ */

#undef staler
#undef stack


/* Subroutine */ int safe_(integer *n)
{
    /* Local variables */
    static integer k;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* --------------------------------------------------------------------- */

/*     N = ADRES W TABLICY SYMBOLI LUB 0. */
/*     JESLI N <> 0 ,GENERUJE NOWY ATRYBUT ROBOCZY I ZASTEPUJE NIM */
/*      PARAMETR AKTUALNY,ZACHOWUJAC ZNAK. */
/*     GENERUJE OPKOD MOVE&SAFE - NOWY ATRYBUT Z WARTOSCIA I APETYTEM */
/*     STAREGO,WARTOSC W ZMIENNEJ ROBOCZEJ. */

/*     ##### OUTPUT CODE : 195 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



    if (*n == 0) {
	return 0;
    }
    stos_1.lstemp += -3;
    k = stos_1.lstemp;
/*     ABY ZACHOWAC EWENTUALNY MINUS */
    if (*n > 0) {
	goto L100;
    }
    k = -k;
    *n = -(*n);
L100:
    quadr3_(&c__195, &stos_1.lstemp, n);
    *n = k;
    return 0;
} /* safe_ */

#undef staler
#undef stack


integer tstemp_(integer *n)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int sstovf_(void);

/* ------------------------------------------------------------------------ */


/*     ##### OUTPUT CODE : 201 , 202 , 203 , 204 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



    stos_1.lstemp += -3;
    ret_val = stos_1.lstemp;
    i__1 = *n + 200;
    quadr2_(&i__1, &ret_val);
    if (stos_1.frstts >= stos_1.lstemp) {
	sstovf_();
    }
    return ret_val;
} /* tstemp_ */

#undef staler
#undef stack


integer tsinse_(integer *k, integer *n)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer j;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    serro2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int sstovf_(void);

/* ------------------------------------------------------------------------- */

/*     K = ADRES OPISU ATRYBUTU W IPMEM */
/*     N = WIDZIALNOSC : 0 - GLOBALNY,1 - PRZEZ DISPLAY,2 - LOKALNY ATRYBUT */

/*     WYZNACZA ADRES OPISU ATRYBUTU W TABLICY SYMBOLI. */
/*     UZYWA POMOCNICZEGO SLOWNIKA ZAWIERAJACEGO TYLKO ATRYBUTY UZYTE */
/*     W BIEZACYM MODULE. */

/*     ELEMENTY SLOWNIKA: */
/* 	      SLOWO  0 = P /BIEZACY PROTOTYP/	 ORAZ */
/* 	      SLOWO +1 = ADRES OPISU ATRYBUTU W IPMEM */
/* 			  <=> ATRYBUT JEST W SLOWNIKU. */
/* 					    - I WTEDY SLOWO +1 OPISU */
/* 			     ATRYBUTU ZAWIERA ADRES TEGO ELEMENTU SLOWNIKA */

/* 	      SLOWO +2 = ADRES W TABLICY SYMBOLI */

/* 	      JESLI SLOWO 0  <> P LUB SLOWO +1	<> ADRESU ATRYBUTU */
/* 		 TO ATRYBUTU JESZCZE NIE MA W SLOWNIKU */
/*     ELEMENTY SLOWNIKA DOPISYWANE SA NA LEWO OD LMEM */
/* 	IPMEM(LMEM) = INDEKS PIERWSZEGO OD PRAWEJ WOLNEGO */



/*     ##### OUTPUT CODE : 205 , 206 , 207 . */

/*     ##### DETECTED ERROR(S) : 553 , 554 . ( PRZEPELNIENIA ) */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */





    ret_val = blank_1.ipmem[*k];
/*     UZYTY JUZ W TYM MODULE? */
    if (blank_1.ipmem[ret_val - 1] != blank_1.p) {
	goto L100;
    }
    if (blank_1.ipmem[ret_val] != *k) {
	goto L100;
    }
/* .....TAK. */
    ret_val = blank_1.ipmem[ret_val + 1];
    return ret_val;
/* .....JESZCZE NIE. WYZNACZ NOWY ADRES W TABLICY SYMBOLI */
L100:
    j = blank_1.ipmem[blank_1.lmem - 1] - 3;
    if (blank_1.irecn > j) {
	goto L200;
    }
    blank_1.ipmem[blank_1.lmem - 1] = j;
    ret_val = j + 1;
    blank_1.ipmem[ret_val - 1] = blank_1.p;
    blank_1.ipmem[ret_val] = *k;
    blank_1.ipmem[ret_val + 1] = stos_1.frstts;
    blank_1.ipmem[*k] = ret_val;
    ret_val = stos_1.frstts;
    stos_1.frstts += 3;
    i__1 = *n + 205;
    quadr3_(&i__1, &ret_val, k);
    if (stos_1.frstts >= stos_1.lstemp) {
	sstovf_();
    }
    return ret_val;
/* .....PRZEPELNIENIE TABLICY SYMBOLI LUB SLOWNIKA STALYCH REAL */
L200:
    serro2_(&c__504, &c__0);
    return ret_val;
} /* tsinse_ */

#undef staler
#undef stack


/* Subroutine */ int scancel_(integer *adr)
{
    /* Local variables */
    static integer n;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* ----------------------------------------------------------------------------- */

/*     JESLI ATRYBUT WSKAZANY PRZEZ ADR BYL UZYTY /JEST W TABLICY */
/* 	SYMBOLI/  - PROCEDURA WYPISUJE OPKOD "CANCEL"  , INACZEJ */
/*      NIC NIE ROBI. */

/*     UZYWANA PRZY ZMIANIE WARTOSCI ATRYBUTU DOSTEPNEGO PRZEZ KROPKE, */
/*      DLA ZABEZPIECZENIA NASTEPNEGO PRZEBIEGU PRZED TRZYMANIEM */
/* 	INFORMACJI "WARTOSC ATRYBUTU W REJESTRZE" POMIMO /NIEJAWNEJ/ */
/* 	ZMIANY WARTOSCI TEGO ATRYBUTU PRZY UZYCIU DOSTEPU KROPKOWANEGO. */

/*     ##### OUTPUT CODE : 158 . */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */




/* .....JEST W TABLICY SYMBOLI? */
    n = blank_1.ipmem[*adr];
    if (blank_1.ipmem[n - 1] != blank_1.p) {
	return 0;
    }
    if (blank_1.ipmem[n] != *adr) {
	return 0;
    }
/*     TAK */
    quadr2_(&c__158, &blank_1.ipmem[n + 1]);
    return 0;
} /* scancel_ */

#undef staler
#undef stack


/* Subroutine */ int safest_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer k, l, n;
    extern /* Subroutine */ int safe_(integer *);
    static integer elem;
#define stack ((integer *)&blank_1 + 302)
    static integer dswap;
    extern integer sapet2_(integer *);
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *), sarray_(integer *), smember_(integer *)
	    ;
    extern /* Subroutine */ int savevar_(integer *);

/* ------------------------------------------------------------------------- */

/*     ZABEZPIECZA ELEMENTY STOSU PRZY GENERACJI NOWEGO MODULU: */
/*     DLA ELEMENTOW BEDACYCH LSE ZABEZPIECZA ADRES TJ. WARTOSC WYRAZENIA */
/*     PRZED KROPKA DLA ZMIENNEJ I TABLICY STATYCZNEJ, ADRES TABLICY DLA */
/*     ELEMENTU TABLICY I WARTOSC INDEKSU - JESLI NIE STALA - DLA TABLIC. */

/*     DLA ELEMENTOW POWYZEJ LSTLSE ZABEZPIECZA WARTOSC ZMIENNYCH. */

/*     ##### OUTPUT CODE : 61 , 62 , 63 , 84 , 85 , 86 . */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



/* ......ZACZNIJ OD POPRZEDNIEGO */
    k = stos_1.vlprev;
/*     CZY JEST COS NIEZABEZPIECZONEGO NAD OPISAMI PETLI FOR? */
L100:
    if (k > stos_1.lstfor && k > stos_1.lstsaf) {
	goto L120;
    }
/*     NIE */
    stos_1.lstsaf = stos_1.vlprev;
    return 0;
/*     TAK. */
L120:
    elem = stack[k - 1];
/*     ELEM=RODZAJ ELEMENTU */
    if (elem < 2 || elem > 5) {
	goto L1000;
    }
/*     LSE? */
    if (k <= stos_1.lstlse) {
	goto L200;
    }
/* .....A WIEC POWYZEJ LSE : WARTOSC,ZMIENNA,ELEM.TABLICY,TABLICA STATYCZNA. */
/*     ZASTAP PRZEZ WARTOSC. */
    if (elem == 2) {
	goto L150;
    }
    if (elem == 4) {
	goto L160;
    }
/*     B R A K	DLA TABLICY STATYCZNEJ */
/* ... ZMIENNA. PRZEZ KROPKE? */
    if (stack[k - 8] == 0) {
	goto L140;
    }
/*     TAK.ODCZYTAJ WARTOSC */
    n = sapet2_(&k);
/*     N=RODZAJ APETYTU ZMIENNEJ */
/* vax changed because of real appetite = 1 */
    dswap = n;
    if (dswap == 2) {
	dswap = 1;
    }
    l = tstemp_(&dswap);
    n = stos_1.apetyt[n - 1];
    i__1 = n + 83;
    i__2 = smember_(&k);
    quadr4_(&i__1, &l, &i__2, &stack[k - 3]);
L135:
    stack[k - 3] = l;
/*     WPISZ 'WARTOSC' */
L140:
    stack[k - 1] = 2;
L150:
    safe_(&stack[k - 3]);
    goto L1000;
/* ... ELEM.TABLICY.  ODCZYTAJ WARTOSC */
L160:
    n = sapet2_(&k);
/* vax changed because of real appetite = 1 */
    dswap = n;
    if (dswap == 2) {
	dswap = 1;
    }
    l = tstemp_(&dswap);
    n = stos_1.apetyt[n - 1];
    i__1 = n + 60;
    i__2 = sarray_(&k);
    quadr3_(&i__1, &l, &i__2);
    goto L135;
/* .....LSE : ZMIENNA,ELEM.TABLICY,TABLICA STATYCZNA. */
L200:
    savevar_(&k);

/* .....WEZ POPRZEDNI ELEMENT */
L1000:
    k -= stos_1.stckap[elem - 1];
    goto L100;
} /* safest_ */

#undef staler
#undef stack


/* Subroutine */ int sindxs_(void)
{
/*      MAKIETA */
    return 0;
} /* sindxs_ */

/* Subroutine */ int quadr4_(integer *n1, integer *n2, integer *n3, integer *
	n4)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int ffputi_(integer *, integer *, integer *), 
	    qdrout_(void), ffputcs_(integer *, char *, ftnlen), ffputnl_(
	    integer *);

/* ------------------------------------------------------------ */

/*     WYPISUJE GENEROWANY KOD POSREDNI */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */




/*     BUFOR ZAJMUJE SLOWA LMEM-259 .. LMEM-1 */
    blank_1.ipmem[stos_1.lstwrd] = *n1;
    blank_1.ipmem[stos_1.lstwrd + 1] = *n2;
    blank_1.ipmem[stos_1.lstwrd + 2] = *n3;
    blank_1.ipmem[stos_1.lstwrd + 3] = *n4;
    if (! test_1.testc) {
	goto L1000;
    }
    ffputcs_(&c__13, " *******************", (ftnlen)20);
    ffputi_(&c__13, n1, &c__8);
    ffputi_(&c__13, n2, &c__8);
    ffputi_(&c__13, n3, &c__8);
    ffputi_(&c__13, n4, &c__8);
    ffputnl_(&c__13);
L1000:
    stos_1.lstwrd += 4;
    if (stos_1.lstwrd >= blank_1.lmem - 4) {
	qdrout_();
    }
    return 0;
} /* quadr4_ */

#undef staler
#undef stack


/* Subroutine */ int quadr3_(integer *n1, integer *n2, integer *n3)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int ffputi_(integer *, integer *, integer *), 
	    qdrout_(void), ffputcs_(integer *, char *, ftnlen), ffputnl_(
	    integer *);

/* ------------------------------------------------------------ */

/*     WYPISUJE GENEROWANY KOD POSREDNI */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */




/*     BUFOR ZAJMUJE SLOWA LMEM-259 .. LMEM-1 */
    blank_1.ipmem[stos_1.lstwrd] = *n1;
    blank_1.ipmem[stos_1.lstwrd + 1] = *n2;
    blank_1.ipmem[stos_1.lstwrd + 2] = *n3;
    if (! test_1.testc) {
	goto L1000;
    }
    ffputcs_(&c__13, " *******************", (ftnlen)20);
    ffputi_(&c__13, n1, &c__8);
    ffputi_(&c__13, n2, &c__8);
    ffputi_(&c__13, n3, &c__8);
    ffputnl_(&c__13);
L1000:
    stos_1.lstwrd += 3;
    if (stos_1.lstwrd >= blank_1.lmem - 4) {
	qdrout_();
    }
    return 0;
} /* quadr3_ */

#undef staler
#undef stack


/* Subroutine */ int quadr2_(integer *n1, integer *n2)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int ffputi_(integer *, integer *, integer *), 
	    qdrout_(void), ffputcs_(integer *, char *, ftnlen), ffputnl_(
	    integer *);

/* ------------------------------------------------------------ */

/*     WYPISUJE GENEROWANY KOD POSREDNI */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */




/*     BUFOR ZAJMUJE SLOWA LMEM-259 .. LMEM-1 */
    blank_1.ipmem[stos_1.lstwrd] = *n1;
    blank_1.ipmem[stos_1.lstwrd + 1] = *n2;
    if (! test_1.testc) {
	goto L1000;
    }
    ffputcs_(&c__13, " *******************", (ftnlen)20);
    ffputi_(&c__13, n1, &c__8);
    ffputi_(&c__13, n2, &c__8);
    ffputnl_(&c__13);
L1000:
    stos_1.lstwrd += 2;
    if (stos_1.lstwrd >= blank_1.lmem - 4) {
	qdrout_();
    }
    return 0;
} /* quadr2_ */

#undef staler
#undef stack


/* Subroutine */ int quadr1_(integer *n1)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int ffputi_(integer *, integer *, integer *), 
	    qdrout_(void), ffputcs_(integer *, char *, ftnlen), ffputnl_(
	    integer *);

/* ------------------------------------------------------------ */

/*     WYPISUJE GENEROWANY KOD POSREDNI */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */




/*     BUFOR ZAJMUJE SLOWA LMEM-259 .. LMEM-1 */
    ++stos_1.lstwrd;
    blank_1.ipmem[stos_1.lstwrd - 1] = *n1;
    if (! test_1.testc) {
	goto L1000;
    }
    ffputcs_(&c__13, " *******************", (ftnlen)20);
    ffputi_(&c__13, n1, &c__8);
    ffputnl_(&c__13);
L1000:
    if (stos_1.lstwrd >= blank_1.lmem - 4) {
	qdrout_();
    }
    return 0;
} /* quadr1_ */

#undef staler
#undef stack


/* Subroutine */ int qdrout_(void)
{
    /* Local variables */
    static integer m, n;
    extern /* Subroutine */ int ffwrite_ints__(integer *, integer *, integer *
	    );
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* ----------------------------------------------------------------------------- */

/*     OPROZNIA BUFOR IPMEM Z GENEROWANYM KODEM POSREDNIM. */
/*     PRZEPISUJE OSTATNIE 3 LICZBY NA POCZATEK,USTAWIA LSTWRD. */
/*     JESLI ERRFLG=.TRUE. - NIE WYPISUJE NIC. */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



/*     BUFOR ZAJMUJE SLOWA LMEM-259 .. LMEM-1 */

/* ..... */
    if (stream_2.errflg) {
	goto L100;
    }
/*     WEZ NOWY NUMER REKORDU */
    ffwrite_ints__(&c__18, &blank_1.ipmem[blank_1.lmem - 260], &c__256);
/* bc */
/* dsw ********************************* */
/*     PRZEPISZ OSTATNIE 3 SLOWA NA POCZATEK */
    n = blank_1.lmem - 259;
    m = blank_1.lmem - 3;
    blank_1.ipmem[n - 1] = blank_1.ipmem[m - 1];
    blank_1.ipmem[n] = blank_1.ipmem[m];
    blank_1.ipmem[n + 1] = blank_1.ipmem[m + 1];
L100:
    stos_1.lstwrd += -256;
    return 0;
} /* qdrout_ */

#undef staler
#undef stack


/* Subroutine */ int serror_(integer *numer)
{
    /* Local variables */
    static integer elem;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    static integer nazwa;
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int ffputi_(integer *, integer *, integer *), 
	    ffputcs_(integer *, char *, ftnlen), ffputnl_(integer *);

/* ------------------------------------------------------------------------ */
/* dsw procedura podzielona na serror i serro2 */

/*     SYGNALIZUJE BLAD O PODANYM NUMERZE DLA NAZWY Z CZUBKA STOSU. */
/*     DLA 'UNIWERSALNEGO' NIE ROBI NIC. */


/*     ENTRY SERRO2 */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */





    elem = stos_1.valtop;
/* L100: */
    if (stack[elem - 1] == 0) {
	return 0;
    }
    nazwa = stack[elem - 2];
    if (! test_1.testc) {
	goto L1000;
    }
    ffputcs_(&c__13, " ERROR", (ftnlen)6);
    ffputi_(&c__13, numer, &c__6);
    ffputi_(&c__13, &nazwa, &c__8);
    ffputnl_(&c__13);
L1000:
    merr_(numer, &nazwa);
    return 0;
} /* serror_ */

#undef staler
#undef stack


/* Subroutine */ int serro2_(integer *numer, integer *elem)
{
    /* Local variables */
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    static integer nazwa;
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int ffputi_(integer *, integer *, integer *), 
	    ffputcs_(integer *, char *, ftnlen), ffputnl_(integer *);

/* ------------------------------------------------------------------------ */
/* dsw procedura podzielona na serror i serro2 */

/*     SYGNALIZUJE BLAD O PODANYM NUMERZE DLA NAZWY Z CZUBKA STOSU. */
/*     DLA 'UNIWERSALNEGO' NIE ROBI NIC. */


/*     ENTRY SERRO2 */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */





/* L100: */
    if (stack[*elem - 1] == 0) {
	return 0;
    }
    nazwa = stack[*elem - 2];
    if (! test_1.testc) {
	goto L1000;
    }
    ffputcs_(&c__13, " ERROR", (ftnlen)6);
    ffputi_(&c__13, numer, &c__6);
    ffputi_(&c__13, &nazwa, &c__8);
    ffputnl_(&c__13);
L1000:
    merr_(numer, &nazwa);
    return 0;
} /* serro2_ */

#undef staler
#undef stack


/* Subroutine */ int sstovf_(void)
{
    /* Local variables */
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* --------------------------------------------------------------------------- */

/*     SYGNALIZUJE PRZEPELNIENIE TABLICY SYMBOLI - BLAD 553 */
/*      I CZYSCI JA */


/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */

/* dsw&bc */




/* ....PRZEPELNIENIE TABLICY SYMBOLI */
    merr_(&c__553, &c__0);
/*     OPROZNIJ TABLICE SYMBOLI */
/* dsw&bc      FRSTTS=LPMEM+1 */
/*            TEMPNR=LMEM-3 */
    stos_1.frstts = stacks_1.btsins;
    stos_1.tempnr = stacks_1.btstem - 3;

/* dsw  ----------  added  ----------- */
    stos_1.lstemp = stos_1.tempnr;
/* dsw  ------------------------------ */
    blank_1.ipmem[blank_1.lmem - 1] = stos_1.bottom - 1;
    return 0;
} /* sstovf_ */

#undef staler
#undef stack


/* Subroutine */ int stest_(void)
{
    /* Initialized data */

    static char hn[1] = "n";
    static char hns[1] = "n";
    static char hy[1] = "y";
    static char hys[1] = "y";
    static char hc[1] = "c";
    static char hs[1] = "s";
    static char hh[1] = "h";

    static integer n;
    static char chars[1*80];
    extern /* Subroutine */ int ffgets_(integer *, char *, integer *, ftnlen),
	     ffputcs_(integer *, char *, ftnlen), ffputnl_(integer *);

/* --------------------------------------------------------------------- */

/*     READ TESTING OPTIONS */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */



/* dsw  BYTE  CHARS(80) */
/* dsw  BYTE  HN,HNS,HY,HYS,HC,HS,HH */
/* dsw  --------------------------------- */
/* dsw  --------------------------------- */


    stos_1.test = FALSE_;
    test_1.testc = FALSE_;
    test_1.tests = FALSE_;
    test_1.testh = FALSE_;
    stos_1.atline = 0;
    return 0;
L100:
    ffputcs_(&c__0, " TESTING ?   Y/N:", (ftnlen)17);
    ffgets_(&c__0, chars, &c__80, (ftnlen)1);
    if (*(unsigned char *)&chars[0] == *(unsigned char *)&hn[0] || *(unsigned 
	    char *)&chars[0] == *(unsigned char *)&hns[0]) {
	return 0;
    }
    if (*(unsigned char *)&chars[0] != *(unsigned char *)&hy[0] && *(unsigned 
	    char *)&chars[0] != *(unsigned char *)&hys[0]) {
	goto L100;
    }
    stos_1.test = TRUE_;
    ffputcs_(&c__0, " OPTIONS : C - code , S - stack , H - halt", (ftnlen)42);
    ffputnl_(&c__0);
    ffgets_(&c__0, chars, &c__80, (ftnlen)1);
    for (n = 1; n <= 80; ++n) {
	if (*(unsigned char *)&chars[n - 1] == *(unsigned char *)&hc[0]) {
	    test_1.testc = TRUE_;
	}
	if (*(unsigned char *)&chars[n - 1] == *(unsigned char *)&hs[0]) {
	    test_1.tests = TRUE_;
	}
	if (*(unsigned char *)&chars[n - 1] == *(unsigned char *)&hh[0]) {
	    test_1.testh = TRUE_;
	}
/* L200: */
    }
/* dsw  IF(TESTH) CALL STOPAT */
    return 0;
} /* stest_ */

/* Subroutine */ int sabort_(void)
{
    return 0;
} /* sabort_ */

/* Subroutine */ int srcvoff_(void)
{
    return 0;
} /* srcvoff_ */

/* Subroutine */ int slcstout_(void)
{
    /* Local variables */
#define bl ((integer *)&blank_1)
    static integer len;
#define buf1 ((integer *)&combuf_1 + 2)
#define bufc ((char *)&combuf_1 + 8)
    static integer wlen;
    extern /* Subroutine */ int ffwrite_ints__(integer *, integer *, integer *
	    );
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int mdrop_(integer *), ffread_(integer *, integer 
	    *, integer *), ffseek_(integer *, integer *);
    static integer offset;
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int ffwrite_(integer *, integer *, integer *);

/* --------------------------------------------------------------------- */

/*     WYPISUJE NA PLIK 15 HEKSADECYMALNA REPREZENTACJE */
/*     TABLICY SYMBOLI I L-KODU. */

/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */
/* ............. /STOS/ ..... */
/*    Loglan82 Compiler&Interpreter */
/*     Copyright (C) 1981-1993 Institute of Informatics, University of Warsaw */
/*     Copyright (C)  1993, 1994 LITA, Pau */

/*     This program is free software; you can redistribute it and/or modify */
/*     it under the terms of the GNU General Public License as published by */
/*     the Free Software Foundation; either version 2 of the License, or */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful, */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*     GNU General Public License for more details. File: LICENSE.GNU */
/*  =============================================================== */



/*     IBUF3 - OPIS STRUMIENIA Z WCZYTYWANYM I PRODUKOWANYM KODEM POSREDNIM */


/* vax  equivalence (bigbuf(1), buf1(1)) */
/* dsw&ail */
/* bc */

/* .....SYMBOL TABLE */
/* dsw&ail */
/*  adres stalej none jest przekazany na zmiennej LOCAL ( numer 300 ) */
    blank_1.local = stacks_1.btstem - 3;
    ffwrite_ints__(&c__15, bl, &c__302);
/* PS   tu bylo porownanie z 50000, co dla LPMEM=48000 dalo maximun */
/* PS   2000 slow na stale rzeczywiste - nie rozumiem skad to ograniczenie */
/* PS   dlatego nie zmienilem go */
    if (blank_1.irecn > 50000) {
	mdrop_(&c__0);
    }
    ffwrite_ints__(&c__15, blank_1.ipmem, &blank_1.irecn);
/* .....L-CODE */
    offset = 0;
    ffseek_(&c__18, &offset);
L3000:
    len = 31744;
    ffread_(&c__18, buf1, &len);
    if (len == 0) {
	goto L3010;
    }
    wlen = len;
    ffwrite_(&c__15, buf1, &wlen);
    if (len == 31744) {
	goto L3000;
    }
L3010:
    return 0;
} /* slcstout_ */

#undef staler
#undef stack
#undef bufc
#undef buf1
#undef bl


