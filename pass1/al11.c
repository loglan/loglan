/* al11.f -- translated by f2c (version 20090411).
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

union {
    struct {
	logical errflg;
	integer line, ibuf2[265], ibuf3[7], junk[260];
    } _1;
    struct {
	logical errflg;
	integer line, ibuf23[272], junk[260];
    } _2;
    struct {
	integer errflg, line, ibuf2[265], ibuf3[7], junk[260];
    } _3;
} stream_;

#define stream_1 (stream_._1)
#define stream_2 (stream_._2)
#define stream_3 (stream_._3)

struct {
    integer free;
} summary_;

#define summary_1 summary_

struct {
    integer deep, over;
} case_;

#define case_1 case_

struct {
    integer breaklid;
} brid_;

#define brid_1 brid_

struct {
    logical deb;
    integer breakt[500], brnr, maxbr;
} debug_;

#define debug_1 debug_

struct {
    integer ierc;
    char msg[4];
} mjlmsg_;

#define mjlmsg_1 mjlmsg_

struct {
    integer btsins, btstem;
} stacks_;

#define stacks_1 stacks_

struct {
    logical testc, tests, testh;
} test_;

#define test_1 test_

struct {
    integer optmem;
    logical optopt;
    integer optind;
    logical opttyp, opttrc;
    integer optcsc, optcsf;
} option_;

#define option_1 option_

/* Table of constant values */

static integer c__211 = 211;
static integer c__210 = 210;
static integer c__200 = 200;
static integer c__18 = 18;
static integer c__256 = 256;
static integer c__13 = 13;
static integer c__6 = 6;
static integer c__5 = 5;
static integer c__4 = 4;
static integer c__184 = 184;
static integer c__179 = 179;
static integer c__178 = 178;
static integer c__181 = 181;
static integer c__1 = 1;
static integer c__194 = 194;
static integer c__174 = 174;
static integer c__193 = 193;
static integer c__185 = 185;
static integer c__429 = 429;
static integer c__186 = 186;
static integer c__422 = 422;
static integer c__41 = 41;
static integer c__187 = 187;
static logical c_false = FALSE_;
static integer c__31 = 31;
static integer c__176 = 176;
static integer c__411 = 411;
static integer c__423 = 423;
static integer c__2 = 2;
static integer c__85 = 85;
static integer c__407 = 407;
static integer c__0 = 0;
static integer c__177 = 177;
static integer c__182 = 182;
static integer c__10 = 10;
static integer c__7 = 7;
static integer c__149 = 149;
static integer c__444 = 444;
static integer c__479 = 479;
static integer c__240 = 240;
static integer c__221 = 221;
static integer c__15 = 15;
static logical c_true = TRUE_;
static integer c__132 = 132;
static integer c__145 = 145;
static integer c__418 = 418;
static integer c__23 = 23;
static integer c__427 = 427;
static integer c__449 = 449;
static integer c__73 = 73;
static integer c__419 = 419;
static integer c__420 = 420;
static integer c__416 = 416;
static integer c__39 = 39;
static integer c__40 = 40;
static integer c__74 = 74;
static integer c__75 = 75;
static integer c__83 = 83;
static integer c__82 = 82;
static integer c__223 = 223;
static integer c__224 = 224;
static integer c__225 = 225;
static integer c__188 = 188;
static integer c__477 = 477;
static integer c__405 = 405;
static integer c__189 = 189;
static integer c__402 = 402;
static integer c__401 = 401;
static integer c__406 = 406;
static integer c__403 = 403;
static integer c__404 = 404;
static integer c__190 = 190;
static integer c__175 = 175;
static integer c__183 = 183;
static integer c__227 = 227;
static integer c__478 = 478;
static integer c__208 = 208;
static integer c__139 = 139;
static integer c__60 = 60;
static integer c__152 = 152;
static integer c__141 = 141;
static integer c__415 = 415;
static integer c__443 = 443;
static integer c__441 = 441;
static integer c_n1 = -1;
static integer c__12 = 12;
static integer c__413 = 413;
static integer c_n45 = -45;
static integer c__445 = 445;
static integer c__446 = 446;
static integer c__417 = 417;
static integer c__42 = 42;
static integer c__37 = 37;
static integer c__460 = 460;
static integer c__140 = 140;
static integer c__475 = 475;
static integer c__476 = 476;
static integer c__433 = 433;
static integer c__3 = 3;
static integer c__435 = 435;
static integer c__29 = 29;
static integer c__30 = 30;
static integer c__431 = 431;
static integer c__412 = 412;
static integer c__150 = 150;
static integer c__170 = 170;

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
/* Subroutine */ int al1_(void)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int ffunlink_(integer *), slcstout_(void);
    static integer i__;
    extern /* Subroutine */ int ml2_(void), mess_(void), ffwrite_ints__(
	    integer *, integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int stest_(void), quadr1_(integer *), quadr2_(
	    integer *, integer *), spass2_(void);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int sabort_(void), ffclose_(integer *), srcvoff_(
	    void);

/* ----------------------------------------------------------------------- */

/*      1983.01.06 */

/*     * * * * * * * * * * * * * * * * * * * * */

/*     THE FOLLOWING FILE UNITS ARE USED : */

/*      1 - INTERACTIVE INPUT FROM THE TERMINAL ( FOR TESTING ONLY ) */
/*      2 - INTERACTIVE OUTPUT TO THE TERMINAL  ( FOR TESTING ONLY ) */
/*     13 - LISTING OUTPUT		       ( TEST MESSAGES	  ) */
/*     14 - WORKING FILE SCRATCH       - CODE FROM PARSER AND L-CODE */
/* 			  ( USED ONLY VIA SEEK,PUT,GET WITH IBUF3 ) */
/*     15 - L-CODE OUTPUT   ( TEXTUAL (HEXADECIMAL) REPRESENTATION */
/* 				       OF SYMBOL TABLE AND L-CODE ) */

/*     * * * * * * * * * * * * * * * * * * * * */

/* 	 STRUMIENIE : */
/* 		3 - BINARNY - KOD Z PARSERA */
/* 		LO - WYDRUKI KONTROLNE /ZNAKOWY/ */
/* 		3 - PRODUKOWANE CZWORKI /BINARNY/ - SEKWENCYJNIE, */
/* 			   OD REKORDU NUMER IOP(2)+1 . */
/* 			   /REKORD O NUMERZE IOP(2) BUFORUJE STOS "CASE"/ */

/*     * * * * * * * * * * * * * * * * * * * * */




/*     ##### OUTPUT CODE : 200 . */



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



/* deb --------------- added ------------ */
/*  breaklid - numer w displayu (dla interpretera) procedury breakl */
/* deb ----------------------------------- */
/* dsw  ---------------------------- */
/* dsw  ---------------------------- */
/* dsw&bc */


    mjlmsg_1.ierc = 0;
    s_copy(mjlmsg_1.msg, "al1 ", (ftnlen)4, (ftnlen)4);

    stest_();
/* 		WCZYTANA OPCJA WYDRUKOW KONTROLNYCH */
    sabort_();
/* 		WYLAPANIE ABORTU */


    stos_1.lstwrd = blank_1.lmem - 260;
/*     OSTATNIE ZAJETE SLOWO W BUFORZE WYJSCIOWYM / LMEM-259 .. LMEM-1 / */
    stos_1.bottom = blank_1.lmem - 916;
    stack[stos_1.bottom - 1] = -1;
/*     DNO STOSU / LMEM-916 .. LMEM-516 /  Z WARTOWNIKIEM = -1 */
    summary_1.free = blank_1.lmem - 516 - stos_1.bottom;
/*     ROZMIAR STOSU = 400 */
    case_1.deep = blank_1.lmem - 600;
/*     PUSTY STOS INSTRUKCJI "CASE" / LMEM-515 .. LMEM-260 / */
    stos_1.qrecnr = blank_1.iop[1];
/*     NAJWIEKSZY UZYTY NUMER REKORDU STRUMIENIA 3 */

/* dsw&bc */
    stacks_1.btsins = blank_1.lpml;
    stacks_1.btstem = blank_1.lpmf;
/* dsw  -----------------  added	---------------------------------- */
/*  inicjalizacje zmiennych z common przeniesione z podprogramow */
/*    przeniesione z sinit */
    stos_1.stckag = 0;
    stos_1.stcka0 = 8;
    for (i__ = 1; i__ <= 14; ++i__) {
	stos_1.stckap[i__ - 1] = 8;
/* L10: */
    }
    stos_1.stckap[4] = 10;
    stos_1.stckap[5] = 4;
    stos_1.apetyt[0] = 1;
    stos_1.apetyt[1] = 1;
    stos_1.apetyt[2] = 3;
    stos_1.apetyt[3] = 2;
/*   przeniesione z scase */
    case_1.over = 0;
/* dsw ----------------------------------------------------------------- */

    spass2_();

/* deb ----------------- added ------------------- */
/*  instrukcja L-kodu przekazujaca breaklid */
    if (! debug_1.deb) {
	goto L2001;
    }
    quadr1_(&c__211);
    if (brid_1.breaklid == 0) {
	goto L2001;
    }
    quadr2_(&c__210, &brid_1.breaklid);
L2001:
/* deb ------------------------------------------- */

/*     WYPISZ ZNACZNIK KONCA PRODUKOWANEGO KODU POSREDNIEGO */
    quadr1_(&c__200);
/*     JESLI TRZEBA - WYPISZ BUFOR Z CZWORKAMI */
    if (stream_1.errflg) {
	goto L2000;
    }
    if (stos_1.lstwrd == blank_1.lmem - 260) {
	goto L1000;
    }
/* dsw **************************** */
/* dsw      QRECNR=QRECNR+1 */
/* dsw      CALL SEEK(IBUF3,QRECNR) */
/* dsw      CALL PUT(IBUF3,IPMEM(LMEM-259)) */
/* bc   write(18) (ipmem(i),i=lmem-259,lmem-4) */
    ffwrite_ints__(&c__18, &blank_1.ipmem[blank_1.lmem - 260], &c__256);
/* bc */
/* dsw ***************************** */


/*     WRITE HEXADECIMAL REPRESENTATION OF SYMBOL TABLE AND L-CODE */
L1000:
    slcstout_();
L2000:
    ffclose_(&c__18);
/*     CLOSED TEMPORARY 18 should BE AUTOMATICALLY DELETED but ... */
    ffunlink_(&c__18);


/*     WYLACZ 'RECOVERY' */
    srcvoff_();


/* .....PRZYGOTUJ DANE STATYSTYCZNE */


    blank_1.ipmem[blank_1.isfin - 4] = stos_1.qrecnr - blank_1.iop[1];
/*      = LICZBA WYPRODUKOWANYCH REKORDOW Z KODEM POSREDNIM */
    blank_1.ipmem[blank_1.isfin - 5] = (400 - summary_1.free) / 4;
/*      = % UZYTEGO STOSU   /WZOR POPRAWNY DLA ROZMIARU = 400 / */


/* dsw  MSG=HAL1 */
    mess_();
/*     PRINT LISTING */
    ml2_();
/*     STOP */
/*     PO ABORCIE /BLAD W KOMPILATORZE/ */
/* 7777 ERRFLG=.TRUE.	CHANGED TO COMMENT 04.01.84 */
/* BC   GO TO 1000 */
    return 0;
} /* al1_ */

#undef staler
#undef stack


/* Subroutine */ int spass2_(void)
{
    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer n;
    extern /* Subroutine */ int get_(integer *, integer *), seek_(integer *, 
	    integer *);
    static logical init;
    extern /* Subroutine */ int sdpda_(logical *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int ffputi_(integer *, integer *, integer *), 
	    mproto_(void), mprotc_(void), ffputcs_(integer *, char *, ftnlen),
	     stclass_(void), ffputnl_(integer *);

/* ----------------------------------------------------------------------------- */

/*     PROCEDURA STERUJACA PRZEBIEGIEM 2. */
/*     DWUKROTNIE PRZECHODZI PRZEZ WSZYSTKIE MODULY. */
/* 	FAZA 1 : WYLICZANIE WARTOSCI STALYCH /INIT=TRUE/ */
/* 		 - WYBIERA TYLKO MODULY ZAWIERAJACE STALE WYLICZANE */
/* 	FAZA 2 : WLASCIWA GENERACJA KODU /INIT=FALSE/ */
/* 		 - PRZECHODZI PRZEZ WSZYSTKIE MODULY ZAWIERAJACE INSTRUKCJE */
/*     W OBU FAZACH PRZECHODZI KOLEJNO PRZEZ MODULY I DLA KAZDEGO MODULU */
/*     WSTAWIA JEGO ADRES DO P ,WCZYTUJE PIERWSZY REKORD Z KODEM POSREDNIM, */
/*      USTAWIA WB I INDEKS SYMBOLU DLA SNEXT,INICJALIZUJE STRUKTURY DANYCH, */
/*     WOLA SDPDA. */

/*     STARTUJE OD BLOKU WSKAZANEGO PRZEZ NBLUS. */
/*     DLA KAZDEGO MODULU REKORDY Z KODEM POSREDNIM Z PARSERA POWIAZANE */
/*     SA W LISTE : SLOWO +8 ZAWIERA NUMER PIERWSZEGO REKORDU /JESLI SLOWO */
/*     +9  =0 TO LISTA JEST PUSTA/ A SLOWO +9 INDEKS PIERWSZEGO SYMBOLU */
/*     W REKORDZIE. SLOWO 256 REKORDU ZAWIERA NUMER NASTEPNEGO REKORDU */
/*     LISTY. KOD DLA KAZDEGO MODULU JEST ZAKONCZONY PARA <FIN,NUMER ETYKIETY>. */

/*     SLOWO +2 W OPISIE MODULU ZAWIERA ADRES /W IPMEM/ NASTEPNEGO MODULU. */

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



/*      = TRUE DLA FAZY WYLICZANIA STALYCH */

/*     INTERNAL 2000		CHANGED TO COMMENT 04.01.84 */
/*     PUNKT POWROTU PO PRZEPELNIENIU STOSU W SPUSH */


/* ................. FAZA WYLICZANIA STALYCH */
/* 		   /PIERWSZE PRZEJSCIE PRZEZ KOD DLA MODULOW/ */

    init = TRUE_;

/* .....USTAW P NA BLOK GLOWNY */
L100:
    blank_1.p = blank_1.nblus;


/* .....INICJALIZACJA DLA PROTOTYPU P */
L1000:
    if (! test_1.testc) {
	goto L5000;
    }
    ffputcs_(&c__13, " ------------ PASS2 ---------- P =", (ftnlen)34);
    ffputi_(&c__13, &blank_1.p, &c__6);
    ffputnl_(&c__13);
L5000:
/*     POMIN,JESLI TO PROTOTYP FORMALNY/PROC.,FUN.,SYGNAL/ */
    if ((lbit_shift(blank_1.ipmem[blank_1.p - 1], (ftnlen)-4) & 15) != 0) {
	goto L2000;
    }

/* ... PODCZAS WYLICZANIA STALYCH POMIN,JESLI MODUL ICH NIE MA */
    if (init && blank_1.ipmem[blank_1.p - 2] == 0) {
	goto L2000;
    }

/*     POMIN , JESLI NIE MA INSTRUKCJI */
    if (blank_1.ipmem[blank_1.p + 8] == 0) {
	goto L2500;
    }

/* ... ODSZUKAJ PIERWSZY REKORD Z KODEM POSREDNIM */
    n = blank_1.ipmem[blank_1.p + 7];
/*     WSTAW NUMER I WCZYTAJ PIERWSZY REKORD */
    blank_1.ix[257] = n;
    seek_(stream_1.ibuf3, &n);
    if (! test_1.testc) {
	goto L6000;
    }
    ffputcs_(&c__13, " REKORD", (ftnlen)7);
    ffputi_(&c__13, &n, &c__5);
    ffputcs_(&c__13, "  SYMBOL", (ftnlen)8);
    ffputi_(&c__13, &blank_1.ipmem[blank_1.p + 8], &c__4);
    ffputnl_(&c__13);
L6000:
    get_(stream_1.ibuf3, blank_1.ix);
    stos_1.wb = blank_1.ipmem[blank_1.p + 8];
/*     WSTAW INDEKS BIEZACEGO SYMBOLU,USTAW WB */
    blank_1.ix[256] = stos_1.wb;
    stos_1.wb = blank_1.ix[stos_1.wb - 1];
/*     INICJALIZACJA */
    mproto_();
    sdpda_(&init);
    mprotc_();
/* ...........WEZ NASTEPNY MODUL */
L2000:
    blank_1.p = blank_1.ipmem[blank_1.p + 1];
    if (blank_1.p != 0) {
	goto L1000;
    }
/*     WSZYSTKIE MODULY JUZ SKOMPILOWANE. */

/* ................. FAZA GENERACJI KODU */
/* 		   /DRUGIE PRZEJSCIE PRZEZ KOD DLA MODULOW/ */

    if (! init) {
	return 0;
    }
    init = FALSE_;
    goto L100;


/* .....MODUL BEZ INSTRUKCJI. PREFIKS? */
L2500:
    blank_1.idl = blank_1.ipmem[blank_1.p + 20];
    if (blank_1.idl == 0) {
	goto L2600;
    }
/*     TAK. PRZEPISZ INFORMACJE O INSTRUKCJACH PO INNER */
    blank_1.ipmem[blank_1.p - 8] = blank_1.ipmem[blank_1.idl - 8];
    goto L2000;
/* ... BEZ PREFIKSU. DLA KLASY,REKORDU WSTAW: BRAK INSTR. PO INNER */
L2600:
    if ((blank_1.ipmem[blank_1.p - 1] & 15) != 1) {
	blank_1.ipmem[blank_1.p - 8] = 0;
    }
/* dsw&bc */
    if (! init) {
	stclass_();
    }
    goto L2000;
} /* spass2_ */

#undef staler
#undef stack


/* Subroutine */ int stclass_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr1_(integer *), quadr2_(integer *, 
	    integer *);
#define staler ((real *)&blank_1 + 302)

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


/* not yet used as prefix */
    blank_1.ipmem[blank_1.p] = 0;
/* begin of module */
    quadr2_(&c__184, &blank_1.p);
/* begin of instructions */
    quadr1_(&c__179);
/* inner */
    quadr2_(&c__178, &blank_1.ipmem[blank_1.p + 22]);
/* after inner label */
    quadr2_(&c__181, &c__1);
/* fin */
    quadr1_(&c__194);
/* lastwill */
    quadr1_(&c__174);
    blank_1.ipmem[blank_1.p + 7] = 0;
/* back */
    quadr1_(&c__193);
/* end module */
    quadr1_(&c__185);
    return 0;
} /* stclass_ */

#undef staler
#undef stack


/* Subroutine */ int sdpda_(logical *inicja)
{
    /* System generated locals */
    integer i__1;
    static real equiv_2[1];

    /* Local variables */
    static integer i__;
#define m ((shortint *)equiv_2)
    static integer n;
#define y (equiv_2)
    static integer ind, ats, elem;
    extern /* Subroutine */ int send_(void), seof_(integer *), sfin_(void), 
	    sget_(integer *);
    extern integer mdot_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int merr_(integer *, integer *), spop_(void), 
	    snot_(void), sput_(integer *), seof0_(integer *), scase_(void), 
	    sesac_(void), sread_(integer *);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int skill_(void), sconc_(integer *), sinit_(void);
    static integer error;
    extern integer swhat_(integer *), mthis_(integer *);
    static integer whdsw;
    extern integer svats_(integer *);
    extern /* Subroutine */ int snext_(void), spush_(integer *), quadr1_(
	    integer *), quadr2_(integer *, integer *), quadr3_(integer *, 
	    integer *, integer *), quadr4_(integer *, integer *, integer *, 
	    integer *), serro2_(integer *, integer *), scheck_(integer *, 
	    integer *), scallb_(void), scalle_(void), scslab_(void);
    extern integer maquab_(integer *);
    extern /* Subroutine */ int sfladr_(void);
    extern integer mident_(integer *);
    extern /* Subroutine */ int sparam_(void), spgrec_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern logical mloctp_(integer *, integer *), mdistp_(integer *, integer *
	    , integer *);
    static logical forstp;
    extern /* Subroutine */ int serror_(integer *), sindex_(void), sindxs_(
	    void), svalue_(void);
    extern integer tstemp_(integer *);
    extern /* Subroutine */ int sforto_(logical *, logical *), sstovf_(void);
    extern integer tsinse_(integer *, integer *);
    extern /* Subroutine */ int sarith_(void), sother_(void), srelat_(void), 
	    sresum_(void), swrite_(integer *), slwill_(void);
    extern integer sconst_(integer *);
    extern /* Subroutine */ int sftest_(void), sstore_(integer *, integer *), 
	    sreslt1_(integer *), sattach_(void);
    extern integer smember_(integer *);
    extern /* Subroutine */ int sforend_(void), svaradr_(void), sassign_(void)
	    , smodify_(integer *, integer *), sboolex_(integer *), snewarr_(
	    void), sindtyp_(void), soption_(void), sreturn_(void);

/* ----------------------------------------------------------------------------- */

/*     WERSJA 1983.03.09 */

/*     GLOBAL JUMPS ARE CHANGED TO LOCAL JUMPS IF POSSIBLE  OTHERWISE THEY ARE */
/*     CHANGED TO COMPUTED JUMPS  8.5.84 */

/*     MAIN ROUTINE OF SEMANTIC ANALYSIS AND CODE GENERATION */
/*     GLOWNA PROCEDURA ANALIZY SEMANTYCZNEJ I GENERACJI KODU POSREDNIEGO */
/*     /CZWOREK/ DLA MODULU. */
/*     PRACUJE JAK DETERMINISTYCZNY AUTOMAT ZE STOSEM STEROWANY SYMBOLEM */
/*     WEJSCIOWYM. */
/*     W ZALEZNOSCI OD WB /SYMBOL WEJSCIOWY/ WYBIERANA JEST AKCJA DO WYKONANIA */
/*     O ETYKIECIE 100*WB : OD 100 DO 7200. */
/*     WB MUSI MIEC NADANA WARTOSC PRZED WYWOLANIEM SDPDA. */

/*     DLA KAZDEGO MODULU WOLANA DWUKROTNIE: */
/*      PIERWSZY RAZ W FAZIE WYLICZANIA STALYCH /O ILE MODUL ZAWIERAL */
/* 	STALE WYLICZANE/ I DRUGI RAZ W FAZIE GENERACJI KODU /O ILE */
/* 	BYLY INSTRUKCJE/. */
/*     W FAZIE WYLICZANIA STALYCH PO WYSTAPIENIU ZNACZNIKA PIERWSZEJ */
/* 	INSTRUKCJI ZASTEPUJE W PROTOTYPIE ADRES POCZATKU KODU DLA MODULU */
/* 	PRZEZ NUMER REKORDU I MIEJSCE W REKORDZIE ZAWIERAJACE TEN ZNACZNIK. */



/*     ##### OUTPUT CODE :    15 , 23 , 31 , 33 , 34 , 35 , 36 , 41 , */
/* 			     85 , 132 , 145 , 149 , 151 , 152 , */
/* 			     172 , 173 , 176 , 177 , 178 , 179 , */
/* 			     181 , 182 , 186 , 187 . */


/*     ##### DETECTED ERROR(S) :   407 , 410 , 411 , 414 , 415 , 416 , */
/* 		      418 , 420 , 421 , 422 , 423 , 424 , 426 , 427 , */
/* 		      428 , 429 , 430 , 440 , 444 , 449 , 454 , 604 . */


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


/* 	     STACK - STOS DLA ANALIZY SEMANTYCZNEJ. OD LEWEJ WKLADANE SA */
/* 		     ELEMENTY,OD PRAWEJ OPISY PARAMETROW OUTPUT. */
/* 		     KAZDY ELEMENT STOSU ZAJMUJE KILKA KOLEJNYCH SLOW */
/* 		     OZNACZANYCH -9,...,-1,0. ZEROWE SLOWO OKRESLA RODZAJ */
/* 		     ELEMENTU. */
/* 		       OPISY PAR. OUTPUT ZAJMUJA ZAWSZE 12 SLOW: -9,..,+2 */
/* 		     STOS /400 SLOW + WARTOWNIK/ ZAJMUJE W TABLICY IPMEM */
/* 		     SLOWA OD BOTTOM = LMEM-916 DO LMEM-516 */
/* 		     ELEMENTY STOSU : */
/* 				    0 - UNIWERSALNY */
/* 				    1 - STALA */
/* 				    2 - WARTOSC */
/* 				    3 - ZMIENNA */
/* 				    4 - ELEMENT TABLICY DYN. */
/* 				    5 - TABLICA STATYCZNA */
/* 				    6 - OPIS PETLI "FOR" */
/* 				    7 - NAZWA TYPU */
/* 				    8 - REKORD */
/* 				    9 - KLASA */
/* 				   10 - BLOK PREFIKSOWANY */
/* 				   11 - PROCEDURA */
/* 				   12 - FUNKCJA */
/* 				   13 - SYGNAL */
/* 				   14 - OPERATOR */
/* 	     BOTTOM - WSKAZUJE DNO STOSU / WARTOWNIKA = -1 / */
/* 	     VALTOP - CZUBEK STOSU /INDEKS ZEROWEGO SLOWA/ */
/* 	     VLPREV - INDEKS ZEROWEGO SLOWA POPRZEDNIEGO ELEMENTU */
/* 	     STCKAG,STCKA0,STCKAP - TABLICA  -1..14 APETYTOW ELEMENTOW STOSU */
/* 			    /TZN. STCKAP(I)=APETYT ELEMENTU TYPU I/ */
/* 		      STCKAP(-1)= 0 =APETYT WARTOWNIKA DLA POP */
/* 	     APETYT - TABLICA OKRESLAJACA DLA KAZDEGO RODZAJU TYPU JEGO */
/* 		       APETYT.	1,2,3,4 --> 1,2,3,2 */
/* 	     LSTFOR - INDEKS OSTATNIEGO SLOWA ZAJETEGO PRZEZ PETLE FOR */
/* 	     LSTLSE -	"        "      LSE NA STOSIE /LSE ,TZN. LEWE STRONY */
/* 		      PODSTAWIENIA SA UMIESZCZONE POWYZEJ LSTFOR DO LSTLSE/ */
/* 	     KIND - RODZAJ WOLANEGO MODULU: 0-ZWYKLY,1-VIRTUALNY,2-FORMALNY */
/* 	     PHADR - ATS ADRESU FIZYCZNEGO POLA DANYCH GENEROWANEGO OBIEKTU */
/* 		      LUB 0 ,GDY  ADR.FIZYCZNY TRZEBA ODTWORZYC Z ADR.VIRT. */
/* 	     LASTPR - JESLI NA STOSIE JEST FUNKCJA,PROCEDURA,KLASA,REKORD, */
/* 		      SYGNAL,BLOK PREF. , DLA KTOREGO PAMIETANY JEST TYLKO */
/* 		      ADRES POSREDNI ZAMIAST PELNEGO ADR.VIRTUALNEGO, TO */
/* 		      LASTPR= INDEKS TEGO ELEMENTU; INACZEJ ZERO */
/* 	     FSTOUT - INDEKS PIERWSZEGO SLOWA ZAJETEGO PRZEZ OPISY PAR. */
/* 		      OUTPUT */
/* 	     WB     - BIEZACY SYMBOL /WEJSCIOWY/ KODU POSREDNIEGO */
/* 	     RESULT - ATS WYNIKU OPERACJI */
/* 	     CONSNR -	  TABLICA ZAWIERAJACA ADRESY /INDEKSY W IPMEM/ TYPOW: */
/* 		 BOOLEAN,CHAR,INTEGER,NONE,REAL,STRING I UNIWERSALNEGO . */
/* 	     LSTSAF - OSTATNI ELEMENT STOSU NIE WYMAGAJACY ZABEZPIECZENIA */
/* 		       PRZEZ SAFEST ,USTAWIA SAFEST,OBNIZA SPOP. */
/* 	     TEMPNR - POCZATEK ADRESOW W /BUDOWANEJ/ TABLICY SYMBOLI */
/* 		       UZYWANYCH DLA ATRYBUTOW ROBOCZYCH, */
/* 		       ADRESY WIEKSZE ZAREZERWOWANE DLA PETLI FOR, */
/* 			ZMNIEJSZANE O 6 NA POCZATKU, A ZWIEKSZANE NA KONCU */
/* 			PETLI. */
/* 	     LSTEMP - NAJMNIEJSZY UZYTY ADRES ATRYBUTU ROBOCZEGO */

/* 	     QRECNR - OSTATNI UZYTY NUMER REKORDU W STRUMIENIU 3 */
/* 		   BUFOR NA GENEROWANY KOD POSREDNI WYSYLANY NA STRUMIEN 3 */
/* 		   ZAJMUJE 259 SLOW W TABLICY IPMEM : OD LMEM-259 DO LMEM-1 . */
/* 	     LSTWRD - INDEKS OSTATNIEGO ZAJETEGO SLOWA W BUFORZE. */

/* 		 ZASADA WYPELNIANIA BUFORA : SA CO NAJMNIEJ 4 WOLNE SLOWA */
/* 		 / LSTWRD < LMEM-4 / . PROCEDURY QUADR1 .. QUADR4 */
/* 		  DOPISUJA ZA LSTWRD SWOJE ARGUMENTY I ZWIEKSZAJA LSTWRD. */
/* 		  JESLI POZOSTANA MNIEJ NIZ 4 SLOWA - WOLAJA QDROUT. */
/* 		 QDROUT WYPISUJE PIERWSZE 256 SLOW I OSTATNIE 3 SLOWA */
/* 		 PRZEPISUJE NA POCZATEK, ZMNIEJSZAJAC LSTWRD O 256. */
/* 	     FRSTTS - PIERWSZE SLOWO W IPMEM NA NOWE OPISY ATRYBUTOW */
/* 			W TABLICY SYMBOLI */
/* 		ZAPELNIANIE TABLICY SYMBOLI: TSINSE -->  <-- TSTEMP */
/* 		       OBSZAR WOLNY -	FRSTTS .. LSTEMP-1 */
/* 	     UNIT - RODZAJ BIEZACEGO MODULU: */
/* 				1 - BLOK */
/* 				2 - HANDLER */
/* 				3 - BLOK PREFIKSOWANY */
/* 				4 - PROCEDURA */
/* 				5 - FUNKCJA */
/* 				6 - KLASA */
/* 	     INNER = 0 - NIE BYLO "INNER",ALE JEST LEGALNY */
/* 		     1 - WYSTAPIENIE "INNER" BEDZIE NIELEGALNE */
/* 		     2 - JUZ WYSTAPIL */
/* 		     4 - LAST-WILL  WYSTAPIENIE INNER NIELEGALNE */
/* 	     LSTWILL - TRUE,JESLI WYSTAPILO LAST WILL */

/* 	     TEST - OPCJA / U3 / WYDRUKOW KONTROLNYCH , */
/* 		      = 0 --> BEZ WYDRUKOW , <> 0 --> WYDRUKI */

/* 	     ARG - INFORMACJA O STALYCH ARGUMENTACH /USTAWIANA PRZEZ */
/* 		    SARGMT/  : */
/* 			    1 - OBA STALE */
/* 			    2 - LEWY STALY,PRAWY NIE */
/* 			    3 - LEWY NIE,PRAWY STALY */
/* 			    4 - OBA ROZNE OD STALYCH */
/* 	     ATLINE - NUMER LINII, W KTOREJ PRZEBIEG MA SIE ZAWIESIC */

/* 	     FILE - ADRES PLIKU NA STOSIE LUB 0 DLA OPERACJI NA PLIKU */
/* 		     STANDARDOWYM */

/* 	     FLARGS - INFORMACJA O PRZETWORZONYCH ARGUMENTACH OPERACJI */
/* 		       WE/WY : */
/* 			0 - NIE WYSTAPIL ZADEN ARGUMENT */
/* 			1 - WYSTAPIL TYLKO ADRES PLIKU */
/* 			2 - WYSTAPIL CO NAJMNIEJ 1 ARGUMENT */
/* 			     ( LUB READLN/WRITELN ) */

/* 	     FLREADY - TRUE, JESLI (R6-12) ZAWIERA ADRES PLIKU, ZAPALANE PRZEZ */
/* 			SFLADR, GASZONE PRZEZ SCALLB I DLA 'I-O-END' */

/* 	     FLMODF - PRZELACZNIK NUMERU PROCEDURY STANDARDOWEJ UZYWANY */
/* 		       DLA WE/WY :  1 DLA PLIKU STANDARDOWEGO */
/* 				    0 DLA WSKAZYWANEGO */
/* 		      NUMERY PROCEDUR WE/WY (ROZNE PUNKTY WEJSCIA) SA */
/* 		       POWIAZANE : */
/* 			     INPUT	: N-1 */
/* 			     WSKAZYWANY : N */
/* 			     OUTPUT	: N+1 */

/* ............. */
/*   COMDECK OPT?      04.01.84 */
/*     COMMON/OPTION/OPTMEM,OPTOPT,OPTIND,OPTTYP,OPTTRC,OPTCSC,OPTCSF */
/*     LOGICAL OPTOPT,OPTTYP,OPTTRC */
/*   FROM LOGLAN.08 */

/* 	   ***** OPCJE KOMPILATORA ***** */

/* 	     OPTMEM -	    0 - TRZEBA ROBIC MEMBER */
/* 			    1 - NIE TRZEBA ROBIC MEMBER */
/* 	     OPTOPT -	  .TRUE. - WOLNO OPTYMALIZOWAC */
/* 			  .FALSE. - NIE WOLNO */
/* 	     OPTIND -	    0 - KONTROLA INDEKSOW DLA TABLIC */
/* 			    2 - BEZ KONTROLI INDEKSOW */
/* 	     OPTTYP -	   .TRUE. - BEZ DYNAMICZNEJ KONTROLI TYPOW */

/* 	     OPTTRC -	   .TRUE. - KOMPILAT POWINIEN ZAWIERAC SLEDZENIE */

/* 	     OPTCSC -	      1   - BEZ KONTROLI ZAKRESU DLA "CASE" */
/* 			      0     WYMAGANA KONTROLA */
/* 	     OPTCSF -	      0   - SZYBKI "CASE" */
/* 			      1   - PAMIECIOOSZCZEDNY */


/* ................ */

/* *COMDECK BLANKSEM */
/*     LOGICAL	INSYS,	OWN */
/*     COMMON /BLANK/ IOP(4), */
/*    X	      P, */
/*    X	      TLDIM, TLBAS,  IDL, OBJL, */
/*    X	      TRDIM, TRBAS,  IDR, OBJR, */
/*    X	      TRESLT, */
/*    X	      TRESLT, */
/*    X	      CONVL, CONVR, */
/*    X	      NRPAR, */
/*    X	      IX (261), */
/*    X	      LMEM  , LPMEM , IRECN , ISFIN , LPMSYS, LPML  , LPMF  , */
/*    X	      NRINT , NRRE  , NRBOOL, NRCHR , NRCOR , NRPROC, NRTEXT, */
/*    X	      NRUNIV, NATTR , NRNONE, NBLSYS, NBLUS , NEMPTY, INSYS , */
/*    X	      LOCAL,  OWN,    OBJECT, */
/*    X	      IPMEM(5000) */
/*     REAL   STALER(100) */
/*     INTEGER STACK(5000) */
/*     EQUIVALENCE(STALER(1),IPMEM(1)) */
/*     EQUIVALENCE(STACK(1),IPMEM(1)) */
/* ......COMDECK BLANKSEM */
/*      FROM LOGLAN.08	   17.01.84 */
/* 	      LMEM   - (=5000) ROZMIAR CALEJ PAMIECI GLOWNEJ */
/* 	      LPMEM  - PODZIAL PAMIECI NA CZESCI  IPMEM  I  IPMEM */

/*     CZESC SEMANT */
/* 	      P - PROTOTYP AKTUALNY */
/* 	      TLDIM - LICZBA ARRAY OF W TYPIE LEWEGO ARGUMENTU */
/* 	      TLBAS - TYP BAZOWY LEWEGO ARGUMENTU */
/* 	      DISPL - .TRUE. JESLI LEWY ARGUMENT JEST DOSTEPNY	PRZEZ */
/* 		   DISPLAY */
/* 	     OBJL - PROTOTYP OBIEKTU, Z KTOEGO POCHODZI TEN ATRYBUT */
/* 	      IDL - IDENTYFIKATOR LEWEGO ARGUMENTU (DO SYGNALIZACJI BLE- */
/* 		    DOW) */
/* 	      TRDIM, TRBAS, DISPR, IDR, OBJR - ANALOGICZNIE DLA PRAWEGO ARGU- */
/* 		    MENTU */
/* 	      TRESLT - TYP BAZOWY WYNIKU OPERACJI ARYTMETYCZNEJ */
/* 	      CONVL, CONVR - FLAGA KONWERSJI LEWEGO I PRAWEGO ARGUMENTU */
/* 		    OPERACJI ARYTMETYCZNYCH LUB RELACJI */
/* 		    WARTOSCI : */
/* 		      0 - BRAK KONWERSJI */
/* 		      1 - KONWERSJA DO REAL */
/* 		      2 - KONWERSJA DO INTEGER (?) */
/* 	      NRPAR - NUMER PARAMETRU (PROCEDURA  MPKIND) */

/* 	      IRECN  - INDEKS SZCZYTU STOSU STALYCH REAL */
/* 	      ISFIN  - INDEKS SZCZYTU SLOWNIKA PROTOTYPOW */

/* 	      LPMSYS - INDEKS PIERWSZEGO SLOWA W IPMEM OBSZARU NIEPRZEZ- */
/* 		       NACZONEGO NA PROTOTYPY SYSTEMOWE */
/* 	      LPML   - INDEKS PIERWSZEGO SLOWA OBSZARU WOLNEGO W IPMEM */
/* 	      LPMF   - INDEKS OSTATNIEGO SLOWA WOLNEGO OBSZARU W IPMEM */

/*     IDENTYFIKATORY PROTOTYPOW SYSTEMOWYCH */
/* 	      NRINT  - IDENTYFIKATOR PROTOTYPU	INTEGER */
/* 	      NRRE   -				REAL */
/* 	      NRBOOL -				BOOLEAN */
/* 	      NRCHR  -				CHARACTER */
/* 	      NRCOR  -				COROUTINE */
/* 	      NRPROC -				PROCESS */
/* 	      NRTEXT -				STRING (TEXT) */
/* 	      NRUNIV - IDENTYFIKATOR PROTOTYPU UNIWERSALNEGO */
/* 	      NATTR  - IDENTYFIKATOR PSEUDO-ATRYBUTU (Z NUMEREM -1) */
/* 	      NRNONE - IDENTYFIKATOR PROTOTYPU TYPU NONE (UNIWERSALNY */
/* 		       REFERENCYJNY) */
/* 	      NBLSYS - IDENTYFIKATOR BLOKU SYSTEMOWEGO */
/* 	      NBLUS  -		     BLOKU GLOWNEGO UZYTKOWNIKA */

/* 	      INSYS  - FLAGA SPOSOBU REZERWACJI (PRZEZ	MGETM) PAMIECI */
/* 		       W IPMEM - .TRUE. JESLI REZERWACJA W CZESCI SYSTE- */
/* 		       MOWEJ */
/* 	      LOCAL  - FLAGA DOSTEPU DO OBIEKTOW - .TRUE. JESLI OBIEKT */
/* 		       BYL LOKALNY */
/* 	      OWN    - FLAGA DOSTEPU DO OBIEKTOW - .TRUE. JESLI OBIEKT NIE */
/* 		       POCHODZI Z PREFIKSOW (TYLKO Z WLASCIWEGO OBIEKTU) */
/* 	      OBJECT - PROTOTYP OBIEKTU, Z KTOREGO POCHODZIL OSTATNIO */
/* 		      SZUKANY IDENTYFIKATOR (OBIEKT POCHODZACY Z CIAGU SL) */




/* dsw&bc */
/* dsw&bc */


/*     INICJA=.TRUE. W FAZIE WYLICZANIA WARTOSCI STALYCH SYMBOLICZNYCH I GRANIC */
/*     TABLIC STATYCZNYCH. */



/*     ERROR=NUMER BLEDU DLA WSPOLNEJ SYGNALIZACJI /9900/ */

/*     DLA PETLI "FOR" : TRUE --> WYSTAPILO "STEP", FALSE --> NIE WYSTAPILO */



/*     AUXILIARY VARIABLES */

/* .....INICJALIZACJA */
/* dsw&bc      FRSTTS=LPMEM+1 */
    stos_1.frstts = stacks_1.btsins;

/*     =INDEKS POCZATKU TABLICY SYMBOLI - CZESC DLA ATRYBUTOW DEKLAROWANYCH */
    blank_1.ipmem[blank_1.lmem - 1] = stos_1.bottom - 1;
/*     OSTATNIE SLOWO IPMEM ZAWIERA INDEKS PIERWSZEGO OD PRAWEJ WOLNEGO */
/*     SLOWA NA POMOCNICZY SLOWNIK DLA WYZNACZANIA ADRESOW ATRYBUTOW */
/*     DEKLAROWANYCH W TABLICY SYMBOLI. */



    stos_1.consnr[0] = blank_1.nrbool;
    stos_1.consnr[1] = blank_1.nrchr;
    stos_1.consnr[2] = blank_1.nrint;
    stos_1.consnr[3] = blank_1.nrnone;
    stos_1.consnr[4] = blank_1.nrre;
    stos_1.consnr[5] = blank_1.nrtext;
    stos_1.consnr[6] = blank_1.nruniv;
/* dsw&bc */
    stos_1.consnr[7] = -17;
    if (*inicja) {
	goto L10;
    }
    sinit_();
L10:
    stos_1.valtop = stos_1.bottom;
    stos_1.vlprev = stos_1.bottom;
    stos_1.lstlse = stos_1.bottom;
    stos_1.lstfor = stos_1.bottom;
    stos_1.lastpr = 0;
    stos_1.lstsaf = stos_1.bottom;
    stos_1.fstout = stos_1.bottom + 401;
/* dsw&bc      TEMPNR=LMEM-6 */
    stos_1.tempnr = stacks_1.btstem - 6;

    stos_1.lstemp = stos_1.tempnr;
    stos_1.file = 0;
    stos_1.flargs = 0;
    stos_1.flready = FALSE_;
    stos_1.flmodf = 1;
    stos_1.icount = 0;
    stos_1.ocount = 0;
    goto L50;



L30:
    spop_();
L40:
    snext_();
/* .....GLOWNA PETLA.  W ZALEZNOSCI OD SYMBOLU Z WEJSCIA WYBIERZ AKCJE */
L50:
    switch (stos_1.wb) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
	case 10:  goto L1000;
	case 11:  goto L1100;
	case 12:  goto L1200;
	case 13:  goto L1300;
	case 14:  goto L1400;
	case 15:  goto L1500;
	case 16:  goto L1600;
	case 17:  goto L1700;
	case 18:  goto L1800;
	case 19:  goto L1900;
	case 20:  goto L2000;
	case 21:  goto L2100;
	case 22:  goto L2200;
	case 23:  goto L2300;
	case 24:  goto L2400;
	case 25:  goto L2500;
	case 26:  goto L2600;
	case 27:  goto L2700;
	case 28:  goto L2800;
	case 29:  goto L2900;
	case 30:  goto L3000;
	case 31:  goto L3100;
	case 32:  goto L3200;
	case 33:  goto L3300;
	case 34:  goto L3400;
	case 35:  goto L3500;
	case 36:  goto L3600;
	case 37:  goto L3700;
	case 38:  goto L3800;
	case 39:  goto L3900;
	case 40:  goto L4000;
	case 41:  goto L4100;
	case 42:  goto L4200;
	case 43:  goto L4300;
	case 44:  goto L4400;
	case 45:  goto L4500;
	case 46:  goto L4600;
	case 47:  goto L4700;
	case 48:  goto L4800;
	case 49:  goto L4900;
	case 50:  goto L5000;
	case 51:  goto L5100;
	case 52:  goto L5200;
	case 53:  goto L5300;
	case 54:  goto L5400;
	case 55:  goto L5500;
	case 56:  goto L5600;
	case 57:  goto L5700;
	case 58:  goto L5800;
	case 59:  goto L5900;
	case 60:  goto L6000;
	case 61:  goto L6100;
	case 62:  goto L6200;
	case 63:  goto L6300;
	case 64:  goto L6400;
	case 65:  goto L6500;
	case 66:  goto L6600;
	case 67:  goto L6700;
	case 68:  goto L6800;
	case 69:  goto L6900;
	case 70:  goto L7000;
	case 71:  goto L7100;
	case 72:  goto L7200;
	case 73:  goto L7300;
	case 74:  goto L7400;
	case 75:  goto L7500;
	case 76:  goto L7600;
	case 77:  goto L7700;
	case 78:  goto L7800;
	case 79:  goto L7900;
	case 80:  goto L8000;
	case 81:  goto L8100;
	case 82:  goto L8200;
	case 83:  goto L8300;
	case 84:  goto L8400;
	case 85:  goto L8500;
	case 86:  goto L8600;
	case 87:  goto L8700;
	case 88:  goto L8800;
	case 89:  goto L8900;
	case 90:  goto L9000;
	case 91:  goto L9100;
	case 92:  goto L9200;
	case 93:  goto L9300;
	case 94:  goto L9400;
    }
/* bc  X 8600,8700,8800,8900,9000),WB */
/* bc  X 8600,8700,8800),WB */

/* ----------------  AND	  -------------------------- */

L100:
    sboolex_(&c__1);
    goto L40;

/* ---------------  ARRAY OF  ------------------------ */

/*     ZWRACA : SLOWO -2 =0  - TYP STATYCZNY (-3),(-4) */
/* 	       SLOWO -2 >0 - ATS ZMODYFIKOWANEGO TYPU FORMALNEGO */

L200:
    snext_();
/*      WB=LICZBA ARRAY OF */
/*     CZY NA CZUBKU JEST KLASA,REKORD LUB NAZWA TYPU? */
    elem = stack[stos_1.valtop - 1];
    if (elem == 0) {
	goto L40;
    }
    if (elem < 7 || elem > 9) {
	goto L250;
    }
/*     OK. WPISZ LICZBE ARRAY OF */
    stack[stos_1.valtop - 4] = stos_1.wb;
/*     CZY TYP FORMALNY? */
    if (stack[stos_1.valtop - 3] != 0) {
	smodify_(&stack[stos_1.valtop - 3], &stos_1.wb);
    }
    goto L40;
/* .....NIEPOPRAWNY CZUBEK STOSU */
L250:
    error = 440;
    goto L9900;

/* ---------------  ASSIGN  -------------------------- */

/*     CZUBEK STOSU POWINIEN ZAWIERAC WARTOSC,PONIZEJ SA LSE /POWYZEJ LSTFOR DO */

L300:
    sassign_();
    goto L40;

/* ---------------  ASSIGN CONST	-------------------- */
/*     CZUBEK STOSU POWINIEN ZAWIERAC STALA /WARTOSC WYRAZENIA DEFINIUJACEGO/, */
/*     PONIZEJ CZUBKA JEST STALA DEFINIOWANA,MAJACA W SLOWIE -2 INDEKS */
/*     SWOJEGO OPISU W IPMEM. */

/*     STALA? */
L400:
    if (stack[stos_1.vlprev - 1] == 0 || stack[stos_1.valtop - 1] == 0) {
	goto L420;
    }
    if (stack[stos_1.valtop - 1] == 1) {
	goto L410;
    }
    serro2_(&c__429, &stos_1.vlprev);
    goto L420;
/*     POBIERZ ADRES OPISU STALEJ DEFINIOWANEJ */
L410:
    elem = stack[stos_1.vlprev - 3];
/*     WPISZ WARTOSC I TYP */
    blank_1.ipmem[elem - 2] = stack[stos_1.valtop - 3];
    blank_1.ipmem[elem - 5] = 0;
    blank_1.ipmem[elem - 4] = stack[stos_1.valtop - 5];
L420:
    spop_();
    goto L30;

/* ---------------  ATTACH  -------------------------- */
/*     CZUBEK STOSU POWINIEN ZAWIERAC REFERENCJE */

L500:
    sattach_();
    stos_1.lstemp = stos_1.tempnr;
    goto L30;

/* ---------------  BLOCK  --------------------------- */
/*      WYSTAPIENIE BLOKU O NUMERZE WN */
L600:
    snext_();
    quadr2_(&c__186, &blank_1.ipmem[stos_1.wb - 1]);
    stos_1.lstemp = stos_1.tempnr;
    goto L40;

/* ---------------  CALL	---------------------------- */
/*     NA PEWNO BLAD: PROCEDURA SAMA "ZJADA" CALL. */

L700:
    serror_(&c__422);
    goto L30;

/* ---------------  CASE	---------------------------- */
L800:
    scase_();
    goto L30;
/*     WRACA DO ETYKIETY 30 */
/* ---------------  CASE LABEL  ---------------------- */
L900:
    scslab_();
    goto L30;
/*     WRACA DO ETYKIETY 30 */
/* ---------------  COMA	---------------------------- */

/*     PONIZEJ CZUBKA JEST : */
/* 	 UNIWERSALNY LUB ELEMENT TABLICY/DYN./ LUB TABLICA STATYCZNA */
/* 	  LUB REKORD,KLASA,BLOK PREF.,PROCEDURA,FUNKCJA. */
/*     NA CZUBKU JEST INDEKS LUB PARAMETR AKTUALNY. */
/*     PO OBSLUZENIU  WOLA SNEXT */

L1000:
    elem = stack[stos_1.vlprev - 1];
/*     JESLI UNIWERSALNY-OMIN */
    if (elem == 0) {
	goto L30;
    }
/*     CZY TO PARAMETR? */
    if (elem > 7) {
	goto L1050;
    }
/*     NIE,MOZE TABLICA STATYCZNA? */
    if (elem == 5) {
	goto L1060;
    }
/*     ZATEM TABLICA DYNAMICZNA /ELEMENT TABLICY/ */
    sindex_();
    goto L30;
L1050:
    sparam_();
    goto L40;
L1060:
    sindxs_();
    goto L40;

/* ---------------  CONST:BOOL,CHAR,INT,NONE,REAL,STRING	----- */

L1100:
L1200:
L1300:
L1500:
L1600:
    elem = stos_1.wb - 10;
    snext_();
/* .....WSPOLNA AKCJA DLA WSZYSTKICH STALYCH,ROWNIEZ NONE */
L1650:
    spush_(&c__1);
    stack[stos_1.valtop - 2] = 0;
    stack[stos_1.valtop - 3] = stos_1.wb;
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 5] = stos_1.consnr[elem - 1];
    stack[stos_1.valtop - 6] = 0;
    goto L40;
/* .....WYROZNIONY POCZATEK DLA NONE */
L1400:
    elem = 4;
    stos_1.wb = 0;
    goto L1650;


/* ---------------  COPY	---------------------------- */
/*     NA CZUBKU STOSU JEST WARTOSC DO SKOPIOWANIA. */

L1700:
    svalue_();
/*     JESLI UNIWERSALNY-POMIN */
    if (stack[stos_1.valtop - 1] == 0) {
	goto L40;
    }
/*     ZBADAJ TYP. POMIN NONE. */
    elem = stack[stos_1.valtop - 5];
    if (elem == blank_1.nrnone) {
	goto L40;
    }
/*     MOZE TO TABLICA? */
    if (stack[stos_1.valtop - 4] > 0) {
	goto L1750;
    }
/*     NIE. CZY TYP PIERWOTNY? */
    for (i__ = 1; i__ <= 6; ++i__) {
	if (stos_1.consnr[i__ - 1] == elem) {
	    goto L1790;
	}
/* L1730: */
    }
/* .....ZATEM O.K. */
L1750:
    ats = tstemp_(&c__4);
    quadr3_(&c__41, &ats, &stack[stos_1.valtop - 3]);
    stack[stos_1.valtop - 1] = 2;
    stack[stos_1.valtop - 3] = ats;
    goto L40;
/* .....NIE REFERENCJA */
L1790:
    error = 415;
    goto L9900;

/* ---------------  DETACH  -------------------------- */

L1800:
    quadr1_(&c__187);
    stos_1.lstemp = stos_1.tempnr;
    goto L40;

/* ---------------  DOT ------------------------------ */

L1900:
    snext_();
/*     WB=IDENT */
    snext_();
/*     WB = NAZWA PO KROPCE */
    svalue_();
    if (stack[stos_1.valtop - 1] != 0) {
	goto L1910;
    }
/*     UNIWERSALNY.IDENT ZASTAP PRZEZ UNIWERSALNY Z NAZWA PO KROPCE */
    stack[stos_1.valtop - 2] = stos_1.wb;
    goto L40;
/*     O.K. */
L1910:
    i__ = stack[stos_1.valtop - 5];
/*     I=KWALIFIKACJA WARTOSCI PRZED KROPKA */
    ind = mdot_(&stack[stos_1.valtop - 4], &i__, &stack[stos_1.valtop - 2], &
	    stos_1.wb);
    ats = stack[stos_1.valtop - 3];
/*     ATS=WARTOSC PRZED KROPKA */
    spop_();
/*     DALEJ JAK DLA WIDOCZNEGO IDENTYFIKATORA */
    goto L2805;
/* ---------------  DOWNTO  -------------------------- */
L2000:
    sforto_(&c_false, &forstp);
    goto L40;
/*     POWROT DO ETYKIETY 40 */
/* ---------------  SIGN	---------------------------- */
L2100:
    svalue_();
    elem = stack[stos_1.valtop - 1];
    blank_1.idl = stack[stos_1.valtop - 3];
    if (elem == 0) {
	goto L40;
    }
    if (stack[stos_1.valtop - 4] > 0) {
	goto L2110;
    }
    ats = 1;
    if (stack[stos_1.valtop - 5] == blank_1.nrint) {
	goto L2130;
    }
    if (stack[stos_1.valtop - 5] == blank_1.nrre) {
	goto L2150;
    }
/* ... NIEPOPRAWNY TYP ARGUMENTU SIGN */
L2110:
    error = 604;
    goto L9900;
/* ... INTEGER.	 STALA ? */
L2130:
    if (elem != 1) {
	goto L2160;
    }
    if (blank_1.idl < 0) {
	ats = -1;
    }
    if (blank_1.idl == 0) {
	ats = 0;
    }
    goto L2170;
/* ... REAL.	 STALA ? */
L2150:
    if (elem != 1) {
	goto L2160;
    }
/* dsw&bc      IF(STALER(IDL).LT. 0.0) ATS= -1 */
/* dsw&bc      IF(STALER(IDL).EQ. 0.0) ATS= 0 */
    if (staler[blank_1.idl - 1] < 0.f) {
	ats = -1;
    }
    if (staler[blank_1.idl - 1] == 0.f) {
	ats = 0;
    }

    goto L2170;
/* ... GENERUJ KOD */
L2160:
    ats = tstemp_(&c__1);
    quadr3_(&c__31, &ats, &blank_1.idl);
/*     ZASTAP PRZEZ WARTOSC */
    stack[stos_1.valtop - 1] = 2;
L2170:
    stack[stos_1.valtop - 2] = 0;
    stack[stos_1.valtop - 3] = ats;
    stack[stos_1.valtop - 5] = blank_1.nrint;
    goto L40;
/* ---------------  ESAC	---------------------------- */
L2200:
    sesac_();
    goto L40;
/* ---------------  FIN  ----------------------------- */

L2300:
    send_();
    return 0;


/* ---------------  FIRSTINSTR  ---------------------- */

/*     JESLI TO FAZA WYLICZANIA STALYCH - ZAPAMIETAJ TO MIEJSCE I KONCZ. */

L2400:
    if (*inicja) {
	goto L2450;
    }
    snext_();
/*     PIERWSZA INSTRUKCJA MODULU, WB=NUMER INSTRUKCJI */
    quadr1_(&c__179);
    stream_2.line = stos_1.wb;
    goto L40;

/* ... KONIEC WYLICZANIA STALYCH DLA TEGO MODULU */
L2450:
    blank_1.ipmem[blank_1.p + 7] = blank_1.ix[257];
    blank_1.ipmem[blank_1.p + 8] = blank_1.ix[256];
    return 0;
/* ---------------  FOR END  ------------------------- */

L2500:
    sforend_();
    goto L30;
/*     POWROT DO ETYKIETY 30 */
/* ---------------  FOR VARIABLE	-------------------- */

/*     PISZ : KONIEC BLOKU BAZOWEGO /BY UNIKNAC PONOWNEGO PRZYDZIALU */
/* 	  TYCH SAMYCH ATRYBUTOW ROBOCZYCH W JEDNYM BLOKU/ */
L2600:
    quadr1_(&c__176);
/*     ZAREZERWUJ 2 NUMERY DLA ATRYBUTOW ROBOCZYCH DLA PETLI FOR */
    stos_1.tempnr += -6;
    if (stos_1.frstts >= stos_1.lstemp) {
	sstovf_();
    }


    stos_1.lstemp = stos_1.tempnr;


/* ... ZMIENNA PROSTA? */
    ind = stack[stos_1.valtop - 1];
    if (ind == 0) {
	goto L40;
    }
    error = 410;
/*     ="OCZEKIWANA ZMIENNA PROSTA" */
    if (ind != 3 || stack[stos_1.valtop - 8] != 0) {
	goto L9900;
    }
/*     TAK. INTEGER? */
    scheck_(&c__411, &blank_1.nrint);
    stos_1.lstlse = stos_1.valtop;
    goto L40;
/* ---------------  FROM	---------------------------- */

L2700:
    sindtyp_();
    forstp = FALSE_;
    goto L40;
/* ---------------  IDENTYFIKATOR  ------------------- */
/*     WB=IDENT , WN=NAZWA ZE SCANNERA */
L2800:
    snext_();
    ind = mident_(&stos_1.wb);
    ats = 0;
/* ..........WSPOLNE ROZPOZNANIE I OBSLUGA DLA IDENTYFIKATORA PRZEZ KROPKE */
/*     LUB WIDOCZNEGO. */
/*     IND = ADRES ZEROWEGO SLOWA OPISU ROZPOZNANEGO IDENTYFIKATORA */
/*     ATS= ATS WARTOSCI PRZED KROPKA /I=KWALIFIKACJA/ LUB ZERO */

L2805:
    elem = swhat_(&ind);
/*     WLOZ NA STOS , WPISZ NAZWE , WEZ KOLEJNY SYMBOL */
    spush_(&elem);
    stack[stos_1.valtop - 2] = stos_1.wb;
    snext_();
/*     FAZA WYLICZANIA STALYCH ? */
    if (*inicja) {
	goto L2850;
    }
/*     NIE. */
/*     JESLI TO "UNIWERSALNY"-NIC NIE ROB */
    if (elem == 0) {
	goto L50;
    }
L2807:
    stack[stos_1.valtop - 7] = 0;
    stack[stos_1.valtop - 8] = ats;
    stack[stos_1.valtop - 6] = 0;
/*     NAZWA TYPU? */
    if (elem == 7) {
	goto L2880;
    }
    if (elem > 5) {
	goto L2870;
    }
/* .....STALA,ZMIENNA,TABLICA STATYCZNA. WSTAW TYP. */
    stack[stos_1.valtop - 5] = blank_1.ipmem[ind - 4];
/*     STALA? */
    if (elem != 1) {
	goto L2815;
    }
/* ....."STALA" */
    stack[stos_1.valtop - 4] = 0;
    if (! (*inicja)) {
	stack[stos_1.valtop - 3] = blank_1.ipmem[ind - 2];
    }
/*     WSTAWIONY TYP,WARTOSC STALEJ */
    goto L50;
/* ....."ZMIENNA","TABLICA STATYCZNA" */
L2815:
    stack[stos_1.valtop - 4] = blank_1.ipmem[ind - 5];
    stack[stos_1.valtop - 3] = ind;
    if (ats == 0) {
	stack[stos_1.valtop - 3] = tsinse_(&ind, &blank_1.local);
    }
/*     WSTAWIONY ATS */
/* .....TYPU FORMALNEGO? */
    elem = stack[stos_1.valtop - 5];
L2820:
    elem = blank_1.ipmem[elem - 1] & 15;
/*     ELEM=POLE T TYPU ZMIENNEJ */
    if (elem != 6) {
	goto L2830;
    }
/*     A WIEC TYP FORMALNY. PRZEZ KROPKE? */
    if (ats != 0) {
	goto L2825;
    }
/* .....PRZEZ DISPLAY */
    stack[stos_1.valtop - 7] = blank_1.object;
/*     CZY TYP DOSTEPNY PRZEZ DISPLAY? */
    if (mdistp_(&blank_1.ipmem[ind - 2], &stack[stos_1.valtop - 5], &elem)) {
	goto L2823;
    }
/*     TYP NIEDOSTEPNY PRZEZ DISPLAY,WSTAW SL ZMIENNEJ */
    stack[stos_1.valtop - 6] = -blank_1.ipmem[ind - 2];
    goto L2830;
/*     TYP DOSTEPNY PRZEZ DISPLAY,WSTAW WARSTWE */
L2823:
    stack[stos_1.valtop - 6] = elem;
    goto L2830;
/* .....PRZEZ KROPKE. TYP JEST LOKALNYM ATRYBUTEM? */
L2825:
    stack[stos_1.valtop - 6] = -1;
    if (mloctp_(&stack[stos_1.valtop - 5], &i__)) {
	stack[stos_1.valtop - 6] = 1;
    }
/* .....TYP JUZ WSTAWIONY */
L2830:
    if (stack[stos_1.valtop - 1] == 3) {
	goto L50;
    }
    if (stack[stos_1.valtop - 1] == 12) {
	goto L2875;
    }
/* ....."TABLICA STATYCZNA" */
/*      NA RAZIE  B R A K */
    goto L50;

/* ... W FAZIE WYLICZANIA STALYCH */
L2850:
    if (elem < 2) {
	goto L2860;
    }
/*     NIELEGALNY OBIEKT W WYRAZENIU DEFINIUJACYM STALA. */
    error = 429;
    goto L9901;
L2860:
    if (elem == 0) {
	goto L50;
    }
/*     STALA DEFINIOWANA ? /TAK,JESLI  WB = "LSE" / */
    if (stos_1.wb != 39) {
	goto L2865;
    }
/*     TAK. WSTAW DO SLOWA -2 ADRES OPISU STALEJ */
    stack[stos_1.valtop - 3] = ind;
    goto L50;
/*     STALA W WYRAZENIU DEFINIUJACYM. WSTAW DO SLOWA -2 WARTOSC */
/* 	  / DLA REAL - NUMER STALEJ / */
L2865:
    stack[stos_1.valtop - 3] = blank_1.ipmem[ind - 2];
/*     CZY STALA MA JUZ OKRESLONA WARTOSC ? */
    if (blank_1.ipmem[ind - 4] != 0) {
	goto L2807;
    }
/*      TYP = 0	/SLOWO -3/ OZNACZA,ZE STALA JESZCZE NIE MIALA OKRESLONEJ */
/* 	 WARTOSCI */
    error = 430;
    goto L9901;

/* .....REKORD,KLASA,PROCEDURA,FUNKCJA,SYGNAL,OPERATOR. */
L2870:
    elem = blank_1.ipmem[ind - 4];
    stack[stos_1.valtop - 5] = ind;
    stack[stos_1.valtop - 4] = 0;
    blank_1.idr = stack[stos_1.valtop - 1] - 7;
/*     DLA FUNKCJI ZBADAJ CZY TYP FORMALNY */
    switch (blank_1.idr) {
	case 1:  goto L2872;
	case 2:  goto L2872;
	case 3:  goto L2872;
	case 4:  goto L2875;
	case 5:  goto L2820;
	case 6:  goto L2875;
	case 7:  goto L2890;
    }

/* ... KLASA,REKORD .  NEW ? */
L2872:
    stack[stos_1.valtop - 3] = 0;
/*     - TYP STATYCZNY */
    if (stos_1.wb == 40) {
	goto L2873;
    }
/*     LEWY NAWIAS? */
    if (stos_1.wb != 36) {
	goto L50;
    }
/*     BRAK NEW PRZED LEWYM NAWIASEM */
    serror_(&c__423);
    goto L2874;
/*     NEW */
L2873:
    snext_();
L2874:
    scallb_();
    goto L50;
/* ... PROCEDURA,SYGNAL, C.D. DLA FUNKCJI */
/*     JESLI WB ROZNE OD "," LUB ")"  - WYWOLAJ /INACZEJ-PODEJRZEWAJ PARAMETR/ */
L2875:
    if (stos_1.wb != 10 && stos_1.wb != 54) {
	goto L2874;
    }
    goto L50;
/* ....."NAZWA TYPU"  /PARAMETR FORMALNY "TYPE"/ */
L2880:
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 5] = ind;
/*     PRZEZ KROPKE? */
    if (ats != 0) {
	goto L2885;
    }
/*     PRZEZ DISPLAY */
    stack[stos_1.valtop - 3] = tsinse_(&ind, &blank_1.local);
/*     ZERO ARRAY OF,TYP FORMALNY,ATS TEGO TYPU */
    stack[stos_1.valtop - 7] = blank_1.object;
    goto L50;
/* .....PARAMETR "TYPE" PRZEZ KROPKE */
/*     ODCZYTAJ TYP */
L2885:
    stack[stos_1.valtop - 3] = tstemp_(&c__2);
    i__1 = smember_(&stos_1.valtop);
    quadr4_(&c__85, &stack[stos_1.valtop - 3], &i__1, &ind);
    goto L50;
/* .....OPERATOR, JESLI WB ROZNE OD "(" - BLAD */
L2890:
    error = 454;
/*     = NIELEGALNE WYSTAPIENIE NAZWY OPERATORA */
    if (stos_1.wb != 36) {
	goto L9901;
    }
    goto L50;
/* --------------- IF-FALSE , IF-TRUE  ---------------- */
L2900:
L3000:
    svalue_();
    ind = stos_1.wb - 29;
/*     IND= 1 DLA IF-TRUE , = 0 DLA IF-FALSE */
    snext_();
/*     NA CZUBKU WARTOSC TYPU BOOLEAN? */
    scheck_(&c__407, &blank_1.nrbool);
/*     STALA? */
    if (stack[stos_1.valtop - 1] == 1) {
	goto L3050;
    }
    i__1 = ind + 151;
    quadr3_(&i__1, &stack[stos_1.valtop - 3], &stos_1.wb);
    goto L30;
/*     SKOK PRZY STALEJ WARTOSCI WYRAZENIA */
L3050:
    if (ind + stack[stos_1.valtop - 3] != 0) {
	goto L30;
    }
/* 	ZATEM TRUE, IF TRUE   FALSE, IF FALSE */
    spop_();
    goto L3350;

/* ------ INNER -------- */
/* 	LOKALNE WYSTAPIENIE */
L3100:
    if (stos_1.inner != 0) {
	i__1 = stos_1.inner + 424;
	merr_(&i__1, &c__0);
    }
    stos_1.inner = 2;
    quadr2_(&c__178, &blank_1.ipmem[blank_1.p + 22]);
/* 	ZAZNACZ: INSTRUKCJE PO INNER */
    blank_1.ipmem[blank_1.p - 8] = blank_1.p;
    stos_1.lstemp = stos_1.tempnr;
    goto L40;

/* ------- INSTREND-------- */

L3200:
    snext_();
    stream_2.line = stos_1.wb;
/* JF	IF (LINE.EQ.ATLINE) CALL STOPAT(ATLINE) */
    snext_();
/* 	JESLI BYLY BLEDY CZYSC STOS */
    if (stream_2.errflg) {
	goto L10;
    }
    if (*inicja) {
	goto L50;
    }


/* PRZY ZGASZONEJ OPCJI "OPTIMALIZATION" LUB "SYSPP"  ZAKONCZ BLOK BAZOWY */
    if (option_1.optopt && blank_1.ipmem[blank_1.nblsys + 3] == 0) {
	goto L3250;
    }
    stos_1.lstemp = stos_1.tempnr;
    quadr1_(&c__176);

/*     PRZY WYLACZONEJ OPCJI "TRACE" WYPISZ UJEMNY  NUMER */
L3250:
    elem = stream_2.line;
    if (! option_1.opttrc) {
	elem = -stream_2.line;
    }
    quadr2_(&c__177, &elem);
    goto L50;
/* ---------------  JUMP	----------------------------------- */
L3300:
    snext_();
L3350:
    quadr2_(&c__182, &stos_1.wb);
    stos_1.lstemp = stos_1.tempnr;
    goto L40;
/* ---------------  KILL	---------------------------- */
/*     CZUBEK POWINIEN ZAWIERAC WARTOSC REFERENCYJNA */

L3400:
    skill_();
    goto L30;

/* ---------------  LABEL  ---------------------------- */
L3500:
    snext_();
/*     WYPISZ ETYKIETE */
    quadr2_(&c__181, &stos_1.wb);
    stos_1.lstemp = stos_1.tempnr;
    goto L40;
/* ---------------  LEFT PARANTHESIS  ---------------- */

L3600:
    if (stack[stos_1.valtop - 1] < 8) {
	svalue_();
    }
    goto L40;

/* ---------------	---------------------------- */
L3700:
    goto L40;
/* ---------------  LOWINDEX  ------------------------ */
/*     NA CZUBKU POWINIEN BYC ELEMENT SPROWADZALNY DO WARTOSCI INTEGER */
L3800:
    sindtyp_();
    goto L40;
/* ---------------  LSE  ----------------------------- */
/*     NA CZUBKU POWINNA BYC LEWA STRONA PODSTAWIENIA: UNIWERSALNY, */
/*     ZMIENNA,ELEM. TABLICY,TABLICA STATYCZNA LUB - DLA INICJALIZACJI- */
/*     STALA DEFINIOWANA */

L3900:
    stos_1.lstlse = stos_1.valtop;
    elem = stack[stos_1.valtop - 1] + 1;
    if (elem > 6) {
	goto L3980;
    }
    switch (elem) {
	case 1:  goto L40;
	case 2:  goto L3910;
	case 3:  goto L3980;
	case 4:  goto L40;
	case 5:  goto L40;
	case 6:  goto L40;
    }
/* .....STALA. LEGALNE TYLKO PODCZAS INICJALIZACJI. */
L3910:
    if (*inicja) {
	goto L40;
    }
/* .....BLAD. */
L3980:
    error = 420;
/*     ZASTAP PRZEZ UNIWERSALNY I OBSLUZ OD NOWA */
    goto L9901;

/* ---------------  NEW  ----------------------------- */
/*     NA PEWNO BLAD: KLASA /REKORD/ SAMA "ZJADA" NEW */

L4000:
    error = 421;
    goto L9900;

/* ---------------  NEWARRAY  ------------------------ */

L4100:
    snewarr_();
    goto L30;

/* ---------------  NOT  ----------------------------- */

L4200:
    snot_();
    goto L50;

/* ---------------  OPERATION  ----------------------- */

L4300:
    snext_();
/*     WB=NUMER OPERACJI */
    sarith_();
    goto L40;

/* ---------------  OPTION  -------------------------- */

L4400:
    soption_();
    goto L40;

/* ---------------  OR  ------------------------------ */

L4500:
    sboolex_(&c__0);
    goto L40;

/* ---------------  OTHERWISE  ------------------------- */

L4600:
    sother_();
    goto L40;

/* ---------------  PREFBLOCK  ------------------------- */

L4700:
    snext_();
    spush_(&c__10);
    stack[stos_1.valtop - 2] = 0;
    stack[stos_1.valtop - 8] = 0;
    stack[stos_1.valtop - 5] = blank_1.ipmem[stos_1.wb - 1];
    snext_();
    scallb_();
    goto L50;
/* ---------------  PRIMITIVE TYPE  ------------------ */

L4800:
    snext_();
    spush_(&c__7);
    stack[stos_1.valtop - 2] = 0;
    stack[stos_1.valtop - 3] = 0;
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 5] = stos_1.consnr[stos_1.wb - 1];
    goto L40;

/* ---------------  QUA  ----------------------------- */

L4900:
    svalue_();
    snext_();
    if (stack[stos_1.valtop - 1] == 0) {
	goto L40;
    }
    blank_1.tldim = stack[stos_1.valtop - 4];
    blank_1.tlbas = stack[stos_1.valtop - 5];
    blank_1.idl = stack[stos_1.valtop - 2];
    stack[stos_1.valtop - 5] = maquab_(&stos_1.wb);
    quadr3_(&c__149, &stack[stos_1.valtop - 3], &stack[stos_1.valtop - 5]);
    goto L40;

/* ---------------  I-O-END  ------------------------- */

/*     WYSTAPILY ARGUMENTY ? */
L5000:
    if (stos_1.flargs < 2) {
	merr_(&c__444, &c__0);
    }
    if (stos_1.file != 0) {
	spop_();
    }
    stos_1.file = 0;
    stos_1.flargs = 0;
    stos_1.flready = FALSE_;
    stos_1.flmodf = 1;
    goto L40;

/* ---------------  RELATION  ------------------------ */

L5100:
    snext_();
/*     WB=NUMER RELACJI */
    srelat_();
    goto L40;
/* BC added */
/* ---------------  RESUME  -------------------------- */

L5200:
    sresum_();
    stos_1.lstemp = stos_1.tempnr;
    goto L30;

/* ---------------  RETURN  -------------------------- */

L5300:
    stos_1.lstemp = stos_1.tempnr;
    sreturn_();
/* bc   GO TO 40 */
    goto L50;

/* ---------------  RIGHT PARENTHESIS  ------------- */

L5400:
    if (stack[stos_1.vlprev - 1] < 8) {
	goto L1000;
    }
/*     KONIEC WYWOLANIA */
    sparam_();
    snext_();
    scalle_();
    goto L50;

/* ---------------  START  ------------------------- */

L5500:
    goto L40;

/* ---------------  STEP	--------------------------- */
L5600:
    sindtyp_();
    forstp = TRUE_;
/* dsw&bc */
/*  check if constant step */
    if (stack[stos_1.valtop - 1] != 1) {
	goto L5601;
    }
/*  yes, error if step < 0 */
    if (stack[stos_1.valtop - 3] < 0) {
	serror_(&c__479);
    }
    goto L40;
L5601:
/*  not constant */
/*  generate code to check if step >= 0 */
    quadr2_(&c__240, &stack[stos_1.valtop - 3]);

    goto L40;

/* ---------------  STOP	-------------------------- */

L5700:
/* bc... */
    quadr1_(&c__221);
/* ...bc */
    goto L40;

/* ---------------  THIS	-------------------------- */

L5800:
    snext_();
/*     WB=NAZWA PO 'THIS' */
/*     WEZ Z DISPLAYA ADR.VIRTUALNY,WSTAW NA STOS WARTOSC */
    spush_(&c__2);
    stack[stos_1.valtop - 2] = stos_1.wb;
    stack[stos_1.valtop - 3] = tstemp_(&c__4);
    stack[stos_1.valtop - 5] = mthis_(&stos_1.wb);
    quadr3_(&c__15, &stack[stos_1.valtop - 3], &stack[stos_1.valtop - 5]);
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 6] = 0;
    goto L40;

/* ---------------  TO  ---------------------------- */
L5900:
    sforto_(&c_true, &forstp);
    goto L40;

/* --------------- WAIT  --------------------------- */

L6000:
    goto L40;

/* ---------------  WRITE  --------------------------- */
/* 6100 CALL SWRITE */
/* dsw 6100 CALL SWRITE(*30,*40) */
/*     POWROT DO ETYKIETY 30 LUB 40 */
/* dsw  ----------------------------- */
L6100:
    swrite_(&whdsw);
    switch (whdsw) {
	case 1:  goto L30;
	case 2:  goto L40;
    }
/* dsw  ----------------------------- */

/* ---------------  WRITELN  ------------------------- */
L6200:
    sfladr_();
    stos_1.flargs = 2;
    i__1 = stos_1.flmodf + 58;
    quadr2_(&c__132, &i__1);
    goto L40;

/* ---------------  BOUNDS  ---------------------------- */

L6300:
    goto L40;

/* ---------------  LOWER , UPPER  ---------------------- */

/*     CZUBEK STOSU ZAWIERA ADRES TABLICY */
L6400:
L6500:
    svalue_();
/*     WARTOSC TABLICOWA? */
    error = 416;
    if (stack[stos_1.valtop - 4] == 0) {
	goto L9900;
    }
/*     O.K. */
    stos_1.result = tstemp_(&c__1);
    i__1 = (stos_1.wb << 1) - 95 + option_1.optmem;
    quadr3_(&i__1, &stos_1.result, &stack[stos_1.valtop - 3]);
/*     ZASTAP PRZEZ WARTOSC INTEGER */
    sreslt1_(&blank_1.nrint);
    goto L40;

/* ---------------  LOCK , UNLOCK  --------------------- */

L6600:
L6700:
    blank_1.idl = stos_1.wb - 33;
/*     = NUMER PROCEDURY STANDARDOWEJ LOCK,UNLOCK */
L6710:
    svaradr_();
/*     PRZEKAZ ADRES ZMIENNEJ */
    quadr4_(&c__145, &stos_1.result, &blank_1.idl, &c__0);
/*     WYWOLAJ PROCEDURE */
    quadr2_(&c__132, &blank_1.idl);
/*     ZBADAJ TYP : SEMAPHORE ? */
    blank_1.idr = stack[stos_1.valtop - 5];
    if (stack[stos_1.valtop - 4] > 0 || (blank_1.ipmem[blank_1.idr - 1] & 15) 
	    != 9) {
	serror_(&c__418);
    }
/*     DLA LOCK,UNLOCK TO JUZ WSZYSTKO */
    if (stos_1.wb != 68) {
	goto L30;
    }
/* ... TEST&SET .    ODCZYTAJ WARTOSC */
    stos_1.result = tstemp_(&c__1);
    quadr4_(&c__23, &stos_1.result, &blank_1.idl, &c__1);
/*     ZASTAP PRZEZ WARTOSC */
    sreslt1_(&blank_1.nrbool);
    goto L40;
/* ---------------  TEST&SET  -------------------------- */
L6800:
    blank_1.idl = 38;
    goto L6710;

/* ---------------  WIND , TERMINATE  ------------------ */

/*     NIELEGALNE POZA HANDLEREM */
L6900:
L7000:
    if (stos_1.unit == 2) {
	goto L7050;
    }
    merr_(&c__427, &c__0);
    goto L40;
/*     O.K. */
L7050:
    i__1 = stos_1.wb + 103;
    quadr1_(&i__1);
    goto L40;

/* ---------------  RAISE  ----------------------------- */

/*     NA PEWNO BLAD: SYGNAL SAM "ZJADA" RAISE. */
L7100:
    serror_(&c__449);
    goto L30;

/* ---------------  LAST-WILL  ------------------------- */

/*     ZAKONCZ INSTRUKCJE MODULU */
L7200:
    sfin_();
    stos_1.lstwill = TRUE_;
/*     INNER BEDZIE NIELEGALNY */
    stos_1.inner = 4;
/*     WYPISZ ETYKIETE LAST-WILL */
    slwill_();
    goto L40;

/* ---------------  READ	---------------------------- */
/* dsw 7300 CALL SREAD(*30,*40) */
/* dsw  ------------------------------- */
L7300:
    sread_(&whdsw);
    switch (whdsw) {
	case 1:  goto L30;
	case 2:  goto L40;
    }
/* dsw  -------------------------------- */
/*     POWROT DO ETYKIETY 30 LUB 40 */
/* ---------------  READLN  -------------------------- */
L7400:
    sfladr_();
    stos_1.flargs = 2;
    i__1 = 42 - stos_1.flmodf;
    quadr2_(&c__132, &i__1);
    goto L40;

/* ---------------  PUT  ----------------------------- */
/* 7500 CALL SPUT */
/* dsw 7500 CALL SPUT(*30,*40) */
/*     POWROT DO ETYKIETY 30 LUB 40 */
/* dsw  --------------------------- */
L7500:
    sput_(&whdsw);
    switch (whdsw) {
	case 1:  goto L30;
	case 2:  goto L40;
    }
/* dsw  --------------------------- */

/* ---------------  GET  ----------------------------- */
/* 7600 CALL SGET */
/* dsw 7600 CALL SGET(*30,*40) */
/* dsw  -------------------------- */
L7600:
    sget_(&whdsw);
    switch (whdsw) {
	case 1:  goto L30;
	case 2:  goto L40;
    }
/* dsw  --------------------------- */
/*     POWROT DO ETYKIETY 30 LUB 40 */

/* ---------------  OPEN2  --------------------------- */
L7800:
    svalue_();
    ats = svats_(&stos_1.valtop);
/*     CZUBEK POWINIEN ZAWIERAC NAZWE PLIKU (arrayof char) */
/* bc   CALL SCHECK(414,NRTEXT) */
    if (stack[stos_1.valtop - 4] != 1) {
	goto L7801;
    }
    n = stack[stos_1.valtop - 5];
    if (n != blank_1.nrchr) {
	goto L7801;
    }
/* file CALL QUADR4(145,ATS,73,1) */
/* file  ------------------------- */
    quadr4_(&c__145, &ats, &c__73, &c__2);
/* file  -------------------------- */
    spop_();
/*     DALEJ JAK DLA OPEN1 */

/* ---------------  OPEN1  --------------------------- */
/* file 7700 N=STACK(VALTOP) */
/* file  -----------  added  ------------------------ */
/*  wspolna obsluga */
/*  nowa postac OPEN:  OPEN(f,T,nazwa) - proc.stand. 73 */
/* 		      OPEN(f,T)       - proc.stand. 72 */
/* T okresla rodzaj operacji. Dozwolone: integer, real ,boolean, char, text */
/*  zmiana w interpreterze dla procedur standardowych 72 i 73: */
/*     parametr 0: output, adres nowego obiektu typu file */
/*     parametr 1: rodzaj operdcji () zalezy do T): */
/* 	  1-text, 2-char, 3-int, 4-real, 5-direct */
/*     parametr 2: nazwa ( tylko dla 73) */

/*  stos zawiera na czubku T, ponizej F */

L7700:
/*  nazwa typu pierwotnego? */
    if (stack[stos_1.valtop - 1] != 7) {
	goto L7702;
    }
/*  legalne nazwy typu: text, char ,integer, real */
    n = stack[stos_1.valtop - 5];
/*  n - ident. typu */
    if (n == blank_1.nrtext) {
	goto L7701;
    }
    if (n == blank_1.nrint) {
	goto L7705;
    }
    if (n == blank_1.nrre) {
	goto L7706;
    }
    if (n == blank_1.nrchr) {
	goto L7708;
    }
/* bc */
    if (n == -17) {
	goto L7709;
    }
/*  error - nie nazwa typu lub  nielegalny typ */
L7702:
    serror_(&c__419);
    goto L7715;
/*  nrtext */
L7701:
    n = 1;
    goto L7710;
/*  nrint */
L7705:
    n = 3;
    goto L7710;
/*  nrreal */
L7706:
    n = 4;
    goto L7710;
/*   nrchr */
L7708:
    n = 2;
    goto L7710;
/* bc */
L7709:
    n = 5;
L7710:
    n = sconst_(&n);
    i__1 = stos_1.wb - 5;
    quadr4_(&c__145, &n, &i__1, &c__1);
L7715:
    spop_();

    n = stack[stos_1.valtop - 1];
/* file  ------------------------------------- */
/*     ZMIENNA ? */
    if (n > 2 && n < 6) {
	goto L7720;
    }
    serror_(&c__420);
    goto L30;
/*     TYPU 'FILE' */
L7720:
    sftest_();
    i__1 = stos_1.wb - 5;
    quadr2_(&c__132, &i__1);
    ats = tstemp_(&c__4);
    i__1 = stos_1.wb - 5;
    quadr4_(&c__23, &ats, &i__1, &c__0);
    sstore_(&stos_1.valtop, &ats);
    goto L30;
L7801:
    serror_(&c__416);
    goto L30;

/* ---------------  EOF0	---------------------------- */

/*     = EOF(INPUT) */
L7900:
    seof0_(&c__39);
    goto L40;

/* ---------------  EOF1	---------------------------- */
L8000:
    seof_(&c__40);
    goto L40;
/*     WRACA BEZPOSREDNIO DO ETYKIETY 40 */

/* ---------------  PAR. INPUT  ---------------------- */
/* UNIMPLEMENTED */
L8100:
/*     PARAMETR INPUT WSTAWKI W ASSEMBLERZE */
/* 8100 CALL SNEXT */
/*     WB = NUMER REJESTRU.   C.D. DLA IN-OUT */
/* 8150 CALL SVALUE */
/*     WPISZ NUMER REJESTRU DO SLOWA -1 */
/*     STACK(VALTOP-1)=SREGSTR(WB) */
/*     ICOUNT=ICOUNT+1 */
/*     GO TO 40 */

/* ---------------  PAR. OUTPUT  --------------------- */
/* UNIMPLEMENTED */
L8200:
/*     PARAMETR OUTPUT WSTAWKI W ASSEMBLERZE */
/* 8200 CALL SOUTPAR */
/*     ZDEJMIJ ZE STOSU */
/*     GO TO 30 */

/* ---------------  PAR. INOUT  ---------------------- */
/* UNIMPLEMENTED */
L8300:
/*     PARAMETR IN-OUT WSTAWKI W ASSEMBLERZE */
/*     NAJPIERW OBSLUZ JAK PAR.OUTPUT, POTEM JAK PAR.INPUT */
/* 8300 CALL SOUTPAR */
/*     GO TO 8150 */

/* ---------------  ASSEMBLER  ----------------------- */
/* UNIMPLEMENTED */
L8400:
/*     WSTAWIANY TEKST W ASSEMBLERZE */
/* 8400 CALL SBODY */
/*     GO TO 40 */

/* ---------------  EOLN0  --------------------------- */

L8500:
    seof0_(&c__74);
    goto L40;

/* ---------------  EOLN1  --------------------------- */

L8600:
    seof_(&c__75);
    goto L40;

/* --------  THIS-COROUTINE  ---------------------------- */

L8700:
    n = blank_1.nrcor;
/*     WLOZ NA STOS 'WARTOSC' */
L8720:
    spush_(&c__2);
    ats = tstemp_(&c__4);
    stack[stos_1.valtop - 2] = 0;
    stack[stos_1.valtop - 3] = ats;
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 5] = n;
    stack[stos_1.valtop - 6] = 0;
/*     ODCZYTAJ WARTOSC : FUNKCJA STANDARDOWA 76,77 */
    i__1 = stos_1.wb - 11;
    quadr2_(&c__132, &i__1);
    i__1 = stos_1.wb - 11;
    quadr4_(&c__23, &ats, &i__1, &c__0);
    goto L40;

/* ---------  THIS-PROCESS  ---------------------------- */

L8800:
    n = blank_1.nrproc;
    goto L8720;

/* ---------  putrec ----------------------------------- */

L8900:
    spgrec_(&c__83);
    goto L30;

/* ---------  getrec ----------------------------------- */
L9000:
    spgrec_(&c__82);
    goto L30;

/* bc added concurrent statements */
/* ---------  enable ----------------------------------- */
L9100:
    sconc_(&c__223);
    goto L40;

/* ---------  disable ---------------------------------- */
L9200:
    sconc_(&c__224);
    goto L40;

/* ---------  accept ----------------------------------- */
L9300:
    sconc_(&c__225);
    goto L40;
/* ---------  procedure list end ----------------------- */
/* error - skip and read next symbol */
L9400:
    goto L40;

/* ------------------------------------------------------ */

/* ..........WSPOLNA OBSLUGA BLEDOW. ERROR=NUMER BLEDU. */
/*     ZASTAPIENIE CZUBKA STOSU PRZEZ UNIWERSALNY Z ZACHOWANIEM NAZWY. */
/*     WRACA NA POCZATEK PETLI. */
L9900:
    snext_();
L9901:
    serror_(&error);
    elem = stack[stos_1.valtop - 2];
    spop_();
    spush_(&c__0);
    stack[stos_1.valtop - 2] = elem;
    goto L50;
} /* sdpda_ */

#undef staler
#undef stack
#undef y
#undef m


/* Subroutine */ int sinit_(void)
{
    /* Initialized data */

    static struct {
	integer e_1[8];
	} equiv_2 = { 1, 3, 5, 5, 4, 4, 3, 2 };


    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer n;
#define aux ((integer *)&equiv_2 + 1)
#define aux0 ((integer *)&equiv_2)
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* ------------------------------------------------------ */

/*     POMOCNICZA. INICJALIZACJA SLOWNIKA ATRYBUTOW, */
/*      ZMIENNYCH UNIT,INNER,LSTWILL */
/*     NIE JEST WOLANA W FAZIE WYLICZANIA STALYCH. */

/*     DLA KLAS WSTAWIA DO SLOWA +1 ZERO. */
/*     JESLI MODUL MA PREFIKS,WSTAWIA DO SLOWA +1 PREFIKSU 1. */

/*     ##### OUTPUT CODE : 184 . */


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


/*      = RODZAJ MODULU W ZALEZNOSCI OD POLA "S" ZEROWEGO SLOWA */

/* dsw  DATA STCKAG,STCKA0,STCKAP /0,8,8,8,8,8,10,4,8,8,8,8,8,8,8,8/ */
/* dsw X	    ,APETYT /1,2,3,2/ */


/* .....JAKI TO MODUL ? */
    stos_1.lstwill = FALSE_;
    stos_1.inner = 1;
    n = blank_1.ipmem[blank_1.p - 1];
/*     SPRAWDZ POLE "S" : BITY 5..7 */
    stos_1.unit = lbit_shift(n, (ftnlen)-8) & 7;
    stos_1.unit = aux[stos_1.unit - 1];
/*     MOZE KLASA ? /JESLI POLE "T",BITY 12..15, <> 1 / */
    if ((n & 15) == 1) {
	goto L100;
    }
/*     KLASA */
    stos_1.unit = 6;
    stos_1.inner = 0;
L100:
/* .....ZAZNACZ : JESZCZE NIE UZYWANY JAKO PREFIKS */
    blank_1.ipmem[blank_1.p] = 0;
    if (stos_1.unit < 3) {
	goto L200;
    }
/*     JESLI MA PREFIKS - ZAZNACZ DLA PREFIKSU,ZE UZYWANY */
    blank_1.idl = blank_1.ipmem[blank_1.p + 20];
    if (blank_1.idl != 0) {
	blank_1.ipmem[blank_1.idl] = 1;
    }
/* .....WYPISZ : POCZATEK MODULU */
L200:
    quadr2_(&c__184, &blank_1.p);
    return 0;
} /* sinit_ */

#undef staler
#undef stack
#undef aux0
#undef aux


/* Subroutine */ int snext_(void)
{
    /* Local variables */
    extern /* Subroutine */ int get_(integer *, integer *), seek_(integer *, 
	    integer *);
#define stack ((integer *)&blank_1 + 302)
#define record ((integer *)&blank_1 + 274)
#define staler ((real *)&blank_1 + 302)
#define current ((integer *)&blank_1 + 273)

/* ----------------------------------------------------------------------------- */

/*     DOSTARCZA KOLEJNEGO SYMBOLU KODU POSREDNIEGO WYGENEROWANEGO */
/*     PRZEZ PARSER. SYMBOL TEN WPISUJE NA WB. */

/*     CZYTA ZE STRUMIENIA "INP" , OPISANEGO W BUFORZE IBUF3 ,DO TABLICY IX . */

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




/* 	      = INDEKS W BUFORZE IX OSTATNIO WCZYTANEGO SYMBOLU */
/* 	      = NUMER OSTATNIO WCZYTANEGO REKORDU */
/* .....OSTATNI W REKORDZIE? */
    if (*current == 255) {
	goto L200;
    }
/*     NIE. */
    ++(*current);
L100:
    stos_1.wb = blank_1.ix[*current - 1];


/* 1000 FORMAT(' NEXT, WB =',I6) */


    return 0;
/* .....OSTATNI. WCZYTAJ KOLEJNY REKORD */
L200:
    *record = blank_1.ix[255];
/*     SLOWO 256 ZAWIERA NUMER KOLEJNEGO REKORDU */
    seek_(stream_1.ibuf3, record);
    get_(stream_1.ibuf3, blank_1.ix);
    *current = 1;
    goto L100;
} /* snext_ */

#undef current
#undef staler
#undef record
#undef stack


/* Subroutine */ int sattach_(void)
{
    /* Local variables */
    static integer elem;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), serror_(integer *);

/* ------------------------------------------------------ */

/*     NA CZUBKU JEST ARGUMENT ATTACH. BADA TYP,GENERUJE KOD, */
/*     ZDEJMUJE ZE STOSU. */

/*     ##### OUTPUT CODE : 188 . */

/*     ##### DETECTED ERROR(S) : 477 */

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


/* dsw&ail */

/* ......... */
    svalue_();
    if (stack[stos_1.valtop - 1] == 0) {
	return 0;
    }
    if (stack[stos_1.valtop - 4] > 0) {
	goto L500;
    }
    elem = stack[stos_1.valtop - 5];
    elem = blank_1.ipmem[elem - 1] & 15;
    if (elem > 7 && elem < 13 || elem == 2) {
	goto L500;
    }
    elem = stack[stos_1.valtop - 3];
/*     ATTACH( NONE ) ? */
/* dsw&ail      IF(STACK(VALTOP).EQ.1)ELEM=LMEM-3 */
    if (stack[stos_1.valtop - 1] == 1) {
	elem = stacks_1.btstem - 3;
    }
/* 			    = ATS NONE */
    quadr2_(&c__188, &elem);
    return 0;
/*     NIEPOPRAWNY TYP ARGUMENTU ATTACH */
L500:
    serror_(&c__477);
    return 0;
} /* sattach_ */

#undef staler
#undef stack


/* Subroutine */ int scase_(void)
{
    /* Initialized data */

    static integer maxinteger = 2147483647;
    static integer mininteger = -2147483648;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, n;
#define lab ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int put_(integer *, integer *);
    static integer elem;
    extern /* Subroutine */ int seek_(integer *, integer *), merr_(integer *, 
	    integer *);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int snext_(void), svint_(integer *), quadr4_(
	    integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), serror_(integer *);
    extern integer sconst_(integer *);

/* -------------------------------------------------------------------------- */

/*     OBSLUGUJE POCZATEK INSTRUKCJI "CASE". */
/*     CZUBEK STOSU ZAWIERA WARTOSC WYRAZENIA CASE,NASTEPNY SYMBOL */
/* 	WEJSCIOWY JEST NUMEREM ETYKIETY BAZOWEJ. */
/*     WKLADA NA STOS W TABLICY LAB OPIS NOWEJ INSTRUKCJI CASE, */
/* 	PRZY CZYM : JESLI ZAGNIEZDZENIE = 4 , WYSYLA OPIS POPRZEDNICH */
/* 	 3 CASE-OW NA DYSK JAKO REKORD O NUMERZE IOP(2),USTAWIAJAC OVER=6, */
/* 	JESLI JEDNAK ZAGNIEZDZENIE > 6 , ZWIEKSZA JEDYNIE LICZNIK NADMIAROWYCH */
/* 	  ZAGNIEZDZEN. */

/*     OGRANICZENIA : ZAGNIEZDZENIE MUSI BYC < 7 , */
/* 		     ROZNICA MIEDZY NAJWIEKSZA A NAJMNIEJSZA ETYKIETA < 160 . */

/*     GENERUJE : */
/* 	< CASE , ATS WYRAZENIA , ETYKIETA BAZOWA -1 , OPTCSC+OPTCSF > */


/*     ##### OUTPUT CODE : 189 . */

/*     ##### DETECTED ERROR(S) :  402 , 405 . */


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



/* dsw  DATA OVER/0/ */

/*     LAB ZAWIERA OPISY ZAGNIEZDZONYCH INSTRUKCJI CASE. */
/* 	WYKORZYSTYWANYCH JEST 256 SLOW W TABLICY IPMEM : */
/* 	OD LMEM-515 DO LMEM-260 . */
/*     POSTAC OPISU : */
/* 	SLOWO  0 : TYP WYRAZENIA CASE */
/* 	      +1 : NUMER ETYKIETY BAZOWEJ */
/* 	      +2 : MINIMALNA WARTOSC ETYKIETY */
/* 	      +3 : MAKSYMALNA WARTOSC ETYKIETY */
/* 	      +4 : LICZBA ETYKIET */
/* 	      +5..+84 : 160 BAJTOW NA WZGLEDNY NUMER ETYKIETY */
/*     OPIS BIEZACEJ INSTRUKCJI CASE WSKAZANY JEST PRZEZ ZMIENNA DEEP */
/* 	PRZYJMUJACA WARTOSCI : LMEM-600 PRZY BRAKU "CASE", */
/* 			       LMEM-515 PRZY ZAGNIEZDZENIU = 1 */
/* 			       LMEM-430 PRZY ZAGNIEZDZENIU = 2 */
/* 			       LMEM-345 PRZY ZAGNIEZDZENIU = 3 */
/* 			       LMEM-260 PRZY PRZEPELNIENIU */
/*     PRZY ZAGNIEZDZENIU 4..6 OPIS PIERWSZYCH 3 CASE-OW JEST WYSYLANY */
/* 	NA DYSK JAKO REKORD O NUMERZE IOP(2), OVER PRZYJMUJE WTEDY WARTOSC 6. */
/*     PRZY  ZAGNIEZDZENIACH > 6 UTRZYMYWANA JEST WARTOSC DEEP=LMEM-260 , */
/*      OPISY NOWYCH CASE-OW SA JEDYNIE ZLICZANE NA ZMIENNEJ OVER / 7,8,.../. */
/*     LAB(LMEM-260) = NRUNIV I JEST WYKORZYSTYWANE DLA UNIKNIECIA SYGNALIZACJI */
/*      NIEZGODNOSCI TYPOW ETYKIET PRZY ZBYT ZAGNIEZDZONYCH CASE-ACH. */
/*     DLA ETYKIETY O WARTOSCI N DO BAJTU O NUMERZE /NUMERACJA 0..159/ */
/*     ( N MODE 160 ) WSTAWIANA JEST ROZNICA MIEDZY ODPOWIADAJACYM */
/*      JEJ NUMEREM ETYKIETY Z PARSERA A ETYKIETA BAZOWA. */



    svalue_();
    snext_();
/*     TERAZ WB = NUMER ETYKIETY BAZOWEJ */
    if (stack[stos_1.valtop - 1] == 0) {
	goto L150;
    }
/* ... ZBADAJ TYP */
    if (stack[stos_1.valtop - 4] > 0) {
	goto L100;
    }
    if (stack[stos_1.valtop - 5] == blank_1.nrre) {
	svint_(&stos_1.valtop);
    }
    elem = stack[stos_1.valtop - 5];
/*      = TYP WYRAZENIA CASE /PO EWENT. KONWERSJI REAL->INTEGER / */
    if (elem == blank_1.nrint || elem == blank_1.nrchr) {
	goto L200;
    }
/*     NIELEGALNY TYP WYRAZENIA CASE */
L100:
    serror_(&c__405);
L150:
    elem = blank_1.nruniv;
/* .....DODAJ NOWY OPIS DO STOSU INSTRUKCJI CASE */
L200:
    case_1.deep += 85;
    if (case_1.deep < blank_1.lmem - 260) {
	goto L500;
    }
/*     PELNY STOS. BUFOR NA DYSKU JUZ UZYTY ? */
    if (case_1.over > 0) {
	goto L1000;
    }
/*     JESZCZE NIE. */
    case_1.over = 6;
    case_1.deep = blank_1.lmem - 515;
    seek_(stream_1.ibuf3, &blank_1.iop[1]);
    put_(stream_1.ibuf3, &lab[case_1.deep - 1]);

/* .....WSTAW OPIS */
L500:
    lab[case_1.deep - 1] = elem;
    lab[case_1.deep] = stos_1.wb;
    lab[case_1.deep + 1] = maxinteger;
    lab[case_1.deep + 2] = mininteger;
    lab[case_1.deep + 3] = 0;
/*     JAKO MINIMALNA I MAKSYMALNA ETYKIETA POCZATKOWO NAJWIEKSZA I NAJMNIEJSZA */
/* 	LICZBA ---> POTEM KONIECZNE JEST POROWNANIE KAZDEJ ETYKIETY ZAROWNO */
/* 	Z MINIMALNA JAK I MAKSYMALNA. */
    for (i__ = 5; i__ <= 84; ++i__) {
	n = case_1.deep + i__;
/* L600: */
	lab[n - 1] = 0;
    }
/*     BAJT ROWNY ZERO OZNACZA, ZE NIE WYSTAPILA ETYKIETA O WARTOSCI */
/* 	WYZNACZAJACEJ TEN BAJT. */

/* ... JESLI STALA - WSTAW */
    elem = stack[stos_1.valtop - 3];
    if (stack[stos_1.valtop - 1] == 1) {
	elem = sconst_(&elem);
    }
/* ... GENERUJ SKOK DO MIEJSCA WYBRANIA WLASCIWEJ INSTRUKCJI */
    i__1 = stos_1.wb - 1;
    i__2 = option_1.optcsc + option_1.optcsf;
    quadr4_(&c__189, &elem, &i__1, &i__2);
    return 0;
/* .....PRZEPELNIENIE : ZAGNIEZDZENIE PRZEKRACZA 6 . */
/*     NIE SYGNALIZUJ BLEDU DLA DALSZYCH ZAGNIEZDZEN */
L1000:
    if (case_1.over == 6) {
	merr_(&c__402, &c__0);
    }
    ++case_1.over;
    case_1.deep = blank_1.lmem - 260;
    lab[case_1.deep - 1] = blank_1.nruniv;
    return 0;
} /* scase_ */

#undef staler
#undef stack
#undef lab


/* Subroutine */ int scslab_(void)
{
    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer l, m, n;
#define lab ((integer *)&blank_1 + 302)
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int snext_(void);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int serror_(integer *);

/* ------------------------------------------------------------------------- */

/*     OBSLUGUJE ETYKIETE DLA INSTRUKCJI CASE. */
/*     CZUBEK STOSU POWINIEN ZAWIERAC WARTOSC ETYKIETY,NASTEPNY SYMBOL */
/* 	TO NUMER ETYKIETY WYGENEROWANEJ PRZEZ PARSER. */
/*     PROCEDURA SPRAWDZA,CZY CZUBEK STOSU ZAWIERA STALA TYPU ZGODNEGO */
/* 	Z TYPEM WYRAZENIA CASE I CZY WARTOSC TA JUZ NIE WYSTAPILA */
/*      LUB CZY ROZNICA MIEDZY MAKS. I MIN. ETYKIETA < 160. */
/*     WYZNACZA NOWA WARTOSC ETYKIETY MAKS. I MIN. ORAZ DO BAJTU */
/* 	WYZNACZONEGO PRZEZ WARTOSC ETYKIETY WSTAWIA ROZNICE MIEDZY */
/* 	NUMEREM ODPOWIADAJACEJ ETYKIETY A ETYKIETA BAZOWA. */
/*     ZWIEKSZA LICZNIK ETYKIET. */
/* 	W PRZYPADKU, GDY ROZPIETOSC ETYKIET PRZEKRACZA 160,ZMIENIA */
/* 	 ETYKIETE BAZOWA NA -1 /DLA UNIKNIECIA DALSZEJ SYGNALIZACJI */
/* 	 TEGO BLEDU/. */


/*     ##### DETECTED ERROR(S) :  401 , 403 , 404 , 406 . */


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




/*     TRICK FOR HAVING 2 RIGHTMOST BYTES ADDRESSABLE */
/* dsw  INTEGER BYTES */
/* dsw  BYTE  BYTE(4) */
/* dsw  EQUIVALENCE ( BYTES , BYTE(1) ) */



    snext_();
/*     WB = NUMER ETYKIETY Z PARSERA. SPRAWDZ, CZY NA STOSIE JEST STALA */
    n = stack[stos_1.valtop - 1];
    if (n == 0) {
	return 0;
    }
    if (n == 1) {
	goto L100;
    }
/* ... JAKO ETYKIETA W "CASE"  WYSTAPIL OBIEKT ROZNY OD STALEJ */
    serror_(&c__401);
    return 0;

/* .....ZBADAJ ZGODNOSC TYPOW /JESLI NIE BYLO PRZEPELNIENIA/ */
L100:
    if (stack[stos_1.valtop - 5] == lab[case_1.deep - 1]) {
	goto L200;
    }
/*     NIEZGODNOSC TYPOW ETYKIETY I WYRAZENIA "CASE" */
    if (lab[case_1.deep - 1] != blank_1.nruniv) {
	serror_(&c__406);
    }
    return 0;

/* .....USTAL NOWE WARTOSCI ETYKIET : MINIMALNA I MAKSYMALNA. */
/*      /UWAGA: ZE WZGLEDU NA INICJALIZACJE KONIECZNE OBA POROWNANIA/ */
L200:
    n = stack[stos_1.valtop - 3];
    if (n < lab[case_1.deep + 1]) {
	lab[case_1.deep + 1] = n;
    }
    if (n > lab[case_1.deep + 2]) {
	lab[case_1.deep + 2] = n;
    }
    if (lab[case_1.deep + 2] - lab[case_1.deep + 1] < 160) {
	goto L300;
    }
/*     ROZPIETOSC WARTOSCI ETYKIET PRZEKRACZA 160 */
    if (lab[case_1.deep] == -1) {
	return 0;
    }
    serror_(&c__403);
    lab[case_1.deep] = -1;
    return 0;
/* .....WYZNACZ NUMER BAJTU */
L300:
    n %= 160;
    if (n < 0) {
	n += 160;
    }
    l = n / 2 + case_1.deep + 5;
/*      = NUMER SLOWA W LAB */
    m = lab[l - 1];
/*      = WARTOSC TEGO SLOWA */
    stos_1.wb -= lab[case_1.deep];
/*     ZWIEKSZ LICZNIK ETYKIET */
    ++lab[case_1.deep + 3];
/*     PARZYSTY BAJT ? */
    if ((n & 1) == 0) {
	goto L500;
    }
/* ... NIEPARZYSTY, PRAWY BAJT. ETYKIETA JUZ WYSTAPILA ? */
    if ((m & 255) == 0) {
	goto L400;
    }
/* ... POWTORNE WYSTAPIENIE TEJ SAMEJ ETYKIETY */
L350:
    serror_(&c__404);
    return 0;
/*     WSTAW ROZNICE : NUMER ETYKIETY - ETYKIETA BAZOWA */
L400:
    lab[l - 1] = m | stos_1.wb;
    return 0;
/* ... PARZYSTY, LEWY BAJT */
L500:
    if ((lbit_shift(m, (ftnlen)-8) & 255) != 0) {
	goto L350;
    }
    lab[l - 1] = stos_1.wb << 8 | m;
    return 0;
} /* scslab_ */

#undef staler
#undef stack
#undef lab


/* Subroutine */ int sother_(void)
{
    /* Local variables */
#define lab ((integer *)&blank_1 + 302)
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int scsout_(void);

/* -------------------------------------------------------------------------- */

/*     WOLANA PO WYSTAPIENIU "OTHERWISE" W INSTRUKCJI "CASE" . */
/*     WYPISUJE ETYKIETY /POPRZEZ SCSOUT/ I ZAZNACZA TO POPRZEZ ZMIANE */
/* 	SLOWA 0 OPISU CASE NA NRUNIV. */

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




    if (lab[case_1.deep - 1] == blank_1.nruniv) {
	return 0;
    }
/*     WYPISZ ETYKIETY I ZAZNACZ TO */
    scsout_();
    lab[case_1.deep - 1] = blank_1.nruniv;
    return 0;
} /* sother_ */

#undef staler
#undef stack
#undef lab


/* Subroutine */ int scsout_(void)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer l, n, nr;
#define lab ((integer *)&blank_1 + 302)
    static integer diff, byte;
#define stack ((integer *)&blank_1 + 302)
    static integer bound, bytes;
    extern /* Subroutine */ int quadr1_(integer *), quadr2_(integer *, 
	    integer *), quadr4_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* ---------------------------------------------------------------------------- */


/*     WOLANA : PRZED "OTHERWISE" /JESLI WYSTAPILO/ LUB PRZY "ESAC" . */

/*     WYPISUJE ETYKIETY DLA "CASE". */
/*     POSTAC : "ESAC" / =190 / */
/* 		LICZBA ETYKIET */
/* 		NUMER ETYKIETY BAZOWEJ */
/* 		WARTOSC ETYKIETY MINIMALNEJ */
/* 		DLA KAZDEJ ETYKIETY SLOWO ZAWIERAJACE : */
/* 		 LEWY BAJT = ETYKIETA - ET.MINIMALNA */
/* 		 PRAWY BAJT = ODLEGLOSC OD ETYKIETY BAZOWEJ */
/* 		 - W KOLEJNOSCI OD ETYKIETY MINIMALNEJ DO MAKSYMALNEJ. */

/*     NA KONCU DOPISUJE ETYKIETE DLA "OTHERWISE" /BAZOWA/ ,NIEZALEZNIE */
/* 	OD TEGO,CZY "OTHERWISE" WYSTAPILO. */


/*     ##### OUTPUT CODE : 181 , 190 . */

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




/*     TRICK FOR HAVING 2 RIGHTMOST BYTES ADDRESSABLE */
/* dsw  INTEGER BYTES,OBYTES */
/* dsw  BYTE  BYTE(4),OBYTE(4) */
/* dsw  EQUIVALENCE ( BYTES , BYTE(1) ) , ( OBYTES , OBYTE(1) ) */



    if (stream_1.errflg) {
	return 0;
    }
    n = lab[case_1.deep + 1];
/*      = ETYKIETA MINIMALNA */
    nr = lab[case_1.deep + 3];
/*      = LICZBA ETYKIET */
/*     WYPISZ "ESAC",LICZBA ETYKIET,ETYKIETA BAZOWA I MINIMALNA */
    quadr4_(&c__190, &nr, &lab[case_1.deep], &n);

/* .....WYPISZ DLA KAZDEJ ETYKIETY 2 BAJTY : */
/*      LEWY = ET. - ET.MIN. , PRAWY = NUMER - ETYKIETA BAZOWA */

/*     DALEJ : */
/*     DALEJ : */
/* 	 DIFF = BIEZACA ETYKIETA - ET.MINIMALNA */
/* 	 L = NUMER SLOWA DLA KOLEJNEJ ETYKIETY */
/* 	 K = WARTOSC SLOWA */
/* 	 NR = LICZBA ETYKIET DO WYPISANIA */
/* 	 BOUND = NUMER PIERWSZEGO SLOWA ZA OPISEM "CASE" */

    bound = case_1.deep + 85;
    n %= 160;
    if (n < 0) {
	n += 160;
    }
/*     = NUMER BAJTU DLA ETYKIETY MINIMALNEJ , 0..159 */
    diff = -1;
    l = case_1.deep + 5 + n / 2;
/*      = NUMER SLOWA */
/* dsw  OBYTES=0 */
    bytes = lab[l - 1];
/*     PARZYSTA ? */
    if ((n & 1) != 0) {
	goto L300;
    }
/* ... PARZYSTY,LEWY BAJT */
L200:
    ++diff;
/*     WEZ LEWY BAJT */
    byte = lbit_shift(bytes, (ftnlen)-8) & 255;
    if (byte == 0) {
	goto L300;
    }
/*     WYPISZ PARE DLA TEJ ETYKIETY */
    i__1 = byte | diff << 8;
    quadr1_(&i__1);
    --nr;
    if (nr == 0) {
	goto L1000;
    }
/* ... NIEPARZYSTY,PRAWY BAJT */
L300:
    ++diff;
/*     WEZ PRAWY BAJT */
    byte = bytes & 255;
    if (byte == 0) {
	goto L400;
    }
/*     WYPISZ PARE DLA TEJ ETYKIETY */
    i__1 = diff << 8 | byte;
    quadr1_(&i__1);
    --nr;
    if (nr == 0) {
	goto L1000;
    }
/* ... ZWIEKSZ NUMER SLOWA/ ZWAZAJAC NA GRANICE / I WCZYTAJ TO SLOWO */
L400:
    ++l;
    if (l == bound) {
	l += -80;
    }
    bytes = lab[l - 1];
    goto L200;
/* .....WYPISZ ETYKIETE DLA "OTHERWISE" */
L1000:
    quadr2_(&c__181, &lab[case_1.deep]);
    return 0;
} /* scsout_ */

#undef staler
#undef stack
#undef lab


/* Subroutine */ int sesac_(void)
{
    /* Local variables */
#define lab ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int get_(integer *, integer *), seek_(integer *, 
	    integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int scsout_(void);

/* ---------------------------------------------------------------------------- */

/*     OBSLUGUJE ZAKONCZENIE INSTRUKCJI "CASE". */
/*     OBNIZA STOS INSTRUKCJI CASE. */
/*     JESLI NIE WYSTAPILO "OTHERWISE" I NIE BYLO PRZEPELNIENIA */
/*     WYPISUJE ETYKIETY /PRZEZ SCSOUT/ */

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




/* .....WYPISZ ETYKIETY / O ILE NIE WYSTAPILO "OTHERWISE" LUB PRZEPELNIENIE/ */
    if (lab[case_1.deep - 1] != blank_1.nruniv) {
	scsout_();
    }
    if (case_1.over > 6) {
	goto L500;
    }
    case_1.deep += -85;
    if (case_1.deep > blank_1.lmem - 600) {
	return 0;
    }
/*     POBRAC OPIS Z DYSKU ? */
    if (case_1.over == 0) {
	return 0;
    }
    seek_(stream_1.ibuf3, &blank_1.iop[1]);
    get_(stream_1.ibuf3, &lab[blank_1.lmem - 516]);
    case_1.over = 0;
    case_1.deep = blank_1.lmem - 345;
    return 0;
/* .....PRZEPELNIENIE. */
L500:
    --case_1.over;
    return 0;
} /* sesac_ */

#undef staler
#undef stack
#undef lab


/* Subroutine */ int send_(void)
{
    /* Local variables */
    static integer n;
    extern /* Subroutine */ int sfin_(void);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr1_(integer *), quadr2_(integer *, 
	    integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int slwill_(void);

/* ------------------------------------------------------------------------- */

/*     WOLANA PRZY END MODULU. */
/*     JESLI TRZEBA, DOPISUJE LAST-WILL. */
/*     WYPISUJE ZAKONCZENIE LAST-WILL. */

/*     ##### OUTPUT CODE : 175 , 185 , 193 . */


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


/* .....BYLO LAST-WILL ? */
    if (stos_1.lstwill) {
	goto L1000;
    }
/*     NIE. ZAKONCZ INSTRUKCJE MODULU */
    sfin_();
/* 	       I DOPISZ LAST-WILL */
    slwill_();

/* .....WYPISZ ZAKONCZENIE LAST-WILL: SKOK ZA LAST-WILL PREFIKSU */
/* 				     LUB BACK */
L1000:
    if (stos_1.unit <= 2) {
	goto L2000;
    }
    blank_1.idl = blank_1.ipmem[blank_1.p + 20];
/*     JESLI NIE MA PREFIKSU - BACK */
    if (blank_1.idl == 0) {
	goto L2000;
    }
/*     PREFIKSOWANY. CZY W CIAGU PREFIKSOWYM BYLO LAST-WILL ? */
/* 	   /TAK, GDY SLOWO +8 PREFIKSU	<> 0  / */
    blank_1.idl = blank_1.ipmem[blank_1.idl + 7];
    if (blank_1.idl == 0) {
	goto L2000;
    }
/*     SKOK ZA LAST-WILL W SEKWENCJI PREFIKSOWEJ */
    quadr2_(&c__175, &blank_1.idl);
    goto L3000;
/* .....BACK */
/* dsw 2000 CALL QUADR1(193) */
/* dsw  --------------------------------------- */
/*   jesli coroutina/process to FIN (194) */
L2000:
    n = blank_1.ipmem[blank_1.p - 1] & 15;
/*  pole = t */
    if (n == 5 || n == 7) {
	goto L2100;
    }
    quadr1_(&c__193);
    goto L3000;
/*  coroutina/ process */
L2100:
    quadr1_(&c__194);
/* dsw  ---------------------------------------- */

/* .....WYPISZ ZNACZNIK KONCA MODULU */
L3000:
    quadr1_(&c__185);
    return 0;
} /* send_ */

#undef staler
#undef stack


/* Subroutine */ int sfin_(void)
{
    /* Initialized data */

    static integer aux[6] = { 191,172,194,192,192,194 };

    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int snext_(void), quadr1_(integer *), quadr2_(
	    integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* ------------------------------------------------------------------- */

/*     OBSLUGUJE KONIEC INSTRUKCJI MODULU / LAST-WILL LUB END, */
/* 				 JESLI LAST-WILL NIE WYSTAPILO/ */
/*     KOLEJNE DWA SYMBOLE TO : NUMER ETYKIETY, NUMER LINII. */

/*     JESLI TRZEBA,DOPISUJE INNER. */
/*     DOPISUJE ETYKIETE ORAZ NUMER LINII PRZED END. */
/*     DLA MODULOW PREFIKSOWANYCH GENERUJE SKOK ZA INNER,DLA POZOSTALYCH */
/*     END BLOKU /BACKBL/ LUB END PROCEDURY,FUNKCJI /BACKPR/ LUB */
/*     END KLASY,COROUTINY /FIN/ LUB END HANDLERA /TERMINATE/. */

/*     ##### OUTPUT CODE : 172 , 177 , 178 , 181 , 183 , */
/* 			     191 , 192 , 194 . */

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


/*     POWROTY Z MODULU: BACKBL,TERMINATE,FIN,BACKPR,BACKPR,FIN . */

/* .....DOPISAC INNER? */
    if (stos_1.inner != 0) {
	goto L10;
    }
    quadr2_(&c__178, &blank_1.ipmem[blank_1.p + 22]);
/*     ZAZNACZ BRAK INSTRUKCJI PO INNER /CHYBA,ZE Z PREFIKSU/ */
    blank_1.ipmem[blank_1.p - 8] = 0;
    blank_1.idl = blank_1.ipmem[blank_1.p + 20];
/*     IDL=PREFIKS LUB 0 */
    if (blank_1.idl != 0) {
	blank_1.ipmem[blank_1.p - 8] = blank_1.ipmem[blank_1.idl - 8];
    }
/* .....DOPISZ ETYKIETE O NUMERZE WB */
L10:
    snext_();
    quadr2_(&c__181, &stos_1.wb);
/* ... DOPISZ NUMER LINII */
    snext_();
    if (! option_1.opttrc) {
	stos_1.wb = -stos_1.wb;
    }
    quadr2_(&c__177, &stos_1.wb);
    if (stos_1.unit > 2) {
	goto L200;
    }
/* ... BLOK LUB HANDLER */
L100:
    quadr1_(&aux[stos_1.unit - 1]);
    return 0;
/* ... PREFIKSOWANY ? */
L200:
    blank_1.idl = blank_1.ipmem[blank_1.p + 20];
    if (blank_1.idl == 0) {
	goto L100;
    }
/*     TAK. CZY SA INSTRUKCJE PO INNER ? */
    blank_1.idl = blank_1.ipmem[blank_1.idl - 8];
    if (blank_1.idl == 0) {
	goto L100;
    }
/* ... SKOK ZA INNER PREFIKSU */
    quadr2_(&c__183, &blank_1.idl);
    return 0;
} /* sfin_ */

#undef staler
#undef stack


/* Subroutine */ int slwill_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr1_(integer *);
#define staler ((real *)&blank_1 + 302)

/* ---------------------------------------------------------------------- */

/*     WYPISUJE ETYKKIETE LAST-WILL. */
/*     DLA KLASY WPISUJE DO SLOWA +8 INFORMACJE O LAST-WILL: */
/* 	 NUMER NAJBLIZSZEGO MODULU W CIAGU PREFIKSOWYM /Z BIEZACYM */
/* 	  MODULEM WLACZNIE/ MAJACEGO LAST-WILL LUB ZERO,JESLI */
/* 	 W CALYM CIAGU PREFIKSOWYM LAST-WILL NIE WYSTAPILO. */

/*     ##### OUTPUT CODE : 174 . */

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


/* .....WYPISZ ETYKIETE LAST-WILL */
    quadr1_(&c__174);
    if (stos_1.unit != 6) {
	return 0;
    }
/* ... KLASA */
    blank_1.idr = 0;
/*     JESLI JEST PREFIKS - SKOPIUJ Z PREFIKSU */
    blank_1.idl = blank_1.ipmem[blank_1.p + 20];
    if (blank_1.idl != 0) {
	blank_1.idr = blank_1.ipmem[blank_1.idl + 7];
    }
/*     JESLI W TYM MODULE WYSTAPILO LAST-WILL, TO WPISZ NUMER BIEZACEGO */
/* 	MODULU */
    if (stos_1.lstwill) {
	blank_1.idr = blank_1.p;
    }
    blank_1.ipmem[blank_1.p + 7] = blank_1.idr;
    return 0;
} /* slwill_ */

#undef staler
#undef stack


/* Subroutine */ int sreturn_(void)
{
    /* Initialized data */

    static integer aux[6] = { 191,180,193,192,192,193 };

    /* Local variables */
    static integer op, ind, elem;
#define stack ((integer *)&blank_1 + 302)
    extern integer swhat_(integer *);
    extern /* Subroutine */ int snext_(void), quadr1_(integer *);
    extern integer mident_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int serror_(integer *);

/* ----------------------------------------------------------------- */

/*     DLA WYSTAPIENIA "RETURN" GENERUJE : */
/* 	      DLA PROCEDUR,FUNKCJI BEZ PREFIKSU BACKPR, DLA PREFIKSOWANYCH */
/*     LUB KLAS,COROUTIN BACK, DLA BLOKOW BACKBL, DLA HANDLERA BACKHD. */


/*     ##### OUTPUT CODE : 180 , 191 , 192 , 193 . */

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


/*     POWROTY Z MODULU : BACKBL,BACKHD,BACK,BACKPR,BACKPR,BACK */


    blank_1.idl = aux[(0 + (0 + (stos_1.unit - 1 << 2))) / 4];
/* bc added concurrent statements */
    snext_();
/* check if procedure or function */
    if (stos_1.unit != 4 && stos_1.unit != 5) {
	goto L100;
    }
/* generate BACKRPC */
    quadr1_(&c__227);
L10:
    op = stos_1.wb;
    if (op != 91 && op != 92) {
	goto L40;
    }
/* process next ENABLE/DISABLE list */
L20:
    snext_();
    if (stos_1.wb != 28) {
	goto L10;
    }
/* process next identifier */
    snext_();
    ind = mident_(&stos_1.wb);
    elem = swhat_(&ind);
/* check if procedure or function */
    if (elem != 11 && elem != 12) {
	goto L30;
    }
    if (op == 92) {
	ind = -ind;
    }
    quadr1_(&ind);
    goto L20;
L30:
    serror_(&c__478);
    goto L20;
L40:
    quadr1_(&c__0);
    snext_();
    return 0;

/* bc   JESLI MODUL PREFIKSOWANY TO BACK */
/* bc   IF(UNIT.GT.2 .AND. IPMEM(P+21).NE.0)IDL=193 */
L100:
    quadr1_(&blank_1.idl);
    return 0;
} /* sreturn_ */

#undef staler
#undef stack


/* Subroutine */ int sforto_(logical *up, logical *step)
{
    /* Initialized data */

    static integer sfthx2 = 16384;
    static integer sfthx3 = 8192;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer k, l, n;
    static logical end1;
    static integer end2;
    extern /* Subroutine */ int spop_(void);
    static integer step1, step2;
#define stack ((integer *)&blank_1 + 302)
    extern integer svats_(integer *);
    extern /* Subroutine */ int snext_(void), spush_(integer *), quadr2_(
	    integer *, integer *), quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *);
    static integer sfthx1;
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);
    extern /* Subroutine */ int sindtyp_(void);

/* ----------------------------------------------------------------------------- */

/*     OBSLUGUJE POCZATEK PETLI FOR. */
/*     WOLANA PO WYSTAPIENIU SYMBOLU "TO" LUB "DOWNTO". */
/*     UP = TRUE ,JESLI BYLO "TO" */
/*     STEP = TRUE ,JESLI WYSTAPILO "STEP" */
/*     STOS ZAWIERA: ZMIENNA STERUJACA,WARTOSC POCZATKOWA,KROK/JESLI BYL/, */
/*     WARTOSC KONCOWA. */
/*     NASTEPNE 2 SYMBOLE WEJSCIOWE TO NUMERY ETYKIET POCZATKU PETLI I ZA PETLA */
/*     WCZYTUJE OBA NUMERY,ZASTEPUJE 4 LUB 3 GORNE ELEMENTY STOSU PRZEZ */
/*     OPIS PETLI FOR. */
/* 	JESLI KROK LUB WARTOSC KONCOWA NIE SA STALE, PRZYDZIELA IM ATRYBUTY */
/*     ROBOCZE ZYWE PO WYJSCIU Z BLOKU BAZOWEGO ORAZ GENERUJE MOVE&SAFE */
/*      DLA NICH. */

/*     GENERUJE KOD : */
/* 	  WSTAWIENIE WARTOSCI POCZATKOWEJ DO R5 , */
/* 	   ETYKIETA POCZATKU PETLI , */
/* 	    PODSTAWIENIE WARTOSCI Z R5 NA ZMIENNA STERUJACA , */
/* 	     RELACJA I SKOK WARUNKOWY /WYJSCIE Z PETLI/ */



/*     ##### OUTPUT CODE : 13 , 60 , 90 , 92 , 108 , 110 , */
/* 			     139 , 152 , 181 , 208 . */


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

/* dsw  DATA SFTHEX1,SFTHEX2,SFTHEX3 /Z8000,Z4000,Z2000 / */

/* 	TRUE,JESLI: BYLO "TO", BYLO "STEP" , WARTOSC KONCOWA ROZNA OD STALEJ */
/* 	ATS LUB WARTOSC STALEJ DLA WARTOSCI KONCOWEJ,RODZAJ KROKU */
/* 	 /1 JESLI STALY/, ATS LUB WARTOSC KROKU. */

/* dsw  ------------------------------------------------ */
    sfthx1 = 32768;
/* dsw  ------------------------------------------------ */

/* .....WARTOSC KONCOWA */
    sindtyp_();
    end1 = stack[stos_1.valtop - 1] != 1;
    end2 = stack[stos_1.valtop - 3];
    spop_();
/*     JESLI TRZEBA - ZABEZPIECZ WARTOSC KONCOWA */
    if (! end1) {
	goto L100;
    }
/*     ZABEZPIECZ */
    i__1 = stos_1.tempnr + 6;
    quadr3_(&c__208, &i__1, &end2);
    end2 = stos_1.tempnr + 6;

/* .....BYLO "STEP" ? */
L100:
    if (*step) {
	goto L200;
    }
/*     NIE.  WSTAW KROK=1 */
    step1 = 1;
    step2 = 1;
    goto L300;
/*     TAK. */
L200:
    step1 = stack[stos_1.valtop - 1];
    step2 = stack[stos_1.valtop - 3];
    spop_();
/*     STALY KROK? JESLI NIE - ZABEZPIECZ */
    if (step1 == 1) {
	goto L300;
    }
    i__1 = stos_1.tempnr + 3;
    quadr3_(&c__208, &i__1, &step2);
    step2 = stos_1.tempnr + 3;

/* .....WARTOSC POCZATKOWA. WPISZ DO "R5" */
L300:
    n = svats_(&stos_1.valtop);
    k = stack[stos_1.vlprev - 3];
/*     K = ATS ZMIENNEJ	STERUJACEJ */
    spop_();
/*     ZDEJMIJ TEZ ZMIENNA STERUJACA */
    spop_();
    stos_1.lstlse = 0;
/*     WPISZ WARTOSC POCZATKOWA DO R5 ( REJESTR = 4 ) */
    quadr3_(&c__139, &n, &c__4);


/* .....WSTAW OPIS PETLI NA STOS */

/*     POSTAC OPISU : SLOWO -1 = ATS ZMIENNEJ STERUJACEJ */
/* 		     SLOWO -2 = WARTOSC LUB ATS KROKU */
/* 		     SLOWO -3 : BIT 0 = 0 --> "TO",= 1 --> "DOWNTO" */
/* 				BIT 1 = 0 --> STALY KROK,= 1 --> WYLICZONY */
/* 				BIT 2 = 0 --> STALA WARTOSC KONCOWA, */
/* 						  = 1 --> WYLICZONA */

    spush_(&c__6);
    stos_1.lstfor = stos_1.valtop;
    stack[stos_1.valtop - 2] = k;
    stack[stos_1.valtop - 3] = step2;
    n = 0;
/*      = "TO" , STALY KROK , STALA WARTOSC KONCOWA */
    if (! (*up)) {
	n |= sfthx1;
    }
    if (step1 != 1) {
	n |= sfthx2;
    }
    if (end1) {
	n |= sfthx3;
    }
    stack[stos_1.valtop - 4] = n;


/* .....POCZATEK PETLI. */
    snext_();
/*     WB=NUMER ETYKIETY POCZATKU. GENERUJ ETYKIETE. */
    quadr2_(&c__181, &stos_1.wb);
    snext_();
/*     WB=NUMER ETYKIETY ZA PETLA */

/* ... PODSTAW WARTOSC Z R5 NA ZMIENNA STERUJACA */
    l = tstemp_(&c__1);
/*     4  -->  R5 */
    quadr3_(&c__13, &l, &c__4);
    quadr3_(&c__60, &k, &l);

/* ... GENERUJ POROWNANIE */
    step1 = tstemp_(&c__1);
    n = 110;
/*     ="GT INTEGER" */
/*     STALA WARTOSC KONCOWA? */
    if (end1) {
	goto L500;
    }
/*     TAK */
    n = 92;
/*     = "GT CONST" */

/* .....POROWNANIE I WYSKOK ZA PETLE */
L500:
    if (! (*up)) {
	n += -2;
    }
/*     OPKOD "LT" = OPKOD "GT" -2 . */
    quadr4_(&n, &step1, &k, &end2);
    quadr3_(&c__152, &step1, &stos_1.wb);
    return 0;
} /* sforto_ */

#undef staler
#undef stack


/* Subroutine */ int sforend_(void)
{
    /* Initialized data */

    static integer sfehx2 = 16384;
    static integer sfehx3 = 8192;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer k, n, ats, step;
#define stack ((integer *)&blank_1 + 302)
    static integer opkod, sfehx1;
    extern /* Subroutine */ int quadr4_(integer *, integer *, integer *, 
	    integer *), quadr3_(integer *, integer *, integer *), quadr2_(
	    integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* ---------------------------------------------------------------------------- */

/*     OBSLUGUJE ZAKONCZENIE PETLI FOR */
/*     ZWIEKSZA ZMIENNA STERUJACA O KROK /ZMNIEJSZA DLA "DOWNTO"/ */
/*     I WKLADA DO "R5". */
/*     ZMNIEJSZA LSTFOR,TEMPNR. */
/*     JESLI KROK LUB WARTOSC KONCOWA NIE BYLY STALE, ZWALNIA */
/* 	ZAJMOWANE PRZEZ NIE ZMIENNE ROBOCZE /GENERUJE "RELEASE"/ */

/*     GENERUJE KOD : */
/* 	       WSTAWIENIE DO R5 WARTOSCI ZMIENNEJ STERUJACEJ POWIEKSZONEJ */
/* 		  O KROK / POMNIEJSZONEJ DLA DOWNTO / , */
/* 		SKOK NA POCZATEK PETLI */


/*     ##### OUTPUT CODE : 37 , 113 , 114 , 139 , 141 . */


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




/* dsw  DATA SFEHEX1,SFEHEX2,SFEHEX3 /Z8000,Z4000, Z2000 / */

/* dsw  --------------------------------------------------- */
    sfehx1 = 32768;
/* dsw  ----------------------------------------------- */
/* .............. */
    n = stack[stos_1.valtop - 4];
    step = stack[stos_1.valtop - 3];
    ats = stack[stos_1.valtop - 2];
    k = tstemp_(&c__1);
/*     "DOWNTO" ? */
    if ((n & sfehx1) != 0) {
	goto L600;
    }
/* ....."TO" */
    opkod = 113;
/*     =" + INTEGER" */
/*     STALY KROK?  TAK,JESLI BIT 1 = 0 */
    if ((n & sfehx2) != 0) {
	goto L400;
    }
/*     TAK. */
L200:
    opkod = 37;
/*     =" + CONST" */

L400:
    quadr4_(&opkod, &k, &ats, &step);
/*     WSTAW DO "R5" ( REJESTR = 4 ) */
    quadr3_(&c__139, &k, &c__4);
    stos_1.lstfor = stos_1.vlprev;
/* .....ZWOLNIJ ZMIENNE ROBOCZE,JESLI: */
/*     WARTOSC KONCOWA ROZNA OD STALEJ /BIT 2 = 1/ */
    if ((n & sfehx3) != 0) {
	i__1 = stos_1.tempnr + 6;
	quadr2_(&c__141, &i__1);
    }
/*     KROK ROZNY OD STALEJ /BIT 1 = 1/ */
    if ((n & sfehx2) != 0) {
	i__1 = stos_1.tempnr + 3;
	quadr2_(&c__141, &i__1);
    }

/*     ZWOLNIJ NUMERY ATRYBUTOW ROBOCZYCH REZERWOWANE DLA PETLI FOR */
    stos_1.tempnr += 6;
    return 0;

/* ....."DOWNTO".   STALY KROK? */
L600:
    opkod = 114;
/*     =" - INTEGER" */
    if ((n & sfehx2) != 0) {
	goto L400;
    }
/*     TAK */
    step = -step;
    goto L200;
} /* sforend_ */

#undef staler
#undef stack


/* Subroutine */ int skill_(void)
{
    /* Local variables */
    static integer i__;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), serror_(integer *);

/* --------------------------------------------------------------- */

/*     NA CZUBKU JEST ARGUMENT KILL. BADA TYP,GENERUJE KOD. */


/*     ##### OUTPUT CODE  : 143 , 146 . */

/*     ##### DETECTED ERROR(S) : 415 . */

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


    svalue_();
/*     JESLI UNIWERSALNY-POMIN */
    if (stack[stos_1.valtop - 1] == 0) {
	return 0;
    }
/*     POMIN TAKZE NONE LUB TYP UNIWERSALNY */
    blank_1.idl = stack[stos_1.valtop - 5];
    if (blank_1.idl == blank_1.nrnone || blank_1.idl == blank_1.nruniv) {
	return 0;
    }
    blank_1.idr = 143;
/*     OPKOD KILL DLA TABLICY,REKORDU */
/*     TABLICA? */
    if (stack[stos_1.valtop - 4] > 0) {
	goto L50;
    }
/*     NIE. CZY TYP PIERWOTNY? */
    for (i__ = 1; i__ <= 6; ++i__) {
	if (blank_1.idl == stos_1.consnr[i__ - 1]) {
	    goto L90;
	}
/* L20: */
    }
/* ..... O.K.	REKORD? /POLE T=2/ */
    if ((blank_1.ipmem[blank_1.idl - 1] & 15) != 2) {
	blank_1.idr = 146;
    }
/*     OPKOD UNIWERSALNEGO KILL */
L50:
    quadr2_(&blank_1.idr, &stack[stos_1.valtop - 3]);
    return 0;
L90:
    serror_(&c__415);
    return 0;
} /* skill_ */

#undef staler
#undef stack


/* Subroutine */ int soption_(void)
{
    /* Initialized data */

    static struct {
	integer e_1;
	logical e_2;
	integer e_3;
	logical e_4[2];
	integer e_5[2];
	} equiv_3 = { 0, TRUE_, 0, FALSE_, TRUE_, 0, 0 };

    static struct {
	integer e_1;
	logical e_2;
	integer e_3;
	logical e_4[2];
	integer e_5[2];
	} equiv_4 = { 1, FALSE_, 2, TRUE_, FALSE_, 1, 2 };


    /* Local variables */
    static integer n;
#define plus ((integer *)&equiv_3)
#define stack ((integer *)&blank_1 + 302)
#define minus ((integer *)&equiv_4)
#define lplus ((logical *)&equiv_3)
    extern /* Subroutine */ int snext_(void);
#define staler ((real *)&blank_1 + 302)
#define option ((integer *)&option_1)
#define lminus ((logical *)&equiv_4)

/* ------------------------------------------------------ */

/*     OBSLUGUJE ZMIANE OPCJI */

/*     NASTEPNY SYMBOL TO + , - NUMER OPCJI. */

/*     NUMER I NAZWA OPCJI * ZMIENNA * WARTOSC DLA + * DLA - * ZNACZENIE DLA + */

/*     M 2 MEMBER CONTROL  * OPTMEM  *	  0    *    1	* WYMAGANA KONTROLA */
/*     O 3 OPTIMIZATION	  * OPTOPT  *  TRUE    *  FALSE * WOLNO OPTYMALIZOWAC */
/*     I 4 INDEX CONTROL   * OPTIND  *	  0    *    2	* WYMAGANA KONTROLA */
/*     T 5 TYPE CONTROL	  * OPTTYP  *  FALSE   *  TRUE	* WYMAGANA KONTROLA */
/*     D 6 TRACE 	  * OPTTRC  *  TRUE    *  FALSE * WYMAGANY SLAD */
/*     C 7 CASE CONTROL	  * OPTCSC  *	  0    *    1	* WYMAGANA KONTROLA */
/*     F 8 FAST CASE	  * OPTCSF  *	  0    *    2	* SZYBKI CASE */


/*     OPCJA 1 - LISTING - JEST UZYWANA TYLKO PRZEZ PARSER */



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


/*     PLUS,LPLUS - WARTOSCI ODPOWIEDNICH ZMIENNYCH DLA ZAPALONEJ OPCJI */
/*     MINUS,LMINUS -   "        "           "       "  ZGASZONEJ OPCJI */



/* .....WCZYTAJ NUMER OPCJI */
    snext_();
/*     ZGASZONA ? */
    if (stos_1.wb > 0) {
	goto L100;
    }
/* ... TAK */
    stos_1.wb = -stos_1.wb - 1;
    n = minus[stos_1.wb - 1];
    goto L200;
/* ... ZAPALONA */
L100:
    --stos_1.wb;
    n = plus[stos_1.wb - 1];
L200:
    option[stos_1.wb - 1] = n;
    return 0;
} /* soption_ */

#undef lminus
#undef option
#undef staler
#undef lplus
#undef minus
#undef stack
#undef plus


/* dsw  subroutine sread(*,*) */
/* Subroutine */ int sread_(integer *where)
{
    /* Local variables */
    static integer k, l, n, elem;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr2_(integer *, integer *), quadr4_(
	    integer *, integer *, integer *, integer *), sfladr_(void);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), serror_(integer *);
    extern integer tstemp_(integer *);
    extern /* Subroutine */ int sstore_(integer *, integer *);

/* ----------------------------------------------------------------------- */
/* dsw   where=1 - return1, where=2 - return2 */

/*     OBSLUGUJE OPERACJE CZYTANIA. */
/*     NA CZUBKU STOSU ZNAJDUJE SIE ARGUMENT LUB ADRES PLIKU */

/*     WRACA DO ETYKIETY 30 LUB 40 W SDPDA */

/*     KORZYSTA Z /BEZPARAMETROWYCH/ STANDARDOWYCH FUNKCJI */
/*     O NUMERACH : */
/* 		   43,44 - READCHAR */
/* 		   45,46 - READINT */
/* 		   47,48 - READREAL */


/*     ##### OUTPUT CODE  : 23 , 132 . */

/*     ##### DETECTED ERROR(S) : 420 , 443 . */


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




    elem = stack[stos_1.valtop - 1];
    if (elem == 0) {
	goto L500;
    }
    k = stack[stos_1.valtop - 5];
/*     PIERWSZY ARGUMENT ? */
    if (stos_1.flargs > 0) {
	goto L100;
    }
/*     TAK. FUNKCJA ? */
    if (elem == 12) {
	goto L50;
    }
/*     NIE. ADRES PLIKU ? */
    if (stack[stos_1.valtop - 4] > 0) {
	goto L200;
    }
    if ((blank_1.ipmem[k - 1] & 15) != 11) {
	goto L100;
    }
/*     TAK. PRZEKAZ ADRES PLIKU */
L50:
    svalue_();
    k = stack[stos_1.valtop - 5];
    if (stack[stos_1.valtop - 4] > 0) {
	goto L200;
    }
    if ((blank_1.ipmem[k - 1] & 15) != 11) {
	goto L100;
    }
    stos_1.flmodf = 0;
    stos_1.file = stos_1.valtop;
    sfladr_();
    stos_1.flargs = 1;
/*     GO TO 40 */
/* dsw  RETURN2 */
/* dsw  ------------------ */
    *where = 2;
    return 0;
/* dsw  ------------------ */
/*     POWROT DO PETLI W SDPDA */


/* .....ARGUMENT. ZMIENNA ? */
L100:
    if (elem < 3 || elem > 5) {
	serror_(&c__420);
    }
/*     WPISZ ADRES PLIKU */
    sfladr_();
/*     ZBADAJ TYP, TABLICOWY ? */
    if (stack[stos_1.valtop - 4] > 0) {
	goto L200;
    }
/*     N=NUMER FUNKCJI STANDARDOWEJ ,L=APETYT, K=TYP */
    n = 46;
    l = 1;
/*     INTEGER? */
    if (k == blank_1.nrint) {
	goto L300;
    }
/*     CHAR? */
    n = 44;
    if (k == blank_1.nrchr) {
	goto L300;
    }
/*     REAL? */
    n = 48;
    l = 1;
    if (k == blank_1.nrre) {
	goto L300;
    }
/* .....ZATEM NIEPOPRAWNY TYP ZMIENNEJ W INSTRUKCJI READ */
L200:
    serror_(&c__443);
    goto L500;

/* .....OK   PRZEKAZ STEROWANIE DO FUNKCJI STANDARDOWEJ */
L300:
    n -= stos_1.flmodf;
    quadr2_(&c__132, &n);
/*     ODCZYTAJ WARTOSC */
    k = tstemp_(&l);
    quadr4_(&c__23, &k, &n, &c__0);
/*     WPISZ WARTOSC */
    sstore_(&stos_1.valtop, &k);
L500:
    stos_1.flargs = 2;
/*     POWROT DO ETYKIETY 30 W SDPDA */
/*     GO TO 30 */
/* dsw  RETURN1 */
/* dsw  ---------------- */
    *where = 1;
    return 0;
/* dsw  ----------------- */
} /* sread_ */

#undef staler
#undef stack


/* dsw  SUBROUTINE SWRITE(*,*) */
/* Subroutine */ int swrite_(integer *where)
{
    /* Local variables */
    static integer i__, k, n;
    extern /* Subroutine */ int spop_(void);
#define stack ((integer *)&blank_1 + 302)
    extern integer svats_(integer *);
    extern /* Subroutine */ int snext_(void), quadr2_(integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *), sfladr_(void)
	    ;
    static integer format[2];
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), serror_(integer *);
    extern integer sconst_(integer *);
    extern /* Subroutine */ int sindtyp_(void);

/* ------------------------------------------------------------------------ */
/* dsw  where = 1 - return1, where = 2 - return2 */

/*     OBSLUGUJE OPERACJE PISANIA. */
/*     NA STOSIE JEST ADRES PLIKU LUB WARTOSC DO WYPISANIA, A NAD NIA 0,1 LUB 2 */
/*     WARTOSCI OKRESLAJACE FORMAT. */
/*     NASTEPNY SYMBOL = LICZBA WARTOSCI OKRESLAJACYCH FORMAT /0..2/ */
/*     ZDEJMUJE TE WARTOSCI ZE STOSU. */

/*     WRACA DO ETYKIETY 30 LUB 40 W SDPDA */

/*     UZYWA PROCEDUR STANDARDOWYCH : */
/* 	 60,61 - WRITECHAR ( ZNAK ) */
/* 	 62,63 - WRITEINT ( LICZBA , SZEROKOSC POLA ) */
/* 	 64,65 - WRITEREAL ( LICZBA , LICZBA ZNAKOW PRZED KROPKA , PO KROPCE ) */
/* 			     = WRFLT. = */
/* 	 66,67 - WRITEREAL   = WRFLE. = */
/* 	 68,69 - WRITEREAL   = WRFLF. = */
/* 	 70,71 - WRITESTRING ( ADRES TEKSTU , SZEROKOSC POLA LUB -1 ) */

/*     DOZWOLONE FORMATY : */
/* 	 INTEGER - 0 LUB 1  , DEFAULT = 6 */
/* 	 CHAR - 0 */
/* 	 TEXT - 0 LUB 1  , DEFAULT = -1  /=CALY TEKST/ */
/* 	 REAL - 0 , 1 LUB 2  , DEFAULT = 12 . 4 /=17/ */

/*      UWAGA : PARAMETRY / W TYM WARTOSC FUNKCJI / SA NUMEROWANE OD ZERA . */

/*     ##### OUTPUT CODE : 132 , 145 . */

/*     ##### DETECTED ERROR(S) :  441 , 442 . */

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





    snext_();
/*     WB=LICZBA WYRAZEN OKRESLAJACYCH FORMAT */
/* .....WSTAW DO TABLICY FORMAT ATS-Y FORMATOW */

    i__ = stos_1.wb;
L100:
    if (i__ == 0) {
	goto L200;
    }
    sindtyp_();
    format[i__ - 1] = svats_(&stos_1.valtop);
    spop_();
    --i__;
    goto L100;

/* .....TERAZ CZUBEK ZAWIERA WARTOSC DO WYPISANIA LUB ADRES PLIKU */
L200:
    svalue_();
    if (stack[stos_1.valtop - 1] == 0) {
	goto L1000;
    }
    k = svats_(&stos_1.valtop);
/*     ZBADAJ TYP */
    if (stack[stos_1.valtop - 4] != 0) {
	goto L400;
    }
    i__ = stack[stos_1.valtop - 5];
/*     PIERWSZY ARGUMENT ? */
    if (stos_1.flargs > 0) {
	goto L300;
    }
/*     TAK. ADRES PLIKU ? */
    if ((blank_1.ipmem[i__ - 1] & 15) != 11) {
	goto L300;
    }
/*     TAK. WYSTAPIL FORMAT ? */
    if (stos_1.wb != 0) {
	serror_(&c__441);
    }
    stos_1.flmodf = 0;
    stos_1.file = stos_1.valtop;
    stos_1.flargs = 1;
    sfladr_();
/*     GO TO 40 */
/* dsw  RETURN2 */
/* dsw  ------------------- */
    *where = 2;
    return 0;
/* dsw  -------------------- */
/*     POWROT DO PETLI W SDPDA */

/* .....ARGUMENT */
L300:
    sfladr_();
    if (i__ == blank_1.nrre) {
	goto L800;
    }
/*     ZATEM CHAR,INTEGER,TEXT */
    if (i__ == blank_1.nrint) {
	goto L500;
    }
    if (i__ == blank_1.nrtext) {
	goto L600;
    }
    if (i__ == blank_1.nrchr) {
	goto L700;
    }

/* .....ZATEM NIELEGALNY TYP ARGUMENTU INSTRUKCJI WRITE */
L400:
    i__ = 442;
L410:
    serror_(&i__);
    goto L1000;

/* ....NIELEGALNY FORMAT */
L420:
    i__ = 441;
    goto L410;


/* .....INTEGER.	 DEFAULT : 6 ZNAKOW */
L500:
    if (stos_1.wb == 2) {
	goto L420;
    }
    if (stos_1.wb == 0) {
	format[0] = sconst_(&c__6);
    }
    n = stos_1.flmodf + 62;
    goto L920;

/* ....TEXT.  -1 JESLI BRAK FORMATU */
L600:
    if (stos_1.wb == 2) {
	goto L420;
    }
    if (stos_1.wb == 0) {
	format[0] = sconst_(&c_n1);
    }
    n = stos_1.flmodf + 70;
    goto L920;

/* .....CHAR */
L700:
    if (stos_1.wb != 0) {
	goto L420;
    }
    n = stos_1.flmodf + 60;
    goto L930;

/* .....REAL.   DEFAULT : 12 ZNAKOW PRZED KROPKA , 4 PO KROPCE. */
L800:
    n = (stos_1.wb << 1) + 64 + stos_1.flmodf;
    ++stos_1.wb;
    switch (stos_1.wb) {
	case 1:  goto L810;
	case 2:  goto L820;
	case 3:  goto L830;
    }
/* ... BEZ FORMATU , DEFAULT 12.4   , "WRFLT." = 8 */
L810:
    format[0] = sconst_(&c__12);
    format[1] = sconst_(&c__4);
    goto L900;
/* ... FORMAT = SZEROKOSC POLA , 5 ZNAKOW PO KROPCE, "WRFLE." = 10 */
L820:
    format[1] = sconst_(&c__5);

/* ... FORMAT = SZEROKOSC POLA,LICZBA ZNAKOW PO KROPCE, "WRFLF." = 11 */
L830:
/* .....WSTAWIANIE PARAMETROW : N = NUMER PROCEDURY STANDARDOWEJ */
/* 			      K = ATS WARTOSCI */
/*     WSTAW PRAWY FORMAT DLA REAL */
L900:
    quadr4_(&c__145, &format[1], &n, &c__2);
/*     WSTAW /LEWY/ FORMAT */
L920:
    quadr4_(&c__145, format, &n, &c__1);
/*     WSTAW WARTOSC */
L930:
    quadr4_(&c__145, &k, &n, &c__0);
/*     PRZEKAZ STEROWANIE */
    quadr2_(&c__132, &n);
L1000:
    stos_1.flargs = 2;
/*     POWROT DO ETYKIETY 30 W SDPDA */
/* dsw  RETURN1 */
/* dsw  ----------------- */
    *where = 1;
    return 0;
/* dsw  ----------------- */
} /* swrite_ */

#undef staler
#undef stack


/* Subroutine */ int sftest_(void)
{
    /* Local variables */
    static integer n;
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int serror_(integer *);

/* --------------------------------------------------------- */

/*     SPRAWDZA, CZY ELEMENT Z CZUBKA STOSU (UNIW.,STALA, */
/* 	WARTOSC,ZMIENNA,TABL.STAT.,ELEM.TABL.) JEST TYPU FILE . */
/*     'NONE' NIE JEST AKCEPTOWANE */

/*     ##### DETECTED ERROR(S) : 413 . */

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


    n = stack[stos_1.valtop - 5];
    if (stack[stos_1.valtop - 4] > 0 || n != blank_1.nruniv && (blank_1.ipmem[
	    n - 1] & 15) != 11) {
	serror_(&c__413);
    }
    return 0;
} /* sftest_ */

#undef staler
#undef stack


/* Subroutine */ int sfladr_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* --------------------------------------------------------- */

/*     ZAPEWNIA, ZE (R6-12) ZAWIERA ADRES PLIKU */
/* 	 - DLA OPERACJI NA PLIKU WSKAZYWANYM */

/*     ##### OUTPUT CODE : 139 . */

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


    if (stos_1.file == 0 || stos_1.flready) {
	return 0;
    }
    quadr3_(&c__139, &stack[stos_1.file - 3], &c_n45);
/* 		-45 --> (R6-12) */
    stos_1.flready = TRUE_;
    return 0;
} /* sfladr_ */

#undef staler
#undef stack


/* dsw  SUBROUTINE SPUT(*,*) */
/* Subroutine */ int sput_(integer *where)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer n;
#define stack ((integer *)&blank_1 + 302)
    extern integer svats_(integer *);
    extern /* Subroutine */ int quadr2_(integer *, integer *), quadr4_(
	    integer *, integer *, integer *, integer *), sfladr_(void);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), sftest_(void), serror_(integer 
	    *);

/* --------------------------------------------------------- */
/* dsw   where = 1 - return1, where = 2 - return2 */

/*     OBSLUGUJE 'PUT' . */
/*     CZUBEK STOSU ZAWIERA ADRES PLIKU LUB ARGUMENT. */

/*     WRACA BEZPOSREDNIO DO ETYKIETY 30 LUB 40 W SDPDA. */

/*     ##### OUTPUT CODE : 132 , 145 . */

/*     ##### DETECTED ERROR(S) : 445 . */

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


    svalue_();
/*     ADRES PLIKU JUZ WYSTAPIL ? */
    if (stos_1.flargs > 0) {
	goto L100;
    }
/*     JESZCZE NIE */
    sftest_();
    stos_1.file = stos_1.valtop;
    stos_1.flargs = 1;
    stos_1.flmodf = 0;
    sfladr_();
/*     GO TO 40 */
/* dsw  RETURN2 */
/* dsw  ------------------ */
    *where = 2;
    return 0;
/* dsw  ------------------ */
/*     POWROT DO SDPDA */

/* .....ARGUMENT */
L100:
    stos_1.flargs = 2;
    sfladr_();
    n = stack[stos_1.valtop - 5];
/*     SEMAPHORE ? */
    if ((blank_1.ipmem[n - 1] & 15) == 9) {
	goto L799;
    }
    if (stack[stos_1.valtop - 4] > 0) {
	goto L799;
    }
    if (n == blank_1.nrint) {
	goto L400;
    }
    if (n == blank_1.nrchr) {
	goto L300;
    }
    if (n == blank_1.nrre) {
	goto L500;
    }
    if (n == blank_1.nrtext) {
	goto L799;
    }
/*     ZATEM REFERENCJA lub nielegealny typ */
    goto L799;
/* PS  600 N=56        dziwne, ta etykieta nie jest uzywana ! */
/* PS      GO TO 1000 */
L300:
    n = 53;
    goto L1000;
L400:
    n = 54;
    goto L1000;
L500:
    n = 55;
    goto L1000;

L1000:
    i__1 = svats_(&stos_1.valtop);
    quadr4_(&c__145, &i__1, &n, &c__0);
    quadr2_(&c__132, &n);
/*     GO TO 30 */
/* dsw  RETURN1 */
/* dsw  ------------------ */
    *where = 1;
    return 0;
/* dsw  ------------------ */
/*     POWROT DO SDPDA */
L799:
    serror_(&c__445);
    *where = 1;
    return 0;
} /* sput_ */

#undef staler
#undef stack


/* dsw  SUBROUTINE SGET(*,*) */
/* Subroutine */ int sget_(integer *where)
{
    /* Local variables */
    static integer n, ats, elem;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr2_(integer *, integer *), quadr4_(
	    integer *, integer *, integer *, integer *), sfladr_(void);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), sftest_(void);
    extern integer tstemp_(integer *);
    extern /* Subroutine */ int serror_(integer *), sstore_(integer *, 
	    integer *);

/* --------------------------------------------------------- */
/* dsw  where = 1 - return1 , where = 2 - return2 */

/*     OBSLUGUJE 'GET' */
/*     CZUBEK STOSU ZAWIERA ARGUMENT LUB ADRES PLIKU. */

/*     WRACA DO ETYKIETY 30 LUB 40 W SDPDA. */

/*     ##### OUTPUT CODE : 23 , 132 , 145 . */

/*     #####  DETECTED ERROR(S) : 420 , 446 . */

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



/*     ADRES PLIKU JUZ WYSTAPIL ? */
    if (stos_1.flargs > 0) {
	goto L100;
    }
/*     JESZCZE NIE */
    svalue_();
    sftest_();
    stos_1.file = stos_1.valtop;
    stos_1.flargs = 1;
    stos_1.flmodf = 0;
    sfladr_();
/*     GO TO 40 */
/* dsw  RETURN2 */
/* dsw  ------------------------ */
    *where = 2;
    return 0;
/* dsw  ------------------------ */
/*     POWROT DO SDPDA */

/* .....ARGUMENT. ZMIENNA ? */
L100:
    stos_1.flargs = 2;
    sfladr_();
    elem = stack[stos_1.valtop - 1];
    n = stack[stos_1.valtop - 5];
/*     SEMAPHORE ? */
    if ((blank_1.ipmem[n - 1] & 15) == 9) {
	goto L9000;
    }
    if (stack[stos_1.valtop - 4] > 0) {
	goto L9000;
    }
    if (n == blank_1.nrint) {
	goto L1000;
    }
    if (n == blank_1.nrchr) {
	goto L1200;
    }
    if (n == blank_1.nrre) {
	goto L1100;
    }
    if (n == blank_1.nrtext) {
	goto L9000;
    }
/*     ZATEM REFERENCJA.lub nielegalny typ */
    goto L9000;
/*     POWROT DO PETLI W SDPDA */

/* ... INTEGER */
L1000:
    n = 50;
    goto L1500;
/* ... REAL */
L1100:
    n = 51;
    ats = tstemp_(&c__1);
    goto L2000;
/* ... CHAR */
L1200:
    n = 49;


L1500:
    ats = tstemp_(&c__1);
/*     ZMIENNA ? */
L2000:
    if (elem < 3 || elem > 5) {
	serror_(&c__420);
    }
    quadr2_(&c__132, &n);
    quadr4_(&c__23, &ats, &n, &c__0);
    sstore_(&stos_1.valtop, &ats);
/*     GO TO 30 */
/* dsw  RETURN1 */
/* dsw  ---------------- */
    *where = 1;
    return 0;
/* dsw  ---------------- */
/*     POWROT DO SDPDA */
/* .....NIELEGALNY TYP ARGUMENTU */
L9000:
    serror_(&c__446);
/*     GO TO 30 */
/* dsw  RETURN1 */
/* dsw  ---------------- */
    *where = 1;
    return 0;
/* dsw  ----------------- */
} /* sget_ */

#undef staler
#undef stack


/* Subroutine */ int seof_(integer *n)
{
    /* Local variables */
    extern /* Subroutine */ int spop_(void), seof0_(integer *);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), sftest_(void);

/* -------------------------------------------------------------- */
/* dsw   procedura zostala podzielona na dwie - seof i seof0 */

/*     OBSLUGUJE OPERATORY 'EOF' I 'EOLN'. */
/*     WSTAWIA NA STOS ODCZYTANA WARTOSC FUNKCJI. */

/*     WEJSCIE SEOF0 ODPOWIADA BEZPARAMETROWYM EOF, EOLN. */
/*     WEJSCIE SEOF ODPOWIADA EOF, EOLN Z PODANYM (NA CZUBKU STOSU) */
/* 	ADRESEM PLIKU (JEST USUWANY). */
/*     N = NUMER ODPOWIEDNIEJ FUNKCJI STANDARDOWEJ */
/* 	     (39, 40 DLA EOF, 74, 75 DLA EOLN) */


/*     ###### GENEROWANY KOD : 23 , 132 , 139 . */


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



/* ......CZUBEK STOSU ZAWIERA ADRES PLIKU */
    svalue_();
    sftest_();
/*     PRZEKAZ ADRES PLIKU DO (R6-12) */
    quadr3_(&c__139, &stack[stos_1.valtop - 3], &c_n45);
    spop_();
/*     DALEJ JAK DLA BEZPARAMETROWYCH EOF, EOLN */

    seof0_(n);
    return 0;
} /* seof_ */

#undef staler
#undef stack


/* Subroutine */ int seof0_(integer *n)
{
    /* Local variables */
    static integer ats;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int spush_(integer *), quadr2_(integer *, integer 
	    *), quadr4_(integer *, integer *, integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *);

/* -------------------------------------------------------------- */
/* dsw   procedura zostala podzielona na dwie - seof i seof0 */

/*     OBSLUGUJE OPERATORY 'EOF' I 'EOLN'. */
/*     WSTAWIA NA STOS ODCZYTANA WARTOSC FUNKCJI. */

/*     WEJSCIE SEOF0 ODPOWIADA BEZPARAMETROWYM EOF, EOLN. */
/*     WEJSCIE SEOF ODPOWIADA EOF, EOLN Z PODANYM (NA CZUBKU STOSU) */
/* 	ADRESEM PLIKU (JEST USUWANY). */
/*     N = NUMER ODPOWIEDNIEJ FUNKCJI STANDARDOWEJ */
/* 	     (39, 40 DLA EOF, 74, 75 DLA EOLN) */


/*     ###### GENEROWANY KOD : 23 , 132 , 139 . */


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



/* ...................BEZPARAMETROWE EOF , EOLN */

/*     WYWOLAJ FUNKCJE */
    quadr2_(&c__132, n);
    ats = tstemp_(&c__1);
/*     PODCZYTAJ WARTOSC ( PARAMETR 0 ) */
    quadr4_(&c__23, &ats, n, &c__0);
/*     WSTAW NA STOS ODCZYTANA WARTOSC */
    spush_(&c__2);
    stack[stos_1.valtop - 2] = 0;
    stack[stos_1.valtop - 3] = ats;
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 5] = blank_1.nrbool;
    stack[stos_1.valtop - 6] = 0;
    return 0;
} /* seof0_ */

#undef staler
#undef stack


integer svats_(integer *elem)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer n;
#define stack ((integer *)&blank_1 + 302)
    extern integer screal_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer sconst_(integer *);

/* -------------------------------------------------------------- */

/*     ZWRACA ATS WARTOSCI Z MIEJSCA ELEM STOSU . */
/* 	  (UNIWERSALNY,STALA,WARTOSC) */
/* 	DLA STALEJ GENERUJE NOWY ATS. */

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

/* dsw&ail */

    ret_val = stack[*elem - 3];
    if (stack[*elem - 1] != 1) {
	return ret_val;
    }
/*     STALA */
    n = stack[*elem - 5];
    if (n == blank_1.nrre) {
	goto L100;
    }
    if (n == blank_1.nrnone) {
	goto L200;
    }
/*     ZATEM : INTEGER,CHAR,BOOLEAN,TEXT */
    ret_val = sconst_(&ret_val);
    return ret_val;
/* ... STALA REAL */
L100:
    ret_val = screal_(&ret_val);
    return ret_val;
/* ... STALA NONE */
/* dsw&ail  200 SVATS=LMEM-3 */
L200:
    ret_val = stacks_1.btstem - 3;
    return ret_val;
} /* svats_ */

#undef staler
#undef stack



/* Subroutine */ int savevar_(integer *elem)
{
    /* Local variables */
    static integer n;
    extern /* Subroutine */ int safe_(integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* ------------------------------------------------------- */

/*     ZABEZPIECZA ADRES ZMIENNEJ (UOGOLNIONEJ) Z MIEJSCA */
/*      ELEM STOSU. */

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



    n = stack[*elem - 1] - 2;
    switch (n) {
	case 1:  goto L300;
	case 2:  goto L400;
	case 3:  goto L500;
    }
/* .....ZMIENNA */
/*     ADRES PRZED KROPKA : */
L300:
    safe_(&stack[*elem - 8]);
    return 0;
/* .....ELEMENT TABLICY */
/*     ADRES TABLICY : */
L400:
    safe_(&stack[*elem - 3]);
/*     I INDEKS, JESLI ROZNY OD STALEJ : */
    if (stack[*elem - 3] > 0) {
	goto L300;
    }
/* dsw     added - bug! */
    return 0;
/* .....TABLICA STATYCZNA */
L500:
    goto L300;
} /* savevar_ */

#undef staler
#undef stack


/* Subroutine */ int scheck_(integer *error, integer *typ)
{
    /* Local variables */
    static integer i__;
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int serror_(integer *);

/* -------------------------------------------------------- */

/*     POMOCNICZA. JESLI CZUBEK STOSU NIE JEST TYPU PROSTEGO */
/*     TYP LUB UNIWERSALNEGO - SYGNALIZUJE BLAD ERROR. */

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



    i__ = stack[stos_1.valtop - 5];
    if (stack[stos_1.valtop - 4] != 0 || i__ != blank_1.nruniv && i__ != *typ)
	     {
	serror_(error);
    }
    return 0;
} /* scheck_ */

#undef staler
#undef stack


/* Subroutine */ int snot_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int snext_(void), quadr3_(integer *, integer *, 
	    integer *), scheck_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void);
    extern integer tstemp_(integer *);

/* ----------------------------------------------------------------- */

/*     OBSLUGUJE OPERATOR NOT. ARGUMENT JEST NA CZUBKU . */


/*     ##### OUTPUT CODE : 42 . */

/*     ##### DETECTED ERROR(S) : 417 . */

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



    snext_();
    svalue_();
/*     JESLI UNIWERSALNY-POMIN */
    if (stack[stos_1.valtop - 1] == 0) {
	return 0;
    }
/*     SPRAWDZ TYP */
    scheck_(&c__417, &blank_1.nrbool);
/* .....	CZY STALA? */
    if (stack[stos_1.valtop - 1] == 1) {
	goto L51;
    }
/*     NIE. CZY WB= IF.FALSE LUB IF.TRUE ? */
    if (stos_1.wb == 29 || stos_1.wb == 30) {
	goto L60;
    }
/* .....NIE,  WYKONAJ NOT. */
    blank_1.idl = tstemp_(&c__1);
    quadr3_(&c__42, &blank_1.idl, &stack[stos_1.valtop - 3]);
    stack[stos_1.valtop - 1] = 2;
    stack[stos_1.valtop - 3] = blank_1.idl;
    return 0;
/* .....STALA, ZMIEN WARTOSC. */
L51:
    stack[stos_1.valtop - 3] = -1 - stack[stos_1.valtop - 3];
    return 0;
/* .....NOT PRZED SKOKIEM WARUNKOWYM,ZMIEN RODZAJ SKOKU */
L60:
    stos_1.wb = 59 - stos_1.wb;
    return 0;
} /* snot_ */

#undef staler
#undef stack


/* Subroutine */ int sarith_(void)
{
    /* System generated locals */
    integer i__1;
    real r__1;
    static real equiv_2[1];

    /* Local variables */
#define m ((shortint *)equiv_2)
    static integer n;
#define y (equiv_2)
    static integer elem;
    extern integer creal_(real *);
#define stack ((integer *)&blank_1 + 302)
    static integer opkod;
    static real xreal, yreal;
    extern /* Subroutine */ int quadr2_(integer *, integer *), quadr3_(
	    integer *, integer *, integer *), quadr4_(integer *, integer *, 
	    integer *, integer *), svalu2_(void);
    extern integer screal_(integer *);
    extern /* Subroutine */ int marith_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void);
    extern integer tstemp_(integer *);
    extern /* Subroutine */ int svreal_(integer *), sargmt_(void);
    extern integer sconst_(integer *);
    extern /* Subroutine */ int serror_(integer *), sresult_(integer *);

/* -------------------------------------------------------------------------- */

/*     1982.09.15 */

/*     OBSLUGUJE 1 LUB 2 - ARGUMENTOWE OPERACJE ARYTMETYCZNE. */
/*     WB=NUMER OPERACJI,      1..8 OZNACZaJA: */
/*      ABS,MINUS UNARNY,+,-,*,/,DIV,MODE */
/*     ARGUMENT LUB 2 ARGUMENTY SA NA CZUBKU STOSU. */
/*     ARGUMENTY ZASTEPUJE PRZEZ WYNIK OPERACJI /UNIWERSALNY,STALA,WARTOSC/ */

/*     WYROZNIA PRZYPADKI: */
/*      OBA ARGUMENTY STALE, */
/*      DODAWANIE,ODEJMOWANIE STALEJ */
/*      MNOZENIE PRZEZ STALE 0..10, */
/*      DZIELENIE PRZEZ 0,1,2,4,8. */


/*     ##### OUTPUT CODE : 37 , 48 , 49 , 50 , 51 , 64 , 65 , 66 , */
/* 			     67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , */
/* 			     75 , 113 , 114 , 115 , 117 , 118 , 119 , */
/* 			     120 , 121 , 122 , 140 . */

/*     ##### DETECTED ERROR(S) : 460 . */

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
/* CCCCCCCCCCCCCC */
/*     ROBOCZE */





/* ........................ */

/*     TERAZ WB=NUMER OPERACJI */
/*     WYLICZ WARTOSC */
    svalue_();
/*     I WSTAW TYP PRAWEGO ARGUMENTU */
    blank_1.trdim = stack[stos_1.valtop - 4];
    blank_1.trbas = stack[stos_1.valtop - 5];
    blank_1.idr = stack[stos_1.valtop - 2];
/* .....PRZESKOCZ,JESLI OPERACJA 2-ARGUMENTOWA */
    if (stos_1.wb > 2) {
	goto L1000;
    }
/* .....ABS LUB MINUS UNARNY */
    if (stack[stos_1.valtop - 1] == 0) {
	return 0;
    }
/*      ZBADAJ TYP */
    blank_1.tldim = blank_1.trdim;
    blank_1.tlbas = blank_1.trbas;
    blank_1.idl = blank_1.idr;
    marith_(&c__1);
/*     CZY STALA? */
    if (stack[stos_1.valtop - 1] == 1) {
	goto L200;
    }
/*     NIE. INTEGER? */
    if (stack[stos_1.valtop - 5] == blank_1.nrint) {
	goto L150;
    }
/*     ZATEM ZMIENNA,WARTOSC TYPU REAL */
    stos_1.result = tstemp_(&c__1);
L100:
    i__1 = stos_1.wb + 49;
    quadr3_(&i__1, &stos_1.result, &stack[stos_1.valtop - 3]);
/*     ZASTAP PRZEZ "WARTOSC" Z NOWYM RESULT */
    stack[stos_1.valtop - 1] = 2;
    stack[stos_1.valtop - 3] = stos_1.result;
    return 0;
/*     ZMIENNA,WARTOSC TYPU INTEGER */
L150:
    stos_1.result = tstemp_(&c__1);
    stos_1.wb += -2;
    goto L100;
/*     STALA JAKO ARGUMENT ABS LUB MINUSA UNARNEGO */
L200:
    if (stack[stos_1.valtop - 5] == blank_1.nrre) {
	goto L250;
    }
    if (stos_1.wb == 1 && stack[stos_1.valtop - 3] < 0 || stos_1.wb == 2) {
	stack[stos_1.valtop - 3] = -stack[stos_1.valtop - 3];
    }
    return 0;
/*     STALA REAL */
L250:
    stos_1.result = stack[stos_1.valtop - 3];
/* dsw&bc      XREAL=STALER(RESULT) */
    xreal = staler[stos_1.result - 1];

    if (stos_1.wb == 1 && xreal < 0.f || stos_1.wb == 2) {
	r__1 = -xreal;
	stack[stos_1.valtop - 3] = creal_(&r__1);
    }
    return 0;

/* ................ OPERACJE 2-ARGUMENTOWE....................... */

/*     ROZROZNIA PRZYPADKI : OBA ARGUMENTY STALE , JEDEN ARGUMENT STALY, */
/* 	MNOZENIE LUB DZIELENIE PRZEZ WYROZNIONE STALE */
/* 		 /0,1,2,3,4,5,6,7,8,9,10 LUB 0,1,2,4,8/ */

L1000:
    svalu2_();
    elem = 0;
/*     JESLI JEDEN Z ARGUMENTOW UNIWERSALNY-ZASTAP OBA PRZEZ UNIWERSALNY */
    if (stack[stos_1.valtop - 1] * stack[stos_1.vlprev - 1] == 0) {
	goto L1400;
    }
/*     WSTAW TYP I NAZWE LEWEGO ,SPRAWDZ TYPY */
    blank_1.tldim = stack[stos_1.vlprev - 4];
    blank_1.tlbas = stack[stos_1.vlprev - 5];
    blank_1.idl = stack[stos_1.vlprev - 2];
    elem = 2;
/*      ELEM="WARTOSC",UZYWANE PO SKOKU DO 1400. */
    opkod = 1;
    if (stos_1.wb > 6) {
	opkod = 2;
    }
    if (stos_1.wb == 6) {
	opkod = 3;
    }
    marith_(&opkod);
/*     WYKONAJ EWENTUALNA KONWERSJE */
    if (blank_1.convr == 1) {
	svreal_(&stos_1.valtop);
    }
    if (blank_1.convl == 1) {
	svreal_(&stos_1.vlprev);
    }
    blank_1.idl = stack[stos_1.vlprev - 3];
    blank_1.idr = stack[stos_1.valtop - 3];
/*     IDL,IDR = WARTOSC LUB NUMER STALEJ LUB ATS LEWEGO,PRAWEGO ARGUMENTU. */
/* 	DLA JEDNEGO ARG.STALEGO - IDR=STALA */


/* ..........STALE ARGUMENTY? */
    sargmt_();
    switch (stos_1.arg) {
	case 1:  goto L2000;
	case 2:  goto L4000;
	case 3:  goto L1600;
	case 4:  goto L1050;
    }

/* ..........OBA ROZNE OD STALYCH */

L1050:
    if (blank_1.treslt == blank_1.nrre) {
	goto L1500;
    }


/*     INTEGER */
L1100:
    stos_1.result = tstemp_(&c__1);
L1200:
    opkod = 110;
/*     GENERUJ OPERACJE */
L1300:
    i__1 = opkod + stos_1.wb;
    quadr4_(&i__1, &stos_1.result, &blank_1.idl, &blank_1.idr);


/* .....ZASTAP OBA PRZEZ "WARTOSC" TYPU TRESLT */

L1400:
    sresult_(&elem);
    return 0;


/*     REAL */
L1500:
    opkod = 116;
    stos_1.result = tstemp_(&c__1);
    goto L1300;

/* .....PRAWY ARGUMENT STALY,LEWY NIE /DLA + , * ROWNIEZ ODWROTNIE/ */
/*     JESLI REAL - WSTAW STALA I DALEJ JAK DLA OBU ROZNYCH OD STALYCH */
L1600:
    if (blank_1.treslt != blank_1.nrre) {
	goto L4100;
    }

/*     TUTAJ ROZSZERZENIE O ARGUMENT 0.0 LUB 1.0 */

    blank_1.idr = screal_(&blank_1.idr);
    goto L1500;


/* .............OBA ARGUMENTY STALE. OBLICZ WYNIK. */

L2000:
    elem = 1;
    stos_1.wb += -2;
    if (blank_1.treslt != blank_1.nrint) {
	goto L3000;
    }

/* .....OPERACJA NA 2 STALYCH INTEGER */
    switch (stos_1.wb) {
	case 1:  goto L2100;
	case 2:  goto L2200;
	case 3:  goto L2300;
	case 4:  goto L2400;
	case 5:  goto L2400;
	case 6:  goto L2500;
    }
/*     + */
L2100:
    stos_1.result = blank_1.idl + blank_1.idr;
    goto L1400;
/*     - */
L2200:
    stos_1.result = blank_1.idl - blank_1.idr;
    goto L1400;
/*     * */
L2300:
    stos_1.result = blank_1.idl * blank_1.idr;
    goto L1400;
/*     /  , DIV */
L2400:
    if (blank_1.idr == 0) {
	goto L4800;
    }
    stos_1.result = blank_1.idl / blank_1.idr;
    goto L1400;
/*     MODE */
L2500:
    stos_1.result = blank_1.idl % blank_1.idr;
    goto L1400;

/* .....OPERACJA NA 2 STALYCH TYPU REAL */
L3000:
/* dsw&bc      XREAL=STALER(IDR) */
/* dsw&bc      YREAL=STALER(IDL) */
    xreal = staler[blank_1.idr - 1];
    yreal = staler[blank_1.idl - 1];
/*     XREAL,YREAL = WARTOSC PRAWEGO,LEWEGO ARGUMENTU */
    switch (stos_1.wb) {
	case 1:  goto L3100;
	case 2:  goto L3200;
	case 3:  goto L3300;
	case 4:  goto L3400;
    }
/*     + */
L3100:
    xreal = yreal + xreal;
    goto L3500;
/*     - */
L3200:
    xreal = yreal - xreal;
    goto L3500;
/*     * */
L3300:
    xreal = yreal * xreal;
    goto L3500;
/*     / */
/* ailvax and all other computers: 3400 IF(YREAL.EQ. 0.0)GO TO 4800 */
L3400:
    if (xreal == 0.f) {
	goto L4800;
    }
    xreal = yreal / xreal;
/*     WSTAW XREAL DO SLOWNIKA STALYCH REAL */
L3500:
    stos_1.result = creal_(&xreal);
    goto L1400;

/* .....LEWY ARGUMENT STALY,PRAWY NIE. */

/*     OPERACJA SYMETRYCZNA? */
L4000:
    if (stos_1.wb == 3 || stos_1.wb == 5) {
	goto L4050;
    }
/*     OPERACJA NIESYMETRYCZNA */
    if (blank_1.treslt == blank_1.nrre) {
	goto L4030;
    }
    blank_1.idl = sconst_(&blank_1.idl);
    goto L1100;
L4030:
    blank_1.idl = screal_(&blank_1.idl);

/*     TUTAJ ROZSZERZENIE O LEWY ARGUMENT 0.0 DLA - , / . */

    goto L1500;

/*     OPERACJA SYMETRYCZNA:   + , * .ZAMIEN IDL,IDR */
L4050:
    blank_1.trdim = blank_1.idl;
    blank_1.idl = blank_1.idr;
    blank_1.idr = blank_1.trdim;
    goto L1600;

/* .....WSPOLNA AKCJA. PRAWY ARG.STALY LUB OP.SYM. I LEWY STALY */
/*     IDL = ATS ROZNEGO OD STALEJ ARG.,IDR=STALA */
/* 	  OBA ARGUMENTY TYPU INTEGER. */

L4100:
    stos_1.result = tstemp_(&c__1);
    switch (stos_1.wb) {
	case 1:  goto L4150;
	case 2:  goto L4150;
	case 3:  goto L4300;
	case 4:  goto L4200;
	case 5:  goto L4400;
	case 6:  goto L4700;
	case 7:  goto L4700;
	case 8:  goto L4720;
    }
L4150:

/* ........... */
/*     -  . ZMIEN ZNAK STALEJ */
L4200:
    blank_1.idr = -blank_1.idr;

/* ........... */
/*     + , - .	   +0	? */
L4300:
    if (blank_1.idr == 0) {
	goto L4810;
    }
    quadr4_(&c__37, &stos_1.result, &blank_1.idl, &blank_1.idr);
    goto L1400;

/* .......... */
/*     *     . JAKA TO STALA? */
L4400:
    if (blank_1.idr < 0 || blank_1.idr > 10) {
	goto L4720;
    }
/*     ZATEM STALA 0..10 */
    if ((i__1 = blank_1.idr - 1) < 0) {
	goto L4805;
    } else if (i__1 == 0) {
	goto L4810;
    } else {
	goto L4500;
    }
/* ... MNOZENIE PRZEZ STALA 2..10  /REALIZOWANE PRZEZ SHIFT/ */
L4500:
    opkod = blank_1.idr + 62;
L4600:
    quadr3_(&opkod, &stos_1.result, &blank_1.idl);
    goto L1400;

/* ........... */
/*     DIVE */
L4700:
    if (blank_1.idr >= 0 && blank_1.idr <= 8) {
	goto L4750;
    }
/*     WSTAW STALA */
L4720:
    blank_1.idr = sconst_(&blank_1.idr);
    goto L1200;
/* ... DZIELENIE PRZEZ STALE 0..8   . WYROZNIJ 0,1,2,4,8 */
L4750:
    n = blank_1.idr + 1;
    switch (n) {
	case 1:  goto L4800;
	case 2:  goto L4810;
	case 3:  goto L4820;
	case 4:  goto L4720;
	case 5:  goto L4840;
	case 6:  goto L4720;
	case 7:  goto L4720;
	case 8:  goto L4720;
	case 9:  goto L4880;
    }

/* .....DZIELENIE PRZEZ ZERO */
L4800:
    serror_(&c__460);
/*     ZASTAP PRZEZ STALA ZERO / DLA MNOZENIA LUB DZIELENIA PRZEZ ZERO / */
L4805:
    elem = 1;
    if (! option_1.optopt) {
	quadr2_(&c__140, &blank_1.idl);
    }
    stos_1.result = blank_1.idr;
    goto L1400;
/* ... ZASTAP PRZEZ ARGUMENT ROZNY OD STALEJ / MNOZENIE,DZIELENIE */
/* 			PRZEZ 1 LUB DODAWANIE,ODEJMOWANIE 0 / */
L4810:
    stos_1.result = blank_1.idl;
    goto L1400;

/* ... DIVE 2 */
L4820:
    opkod = 75;
    goto L4600;
/* ... DIVE 4 */
L4840:
    opkod = 74;
    goto L4600;
/* ... DIVE 8 */
L4880:
    opkod = 73;
    goto L4600;

} /* sarith_ */

#undef staler
#undef stack
#undef y
#undef m


/* Subroutine */ int srelat_(void)
{
    /* Initialized data */

    static integer relconv[6] = { 3,4,7,8,5,6 };
    static integer rel[6] = { 2,5,1,3,4,6 };

    /* System generated locals */
    integer i__1;
    static real equiv_2[1];

    /* Local variables */
#define m ((shortint *)equiv_2)
    static real x;
#define y (equiv_2)
    static integer elem;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr3_(integer *, integer *, integer *), 
	    quadr4_(integer *, integer *, integer *, integer *), svalu2_(void)
	    ;
    static integer rlcase;
    extern integer screal_(integer *);
    extern /* Subroutine */ int marith_(integer *), mequal_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), svreal_(integer *), sargmt_(
	    void);
    extern integer tstemp_(integer *);
    extern /* Subroutine */ int serror_(integer *), sresult_(integer *);

/* ----------------------------------------------------------------------------- */

/*     DWA GORNE ELEMENTY STOSU ZAWIERAJA ARGUMENTY RELACJI : */
/*      IS , IN DLA WB= 1,2  LUB */
/*      = , <> , < , <= , > , >=    . WB=NUMER RELACJI /3..8/ */
/*     GENERUJE KOD WYZNACZAJACY WARTOSC RELACJI. */
/*     WYROZNIA PRZYPADKI : OBA ARGUMENTY STALE, */
/* 			   POROWNANIE ZE STALA INTEGER */
/* 			   POROWNANIE Z ZEREM  / 0 LUB 0.0 / */
/* 			   POROWNANIE Z NONE . */


/*     ##### OUTPUT CODE : 55 , 56 , 76 , 77 , 78 , 79 , 80 , 81 , */
/* 			     82 , 83 , 88 , 89 , 90 , 91 , 92 , 93 , */
/* 			     106 , 107 , 108 , 109 , 110 , 111 , */
/* 			     123 , 124 , */
/* 			     125 , 126 , 127 , 128 , 129 , 130 . */

/*     ##### DETECTED ERROR(S) : 475 , 476 . */


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


/* CCCCCCCCCCCCCCCCCCCCCCC */
/*     REL - TABLICA WYZNACZAJACA WYNIKI POROWNANIA DLA 6 RELACJI, */
/* 	   BITY 15,14,13 =0 JESLI DLA L<P , L=P , L>P WYNIK JEST FALSE */
/*     RELCONV - TABLICA ZAMIANY POROWNAN PRZY ZAMIANIE ARGUMENTOW */
/*     RLCASE - TYP POROWNANIA: 1,3,4-INTEGER,2-REAL,5,6-REFERENCYJNY */
/*     ELEM - RODZAJ ELEMENTU */
/* dsw&bc */


/* .......... */
    elem = 0;
    svalu2_();
/*     WSTAW TYP I NAZWE LEWEGO ARGUMENTU */
    blank_1.tldim = stack[stos_1.vlprev - 4];
    blank_1.tlbas = stack[stos_1.vlprev - 5];
    blank_1.idl = stack[stos_1.vlprev - 2];
/*     IS,IN ? */
    if (stos_1.wb < 3) {
	goto L7000;
    }
    svalue_();
    if (stack[stos_1.valtop - 1] * stack[stos_1.vlprev - 1] == 0) {
	goto L3200;
    }
/*     WSTAW TYPY ARGUMENTOW */
    blank_1.trdim = stack[stos_1.valtop - 4];
    blank_1.trbas = stack[stos_1.valtop - 5];
    blank_1.idr = stack[stos_1.valtop - 2];
    elem = 2;
/*     JAKA RELACJA? */
    if (stos_1.wb <= 4) {
	goto L200;
    }
/*     < , <= , > , >= */
    marith_(&c__1);
    rlcase = 1;
    if (blank_1.treslt == blank_1.nrre) {
	rlcase = 2;
    }
    goto L300;
/*     = , <> */
/*     WSTAW INFORMACJE O DOSTEPNOSCI TYPOW FORMALNYCH */
L200:
    blank_1.objl = stack[stos_1.vlprev - 7];
    blank_1.objr = stack[stos_1.valtop - 7];
    mequal_(&rlcase);

/*     RLCASE OKRESLA TYP POROWNANIA: 1,3,4-INTEGER,2-REAL,5,6-REFERENCYJNE */
L300:
    if (blank_1.convl == 1) {
	svreal_(&stos_1.vlprev);
    }
    if (blank_1.convr == 1) {
	svreal_(&stos_1.valtop);
    }
    blank_1.idl = stack[stos_1.vlprev - 3];
    blank_1.idr = stack[stos_1.valtop - 3];
/*     IDL,IDR=WARTOSC LUB NUMER STALEJ LUB ATS LEWEGO,PRAWEGO ARGUMENTU */
    sargmt_();
/*     WYBIERZ TYP POROWNANIA: INTEGER,REAL,REFERENCYJNY */
    switch (rlcase) {
	case 1:  goto L1000;
	case 2:  goto L3000;
	case 3:  goto L1000;
	case 4:  goto L1000;
	case 5:  goto L5000;
	case 6:  goto L5000;
    }

/* ..........INTEGER */


/*     STALE ARGUMENTY? */
L1000:
    switch (stos_1.arg) {
	case 1:  goto L1050;
	case 2:  goto L1200;
	case 3:  goto L1500;
	case 4:  goto L1300;
    }
/* .....OBA STALE,WYZNACZ WARTOSC RELACJI */
L1050:
    x = (real) (blank_1.idl - blank_1.idr);
    goto L3100;
/* .....LEWY STALY,PRAWY NIE. ZAMIEN. */
L1200:
    blank_1.objl = blank_1.idl;
    blank_1.idl = blank_1.idr;
    blank_1.idr = blank_1.objl;
    stos_1.wb = relconv[stos_1.wb - 3];
    goto L1500;
/* .....LEWY ROZNY OD STALEJ. */
/*     POROWNANIE */
L1300:
    rlcase = 103;
/*     ="POROWNANIE INTEGER"-3 */
    goto L1800;
/* .....PRAWY STALY,LEWY NIE. */
L1500:
    rlcase = 85;
/*     ="POROWNANIE ZE STALA"-3 */
/*     CZY Z ZEREM? */
    if (blank_1.idr == 0) {
	goto L3400;
    }
/*     NIE */

/* .....GENERUJ POROWNANIE 2-ARG. */
L1800:
    stos_1.result = tstemp_(&c__1);
    i__1 = rlcase + stos_1.wb;
    quadr4_(&i__1, &stos_1.result, &blank_1.idl, &blank_1.idr);
    goto L3200;


/* ..........POROWNANIE 2 ARGUMENTOW REAL */

L3000:
    rlcase = 122;
/*     ="POROWNANIE REAL"-3 */
/* dsw      GO TO (3050,3300,4000,1800),ARG */
/* dsw -------------------------- */
    switch (stos_1.arg) {
	case 1:  goto L3050;
	case 2:  goto L3700;
	case 3:  goto L4000;
	case 4:  goto L1800;
    }
/* dsw -------------------------- */
/* .....OBA STALE. WYZNACZ WARTOSC RELACJI */
/* dsw&bc 3050 X=STALER(IDL)-STALER(IDR) */
L3050:
    x = staler[blank_1.idl - 1] - staler[blank_1.idr - 1];

L3100:
    if (x < 0.f) {
	goto L3110;
    } else if (x == 0) {
	goto L3120;
    } else {
	goto L3130;
    }
/*      LEWY < PRAWY */
L3110:
    stos_1.result = rel[stos_1.wb - 3] & 1;
    goto L3150;
/*     LEWY = PRAWY */
L3120:
    stos_1.result = rel[stos_1.wb - 3] & 2;
    goto L3150;
/*     LEWY > PRAWY */
L3130:
    stos_1.result = rel[stos_1.wb - 3] & 4;
L3150:
    if (stos_1.result != 0) {
	stos_1.result = -1;
    }
/*     RESULT ZAWIERA REPREZENTACJE TRUE LUB FALSE */
    elem = 1;


/* .....ZASTAP OBA ARGUMENTY PRZEZ WYNIK TYPU BOOLEAN */


L3200:
    blank_1.treslt = blank_1.nrbool;
    sresult_(&elem);
    return 0;


/* .....LEWY STALY,PRAWY NIE. LEWY = 0.0 ? */
/* dsw3300 IF(STALER(IDL).NE. 0.0)GO TO 3700 */
/*     LEWY=0.0, ZAMIEN POROWNANIA */
/* dsw      WB=RELCONV(WB-2) */
/* dsw      IDL=IDR */
/* .....GENERUJ POROWNANIE 1-ARG. */
L3400:
    stos_1.result = tstemp_(&c__1);
    i__1 = stos_1.wb + 73;
    quadr3_(&i__1, &stos_1.result, &blank_1.idl);
/*     ZASTAP PRZEZ WARTOSC */
    goto L3200;
/* .....LEWY ARG. STALY<>0.0 ,WSTAW STALA */
L3700:
    blank_1.idl = screal_(&blank_1.idl);
    goto L1800;
/* .....PRAWY STALY,LEWY NIE. PRAWY = 0.0 ? */
/* dsw 4000 IF(STALER(IDR).EQ. 0.0)GO TO 3400 */
/*     NIE 0.0 , WSTAW STALA */
/* dsw ---------- added ------- */
L4000:
/* dsw ------------------------ */
    blank_1.idr = screal_(&blank_1.idr);
    goto L1800;




/* ..........REFERENCYJNE. */
L5000:
    switch (stos_1.arg) {
	case 1:  goto L5050;
	case 2:  goto L5200;
	case 3:  goto L5300;
	case 4:  goto L5600;
    }
/*     OBA NONE ,WSTAW TRUE DLA = , FALSE DLA <>   / -1 LUB 0 / */
L5050:
    elem = 1;
    stos_1.result = stos_1.wb - 4;
    goto L3200;
/* .....LEWY NONE,PRAWY NIE. ZAMIEN */
L5200:
    blank_1.idl = blank_1.idr;
/* .....PRAWY NONE,LEWY NIE */
L5300:
    stos_1.wb += 6;
    goto L3400;
/* .....OBA ROZNE OD NONE. ### BEZ DYNAMICZNEJ KONTROLI TYPOW ##### */
L5600:
    rlcase = 120;
/*     ="EQ REF"-3 */
    goto L1800;

/* .....RELACJA IS , IN */

/*     ZBADAJ TYP LEWEGO */
L7000:
    if (stack[stos_1.vlprev - 1] == 0) {
	goto L7100;
    }
    blank_1.tlbas = blank_1.ipmem[blank_1.tlbas - 1] & 15;
    if (blank_1.tlbas > 7 && blank_1.tlbas < 13 || blank_1.tldim > 0) {
	merr_(&c__475, &blank_1.idl);
    }
/*     ZBADAJ PRAWY : REKORD,KLASA? */
L7100:
    blank_1.idl = stack[stos_1.valtop - 1];
    if (blank_1.idl == 0) {
	goto L3200;
    }
    if (blank_1.idl == 8 || blank_1.idl == 9) {
	goto L7200;
    }
    serror_(&c__476);
    goto L3200;
/*     O.K.   LEWY=NONE ? */
L7200:
    if (stack[stos_1.vlprev - 1] == 1) {
	goto L7300;
    }
    elem = 2;
    stos_1.result = tstemp_(&c__1);
    i__1 = stos_1.wb + 54;
    quadr4_(&i__1, &stos_1.result, &stack[stos_1.vlprev - 3], &stack[
	    stos_1.valtop - 5]);
    goto L3200;
/*     LEWY=NONE : NONE IS -> FALSE , NONE IN -> TRUE */
L7300:
    elem = 1;
    stos_1.result = 1 - stos_1.wb;
    goto L3200;
} /* srelat_ */

#undef staler
#undef stack
#undef y
#undef m


/* Subroutine */ int snewarr_(void)
{
    /* Initialized data */

    static integer aux[4] = { -1,-3,0,-2 };

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, n;
    extern /* Subroutine */ int spop_(void);
#define stack ((integer *)&blank_1 + 302)
    extern integer sapet_(integer *, integer *), svats_(integer *);
    extern /* Subroutine */ int quadr2_(integer *, integer *), quadr4_(
	    integer *, integer *, integer *, integer *), serro2_(integer *, 
	    integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer sconst_(integer *), tstemp_(integer *);
    extern /* Subroutine */ int sstore_(integer *, integer *), serror_(
	    integer *), sindtyp_(void);

/* ----------------------------------------------------------------------------- */

/*     OBSLUGUJE GENERACJE TABLICY. */
/*     GORNE 3 ELEMENTY STOSU TO: ZMIENNA TABLICOWA,DOLNA GRANICA /UNIWERSALNY, */
/*      STALA,WARTOSC/,GORNA GRANICA /NA CZUBKU/. */
/*     ZDEJMUJE ZE STOSU 2 GORNE /1 ZOSTAWIA/,NIE WOLA SNEXT */


/*     ##### OUTPUT CODE : 23 , 132 ,145 . */

/*     ##### DETECTED ERROR(S) : 433 , 435 . */

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



/*     RUNNING-SYSTEM IDENTIFIERS OF ARRAY ELEMENTS : INTEGER,REAL,--,REFERENCE */


/* ..... */
    sindtyp_();
/*     STALE GRANICE? */
    if (stack[stos_1.valtop - 1] != 1 || stack[stos_1.vlprev - 1] != 1) {
	goto L60;
    }
/*     TAK. DOLNA < GORNA ? */
    if (stack[stos_1.vlprev - 3] > stack[stos_1.valtop - 3]) {
	i__1 = stos_1.vlprev - 9;
	serro2_(&c__433, &i__1);
    }
/* 	    NAZWA 3-GO OD GORY,2-GI MA APETYT 8 /STALA/ */
L60:
/*     WSTAW GRANICE GORNA,DOLNA */
    for (i__ = 1; i__ <= 2; ++i__) {
	i__1 = svats_(&stos_1.valtop);
	i__2 = i__ - 1;
	quadr4_(&c__145, &i__1, &c__1, &i__2);
/* 	WSTAW WARTOSC I-TEGO PARAMETRU */
/* 	PROCEDRA STANDARDOWA GENERACJI TABLICY MA NUMER 1 I PARAMETRY: */
/* 	  0 - UPPER ,1 - LOWER,2 - APETYT,3 - ADRES VIRT.NOWEJ TABLICY */
	spop_();
/* L100: */
    }
/*     OBIE GRANICE WSTAWIONE. NA CZUBKU ZMIENNA.TABLICOWA? */
    stos_1.lstlse = 0;
/*     IF(STACK(VALTOP).EQ.0)GO TO 30		NO GLOBAL JUMPS */
    if (stack[stos_1.valtop - 1] == 0) {
	return 0;
    }
    n = stack[stos_1.valtop - 4];
    if (n == 0) {
	goto L300;
    }
/*     O.K.   WSTAW APETYT */
    i__1 = n - 1;
    n = sapet_(&i__1, &stack[stos_1.valtop - 5]);
    n = aux[n - 1];
    i__1 = sconst_(&n);
    quadr4_(&c__145, &i__1, &c__1, &c__2);
    quadr2_(&c__132, &c__1);
/*     WYGENEROWANA NOWA TABLICA.ODCZYTAJ I WPISZ JEJ ADRES */
    n = tstemp_(&c__4);
    quadr4_(&c__23, &n, &c__1, &c__3);
    sstore_(&stos_1.valtop, &n);
    return 0;
/* .....ERROR: ZMIENNA NIE JEST TYPU TABLICOWEGO */
L300:
    serror_(&c__435);
    return 0;
} /* snewarr_ */

#undef staler
#undef stack


/* Subroutine */ int sresult_(integer *elem)
{
    /* Local variables */
    extern /* Subroutine */ int spop_(void);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int spush_(integer *);
#define staler ((real *)&blank_1 + 302)

/* ----------------------------------------------------------------------------- */

/*     POMOCNICZA. ZASTEPUJE 2 GORNE ELEMENTY STOSU PRZEZ ELEMENT */
/*     BEZ NAZWY TYPU ELEM. */
/*     JESLI TO NIE UNIWERSALNY,TO WSTAWIA TYP /0,TRESLT/, */
/*     ZERUJE SLOWO -5,DO SLOWA -2 WSTAWIA RESULT */
/*     UZYWANA DLA ZASTAPIENIA 2 ARGUMENTOW PRZEZ WYNIK /WARTOSC/ OPERACJI. */

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

    spop_();
    spop_();
    spush_(elem);
    stack[stos_1.valtop - 2] = 0;
    if (*elem == 0) {
	return 0;
    }
    stack[stos_1.valtop - 3] = stos_1.result;
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 5] = blank_1.treslt;
    stack[stos_1.valtop - 6] = 0;
    return 0;
} /* sresult_ */

#undef staler
#undef stack


/* Subroutine */ int sreslt1_(integer *type__)
{
    /* Local variables */
    extern /* Subroutine */ int spop_(void);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int spush_(integer *);
#define staler ((real *)&blank_1 + 302)

/* ----------------------------------------------------------------------- */

/*     ZASTEPUJE CZUBEK STOSU PRZEZ WARTOSC TYPU <0,TYPE> , */
/* 	BEZ NAZWY, DO SLOWA -2 WSTAWIA RESULT, ZERUJE SLOWA -5,-6 */


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


    spop_();
    spush_(&c__2);
    stack[stos_1.valtop - 2] = 0;
    stack[stos_1.valtop - 3] = stos_1.result;
    stack[stos_1.valtop - 4] = 0;
    stack[stos_1.valtop - 5] = *type__;
    stack[stos_1.valtop - 6] = 0;
    stack[stos_1.valtop - 7] = 0;
    return 0;
} /* sreslt1_ */

#undef staler
#undef stack


/* Subroutine */ int svaradr_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer n;
    extern /* Subroutine */ int spop_(void);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int spush_(integer *), quadr3_(integer *, integer 
	    *, integer *), quadr4_(integer *, integer *, integer *, integer *)
	    ;
#define staler ((real *)&blank_1 + 302)
    extern integer tstemp_(integer *), sarray_(integer *);
    extern /* Subroutine */ int serror_(integer *);
    extern integer smember_(integer *);

/* ---------------------------------------------------------------------- */

/*     SPRAWDZA,CZY CZUBEK STOSU ZAWIERA ZMIENNA /ZMIENNA PROSTA, */
/* 	ELEMENT TABLICY,TABLICA STATYCZNA/. */
/*     JESLI NIE, TO SYGNALIZUJE BLAD I ZASTEPUJE PRZEZ UNIWERSALNY. */
/*     GENERUJE KOD WYLICZAJACY ADRES FIZYCZNY ZMIENNEJ. */
/*     ATS WYLICZONEGO ADRESU ZWRACA NA ZMIENNA RESULT. */

/*     ##### OUTPUT CODE : 29 , 30 . */

/*     ##### DETECTED ERROR(S) : 420. */


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



    blank_1.idl = stack[stos_1.valtop - 1];
/*     = RODZAJ ELEMENTU */
    if (blank_1.idl == 0) {
	return 0;
    }
    if (blank_1.idl > 5) {
	goto L1000;
    }
    switch (blank_1.idl) {
	case 1:  goto L1000;
	case 2:  goto L1000;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
    }
/* .....ZMIENNA */
L300:
    n = stack[stos_1.valtop - 3];
    stos_1.result = tstemp_(&c__1);
/*     PRZEZ KROPKE ? */
    if (stack[stos_1.valtop - 8] == 0) {
	goto L350;
    }
/* ... ZMIENNA PRZEZ KROPKE */
    i__1 = smember_(&stos_1.valtop);
    quadr4_(&c__29, &stos_1.result, &i__1, &n);
    return 0;
/* ... ZMIENNA WIDOCZNA */
L350:
    quadr3_(&c__30, &stos_1.result, &n);
    return 0;
/* .....ELEMENT TABLICY */
L400:
    stos_1.result = sarray_(&stos_1.valtop);
    return 0;
/* .....TABLICA STATYCZNA */
L500:
/*     B R A K */
/* .....NIE ZMIENNA */
L1000:
    serror_(&c__420);
/*     ZASTAP PRZEZ UNIWERSALNY */
    spop_();
    spush_(&c__0);
    stack[stos_1.valtop - 2] = 0;
    return 0;
} /* svaradr_ */

#undef staler
#undef stack


/* Subroutine */ int sboolex_(integer *n)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer elem;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int quadr2_(integer *, integer *), quadr4_(
	    integer *, integer *, integer *, integer *), svalu2_(void), 
	    scheck_(integer *, integer *);
    static integer andopr;
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), sargmt_(void);
    extern integer tstemp_(integer *);
    extern /* Subroutine */ int sresult_(integer *);

/* ----------------------------------------------------------------------------- */

/*     OBSLUGUJE 2-ARGUMENTOWE OPERACJE BOOLOWSKIE /N=1 --> AND, */
/*      =0 --> OR / */
/*     2 GORNE ELEMENTY STOSU SA ARGUMENTAMI. */


/*     ##### OUTPUT CODE : 100 , 101 , 140 . */

/*     ##### DETECTED ERROR(S) : 417 . */

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

/* CCCCCCCCCCCCCCCCCCCCCC */
/*     SKOPIUJ PARAMETR */
    andopr = *n;
    svalu2_();
    svalue_();
/* .....USTAW TYP WYNIKU */
    blank_1.treslt = blank_1.nrbool;
/*     ZBADAJ TYPY,NAJPIERW PRAWEGO. */
    if (stack[stos_1.valtop - 1] != 0) {
	scheck_(&c__417, &blank_1.nrbool);
    }
/*     SPRAWDZ LEWY ARGUMENT */
    elem = 0;
    if (stack[stos_1.vlprev - 1] == 0) {
	goto L120;
    }
    blank_1.idr = stos_1.valtop;
    stos_1.valtop = stos_1.vlprev;
/*     TRICK */
    scheck_(&c__417, &blank_1.nrbool);
    stos_1.valtop = blank_1.idr;
    if (stack[stos_1.valtop - 1] == 0) {
	goto L120;
    }
/* .....ZATEM OBA ARGUMENTY O.K.	 ARGUMENY STALE? */
    sargmt_();
    switch (stos_1.arg) {
	case 1:  goto L170;
	case 2:  goto L130;
	case 3:  goto L160;
	case 4:  goto L100;
    }
/*     GENERUJ ZMIENNA ROBOCZA. */
L100:
    stos_1.result = tstemp_(&c__1);
    i__1 = andopr + 100;
    quadr4_(&i__1, &stos_1.result, &stack[stos_1.vlprev - 3], &stack[
	    stos_1.valtop - 3]);

L119:
    elem = 2;

/* .....ZASTAP PRZEZ WYNIK */

L120:
    sresult_(&elem);
    return 0;


/* .....LEWY ARGUMENT STALY,PRAWY NIE. */
/*     DALEJ BEDZIE: ELEM=ATS WARTOSCI LUB ZMIENNEJ, RESULT=WARTOSC STALEJ. */
L130:
    stos_1.result = stack[stos_1.vlprev - 3];
    elem = stack[stos_1.valtop - 3];
/* .....WSPOLNA AKCJA DLA 1 ARGUMENTU STALEGO. ELEM,RESULT - JAK WYZEJ. */
L140:
    if (andopr == 1 && stos_1.result == -1 || andopr == 0 && stos_1.result == 
	    0) {
	goto L150;
    }
/* .....AND,FALSE LUB OR,TRUE . */
/*     ZASTAP OBA WARTOSCIA RESULT, EWENT. GENERUJ NOP. */
    if (! option_1.optopt) {
	quadr2_(&c__140, &elem);
    }
    elem = 1;
    goto L120;
/* .....AND,TRUE LUB OR,FALSE. ZASTAP OBA PRZEZ ROZNY OD STALEJ ARGUMENT. */
L150:
    stos_1.result = elem;
    goto L119;
/* .....PRAWY STALY,LEWY NIE. */
L160:
    elem = stack[stos_1.vlprev - 3];
    stos_1.result = stack[stos_1.valtop - 3];
    goto L140;
/* .....0BA STALE */
L170:
    stos_1.result = 0;
    elem = stack[stos_1.valtop - 3] + stack[stos_1.vlprev - 3];
    if (andopr == 1 && elem == -2 || andopr == 0 && elem != 0) {
	stos_1.result = -1;
    }
    elem = 1;
    goto L120;
} /* sboolex_ */

#undef staler
#undef stack


/* Subroutine */ int sargmt_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* ----------------------------------------------------------------------- */

/*     POMOCNICZA. BADA,CZY 2 GORNE ELEMENTY STOSU SA STALYMI. */
/*     NADAJE ZMIENNEJ ARG WARTOSC : */
/* 	    1 - OBA STALE */
/* 	    2 - LEWY STALY,PRAWY NIE */
/* 	    3 - LEWY NIE,PRAWY STALY */
/* 	    4 - OBA ROZNE OD STALYCH */

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



    stos_1.arg = 1;
    if (stack[stos_1.valtop - 1] != 1) {
	stos_1.arg = 2;
    }
    if (stack[stos_1.vlprev - 1] != 1) {
	stos_1.arg += 2;
    }
    return 0;
} /* sargmt_ */

#undef staler
#undef stack


/* Subroutine */ int sindex_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int svalu2_(void), serro2_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int sindtyp_(void);

/* ----------------------------------------------------------------------------- */

/*     OBSLUGUJE KOLEJNY INDEKS DLA TABLICY DYNAMICZNEJ. */
/*     WOLANA PO WYSTAPIENIU "," LUB ")" */
/*     CZUBEK STOSU ZAWIERA INDEKS . */
/*     PONIZEJ ADRES TABLICY . */
/*     ZASTEPUJE 2 GORNE ELEMENTY STOSU PRZEZ  "ELEM.TABLICY"  . */



/*     ##### DETECTED ERROR(S) :  431 . */

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


/* .................. */
    svalu2_();
/*     SPRAWDZ TYP INDEKSU */
    sindtyp_();
    if (stack[stos_1.vlprev - 4] > 0) {
	goto L200;
    }
/*     ZA DUZO INDEKSOW */
    serro2_(&c__431, &stos_1.vlprev);
    goto L300;
/*     O.K. */
L200:
    --stack[stos_1.vlprev - 4];
/*     ZASTAP PRZEZ "ELEM.TABLICY" */
L300:
    stack[stos_1.vlprev - 1] = 4;
    stack[stos_1.vlprev - 8] = stack[stos_1.valtop - 3];
/*     WARTOSC INDEKSU. STALY? */
    if (stack[stos_1.valtop - 1] == 1) {
	stack[stos_1.vlprev - 3] = -stack[stos_1.vlprev - 3];
    }
    return 0;
} /* sindex_ */

#undef staler
#undef stack


/* Subroutine */ int sindtyp_(void)
{
    /* Local variables */
    static integer n;
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int svint_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void), serror_(integer *);

/* ---------------------------------------------------------------------- */

/*     POMOCNICZA. SPRAWDZA,CZY CZUBEK STOSU ZAWIERA ELEMENT */
/*     SPROWADZALNY DO WARTOSCI TYPU INTEGER. */
/*     WYLICZA WARTOSC CZUBKA STOSU,DOKONUJE EWENTUALNEJ KONWERSJI DO INTEGER */
/*     WOLANA PRZEZ PROCEDURY SINDEX,SINDXS DLA KONTROLI INDEKSU */

/*     ##### DETECTED ERROR(S) : 412 . */

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



    svalue_();
    if (stack[stos_1.valtop - 1] == 0) {
	return 0;
    }
/*     NIE UNIWERSALNY,SPRAWDZ TYP */
    n = stack[stos_1.valtop - 5];
    if (stack[stos_1.valtop - 4] > 0 || n != blank_1.nruniv && n != 
	    blank_1.nrint && n != blank_1.nrre) {
	goto L500;
    }
/*     O.K. */
    if (n == blank_1.nrre) {
	svint_(&stos_1.valtop);
    }
    return 0;
/* .....NIEPOPRAWNY TYP INDEKSU */
L500:
    serror_(&c__412);
    return 0;
} /* sindtyp_ */

#undef staler
#undef stack


/* Subroutine */ int sassign_(void)
{
    /* Local variables */
    static integer j, lse;
    extern /* Subroutine */ int spop_(void);
    static integer typl, typr;
#define stack ((integer *)&blank_1 + 302)
    static integer value;
    extern integer svats_(integer *);
    extern /* Subroutine */ int svint_(integer *), quadr3_(integer *, integer 
	    *, integer *), quadr4_(integer *, integer *, integer *, integer *)
	    ;
    extern integer screal_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int svalue_(void);
    extern integer msubst_(integer *), sconst_(integer *);
    extern /* Subroutine */ int svreal_(integer *);
    extern integer stypft_(integer *);
    extern /* Subroutine */ int sstore_(integer *, integer *);
    extern integer stypst_(integer *);

/* ----------------------------------------------------------------------------- */

/*     WERSJA 1982.02.12 */

/*     PROCEDURA OBSLUGUJE WIELOKROTNE PODSTAWIENIE. */
/*     WOLANA PRZEZ SDPDA PO POJAWIENIU SIE ASSIGN. */
/*     DOKONUJE KONTROLI TYPOW, GENERUJE KOD DYNAMICZNEJ KONTROLI */
/*     TYPOW I KONWERSJI ORAZ KOD NADAJACY WARTOSCI LEWYM STRONOM PODSTAWIENIA. */
/*     CZUBEK STOSU ZAWIERA PRAWA STRONE PODSTAWIENIA */
/*     PONIZEJ ,OD LSTFOR+1 DO LSTLSE ZNAJDUJA SIE LEWE STRONY PODSTAWIENIA */
/*    /UNIWERSALNY,ZMIENNA -MOZE BYC PRZEZ KROPKE-,ELEMTABLICY,TABL.STATYCZNA/. */
/*     WYROZNIA PRZYPADEK PODSTAWIENIA STALEJ REPREZENTOWANEJ PRZEZ ZERA. */

/*     OBNIZA STOS , USTAWIA LSTLSE. */


/*     ##### OUTPUT CODE :   150 , 170 . */



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


/* CCCCCCCCCCCCCCCCCCCC */
/*     TYPL,TYPR - ATS-Y TYPOW LEWEJ,PRAWEJ STRONY /DLA KONTROLI DYNAMICZNEJ/ */
/*     VALUE=ATS PRAWEJ STRONY LUB 0,GDY TO STALA REPREZENTOWANA PRZEZ ZERA */
/*     LSE=KOLEJNA LEWA STRONA */

/* ............................................ */
    svalue_();
/*     JESLI BRAK LEWYCH STRON LUB CZUBEK UNIWERSALNY-OBNIZ STOS */
    if (stack[stos_1.valtop - 1] == 0 || stos_1.lstlse <= stos_1.lstfor) {
	goto L1000;
    }
/*     CZUBEK NIE JEST UNIWERSALNY,SA LEWE STRONY. */

/* .....OBEJRZYJ PRAWA STRONE PODSTAWIENIA */
    typr = stack[stos_1.valtop - 6];
    typl = 0;
    value = svats_(&stos_1.valtop);

/* ................ KONIEC PRZYGOTOWAN.  WYKONAJ W PETLI PODSTAWIENIE. */

/* L400: */
    lse = stos_1.vlprev;

/* ....................POCZATEK PETLI DLA KOLEJNYCH LEWYCH STRON */
/*     LSE WSKAZUJE KOLEJNA LEWA STRONE */
L500:
    if (stack[lse - 1] == 0) {
	goto L900;
    }

/*     ZBADAJ POPRAWNOSC PODSTAWIENIA */
    blank_1.tldim = stack[lse - 4];
    blank_1.tlbas = stack[lse - 5];
    blank_1.objl = stack[lse - 7];
    blank_1.idl = stack[lse - 2];
    blank_1.trdim = stack[stos_1.valtop - 4];
    blank_1.trbas = stack[stos_1.valtop - 5];
    blank_1.objr = stack[stos_1.valtop - 7];
    j = msubst_(&c__1) + 1;
/*     KONTROLA DYNAMICZNA? */
    if (j >= 4 && option_1.opttyp) {
	goto L800;
    }
/*     KONWERSJA LUB KONTROLA DYNAMICZNA */
    switch (j) {
	case 1:  goto L800;
	case 2:  goto L610;
	case 3:  goto L620;
	case 4:  goto L630;
	case 5:  goto L640;
	case 6:  goto L650;
	case 7:  goto L660;
    }

/* .....INTEGER:=REAL */
L610:
    svint_(&stos_1.valtop);
    value = stack[stos_1.valtop - 3];
/*     JESLI STALA - WSTAW DO TABLICY SYMBOLI */
    if (stack[stos_1.valtop - 1] == 1) {
	value = sconst_(&value);
    }
    goto L800;

/* .....REAL:=INTEGER */
L620:
    svreal_(&stos_1.valtop);
    value = stack[stos_1.valtop - 3];
/*     JESLI STALA - WSTAW DO TABLICY SYMBOLI */
    if (stack[stos_1.valtop - 1] == 1) {
	value = screal_(&value);
    }
    goto L800;

/* .....OBIE STRONY ZNANEGO TYPU */
L630:
    quadr3_(&c__150, &value, &stack[lse - 5]);
    goto L800;

/* .....TYP LEWEJ FORMALNY,PRAWEJ ZNANY */
L640:
    if (typr == 0) {
	typr = stypst_(&stos_1.valtop);
    }
    goto L660;

/* .....TYP LEWEJ ZNANY,PRAWEJ FORMALNY */
L650:
    typl = stypst_(&lse);
    goto L700;

/* .....TYPY OBYDWU STRON FORMALNE */
L660:
    typl = stypft_(&lse);
    goto L700;


/* ..........KONTROLA DYNAMICZNA: TYPL,TYPR - TYPY LEWEJ,PRAWEJ STRONY */
L700:
    quadr4_(&c__170, &typl, &value, &typr);

/* .....WPISZ WARTOSC */

L800:
    sstore_(&lse, &value);
/* ....................ZAKONCZENIE PETLI: */
/*     CZY JEST KOLEJNE LSE? */
L900:
    j = stack[lse - 1];
    lse -= stos_1.stckap[j - 1];
    if (lse > stos_1.lstfor) {
	goto L500;
    }
/* .................... OBNIZANIE STOSU */
L1000:
L1020:
    spop_();
    if (stos_1.valtop > stos_1.lstfor) {
	goto L1020;
    }
    stos_1.lstlse = 0;
    return 0;
} /* sassign_ */

#undef staler
#undef stack


