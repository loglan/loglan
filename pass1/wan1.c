/* wan1.f -- translated by f2c (version 20090411).
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

union {
    struct {
	integer com[278], lmem, lpmem, irecn, isfin, lpmsys, lpml, lpmf, 
		nrint, nrre, nrbool, nrchr, nrcor, nrproc, nrtext, nruniv, 
		nattr, nrnone, nblsys, nblus, nempty;
	logical insys;
	integer local;
	logical own;
	integer object, ipmem[5000];
    } _1;
    struct {
	integer c0m[4], s, adres, k, scoma, sdot, semicol, scolon, sleft, 
		sright, sbecome, star, srelat, seof, sident, sconst, sand, 
		sarray, sarrof, sattach, sbegin, sblock, sbool, scall, scase, 
		sclass, sclose, scons, scopy, scorout, sdetach, sdim, sdo, 
		sdown, selse, send, sesac, sexit, sextern, sfi, sfor, sfunct, 
		sif, sinner, sinput, sint, skill, slock, snew, snone, snot, 
		sod, sor, sorif, sother, soutput, spref, sprcd, squa, sread, 
		sresume, sreturn, step, stop, staken, sthen, sthis, sto, 
		stype, sunit, svar, svirtual, swait, swhen, swhile, swrit, 
		swritln, strue, sall, wand, warray, wassign, wasscon, wattach,
		 wblock, wcall, wcase, wcasel, wcoma, wcnstb, wcnstc, wcnsti, 
		wcnstn, wcnstr, wcnst, wcopy, wdetach, wdot, wdownto, weof, 
		wesac, wfin, wfirst, wforend, wforvar, wfrom, wident, wiffals,
		 wiftrue, winner, winstrend, wjump, wkill, wlabel, wleft, 
		wlock, wlow, wlse, wnew, wnewarray, wnot, woperat, wopt, wor, 
		wother, wpref, wprim, wqua, wread, wrelat, wresume, wreturn, 
		wright, wstart, wstep, wstop, wthis, wto, wait, write, 
		writeln, wbound, unical, com[132], lmem, lpmem, irecn, isfin, 
		lpmsys, lpml, lpmf, nrint, nrre, nrbool, nrchar, nrcor, 
		nrproc, nrtext, nruniv, nattr, nrnone, nblsys, nblus, nempty, 
		insys, local, own, object, hash[8000], m, name__[10], nlast, 
		nl, keys[200], trans1[169]	/* was [13][13] */, trans2[
		169]	/* was [13][13] */, b0, b[70], skok0, skok[70], kk, 
		mm, stan, stan1, aux, k1, sy, sy1;
	real nu;
	integer exp__, sign, intpart, frac, okey;
	real fract;
	integer nb, tl, byte, text[20], top, in, nekst, stack[500], reszta[
		3652];
    } _2;
    struct {
	integer com[302], hash[8000], dow[13], keys[200], rest[2000];
    } _3;
    struct {
	integer c0m[4];
    } _4;
    struct {
	integer c0m[4], s, adres, k, scoma, sdot, semicol, scolon, sleft, 
		sright, sbecome, star, srelat, seof, sident, sconst, sand, 
		sarray, sarrof, sattach, sbegin, sblock, sbool, scall, scase, 
		sclass, sclose, scons, scopy, scorout, sdetach, sdim, sdo, 
		sdown, selse, send, sesac, sexit, sextern, sfi, sfor, sfunct, 
		sif, sinner, sinput, sint, skill, slock, snew, snone, snot, 
		sod, sor, sorif, sother, soutput, spref, sprcd, squa, sread, 
		sresume, sreturn, step, stop, staken, sthen, sthis, sto, 
		stype, sunit, svar, svirtual, swait, swhen, swhile, swrit, 
		swritln, strue, sall, wand, warray, wassign, wasscon, wattach,
		 wblock, wcall, wcase, wcasel, wcoma, wcnstb, wcnstc, wcnsti, 
		wcnstn, wcnstr, wcnst, wcopy, wdetach, wdot, wdownto, weof, 
		wesac, wfin, wfirst, wforend, wforvar, wfrom, wident, wiffals,
		 wiftrue, winner, winstrend, wjump, wkill, wlabel, wleft, 
		wlock, wlow, wlse, wnew, wnewarray, wnot, woperat, wopt, wor, 
		wother, wpref, wprim, wqua, wread, wrelat, wresume, wreturn, 
		wright, wstart, wstep, wstop, wthis, wto, wait, write, 
		writeln, wbound, unical, com[132], lmem, lpmem, irecn, isfin, 
		lpmsys, lpml, lpmf, nrint, nrre, nrbool, nrchar, nrcor, 
		nrproc, nrtext, nruniv, nattr, nrnone, nblsys, nblus, nempty, 
		insys, local, own, object, scaner[8735], top, in, next, stack[
		500], reszta[3652];
    } _5;
} blank_;

#define blank_1 (blank_._1)
#define blank_2 (blank_._2)
#define blank_3 (blank_._3)
#define blank_4 (blank_._4)
#define blank_5 (blank_._5)

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
    integer opt;
} option_;

#define option_1 option_

struct {
    char jfname[72];
    integer jf;
} jf_;

#define jf_1 jf_

struct {
    integer ind, length;
    shortint bigbuf[16000];
} combuf_;

#define combuf_1 combuf_

union {
    struct {
	logical errflg;
	integer line, ibuf2[265], buf[7], on, bufout[256], posit, recnr, next;
    } _1;
    struct {
	logical errflg;
	integer line, ibuf2[265], ibuf3[7], on, junk[259];
    } _2;
} stream_;

#define stream_1 (stream_._1)
#define stream_2 (stream_._2)

struct {
    integer outstr[265];
} listing_;

#define listing_1 listing_

union {
    struct {
	integer instr[265], bufor[85], lp, ln, max__, postr[265], status;
    } _1;
    struct {
	integer instr[265], bufor[85], lp, ln, max__, jnk[266];
    } _2;
} buff_;

#define buff_1 (buff_._1)
#define buff_2 (buff_._2)

/* Table of constant values */

static integer c__16 = 16;
static integer c__18 = 18;
static integer c__14 = 14;
static integer c__0 = 0;
static integer c__17 = 17;
static integer c__15 = 15;
static integer c__1 = 1;
static real c_b64 = 0.f;
static real c_b65 = 1.f;
static integer c__191 = 191;
static integer c__136 = 136;
static integer c__137 = 137;
static integer c__21 = 21;
static integer c__8000 = 8000;
static integer c__40 = 40;
static integer c__13 = 13;
static integer c__10 = 10;
static integer c__122 = 122;
static integer c_n1 = -1;
static integer c__4 = 4;
static integer c__107 = 107;
static integer c__2 = 2;
static integer c__109 = 109;
static integer c__3 = 3;
static integer c__126 = 126;
static integer c__115 = 115;
static integer c__101 = 101;
static integer c__5 = 5;
static integer c__6 = 6;

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
/* Subroutine */ int wan_(void)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int e0_(void), it1_(void), end_(void), inbr_(void)
	    , mess_(void), data1_(void), endbr_(void);


/* 	      COM    - OBSZAR KOMUNIKACYJNY STRUMIENI */
/* 	      LMEM   - (=32000) ROZMIAR CALEJ PAMIECI GLOWNEJ */
/* 	      LPMEM  - PODZIAL PAMIECI NA CZESCI  IPMEM  I  ISMEM */
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
/* 	      LOCAL  - FLAGA DOSTEPU DO OBIEKTOW - 2 JESLI OBIEKT */
/* 	  BYL LOKALNY, 1 - GDY Z SL, 0 - GDY Z BLOKU GLOWNEGO */
/* 	      OWN    - FLAGA DOSTEPU DO OBIEKTOW - .TRUE. JESLI OBIEKT NIE */
/* 		       POCHODZI Z PREFIKSOW (TYLKO Z WLASCIWEGO OBIEKTU) */
/* 	      OBJECT - PROTOTYP OBIEKTU, Z KTOREGO POCHODZIL OSTATNIO */
/* 		      SZUKANY IDENTYFIKATOR (OBIEKT POCHODZACY Z CIAGU SL) */

/* deb ----------- added ---------------------- */
/*  new common blockfor the debugger */
/*  deb = true - compilation with the debugger */
/*  breakt - array of static break points */
/*  brnr - index in breakt */
/*  maxbr - maximal number of static break points */
/* deb ---------------------------------------- */
/* dsw  DATA IDENT /4HWAN / */
/* dsw  MSG = IDENT */
    s_copy(mjlmsg_1.msg, "wan ", (ftnlen)4, (ftnlen)4);
    mjlmsg_1.ierc = 0;
    data1_();
/* deb */
    if (debug_1.deb) {
	inbr_();
    }
/* deb */
    e0_();
    option_1.opt = blank_1.com[1];
    end_();
/* deb */
    if (debug_1.deb) {
	endbr_();
    }
/* deb */
    mess_();
    it1_();
    return 0;
} /* wan_ */

/* Subroutine */ int data1_(void)
{
    /* Initialized data */

    static integer data1hex = 8224;

    /* System generated locals */
    integer i__1;
    char ch__1[1];

    /* Local variables */
    static integer i__;
#define w ((integer *)&blank_2 + 82)
    extern integer ord_(integer *);
    static integer iend;
    extern /* Subroutine */ int scan_(void), seek_(integer *, integer *), 
	    ffwrite_ints__(integer *, integer *, integer *);
    static integer begin;
    extern /* Subroutine */ int openf_(integer *, integer *), error_(integer *
	    );
    extern integer embede_(real *);
    extern /* Subroutine */ int readin_(void), ffopen_(integer *, char *, 
	    ftnlen), ffcreat_(integer *, char *, ftnlen), ffcrtmp_(integer *),
	     ffwrhex_(integer *, integer *);
    extern /* Character */ VOID int2char_(char *, ftnlen, integer *);


/*  OPENS FILES */

/* dsw   error !!!! */

/* deb ----------- added ---------------------- */
/*  new common blockfor the debugger */
/*  deb = true - compilation with the debugger */
/*  breakt - array of static break points */
/*  brnr - index in breakt */
/*  maxbr - maximal number of static break points */
/* deb ---------------------------------------- */
/* dsw   kod spacji ascii */
/* deb */
/*   nadanie wartosci zmiennej deb - czy zapalona opcja S */
    debug_1.deb = FALSE_;
    if (bit_test(blank_2.c0m[1],13)) {
	debug_1.deb = TRUE_;
    }
/* deb */
    for (i__ = 1; i__ <= 63; ++i__) {
/* L10: */
	w[i__ - 1] = i__;
    }
    blank_2.unical = 3;
/* --- */
/*   unit 16 - roboczy listing (sequential ) */
    ffcrtmp_(&c__16);
/* --- WRITE LISTING OPTION FLAG */
    ffwrhex_(&c__16, &blank_2.c0m[1]);
/* --- */
    stream_1.errflg = FALSE_;
/* dsw *********** new file ************** */
/*  unit 18 - roboczy,sekwencyjny do kodu posredniego */
    ffcrtmp_(&c__18);
/* ------   unit 14 (buf) - kod posredni (direct) */
    openf_(stream_1.buf, &c__14);
    stream_1.posit = 1;
/* dsw  RECNR=12 */
/* dsw  NEXT=13 */
    stream_1.recnr = 32;
    stream_1.next = 33;
    seek_(stream_1.buf, &stream_1.recnr);
/*     DATA BUFOR,LN,LP,MAX /85*4Z2020,0,81,81/ */
    buff_1.ln = 0;
    buff_1.lp = 81;
    buff_1.max__ = 81;
    for (jf_1.jf = 1; jf_1.jf <= 70; ++jf_1.jf) {
	if (*(unsigned char *)&jf_1.jfname[jf_1.jf - 1] == '.') {
	    goto L9998;
	}
	if (*(unsigned char *)&jf_1.jfname[jf_1.jf - 1] == ' ') {
	    goto L9996;
	}
/* L9997: */
    }
L9996:
    if (jf_1.jf + 4 > 70) {
	goto L9991;
    }
    *(unsigned char *)&jf_1.jfname[jf_1.jf - 1] = '.';
    *(unsigned char *)&jf_1.jfname[jf_1.jf] = 'l';
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 1] = 'o';
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 2] = 'g';
L9998:
    int2char_(ch__1, (ftnlen)1, &c__0);
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 3] = *(unsigned char *)&ch__1[0];
L9991:
    int2char_(ch__1, (ftnlen)1, &c__0);
    *(unsigned char *)&jf_1.jfname[69] = *(unsigned char *)&ch__1[0];
/*   unit 17 - input (sequential) */
    ffopen_(&c__17, jf_1.jfname, (ftnlen)1);
    combuf_1.length = 0;
    combuf_1.ind = 1;
    *(unsigned char *)&jf_1.jfname[jf_1.jf] = 'l';
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 1] = 'c';
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 2] = 'd';
    int2char_(ch__1, (ftnlen)1, &c__0);
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 3] = *(unsigned char *)&ch__1[0];
    ffcreat_(&c__15, jf_1.jfname, (ftnlen)1);
    buff_1.status = 0;
    for (i__ = 1; i__ <= 85; ++i__) {
/* L1: */
	buff_1.bufor[i__ - 1] = data1hex;
    }
    stream_1.on = 49;
    begin = 1;
    iend = 0;
L800:
    readin_();
    i__ = 1;
L900:
    i__1 = ' ';
    if (ord_(&buff_1.bufor[i__ - 1]) != ord_(&i__1)) {
	goto L1000;
    }
    ++i__;
    if (i__ > buff_1.max__) {
	goto L800;
    }
    goto L900;
L1000:
    if (buff_1.bufor[i__ - 1] != 'P' && buff_1.bufor[i__ - 1] != 'p') {
	goto L2500;
    }
    if (buff_1.bufor[i__] != 'R' && buff_1.bufor[i__] != 'r') {
	goto L2500;
    }
    if (buff_1.bufor[i__ + 1] != 'O' && buff_1.bufor[i__ + 1] != 'o') {
	goto L2500;
    }
    if (buff_1.bufor[i__ + 2] != 'G' && buff_1.bufor[i__ + 2] != 'g') {
	goto L2500;
    }
    if (buff_1.bufor[i__ + 3] != 'R' && buff_1.bufor[i__ + 3] != 'r') {
	goto L2500;
    }
    if (buff_1.bufor[i__ + 4] != 'A' && buff_1.bufor[i__ + 4] != 'a') {
	goto L2500;
    }
    if (buff_1.bufor[i__ + 5] != 'M' && buff_1.bufor[i__ + 5] != 'm') {
	goto L2500;
    }
    if (buff_1.bufor[i__ + 6] == 1) {
	goto L1100;
    }
    i__1 = ' ';
    if (ord_(&buff_1.bufor[i__ + 6]) != ord_(&i__1)) {
	goto L2500;
    }
L1100:
    i__ += 8;
    if (i__ < buff_1.max__) {
	goto L1200;
    }
L1150:
    readin_();
    i__ = 1;
L1200:
    i__1 = ' ';
    if (ord_(&buff_1.bufor[i__ - 1]) != ord_(&i__1)) {
	goto L1300;
    }
    ++i__;
    if (i__ > buff_1.max__) {
	goto L1150;
    }
    goto L1200;
L1300:
    begin = i__;
    iend = i__ - 1;
L1350:
    if (ord_(&buff_1.bufor[i__ - 1]) < 10 || ord_(&buff_1.bufor[i__ - 1]) > 
	    35) {
	goto L1500;
    }
L1400:
    ++i__;
    if (buff_1.bufor[i__ - 1] >= '0' && buff_1.bufor[i__ - 1] <= '9') {
	goto L1400;
    }
    goto L1350;
L1500:
    iend = i__ - 1;

/*   INITIALIZE STRINGS OUTPUT TO LFILE WITH EMPTY STRING */

L2500:
/* write length of empty string */
    ffwrite_ints__(&c__15, &c__0, &c__1);
/* write empty string itself */
    ffwrite_ints__(&c__15, &c__0, &c__1);
/* bc */

/*   INITIATE THE TABLE OF REAL CONSTANTS */
/*   THE TWO INITIAL CONSTANTS, WHICH ALWAYS RESIDE IN THE TABLE ARE */
/*   0.0 AND 1.0 */

    blank_2.exp__ = embede_(&c_b64);
    blank_2.exp__ = embede_(&c_b65);
    buff_1.lp = iend + 1;
    i__ = 0;
    if (iend < begin) {
	goto L3500;
    }
    blank_2.s = blank_2.sblock;
    goto L4000;
L3500:
    if (blank_2.s == 70) {
	error_(&c__191);
    }
L3550:
    scan_();
/* L3600: */
    if (blank_2.s == blank_2.sblock) {
	goto L4000;
    }
    i__ = 1;
    if (blank_2.s == blank_2.sbegin) {
	goto L4000;
    }
    if (blank_2.s == blank_2.sunit) {
	goto L4000;
    }
    if (blank_2.s == blank_2.svar) {
	goto L4000;
    }
    if (blank_2.s == blank_2.scons) {
	goto L4000;
    }
    if (blank_2.s == blank_2.send) {
	goto L4000;
    }
    if (blank_2.s == blank_2.sprcd) {
	goto L4000;
    }
    if (blank_2.s == blank_2.sfunct) {
	goto L4000;
    }
    if (blank_2.s == blank_2.sclass) {
	goto L4000;
    }
    if (blank_2.s == blank_2.sident) {
	goto L3550;
    }
    if (blank_2.s == blank_2.staken) {
	goto L4000;
    }
    if (blank_2.s == blank_2.sclose) {
	goto L4000;
    }
    if (blank_2.s < 25) {
	goto L4000;
    }
    if (blank_2.s != 70) {
	goto L3550;
    }
    error_(&c__136);
L4000:
    if (i__ == 1) {
	error_(&c__137);
    }
    return 0;
} /* data1_ */

#undef w


/* deb  new procedures */
/* Subroutine */ int inbr_(void)
{
    /* System generated locals */
    integer i__1;
    char ch__1[1];

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int ffcreat_(integer *, char *, ftnlen);
    extern /* Character */ VOID int2char_(char *, ftnlen, integer *);

/* deb ----------- added ---------------------- */
/*  new common blockfor the debugger */
/*  deb = true - compilation with the debugger */
/*  breakt - array of static break points */
/*  brnr - index in breakt */
/*  maxbr - maximal number of static break points */
/* deb ---------------------------------------- */
    debug_1.brnr = 0;
    debug_1.maxbr = 500;
    i__1 = debug_1.maxbr;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	debug_1.breakt[i__ - 1] = 0;
    }
/*  file na hash, breakt, keys */
    *(unsigned char *)&jf_1.jfname[jf_1.jf] = 'd';
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 1] = 'e';
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 2] = 'b';
    int2char_(ch__1, (ftnlen)1, &c__0);
    *(unsigned char *)&jf_1.jfname[jf_1.jf + 3] = *(unsigned char *)&ch__1[0];
    ffcreat_(&c__21, jf_1.jfname, (ftnlen)1);
    return 0;
} /* inbr_ */

/* Subroutine */ int addbr_(integer *l)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

/* deb ----------- added ---------------------- */
/*  new common blockfor the debugger */
/*  deb = true - compilation with the debugger */
/*  breakt - array of static break points */
/*  brnr - index in breakt */
/*  maxbr - maximal number of static break points */
/* deb ---------------------------------------- */
/*   wstawia do breakt linie o  numerze l */
    if (! debug_1.deb) {
	return 0;
    }
    i__1 = debug_1.brnr;
    for (i__ = 1; i__ <= i__1; ++i__) {
/*  czy juz jest */
	if (*l == debug_1.breakt[i__ - 1]) {
	    return 0;
	}
/* L100: */
    }
/*  nowy punkt lamiacy */
    if (debug_1.brnr >= debug_1.maxbr) {
	return 0;
    }
/*  nadmiarowe punkty lamiace sa ignorowane */
    ++debug_1.brnr;
    debug_1.breakt[debug_1.brnr - 1] = *l;
    return 0;
} /* addbr_ */

/* Subroutine */ int endbr_(void)
{
    extern /* Subroutine */ int ffwrite_ints__(integer *, integer *, integer *
	    );

/* deb ----------- added ---------------------- */
/*  new common blockfor the debugger */
/*  deb = true - compilation with the debugger */
/*  breakt - array of static break points */
/*  brnr - index in breakt */
/*  maxbr - maximal number of static break points */
/* deb ---------------------------------------- */
/*  wypisuje na plik 21 tablice hash */
    ffwrite_ints__(&c__21, blank_3.hash, &c__8000);
/* ps      call ffwrite_ints(21, keys, 200) */
/* ps      call ffwrite_ints(21, brnr, 1) */
/* ps      call ffwrite_ints(21, breakt, brnr) */
    return 0;
} /* endbr_ */

/* deb */
/* Subroutine */ int pend_(void)
{
    /* Initialized data */

    static struct {
	char e_1[40];
	integer fill_2[10];
	integer e_3;
	} equiv_0 = { "end of parsing -------------------------", {0}, 0 };


    /* System generated locals */
    char ch__1[1];

    /* Local variables */
    extern /* Subroutine */ int ffwrite_char__(integer *, char *, ftnlen);
#define endms1 ((char *)&equiv_0)
    extern /* Subroutine */ int readin_(void);
#define endmsg ((integer *)&equiv_0)
    extern /* Subroutine */ int ffwrite_(integer *, integer *, integer *), 
	    ffwrhex_(integer *, integer *);
    extern /* Character */ VOID int2char_(char *, ftnlen, integer *);

    ++buff_2.ln;
    ffwrhex_(&c__16, &buff_2.ln);

    if (bit_test(blank_4.c0m[1],15)) {
	goto L1;
    }
    ffwrite_char__(&c__16, "0", (ftnlen)1);

    goto L2;
L1:
    ffwrite_char__(&c__16, "1", (ftnlen)1);

L2:
    ffwrite_(&c__16, endmsg, &c__40);
/* end of line - write CR/LF */
    int2char_(ch__1, (ftnlen)1, &c__13);
    ffwrite_char__(&c__16, ch__1, (ftnlen)1);
    int2char_(ch__1, (ftnlen)1, &c__10);
    ffwrite_char__(&c__16, ch__1, (ftnlen)1);
L3:
    if (buff_2.bufor[0] == 2) {
	return 0;
    }
    readin_();
    goto L3;
} /* pend_ */

#undef endmsg
#undef endms1


/* Subroutine */ int e0_(void)
{
    extern /* Subroutine */ int e1_(void), e2_(void), e3_(void), e4_(void), 
	    e5_(void), e6_(void), e7_(void), e8_(void), e9_(void), e10_(void),
	     e11_(void), e12_(void), e13_(void), pend_(void), error_(integer *
	    ), output_(integer *, integer *);

/*  ORGANIZATION OF THE STACK: */
/*     STACK(TOP)   - STACK TOP FOR THE INVOKING MODULE */
/*     STACK(TOP+1) - NUMBER OF THE INVOKING MODULEY */
/*     STACK(TOP+2) - NUMBER OF THE RETURN POINT TO THE INVOKING MODULE */
/*  THE LOCAL VARIABLES, IF ANY ARE USED IN THE MODULE, ARE ALLOCATED ON THE */
/*  STACK STARTING FROM TOP+3 UP. */
/*  AN INVOKING MODULE HAS TO APPROPRIATELY INCREMENT THE TOP OF THE STACK */
/*  RESPECTING ITS LOCAL VARIABLES, THEN STORE ITS NUMBER AND RETURN POINT */
/*  ON THE STACK AND TRANSFER THE CONTROL TO THE SUPERVISING PROGRAM (RETURN). */
/*  AFTER RETURN FROM THE CALLED PROGRAM THE STACK TOP IS APPROPRIATELY */
/*  RESET BY THE SUPERVISING PROGRAM. */
/*  THE PATTERN OF TRANSFERRING CONTROL: */
/*     NEXT= N	-  CONTROL TO BE PASSED TO THE MODULE NUMBER N; */
/*     NEXT= 0	-  RETURN TO THE CALLER. */
/*  UPON ENTRY TO A SUBPROGRAM */
/*  PARAMETER - KEEPS THE NUMBER OF PLACE FROM WHICH THE COMPUTATIONS HAVE TO */
/*  BE CONTINUED */
/* dsw $	 SCANER(3735), */
    blank_5.stack[0] = 0;
    blank_5.stack[1] = 0;
    blank_5.stack[2] = 0;
    blank_5.top = 1;
/*  NOTE: THE FIRST CALL OF E11, I.E. FOR THE MAIN BLOCK, IS NON-STANDARD. */
/* 	 IN IS ASSIGNED VALUE 5 INSTEAD OF STANDARD (1). THIS FACILITATES */
/* 	 THE TEXT ANALYSIS OF A PROGRAM WHICH DOESN-T START WITH 'BLOCK'. */
    blank_5.in = 5;
    blank_5.next = 11;
    if (blank_5.s == 70) {
	goto L10025;
    }
    if (blank_5.s != blank_5.sblock) {
	error_(&c__122);
    }
    output_(&blank_5.wblock, &blank_5.isfin);
    blank_5.stack[blank_5.top + 3] = 0;
    goto L110;
/*   E11 IS CALLED WITH THE PARAMETER (TOP+4)=0, WHICH MEANS THAT NO PREFIX */
/*   IS SPECIFIED. E11 ANALYSES THE ENTIRE SYNTACTICAL UNIT. */
L10:
    e1_();
    goto L1000;
L20:
    e2_();
    goto L1000;
L30:
    e3_();
    goto L1000;
L40:
    e4_();
    goto L1000;
L50:
    e5_();
    goto L1000;
L60:
    e6_();
    goto L1000;
L70:
    e7_();
    goto L1000;
L80:
    e8_();
    goto L1000;
L90:
    e9_();
    goto L1000;
L100:
    e10_();
    goto L1000;
L110:
    e11_();
    goto L1000;
L120:
    e12_();
    goto L1000;
L130:
    e13_();
L1000:
    blank_5.in = 1;
    if (blank_5.next == 0) {
	goto L1002;
    }
L1001:
    switch (blank_5.next) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L70;
	case 8:  goto L80;
	case 9:  goto L90;
	case 10:  goto L100;
	case 11:  goto L110;
	case 12:  goto L120;
	case 13:  goto L130;
    }
L1002:
    blank_5.in = blank_5.stack[blank_5.top + 1];
    blank_5.next = blank_5.stack[blank_5.top];
    blank_5.top = blank_5.stack[blank_5.top - 1];
    if (blank_5.top > 0) {
	goto L1001;
    }
L10025:
    pend_();
    return 0;
} /* e0_ */

/* Subroutine */ int e1_(void)
{
    /* Initialized data */

    static integer seofsi = 60;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern /* Subroutine */ int slad_(integer *, integer *, integer *), scan_(
	    void), error_(integer *), output_(integer *, integer *);

/*  E1 - RECOGNIZES BOOLEAN EXPRESSION */
/*  LOCAL VARIABLES: */
/*    STACK(TOP+3) - NUMBER OF RECOGNIZED AND-S */
/*    STACK(TOP+4) - NUMBER OF RECOGNIZED OR-S */
/*    STACK(TOP+5) - RELATION CODE */
/*    STACK(TOP+6) - 1 IFF 'NOT' HAS BEEN ENCOUNTERED, 0 IN THE OPPOSITE CASE */
/* dsw $	 SCANER(3735) */
/* dsw  INTEGER WEOF0,WEOF1,WEOLN0,WEOLN1 */
/* dsw  DATA WEOF0,WEOF1,WEOLN0,WEOLN1/79,80,85,86/ */
    switch (blank_5.in) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
    }
L10:
    blank_5.stack[blank_5.top + 3] = 0;
L411:
    ++blank_5.stack[blank_5.top + 3];
    if (blank_5.stack[blank_5.top + 3] > 1) {
	scan_();
    }
    blank_5.stack[blank_5.top + 2] = 0;
L420:
    ++blank_5.stack[blank_5.top + 2];
    if (blank_5.stack[blank_5.top + 2] > 1) {
	scan_();
    }
    blank_5.stack[blank_5.top + 5] = 0;
    if (blank_5.s != blank_5.snot) {
	goto L400;
    }
    blank_5.stack[blank_5.top + 5] = 1;
    scan_();
L400:
    if (blank_5.s != blank_5.strue) {
	goto L401;
    }
/*  A BOOLEAN CONSTANT HAS BEEN ENCOUNTERED. ITS WRITING OUT IS SPLIT */
/*  INTO TWO STAGES BECAUSE THE VALUE TRUE (-1) CANNOT STAND FOR THE */
/*  SECOND PARAMETER OF THE WRITING PROCEDURE (OUTPUT). */
    output_(&blank_5.wcnstb, &c_n1);
    i__1 = 1 - blank_5.adres;
    output_(&i__1, &c_n1);
    scan_();
    goto L300;
L401:
    if (blank_5.s != seofsi) {
	goto L402;
    }
    if (blank_5.adres != 1) {
	blank_5.adres = 7;
    }
/*  79+7-1=85 */
    blank_5.stack[blank_5.top + 4] = seofsi + 18 + blank_5.adres;
    scan_();
    if (blank_5.s != blank_5.sleft) {
	goto L444;
    }
    ++blank_5.stack[blank_5.top + 4];
    scan_();
    slad_(&c__4, &c__1, &c__4);
    blank_5.next = 3;
    return 0;
/* CALL OBJECTEXPRESSION /E3/ */
L40:
    if (blank_5.s == blank_5.sright) {
	goto L430;
    }
    error_(&c__107);
    goto L444;
L430:
    scan_();
L444:
    output_(&blank_5.stack[blank_5.top + 4], &c_n1);
    goto L300;

L402:
    slad_(&c__4, &c__1, &c__2);
    blank_5.next = 2;
/*  CALL E2 - ARITHMETIC EXPRESSION */
    return 0;
L20:
    if (blank_5.s != blank_5.srelat) {
	goto L300;
    }
    if (blank_5.adres > 2) {
	goto L22;
    }
/*  RECOGNIZED RELATION IS OR IN */
    blank_5.stack[blank_5.top + 4] = blank_5.adres;
    scan_();
    if (blank_5.s == blank_5.scorout) {
	goto L205;
    }
    if (blank_5.s == blank_5.sident) {
	goto L21;
    }
    error_(&c__109);
    blank_5.adres = 0;
    goto L21;
L205:
    output_(&blank_5.wident, &blank_5.k);
/*  FOR "PROCESS", "COROUTINE" THE HASH ADDRESS IS PASSED BY K */
    goto L215;
L21:
    output_(&blank_5.wident, &blank_5.adres);
L215:
    scan_();
    output_(&blank_5.wrelat, &blank_5.stack[blank_5.top + 4]);
    goto L300;
L22:
    blank_5.stack[blank_5.top + 4] = blank_5.adres;
    scan_();
    slad_(&c__4, &c__1, &c__3);
    blank_5.next = 2;
/*  NEXT CALL FOR E2 - ARITHMETIC EXPRESSION */
    return 0;
L30:
    output_(&blank_5.wrelat, &blank_5.stack[blank_5.top + 4]);
L300:
    if (blank_5.stack[blank_5.top + 5] == 1) {
	output_(&blank_5.wnot, &c_n1);
    }
    if (blank_5.stack[blank_5.top + 2] > 1) {
	output_(&blank_5.wand, &c_n1);
    }
    if (blank_5.s == blank_5.sand) {
	goto L420;
    }
    if (blank_5.stack[blank_5.top + 3] > 1) {
	output_(&blank_5.wor, &c_n1);
    }
    if (blank_5.s == blank_5.sor) {
	goto L411;
    }
    blank_5.next = 0;
    return 0;
} /* e1_ */

/* Subroutine */ int e2_(void)
{
    /* Initialized data */

    static integer slowup = 79;
    static integer wlower = 64;
    static integer sign = 58;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern /* Subroutine */ int slad_(integer *, integer *, integer *), scan_(
	    void);
#define wsign ((integer *)&blank_5 + 102)
    extern /* Subroutine */ int error_(integer *), output_(integer *, integer 
	    *);


/*  E2 - RECOGNIZES ARITHMETIC EXPRESSION */
/*  LOKAL VARIABLES: */
/*    STACK(TOP+3) - MULTIPLICATIVE (HIGHER PRIORITY) OPERATOR */
/*    STACK(TOP+4) - ADDITIVE (LOWER PRIORITY) OPERATOR */
/*    STACK(TOP+5) - CONTAINS 1 IF SIGN CHANGE IS REQUIRED, 0 IF NOT, */
/*    STACK(TOP+6) - CONTAINS 1 IF "ABS" HAS OCCURRED, */
/*    STACK(TOP+7) - KEEPS LOWER/UPPER OPERATOR KIND, */
/*    STACK(TOP+8) - INCLUDES 1 IF THE VARIABLE AFTER LOWER/UPPER IS IN */
/* 		    PARANTHESES. */
/* 	     NOTE:  THE LAST TWO FIELDS ARE ONLY USED IF THE PERTINET */
/* 		    OPERATOR HAS BEEN ENCOUNTERED. THUS THIS PROCEDURE MAY */
/* 		    BE INVOKED WITH DIFFERENT SIZES OF THE AREA FOR LOCAL */
/* 		    VARIABLES, DEPENDING ON THE CONTENTS. */

/* dsw $	 SCANER(3735), */
/* ********************************************************************** */
/* ****** SLOWUP, WLOWER, WUPPER SHOUD BE PUT INTO BLANK */
/* ****** COMMON AT THE NEAREST OPPORTUNITY. */
/* ****** *********** 13.01.1982 ************* */
/* ********************************************************************** */
    switch (blank_5.in) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
    }

/*  INITIALIZE LOCAL VARIABLES */

L10:
    blank_5.stack[blank_5.top + 3] = 0;
    blank_5.stack[blank_5.top + 4] = 0;
    blank_5.stack[blank_5.top + 5] = 0;

/*  CHECK FOR MINUS (-) */

    if (blank_5.s != blank_5.star) {
	goto L100;
    }
    if (blank_5.adres > 4) {
	goto L80;
    }
    switch (blank_5.adres) {
	case 1:  goto L100;
	case 2:  goto L100;
	case 3:  goto L70;
	case 4:  goto L75;
    }

/*  THERE WAS MINUS */

L75:
    blank_5.stack[blank_5.top + 4] = 1;
    goto L90;

/*  PLUS (+) ENCOUNTERED */

L70:
    scan_();
    goto L100;

/*  THE EXPRESSION STARTS WITH * , / , DIV , MOD */

L80:
    error_(&c__126);
L90:
    scan_();
L100:
    blank_5.stack[blank_5.top + 2] = 0;

/*  START OF ANALYSING A SUM COMPONENT */

L110:
    if (blank_5.stack[blank_5.top + 3] != 0) {
	scan_();
    }

/*  START OF ANALYSING A MULTIPLICATIVE COMPONENT */

L120:
    if (blank_5.stack[blank_5.top + 2] != 0) {
	scan_();
    }

/*  CHECK FOR ABS */

    if (blank_5.s != blank_5.star) {
	goto L122;
    }
    if (blank_5.adres != 1) {
	goto L122;
    }

/*  ABS ENCOUNTERED */

    blank_5.stack[blank_5.top + 5] = 1;
    scan_();

/*  CHECK FOR A CONSTANT, IF AFFIRMATIVE THEN RECOGNIZE ITS TYPE */

L122:
    if (blank_5.s != blank_5.sconst) {
	goto L130;
    }
    switch (blank_5.k) {
	case 1:  goto L210;
	case 2:  goto L210;
	case 3:  goto L125;
	case 4:  goto L127;
	case 5:  goto L123;
	case 6:  goto L128;
    }

/*  REAL CONSTANT */

L123:
    output_(&blank_5.wcnstr, &blank_5.adres);
    scan_();
    goto L180;

/*  INTEGER CONSTANT */

L125:
    output_(&blank_5.wcnsti, &blank_5.adres);
    scan_();
    goto L180;

/*  STRING CONSTANT */

L127:
    output_(&blank_5.wcnst, &blank_5.adres);
    goto L129;

/*  CHARACTER CONSTANT */

L128:
    output_(&blank_5.wcnstc, &blank_5.adres);
L129:
    scan_();

/*  CHECK AGAINST AN OCCURRENCE OF A STRING/CHAR CONSTANT WITHIN AN EXPRESSION */

    if (blank_5.stack[blank_5.top + 2] + blank_5.stack[blank_5.top + 3] + 
	    blank_5.stack[blank_5.top + 4] + blank_5.stack[blank_5.top + 5] !=
	     0) {
	error_(&c__115);
    }
    goto L210;

/*  CHECK IF THE MULTIPLICATIVE COMPONENT IS AN EXPRESSION */

L130:
    if (blank_5.s != blank_5.sleft) {
	goto L160;
    }
    scan_();
    slad_(&c__4, &c__2, &c__2);
    blank_5.next = 1;
    return 0;

/*  CALL E1 - BOOLEAN EXPRESSION */
/*  AFTER RETURN CHECK IF THE EXPRESSION IS TERMINATED BY THEW RIGHT */
/*  PARANTHESIS */

L20:
    if (blank_5.s == blank_5.sright) {
	goto L140;
    }
    error_(&c__101);
    goto L180;
L140:
    scan_();
    goto L180;
L160:
    if (blank_5.s == slowup) {
	goto L170;
    }
    if (blank_5.s == sign) {
	goto L165;
    }
    slad_(&c__4, &c__2, &c__3);
    blank_5.next = 3;

/*  CALL E3 - OBJECTEXPRESSION TO ANALYSE THE VARIABLE */
/*  RETURN TO LABEL 30 BELOW - JUMP OPTIMIZATION */

    return 0;

/*  "SIGN" ENCOUNTERED, ARITHMETIC EXPRESSION SHOULD FOLOW. */

L165:
    scan_();
    slad_(&c__5, &c__2, &c__5);
    blank_5.next = 1;
    return 0;

/*  CALL E1 TO ANALYSE THE EXPRESSION */

L50:
    output_(wsign, &c_n1);
    goto L180;

/*  LOWER/UPPER HAS BEEN ENCOUNTERED. WE HAVE TO REMEMBER WHICH ONE AND CALL */
/*  OBJECTEXPRESSION TO ANALYSE THE VARIABLE. THE LOCAL VARIABLE FIELD IS */
/*  INCREASED TO 5 VARIABLES. */

L170:
    blank_5.stack[blank_5.top + 6] = blank_5.adres;
    scan_();
    blank_5.stack[blank_5.top + 7] = 0;
    if (blank_5.s != blank_5.sleft) {
	goto L172;
    }
/* 				       THERE WAS A LEFT PARANTHESIS */
    blank_5.stack[blank_5.top + 7] = 1;
    scan_();
L172:
    slad_(&c__6, &c__2, &c__4);
    blank_5.next = 3;
    return 0;
/*  CALL E3 - OBJECT EXPRESSION, AFTER RETURN THE OPERATOR TYPE */
/*  (LOWER/UPPER) IS TO BE WRITTEN */
L40:
    i__1 = wlower + blank_5.stack[blank_5.top + 6] - 1;
    output_(&i__1, &c_n1);
    if (blank_5.stack[blank_5.top + 7] == 0) {
	goto L30;
    }
    if (blank_5.s == blank_5.sright) {
	goto L44;
    }
/* 				      NO MATCHING RIGHT PARANTHESIS */
    error_(&c__101);
    goto L30;
L44:
    scan_();
L30:
L180:
    if (blank_5.stack[blank_5.top + 5] != 1) {
	goto L185;
    }

/*  ABS BEFORE THE MULTIPLICATIVE COMPONENT */

    output_(&blank_5.woperat, &c__1);
    blank_5.stack[blank_5.top + 5] = 0;
L185:
    if (blank_5.stack[blank_5.top + 4] != 1) {
	goto L190;
    }

/*  MINUS BEFORE THE MULTIPLICATIVE COMPONENT */

    output_(&blank_5.woperat, &c__2);
    blank_5.stack[blank_5.top + 4] = 0;
L190:
    if (blank_5.stack[blank_5.top + 2] != 0) {
	output_(&blank_5.woperat, &blank_5.stack[blank_5.top + 2]);
    }
    blank_5.stack[blank_5.top + 2] = 0;

/*  AND OF THE ANALYSIS OF THE COMPONENT, CHECK WHETHER MORE COMPONENTS ARE */
/*  EXPECTED, E.G. IF THERE OCCURRS * , / , DIV , MOD */

    if (blank_5.s != blank_5.star) {
	goto L200;
    }
    if (blank_5.adres < 5) {
	goto L200;
    }
    blank_5.stack[blank_5.top + 2] = blank_5.adres;
    goto L120;

/*  END OF MULTIPLICATIVE SEQUENCE */

L200:
    if (blank_5.stack[blank_5.top + 3] != 0) {
	output_(&blank_5.woperat, &blank_5.stack[blank_5.top + 3]);
    }
    blank_5.stack[blank_5.top + 3] = 0;

/*  END OF AN ADDITIVE COMPONENT, CHECK FOR MORE (+,-) */

    if (blank_5.s != blank_5.star) {
	goto L210;
    }
    if (blank_5.adres < 3) {
	goto L210;
    }
    blank_5.stack[blank_5.top + 3] = blank_5.adres;
    goto L110;

/*  END OF ADDITIVE SEQUENCE */

L210:
    blank_5.next = 0;
    return 0;
} /* e2_ */

#undef wsign


