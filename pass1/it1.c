/* it1.f -- translated by f2c (version 20090411).
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
    logical errflg;
    integer line, ibuf2[265], ibuf3[7], junk[260];
} stream_;

#define stream_1 stream_

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
	integer com[278], lmem, lpmem, irecn, isfin, lpmsys, lpml, lpmf, 
		nrint, nrre, nrbool, nrchr, nrcor, nrproc, nrtext, nruniv, 
		nattr, nrnone, nblsys, nblus, nempty;
	logical insys;
	integer local;
	logical own;
	integer object, hash[8000];
    } _2;
} blank_;

#define blank_1 (blank_._1)
#define blank_2 (blank_._2)

struct {
    integer ierc;
    char msg[4];
} mjlmsg_;

#define mjlmsg_1 mjlmsg_

struct {
    logical syspp;
} sysppc_;

#define sysppc_1 sysppc_

struct {
    logical deb;
    integer breakt[500], brnr, maxbr;
} debug_;

#define debug_1 debug_

struct {
    integer intnm, renm, boolnm, chrnm, cornm, procnm, textnm, filenm;
} hnames_;

#define hnames_1 hnames_

struct {
    integer opt;
} option_;

#define option_1 option_

struct {
    integer lprefs;
} prefs_;

#define prefs_1 prefs_

struct {
    integer prgraph, prmouse;
} syspro_;

#define syspro_1 syspro_

struct {
    integer slist, elist, snumb, ilt, zfirst, inord, outord;
} tc_;

#define tc_1 tc_

/* Table of constant values */

static integer c__6 = 6;
static integer c__10 = 10;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__41 = 41;
static integer c__9 = 9;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__21 = 21;
static integer c__4 = 4;
static integer c__2613 = 2613;
static integer c_n1 = -1;
static integer c__335 = 335;
static integer c_n2 = -2;
static integer c__307 = 307;
static integer c_n3 = -3;
static integer c__2605 = 2605;
static integer c_n4 = -4;
static integer c__2589 = 2589;
static integer c__15 = 15;
static integer c__2599 = 2599;
static integer c__12 = 12;
static integer c__1731 = 1731;
static integer c__13 = 13;
static integer c__1619 = 1619;
static integer c__14 = 14;
static integer c__1487 = 1487;
static integer c__16 = 16;
static integer c__2571 = 2571;
static integer c_n5 = -5;
static integer c__2575 = 2575;
static integer c_n6 = -6;
static integer c__2563 = 2563;
static integer c__23 = 23;
static integer c__2559 = 2559;
static integer c__24 = 24;
static integer c__2555 = 2555;
static integer c__25 = 25;
static integer c__2551 = 2551;
static integer c__26 = 26;
static integer c__717 = 717;
static integer c__27 = 27;
static integer c__2547 = 2547;
static integer c__28 = 28;
static integer c__331 = 331;
static integer c__19 = 19;
static integer c__2521 = 2521;
static integer c__2515 = 2515;
static integer c__20 = 20;
static integer c__2511 = 2511;
static integer c__22 = 22;
static integer c__237 = 237;
static integer c_n7 = -7;
static integer c__1203 = 1203;
static integer c__18 = 18;
static integer c__2483 = 2483;
static integer c__29 = 29;
static integer c__2375 = 2375;
static integer c__30 = 30;
static integer c__2369 = 2369;
static integer c__31 = 31;
static integer c__1105 = 1105;
static integer c__32 = 32;
static integer c__1685 = 1685;
static integer c__36 = 36;
static integer c__2357 = 2357;
static integer c__37 = 37;
static integer c__2247 = 2247;
static integer c__11 = 11;
static integer c__2253 = 2253;
static integer c__78 = 78;
static integer c__2259 = 2259;
static integer c__79 = 79;
static integer c__2087 = 2087;
static integer c__80 = 80;
static integer c__2091 = 2091;
static integer c__81 = 81;
static integer c__2023 = 2023;
static integer c__84 = 84;
static integer c__7847 = 7847;
static integer c__98 = 98;
static integer c__2101 = 2101;
static integer c__99 = 99;
static integer c__7759 = 7759;
static integer c__150 = 150;
static integer c__7739 = 7739;
static integer c__151 = 151;
static integer c__7747 = 7747;
static integer c__152 = 152;
static integer c__7753 = 7753;
static integer c__153 = 153;
static integer c__7731 = 7731;
static integer c__154 = 154;
static integer c__323 = 323;
static integer c__5 = 5;
static integer c__8 = 8;
static integer c__85 = 85;
static integer c__100 = 100;
static integer c__2273 = 2273;
static integer c__101 = 101;
static integer c__2335 = 2335;
static integer c__102 = 102;
static integer c__1231 = 1231;
static integer c__103 = 103;
static integer c__2279 = 2279;
static integer c__104 = 104;
static integer c__1719 = 1719;
static integer c__105 = 105;
static integer c__189 = 189;
static integer c__106 = 106;
static integer c__2237 = 2237;
static integer c__107 = 107;
static integer c__2231 = 2231;
static integer c__108 = 108;
static integer c__2225 = 2225;
static integer c__109 = 109;
static integer c__2219 = 2219;
static integer c__110 = 110;
static integer c__2213 = 2213;
static integer c__111 = 111;
static integer c__2207 = 2207;
static integer c__112 = 112;
static integer c__2201 = 2201;
static integer c__113 = 113;
static integer c__2195 = 2195;
static integer c__114 = 114;
static integer c__209 = 209;
static integer c__115 = 115;
static integer c__2029 = 2029;
static integer c__116 = 116;
static integer c__2185 = 2185;
static integer c__117 = 117;
static integer c__2179 = 2179;
static integer c__118 = 118;
static integer c__2173 = 2173;
static integer c__119 = 119;
static integer c__2167 = 2167;
static integer c__120 = 120;
static integer c__2161 = 2161;
static integer c__121 = 121;
static integer c__2155 = 2155;
static integer c__122 = 122;
static integer c__2149 = 2149;
static integer c__123 = 123;
static integer c__2143 = 2143;
static integer c__124 = 124;
static integer c__2137 = 2137;
static integer c__125 = 125;
static integer c__2131 = 2131;
static integer c__126 = 126;
static integer c__2299 = 2299;
static integer c__127 = 127;
static integer c__2293 = 2293;
static integer c__128 = 128;
static integer c__2125 = 2125;
static integer c__129 = 129;
static integer c__2119 = 2119;
static integer c__130 = 130;
static integer c__2113 = 2113;
static integer c__131 = 131;
static integer c__1573 = 1573;
static integer c__132 = 132;
static integer c__7991 = 7991;
static integer c__7 = 7;
static integer c__7985 = 7985;
static integer c__200 = 200;
static integer c__1601 = 1601;
static integer c__201 = 201;
static integer c__7973 = 7973;
static integer c__202 = 202;
static integer c__7963 = 7963;
static integer c__203 = 203;
static integer c__7957 = 7957;
static integer c__204 = 204;
static integer c__7945 = 7945;
static integer c__205 = 205;
static integer c__7937 = 7937;
static integer c__206 = 206;
static integer c__7887 = 7887;
static integer c__207 = 207;
static integer c__7917 = 7917;
static integer c__210 = 210;
static integer c__7907 = 7907;
static integer c__211 = 211;
static integer c__7895 = 7895;
static integer c__215 = 215;
static integer c__7927 = 7927;
static integer c__216 = 216;
static integer c__7877 = 7877;
static integer c__219 = 219;
static integer c__987 = 987;
static integer c__1635 = 1635;
static integer c__2319 = 2319;
static integer c__1305 = 1305;
static integer c__827 = 827;
static integer c__2311 = 2311;
static integer c__1995 = 1995;
static integer c__2069 = 2069;
static integer c__2061 = 2061;
static integer c__33 = 33;
static integer c__2469 = 2469;
static integer c__1609 = 1609;
static integer c__2477 = 2477;
static integer c__2431 = 2431;
static integer c__2437 = 2437;
static integer c__2443 = 2443;
static integer c__2449 = 2449;
static integer c__2457 = 2457;
static integer c__1325 = 1325;
static integer c__2393 = 2393;
static integer c__835 = 835;
static integer c__1837 = 1837;
static integer c__2405 = 2405;
static integer c__2413 = 2413;
static integer c__2419 = 2419;
static integer c__2421 = 2421;
static integer c__2425 = 2425;
static integer c__398 = 398;
static integer c__399 = 399;

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
/* Subroutine */ int it1_(void)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int ts1_(void), dsw_(void), init_(void), tord_(
	    integer *), mess_(void);
    static integer prot;
    extern /* Subroutine */ int apars_(void), mppmes_(void);

/* --------------LACZNIK 1------------------------------- */
/*             - PRZESYLA CZESC INFORMACJI ZE SCANNERA NA PLIKI */
/*             - INICJUJE ZMIENNE DLA POTRZEB ANALIZY DEKLARACJI */
/*               I POZNIEJSZYCH PRZEBIEGOW */
/*             - SORTUJE TOPOLOGICZNIE DEKLARACJE TYPOW */

/*             OPIS W DOKUMENTACJI:       D.I.2 */
/*             WERSJA Z DNIA:             19.01.82 */
/*             DLUGOSC KODU:       116 */
/* ........................................................... */

/*     INSERTION OF */
/*     BECAUSE OF TYPECONFLICT    03.01.84 */
/* + */
/* - */
/* ALL STREAM */
/* ALL BLANK */
/* ALL # */
/* dsw  COMMON /SYSPP/ SYSPP */
/* deb ----------- added ---------------------- */
/*  new common blockfor the debugger */
/*  deb = true - compilation with the debugger */
/*  breakt - array of static break points */
/*  brnr - index in breakt */
/*  maxbr - maximal number of static break points */
/* deb ---------------------------------------- */

/* dsw  DATA IDENT /4HIT1 / */

    mjlmsg_1.ierc = 0;
    s_copy(mjlmsg_1.msg, "it1 ", (ftnlen)4, (ftnlen)4);
/*    ---ZBADANIE, CZY MA BYC DZIALANIE W OTOCZENIU SYSPP */
    sysppc_1.syspp = bit_test(blank_1.com[2],14);
/* *********** SCIAGNIECIE BUFOROW PLIKOW */
/* --- BUFFERS NEED NOT BE FETCHED IN THE 'ONE-OVERLAY' VERSION */
/*     CALL  MGTBUF */
    blank_1.nempty = 0;
    apars_();
/* *********** INICJALIZACJA ZMIENNYCH GLOBALNYCH */
    blank_1.ipmem[blank_1.isfin - 9] = blank_1.com[1];
    blank_1.lpmf = blank_1.isfin - 9;

    blank_1.lpml = 1;
    blank_1.com[3] = blank_1.lpmem;
    blank_1.insys = TRUE_;
/* *********** INICJALIZACJA PROTOTYPOW SYSTEMOWYCH */
    init_();
/* *********** SORTOWANIE TOPOLOGICZNE TYPOW */
    i__ = blank_1.lpmem;
/* ...........POBRANIE ELEMENTU ZE SLOWNIKA */
L100:
    prot = blank_1.ipmem[i__ - 1];
/*     ... PROT - PROTOTYP, KTOREGO DEKLARACJE SA SORTOWANE */
    if (prot != 0) {
	tord_(&prot);
    }
    --i__;
    if (i__ >= blank_1.isfin) {
	goto L100;
    }
/* ************ PRZESLANIE BUFOROW */
/* --- BUFFERS NEED NOT BE SENT IN THE 'ONE-OVERLAY' VERSION */
/*     CALL  MPTBUF */
    mess_();
    if (sysppc_1.syspp) {
	mppmes_();
    }
/* deb      CALL DSW */
/* deb ------------- added --------------- */
    if (debug_1.deb && ! stream_1.errflg) {
	goto L1000;
    }
    dsw_();
    return 0;
L1000:
    ts1_();
/* deb ----------------------------------- */
    return 0;
} /* it1_ */

/* Subroutine */ int mppmes_(void)
{
    extern /* Subroutine */ int ffputspaces_(integer *, integer *), ffputcs_(
	    integer *, char *, ftnlen), ffputnl_(integer *);

/* ------------------DRUKUJE INFORMACJE O PRZYLACZENIU BIBLIOTEKI SYSPP */
/* ALL STREAM */
/* ALL # */
    ffputspaces_(&c__6, &c__10);
    ffputcs_(&c__6, "-- SYSPP LIBRARY ADDED", (ftnlen)22);
    ffputnl_(&c__6);
    return 0;
} /* mppmes_ */

/* Subroutine */ int apars_(void)
{
    static integer i__;
    extern /* Subroutine */ int put_(integer *, integer *), seek_(integer *, 
	    integer *);

/* ---------------PRZESYLA TABLICE HASH-U SCANNERA NA STRUMIEN SC */
/*               DO POCZATKOWYCH BLOKOW */

/*             OPIS W DOKUMENTACJI:         D.I.3 */
/*             WERSJA Z DNIA:               19.01.82 */
/*             DLUGOSC KODU:        338 */
/* ............................................................. */

/* ALL BLANK */
/* dsw X        IPMEM(5000) */
/* ALL STREAM */
/* ALL # */

/* ------PRZEWINIECIE STRUMIENIA  SC */
    seek_(stream_1.ibuf3, &c__0);
/* ------PRZEPISANIE BLOKOW TWORZACYCH TABLICE HASH-U */
/* dsw  ---------------------- */
/*  dodane przepisywanie tablicy hash2 */
    for (i__ = 1; i__ <= 8000; i__ += 256) {
	put_(stream_1.ibuf3, &blank_2.hash[i__ - 1]);
/* L100: */
    }
    return 0;
} /* apars_ */

/* Subroutine */ int init_(void)
{
    /* Initialized data */

    static integer inhex7 = 12;
    static integer inhex8 = 4;
    static integer inhex9 = -16370;
    static integer inhx10 = -32687;
    static integer inhx11 = -32671;
    static integer inhx12 = 81;
    static integer inhx13 = 97;
    static integer inhx14 = -16287;
    static integer inhx15 = -16303;
    static integer xx = 4;
    static integer inhx16 = 145;
    static integer inhx17 = 32913;
    static integer inhx18 = 49297;
    static integer inhex1 = 8;
    static integer inhex2 = -32760;
    static integer inhex3 = 10;
    static integer inhex4 = 11;
    static integer inhex5 = -16377;
    static integer inhex6 = -16379;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, mousepref, fpl1, fpl2, fpl3, fpl4, fpl5, fpl6, fpl7, 
	    fpl8, fpl9, fpl10, fpl11, fpl12, fpl13, fpl14, fpl15, fpl16, 
	    fpl22, fpl18, inpf, fpl23, inpi, fpl30, fpl31, inpr, toto, wrds1, 
	    wrds2, toto2, toto3, toto4, toto5, toto6, toto7, toto8, inpch;
    extern integer mgetm_(integer *, integer *);
    extern /* Subroutine */ int msetb_(integer *, integer *);
    static integer outpb, inoui, outpi, inour, inptx;
    extern /* Subroutine */ int mlspp_(void);
    static integer outpr, nrfile, inpari, outach;
    extern integer mstacl_(integer *, integer *);
    static integer grpref;
    extern /* Subroutine */ int mstafp_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), mstasg_(
	    integer *, integer *, integer *);
    static integer outpch, outari;
    extern integer insert_(integer *, integer *, integer *);
    static integer inparch, inouari;

/* --------------INICJALIZACJA PROTOTYPOW SYSTEMOWYCH */

/*             OPIS W DOKUMENTACJI:             D.I.4 */
/*             WERSJA Z DNIA:                   19.01.82 */
/*             DLUGOSC KODU:        1079 */
/* ............................................................... */

/* ALL BLANK */
/* ALL # */
/* dsw  COMMON /SYSPP/ SYSPP */

/* .....NAZWY HASH-U ZE SCANNERA */
/* #F */

/*  lprefs - ostatnio przydzielony numer w prefixset */
/*  grpref - numer prefiksu klasy IIUWGRAPH */
/*  mousepref - numer prefiksu klasy MOUSE */
/*  system class prototypes: */
/*  prgraph - prototype of IIUWGRAPH */
/*  prmouse - prototype of MOUSE */
/* dsw  DATA INTNM,RENM,BOOLNM,CHRNM,CORNM,PROCNM,TEXTNM,FILENM */
/* dsw X /24,40,8,16,2919,2785,48,56/ */
/* NATTR - ATRYBUT "-1" (1 SLOWO, 2 DOMYSLNE) */
/* dsw  DATA    INHEX1,INHEX2,INHEX3,INHEX4,INHEX5,INHEX6,INHEX7,INHEX8, */
/* dsw XINHEX9,INHEX10,INHEX11,INHEX12,INHEX13,INHEX14,INHEX15,XX */
/* dsw X/Z0008,Z8008,Z000A,Z000B,ZC007,ZC005,Z000C,Z0004,ZC00E,Z8051, */
/* dsw X Z8061,Z0051,Z0061,ZC061,ZC051,Z0004/ */
/* dsw  -------------------------------------------------------------- */
/*    #8008 --> -#7ff8, #c007 --> -#3ff9, #c005 --> -#3ffb, */
/*    #c00e --> -#3ff2, #8051 -->   -#7faf, #8061 -->  -#7f9f, */
/*    #c061 --> -#3f9f, #c051 -->  -#3faf */
/* deb ------------------- added ---------------- */
/* deb ---------------------------------------- */
    hnames_1.intnm = 24;
    hnames_1.renm = 40;
    hnames_1.boolnm = 8;
    hnames_1.chrnm = 16;
    hnames_1.cornm = 2919;
    hnames_1.procnm = 2785;
    hnames_1.textnm = 48;
    hnames_1.filenm = 56;
/* dsw  ---------------------------------------------------------------- */
    blank_1.nattr = blank_1.lpml + 2;
    blank_1.ipmem[blank_1.lpml - 1] = -1;
    ++blank_1.lpml;

/* NRINT */
    blank_1.nrint = mgetm_(&c__3, &c__41);
    blank_1.ipmem[blank_1.nrint - 1] = inhex1;
/* NRRE */
    blank_1.nrre = mgetm_(&c__3, &c__41);
    blank_1.ipmem[blank_1.nrre - 1] = inhex2;

/* NRBOOL */
    blank_1.nrbool = mgetm_(&c__3, &c__41);
    blank_1.ipmem[blank_1.nrbool - 1] = inhex3;

/* NRCHR */
    blank_1.nrchr = mgetm_(&c__3, &c__41);
    blank_1.ipmem[blank_1.nrchr - 1] = inhex3;
/* #F */

/* NRFILE */
    nrfile = mgetm_(&c__3, &c__41);
    blank_1.ipmem[nrfile - 1] = inhex4;

/* NRCOR */
    blank_1.nrcor = mgetm_(&c__9, &c__41) + 7;
    blank_1.ipmem[blank_1.nrcor - 1] = inhex5;
/*         NUMER W ZBIORZE PREFIKSOW ORAZ SLOWO Z TEGO ZBIORU */
    blank_1.ipmem[blank_1.nrcor - 2] = 0;
    msetb_(&blank_1.nrcor, &c__0);
    msetb_(&blank_1.nrcor, &c__2);

/* NRPROC */
    blank_1.nrproc = mgetm_(&c__9, &c__41) + 7;
    blank_1.ipmem[blank_1.nrproc - 1] = inhex6;
    blank_1.ipmem[blank_1.nrproc - 7] = 1;
    msetb_(&blank_1.nrproc, &c__0);
    msetb_(&blank_1.nrproc, &c__1);
    msetb_(&blank_1.nrproc, &c__2);

/* NRTEXT */
    blank_1.nrtext = mgetm_(&c__3, &c__41);
    blank_1.ipmem[blank_1.nrtext - 1] = inhex7;

/* NRUNIV */
    blank_1.nruniv = mgetm_(&c__9, &c__41) + 7;
    blank_1.ipmem[blank_1.nruniv - 1] = inhex8;
    blank_1.ipmem[blank_1.nruniv - 7] = 2;
    blank_1.ipmem[blank_1.nruniv - 6] = xx;
    blank_1.ipmem[blank_1.nruniv - 5] = xx;
    blank_1.ipmem[blank_1.nruniv - 4] = xx;

/* NRNONE */
    blank_1.nrnone = mgetm_(&c__9, &c__41) + 7;
    blank_1.ipmem[blank_1.nrnone - 1] = inhex9;
    blank_1.ipmem[blank_1.nrnone - 7] = 2;
    msetb_(&blank_1.nrnone, &c__2);

/* dsw */
/*  stala intsize */
    wrds1 = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[wrds1 - 4] = blank_1.nrint;
    blank_1.ipmem[wrds1] = 1;
    blank_1.ipmem[wrds1 - 1] = 129;
    i__ = 4;
    if (bit_test(option_1.opt,12)) {
	i__ = 4;
    }
    blank_1.ipmem[wrds1 - 2] = i__;
/*  stala realsize */
    wrds2 = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[wrds2 - 4] = blank_1.nrint;
    blank_1.ipmem[wrds2] = 1;
    blank_1.ipmem[wrds2 - 1] = 129;
    i__ = 4;
    if (bit_test(option_1.opt,12)) {
	i__ = 8;
    }
    blank_1.ipmem[wrds2 - 2] = i__;

/* ......INICJALIZACJA BLOKU SYSTEMOWEGO */
    blank_1.nblsys = mgetm_(&c__21, &c__41) + 2;
    blank_1.ipmem[blank_1.nblsys - 1] = 1;
    blank_1.ipmem[blank_1.nblsys + 2] = 2;
/*     USTAWIENIE SL DLA COROUTINE I PROCESS */
    blank_1.ipmem[blank_1.nrcor - 2] = blank_1.nblsys;
    blank_1.ipmem[blank_1.nrproc - 2] = blank_1.nblsys;
/*  inicjalizacja lprefs */
    prefs_1.lprefs = 2;

/* ......INICJALIZACJA FUNKCJI I PROCEDUR STANDARDOWYCH */
/*   ...PARAMETRY - ICH OPISY */
/* INPR - INPUT REAL */
    inpr = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inpr - 4] = blank_1.nrre;
    blank_1.ipmem[inpr] = 1;
    blank_1.ipmem[inpr - 1] = inhx10;
/* OUTPR - OUTPUT REAL (I RESULT) */
    outpr = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[outpr - 4] = blank_1.nrre;
    blank_1.ipmem[outpr] = 1;
    blank_1.ipmem[outpr - 1] = inhx11;
/* INPI - INPUT INTEGER */
    inpi = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inpi - 4] = blank_1.nrint;
    blank_1.ipmem[inpi] = 1;
    blank_1.ipmem[inpi - 1] = inhx12;
/* OUTPI - OUTPUT INTEGER (I RESULT) */
    outpi = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[outpi - 4] = blank_1.nrint;
    blank_1.ipmem[outpi] = 1;
    blank_1.ipmem[outpi - 1] = inhx13;
/* INPCH - INPUT CHARACTER */
    inpch = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inpch - 4] = blank_1.nrchr;
    blank_1.ipmem[inpch] = 1;
    blank_1.ipmem[inpch - 1] = inhx12;
/* OUTPCH - OUTPUT CHARACTER (I RESULT) */
    outpch = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[outpch - 4] = blank_1.nrchr;
    blank_1.ipmem[outpch] = 1;
    blank_1.ipmem[outpch - 1] = inhx13;
/* OUTPB - OUTPUT BOOLEAN (I RESULT) */
    outpb = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[outpb - 4] = blank_1.nrbool;
    blank_1.ipmem[outpb] = 1;
    blank_1.ipmem[outpb - 1] = inhx13;
/* OUTACH - OUTPUT ARRAYOF CHAR (I RESULT) */
    outach = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[outach - 5] = 1;
    blank_1.ipmem[outach - 4] = blank_1.nrchr;
    blank_1.ipmem[outach] = 1;
    blank_1.ipmem[outach - 1] = inhx14;
/* #F  NOWE OPISY PARAMETROW DLA PLIKOW */
/* INPF - INPUT FILE */
    inpf = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inpf - 4] = nrfile;
    blank_1.ipmem[inpf] = 1;
    blank_1.ipmem[inpf - 1] = inhx15;
/* INPTX - INPUT TEXT (=STRING) */
    inptx = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inptx - 4] = blank_1.nrtext;
    blank_1.ipmem[inptx] = 1;
    blank_1.ipmem[inptx - 1] = inhx12;
/* INPARI - INPUT ARRAYOF INTEGER */
    inpari = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inpari - 5] = 1;
    blank_1.ipmem[inpari - 4] = blank_1.nrint;
    blank_1.ipmem[inpari] = 1;
    blank_1.ipmem[inpari - 1] = inhx15;
/* dsw --------------- for exec--- */
/* inparch - input arrayof char */
    inparch = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inparch - 1] = inhx15;
    blank_1.ipmem[inparch] = 1;
    blank_1.ipmem[inparch - 4] = blank_1.nrchr;
    blank_1.ipmem[inparch - 5] = 1;


/* deb --------------- added ------------ */
/*  inoui - inout integer */
    inoui = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inoui - 4] = blank_1.nrint;
    blank_1.ipmem[inoui] = 1;
    blank_1.ipmem[inoui - 1] = inhx16;
/*  inour - inout  real */
    inour = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inour - 4] = blank_1.nrre;
    blank_1.ipmem[inour] = 1;
    blank_1.ipmem[inour - 1] = inhx17;
/*  inouari - inout arrayof integer */
    inouari = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[inouari - 5] = 1;
    blank_1.ipmem[inouari - 4] = blank_1.nrint;
    blank_1.ipmem[inouari] = 1;
    blank_1.ipmem[inouari - 1] = inhx18;
/* deb ------------------------------- */

/*   ...LISTY PARAMETROW FORMALNYCH */
/*   FPL1 - (INPUT REAL): REAL */
    fpl1 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl1 - 1] = inpr;
    blank_1.ipmem[fpl1] = outpr;
/*   FPL2 - (INPUT INTEGER, INPUT INTEGER, INPUT INTEGER): INTEGER */
    fpl2 = mgetm_(&c__4, &c__41);
    blank_1.ipmem[fpl2 - 1] = inpi;
    blank_1.ipmem[fpl2] = inpi;
    blank_1.ipmem[fpl2 + 1] = inpi;
    blank_1.ipmem[fpl2 + 2] = outpi;
/*   FPL3 - (INPUT REAL): INTEGER */
    fpl3 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl3 - 1] = inpr;
    blank_1.ipmem[fpl3] = outpi;
/*   FPL4 - :BOOLEAN */
    fpl4 = mgetm_(&c__1, &c__41);
    blank_1.ipmem[fpl4 - 1] = outpb;

/*   FPL5 - (INPUT INTEGER): CHARACTER */
    fpl5 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl5 - 1] = inpi;
    blank_1.ipmem[fpl5] = outpch;

/*   FPL6 - (INPUT CHARACTER): INTEGER */
    fpl6 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl6 - 1] = inpch;
    blank_1.ipmem[fpl6] = outpi;

/*   FPL7 - (OUTPUT INTEGER, INTEGER, INTEGER) */
    fpl7 = mgetm_(&c__3, &c__41);
    blank_1.ipmem[fpl7 - 1] = outpi;
    blank_1.ipmem[fpl7] = outpi;
    blank_1.ipmem[fpl7 + 1] = outpi;
/*   FPL8 - (INPUT TEXT, OUTPUT ARRAY OF CHAR) */
    fpl8 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl8 - 1] = inptx;
    blank_1.ipmem[fpl8] = outach;
/* #F  NOWE LISTY DLA PLIKOW */

/*   FPL9 - (INPUT FILE, INPUT INTEGER, INPUT ARRAYOF INTEGER) */
    fpl9 = mgetm_(&c__3, &c__41);
    blank_1.ipmem[fpl9 - 1] = inpf;
    blank_1.ipmem[fpl9] = inpi;
    blank_1.ipmem[fpl9 + 1] = inpari;

/*   FPL10 - (INPUT FILE, INPUT TEXT) */
    fpl10 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl10 - 1] = inpf;
    blank_1.ipmem[fpl10] = inptx;
/* deb ------------ added -------------- */
/*  fpl11 - (input integer, inout arrayof integer, integer, */
/*                 arrayof integer, real, integer) */
    fpl11 = mgetm_(&c__6, &c__41);
    blank_1.ipmem[fpl11 - 1] = inpi;
    blank_1.ipmem[fpl11] = inouari;
    blank_1.ipmem[fpl11 + 1] = inoui;
    blank_1.ipmem[fpl11 + 2] = inouari;
    blank_1.ipmem[fpl11 + 3] = inour;
    blank_1.ipmem[fpl11 + 4] = inoui;
/*  fpl12 - (input integer, inout integer, integer,arrayof integer) */
    fpl12 = mgetm_(&c__4, &c__41);
    blank_1.ipmem[fpl12 - 1] = inpi;
    blank_1.ipmem[fpl12] = inoui;
    blank_1.ipmem[fpl12 + 1] = inoui;
    blank_1.ipmem[fpl12 + 2] = inouari;
/*  fpl18 - (input file,file) */
    fpl18 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl18 - 1] = inpf;
    blank_1.ipmem[fpl18] = inpf;
/* deb -------------------------------- */
/* dsw ---------- for exec ------ */
/*  fpl13 - (input arrayof char, input arrayof char):integer */
    fpl13 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl13 - 1] = inparch;
    blank_1.ipmem[fpl13] = outpi;
/* fpl14 - input file, input integer, input integer */
    fpl14 = mgetm_(&c__3, &c__41);
    blank_1.ipmem[fpl14 - 1] = inpf;
    blank_1.ipmem[fpl14] = inpi;
    blank_1.ipmem[fpl14 + 1] = inpi;
/* fpl15 - input integer, input integer, input integer, input integer */
    fpl15 = mgetm_(&c__4, &c__41);
    blank_1.ipmem[fpl15 - 1] = inpi;
    blank_1.ipmem[fpl15] = inpi;
    blank_1.ipmem[fpl15 + 1] = inpi;
    blank_1.ipmem[fpl15 + 2] = inpi;
/* fpl16 - input file, output integer */
    fpl16 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl16 - 1] = inpf;
    blank_1.ipmem[fpl16] = outpi;
/*   ...PROTOTYPY FUNKCJI STANDARDOWYCH I ICH WLACZENIE DO LISTY HASHU */
/* INOT: FUNCTION(INPUT X: INTEGER) : INTEGER */
    i__1 = fpl2 + 2;
    mstafp_(&c__2613, &i__1, &c__2, &c__0, &blank_1.nrint, &outpi, &c_n1, &
	    blank_1.nblsys);
/* IOR: FUNCTION (INPUT X: INTEGER INPUT Y: INTEGER): INTEGER */
    i__1 = fpl2 + 1;
    mstafp_(&c__335, &i__1, &c__3, &c__0, &blank_1.nrint, &outpi, &c_n2, &
	    blank_1.nblsys);
/* IAND:  FUNCTION (INPUT X: INTEGER INPUT Y: INTEGER): INTEGER */
    i__1 = fpl2 + 1;
    mstafp_(&c__307, &i__1, &c__3, &c__0, &blank_1.nrint, &outpi, &c_n3, &
	    blank_1.nblsys);
/* ISHFT: FUNCTION (INPUT X: INTEGER INPUT Y: INTEGER): INTEGER */
    i__1 = fpl2 + 1;
    mstafp_(&c__2605, &i__1, &c__3, &c__0, &blank_1.nrint, &outpi, &c_n4, &
	    blank_1.nblsys);
/* EOF: FUNCTION: BOOLEAN */
/* file CALL  MSTAFP(1841, FPL4, 1, 0, NRBOOL, OUTPB, 39, nblsys) */
/* ENTIER: FUNCTION (INPUT X: REAL): INTEGER */
    mstafp_(&c__2589, &fpl3, &c__2, &c__0, &blank_1.nrint, &outpi, &c__15, &
	    blank_1.nblsys);
/* RANDOM: FUNCTION: REAL */
    i__1 = fpl1 + 1;
    mstafp_(&c__2599, &i__1, &c__1, &c__0, &blank_1.nrre, &outpr, &c__12, &
	    blank_1.nblsys);
/* TIME: FUNCTION: INTEGER */
    i__1 = fpl3 + 1;
    mstafp_(&c__1731, &i__1, &c__1, &c__0, &blank_1.nrint, &outpi, &c__13, &
	    blank_1.nblsys);
/* SQRT: FUNCTION (INPUT X: REAL): REAL */
    mstafp_(&c__1619, &fpl1, &c__2, &c__0, &blank_1.nrre, &outpr, &c__14, &
	    blank_1.nblsys);
/* ROUND: FUNCTION (INPUT X: REAL): INTEGER */
    mstafp_(&c__1487, &fpl3, &c__2, &c__0, &blank_1.nrint, &outpi, &c__16, &
	    blank_1.nblsys);
/* EOLN: FUNCTION: BOOLEAN */
/* file CALL  MSTAFP(2579, FPL4, 1, 0, NRBOOL, OUTPB, 74, nblsys) */
/* ORD: FUNCTION(INPUT X: CHARACTER): INTEGER */
    mstafp_(&c__2571, &fpl6, &c__2, &c__0, &blank_1.nrint, &outpi, &c_n5, &
	    blank_1.nblsys);
/* CHR: FUNCTION(INPUT X: INTEGER): CHARACTER */
    mstafp_(&c__2575, &fpl5, &c__2, &c__0, &blank_1.nrchr, &outpch, &c_n6, &
	    blank_1.nblsys);
/* SIN: FUNCTION(INPUT REAL): REAL */
    mstafp_(&c__2563, &fpl1, &c__2, &c__0, &blank_1.nrre, &outpr, &c__23, &
	    blank_1.nblsys);
/* COS: FUNCTION(INPUT REAL): REAL */
    mstafp_(&c__2559, &fpl1, &c__2, &c__0, &blank_1.nrre, &outpr, &c__24, &
	    blank_1.nblsys);
/* TAN: FUNCTION (INPUT REAL): REAL */
    mstafp_(&c__2555, &fpl1, &c__2, &c__0, &blank_1.nrre, &outpr, &c__25, &
	    blank_1.nblsys);
/* EXP: FUNCTION (INPUT REAL): REAL */
    mstafp_(&c__2551, &fpl1, &c__2, &c__0, &blank_1.nrre, &outpr, &c__26, &
	    blank_1.nblsys);
/* LN: FUNCTION (INPUT REAL): REAL */
    mstafp_(&c__717, &fpl1, &c__2, &c__0, &blank_1.nrre, &outpr, &c__27, &
	    blank_1.nblsys);
/* ATAN: FUNCTION (INPUT REAL): REAL */
    mstafp_(&c__2547, &fpl1, &c__2, &c__0, &blank_1.nrre, &outpr, &c__28, &
	    blank_1.nblsys);
/* IMIN: FUNCTION (INUT INTEGER, INPUT INTEGER): INTEGER */
    i__1 = fpl2 + 1;
    mstafp_(&c__331, &i__1, &c__3, &c__0, &blank_1.nrint, &outpi, &c__19, &
	    blank_1.nblsys);
/* IMIN3: FUNCTION (INPUT INTEGER, INPUT INTEGER, INPUT INTEGER): INTEGER */
    mstafp_(&c__2521, &fpl2, &c__4, &c__0, &blank_1.nrint, &outpi, &c__21, &
	    blank_1.nblsys);
/* IMAX: FUNCTION (INPUT INTEGER, INPUT INTEGER): INTEGER */
    i__1 = fpl2 + 1;
    mstafp_(&c__2515, &i__1, &c__3, &c__0, &blank_1.nrint, &outpi, &c__20, &
	    blank_1.nblsys);
/* IMAX3: FUNCTION (INPUT INTEGER, INPUT INTEGER, INPUT INTEGER): INTEGER */
    mstafp_(&c__2511, &fpl2, &c__4, &c__0, &blank_1.nrint, &outpi, &c__22, &
	    blank_1.nblsys);
/* XOR: FUNCTION(INPUT X,Y: INTEGER): INTEGER */
    i__1 = fpl2 + 1;
    mstafp_(&c__237, &i__1, &c__3, &c__0, &blank_1.nrint, &outpi, &c_n7, &
	    blank_1.nblsys);
/* PANELKEYS: FUNCTION: INTEGER */
    i__1 = fpl3 + 1;
    mstafp_(&c__1203, &i__1, &c__1, &c__0, &blank_1.nrint, &outpi, &c__18, &
	    blank_1.nblsys);
/* ENDRUN : PROCEDURE */
    mstafp_(&c__2483, &c__0, &c__0, &c__0, &c__0, &c__0, &c__29, &
	    blank_1.nblsys);
/* RANSET: PROCEDURE(INPUT X: REAL) */
    mstafp_(&c__2375, &fpl1, &c__1, &c__0, &c__0, &c__0, &c__30, &
	    blank_1.nblsys);
/* CLOCK: PROCEDURE(OUTPUT H,M,S: INTEGER) */
    mstafp_(&c__2369, &fpl7, &c__3, &c__0, &c__0, &c__0, &c__31, &
	    blank_1.nblsys);
/* OPTIONS: FUNCTION: INTEGER */
    i__1 = fpl3 + 1;
    mstafp_(&c__1105, &i__1, &c__1, &c__0, &blank_1.nrint, &outpi, &c__32, &
	    blank_1.nblsys);
/* DATE: PROCEDURE (OUTPUT Y,M,D: INTEGER) */
    mstafp_(&c__1685, &fpl7, &c__3, &c__0, &c__0, &c__0, &c__36, &
	    blank_1.nblsys);
/* EXECPAR: FUNCTION: ARRAYOF CHAR */
    i__1 = fpl8 + 1;
    mstafp_(&c__2357, &i__1, &c__1, &c__1, &blank_1.nrchr, &outach, &c__37, &
	    blank_1.nblsys);
/* UNPACK: FUNCTION( INPUT TEXT): ARRAYOF CHAR */
    mstafp_(&c__2247, &fpl8, &c__2, &c__1, &blank_1.nrchr, &outach, &c__11, &
	    blank_1.nblsys);
/* dsw  --- removed  ------ */
/* #F  NOWE PROCEDURY DLA PLIKOW */
/* REW: PROCEDURE(INPUT FILE) */
/* dsw  CALL  MSTAFP(2339, FPL9, 1, 0, 0, 0, 2, nblsys) */
/* AVF: PROCEDURE(INPUT FILE, INPUT INTEGER) */
/* dsw  CALL MSTAFP(1343, FPL9, 2, 0, 0, 0, 3, nblsys) */
/* BVF: PROCEDURE(INPUT FILE, INPUT INTEGER) */
/* dsw  CALL MSTAFP(1471, FPL9, 2, 0, 0, 0, 4, nblsys) */
/* WEO: PROCEDURE(INPUT FILE) */
/* dsw  CALL MSTAFP(  89, FPL9, 1, 0, 0, 0, 5, nblsys) */
/* PUtREC: PROCEDURE(INPUT FILE, INPUT INTEGER, INPUT ARRAYOF INTEGER) */
/* dsw  CALL MSTAFP(1243, FPL9, 3, 0, 0, 0, 6, nblsys) */
/* GETREC: PROCEDURE(INPUT FILE, INPUT INTEGER, INPUT ARRAYOF INTEGER) */
/* dsw  CALL MSTAFP(  59, FPL9, 3, 0, 0, 0, 7, nblsys) */
/* ASS: PROCEDURE(INPUT FILE, INPUT TEXT) */
/* dsw  CALL MSTAFP(2335, FPL10, 2, 0, 0, 0, 8, nblsys) */
/* ASSIN: PROCEDURE(INPUT STRING) */
/* dsw  CALL MSTAFP(2241, FPL10+1, 1, 0, 0, 0, 9, nblsys) */
/* ASSOUT: PROCEDURE(INPUT STRING) */
/* dsw  CALL MSTAFP(2235, FPL10+1, 1, 0, 0, 0, 10, nblsys) */
/* file  ---------------  added  ---------------------- */
/* reset: procedure(input file) */
    mstafp_(&c__2253, &fpl9, &c__1, &c__0, &c__0, &c__0, &c__78, &
	    blank_1.nblsys);
/*  rewrite:procedure(input file) */
    mstafp_(&c__2259, &fpl9, &c__1, &c__0, &c__0, &c__0, &c__79, &
	    blank_1.nblsys);
/* unlink:procedure(input file) */
    mstafp_(&c__2087, &fpl9, &c__1, &c__0, &c__0, &c__0, &c__80, &
	    blank_1.nblsys);
/* seek:procedure(input file,input integer, input integer) */
    mstafp_(&c__2091, &fpl14, &c__3, &c__0, &c__0, &c__0, &c__81, &
	    blank_1.nblsys);
/* position : function(input file):integer */
    mstafp_(&c__2023, &fpl16, &c__2, &c__0, &blank_1.nrint, &outpi, &c__84, &
	    blank_1.nblsys);
/* memavail : function:integer */
    i__1 = fpl2 + 3;
    mstafp_(&c__7847, &i__1, &c__1, &c__0, &blank_1.nrint, &outpi, &c__98, &
	    blank_1.nblsys);
/* exec:function(input arrayof char):integer */
    mstafp_(&c__2101, &fpl13, &c__2, &c__0, &blank_1.nrint, &outpi, &c__99, &
	    blank_1.nblsys);

/* deb    ------------   debugger ------------ */
/* db01ox:procedure(nr:integer; inout ref1:arrayof integer, */
/*                  offset:integer, ref2:arrayof integer, realval:real, */
/*                  intval:integer ); */
    mstafp_(&c__7759, &fpl11, &c__6, &c__0, &c__0, &c__0, &c__150, &
	    blank_1.nblsys);
/*  sccd01ox : procedure(nr:integer; inout max,lp:integer, bufor:arrayof int ); */
    mstafp_(&c__7739, &fpl12, &c__4, &c__0, &c__0, &c__0, &c__151, &
	    blank_1.nblsys);
/*  scnd01ox:procedure(output s,k,adres:integer); */
    mstafp_(&c__7747, &fpl7, &c__3, &c__0, &c__0, &c__0, &c__152, &
	    blank_1.nblsys);
/*  db01of : procedure(input f1,f2:file); */
    mstafp_(&c__7753, &fpl18, &c__2, &c__0, &c__0, &c__0, &c__153, &
	    blank_1.nblsys);
/*  db01oe : procedure; */
    mstafp_(&c__7731, &c__0, &c__0, &c__0, &c__0, &c__0, &c__154, &
	    blank_1.nblsys);
/* deb ------------------------------------------- */
/* gr ------------- grafika ------------------ */
/*  utworzenie klasy IIUWGRAPH */
    syspro_1.prgraph = mstacl_(&c__323, &blank_1.nblsys);
    grpref = prefs_1.lprefs;
    outari = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[outari - 5] = 1;
    blank_1.ipmem[outari - 4] = blank_1.nrint;
    blank_1.ipmem[outari] = 1;
    blank_1.ipmem[outari - 1] = inhx14;
    toto = mgetm_(&c__6, &c__41);
    blank_1.ipmem[toto - 1] = inpi;
    blank_1.ipmem[toto] = inpi;
    blank_1.ipmem[toto + 1] = inpi;
    blank_1.ipmem[toto + 2] = inpi;
    blank_1.ipmem[toto + 3] = inpi;
    blank_1.ipmem[toto + 4] = inpi;
    toto2 = mgetm_(&c__5, &c__41);
    blank_1.ipmem[toto2 - 1] = inpi;
    blank_1.ipmem[toto2] = inpi;
    blank_1.ipmem[toto2 + 1] = inpi;
    blank_1.ipmem[toto2 + 2] = inpi;
    blank_1.ipmem[toto2 + 3] = inpi;
    toto3 = mgetm_(&c__10, &c__41);
    blank_1.ipmem[toto3 - 1] = inpi;
    blank_1.ipmem[toto3] = inpi;
    blank_1.ipmem[toto3 + 1] = inpi;
    blank_1.ipmem[toto3 + 2] = inpi;
    blank_1.ipmem[toto3 + 3] = inpi;
    blank_1.ipmem[toto3 + 4] = inpi;
    blank_1.ipmem[toto3 + 5] = inpi;
    blank_1.ipmem[toto3 + 6] = inpi;
    blank_1.ipmem[toto3 + 7] = inpi;
    blank_1.ipmem[toto3 + 8] = outpi;
    fpl22 = mgetm_(&c__9, &c__41);
    blank_1.ipmem[fpl22 - 1] = inpi;
    blank_1.ipmem[fpl22] = inpi;
    blank_1.ipmem[fpl22 + 1] = inpi;
    blank_1.ipmem[fpl22 + 2] = inpr;
    blank_1.ipmem[fpl22 + 3] = inpr;
    blank_1.ipmem[fpl22 + 4] = inpi;
    blank_1.ipmem[fpl22 + 5] = inpi;
    blank_1.ipmem[fpl22 + 6] = inpi;
    blank_1.ipmem[fpl22 + 7] = inpi;
    fpl23 = mgetm_(&c__3, &c__41);
    blank_1.ipmem[fpl23 - 1] = inpi;
    blank_1.ipmem[fpl23] = inpi;
    blank_1.ipmem[fpl23 + 1] = outari;
    toto5 = mgetm_(&c__9, &c__41);
    blank_1.ipmem[toto5 - 1] = inpi;
    blank_1.ipmem[toto5] = inpi;
    blank_1.ipmem[toto5 + 1] = inpi;
    blank_1.ipmem[toto5 + 2] = inpi;
    blank_1.ipmem[toto5 + 3] = inptx;
    blank_1.ipmem[toto5 + 4] = inpi;
    blank_1.ipmem[toto5 + 5] = inpi;
    blank_1.ipmem[toto5 + 6] = inpi;
    blank_1.ipmem[toto5 + 7] = outach;
    toto6 = mgetm_(&c__5, &c__41);
    blank_1.ipmem[toto6 - 1] = inpi;
    blank_1.ipmem[toto6] = inpi;
    blank_1.ipmem[toto6 + 1] = inptx;
    blank_1.ipmem[toto6 + 2] = inpi;
    blank_1.ipmem[toto6 + 3] = inpi;
    toto7 = mgetm_(&c__5, &c__41);
    blank_1.ipmem[toto7 - 1] = inpi;
    blank_1.ipmem[toto7] = inpari;
    blank_1.ipmem[toto7 + 1] = inpari;
    blank_1.ipmem[toto7 + 2] = inpi;
    blank_1.ipmem[toto7 + 3] = inpi;
    toto8 = mgetm_(&c__8, &c__41);
    blank_1.ipmem[toto8 - 1] = inpi;
    blank_1.ipmem[toto8] = inpi;
    blank_1.ipmem[toto8 + 1] = inpi;
    blank_1.ipmem[toto8 + 2] = inpi;
    blank_1.ipmem[toto8 + 3] = inpi;
    blank_1.ipmem[toto8 + 4] = inpi;
    blank_1.ipmem[toto8 + 5] = inpi;
    blank_1.ipmem[toto8 + 6] = inpi;
/* gron:procedure(input integer) */
    mstafp_(&c__85, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__100, &
	    syspro_1.prgraph);
/* groff: procedure */
    mstafp_(&c__2273, &c__0, &c__0, &c__0, &c__0, &c__0, &c__101, &
	    syspro_1.prgraph);
/* cls: procedure */
    mstafp_(&c__2335, &c__0, &c__0, &c__0, &c__0, &c__0, &c__102, &
	    syspro_1.prgraph);
/* point: procedure(input integer, input integer) */
    mstafp_(&c__1231, &fpl2, &c__2, &c__0, &c__0, &c__0, &c__103, &
	    syspro_1.prgraph);
/* move: procedure(input integer, input integer) */
    mstafp_(&c__2279, &fpl2, &c__2, &c__0, &c__0, &c__0, &c__104, &
	    syspro_1.prgraph);
/* draw: procedure(input integer, input integer) */
    mstafp_(&c__1719, &fpl2, &c__2, &c__0, &c__0, &c__0, &c__105, &
	    syspro_1.prgraph);
/* hfill: procedure(input integer) */
    mstafp_(&c__189, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__106, &
	    syspro_1.prgraph);
/* vfill: procedure(input integer) */
    mstafp_(&c__2237, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__107, &
	    syspro_1.prgraph);
/* color: procedure(input integer) */
    mstafp_(&c__2231, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__108, &
	    syspro_1.prgraph);
/* style: procedure(input integer) */
    mstafp_(&c__2225, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__109, &
	    syspro_1.prgraph);
/* patern: procedure(input integer,input integer,input integer,input integer, */
/*                   input integer,input boolean) */
    mstafp_(&c__2219, &toto, &c__6, &c__0, &c__0, &c__0, &c__110, &
	    syspro_1.prgraph);
/* intens: procedure(input integer,arrayof int,arrayof int,int,int) */
    mstafp_(&c__2213, &toto7, &c__5, &c__0, &c__0, &c__0, &c__111, &
	    syspro_1.prgraph);
/* pallet: procedure(input integer) */
    mstafp_(&c__2207, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__112, &
	    syspro_1.prgraph);
/* border: procedure(input integer) */
    mstafp_(&c__2201, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__113, &
	    syspro_1.prgraph);
/* video: procedure(input array of integer) */
    i__1 = fpl9 + 2;
    mstafp_(&c__2195, &i__1, &c__1, &c__0, &c__0, &c__0, &c__114, &
	    syspro_1.prgraph);
/* hpage: procedure(input integer, input integer, input integer) */
    mstafp_(&c__209, &fpl2, &c__3, &c__0, &c__0, &c__0, &c__115, &
	    syspro_1.prgraph);
/* nocard: function: integer */
    i__1 = fpl2 + 3;
    mstafp_(&c__2029, &i__1, &c__1, &c__0, &blank_1.nrint, &outpi, &c__116, &
	    syspro_1.prgraph);
/* pushxy: procedure */
    mstafp_(&c__2185, &c__0, &c__0, &c__0, &c__0, &c__0, &c__117, &
	    syspro_1.prgraph);
/* popxy: procedure */
    mstafp_(&c__2179, &c__0, &c__0, &c__0, &c__0, &c__0, &c__118, &
	    syspro_1.prgraph);
/* inxpos: function: integer */
    i__1 = fpl2 + 3;
    mstafp_(&c__2173, &i__1, &c__1, &c__0, &blank_1.nrint, &outpi, &c__119, &
	    syspro_1.prgraph);
/* inypos: function: integer */
    i__1 = fpl2 + 3;
    mstafp_(&c__2167, &i__1, &c__1, &c__0, &blank_1.nrint, &outpi, &c__120, &
	    syspro_1.prgraph);
/* inpix: function(input integer, input integer): integer */
    i__1 = fpl2 + 1;
    mstafp_(&c__2161, &i__1, &c__3, &c__0, &blank_1.nrint, &outpi, &c__121, &
	    syspro_1.prgraph);
/* getmap: function(input integer, input integer): array of integer */
    mstafp_(&c__2155, &fpl23, &c__3, &c__1, &blank_1.nrint, &outari, &c__122, 
	    &syspro_1.prgraph);
/* putmap: procedure(input array of integer) */
    i__1 = fpl9 + 2;
    mstafp_(&c__2149, &i__1, &c__1, &c__0, &c__0, &c__0, &c__123, &
	    syspro_1.prgraph);
/* ormap: procedure(input array of integer) */
    i__1 = fpl9 + 2;
    mstafp_(&c__2143, &i__1, &c__1, &c__0, &c__0, &c__0, &c__124, &
	    syspro_1.prgraph);
/* xormap: procedure(input array of integer) */
    i__1 = fpl9 + 2;
    mstafp_(&c__2137, &i__1, &c__1, &c__0, &c__0, &c__0, &c__125, &
	    syspro_1.prgraph);
/* track: procedure(input integer, input integer,input integer,input integer) */
    mstafp_(&c__2131, &toto2, &c__5, &c__0, &c__0, &c__0, &c__126, &
	    syspro_1.prgraph);
/* inkey: function: integer */
    i__1 = fpl2 + 3;
    mstafp_(&c__2299, &i__1, &c__1, &c__0, &blank_1.nrint, &outpi, &c__127, &
	    syspro_1.prgraph);
/* hascii: procedure(input integer) */
    mstafp_(&c__2293, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__128, &
	    syspro_1.prgraph);
/* hfont: function(input integer,input integer,input integer,input integer) */
/*  (intput integer,input integer,input integer,input integer,input integer): */
/*   integer              new name : gscnum */
    mstafp_(&c__2125, &toto3, &c__10, &c__0, &blank_1.nrint, &outpi, &c__129, 
	    &syspro_1.prgraph);
/* hfont8: function(input int, input int,input int,input int,input string */
/*          intput int,input int,input int) : arrayof char */
    mstafp_(&c__2119, &toto5, &c__9, &c__1, &blank_1.nrchr, &outari, &c__130, 
	    &syspro_1.prgraph);
/* outstring: procedure(input int,input int,input string,input int,input int) */
    mstafp_(&c__2113, &toto6, &c__5, &c__0, &c__0, &c__0, &c__131, &
	    syspro_1.prgraph);
/* cirb: procedure(input x,y,rx,ry,start,end,c,motif :integer) */
    mstafp_(&c__1573, &toto8, &c__8, &c__0, &c__0, &c__0, &c__132, &
	    syspro_1.prgraph);
/* dsw -------------- mouse ------------------------ */
    syspro_1.prmouse = mstacl_(&c__7991, &blank_1.nblsys);
    mousepref = prefs_1.lprefs;
/* fpl30 - output int, output bool */
    fpl30 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[fpl30 - 1] = outpi;
    blank_1.ipmem[fpl30] = outpb;
/* fpl31 - input integer, output integerl, output integer, output integer, */
/*             output integer, output integer, output integer */
    fpl31 = mgetm_(&c__7, &c__41);
    blank_1.ipmem[fpl31 - 1] = outpi;
    blank_1.ipmem[fpl31] = outpi;
    blank_1.ipmem[fpl31 + 1] = outpi;
    blank_1.ipmem[fpl31 + 2] = outpi;
    blank_1.ipmem[fpl31 + 3] = outpi;
    blank_1.ipmem[fpl31 + 4] = outpi;
    blank_1.ipmem[fpl31 + 5] = outpb;
    toto4 = mgetm_(&c__2, &c__41);
    blank_1.ipmem[toto4 - 1] = inpi;
    blank_1.ipmem[toto4] = inpi;
/* init : procedure(mouse,keyboard:integer); */
    mstafp_(&c__7985, &toto4, &c__2, &c__0, &c__0, &c__0, &c__200, &
	    syspro_1.prmouse);
/* showcursor : procedure; */
    mstafp_(&c__1601, &c__0, &c__0, &c__0, &c__0, &c__0, &c__201, &
	    syspro_1.prmouse);
/* hidecursor : procedure; */
    mstafp_(&c__7973, &c__0, &c__0, &c__0, &c__0, &c__0, &c__202, &
	    syspro_1.prmouse);
/* status : procedure(output h,v:integer, l, r, c:boolean) */
    i__1 = fpl31 + 2;
    mstafp_(&c__7963, &i__1, &c__5, &c__0, &c__0, &c__0, &c__203, &
	    syspro_1.prmouse);
/* setposition : procedure(h,v:integer); */
    mstafp_(&c__7957, &fpl2, &c__2, &c__0, &c__0, &c__0, &c__204, &
	    syspro_1.prmouse);
/* getpress : function( output h,v,p,l,r,c : integer) : boolean */
    mstafp_(&c__7945, &fpl31, &c__7, &c__0, &blank_1.nrbool, &outpb, &c__205, 
	    &syspro_1.prmouse);
/* getrelease : function( output h,v,p,l,r,c : integer) : boolean */
    mstafp_(&c__7937, &fpl31, &c__7, &c__0, &blank_1.nrbool, &outpb, &c__206, 
	    &syspro_1.prmouse);
/* setwindow : procedure ( l,r,t,b:integer) */
    mstafp_(&c__7887, &fpl15, &c__4, &c__0, &c__0, &c__0, &c__207, &
	    syspro_1.prmouse);
/* defcursor : procedure (select, x, y:integer) */
    mstafp_(&c__7917, &fpl2, &c__3, &c__0, &c__0, &c__0, &c__210, &
	    syspro_1.prmouse);
/* getmovement : procedure ( input mo,ke:integer) */
    mstafp_(&c__7907, &toto4, &c__2, &c__0, &c__0, &c__0, &c__211, &
	    syspro_1.prmouse);
/* setevent : procedure( m:integer ) */
/*     call mstafp(7865 , fpl2, 1, 0, 0, 0, 212, prmouse) */
/* setspeed : procedure ( speed:integer) */
    mstafp_(&c__7895, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__215, &
	    syspro_1.prmouse);
/* setmargins : procedure( l, r, t, b : integer) */
    mstafp_(&c__7927, &fpl15, &c__4, &c__0, &c__0, &c__0, &c__216, &
	    syspro_1.prmouse);
/* setthreshold : procedure(t:integer) */
    mstafp_(&c__7877, &fpl2, &c__1, &c__0, &c__0, &c__0, &c__219, &
	    syspro_1.prmouse);
/*  signal mouseevent */
/*     call mstasg(7857 , 70, prmouse) */

/* .........UTWORZENIE I WSTAWIENIE DO TABLICY HASHU BLOKU GLOWNEGO */
/*         PROTOTYPOW SYGNALOW STANDARDOWYCH */

/* NUMERROR */
    mstasg_(&c__987, &c__1, &blank_1.nblsys);
/* SYSERROR */
    mstasg_(&c__1635, &c__2, &blank_1.nblsys);
/* LOGERROR */
    mstasg_(&c__2319, &c__20, &blank_1.nblsys);
/* ACCERROR */
    mstasg_(&c__1305, &c__21, &blank_1.nblsys);
/* MEMERROR */
    mstasg_(&c__827, &c__22, &blank_1.nblsys);
/* CONERROR */
    mstasg_(&c__2311, &c__23, &blank_1.nblsys);
/* TYPERROR */
    mstasg_(&c__1995, &c__24, &blank_1.nblsys);

    i__ = blank_1.nblsys + 10;
/* .......UZUPELNIENIE TABLICY HASHU BLOKU GLOWNEGO O TYPY STANDARDOWE */
    xx = insert_(&hnames_1.intnm, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = blank_1.nrint;
    xx = insert_(&hnames_1.renm, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = blank_1.nrre;
    xx = insert_(&hnames_1.boolnm, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = blank_1.nrbool;
    xx = insert_(&hnames_1.chrnm, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = blank_1.nrchr;
/* #F */
    xx = insert_(&hnames_1.filenm, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = nrfile;
    xx = insert_(&hnames_1.cornm, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = blank_1.nrcor;
    xx = insert_(&hnames_1.procnm, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = blank_1.nrproc;
    xx = insert_(&hnames_1.textnm, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = blank_1.nrtext;
    xx = insert_(&blank_1.nempty, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = blank_1.nruniv;
/* dsw */
/*   stala intsize */
    xx = insert_(&c__2069, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = wrds1;
/*   stala realsize */
    xx = insert_(&c__2061, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = wrds2;


    blank_1.lpmsys = blank_1.lpml;

/* *******INICJALIZACJA SYSPP - W RAZIE POTRZEBY */
    if (sysppc_1.syspp) {
	mlspp_();
    }
    return 0;
} /* init_ */

/* dsw      SUBROUTINE MSTASG( HNAME, NRSIG) */
/* Subroutine */ int mstasg_(integer *hname, integer *nrsig, integer *sl)
{
    /* Initialized data */

    static integer msthex = 177;

    static integer xx;
    extern integer mgetm_(integer *, integer *);
    static integer iprot;
    extern integer insert_(integer *, integer *, integer *);

/* ------------- TWORZENIE PROTOTYPU SYGNALU STANDARDOWEGO */
/*              JEST ON SKROCONY I NIE POSIADA TABLICY HASHU */
/*              NAZW ATRYBUTOW. OSTATNIM SLOWEM JEST +7. */
/*              PROCEDURA WYWOLYWANA JEDYNIE Z INIT */
/*              WERSJA Z DN. 16 05 83 */
/* ALL BLANK */
/* ALL # */
/* GENERACJA I INICJLIZACJA PROTOTYPU */
    iprot = mgetm_(&c__9, &c__41) + 1;
/* dsw      IPMEM(IPROT-1) = NBLSYS */
    blank_1.ipmem[iprot - 2] = *sl;
    blank_1.ipmem[iprot - 1] = msthex;
    blank_1.ipmem[iprot] = *nrsig;

/* DODANIE NQZWY SYGNALU DO TBLICY HASHU W NBLYS */
/* dsw      XX = INSERT(HNAME, IPMEM(NBLSYS+10), 41) */
    xx = insert_(hname, &blank_1.ipmem[*sl + 9], &c__41);
/* NAZWA SYGNALU JEST CLOSED */
    blank_1.ipmem[xx] = 1;
    blank_1.ipmem[xx + 1] = iprot;
    return 0;
} /* mstasg_ */

/* Subroutine */ int mstafp_(integer *hname, integer *fplist, integer *fpleng,
	 integer *ndim, integer *ntype, integer *nreslt, integer *nrfp, 
	integer *sl)
{
    /* Initialized data */

    static integer mafhx1 = 513;
    static integer mafhx2 = 1025;

    static integer i__, xx;
    extern integer mgetm_(integer *, integer *);
    static integer iprot;
    extern integer insert_(integer *, integer *, integer *);

/* dsw     X                        NRFP) */
/* ----------------PROCEDURA TWORZY PROTOTYP FUNKCJI STANDARDOWEJ */
/*                I PROCEDURY STANDARDOWEJ - WTEDY NTYPE=0 */
/*                HNAME - NAZWA ZE SCANNERA TWORZONEJ FUNKCJI */
/*                FPLIST, FPLENG - INDEKS LISTY PAR. FORM. I JEJ DLUGOSC */
/*                NDIM, NTYPE - TYP FUNKCJI */
/*                NRESLT - OPIS ATRYBUTU RESULT */
/*                NRFP - ROZROZNIENIE FUNKCJI - WARTOSC DLA GENERATORA KODU */
/*                sl - adres prototypu obejmujacego */

/*             WERSJA Z DNIA:                19.01.82 */
/*               (DLA PROCEDURY INIT) */
/*             DLUGOSC KODU:  157 */
/* .................................................................. */


/* ALL BLANK */
/* ALL # */


/* DSW  DATA MAFPHEX1,MAFPHEX2 /Z0201,Z0401/ */
/* dsw  I = NBLSYS+10 */
    i__ = *sl + 10;

    if (*ntype == 0) {
	goto L100;
    }
/* -----FUNKCJA */
    iprot = mgetm_(&c__10, &c__41) + 5;
    blank_1.ipmem[iprot - 6] = *nreslt;
    blank_1.ipmem[iprot - 5] = *ndim;
    blank_1.ipmem[iprot - 4] = *ntype;
    blank_1.ipmem[iprot - 1] = mafhx1;
    goto L200;
/* -----PROCEDURA */
L100:
    iprot = mgetm_(&c__7, &c__41) + 2;
    blank_1.ipmem[iprot - 1] = mafhx2;
/* -----OBYDWIE RAZEM */
/* dsw   200 IPMEM(IPROT-1) = NBLSYS */
L200:
    blank_1.ipmem[iprot - 2] = *sl;
    blank_1.ipmem[iprot] = 1;
    blank_1.ipmem[iprot + 1] = *nrfp;
    blank_1.ipmem[iprot + 2] = *fplist;
    blank_1.ipmem[iprot + 3] = *fpleng;
    xx = insert_(hname, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = iprot;
    return 0;
} /* mstafp_ */

/* dsw  new procedure */
integer mstacl_(integer *hname, integer *sl)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i__, xx, prot;
    extern integer mgetm_(integer *, integer *);
    extern /* Subroutine */ int msetb_(integer *, integer *);
    extern integer insert_(integer *, integer *, integer *);

/* ALL BLANK */
/*  lprefs - ostatnio przydzielony numer w prefixset */
    blank_1.insys = FALSE_;
    prot = mgetm_(&c__33, &c__41) + 7;
    blank_1.ipmem[prot - 1] = 3;
    blank_1.ipmem[prot - 2] = *sl;
    blank_1.ipmem[prot + 8] = 0;
    xx = insert_(hname, &blank_1.ipmem[*sl + 9], &c__41);
    blank_1.ipmem[xx + 1] = prot;
/*  ustawienie prefixset i prefixlist */
    i__ = mgetm_(&c__1, &c__41);
    blank_1.ipmem[i__ - 1] = prot;
    blank_1.ipmem[prot + 21] = i__;
    blank_1.ipmem[prot + 22] = 1;
    msetb_(&prot, &c__2);
    ++prefs_1.lprefs;
    msetb_(&prot, &prefs_1.lprefs);
    blank_1.ipmem[prot - 7] = prefs_1.lprefs;
/* inicjalizacja listy atrybutow */
    blank_1.ipmem[prot + 6] = prot + 5;
    blank_1.ipmem[prot + 4] = blank_1.nattr;
    ret_val = prot;
    blank_1.insys = TRUE_;
    return ret_val;
} /* mstacl_ */

/* Subroutine */ int mlspp_(void)
{
    /* Initialized data */

    static integer mlphx1 = -16377;
    static integer mlphx2 = -16287;
    static integer mlphx3 = -16303;

    static integer pfl, par, sem, dupa, prev, slow, prot;
    extern integer mgetm_(integer *, integer *);
    extern /* Subroutine */ int msetb_(integer *, integer *);
    extern integer mlpar_(integer *, integer *, integer *, integer *, integer 
	    *);
    static integer pproc, syspp;
    extern integer mlincl_(integer *, integer *, integer *, integer *), 
	    mlinfp_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);

/* -----------------------INICJUJE PROTOTYPY ANALIZY SEMANTYCZNEJ DLA */
/*                       KLASY SYSPP */


/* ALL BLANK */
/* dsw  DATA MLSPHEX1,MLSPHEX2,MLSPHEX3 /ZC007,ZC061,ZC051/ */
/*    #c007 --> -#3ff9, #c061 --> -#3f9f, #c051 --> -#3faf */
/* ALL # */

/* ----------POPRAWIENIE SLOW +3 I +4 W BLOKU SYSTEMOWYM */
/*     +4 - JEST SYSPP */
    blank_1.ipmem[(1208 + (0 + (blank_1.nblsys + 4 - 1 << 2)) - 1208) / 4] = 
	    1;
/*     +3 - OSTATNIO UZYTY NUMER W SENSIE PREFIXSET */
    blank_1.ipmem[blank_1.nblsys + 2] += 4;

/* **** UTWORZENIE KLASY SYSPP */
    syspp = mlincl_(&c__2, &c__3, &blank_1.nblsys, &blank_1.nblsys);
    blank_1.ipmem[blank_1.nblsys + 7] = syspp;
/* **** UTWORZENIE KLASY PROCES */
    pproc = mlincl_(&c__2469, &c__4, &syspp, &syspp);
/*       --POPRAWIENIE NA COROUTINE */
    msetb_(&pproc, &c__0);
    blank_1.ipmem[pproc - 1] = mlphx1;
/* **** UTWORZENIE KLASY SLOWNIK */
    slow = mlincl_(&c__1609, &c__5, &syspp, &pproc);
/* **** UTWORZENIE KLASY SEMAFOR */
    sem = mlincl_(&c__2477, &c__6, &syspp, &slow);

/* ****** WNETRZE KLASY PROCES */
/*     ----WAITN: FUNCTION: PROCES */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    prot = mlinfp_(&c__2431, &pfl, &c__1, &c__0, &pproc, &pproc, &sem);
    prev = prot;
/*       --OPIS PARAMETRU */
    par = mlpar_(&c__0, &pproc, &c__2, &mlphx2, &prot);
    blank_1.ipmem[prot - 6] = par;
    blank_1.ipmem[pfl - 1] = par;
/*     ----STOPAR: PROCEDURE(INPUT Z: SEMAFOR) */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    prot = mlinfp_(&c__2437, &pfl, &c__1, &c__0, &c__0, &pproc, &prev);
    prev = prot;
/*       --OPIS PF */
    blank_1.ipmem[pfl - 1] = mlpar_(&c__0, &sem, &c__2, &mlphx3, &prot);
/*     ----WAITP: FUNCTION(INPUT Y:PROCES): PROCES */
/*       --LISTA PF */
    pfl = mgetm_(&c__2, &c__41);
/*       PROTOTYP */
    prot = mlinfp_(&c__2443, &pfl, &c__2, &c__0, &pproc, &pproc, &prev);
    prev = prot;
/*       --OPISY PF */
    blank_1.ipmem[pfl - 1] = mlpar_(&c__0, &pproc, &c__2, &mlphx3, &prot);
    par = mlpar_(&c__0, &pproc, &c__4, &mlphx2, &prot);
    blank_1.ipmem[pfl] = par;
    blank_1.ipmem[prot - 6] = par;
/*     ----STOPP: PROCEDURE */
    prot = mlinfp_(&c__2449, &c__0, &c__0, &c__0, &c__0, &pproc, &prev);
    prev = prot;
/*     ----RESUMEP: PROCEDURE(INPUT X: PROCES) */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    dupa = dupa;
/* BEZ TEJ DUPY FTS DAJE ZLY KOD WYNIKOWY */
    prot = mlinfp_(&c__2457, &pfl, &c__1, &c__0, &c__0, &pproc, &prev);
    prev = prot;
/*       --OPIS PF */
    blank_1.ipmem[pfl - 1] = mlpar_(&c__0, &pproc, &c__2, &mlphx3, &prot);

/* ***** WNETRZE SLOWNIK (KLASA LINK JEST NIEWIDOCZNA!!!) */
/*     ----AMEMBER: FUNCTION: PROCES */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    prot = mlinfp_(&c__1325, &pfl, &c__1, &c__0, &pproc, &slow, &prev);
    prev = prot;
/*       --OPIS PF */
    par = mlpar_(&c__0, &pproc, &c__2, &mlphx2, &prot);
    blank_1.ipmem[pfl - 1] = par;
    blank_1.ipmem[prot - 6] = par;
/*     ----DELETE: PROCEDURE(INPUT X: PROCES) */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    prot = mlinfp_(&c__2393, &pfl, &c__1, &c__0, &c__0, &slow, &prev);
    prev = prot;
/*       --OPIS PF */
    blank_1.ipmem[pfl - 1] = mlpar_(&c__0, &pproc, &c__3, &mlphx3, &prot);
/*     ----MIN: FUNCTION: PROCES */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    prot = mlinfp_(&c__835, &pfl, &c__1, &c__0, &pproc, &slow, &prev);
    prev = prot;
/*       --OPIS PF */
    par = mlpar_(&c__0, &pproc, &c__2, &mlphx2, &prot);
    blank_1.ipmem[pfl - 1] = par;
    blank_1.ipmem[prot - 6] = par;
/*     ----EMPTY: FUNCTION: BOOLEAN */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    prot = mlinfp_(&c__1837, &pfl, &c__1, &c__0, &blank_1.nrbool, &slow, &
	    prev);
    prev = prot;
/*       --OPIS PF */
    par = mlpar_(&c__0, &blank_1.nrbool, &c__2, &mlphx2, &prot);
    blank_1.ipmem[pfl - 1] = par;
    blank_1.ipmem[prot - 6] = par;
/*     ----INSERT: PROCEDURE(INPUT X: PROCES) */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    prot = mlinfp_(&c__2405, &pfl, &c__1, &c__0, &c__0, &slow, &prev);
    prev = prot;
/*       --OPIS PF */
    blank_1.ipmem[pfl - 1] = mlpar_(&c__0, &pproc, &c__2, &mlphx3, &prot);

/* ***** WNETRZE SEMAFOR */
/*     ----UNLOCKP: PROCEDURE */
/*       --PROTOTYP */
    prot = mlinfp_(&c__2413, &c__0, &c__0, &c__0, &c__0, &sem, &prev);
    prev = prot;
/*     ----LOCKP: PROCEDURE */
/*       --PROTOTYP */
    prot = mlinfp_(&c__2419, &c__0, &c__0, &c__0, &c__0, &sem, &prev);
    prev = prot;
/*     ----UP:  PROCEDURE */
/*       --PROTOTYP */
    prot = mlinfp_(&c__2421, &c__0, &c__0, &c__0, &c__0, &sem, &prev);
    prev = prot;
/*     ----TSP: FUNCTION: BOOLEAN */
/*       --LISTA PF */
    pfl = mgetm_(&c__1, &c__41);
/*       --PROTOTYP */
    prot = mlinfp_(&c__2425, &pfl, &c__1, &c__0, &blank_1.nrbool, &sem, &prev)
	    ;
/*       --OPIS PF */
    par = mlpar_(&c__0, &blank_1.nrbool, &c__2, &mlphx2, &prot);
    blank_1.ipmem[pfl - 1] = par;
    blank_1.ipmem[prot - 6] = par;

/* ******I TO JUZ KONIEC INICJALIZACJI */
    return 0;
} /* mlspp_ */

integer mlincl_(integer *hname, integer *prefnr, integer *sl, integer *prev)
{
    /* Initialized data */

    static integer mlchx1 = -16381;
    static integer mlchx2 = -24543;

    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer xx;
    extern integer mgetm_(integer *, integer *);
    static integer prefl;
    extern /* Subroutine */ int msetb_(integer *, integer *);
    static integer mlchx3;
    extern integer insert_(integer *, integer *, integer *);

/* ---------------------INICJUJE PROTOTYPY KLAS BIBLIOTECZNYCH Z SYSPP */


/* ALL BLANK */
/* dsw  DATA MLCLHEX1,MLCLHEX2,MLCLHEX3 /ZC003,ZA021,Z8000/ */
/*   #c003 --> -#3ffd, #a021 --> -#5fdf, #8000  --> undef */
    mlchx2 = 32768;
/* ALL # */

    ret_val = mgetm_(&c__33, &c__41) + 7;
    prefl = mgetm_(&c__1, &c__41);
    blank_1.ipmem[prefl - 1] = ret_val;
    blank_1.ipmem[ret_val - 7] = *prefnr;
    blank_1.ipmem[ret_val - 4] = 4;
    msetb_(&ret_val, prefnr);
    blank_1.ipmem[ret_val - 2] = *sl;
    blank_1.ipmem[ret_val - 1] = mlchx1;
    blank_1.ipmem[ret_val] = mlchx2;
    blank_1.ipmem[ret_val + 8] = mlchx3;
    blank_1.ipmem[ret_val + 21] = prefl;
    blank_1.ipmem[ret_val + 22] = 1;
/* ----DOLACZENIE DO LISTY NEXTDECL */
    blank_1.ipmem[*prev + 1] = ret_val;
    xx = insert_(hname, &blank_1.ipmem[*sl + 9], &c__41);
    blank_1.ipmem[xx + 1] = ret_val;
    return ret_val;
} /* mlincl_ */

integer mlinfp_(integer *hname, integer *fplist, integer *fpleng, integer *
	ndim, integer *ntype, integer *sl, integer *prev)
{
    /* Initialized data */

    static integer mlfhx1 = 513;
    static integer mlfhx2 = 1025;

    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i__, xx;
    extern integer mgetm_(integer *, integer *), insert_(integer *, integer *,
	     integer *);

/* -----------------------INICJUJE PROTOTYPY FUNKCJI I PROCEDUR Z SYSPP */


/* ALL BLANK */
/* dsw  DATA MLFPHEX1,MLFPHEX2/Z0201,Z0401/ */
/* ALL # */

    i__ = *sl + 10;
    if (*ntype == 0) {
	goto L100;
    }
/* -----FUNCKJA */
    ret_val = mgetm_(&c__29, &c__41) + 5;
    blank_1.ipmem[ret_val - 5] = *ndim;
    blank_1.ipmem[ret_val - 4] = *ntype;
/*     ---OPIS ATRYBUTU RESULT POWINIEN BYC WSTAWIONY NA ZEWNATRZ */
    blank_1.ipmem[ret_val - 1] = mlfhx1;
    goto L200;
/* -----PROCEDURA */
L100:
    ret_val = mgetm_(&c__26, &c__41) + 2;
    blank_1.ipmem[ret_val - 1] = mlfhx2;
/* -----OBYDWIE */
L200:
    blank_1.ipmem[ret_val - 2] = *sl;
    blank_1.ipmem[ret_val] = 1;
    blank_1.ipmem[ret_val + 2] = *fplist;
    blank_1.ipmem[ret_val + 3] = *fpleng;
/* ----DOLACZENIE DO NEXTDECL */
    blank_1.ipmem[*prev + 1] = ret_val;
    xx = insert_(hname, &blank_1.ipmem[i__ - 1], &c__41);
    blank_1.ipmem[xx + 1] = ret_val;
    return ret_val;
} /* mlinfp_ */

integer mlpar_(integer *ndim, integer *ntype, integer *off, integer *zerwrd, 
	integer *sl)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    extern integer mgetm_(integer *, integer *);

/* ----------------WPROWADZA OPIS PARAMETRU FORMALNEGO WRAZ Z OFFSETEM */


/* ALL BLANK */
/* ALL # */

    ret_val = mgetm_(&c__6, &c__41) + 4;
    blank_1.ipmem[ret_val - 5] = *ndim;
    blank_1.ipmem[ret_val - 4] = *ntype;
    blank_1.ipmem[ret_val - 2] = *sl;
    blank_1.ipmem[ret_val - 1] = *zerwrd;
    blank_1.ipmem[ret_val] = *off;
    return ret_val;
} /* mlpar_ */

/* Subroutine */ int tord_(integer *prnr)
{
    static integer name__;
    extern /* Subroutine */ int merr_(integer *, integer *);
    extern integer mgetm_(integer *, integer *);
    static integer olpml;
    extern /* Subroutine */ int tsort_(void), tgraph_(void), torder_(integer *
	    ), tzlink_(void), tsplit_(void);

/* --------------PROCEDURA PORZADKUJACA TYPY KLASOWE DEKLAROWANE W PROTO- */
/*             TYPIE O ADRESIE  PRNR . SORTOWANIE TOPOLOGICZNE ODBYWA SIE */
/*             ZE WZGLEDU NA PREFIKSOWANIE. */
/*             WYJSCIEM Z PROCEDURY JEST UPORZADKOWANA (W PROTOTYPIE  PRNR) */
/*             LISTA TYPOW W KOLEJNOSCI OBROBKI DEKLARACJI. EWENTUALNE CYKLE */
/*             SA ROZERWANE. */
/*          SYGNALIZOWANY BLAD: */
/*             399 - TYPY KLASOWE TWORZA CYKL ZE WZGLEDU NA PREFIKSOWANIE */
/*                       (PROCEDURA TSORT) */
/*             398 - PREFIKS I TYP PREFIKSOWANY JEST TEN SAM */

/* ----------------------------------------------------------------------------- */
/*             POMOCNICZE STRUKTURY DANYCH */

/*     W CZASIE TWORZENIA GRAFU DO SORTOWANIA UZYWANA JEST LOKALNA TABLICA */
/*     HASH'U  THASH. ELEMENT LISTY HASH'U BEDACY JEDNOCZESNIE ELEMENTEM */
/*     DO SORTOWANIA MA NASTEPUJACA BUDOWE: */
/*     --> 0 - NAZWA MODULU */
/*        +1 - LICZNIK ODWOLAN W CZSIE SORTOWANIA */
/*        +2 - POCZATEK LISTY NASTEPNIKOW, TZN. ELEMENTOW PREFIKSOWANYCH */
/*                 PRZEZ DANA KLASE */
/*        +3 - NASTEPNY ELEMENT W LISCIE HASH-U */
/*             W CZASIE SORTOWANIA - FLAGA "PROCESSED"= 1 GDY ELEMENT JEST */
/*             JUZ WSORTOWANY */
/*        +4 - NUMER PROTOTYPU W SLOWNIKU  ISDICT, */
/*              0 - GDY NAZWA OPISUJE PROTOTYP NIEZADEKLAROWANY W  PRNR */
/*              -1 - GDY TYP DEKLAROWANY BYL WIELOKROTNIE */
/*        +5 - NEXTZERO - INDEKS NASTEPNEGO ELEMENTU Z ZEROWYM LICZNIKIEM */
/*             PO WSORTOWANIU - INDEKS ELEMENTU NASTEPNEGO W UTWORZONYM */
/*             PORZADKU LINIOWYM */
/*        +6 - INDEKS NASTEPNEGO ELEMENTU W LISCIE DO SORTOWANIA */
/*             (UZYWANY DO WYKRYCIA CYKLI) */
/*        +7 - ELEMENT DO SORTOWANIA ODPOWIADAJACY BEZPOSREDNIEMU */
/*             PREFIKSOWI (UZYWANY PRZY ROZRYWANIU CYKLI) */

/*     ELEMENT LISTY NASTEPNIKOW (WSKAZYWANEJ PRZEZ SLOWO +2) MA POSTAC */
/*     --> 0 - ELEMENT DO SORTOWANIA ODPOWIADAJACY TYPOWI PREFIKSOWANEMU, */
/*             0 - GDY TEN NASTEPNIK ZOSTAL USUNIETY (ROZERWANY CYKL) */
/*        +1 - NASTEPNY ELEMENT LISTY */

/*     ELEMENTY WIELOKROTNIE DEKLAROWANE TWORZA POMOCNICZA LISTE WSKAZY- */
/*     WANA PRZEZ ZMIENNA  ELIST POSTACI: */
/*     --> 0 - NUMER PROTOTYPU W SLOWNIKU ISDICT */
/*        +1 - NASTEPNY ELEMENT LISTY */


/*     TE STRUKTURY PRZECHOWYWANE SA W  IPMEM ZA CZESCIA PRZEZNACZONA */
/*     NA PROROTYPY SYSTEMOWE. REZERWACJA PAMIECI JEST WYKONYWANA PRZEZ */
/*     PROCEDURE  MGETM . */

/* ----------------------------------------------------------------------------- */



/*             OPIS W DOKUMENTACJI:          D.II.4.1 */
/*             WERSJA Z DNIA:                19.01.82 */
/*             DLUGOSC KODU:        220 */
/* .......................................................................... */


/* ALL STREAM */
/* ALL BLANK */
/* ALL TC */
/* ALL # */
/* ............................................................................. */
/*             WSTEPNE ZBADANIE PROTOTYPU  PRNR */
/*     SORTOWANIE NIE JEST WYKONYWANE, GDY LISTA TYPOW ZAWIERA MNIEJ NIZ */
/*     DWA ELEMENTY */

    tc_1.ilt = blank_1.ipmem[*prnr + 4];
    if (tc_1.ilt == 0) {
	return 0;
    }
    if (blank_1.ipmem[tc_1.ilt] == 0) {
	goto L300;
    }

/* ............................................................................. */

/* INICJALIZACJA ZMIENNYCH */
    tc_1.slist = 0;
    tc_1.elist = 0;
    tc_1.snumb = 0;
    olpml = blank_1.lpml;
    tc_1.inord = mgetm_(&c__8, &c__0);
    tc_1.outord = tc_1.inord;
    tc_1.zfirst = 0;

/* ******************************************* */
/*           UTWORZENIE GRAFU POWIAZAN ORAZ LIST TYPOW DO SORTOWANIA */

    tgraph_();

/* ******************************************* */
/*           SORTOWANIE TOPOLOGICZNE */

    if (tc_1.snumb == 0) {
	goto L200;
    }
/*        --LISTA DO SORTOWANIA JEST PUSTA */

    tzlink_();
/*        -- LACZENIE W LISTE ELEMENTOW Z ZEROWYM LICZNIKIEM */

L100:
    tsort_();
    if (tc_1.snumb == 0) {
	goto L200;
    }
/*        -- GDY SNUMB JEST ROZNE OD ZERA, TO ISTNIEJE CYKL. WOWCZAS */
/*        ROZERWANIE CYKLU I MODYFIKACJA GRAFU ORAZ LISTY ELEMENTOW */
/*        Z ZEROWYM LICZNIKIEM I PONOWNE SORTOWANIE */

    tsplit_();
    goto L100;

/* ******************************************** */
/*           ODTWORZENIE LISTY TYPOW W KOLEJNOSCI DO OBROBKI */
/*           DEKLARACJI */

L200:
    torder_(prnr);
    blank_1.lpml = olpml;
    return 0;

/* ************************************************ */
/*     SPRAWDZENIE, CZY TYP DO SORTOWANIA NIE JEST PREFIKSOWANY */
/*     PRZEZ SAMEGO SIEBIE */
L300:
    tc_1.ilt = blank_1.ipmem[tc_1.ilt - 1];
/*          ILT - NUMER W ISDICT PROTOTYPU SORTOWANEGO */
    tc_1.ilt = blank_1.ipmem[tc_1.ilt - 1];
/*             ILT - PROTOTYP SORTOWANY */
    if (blank_1.ipmem[tc_1.ilt + 1] == blank_1.nempty) {
	return 0;
    }
/*           PROTOTYP NIE JEST PREFIKSOWANY - POWROT */
    name__ = blank_1.ipmem[tc_1.ilt + 9];
    if (name__ != blank_1.ipmem[tc_1.ilt + 1]) {
	return 0;
    }
/*         NAZWY SA ROZNE - POWROT */
/*     ...SYGNALIZACJA BLEDU */
    stream_1.line = blank_1.ipmem[tc_1.ilt + 8];
    merr_(&c__398, &name__);
    blank_1.ipmem[tc_1.ilt + 1] = blank_1.nempty;
    blank_1.ipmem[tc_1.ilt - 1] = 7;
/*           ZAMARKOWANIE USZKODZONEJ LISTY PARAMETROW */
    return 0;
} /* tord_ */

/* Subroutine */ int tgraph_(void)
{
    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i__, iht, inp, name__, prad;
    extern /* Subroutine */ int merr_(integer *, integer *);
    static integer dictn, thash[8];
    extern integer mgetm_(integer *, integer *), member_(integer *, integer *)
	    ;

/* --------------UTWORZENIE GRAFU POWIAZAN, LIST TYPOW DO SORTOWANIA */
/*             ORAZ WIELOKROTNIE DEKLAROWANYCH */

/*             OPIS W DOKUMENTACJI:             D.II.4.2 */
/*             WERSJA Z DNIA:                   19.01.82 */
/*             DLUGOSC KODU:        590 */
/* ...................................................................... */

/* dsw  INTEGER THASH(8) */
/*             POMOCNICZA TABLICA HASH-U */

/* ALL BLANK */
/* ALL TC */
/* ALL STREAM */
/* ALL # */
/*     ZNACZENIE ZMIENNYCH */
/*       ILT - ELEMENT LISTY DEKLAROWANYCH TYPOW */
/*       DICTN - NUMER PROTOTYPU W SLOWNIKU ISDICT */
/*       PRAD - ADRES PROTOTYPU W  IPMEM */
/*       NAME - NAZWA TYPU */
/*       IHT - ELEMENT LISTY HASH-U */


    for (i__ = 1; i__ <= 8; ++i__) {
	thash[i__ - 1] = 0;
/* L10: */
    }

/* ***************************************************************************** */
/*             PRZETWARZANIE ELEMENTU  ILT  Z LISTY TYPOW */

L1000:
    dictn = blank_1.ipmem[tc_1.ilt - 1];
    prad = blank_1.ipmem[dictn - 1];
    name__ = blank_1.ipmem[prad + 9];
    if (name__ == blank_1.nempty) {
	goto L2500;
    }
/*             NAZWA PUSTA - SKOK DO WPISANIA TYPU DO LISTY TYPOW ZLE */
/*             ZADEKLAROWANYCH */
/* --------------------------------------------------------------------------- */
/*     SPRAWDZENIE, CZY TYP NIE JEST PREFIKSOWANY SAM SOBA */
    if (name__ != blank_1.ipmem[prad + 1]) {
	goto L1050;
    }
    stream_1.line = blank_1.ipmem[prad + 8];
    merr_(&c__398, &name__);
    blank_1.ipmem[prad + 1] = blank_1.nempty;
    blank_1.ipmem[prad - 1] = 7;
L1050:
/* ----------------------------------------------------------------------------- */
/*     ODSZUKANIE NAZWY */
    iht = member_(&name__, thash);
    if (iht == 0) {
	goto L1100;
    }
/* .....TU - NAZWA JUZ WYSTEPUJE W LISCIE HASH-U */
/*     SPRAWDZENIE ,CZY POPRZEDNIE WYSTAPIENIE NIE BYLO DEKLARACJA NAZWY, */
/*     JESLI TAK -TO BLAD */
    if (blank_1.ipmem[iht + 3] != 0) {
	goto L2000;
    }
/*             BYLA WCZESNIEJ DEKLAROWANA, SKOK DO ZLE ZADEKLAROWANEGO TYPU */
    goto L1200;

/* ----------------------------------------------------------------------------- */
/*     TWORZENIE NOWEGO ELEMENTU LISTY DO SORTOWANIA */
L1100:
    iht = mgetm_(&c__8, &c__0);
    blank_1.ipmem[iht - 1] = name__;
    i__ = (lbit_shift(name__, (ftnlen)-1) & 7) + 1;
    blank_1.ipmem[iht + 2] = thash[i__ - 1];
    thash[i__ - 1] = iht;
/*     WLACZENIE DO LISTY TYPOW DO SORTOWANIA */
    blank_1.ipmem[iht + 5] = tc_1.slist;
    tc_1.slist = iht;
    ++tc_1.snumb;
/*     WPISANIE NUMERU PROTOTYPU */
L1200:
    blank_1.ipmem[iht + 3] = dictn;

/* ----------------------------------------------------------------------------- */
/*     SPRAWDZENIE PREFIKSOWANIA */
/*             INP - NAZWA BEZPOSREDNIEGO PREFIKSU */
    inp = blank_1.ipmem[prad + 1];
    if (inp == 0) {
	goto L5000;
    }
/*             TYP NIE JEST PREFIKSOWANY - SKOK DO POBRANIA NASTEPNEGO */
/*             ELEMENTU LISTY TYPOW */
/* ----------------------------------------------------------------------------- */
/*     WYSZUKANIE NAZWY PREFIKSU */
/*             PRAD - ELEMENT DO SORTOWANIA ODPOWIADAJACY PREFIKSOWI */
    prad = member_(&inp, thash);
    if (prad != 0) {
	goto L1300;
    }
/*             SKOK, GDY ELEMENT ODPOWIADAJACY PREFIKSOWI JEST JUZ */
/*             W LISCIE DO SORTOWANIA */
/*     WPROWADZENIE NOWEGO OPISU */
    prad = mgetm_(&c__8, &c__0);
    blank_1.ipmem[prad - 1] = inp;
    i__ = (lbit_shift(inp, (ftnlen)-1) & 7) + 1;
    blank_1.ipmem[prad + 2] = thash[i__ - 1];
    thash[i__ - 1] = prad;
    blank_1.ipmem[prad + 5] = tc_1.slist;
    tc_1.slist = prad;
    ++tc_1.snumb;
/* --------UTWORZENIE POWIAZANIA */
L1300:
    i__ = mgetm_(&c__2, &c__0);
    blank_1.ipmem[i__ - 1] = iht;
    blank_1.ipmem[i__] = blank_1.ipmem[prad + 1];
    blank_1.ipmem[prad + 1] = i__;
    blank_1.ipmem[iht + 6] = prad;
    blank_1.ipmem[iht] = 1;
/* -------PRZEJSCIE DO POBIERANIA NASTEPNEGO ELEMENTU LISTY TYPOW */
    goto L5000;

/* ----------------------------------------------------------------------------- */
/*     TYPY ZLE ZADEKLAROWANE */

/* ------TYPY DEKLAROWANE WIELOKROTNIE */
L2000:
    if (blank_1.ipmem[iht + 3] == -1) {
	goto L2500;
    }
/* -------PRZESUNIECIE TYPU WCZESNIEJ DEKLAROWANEGO DO LISTY TYPOW */
/*     ZLE ZADEKLAROWANYCH */
    inp = iht;
    i__ = blank_1.ipmem[inp + 3];
    blank_1.ipmem[inp + 3] = -1;
    iht = mgetm_(&c__2, &c__0);
    blank_1.ipmem[iht - 1] = i__;
    blank_1.ipmem[iht] = tc_1.elist;
    tc_1.elist = iht;
/* -------USUNIECIE KRAWEDZI W PREFIKSIE TEGO TYPU */
    iht = blank_1.ipmem[inp + 6];
/*          IHT - GDY ROZNE OD ZERA JEST OPISEM ELEMENTU ODPOWIADAJACEGO */
/*         PREFIKSOWI */
    if (iht == 0) {
	goto L2500;
    }
/* .....USUNIECIE KRAWEDZI W LISCIE NASTEPNIKOW PREFIKSU */
    iht = blank_1.ipmem[iht + 1];
/*          IHT - ELEMENT LISTY NASTEPNIKOW */
L2100:
    if (iht == 0) {
	goto L2500;
    }
    if (blank_1.ipmem[iht - 1] == inp) {
	goto L2200;
    }
/*         TO BYL ELEMENT ODPOWIADAJACY POLACZENIU */
    iht = blank_1.ipmem[iht];
    goto L2100;
L2200:
    blank_1.ipmem[iht - 1] = 0;
    blank_1.ipmem[inp] = 0;
/* ------DOLACZENIE AKTUALNEGO TYPU DO LISTY TYPOW ZLE ADEKLAROWANYCH */
L2500:
    iht = mgetm_(&c__2, &c__0);
    blank_1.ipmem[iht - 1] = dictn;
    blank_1.ipmem[iht] = tc_1.elist;
    tc_1.elist = iht;
/* ----------------------------------------------------------------------------- */
/*     POBRANIE NASTEPNEGO ELEMENTU LISTY TYPOW */
L5000:
    tc_1.ilt = blank_1.ipmem[tc_1.ilt];
    if (tc_1.ilt != 0) {
	goto L1000;
    }
/* ***************************************************************************** */
    return 0;
} /* tgraph_ */

/* Subroutine */ int tzlink_(void)
{
    static integer i__, ipr;

/* --------------LACZENIE W LISTE ROZPOCZYNAJACA SIE OD ZFIRST */
/*             ELEMENTOW Z ZEROWYM LICZNIKIEM. */
/*             ///PRZY OKAZJI USUNIECIE W PROTOTYPACH PREFIKSOW ODPOWIADAJACYCH */
/*             TYPOM WIELOKROTNIE DEKLAROWANYM */

/*             OPIS W DOKUMENTACJI:          D.II.4.3 */
/*             WERSJA Z DNIA:                19.01.82 */
/*             DLUGOSC KODU:        135 */
/* ........................................................................ */


/* ALL BLANK */
/* ALL TC */
/* ALL # */

    i__ = tc_1.slist;
/* ***************************************************************************** */
L1000:
    ipr = blank_1.ipmem[i__ + 6];
    if (blank_1.ipmem[ipr + 3] != -1) {
	goto L1100;
    }
/* --------USUNIECIE PREFIKSU Z PROTOTYPU , GDY PREFIKS */
/*     BYL TYPEM ZLE ZADEKLAROWANYM */
    ipr = blank_1.ipmem[i__ + 3];
    ipr = blank_1.ipmem[ipr - 1];
    blank_1.ipmem[ipr + 1] = blank_1.nempty;
    blank_1.ipmem[ipr - 1] = 7;
/*         ZAMARKOWANIE BLEDNEJ LISTY PARAMETROW */
    blank_1.ipmem[i__] = 0;
L1100:
    if (blank_1.ipmem[i__] != 0) {
	goto L1500;
    }
    blank_1.ipmem[i__ + 4] = tc_1.zfirst;
    tc_1.zfirst = i__;
L1500:
    blank_1.ipmem[i__ + 2] = 0;
/*             USTAWIENIE FLAGI "PROCESSED" */
/* ------POBRANIE NASTEPNEGO ELEMENTU LISTY DO SORTOWANIA */
    i__ = blank_1.ipmem[i__ + 5];
    if (i__ != 0) {
	goto L1000;
    }
/* ***************************************************************************** */
    return 0;
} /* tzlink_ */

/* Subroutine */ int tsort_(void)
{
    static integer i__, ine;

/* --------------SORTOWANIE TOPOLOGICZNE - CZESC WLASCIWA */

/*             OPIS W DOKUMENTACJI:           D.II.4.4 */
/*             WERSJA Z DNIA:                 19.01.82 */
/*             DLUGOSC KODU:        146 */
/* ................................................................... */


/* ALL BLANK */
/* ALL TC */
/* ALL # */

/*     ILT - ROZPATRYWANY ELEMENT Z ZEROWYM LICZNIKIEM */
L1000:
    tc_1.ilt = tc_1.zfirst;
    if (tc_1.ilt == 0) {
	return 0;
    }
    tc_1.zfirst = blank_1.ipmem[tc_1.ilt + 4];
    blank_1.ipmem[tc_1.outord + 4] = tc_1.ilt;
    tc_1.outord = tc_1.ilt;
    --tc_1.snumb;
/*     USTAWIENIE FLAGI "PROCESSED" */
    blank_1.ipmem[tc_1.ilt + 2] = 1;
/*     ZMNIEJSZENIE LICZNIKOW ELEMENTOM PREFIKSOWANYM */
/*     PRZEZ ILT */
/*     ....SPRAWDZENIE, CZY SORTOWANY PROTOTYP NIE JEST PROTOTYPEM */
/*     ZLYCH DEKLARACJI - DLA NIEGO NIE MA ELEMENTOW PREFIKSOWANYCH */
    if (blank_1.ipmem[tc_1.ilt + 3] == -1) {
	goto L1500;
    }
/*     INE - ELEMENT LISTY NASTEPNIKOW */
    ine = blank_1.ipmem[tc_1.ilt + 1];
L1100:
    if (ine == 0) {
	goto L1500;
    }
    i__ = blank_1.ipmem[ine - 1];
    if (i__ == 0) {
	goto L1200;
    }
/*             SKOK, GDY POLACZENIE JEST OMINIETE */
/*     I -ELEMENT ODPOWIADAJACY TYPOWI PREFIKSOWANEMU */
    blank_1.ipmem[i__] = 0;
    blank_1.ipmem[i__ + 4] = tc_1.zfirst;
    tc_1.zfirst = i__;
/*     POBRANIE NASTEPNEGO ELEMENTU LISTY NASTEPNIKOW */
L1200:
    ine = blank_1.ipmem[ine];
    goto L1100;
/* -------POBRANIE NASTEPNEGO ELEMENTUU DO SORTOWANIA */
L1500:
    goto L1000;
} /* tsort_ */

/* Subroutine */ int tsplit_(void)
{
    static integer ie, ipr, name__, lmin;
    extern /* Subroutine */ int merr_(integer *, integer *);
    static integer iloop;

/* --------------PROCEDURA ROZRYWANIA CYKLI W LISCIE TYPOW DO */
/*             PRZETWORZENIA. */
/*             ZNAJDUJE TYP NAJWCZESNIEJ DEKLAROWANY, USUWA MU PREFIKS */
/*             I MODYFIKUJE GRAF DO SORTOWANIA */
/*     SYGNALIZOWANY BLAD: */
/*             399 - WYSTAPIENIE CYKLU W PREFIKSOWANIU */

/*             OPIS W DOKUMENTACJI:           D.II.4.5 */
/*             WERSJA Z DNIA:                 19.01.82 */
/*             DLUGOSC KODU:        287 */
/* .................................................................. */


/* ALL STREAM */
/* ALL BLANK */
/* ALL TC */
/* ALL # */

/*     ILT - ELEMENT LISTY DO SORTOWANIA ODPOWIADAJACY NAJWCZESNIEJ */
/*             DEKLAROWANEMU PROTOTYPOWI */
/*     LMIN - NUMER NAJWCZESNIEJSZEJ LINII */
/*     IE - AKTUALNY ELEMENT LISTY DO SORTOWANIA */

    ie = tc_1.slist;
    lmin = 32767;
/*         NAJWIEKSZA STALA CALKOWITA */
/* ***************************************************************************** */
L1000:
    if (blank_1.ipmem[ie + 2] == 1) {
	goto L1500;
    }
/*             SKOK, GDY TEN TYP JEST JUZ PRZETWORZONY */
    ipr = blank_1.ipmem[ie + 3];
    ipr = blank_1.ipmem[ipr - 1];
/*     IPR - PROTOTYP TYPU ODPOWIADAJACEGO  IE */
    stream_1.line = blank_1.ipmem[ipr + 8];
    if (stream_1.line > lmin) {
	goto L1500;
    }
/* ....TU POTENCJALNY KANDYDAT NA USUNIECIE CYKLU */
/*     SPRAWDZENIE, CZY TEN ELEMENT WYSTEPUJE W CYKLU */
    iloop = ie;
/*       MARKOWANIE CYKLU */
L1100:
    blank_1.ipmem[iloop + 2] = -1;
    iloop = blank_1.ipmem[iloop + 6];
/*           TO JEST PREFIKS ILOOP */
    if (blank_1.ipmem[iloop + 2] != -1) {
	goto L1100;
    }
    if (iloop != ie) {
	goto L1200;
    }
/*     --WYSTAPIL W CYKLU */
    lmin = stream_1.line;
    tc_1.ilt = ie;
/*     --PRZYWROCENIE STAREGO MARKOWANIA CYKLU */
L1200:
    iloop = ie;
L1300:
    blank_1.ipmem[iloop + 2] = 0;
    iloop = blank_1.ipmem[iloop + 6];
    if (blank_1.ipmem[iloop + 2] != 0) {
	goto L1300;
    }
/* ---------POBRANIE NASTEPNEGO ELEMENTU LISTY DO SORTOWANIA */
L1500:
    ie = blank_1.ipmem[ie + 5];
    if (ie != 0) {
	goto L1000;
    }

/* ***************************************************************************** */
/*     ILT JEST PROTOTYPEM TYPU NAJWCZESNIEJ DEKLAROWANEGO */
    ipr = blank_1.ipmem[tc_1.ilt + 3];
    ipr = blank_1.ipmem[ipr - 1];
    name__ = blank_1.ipmem[ipr + 9];
    stream_1.line = lmin;
/*     ...SYGNALIZACJA BLEDU */
    merr_(&c__399, &name__);
/* ......USUNIECIE PREFIKSU */
    blank_1.ipmem[ipr + 1] = 0;
/* ......"USZKODZENIE" LISTY PARAMETROW */
    blank_1.ipmem[ipr - 1] = 7;
/* .....WSTAWIENIE DO LISTY ELEMENTOW Z ZEROWYM LICZNIKIEM */
    tc_1.zfirst = tc_1.ilt;
/* ------USUNIECIE POWIAZANIA Z PREFIKSEM */
    ipr = blank_1.ipmem[tc_1.ilt + 6];
/*             IPR - ELEMENT LISTY DO SORTOWANIA ODPOWIADAJACY PREFIKSOWI */
    ipr = blank_1.ipmem[ipr + 1];
/*             LISTA NASTEPNIKOW PREFIKSU */
L2000:
    if (blank_1.ipmem[ipr - 1] == tc_1.ilt) {
	goto L2100;
    }
    ipr = blank_1.ipmem[ipr];
    goto L2000;
L2100:
    blank_1.ipmem[ipr - 1] = 0;
    return 0;
} /* tsplit_ */

/* Subroutine */ int torder_(integer *prnr)
{
/* ------------WPISANIE DO LISTY TYPOW PRNR TYPOW TAM DEKLAROWANYCH */
/*             W KOLEJNOSCI OBROBKI DEKLARACJI */

/*             OPIS W DOKUMENTACJI:         D.II.4.6 */
/*             WERSJA Z DNIA:               19.01.82 */
/*             DLUGOSC KODU:        117 */
/* ......................................................................... */



/* ALL BLANK */
/* ALL TC */
/* ALL # */

    tc_1.ilt = blank_1.ipmem[*prnr + 4];
/*       ILT - ELEMENT LISTY TYPOW DEKLAROWANYCH */

/* ***************************************************************************** */
/*     WPISANIE TYPOW Z LISTY INORD (NA POCZATKU JEST STRAZNIK) */
L1000:
    tc_1.inord = blank_1.ipmem[tc_1.inord + 4];
    if (tc_1.inord == 0) {
	goto L2000;
    }
    if (blank_1.ipmem[tc_1.inord + 3] <= 0) {
	goto L1000;
    }
/*             -OMINIECIE TYPOW NIELOKALNYCH */
    blank_1.ipmem[tc_1.ilt - 1] = blank_1.ipmem[tc_1.inord + 3];
    tc_1.ilt = blank_1.ipmem[tc_1.ilt];
    goto L1000;
/* ***************************************************************************** */
/*     WPISANIE TYPOW Z LISTY TYPOW ZLE ZADEKLAROWANYCH */
L2000:
    if (tc_1.elist == 0) {
	return 0;
    }
    blank_1.ipmem[tc_1.ilt - 1] = blank_1.ipmem[tc_1.elist - 1];
    tc_1.elist = blank_1.ipmem[tc_1.elist];
    tc_1.ilt = blank_1.ipmem[tc_1.ilt];
    goto L2000;
} /* torder_ */

