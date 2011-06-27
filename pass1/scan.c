/* scan.f -- translated by f2c (version 20090411).
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
	integer instr[265], bufor[85], lp, ln, max__, jnk[266];
    } _1;
    struct {
	integer instr[265], bufor[85], lp, ln, max__, postr[265], status;
    } _2;
} buff_;

#define buff_1 (buff_._1)
#define buff_2 (buff_._2)

union {
    struct {
	integer errflg, line, ibuf2[265], ibuf3[7], on, junk[259];
    } _1;
    struct {
	logical errflg;
	integer line, ibuf2[265], buf[7], on, bufout[256], posit, recnr, 
		nekst;
    } _2;
} stream_;

#define stream_1 (stream_._1)
#define stream_2 (stream_._2)

union {
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
    } _1;
    struct {
	integer c0m[4];
    } _2;
    struct {
	integer c0m[4], s, adres, ka, reszta[8185];
    } _3;
    struct {
	integer com[302], hash[8000], m, name__[10], nlast, nl, keys[200], 
		scaner[522], stos[503], reszta[3652];
    } _4;
    struct {
	integer com[278], lmem, lpmem, irecn, isfin, lpmsys, lpml, lpmf, 
		nrint, nrre, nrbool, nrchr, nrcor, nrproc, nrtext, nruniv, 
		nattr, nrnone, nblsys, nblus, nempty;
	logical insys, local, own;
	integer object, ipmem[12890];
    } _5;
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
    } _6;
    struct {
	integer c0m[146], com[132], xx[8037], keys[200], reszta[4677];
    } _7;
} blank_;

#define blank_1 (blank_._1)
#define blank_2 (blank_._2)
#define blank_3 (blank_._3)
#define blank_4 (blank_._4)
#define blank_5 (blank_._5)
#define blank_6 (blank_._6)
#define blank_7 (blank_._7)

struct {
    integer outstr[265];
} listing_;

#define listing_1 listing_

/* Table of constant values */

static integer c__111 = 111;
static integer c__212 = 212;
static integer c__211 = 211;
static integer c__205 = 205;
static integer c__201 = 201;
static integer c__202 = 202;
static integer c__203 = 203;
static integer c__204 = 204;
static integer c__16 = 16;
static integer c__13 = 13;
static integer c__10 = 10;
static integer c__17 = 17;
static integer c__0 = 0;
static integer c__196 = 196;
static integer c__199 = 199;
static integer c__15 = 15;
static integer c__1 = 1;
static integer c__2 = 2;

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
/* Subroutine */ int scan_(void)
{
    /* Initialized data */

    static integer sd = 2;
    static integer se = 61;
    static integer sr = 41;
    static integer ss = 47;
    static integer st = 42;
    static integer scanhex = 32767;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, z__;
    static logical ok;
    extern integer ord_(integer *), key_(integer *);
    static integer znak;
    extern /* Subroutine */ int error_(integer *);
    static integer klucz;
    extern integer embede_(real *);
    extern /* Subroutine */ int readin_(void);
    extern integer search_(integer *);
    static logical overfl;
    extern /* Subroutine */ int optset_(void), tinser_(void);

/* dsw&bc */

    overfl = FALSE_;
    ok = FALSE_;
    if (! blank_1.okey) {
	goto L111;
    }
    blank_1.k = blank_1.k1;
    if (blank_1.sy == 70) {
	goto L3001;
    }
/* 	 INSERTED DUE TO T.SZCZEPANEK */
    blank_1.sy = blank_1.sy1;
    blank_1.okey = FALSE_;
    goto L2000;
L101:
    error_(&c__111);
    ++buff_1.lp;
L111:
    if (buff_1.lp < buff_1.max__) {
	goto L1;
    }
    readin_();
L1:
    if (buff_1.bufor[0] == sd) {
	goto L3001;
    }
    z__ = buff_1.bufor[buff_1.lp - 1];
    znak = ord_(&z__);
/*  ZNAK MEANS CHARACTER */
    if (blank_1.stan < 10) {
	goto L10;
    }
/*  WITHIN COMMENT - COMPOUND SYMBOLS ARE NOT PICKED UP */
/*  THE SAME FOR TEXT AND CHARACTER CONSTANTS */
    if (blank_1.stan == 11) {
	goto L11;
    }
    goto L8;
L10:
    if (znak == 63) {
	goto L101;
    }
L11:
    i__ = blank_1.skok[znak - 1];
    switch (i__) {
	case 1:  goto L2;
	case 2:  goto L3;
	case 3:  goto L4;
	case 4:  goto L5;
	case 5:  goto L6;
	case 6:  goto L8;
    }
L2:
    if (buff_1.bufor[buff_1.lp] != se) {
	goto L8;
    }
    goto L7;
L3:
    if (buff_1.bufor[buff_1.lp] != sr) {
	goto L8;
    }
    goto L7;
L4:
    if (buff_1.bufor[buff_1.lp] != ss) {
	goto L8;
    }
    if (buff_1.bufor[buff_1.lp + 1] != se) {
	goto L8;
    }
    ++buff_1.lp;
    goto L7;
/* --- ALLOW FOR "<>" TO STAND FOR "NON EQUAL" */
L5:
    if (znak != 50) {
	goto L5055;
    }
    if (buff_1.bufor[buff_1.lp] != '>') {
	goto L5055;
    }
    znak = 49;
    goto L7;
/* --- */
L5055:
    if (buff_1.bufor[buff_1.lp] != se) {
	goto L8;
    }
    goto L7;
L6:
    if (buff_1.bufor[buff_1.lp] != st) {
	goto L8;
    }
/*  BEGINNING OF COMMENT HAS BEEN RECOGNIZED '(*'. CHECK FOR A LISTING */
/*  CONTROL OPTION FOLLOWING THE COMMENT ANNOUNCEMENT. IF ONE OCCURRS */
/*  THEN THE LISTING CONTROL VARIABLE IS TO BE SET PROPERLY */
    if (buff_1.bufor[buff_1.lp + 1] != '$') {
	goto L7;
    }
    buff_1.lp += 3;
    optset_();
L7:
    ++buff_1.lp;
    znak += 7;
L8:
    ++buff_1.lp;
/*  END OF DETECTING COMPOUND SYMBOLS */
/*  THE AUTOMATON - PART I */
    j = blank_1.b[znak - 1] + 1;
    i__ = blank_1.trans1[j + (blank_1.stan + 1) * 13 - 14];
    switch (i__) {
	case 1:  goto L190;
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
	case 14:  goto L140;
	case 15:  goto L150;
	case 16:  goto L160;
	case 17:  goto L170;
	case 18:  goto L180;
    }
L20:
    blank_1.sy = search_(&blank_1.mm);
    blank_1.k = 0;
    klucz = key_(&blank_1.sy);
    if (klucz == blank_1.sident << 3) {
	blank_1.k = 2;
    }
    blank_1.k /= 2;
    ok = TRUE_;
    goto L190;
L30:
    if (blank_1.kk < blank_1.nb) {
	goto L31;
    }
    if (blank_1.mm < blank_1.tl) {
	goto L32;
    }
    error_(&c__212);
    goto L190;
L31:
    ++blank_1.kk;
/* bc   COM(MM)=ISHFT(COM(MM),8)+Z */
    blank_1.com[blank_1.mm - 1] = z__ << 8 | blank_1.com[blank_1.mm - 1];
/* bc */
    goto L190;
L32:
    blank_1.kk = 1;
    ++blank_1.mm;
    blank_1.com[blank_1.mm - 1] = z__;
    goto L190;
L40:
    if (blank_1.kk < blank_1.nb) {
	goto L41;
    }
    if (blank_1.mm < blank_1.nl) {
	goto L42;
    }
    error_(&c__211);
    goto L190;
L41:
    ++blank_1.kk;
    blank_1.name__[blank_1.mm - 1] = blank_1.name__[blank_1.mm - 1] * 
	    blank_1.byte + znak;
    goto L190;
L42:
    blank_1.kk = 1;
    ++blank_1.mm;
    blank_1.name__[blank_1.mm - 1] = znak;
    if (znak == 0) {
	blank_1.name__[blank_1.mm - 1] = 60;
    }
    goto L190;
L50:
    blank_1.k = 2;
/* dsw&bc      IF (INTPART.LT.0) GOTO 52 */
    if (overfl) {
	goto L52;
    }
    blank_1.sy = blank_1.intpart;
    goto L53;
L52:
    blank_1.sy = scanhex;
    error_(&c__205);
L53:
    blank_1.intpart = 0;
    ok = TRUE_;
    goto L190;
L70:
    error_(&c__201);
L60:
    if (blank_1.sign == 1) {
	blank_1.exp__ = -blank_1.exp__;
    }
    blank_1.exp__ -= blank_1.frac;
/* dsw&bc      IF (INTPART.LT.0) GOTO 191 */
    if (overfl) {
	goto L191;
    }
    blank_1.fract = (real) blank_1.intpart;
    goto L192;
L191:
    blank_1.fract = blank_1.nu;
L192:
    if (blank_1.exp__ < 0) {
	goto L200;
    } else if (blank_1.exp__ == 0) {
	goto L210;
    } else {
	goto L193;
    }
L193:
    i__1 = blank_1.exp__;
    for (j = 1; j <= i__1; ++j) {
/* JF	 IF (FRACT.GT.0.7237005E75) GOTO 207 */
/* L195: */
	blank_1.fract *= 10.f;
    }
    goto L210;
/* JF 207   CALL ERROR(206) */
/* JF       GOTO 210 */
L200:
    blank_1.exp__ = -blank_1.exp__;
    i__1 = blank_1.exp__;
    for (j = 1; j <= i__1; ++j) {
/* JF	 IF (FRACT.GT.0.AND.FRACT.LT.0.5397605E-77) GOTO 207 */
/* L205: */
	blank_1.fract *= .1f;
    }
L210:
    blank_1.k = 4;
    blank_1.nu = blank_1.fract;
    ok = TRUE_;
    blank_1.sign = 0;
    blank_1.exp__ = 0;
    blank_1.intpart = 0;
    blank_1.frac = 0;
    goto L190;
L80:
    blank_1.k = 6;
    blank_1.sy = 38;
    ok = TRUE_;
    goto L190;
L90:
    blank_1.intpart = znak;
    goto L190;
L110:
    blank_1.frac = 0;
L130:
    ++blank_1.frac;
/* dsw&bc 100   IF (INTPART.LT.0) GOTO 102 */
L100:
    if (overfl) {
	goto L102;
    }
    blank_1.nu = (real) blank_1.intpart;
/* dsw&bc check for overflow */
/* ailvaxC  max. integer on VAX is 2147483647 */
    if (blank_1.intpart > 214748364 || blank_1.intpart == 214748364 && znak > 
	    7) {
	overfl = TRUE_;
    }
    if (overfl) {
	goto L102;
    }
    blank_1.intpart = blank_1.intpart * 10 + znak;
/* dsw&bc   IF (INTPART.GE.0) GOTO 190 */
/* ailvaxC   overfl is .FALSE. here */
    goto L190;
L102:
    blank_1.nu = blank_1.nu * 10.f + znak;
    goto L190;
L120:
    blank_1.exp__ = znak;
    goto L190;
L140:
    blank_1.exp__ = blank_1.exp__ * 10 + znak;
    goto L190;
L150:
    blank_1.sign = 1;
    goto L190;
L160:
    blank_1.stan1 = blank_1.stan;
    goto L190;
L170:
    error_(&c__202);
    goto L190;
L180:
    if (blank_1.exp__ < 0) {
	goto L181;
    }
    if (znak == 44) {
	goto L190;
    }
    znak = 36;
    blank_1.stan = 0;
/* dsw&bc */
    blank_1.exp__ = 0;

    error_(&c__203);
    goto L190;
L181:
    blank_1.exp__ = z__;
    znak = 0;
L190:
/*  THE AUTOMATON - PART II */
/* L1000: */
    j = blank_1.b[znak - 1] + 1;
    i__ = blank_1.trans2[j + (blank_1.stan + 1) * 13 - 14];
    switch (i__) {
	case 1:  goto L1300;
	case 2:  goto L1020;
	case 3:  goto L1030;
	case 4:  goto L1040;
	case 5:  goto L1050;
	case 6:  goto L1060;
	case 7:  goto L1070;
	case 8:  goto L1080;
	case 9:  goto L1090;
	case 10:  goto L1100;
	case 11:  goto L1110;
	case 12:  goto L1120;
	case 13:  goto L1130;
	case 14:  goto L1140;
	case 15:  goto L1150;
	case 16:  goto L1160;
	case 17:  goto L1170;
	case 18:  goto L1180;
	case 19:  goto L1190;
	case 20:  goto L1200;
	case 21:  goto L1210;
    }
L1020:
    blank_1.stan = 0;
    goto L1300;
L1030:
    blank_1.kk = 1;
    blank_1.mm = 1;
    blank_1.name__[0] = znak;
    blank_1.stan = 1;
    goto L1300;
L1040:
    blank_1.kk = 2;
    blank_1.mm = 1;
    blank_1.name__[0] = blank_1.byte * 14 + znak;
    blank_1.stan = 1;
    goto L1300;
L1050:
    blank_1.stan = 2;
    goto L1300;
L1060:
    blank_1.stan = 5;
    goto L1300;
L1070:
    blank_1.stan = 9;
    goto L1300;
L1080:
    blank_1.stan = 8;
    goto L1300;
L1090:
    blank_1.stan = 3;
    goto L1300;
L1100:
    blank_1.sy = znak;
    goto L2070;
L1110:
    blank_1.stan = 4;
    goto L1300;
L1120:
    error_(&c__204);
L1130:
    blank_1.stan = 6;
    goto L1300;
L1140:
    if (ok) {
	goto L1145;
    }
    blank_1.stan = 0;
    blank_1.sy = znak;
    goto L2070;
L1145:
    blank_1.k1 = 6;
    blank_1.sy1 = znak;
    blank_1.stan = 0;
    blank_1.okey = TRUE_;
    goto L1300;
L1150:
    blank_1.stan = 7;
    goto L1300;
L1160:
    blank_1.kk = 2;
    blank_1.mm = 1;
/* dsw&bc */
    blank_1.com[1] = 0;

    blank_1.stan = 10;
    goto L1300;
L1170:
    blank_1.stan = 0;
    blank_1.k = 4;
    blank_1.s = blank_1.sconst;
    tinser_();
    goto L3000;
L1180:
    blank_1.stan = 11;
    goto L1300;
L1190:
    blank_1.stan = blank_1.stan1;
    goto L1300;
L1200:
    blank_1.stan = 12;
    blank_1.exp__ = -1;
    goto L1300;
L1210:
    blank_1.k = 6;
    blank_1.stan = 0;
    blank_1.s = blank_1.sconst;
    blank_1.adres = blank_1.exp__;
    blank_1.exp__ = 0;
    goto L3000;
L1300:
/*  END OF THE SECOND PHASE */
    if (! ok) {
	goto L111;
    }
L2000:
    ++blank_1.k;
    switch (blank_1.k) {
	case 1:  goto L2010;
	case 2:  goto L2020;
	case 3:  goto L2030;
	case 4:  goto L2040;
	case 5:  goto L2050;
	case 6:  goto L2060;
	case 7:  goto L2070;
    }
L2010:
    blank_1.k = klucz;
    blank_1.s = blank_1.k / 8;
    blank_1.adres = blank_1.k % 8 + 1;
    blank_1.k = blank_1.sy;
    goto L3000;
L2020:
    blank_1.s = blank_1.sident;
    blank_1.adres = blank_1.sy;
    goto L3000;
L2030:
    blank_1.s = blank_1.sconst;
/*  INTEGER CONSTANT RECOGNIZED */
    blank_1.adres = blank_1.sy;
/* dsw */
    blank_1.sy = 0;
    goto L3000;
L2040:
    blank_1.s = blank_1.sconst;
    tinser_();
    goto L3000;
L2050:
    blank_1.s = blank_1.sconst;
    blank_1.adres = embede_(&blank_1.nu);
    goto L3000;
L2060:
    blank_1.s = blank_1.sconst;
    blank_1.adres = blank_1.exp__;
    goto L3000;
L2070:
    blank_1.k = blank_1.sy - 37;
    switch (blank_1.k) {
	case 1:  goto L2150;
	case 2:  goto L2102;
	case 3:  goto L2103;
	case 4:  goto L2104;
	case 5:  goto L2150;
	case 6:  goto L2150;
	case 7:  goto L2150;
	case 8:  goto L2150;
	case 9:  goto L2150;
	case 10:  goto L2150;
	case 11:  goto L2105;
	case 12:  goto L2106;
	case 13:  goto L2107;
	case 14:  goto L2108;
	case 15:  goto L2150;
	case 16:  goto L2150;
	case 17:  goto L2150;
	case 18:  goto L2150;
	case 19:  goto L2109;
	case 20:  goto L2110;
	case 21:  goto L2111;
    }
L2102:
    blank_1.s = blank_1.star;
    blank_1.adres = 3;
    goto L3000;
L2103:
    blank_1.s = blank_1.star;
    blank_1.adres = 4;
    goto L3000;
L2104:
    blank_1.s = blank_1.star;
    blank_1.adres = 6;
    goto L3000;
L2105:
    blank_1.s = blank_1.star;
    blank_1.adres = 5;
    goto L3000;
L2106:
    blank_1.s = blank_1.srelat;
    blank_1.adres = 3;
    goto L3000;
L2107:
    blank_1.s = blank_1.srelat;
    blank_1.adres = 5;
    goto L3000;
L2108:
    blank_1.s = blank_1.srelat;
    blank_1.adres = 7;
    goto L3000;
L2109:
    blank_1.s = blank_1.srelat;
    blank_1.adres = 4;
    goto L3000;
L2110:
    blank_1.s = blank_1.srelat;
    blank_1.adres = 6;
    goto L3000;
L2111:
    blank_1.s = blank_1.srelat;
    blank_1.adres = 8;
    goto L3000;
L2150:
    blank_1.s = blank_1.sy;
L3000:
    return 0;
L3001:
    blank_1.k = 6;
    blank_1.s = 70;
    blank_1.okey = TRUE_;
    blank_1.sy1 = 70;
/*     THE LAST TWO STATEMENT ARE INSERTED DUE TO T.SZCZEPANEK */
    return 0;
} /* scan_ */

/* Subroutine */ int readin_(void)
{
    /* System generated locals */
    integer i__1;
    char ch__1[1];
    static integer equiv_0[43];

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int ffwrite_char__(integer *, char *, ftnlen);
#define bufor1 ((char *)equiv_0)
#define bufor2 (equiv_0)
    extern /* Subroutine */ int nextch_(integer *, integer *), ffwrite_(
	    integer *, integer *, integer *), ffwrhex_(integer *, integer *);
    extern /* Character */ VOID int2char_(char *, ftnlen, integer *);


/*  POSTR - BUFFER FOR AUXILIARY INPUT FILE */
/*  VARIABLE STATUS DESCRIBES THE STATUS OF INPUT: */
/*    1 - SOURCE TEXT IS READ FROM THE AUXILIARY INPUT */
/*    0 - SOURCE TEXT IS READ FROM THE STANDARD INPUT */
/*   -1 - SOURCE TEXT HAS BEEN READ UNTIL THE LAST END. NOW THE STANDARD */
/* 	 INPUT IS BEING SKIPPED UNTIL EOF */

    i__ = 1;
    buff_2.lp = 1;
    goto L2;
/*  NOW ONE LINE IS READ FROM THE INPUT FILE */
L1:
    ++buff_2.ln;
    ffwrhex_(&c__16, &buff_2.ln);

    if (bit_test(blank_2.c0m[1],15)) {
	goto L1001;
    }
    ffwrite_char__(&c__16, "0", (ftnlen)1);

    goto L1002;
L1001:
    ffwrite_char__(&c__16, "1", (ftnlen)1);

L1002:
/* end of line - write CR/LF */
    int2char_(ch__1, (ftnlen)1, &c__13);
    ffwrite_char__(&c__16, ch__1, (ftnlen)1);
    int2char_(ch__1, (ftnlen)1, &c__10);
    ffwrite_char__(&c__16, ch__1, (ftnlen)1);
L2:
    nextch_(&c__17, buff_2.bufor);
    buff_2.bufor[0] = 255 & buff_2.bufor[0];
    if (buff_2.bufor[0] == 1) {
	goto L1;
    }
    if (buff_2.bufor[0] == 2) {
	return 0;
    }
L3:
    ++i__;
    nextch_(&c__17, &buff_2.bufor[i__ - 1]);
    buff_2.bufor[i__ - 1] = 255 & buff_2.bufor[i__ - 1];
    if (buff_2.bufor[i__ - 1] == 1) {
	goto L90;
    }
    if (i__ < 84) {
	goto L3;
    }
    buff_2.max__ = i__;
    goto L100;
L90:
    buff_2.max__ = i__ - 1;
L100:
    ++buff_2.ln;
    ffwrhex_(&c__16, &buff_2.ln);

    if (bit_test(blank_2.c0m[1],15)) {
	goto L110;
    }
    ffwrite_char__(&c__16, "0", (ftnlen)1);

    goto L115;
L110:
    ffwrite_char__(&c__16, "1", (ftnlen)1);

L115:
    buff_2.bufor[buff_2.max__] = 1;
    i__1 = buff_2.max__;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L120: */
	*(unsigned char *)&bufor1[i__ - 1] = (char) buff_2.bufor[i__ - 1];
    }
    ffwrite_(&c__16, bufor2, &buff_2.max__);

    int2char_(ch__1, (ftnlen)1, &c__13);
    ffwrite_char__(&c__16, ch__1, (ftnlen)1);
    int2char_(ch__1, (ftnlen)1, &c__10);
    ffwrite_char__(&c__16, ch__1, (ftnlen)1);
    for (i__ = buff_2.max__ + 1; i__ <= 85; ++i__) {
/* L140: */
	buff_2.bufor[i__ - 1] = ' ';
    }
    buff_2.max__ += 2;
    return 0;
} /* readin_ */

#undef bufor2
#undef bufor1


/* Subroutine */ int error_(integer *k)
{
    /* Initialized data */

    static integer el = 0;
    static integer ep = 0;

    /* System generated locals */
    integer i__1;
    char ch__1[1];

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int merr_(integer *, integer *), ffwrite_char__(
	    integer *, char *, ftnlen), overf_(integer *), ffwrhex_(integer *,
	     integer *), ffwrint_(integer *, integer *);
    extern /* Character */ VOID int2char_(char *, ftnlen, integer *);

/*   LIS OF THE ERRORS DIAGNOSED BY THE PARSER */

/*   101 - :=		  EXPECTED */
/*   102 - ;		      " */
/*   103 - 'THEN'              " */
/*   104 - 'FI', 'ELSE'        " */
/*   105 - 'OD'                " */
/*   106 - (		      " */
/*   107 - )		      " */
/*   108 - 'DO'                " */
/*   109 - IDENTIFIER	      " */
/*   110 - TOO MANY EXIT-S */
/*   111 - ILLEGAL CHARACTER */
/*   112 - STRUCTURE ERROR IN 'IF THEN ELSE FI' */
/*   113 - ???????????????????????????????????????????????? */
/*   114 - DOT MISSING */
/*   115 - WRONG OCCURRENCE OF A CONSTANT IN EXPRESSION */
/*   116 -  =		  MISSING */
/*   117 -  CONSTANT	  MISSING */
/*   118 -  DELIMITER	  MISSING */
/*   119 - CLASS/ PROCEDURE / FUNCTION	 EXPECTED */
/*   120 - 'HIDDEN HIDDEN' OR 'CLOSE CLOSE' */
/*   121 - HIDDEN OUTSIDE CLASS */
/*   122 - 'BLOCK' MISSING */
/*   123 - OBJECTEXPRESSION IS NOT A GENERATOR */
/*   124 - 'DIM'                MISSING */
/*   125 - 'TO' / 'DOWNTO'      MISSING */
/*   126 - ILLEGAL OCCURRENCE OF AN ARITHMETIC OPERATOR */
/*   127 - DECLARATIONS EXPECTED (UNIT, VAR, CONST) */
/*   128 - THE NAME OCCURRING AFTER 'END' DOESN-T MATCH THE UNIT NAME */
/*   129 - CASE...ESAC STRUCTURE ERROR */
/*   130 - DO...OD STRUCTURE ERROR */
/*   131 - ILLEGAL OCCURRENCE OF MAIN */
/*   132 - WHEN EXPECTED */
/*   133 - TOO MANY CASES IN 'CASE' (UPPER LIMIT = 127) */
/*   134 - 'BEGIN' MISSING */
/*   135 - ERROR IN OPTION DEFINITON IN COMMENT */
/*   136 - NULL PROGRAM */
/*   137 - WRONG HEADER OF THE SOURCE PROGRAM (BLOCK/PROGRAM MISSING) */
/*   138 - TOO MANY REPEAT STATEMENTS */
/*   139 - UNREACHABLE INSTRUCTIONS AFTER EXIT */
/*   140 - ANDIF'S AND ORIF'S INTERLEAVE */
/*   141 - SEMAPHORE TYPE PRECEDED BY ARRAYOF */
/*   142 - HANDLER IMPROPERLY ENDED */
/*   143 - LASTWILL OCCURRS WITHIN A COMPOUND STATEMENT OR WITHIN A HANDLER */
/*   144 - LASTWILL OCURRS TWICE */
/*   145 - NO PARAMETER SPECIFICATION */
/*   146 - WRONG REGISTER SPECIFICATION (IMPOSSIBLE IN THE PORTABLE VERSION) */
/*   147 - */
/* 	  OVERFLOW-TYPE ERRORS: SCANNING STOPS ON ANY OF THEM */
/*   191 - NULL PROGRAM - THE INPUT FILE IS EMPTY */
/*   196 - HASH TABLE OVERFLOW */
/*   197 - VARIABLE OR FORMAL PARAMETER LIST TOO LONG (LENGTH>132) */
/*   198 - PARSER STACK OVERFLOW */
/*   199 - IPMEM TABLE OVERFLOW - NO ROOM FOR MORE PROTOTYPES */
/* 	  SCANNER ERRORS: */
/*   201 - ERROR IN REAL CONSTANT */
/*   202 - COMMENT STRUCTURE ERROR */
/*   203 - ERROR IN CHARACTER CONSTANT */
/*   204 - ERROR IN CONSTANT */
/*   205 - VALUE OF A INTEGER CONSTANT EXCEEDS MACHINE ARITHMETIC */
/*   206 -            REAL */
/*   211 - IDENTIFIER TOO LONG (INITIAL 20 CHARACTERS ARE SIGNIFICANT) */
/*   212 - TEXT TOO LONG (INITIAL 264 CHARACTERS ARE SIGNIFICANT) */
    if (el == buff_1.ln && ep >= buff_1.lp - 1) {
	goto L15;
    }
    ffwrhex_(&c__16, &buff_1.ln);

    if (bit_test(blank_3.c0m[1],15)) {
	goto L1;
    }
    ffwrite_char__(&c__16, "0", (ftnlen)1);

    goto L2;
L1:
    ffwrite_char__(&c__16, "1", (ftnlen)1);

L2:
    if (buff_1.lp < 3) {
	goto L6;
    }
    i__1 = buff_1.lp;
    for (i__ = 3; i__ <= i__1; ++i__) {
/* L5: */
	ffwrite_char__(&c__16, " ", (ftnlen)1);
    }
L6:
    ffwrite_char__(&c__16, "?", (ftnlen)1);
    ffwrint_(&c__16, k);
/* end of line - write CR/LF */
    int2char_(ch__1, (ftnlen)1, &c__13);
    ffwrite_char__(&c__16, ch__1, (ftnlen)1);
    int2char_(ch__1, (ftnlen)1, &c__10);
    ffwrite_char__(&c__16, ch__1, (ftnlen)1);

    stream_1.line = buff_1.ln;
    if (*k > 190 && *k < 200) {
	overf_(k);
    }
    merr_(k, &c__0);
L15:
    ep = buff_1.lp;
    el = buff_1.ln;
    return 0;
} /* error_ */

integer ord_(integer *x)
{
    /* Initialized data */

    static integer tab[122] = { 63,63,63,63,63,63,63,63,36,63,63,63,37,36,36,
	    36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,36,63,43,63,63,63,
	    63,44,52,53,48,39,42,40,38,41,0,1,2,3,4,5,6,7,8,9,47,45,50,49,51,
	    63,63,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
	    30,31,32,33,34,35,63,63,63,63,46,63,10,11,12,13,14,15,16,17,18,19,
	    20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35 };

    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer z__;

/* dsw	BYTE TAB(122) */
/* --- ORIGINAL TABLE (FOR ISO-7 CODE) CHANGED TO WORK FOR EBCDIC */
    z__ = *x;
    if (z__ > 122) {
	goto L10;
    }
    ret_val = tab[z__ - 1];
    return ret_val;
L10:
    ret_val = 63;
    return ret_val;
} /* ord_ */

integer search_(integer *k)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i__, j, p, t, name1;
    extern /* Subroutine */ int error_(integer *);

    name1 = blank_4.name__[0];
    i__ = name1 % blank_4.m;
    i__ = (i__ << 1) + 1;
    if (blank_4.hash[i__ - 1] != 0) {
	goto L3;
    }
    ret_val = i__;
    blank_4.hash[i__ - 1] = name1;
    goto L11;
L1:
    if (i__ != 0) {
	goto L3;
    }
L2:
    blank_4.nlast += -2;
    if (blank_4.nlast < 0) {
	error_(&c__196);
    }
    if (blank_4.hash[blank_4.nlast - 1] != 0) {
	goto L2;
    }
    ret_val = blank_4.nlast;
    blank_4.hash[blank_4.nlast - 1] = blank_4.name__[0];
    blank_4.hash[j] = blank_4.nlast;
    i__ = blank_4.nlast;
    goto L11;
L3:
    if (blank_4.hash[i__ - 1] == name1) {
	goto L4;
    }
    j = i__;
    i__ = blank_4.hash[j];
    goto L10;
L4:
    if (*k != 1 || blank_4.hash[i__] < 0) {
	goto L5;
    }
    ret_val = i__;
    return ret_val;
L5:
    j = i__;
    p = 1;
L6:
    t = blank_4.hash[j];
    ++p;
    if (p <= *k) {
	goto L8;
    }
    if (t < 0) {
	goto L7;
    }
    ret_val = i__;
    return ret_val;
L7:
    j = -t;
    i__ = blank_4.hash[j];
    goto L10;
L8:
    if (t < 0) {
	goto L9;
    }
    i__ = t;
    goto L1;
L9:
    j = -t;
    if (blank_4.name__[p - 1] == blank_4.hash[j - 1]) {
	goto L6;
    }
    i__ = blank_4.hash[j];
L10:
    if (i__ >= 0) {
	goto L1;
    }
    j = -i__;
    i__ = blank_4.hash[j];
    goto L10;
L11:
    p = 2;
L12:
    if (p > *k) {
	return ret_val;
    }
L13:
    blank_4.nlast += -2;
    if (blank_4.nlast < 0) {
	error_(&c__196);
    }
    if (blank_4.hash[blank_4.nlast - 1] != 0) {
	goto L13;
    }
    blank_4.hash[blank_4.nlast - 1] = blank_4.name__[p - 1];
    blank_4.hash[i__] = -blank_4.nlast;
    i__ = blank_4.nlast;
    ++p;
    goto L12;
} /* search_ */

integer embede_(real *x)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i__;
#define stale ((real *)&blank_5 + 302)
    extern /* Subroutine */ int error_(integer *);

/* --- NAME CHANGED TO AVOID CONFLICTS IN THE 'ONE-PROGRAM' VERSION */
/* --- OF THE COMPILER */
/* dsw X	      IPMEM(7890) */
/*  IPMEM - MAIN MEMORY */
/*  ISFIN - TOP OF THE PROTOTYPE DICTIONARY STACK */
/*  LPMEM - DIVISION POINT OF IPMEM */
    ret_val = 1;
/* vax one real constant in one ipmem element (4 bytes) */
    i__ = blank_5.lpmem - 1;
    goto L10;
L5:
    ++i__;
    if (stale[i__ - 1] == *x) {
	goto L20;
    }
L10:
    if (i__ + 1 < blank_5.lpml) {
	goto L5;
    }
    if (blank_5.lpml + 1 > blank_5.lpmf) {
	goto L300;
    }
    i__ = blank_5.lpml;
    ++blank_5.lpml;
    stale[i__ - 1] = *x;
L20:
    ret_val = i__;
    return ret_val;
L300:
    error_(&c__199);
    return ret_val;
} /* embede_ */

#undef stale


/* Subroutine */ int tinser_(void)
{
    /* Initialized data */

    static struct {
	integer e_1[2];
	} equiv_1 = { 0, 0 };


    /* System generated locals */
    integer i__1, i__2;
    char ch__1[1];
    static integer equiv_0[1];

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i__, l, fill;
#define zero ((integer *)&equiv_1)
#define stringbuffer ((char *)equiv_0)
    extern /* Subroutine */ int ffwrite_ints__(integer *, integer *, integer *
	    );
#define zeroc ((char *)&equiv_1)
#define istringbuffer (equiv_0)
    static integer length, wrdsiz;
    extern /* Subroutine */ int ffwrite_(integer *, integer *, integer *);
    extern /* Character */ VOID int2char_(char *, ftnlen, integer *);

/* vax */

/* bc */
    blank_6.adres = 0;
    if (stream_2.errflg) {
	return 0;
    }
    if (blank_6.com[1] == 0) {
	return 0;
    }
    blank_6.adres = blank_6.text[0];
    length = (blank_6.mm << 1) - 2;
    if (blank_6.com[blank_6.mm - 1] < 256) {
	--length;
    }
/* write string length (in bytes) */
    ffwrite_ints__(&c__15, &length, &c__1);
/* write string itself without any padding */
    l = length / 2;
/* dsw - poprawka na wszelki wypadek */
    if (l == 0) {
	goto L101;
    }

    i__1 = l;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = blank_6.com[i__] & 255;
	int2char_(ch__1, (ftnlen)1, &i__2);
	*(unsigned char *)&stringbuffer[0] = *(unsigned char *)&ch__1[0];
	i__2 = lbit_shift(blank_6.com[i__], (ftnlen)-8);
	int2char_(ch__1, (ftnlen)1, &i__2);
	*(unsigned char *)&stringbuffer[1] = *(unsigned char *)&ch__1[0];
/* L100: */
	ffwrite_(&c__15, istringbuffer, &c__2);
    }
L101:
    if (length % 2 != 1) {
	goto L102;
    }
    i__1 = blank_6.com[l + 1] & 255;
    int2char_(ch__1, (ftnlen)1, &i__1);
    *(unsigned char *)&stringbuffer[0] = *(unsigned char *)&ch__1[0];
    ffwrite_(&c__15, istringbuffer, &c__1);
L102:
/* compute the number of trailing zero bytes */
    wrdsiz = 4;
    fill = wrdsiz - length % wrdsiz;
/* and write them */
    ffwrite_(&c__15, zero, &fill);
/* compute next string address */
    blank_6.text[0] = blank_6.text[0] + 1 + (length + fill) / wrdsiz;
    return 0;
} /* tinser_ */

#undef istringbuffer
#undef zeroc
#undef stringbuffer
#undef zero


integer key_(integer *adr)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer left, right, point;


/*   COMPUTES KEY OF THE ENCOUNTERED WORD. IT-S ADDRESS IS PASSED THRU */
/*   ADR. */

/*   STRUCTURE OF KEY TABLE: */

/* 	  KEYS(2*N)   - ADDRESS OF A KEYWORD */
/* 	  KEYS(2*N-1) - KEY OF THIS WORD */

/*   NOTE:  FOR THE WORDS THAT DO NOT OCCUR IN THE DICTIONARY */
/* 	   THE FUNCTION RETURNS IDENTIFIER KEYS */

/* --- SPECIAL CHECK IS MADE HERE FOR THE ENTRIES WHICH ARE MISSING */
/* --- IN THE HASH TABLE AND IN 'KEYS' */

/* --- READLN */
    if (*adr != 1833) {
	goto L9999;
    }
    ret_val = 256;
    return ret_val;
/* --- END OF CHECK FOR MISSING KEYS */
/*   get */
L9999:
    if (*adr != 59) {
	goto L9998;
    }
    ret_val = 249;
    return ret_val;
/*   put */
L9998:
    if (*adr != 1243) {
	goto L9997;
    }
    ret_val = 248;
    return ret_val;
/*  file */
L9997:
    if (*adr != 2339) {
	goto L9996;
    }
    ret_val = 518;
    return ret_val;
/*   open */
L9996:
    if (*adr != 2347) {
	goto L9995;
    }
    ret_val = 240;
    return ret_val;
/*   eof */
L9995:
    if (*adr != 1841) {
	goto L9994;
    }
    ret_val = 480;
    return ret_val;
/*   eoln */
L9994:
    if (*adr != 2579) {
	goto L9993;
    }
    ret_val = 481;
    return ret_val;
/*   text - key jak dla string */
L9993:
    if (*adr != 2249) {
	goto L9992;
    }
    ret_val = 517;
    return ret_val;
/*  direct - klasa 64/7 - jak dla typow pierwotnych */
L9992:
    if (*adr != 2097) {
	goto L8888;
    }
    ret_val = 519;
    return ret_val;
/*  putrec - klasa 34/0 */
L8888:
    if (*adr != 2075) {
	goto L8889;
    }
    ret_val = 272;
    return ret_val;
/*  getrec - klasa 34/1 */
L8889:
    if (*adr != 2081) {
	goto L8890;
    }
    ret_val = 273;
    return ret_val;
/* bc    ----- added concurrent statements */
/*  enable - klasa 35/0 */
L8890:
    if (*adr != 2047) {
	goto L8891;
    }
    ret_val = 280;
    return ret_val;
/*  disable - klasa 35/1 */
L8891:
    if (*adr != 2041) {
	goto L8892;
    }
    ret_val = 281;
    return ret_val;
/*  accept - klasa 36/0 */
L8892:
    if (*adr != 2053) {
	goto L8893;
    }
    ret_val = 288;
    return ret_val;
/* bc   -----------  end */
/*    break */
L8893:
    if (*adr != 1463) {
	goto L9991;
    }
    ret_val = 264;
    return ret_val;
L9991:
    ret_val = 8;
    left = 1;
    right = blank_7.com[0];
    if ((i__1 = blank_7.keys[(left << 1) - 1] - *adr) < 0) {
	goto L30;
    } else if (i__1 == 0) {
	goto L20;
    } else {
	goto L10;
    }
L10:
    return ret_val;
L20:
    point = left;
    goto L200;
L30:
    if ((i__1 = blank_7.keys[(right << 1) - 1] - *adr) < 0) {
	goto L10;
    } else if (i__1 == 0) {
	goto L40;
    } else {
	goto L50;
    }
L40:
    point = right;
    goto L200;
L50:
    point = (left + right) / 2;
    if ((i__1 = blank_7.keys[(point << 1) - 1] - *adr) < 0) {
	goto L100;
    } else if (i__1 == 0) {
	goto L200;
    } else {
	goto L300;
    }
L100:
    if (left == point) {
	return ret_val;
    }
    left = point;
    goto L50;
L200:
    ret_val = blank_7.keys[(point << 1) - 2];
    return ret_val;
L300:
    right = point;
    goto L50;
} /* key_ */

