/* it0.f -- translated by f2c (version 20090411).
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
	integer c0m[4], s, adres, k;
    } _1;
    struct {
	integer com[278], lmem, lpmem, irecn, isfin, lpmsys, lpml, lpmf, 
		nrint, nrre, nrbool, nrchr, nrcor, nrproc, nrtext, nruniv, 
		nattr, nrnone, nblsys, nblus, nempty;
	logical insys;
	integer local;
	logical own;
	integer object, ipmem[5000];
    } _2;
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
	integer jk1, exp__, sign, intpart, frac;
	logical okey;
	real fract;
	integer jk2, nb, tl, byte, text[20], top, in, next, stack[500], 
		reszta[3652];
    } _3;
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
	integer jk1, exp__, sign, intpart, frac, okey;
	real fract;
	integer jk2, nb, tl, byte, text[20], top, in, next, stack[500], 
		reszta[3652];
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
		insys, local, own, object, hash[8000], m, name__[10], nlast, 
		nl, keys[200], trans1[169]	/* was [13][13] */, trans2[
		169]	/* was [13][13] */, b0, b[70], skok0, skok[70], kk, 
		mm, stan, stan1, aux, k1, sy, sy1, nu, exp__, sign, intpart, 
		frac, okey, fract, nb, tl, byte, text[20], top, in, next, 
		stack[500], reszta[3652];
    } _5;
    struct {
	integer iop[4], p, tldim, tlbas, idl, objl, trdim, trbas, idr, objr, 
		treslt, convl, convr, nrpar, ix[261], lmem, lpmem, irecn, 
		isfin, lpmsys, lpml, lpmf, nrint, nrre, nrbool, nrchr, nrcor, 
		nrproc, nrtext, nruniv, nattr, nrnone, nblsys, nblus, nempty;
	logical insys;
	integer local;
	logical own;
	integer object, ipmem[5000];
    } _6;
} blank_;

#define blank_1 (blank_._1)
#define blank_2 (blank_._2)
#define blank_3 (blank_._3)
#define blank_4 (blank_._4)
#define blank_5 (blank_._5)
#define blank_6 (blank_._6)

union {
    struct {
	integer ierc;
	char msg[4];
    } _1;
    struct {
	integer ierc, msg;
    } _2;
} mjlmsg_;

#define mjlmsg_1 (mjlmsg_._1)
#define mjlmsg_2 (mjlmsg_._2)

struct {
    char param[256];
    integer dl, pozopt;
} par_;

#define par_1 par_

struct {
    char jfname[72];
    integer jf;
} jf_;

#define jf_1 jf_

/* Table of constant values */

static integer c__0 = 0;
static integer c__70 = 70;

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
/* 	files used by compiler : */

/* 	unit	file description */

/* 	13	output sequential (F)	  listing (.LST)          (ML2,     ) */
/* 	14	temporary direct  (C)     code after parser       (WAN1, ML2) */
/* 	15	output sequential (C)     L-code (.LCD)           (WAN1, ML2) */
/* 	16	temporary sequential (C)  listing                 (WAN1, ML2) */
/* 	17	input sequential (C)      source                  (WAN1, ML2) */
/* 	18	temporary sequential (C)  L-code                  (WAN1, AL11) */
/* 	19	temporary direct (C)      errors                  (WAN2, ML2) */
/*       21      output sequential (C)     debugger                (WAN1, ML2) */

/* Subroutine */ int loglan_(integer *parlen, char *parbuf, ftnlen parbuf_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int wan_(void), data_(void), mess_(void), data2_(
	    void), data3_(void), ffgets_(integer *, char *, integer *, ftnlen)
	    , ffputcs_(integer *, char *, ftnlen), ffputnl_(integer *);

/*  parlen - dlugosc linii z parametrami dla kompilatora */
/*  parbuf - bufor zawierajacy parametry dla kompilatora */
/* ======================================================================C */
/* 								       C */
/* 			 LOGLAN L-COMPILER			       C */
/* 			 =================			       C */
/* 								       C */
/*     AUTHORS:							       C */
/* 								       C */
/* 	       DANKA SZCZEPANSKA-WASERSZTRUM			       C */
/* 	       MAREK J. LAO					       C */
/* 	       ANDRZEJ I. LITWINIUK				       C */
/* 	       WOJTEK A. NYKOWSKI				       C */
/* 								       C */
/* 	       IIUW, WARSZAWA, 1982				       C */
/* 								       C */
/*     PORTED TO SIEMENS 7760 BS2000 BY: 			       C */
/* 								       C */
/* 	       PAWEL K. GBURZYNSKI				       C */
/* 	       MANFRED KRAUSE					       C */
/* 	       ANDRZEJ I. LITWINIUK				       C */
/* 								       C */
/* 	       IIPMCAU, KIEL, MAY-JUNE 1984			       C */
/*                                                                      C */
/*     PORTED TO IBM PC BY                                              C */
/*              Danuta Szczepanska                                      C */
/*              Boleslaw Ciesielski                                     C */
/*              Teresa Przytycka                                        C */
/*                                                                      C */
/*     PORTED TO VAX / VMS BY                                           C */
/*              Danuta Szczepanska                                      C */
/*              Andrzej Litwiniuk                                       C */
/* 								       C */
/*     PORTED TO XENIX SCO BY                                           C */
/*              Pawel Susicki                                           C */
/* 								       C */
/*     PORTED TO UNIX SCO BY                                            C */
/*              Pawel Susicki                                           C */
/* 								       C */
/*     PORTED TO SUN SPARC BY                                           C */
/*              Pawel Susicki                                           C */
/* 								       C */
/* ======================================================================C */
/* ======================================================================C */
/*    THE FOLLOWING FILE UNITS ARE USED: 			       C */
/* 								       C */
/* 	 1 - INTERACTIVE INPUT FROM THE TERMINAL		       C */
/* 	 2 - INTERACTIVE OUTPUT TO THE TERMINAL 		       C */
/* 	13 - LISTING OUTPUT					       C */
/* 	14 - WORKING FILE SCRATCH				       C */
/* 	15 - L-CODE OUTPUT					       C */
/* 	16 - PARTIAL LISTING FROM PARSER			       C */
/* 	17 - SOURCE INPUT TO THE COMPILER			       C */
/* 	18 - AUXILIARY SOURCE INPUT				       C */
/* 	19 - SCRATCH FILE INCLUDING INFO ABOUT COMPILATION ERRORS      C */
/* ======================================================================C */
/* dsw	byte	  jfname */
/*   param - line of program parameters */
/*   dl - length of program parameters */
/*   pozopt -  options position in param */
    /* Parameter adjustments */
    --parbuf;

    /* Function Body */
    ffputnl_(&c__0);
    ffputcs_(&c__0, " LOGLAN-82  UNIX Compiler, Version 2.1", (ftnlen)38);
    ffputnl_(&c__0);
    ffputcs_(&c__0, " January 10, 1993", (ftnlen)17);
    ffputnl_(&c__0);
    ffputcs_(&c__0, " (C)Copyright  Institute of Informatics,", (ftnlen)40);
    ffputcs_(&c__0, " University of Warsaw", (ftnlen)21);
    ffputcs_(&c__0, " (C)Copyleft   LITA Universite de Pau", (ftnlen)37);
    ffputnl_(&c__0);
    mjlmsg_1.ierc = 0;
    s_copy(mjlmsg_1.msg, "it0 ", (ftnlen)4, (ftnlen)4);
    for (jf_1.jf = 1; jf_1.jf <= 70; ++jf_1.jf) {
/* L10: */
	*(unsigned char *)&jf_1.jfname[jf_1.jf - 1] = ' ';
    }
    i__1 = *parlen;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L15: */
	*(unsigned char *)&par_1.param[i__ - 1] = *(unsigned char *)&parbuf[
		i__];
    }
    par_1.dl = *parlen;
    if (par_1.dl != 0) {
	goto L100;
    }
    par_1.pozopt = 0;
L200:
/*  prompt */
    ffputcs_(&c__0, " File name: ", (ftnlen)12);
    ffgets_(&c__0, par_1.param, &c__70, (ftnlen)1);
    par_1.dl = 70;
/* file name is in  param */
L100:
    i__1 = par_1.dl;
    for (par_1.pozopt = 1; par_1.pozopt <= i__1; ++par_1.pozopt) {
	if (*(unsigned char *)&par_1.param[par_1.pozopt - 1] != ' ') {
	    goto L30;
	}
/* L20: */
    }
    goto L200;
L30:
    jf_1.jf = 0;
L50:
    if (*(unsigned char *)&par_1.param[par_1.pozopt - 1] == ' ' || *(unsigned 
	    char *)&par_1.param[par_1.pozopt - 1] == ',' || *(unsigned char *)
	    &par_1.param[par_1.pozopt - 1] == ';') {
	goto L300;
    }
    if (jf_1.jf >= 70) {
	goto L40;
    }
    ++jf_1.jf;
    *(unsigned char *)&jf_1.jfname[jf_1.jf - 1] = *(unsigned char *)&
	    par_1.param[par_1.pozopt - 1];
L40:
    ++par_1.pozopt;
    if (par_1.pozopt <= par_1.dl) {
	goto L50;
    }
L300:
    if (jf_1.jf == 0) {
	goto L200;
    }
/* L500: */
    data3_();
    data_();
    data2_();
    mess_();
    wan_();
    return 0;
} /* loglan_ */

/* Subroutine */ int data3_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int ffexit_(void), ffputcs_(integer *, char *, 
	    ftnlen), ffputnl_(integer *);


/*  INITIATES THE BLANK COMMON */
/*  FIXES DIVISION OF IPMEM INTO COMPILER TABLES */


/* dsw&bc     X	      IPMEM(50000) */

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


/*      IN THIS PLACE THE SIZE OF IPMEM MAY BE REDECLARED; THEN THE */
/*      VARIABLE LMEM (BELOW) SHOULD BE SET TO THE LENGTH OF IPMEM. */


/*  IPMEM - MAIN MEMORY AREA OF THE COMPILER */
/*  LPML  - ADDRESS OF THE FIRST - */
/*  LPMF  - ADDRESS OF THE LAST FREE WORD IN IPMEM */
/*  ISFIN - TOP OF THE DICTIONARY OF PROTOTYPES */
/*  LPMEM - DIVISION POINT OF IPMEM */
/*  LMEM  - LENGTH OF IPMEM */

    blank_2.com[0] = 0;
    blank_2.lmem = 70000;
    blank_2.lpmem = 48001;
    if (blank_2.lpmem > 4550) {
	goto L1;
    }
/* --- SIZE OF IPMEM TOO SMALL */
    ffputcs_(&c__0, " Fatal Error:  Memory overflow ", (ftnlen)31);
    ffputnl_(&c__0);
    ffexit_();
/* -- */
L1:
    i__1 = blank_2.lmem;
    for (i__ = 3738; i__ <= i__1; ++i__) {
/* L10: */
	blank_2.ipmem[i__ - 1] = 0;
    }
/* --- 2 BELOW STANDS FOR THE SIZE OF REAL NUMBER EXPRESSED IN THE */
/* --- NUMBER OF INTEGERS WHICH COVERS THIS SIZE. */
/* vax  the size of real numbers on vax is 4 bytes ( = the size of integer) */
/* vax  LPML=LPMEM+2 */
/* dsw  lpml - first free place in real constants */
/* dsw  in the future -  (lpmem+1) = 0.0, (lpmem+2) = 1.0 */
    blank_2.lpml = blank_2.lpmem + 1;

/*  THE FIRST REAL CONSTANT IS 0.0 */

    blank_2.lpmf = blank_2.lmem;
    blank_2.isfin = blank_2.lpmem - 1;
    return 0;
} /* data3_ */

/* Subroutine */ int data_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
#define x ((integer *)&blank_3 + 8515)
#define y ((integer *)&blank_3 + 8684)
    extern /* Subroutine */ int daata_(void);
    static integer schar, dathx1, dathx2, dathx3;
    extern /* Subroutine */ int optdef_(void);

/* dsw  INTEGER DATAHEX1,DATAHEX2,DATAHEX3 */
/* dsw  DATA    DATAHEX1,DATAHEX2,DATAHEX3 /Z802F,Z0000,ZFFFF/ */

/*   INITIATES THE BLANK COMMON */

/*     DATA M,HASH,NAME,NLAST,NL /1009,3000*0,10*0,3001,10/ */
/*      #8027 zmienione na #002F - w zapisie uzupelnieniowym */
    dathx1 = 47;
    dathx2 = 0;
/*     #ffff zmienione na -#0001 */
    dathx3 = -1;
    blank_3.m = 1009;
/* dsw  NLAST=3001 */
    blank_3.nlast = 8001;
    blank_3.nl = 10;
/* dsw  DO 2 I=1,3000 */
/* dsw2 HASH(I)=0 */
    i__1 = blank_3.nl;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L3: */
	blank_3.name__[i__ - 1] = 0;
    }
/*     DATA TRANS2 /1,3,5,8,3,10,10,16,18,1,10,10,20,2,1,1,8,1,14,14,16, */
/*    ,18, */
/*    ,1,14,1,20,1,3,1,9,11,14,14,16,18,1,14,14,20,1,3,6,8,12,14,14,16, */
/*    ,18,1,14,14,20,1,4,7,8,4,15,15,16,18,1,14,14,20,1,3,1,8,13,14,14,16 */
/*    ,,18,1,14,14,20,1,4,7,8,4,15,15,16,18,1,14,14,20,1,3,7,8,3,14,14,16 */
/*    ,,18,1,14,14,20,1,3,6,10,3,14,14,16,18,1,14,14,20,1,3,1,8,3,14,14, */
/*    ,16, */
/*    ,18,1,14,14,20,7*1,17,14*1,19,15*1,21/ */
/*     DATA TRANS1 /1,1,9,5*1,16,17,1,1,1,2,4,4,2,4,2,2,2,16,17,2,4,2,1,5 */
/*    ,,10,1,1,5,5,5,16,17,5,5,5,1,7,11,7,1,7,7,7,16,17,7,7,7,1,5,12,7,5, */
/*    ,15,1,7,16,17,7,7,7,1,6,13,7,1,6,6,6,16,17,6,6,6,1,6,12,7,6,15,1,7, */
/*    ,16,17,7,7,7,1,7,12,7,7,7,7,7,16,17,7,7,7,1,8,11,1,8,8,8,8,16,17,8, */
/*    ,8,8,1,6,14,6,6,6,6,6,16,17,6,6,6,7*3,1,3,3,3,3,3,8*1,17,1,1,1,1, */
/*    ,13*18/ */
/*     DATA B0,B/10*2,4*1,4,21*1,0,0,3,6,5,10,10,7,12,10,11,8*10,9,3*10, */
/*    ,8,11*10/ */
/*     DATA SKOK0,SKOK /47*6,1,2,3,4,4,5,18*6/ */
/* --- */
/* dsw  C0M(2)=DATAHEX1 */
/* dsw  C0M(3)=DATAHEX2 */
/* dsw  C0M(4)=DATAHEX3 */
    blank_3.c0m[1] = dathx1;
    blank_3.c0m[2] = dathx2;
    blank_3.c0m[3] = dathx3;
    optdef_();
/* --- */
    blank_3.skok0 = 6;
    for (i__ = 1; i__ <= 70; ++i__) {
/* L4: */
	blank_3.skok[i__ - 1] = 6;
    }
    blank_3.skok[46] = 1;
    blank_3.skok[47] = 2;
    blank_3.skok[48] = 3;
    blank_3.skok[49] = 4;
    blank_3.skok[50] = 4;
    blank_3.skok[51] = 5;
    blank_3.sident = 1;
    for (i__ = 1; i__ <= 200; ++i__) {
/* L5: */
	blank_3.keys[i__ - 1] = 0;
    }
/*     DATA S,ADRES,STAN,K,SY,AUX,EXP,SIGN,INTPART,FRAC /10*0/ */
    blank_3.s = 0;
    blank_3.adres = 0;
    blank_3.stan = 0;
    blank_3.k = 0;
    blank_3.sy = 0;
    blank_3.aux = 0;
    blank_3.exp__ = 0;
    blank_3.sign = 0;
    blank_3.intpart = 0;
    blank_3.frac = 0;
/*     DATA OKEY,NU /.FALSE.,0.0/ */
    blank_3.okey = FALSE_;
    blank_3.nu = 0.f;
    blank_3.sconst = 1000;
    blank_3.seof = 70;
    blank_3.sand = 67;
    blank_3.sarray = 18;
    blank_3.sarrof = 81;
    blank_3.sattach = 11;
    blank_3.sbegin = 83;
    blank_3.sblock = 22;
    blank_3.sbool = 85;
    blank_3.scall = 9;
    blank_3.scase = 16;
    schar = 71;
    blank_3.sclass = 86;
    blank_3.sclose = 87;
    blank_3.scons = 88;
    blank_3.scopy = 69;
    blank_3.scorout = 78;
    blank_3.sdetach = 5;
    blank_3.sdim = 89;
    blank_3.sdo = 14;
    blank_3.sdown = 90;
    blank_3.selse = 62;
    blank_3.send = 80;
    blank_3.sesac = 91;
    blank_3.sexit = 15;
    blank_3.sextern = 92;
    blank_3.sfi = 63;
    blank_3.sfor = 17;
    blank_3.sfunct = 93;
    blank_3.sif = 2;
    blank_3.sinner = 6;
    blank_3.sinput = 95;
    blank_3.sint = 64;
    blank_3.skill = 10;
    blank_3.slock = 7;
    blank_3.snew = 24;
    blank_3.snone = 1002;
    blank_3.snot = 66;
    blank_3.sod = 65;
    blank_3.sor = 68;
    blank_3.sorif = 97;
    blank_3.sother = 98;
    blank_3.soutput = 99;
    blank_3.spref = 23;
    blank_3.sprcd = 101;
    blank_3.squa = 76;
    blank_3.sread = 8;
    blank_3.sresume = 12;
    blank_3.sreturn = 4;
    blank_3.step = 102;
    blank_3.stop = 13;
    blank_3.staken = 103;
    blank_3.sthen = 61;
    blank_3.sthis = 74;
    blank_3.sto = 104;
    blank_3.strue = 1001;
    blank_3.stype = 105;
    blank_3.sunit = 77;
    blank_3.svar = 106;
    blank_3.svirtual = 107;
    blank_3.swait = 21;
    blank_3.swhen = 109;
    blank_3.swhile = 3;
    blank_3.swrit = 19;
    blank_3.swritln = 20;
    blank_3.scoma = 42;
    blank_3.sdot = 38;
    blank_3.semicol = 45;
    blank_3.scolon = 47;
    blank_3.sleft = 52;
    blank_3.sright = 53;
    blank_3.sbecome = 54;
    blank_3.star = 50;
    blank_3.srelat = 51;
/*     DATA BYTE,TL,NB,TEXT /64,20,2,20*0/ */
    blank_3.byte = 64;
    blank_3.tl = 132;
    blank_3.nb = 2;
/* BC   TEXT(1)=1 */
    blank_3.text[0] = 2;
    blank_3.b0 = 2;
    for (i__ = 1; i__ <= 9; ++i__) {
/* L7: */
	blank_3.b[i__ - 1] = 2;
    }
    for (i__ = 10; i__ <= 35; ++i__) {
/* L8: */
	blank_3.b[i__ - 1] = 1;
    }
    blank_3.b[13] = 4;
    blank_3.b[35] = 0;
    blank_3.b[36] = 0;
    blank_3.b[37] = 3;
    blank_3.b[38] = 6;
    blank_3.b[39] = 5;
    blank_3.b[40] = 10;
    blank_3.b[41] = 10;
    blank_3.b[42] = 7;
    blank_3.b[43] = 12;
    blank_3.b[44] = 10;
    blank_3.b[45] = 11;
    for (i__ = 47; i__ <= 54; ++i__) {
/* L9: */
	blank_3.b[i__ - 1] = 10;
    }
    blank_3.b[54] = 9;
    blank_3.b[55] = 10;
    blank_3.b[56] = 10;
    blank_3.b[57] = 10;
    blank_3.b[58] = 8;
    for (i__ = 60; i__ <= 70; ++i__) {
/* L10: */
	blank_3.b[i__ - 1] = 10;
    }
    daata_();
    return 0;
} /* data_ */

#undef y
#undef x


/* Subroutine */ int daata_(void)
{
    /* Local variables */
    static integer i__;
#define x ((integer *)&blank_4 + 8515)
#define y ((integer *)&blank_4 + 8684)

    x[0] = 1;
    x[1] = 1;
    x[2] = 9;
    x[3] = 1;
    x[4] = 1;
    x[5] = 1;
    x[6] = 1;
    x[7] = 1;
    x[8] = 16;
    x[9] = 17;
    x[10] = 1;
    x[11] = 1;
    x[12] = 1;
    x[13] = 2;
    x[14] = 4;
    x[15] = 4;
    x[16] = 2;
    x[17] = 4;
    x[18] = 2;
    x[19] = 2;
    x[20] = 2;
    x[21] = 16;
    x[22] = 17;
    x[23] = 2;
    x[24] = 4;
    x[25] = 2;
    x[26] = 1;
    x[27] = 5;
    x[28] = 10;
    x[29] = 1;
    x[30] = 1;
    x[31] = 5;
    x[32] = 5;
    x[33] = 5;
    x[34] = 16;
    x[35] = 17;
    x[36] = 5;
    x[37] = 5;
    x[38] = 5;
    x[39] = 1;
    x[40] = 7;
    x[41] = 11;
    x[42] = 7;
    x[43] = 1;
    x[44] = 7;
    x[45] = 7;
    x[46] = 7;
    x[47] = 16;
    x[48] = 17;
    x[49] = 7;
    x[50] = 7;
    x[51] = 7;
    x[52] = 1;
    x[53] = 5;
    x[54] = 12;
    x[55] = 7;
    x[56] = 5;
    x[57] = 15;
    x[58] = 1;
    x[59] = 7;
    x[60] = 16;
    x[61] = 17;
    x[62] = 7;
    x[63] = 7;
    x[64] = 7;
    x[65] = 1;
    x[66] = 6;
    x[67] = 13;
    x[68] = 7;
    x[69] = 1;
    x[70] = 6;
    x[71] = 6;
    x[72] = 6;
    x[73] = 16;
    x[74] = 17;
    x[75] = 6;
    x[76] = 6;
    x[77] = 6;
    x[78] = 1;
    x[79] = 6;
    x[80] = 12;
    x[81] = 7;
    x[82] = 6;
    x[83] = 15;
    x[84] = 1;
    x[85] = 7;
    x[86] = 16;
    x[87] = 17;
    x[88] = 7;
    x[89] = 7;
    x[90] = 7;
    x[91] = 1;
    x[92] = 7;
    x[93] = 12;
    x[94] = 7;
    x[95] = 7;
    x[96] = 7;
    x[97] = 7;
    x[98] = 7;
    x[99] = 16;
    x[100] = 17;
    x[101] = 7;
    x[102] = 7;
    x[103] = 7;
    x[104] = 1;
    x[105] = 8;
    x[106] = 11;
    x[107] = 1;
    x[108] = 8;
    x[109] = 8;
    x[110] = 8;
    x[111] = 8;
    x[112] = 16;
    x[113] = 17;
    x[114] = 8;
    x[115] = 8;
    x[116] = 8;
    x[117] = 1;
    x[118] = 6;
    x[119] = 14;
    x[120] = 6;
    x[121] = 6;
    x[122] = 6;
    x[123] = 6;
    x[124] = 6;
    x[125] = 16;
    x[126] = 17;
    x[127] = 6;
    x[128] = 6;
    x[129] = 6;
    for (i__ = 131; i__ <= 143; ++i__) {
/* L13: */
	x[i__ - 1] = 3;
    }
    x[137] = 1;
    for (i__ = 144; i__ <= 156; ++i__) {
/* L14: */
	x[i__ - 1] = 1;
    }
    x[151] = 17;
    for (i__ = 157; i__ <= 169; ++i__) {
/* L15: */
	x[i__ - 1] = 18;
    }
    y[0] = 1;
    y[1] = 3;
    y[2] = 5;
    y[3] = 8;
    y[4] = 3;
    y[5] = 10;
    y[6] = 10;
    y[7] = 16;
    y[8] = 18;
    y[9] = 1;
    y[10] = 10;
    y[11] = 10;
    y[12] = 20;
    y[13] = 2;
    y[14] = 1;
    y[15] = 1;
    y[16] = 8;
    y[17] = 1;
    y[18] = 14;
    y[19] = 14;
    y[20] = 16;
    y[21] = 18;
    y[22] = 1;
    y[23] = 14;
    y[24] = 1;
    y[25] = 20;
    y[26] = 1;
    y[27] = 3;
    y[28] = 1;
    y[29] = 9;
    y[30] = 11;
    y[31] = 14;
    y[32] = 14;
    y[33] = 16;
    y[34] = 18;
    y[35] = 1;
    y[36] = 14;
    y[37] = 14;
    y[38] = 20;
    y[39] = 1;
    y[40] = 3;
    y[41] = 6;
    y[42] = 8;
    y[43] = 12;
    y[44] = 14;
    y[45] = 14;
    y[46] = 16;
    y[47] = 18;
    y[48] = 1;
    y[49] = 14;
    y[50] = 14;
    y[51] = 20;
    y[52] = 1;
    y[53] = 4;
    y[54] = 7;
    y[55] = 8;
    y[56] = 4;
    y[57] = 15;
    y[58] = 15;
    y[59] = 16;
    y[60] = 18;
    y[61] = 1;
    y[62] = 14;
    y[63] = 14;
    y[64] = 20;
    y[65] = 1;
    y[66] = 3;
    y[67] = 1;
    y[68] = 8;
    y[69] = 13;
    y[70] = 14;
    y[71] = 14;
    y[72] = 16;
    y[73] = 18;
    y[74] = 1;
    y[75] = 14;
    y[76] = 14;
    y[77] = 20;
    y[78] = 1;
    y[79] = 4;
    y[80] = 7;
    y[81] = 8;
    y[82] = 4;
    y[83] = 15;
    y[84] = 15;
    y[85] = 16;
    y[86] = 18;
    y[87] = 1;
    y[88] = 14;
    y[89] = 14;
    y[90] = 20;
    y[91] = 1;
    y[92] = 3;
    y[93] = 7;
    y[94] = 8;
    y[95] = 3;
    y[96] = 14;
    y[97] = 14;
    y[98] = 16;
    y[99] = 18;
    y[100] = 1;
    y[101] = 14;
    y[102] = 14;
    y[103] = 20;
    y[104] = 1;
    y[105] = 3;
    y[106] = 6;
    y[107] = 10;
    y[108] = 3;
    y[109] = 14;
    y[110] = 14;
    y[111] = 16;
    y[112] = 18;
    y[113] = 1;
    y[114] = 14;
    y[115] = 14;
    y[116] = 20;
    y[117] = 1;
    y[118] = 3;
    y[119] = 1;
    y[120] = 8;
    y[121] = 3;
    y[122] = 14;
    y[123] = 14;
    y[124] = 16;
    y[125] = 18;
    y[126] = 1;
    y[127] = 14;
    y[128] = 14;
    y[129] = 20;
    for (i__ = 131; i__ <= 168; ++i__) {
/* L50: */
	y[i__ - 1] = 1;
    }
    y[137] = 17;
    y[152] = 19;
    y[168] = 21;
    return 0;
} /* daata_ */

#undef y
#undef x


/* Subroutine */ int optdef_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, ext, znak;
    extern /* Subroutine */ int ffputcs_(integer *, char *, ftnlen), ffputnl_(
	    integer *);

/* --- READS INPUT PARAMETERS; APPROPRIATELY MODIFIES OPTION WORD */
/*   param - line of program parameters */
/*   dl - length of program parameters */
/*   pozopt -  options position in param */


    ext = 0;
    if (par_1.pozopt > par_1.dl || par_1.dl == 0) {
	goto L1000;
    }
L80:
    blank_5.k = par_1.pozopt;
    i__1 = par_1.dl;
    for (par_1.pozopt = blank_5.k; par_1.pozopt <= i__1; ++par_1.pozopt) {
	if (*(unsigned char *)&par_1.param[par_1.pozopt - 1] != ' ') {
	    goto L102;
	}
/* L101: */
    }
    goto L1000;
L102:
    if (ext == 1) {
	goto L105;
    }
    ext = 1;
    if (*(unsigned char *)&par_1.param[par_1.pozopt - 1] == ';') {
	goto L9999;
    }
    if (*(unsigned char *)&par_1.param[par_1.pozopt - 1] != ',') {
	goto L105;
    }
    ++par_1.pozopt;
    goto L80;
L105:
    i__ = 0;
    i__1 = par_1.dl;
    for (blank_5.k = par_1.pozopt; blank_5.k <= i__1; ++blank_5.k) {
	if (i__ >= 70) {
	    goto L107;
	}
	++i__;
/* L103: */
	blank_5.skok[i__ - 1] = *(unsigned char *)&par_1.param[blank_5.k - 1];
    }
L107:
    ++i__;
    for (blank_5.k = i__; blank_5.k <= 70; ++blank_5.k) {
/* L112: */
	blank_5.skok[blank_5.k - 1] = 0;
    }
    goto L2000;
L1000:
/* vax ------added */
/* ps      write(*,1) */
/* ps1     format ( */
/* ps     * ' Specify compilation options : (default = D-S-L-O+T+M+I+)'$) */
/* ps 3    do 111 k=1,70 */
/* ps111   skok(k) = 0 */
/* ps      read (*,2) skok */
/* ps2     format(70a1) */
L2000:
    blank_5.k = 1;

L10:
    znak = 255 & blank_5.skok[blank_5.k - 1];
    ++blank_5.k;
    if (znak == ' ') {
	goto L10;
    }
    if (znak == ',') {
	goto L10;
    }
    if (znak == 0) {
	goto L9999;
    }

L20:
    blank_5.sign = 255 & blank_5.skok[blank_5.k - 1];
    ++blank_5.k;
    if (blank_5.sign == ' ') {
	goto L20;
    }
    if (blank_5.sign == '+') {
	goto L30;
    }
    if (blank_5.sign == '-') {
	goto L30;
    }
/* --- BAD OPTION */
L29:
    ffputcs_(&c__0, " Bad option - ignored", (ftnlen)21);
    ffputnl_(&c__0);
    goto L9999;
L30:
    if (znak > 'Z') {
	znak += -32;
    }
/*     IF (ZNAK.EQ.ICHAR('C')) GOTO 670 */
    if (znak == 'D') {
	goto L680;
    }
/*     IF (ZNAK.EQ.ICHAR('F')) GOTO 700 */
/* dsw  IF (ZNAK.EQ.ICHAR('I')) GOTO 730 */
    if (znak == 'L') {
	goto L760;
    }
/* dsw  IF (ZNAK.EQ.ICHAR('M')) GOTO 770 */
    if (znak == 'O') {
	goto L790;
    }
/* --- IF (ZNAK.EQ.ICHAR('P')) GOTO 800 */
/* deb */
    if (znak == 'S') {
	goto L830;
    }
/* deb */
    if (znak == 'T') {
	goto L840;
    }
    if (znak == 'H') {
	goto L620;
    }
    goto L29;
/*  opcja 'H' - duza pamiec */
/*  rozpoznano 'H' */
L620:
    goto L10;
/*  ROZPOZNANO 'C' */
/*  ****** "ROZPOZNANO" MEANS "RECOGNIZED" */
/* 670 IF (SIGN.EQ.ICHAR('+')) GO TO 675 */
/*     C0M(4)=IBCLR(C0M(4),5) */
/*     GOTO 10 */
/* 675 C0M(3)=IBSET(C0M(3),5) */
/*     GOTO 10 */
/*  ROZPOZNANO 'D' */
L680:
    if (blank_5.sign == '+') {
	goto L685;
    }
    blank_5.c0m[3] = bit_clear(blank_5.c0m[3],4);
    goto L10;
L685:
    blank_5.c0m[2] = bit_set(blank_5.c0m[2],4);
    goto L10;
/*  ROZPOZNANO 'F' */
/* 700 IF (SIGN.EQ.ICHAR('+')) GOTO 705 */
/*     C0M(4)=IBCLR(C0M(4),6) */
/*     GOTO 10 */
/* 705 C0M(3)=IBSET(C0M(3),6) */
/*     GOTO 10 */
/*  ROZPOZNANO 'I' */
/* 730   IF (SIGN.EQ.ICHAR('+')) GOTO 735 */
/*       C0M(4)=IBCLR(C0M(4),2) */
/*       GOTO 10 */
/* 735   C0M(3)=IBSET(C0M(3),2) */
/*       GOTO 10 */
/*  ROZPOZNANO 'L' */
L760:
    if (blank_5.sign == '+') {
	goto L765;
    }
    blank_5.c0m[3] = bit_clear(blank_5.c0m[3],15);
    goto L10;
L765:
    blank_5.c0m[2] = bit_set(blank_5.c0m[2],15);
    goto L10;
/*  ROZPOZNANO 'M' */
/* 770   IF (SIGN.EQ.ICHAR('+')) GOTO 775 */
/*       C0M(4)=IBCLR(C0M(4),0) */
/*       GOTO 10 */
/* 775   C0M(3)=IBSET(C0M(3),0) */
/*       GOTO 10 */
/*  ROZPOZNANO 'O' */
L790:
    if (blank_5.sign == '+') {
	goto L795;
    }
    blank_5.c0m[3] = bit_clear(blank_5.c0m[3],1);
    goto L10;
L795:
    blank_5.c0m[2] = bit_set(blank_5.c0m[2],1);
    goto L10;
/*  ROZPOZNANO 'P' */
/* 800 IF (SIGN.EQ.ICHAR('+')) GOTO 805 */
/*     C0M(4)=IBCLR(C0M(4),14) */
/*     GOTO 10 */
/* 805 C0M(3)=IBSET(C0M(3),14) */
/*     GOTO 10 */
/* deb  added */
/*  ROZPOZNANO 'S' */
L830:
    if (blank_5.sign == '+') {
	goto L835;
    }
    blank_5.c0m[3] = bit_clear(blank_5.c0m[3],13);
    goto L10;
L835:
    blank_5.c0m[2] = bit_set(blank_5.c0m[2],13);
    goto L10;
/* deb */
/*  ROZPOZNANO 'T' */
L840:
    if (blank_5.sign == '+') {
	goto L845;
    }
    blank_5.c0m[3] = bit_clear(blank_5.c0m[3],3);
    goto L10;
L845:
    blank_5.c0m[2] = bit_set(blank_5.c0m[2],3);
    goto L10;
L9999:
    blank_5.c0m[1] = blank_5.c0m[2] | blank_5.c0m[3] & blank_5.c0m[1];
    ffputnl_(&c__0);
    ffputcs_(&c__0, " Pass One", (ftnlen)9);
    ffputnl_(&c__0);
    ffputnl_(&c__0);
    return 0;
} /* optdef_ */

/* Subroutine */ int mess_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_6 + 302)
#define staler ((real *)&blank_6 + 302)

/* ----------------DISPLAYS END-OF-PASS INFORMATION */

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

/* --- */
    ++blank_6.iop[0];
    if (mjlmsg_2.ierc == 0) {
	return 0;
    }
/* --- */
    if (blank_6.iop[0] <= 7) {
	return 0;
    }
/* --- */
    return 0;
} /* mess_ */

#undef staler
#undef stack


