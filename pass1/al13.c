/* al13.f -- translated by f2c (version 20090411).
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
	integer iop[4], p, tldim, tlbas, idl, objl, trdim, trbas, idr, objr, 
		treslt, convl, convr, nrpar, ix[261], lmem, lpmem, irecn, 
		isfin, lpmsys, lpml, lpmf, nrint, nrre, nrbool, nrchr, nrcor, 
		nrproc, nrtext, nruniv, nattr, nrnone, nblsys, nblus, nempty;
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
	integer object, ipmem[5000];
    } _2;
    struct {
	integer iop[4];
	logical errfg, dropfg;
	integer isbuf2[265], isbuf3[7], ix[5024];
    } _3;
} blank_;

#define blank_1 (blank_._1)
#define blank_2 (blank_._2)
#define blank_3 (blank_._3)

struct {
    integer cllrec;
    logical unicll;
} mcalls_;

#define mcalls_1 mcalls_

struct {
    integer pfpf, pfpa, pf, aprot, aid, aob, olpmf;
    logical dclass, aform;
} mpi2_;

#define mpi2_1 mpi2_

struct {
    integer prfxr, prfxl;
} mtpc_;

#define mtpc_1 mtpc_

struct {
    integer pstart, checks;
} mid_;

#define mid_1 mid_

struct {
    integer stob, prfx1, prfx2, slob1, slob2;
    logical wcl1, wcl2;
} mob_;

#define mob_1 mob_

struct {
    integer nm, nh;
} mem_;

#define mem_1 mem_

struct {
    logical errflg;
    integer line, ibuf2[265], ibuf3[7], junk[260];
} stream_;

#define stream_1 stream_

struct {
    integer ierc, msg;
} mjlmsg_;

#define mjlmsg_1 mjlmsg_

struct {
    logical deb;
    integer breakt[500], brnr, maxbr;
} debug_;

#define debug_1 debug_

/* Table of constant values */

static integer c__632 = 632;
static integer c__626 = 626;
static integer c__635 = 635;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__627 = 627;
static integer c__630 = 630;
static integer c__631 = 631;
static integer c__633 = 633;
static integer c__628 = 628;
static integer c__629 = 629;
static integer c__634 = 634;
static integer c__610 = 610;
static integer c__609 = 609;
static integer c__636 = 636;
static integer c__607 = 607;
static integer c__608 = 608;
static integer c__606 = 606;
static integer c__4 = 4;
static integer c__624 = 624;
static integer c__625 = 625;
static integer c__637 = 637;
static integer c__7 = 7;
static integer c__623 = 623;
static integer c__622 = 622;
static integer c__604 = 604;
static integer c__605 = 605;
static integer c__617 = 617;
static integer c__616 = 616;
static integer c__618 = 618;
static integer c__615 = 615;
static integer c__612 = 612;
static integer c__613 = 613;
static integer c__614 = 614;
static integer c__603 = 603;
static integer c__621 = 621;
static integer c__601 = 601;
static integer c__8 = 8;
static integer c__5 = 5;
static integer c__600 = 600;
static integer c__620 = 620;
static integer c__619 = 619;
static integer c__19 = 19;

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
/* DECK MPARPF */
/* Subroutine */ int mparpf_(integer *paprot, integer *paid, integer *paob, 
	logical *dcontr)
{
    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer zw, pael, pfel;
    extern /* Subroutine */ int merr_(integer *, integer *), mpio2_(logical *)
	    ;
#define stack ((integer *)&blank_1 + 302)
    extern integer mgetm_(integer *, integer *);
    static integer kindpa, kindpf, palgth, pflgth;
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int mfuneq_(integer *, integer *, integer *, 
	    integer *, logical *);

/* -------------BADA ZGODNOSC PARAMETRU AKTUALNEGO (FUNKCJI/PROCEDURY) */
/* 	      I PARAMETRU FORMALNEGO. */
/* 	      PAPROT - NUMER PROTOTYPU AKTUALNEGO */
/* 	      PAID - JEGO IDENTYFIKATOR ZE SCANNERA */
/* 	      PAOB - DOSTEPNOSC PRZEZ DISPLAY */
/* 	      DCONTR - NADAWANA JEST WARTOSC .TRUE., GDY KONIECZNA JEST */
/* 		    KONTROLA DYNAMICZNA */
/* 	  SYGNALIZOWANE BLEDY */
/* 	      626 - NIEZGODNOSC RODZAJOW PARAMETROW FORMALNEGO I AKTUAL- */
/* 		    NEGO (FUNKCJA<->PROCEDURA) */
/* 		NIEZGODNE NAGLOWKI */
/* 	      627 - NIEZGODNE RODZAJE PARAMETROW */
/* 	      628 - TYPY PARAMETROW SA NIEZGODNEGO RODZAJU */
/* 	      629 - TYPY PARAMETROW MAJA ROZLACZNE SEKWENCJE PREFIKSOWE */
/* 	      630 - NIEZGODNE DLUGOSCI LIST */
/* 		INNE */
/* 	      631 - NIEZGODNE TYPY FUNKCJI AKTUALNEJ I FORMALNEJ */
/* 	      632 - PARAMETR AKTUALNY NIE JEST FUNKCJA ANI PROCEDURA */
/* 	      635 - PARAMETR AKTUALNY JEST FUNKCJA LUB PROCEDURA */
/* 		    STANDARDOWA */

/* 	      OPIS W DOKUMENTACJI:	   ?3.7.4 */
/* 	      WERSJA Z DNIA:		   19.01.82 */
/* 	      DLUGOSC KODU:	  807 */
/* ............................................................................. */

/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */
/*     *CALL MPI2 */
/* ......BLOK KOMUNIKACJI PROCEDUR  MPARPF  ORAZ	MPIO2 */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MPI2 FROM LOGLAN.14  !! */

    mpi2_1.aprot = *paprot;
    mpi2_1.aid = *paid;
    mpi2_1.aob = *paob;

    *dcontr = TRUE_;

/* 	SPRAWDZENIE, CZY BEDZIE KONTROLA STATYCZNA */
    if (mcalls_1.unicll) {
	return 0;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 0) {
	return 0;
    }
    if (mpi2_1.aprot == blank_1.nruniv) {
	return 0;
    }

/* ------ KONTROLA ZGODNOSCI RODZAJOW */
/* 	  PF - OPIS PARAMETRU FORMALNEGO */
    mpi2_1.pf = blank_1.ipmem[mcalls_1.cllrec + 4];
    mpi2_1.pf = blank_1.ipmem[mpi2_1.pf - 1];
    zw = blank_1.ipmem[mpi2_1.aprot - 1];
    zw = (lbit_shift(zw, (ftnlen)-8) & 7) + 1;
/* 	  ZW - POLE  S	SLOWA ZEROWEGO PROTOTYPU AKTUALNEGO */
    switch (zw) {
	case 1:  goto L100;
	case 2:  goto L100;
	case 3:  goto L200;
	case 4:  goto L100;
	case 5:  goto L300;
	case 6:  goto L100;
	case 7:  goto L100;
	case 8:  goto L100;
    }

/* ------ TO NIE JEST ANI FUNKCJA, ANI PROCEDURA */
L100:
    merr_(&c__632, &mpi2_1.aid);
    return 0;

/* ...... PARAMETR AKTUALNY JEST FUNKCJA */
L200:
    palgth = -1;
/* 	  PALGTH - BEDZIE DLUGOSCIA LISTY PF DLA PROTOTYPU AKTUALNEGO */
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 4) {
	goto L1000;
    }
    goto L900;

/* ...... PARAMETR AKTUALNY JEST PROCEDURA */
L300:
    palgth = 0;
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 5) {
	goto L2000;
    }

/* ------ NIEZGODNOSC RODZAJOW */
L900:
    merr_(&c__626, &mpi2_1.aid);
    goto L2000;


/* ***** PARAMETRY SA FUNKCJAMI */
L1000:
/* --- ZBADANIE, CZY PF NIE JEST FUNKCJA DRUGIEGO RZEDU JESLI TAK */
/*     TO KONIECZNA JEST KONTROLA DYNAMICZNA */
    *dcontr = TRUE_;
    if (blank_1.ipmem[mcalls_1.cllrec + 1] == 2) {
	return 0;
    }
    *dcontr = FALSE_;
/* --- ZBADANIE ZGODNOSCI TYPOW FUNKCJI FORMALNEJ I AKTUALNEJ */
    mfuneq_(&mpi2_1.aprot, &mpi2_1.aid, &mpi2_1.aob, &mpi2_1.pf, dcontr);
    goto L3000;

/* ***** PARAMETRY SA PROCEDURAMI */
L2000:
    *dcontr = TRUE_;
    if (blank_1.ipmem[mcalls_1.cllrec + 1] == 2) {
	return 0;
    }
    *dcontr = FALSE_;


/* ************************************************************************* */
/* 	  WSPOLNA DLA FUNKCJI I PROCEDUR KONTROLA ZGODNOSCI LIST */

L3000:
    if (mpi2_1.aprot > blank_1.lpmsys) {
	goto L3010;
    }
/* 	--UZYTY MODUL STANDARDOWY */
    merr_(&c__635, &mpi2_1.aid);
/* 	TWORZONY JEST MALY REKORD ZAMIANY TYPOW (W CZESCI PRZEZNACZONEJ */
/* 	NA PROTOTYPY UZYTKOWNIKA */
L3010:
    mpi2_1.olpmf = blank_1.lpmf;
    *dcontr = FALSE_;
    mpi2_1.aform = FALSE_;
    if (bit_test(blank_1.ipmem[mpi2_1.aprot - 1],11)) {
	mpi2_1.dclass = TRUE_;
    }
    if ((lbit_shift(blank_1.ipmem[mpi2_1.aprot - 1], (ftnlen)-4) & 15) != 0) {
	mpi2_1.aform = TRUE_;
    }
    mpi2_1.dclass = mpi2_1.dclass || mpi2_1.aform;
/* ...... INICJALIZACJA */
    pfel = blank_1.ipmem[mpi2_1.pf + 2];
/* 	  ELEMENT LISTY PF FUN/PROC FORMALNEJ */
    pflgth = blank_1.ipmem[mpi2_1.pf + 3];
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 4) {
	--pflgth;
    }
    pael = blank_1.ipmem[mpi2_1.aprot + 2];
/* 	  ELEMENT LISTY PF FUN/PROC AKTUALNEJ */
    palgth += blank_1.ipmem[mpi2_1.aprot + 3];

/* ************* */
/* ------ SPRAWDZENIE CZY SA JESZCZE PARAMETRY W OBYDWU LISTACH */
    if (palgth == 0 || pflgth == 0) {
	goto L6000;
    }
/* 	  --- SKOK DO POROWNANIA DLUGOSCI LIST */
/* ********************************* */
/* ***** POBRANIE I PRZETWARZANIE KOLEJNYCH PARAMETROW */

L4000:
    mpi2_1.pfpf = blank_1.ipmem[pfel - 1];
    mpi2_1.pfpa = blank_1.ipmem[pael - 1];
/* 	  -PFPF - PARAMETR FORMALNY FUN/PROC FORMALNEJ */
/* 	  -PFPA - PARAMETR FORMALNY FUN/PROC AKTUALNEJ */
    kindpf = blank_1.ipmem[mpi2_1.pfpf - 1];
    kindpf = (lbit_shift(kindpf, (ftnlen)-4) & 15) + 1;
    kindpa = blank_1.ipmem[mpi2_1.pfpa - 1];
    kindpa = (lbit_shift(kindpa, (ftnlen)-4) & 15) + 1;
    switch (kindpf) {
	case 1:  goto L5000;
	case 2:  goto L4100;
	case 3:  goto L4200;
	case 4:  goto L4200;
	case 5:  goto L5000;
	case 6:  goto L4300;
	case 7:  goto L4300;
	case 8:  goto L5000;
	case 9:  goto L5000;
	case 10:  goto L4300;
    }

/* ......PFPF JEST TYPEM FORMALNYM */
/* 	PFPA TEZ MUSI BYC TYPEM FORMALNYM (LUB PARAMETREM */
/* 	UNIWERSALNYM) */
/* 	WSTAWIENIE PARY DO MALEGO REKORDU */
L4100:
    kindpf = mgetm_(&c__2, &c__0);
    blank_1.ipmem[kindpf - 1] = mpi2_1.pfpf;
    blank_1.ipmem[kindpf] = mpi2_1.pfpa;
    if (kindpa == 2) {
	goto L5000;
    }
    blank_1.ipmem[kindpf] = blank_1.nruniv;
    if (kindpa == 1) {
	goto L5000;
    }
/* 	  SKOK DO SYGNALIZACJI BLEDU */
    goto L4900;

/* ......PFPF JEST FUNKCJA LUB PROCEDURA */
/* 	  KONTROLA POLEGA JEDYNIE NA POROWNANIU RODZAJOW, GDYZ FUNKCJE I */
/* 	  PROCEDURY FORMALNE 2 RZEDU NIE NIOSA ZADNEJ INFORMACJI */
L4200:
    if (kindpa == kindpf) {
	goto L5000;
    }
    goto L4900;

/* ......PFPF JEST PARAMETREM INPUT/OUTPUT/INOUT */
/* 	  WYWOLANIE PROCEDURY KONTROLUJACEJ ZGODNOSC TYPOW */
L4300:
    if (kindpa <= 5) {
	goto L4900;
    }
    mpio2_(dcontr);
    if (kindpf == kindpa) {
	goto L5000;
    }

/* ......NIEZGODNE RODZAJE PFPF I PFPA */
L4900:
    merr_(&c__627, &mpi2_1.aid);
/* *****PRZESUNIECIE LIST PARAMETROW */
L5000:
    ++pfel;
    ++pael;
    --pflgth;
    --palgth;
    if (pflgth != 0 && palgth != 0) {
	goto L4000;
    }
/* *************************************** */

/* ****************** */
/* -------ZBADANIE ZGODNOSCI DLUGOSCI LIST PF */
/* 	  ZNISZCZENIE MALEGO REKORDU */
L6000:
    blank_1.lpmf = mpi2_1.olpmf;
    if (pflgth == palgth) {
	goto L6300;
    }
    if (pflgth < palgth) {
	goto L6100;
    }
/* 	LISTA AKTUALNA JEST KROTSZA, POWINNA BYC USZKODZONA BY NIE BYLO */
/* 	SYGNALIZACJI BLEDU */
/* 	ZW - POLE S PROTOTYPU APROT */
    if (zw == 4 || zw == 6) {
	return 0;
    }
    goto L6200;
/* 	TU: LISTA PF JEST KROTSZA, TA POWINNA BYC USZKODZONA BY NIE BYLO */
/* 	SYGNALIZACJI BLEDU */
L6100:
    zw = blank_1.ipmem[mpi2_1.pf - 1];
    zw = (lbit_shift(zw, (ftnlen)-8) & 7) + 1;
    if (zw == 4 || zw == 6) {
	return 0;
    }
/*     --- SYGNALIZACJA ROZNYCH DLUGOSCI LIST */
L6200:
    merr_(&c__630, &mpi2_1.aid);
    return 0;
/*     ---LISTY ROWNYCH DLUGOSCI, SYGNALIZACJA BLEDOW GDY (TYLKO) JEDNA Z NICH */
/* 	 JEST USZKODZONA */
L6300:
    if (zw == 4 || zw == 6) {
	goto L6100;
    }
/*     ---LISTA PARAMETROW MODULU AKTUALNEGO NIE JEST USZKODZONA, FORMALNEGO */
/*     ---TEZ NIE POWINNA BYC */
    zw = blank_1.ipmem[mpi2_1.pf - 1];
    zw = (lbit_shift(zw, (ftnlen)-8) & 7) + 1;
    if (zw == 4 || zw == 6) {
	goto L6200;
    }
/*     ---WSZYSTKO JEST W PORZADKU */
    return 0;
} /* mparpf_ */

#undef staler
#undef stack


/* DECK MFUNEQ */
/* Subroutine */ int mfuneq_(integer *pa, integer *aid, integer *aob, integer 
	*pf, logical *dcontr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer z__, azw, fzw;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern integer mtpcon_(integer *);
    extern /* Subroutine */ int mreptp_(integer *, integer *, integer *);
    extern integer mprfsq_(integer *, integer *);

/* --------------PROCEDURA POMOCNICZA BADAJACA ZGODNOSC TYPOW FUNKCJI */
/* 	       AKTUALNEJ(PA) I FORMALNEJ (PF). */
/* 	       POZOSTALE PARAMETRY JAK W MPARPF. */
/* 	       W RAZIE POTRZEBY NADAJE WARTOSC ZMIENNEJ DCONTR. */
/* 	    SYGNALIZOWANE BLEDY: */
/* 	       631 - NIEZGODNE TYPY FUNKCJI AKTUALNEJ I FORMALNEJ */
/* 	       633 - TYP FUNKCJI AKTUALNEJ JEST SLABIEJ OKRESLONY NIZ TYP */
/* 		     FUNKCJI FORMALNEJ */
/* 	      OPIS W DOKUMENTACJI:	    ?3.7.2 */
/* 	      WERSJA Z DNIA:		    19.01.82 */
/* 	      DLUGOSC KODU:	   663 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */
/*     *CALL MTPC */
/* ......BLOK KOMUNIKACJI Z PROCEDURA  MTPCON */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MTPC FROM LOGLAN.14  !! */

/* .....POBRANIE TYPU FUNKCJI AKTUALNEJ */
    blank_1.trdim = blank_1.ipmem[*pa - 5];
    blank_1.trbas = blank_1.ipmem[*pa - 4];
/* .....POBRANIE TYPU FUNKCJI FORMALNEJ */
    blank_1.tldim = blank_1.ipmem[*pf - 5];
    blank_1.tlbas = blank_1.ipmem[*pf - 4];
/* .....MODYFIKACJA TYPU FUNKCJI FORMALNEJ W OPARCIU O REKORD KONTROLI */
    blank_1.objl = blank_1.ipmem[mcalls_1.cllrec + 2];
    mreptp_(&blank_1.tldim, &blank_1.tlbas, &blank_1.objl);
/* .....POBRANIE SLOW ZEROWYCH TYPOW BAZOWYCH - POLA T */
    azw = blank_1.ipmem[blank_1.trbas - 1] & 15;
    fzw = blank_1.ipmem[blank_1.tlbas - 1] & 15;
/* ***************************** */
    if (blank_1.tldim > 0 || blank_1.trdim > 0) {
	goto L2000;
    }
/* ******************* */
/*     TYPY NIETABLICOWE */

/* .....ROZPOZNANIE PRZYPADKU TYPOW PIERWOTNYCH */
    if (azw >= 8) {
	goto L100;
    }
    if (fzw >= 8) {
	goto L200;
    }
    goto L1000;
/* 	--SKOK, GDY ZADEN TYP NIE JEST PIERWOTNY */
/* *****TYPY PIERWOTNE */
/* .....TRBAS (FUNKCJA AKTUALNA) JEST PIERWOTNY */
L100:
    if (blank_1.tlbas == blank_1.nruniv) {
	return 0;
    }
    if (blank_1.tlbas == blank_1.trbas) {
	return 0;
    }
    goto L9100;
/* 	--SKOK GDY TYPY SA NIEZGODNE */
/* .....TLBAS (FUNKCJA FORMALNA) JEST PIERWOTNY */
L200:
    if (blank_1.trbas == blank_1.nruniv) {
	return 0;
    }
/* 	GOTO  9100 */

/* *****TYPY ZLOZONE NIETABLICOWE */
L1000:
    if (blank_1.tlbas == blank_1.nruniv || blank_1.trbas == blank_1.nruniv) {
	return 0;
    }
/* .....OBYDWA TYPY SA KLASOWE, SYSTEMOWE LUB FORMALNE */
    if (fzw == 6) {
	goto L1100;
    }
    if (azw == 6) {
	goto L9200;
    }
/*     --TEN SKOK GDY TYP FUNKCJI AKTUALNEJ JEST SLABIEJ OKRESLONY - */
/* 	SYGNALIZACJA BLEDU */
/* .....OBYDWA TYPY SA KLASOWE LUB SYSTEMOWE */
/*     TYP FUNKCJI FORMALNEJ MUSI PREFIKSOWAC TYP FUNKCJI AKTUALNEJ */
    if (mprfsq_(&blank_1.tlbas, &blank_1.trbas) != 0) {
	goto L9000;
    }
/*     --SKOK GDY TAK NIE JEST */
/*     ...DODATKOWA KONTROLA DYNAMICZNA JEST POTRZEBNA, GDY WYWOLYWANY MODUL */
/* 	 JEST WIRTUALNY */
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 2) {
	*dcontr = TRUE_;
    }
    return 0;

/* .....TYP TLBAS FUNKCJI FORMALNEJ JEST FORMALNY */
L1100:
    if (azw == 6) {
	goto L1200;
    }
/*     ...TU TYP TLBAS JEST FORMALNY, TRBAS NIE - ZAWSZE POTRZEBNA KONTROLA */
/* 	 DYNAMICZNA */
    *dcontr = TRUE_;
    return 0;
/* .....OBYDWA TYPY SA FORMALNE */
/*     - GDY WYWOLYWANY PROTOTYP JEST WIRTUALNY POTRZBNA KONTROLA DYNAMICZNA */
/*     - W PRZECIWNYM PRZYPADKU ORAZ GDY TYPY ZAWSZE POCHODZA Z TEGO SAMEGO */
/* 	NIE MA KONTROLI DYNAMICZNEJ */
L1200:
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	goto L1250;
    }
    mtpc_1.prfxr = *aob;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) == 1) {
	return 0;
    }
/*     ...POTRZEBNA KONTROLA DYNAMICZNA */
L1250:
    *dcontr = TRUE_;
    return 0;


/* ******************** */
/*     TYPY ZLOZONE TABLICOWE (CO NAJMNIEJ JEDEN) */
L2000:
    if ((i__1 = blank_1.tldim - blank_1.trdim) < 0) {
	goto L2100;
    } else if (i__1 == 0) {
	goto L2200;
    } else {
	goto L2300;
    }

/* .....TLDIM<TRDIM (ZAWSZE KONTROLA DYNAMICZNA) */
/*     POPRAWNE WOWCZAS, GDY TLBAS JEST FORMALNY LUB UNIWERSALNY */
/*     - GDY OBA SA TYM SAMYM TYPEM FORMALNYM, TO POPRAWNE GDY */
/* 	 - POCHODZA Z ROZNYCH OBIEKTOW */
/* 	 - PROTOTYP WYWOLYWANY JEST WIRTUALNY */
L2100:
    if (blank_1.tlbas == blank_1.nruniv) {
	return 0;
    }
    if (fzw != 6) {
	goto L9100;
    }
    *dcontr = TRUE_;
    mtpc_1.prfxr = *aob;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) != 1) {
	return 0;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	return 0;
    }
    goto L9100;

/* .....TLDIM=TRDIM */
/*     POPRAWNE GDY */
/*     - OBA TYPY BAZOWE SA ROWNE */
/*     - TYP TLBAS JEST FORMALNY */
/*     - TLBAS LUB TRBAS JEST UNIWERSALNY */
L2200:
    if (blank_1.tlbas == blank_1.nruniv || blank_1.trbas == blank_1.nruniv) {
	return 0;
    }
    if (fzw == 6) {
	goto L2250;
    }
    if (azw == 6) {
	goto L9200;
    }
/* 	--SKOK DO SYGNALIZACJI TYPU SLABIEJ OKRESLONEGO */
    if (blank_1.tlbas == blank_1.trbas) {
	return 0;
    }
    goto L9100;

L2250:
    mtpc_1.prfxr = *aob;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) != 1) {
	*dcontr = TRUE_;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 1] == 1) {
	*dcontr = TRUE_;
    }
    return 0;

/* .....TLDIM>TRDIM */
/*     POPRAWNE JEDYNIE, GDY OBA TYPY SA FORMALNE LUB UNIWERSALNE */
L2300:
    if (blank_1.trbas == blank_1.nruniv) {
	return 0;
    }
    if (azw != 6) {
	goto L9100;
    }
    if (blank_1.tlbas == blank_1.nruniv) {
	return 0;
    }
    if (fzw != 6) {
	goto L9200;
    }
/*     ...OBYDWA SA FORMALNE */
    *dcontr = TRUE_;
    mtpc_1.prfxr = *aob;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) != 1) {
	return 0;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	return 0;
    }
    goto L9100;

/* *********************************** */
/*     SYGNALIZACJE BLEDOW */
/*     BADANIE OKRESLONOSCI TYPOW */
L9000:
    if (azw == 6 && fzw != 6) {
	goto L9200;
    }
    if (blank_1.tlbas != blank_1.nrcor && (blank_1.trbas == blank_1.nrcor || 
	    blank_1.trbas == blank_1.nrproc)) {
	goto L9200;
    }

/* .....TYPY NIEZGODNE */
L9100:
    merr_(&c__631, aid);
    return 0;
/* .....TYP FUNKCJI AKTUALNEJ JEST SLABIEJ OKRESLONY */
L9200:
    merr_(&c__633, aid);
    return 0;
} /* mfuneq_ */

#undef staler
#undef stack


/* DECK MPIO2 */
/* Subroutine */ int mpio2_(logical *dcontr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer z__, azw, fzw;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern integer mtpcon_(integer *);
    extern /* Subroutine */ int mreptp_(integer *, integer *, integer *);
    extern integer mprfsq_(integer *, integer *);

/* --------------PROCEDURA POMOCNICZA KONTROLUJACA ZGODNOSC TYPOW */
/* 	       PARAMETROW FORMALNYCH 'INPUT'/'OUTPUT' DRUGIEGO */
/* 	       RZEDU - TO ZNACZY WYSTEPUJACYCH W LISTACH ODPO- */
/* 	       WIADAJACEJ MODULOWI FORMALNEMU (PF) ORAZ ODPO- */
/* 	       WIADAJACEJ MODULOWI AKTUALNEMU (APROT) */
/* 		 PFPF, PFPA - OPISY UZGADNIANYCH PARAMETROW */
/* 	       /EWENTUALNA NIEZGODNOSC RODZAJOW PARAMETROW SYGNA- */
/* 	       LIZOWANA JEST PRZEZ PROCEDURE MPARPF */
/* 	     SYGNALIZOWANE BLEDY: */
/* 	       628 - NIEUZGODNIONE NAGLOWKI - TYPY PARAMETROW SA */
/* 		     NIEZGODNYCH RODZAJOW */
/* 	       629 - NIEUZGODNIONE NAGLOWKI - TYPY PARAMETROW MAJA */
/* 		     ROZLACZNE SEKWENCJE PREFIKSOWE */
/* 	       634 - NIEUZGODNIONE NAGLOWKI - TYP PARAMETRU W LISCIE */
/* 		     AKTUALNEJ JEST SLABIEJ OKRESLONY */

/* 	      OPIS W DOKUMENTACJI:	   ?3.7.3.5 */
/* 	      WERSJA Z DNIA:		   19.01.82 */
/* 	      DLUGOSC KODU:	   974 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */
/*     *CALL MTPC */
/* ......BLOK KOMUNIKACJI Z PROCEDURA  MTPCON */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MTPC FROM LOGLAN.14  !! */
/*     *CALL MPI2 */
/* ......BLOK KOMUNIKACJI PROCEDUR  MPARPF  ORAZ	MPIO2 */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MPI2 FROM LOGLAN.14  !! */

/* .....POBRANIE TYPOW PARAMETROW PFPF I PFPA */
    blank_1.trdim = blank_1.ipmem[mpi2_1.pfpa - 5];
    blank_1.trbas = blank_1.ipmem[mpi2_1.pfpa - 4];
    azw = blank_1.ipmem[blank_1.trbas - 1] & 15;
    blank_1.tldim = blank_1.ipmem[mpi2_1.pfpf - 5];
    blank_1.tlbas = blank_1.ipmem[mpi2_1.pfpf - 4];
    blank_1.objl = blank_1.ipmem[mcalls_1.cllrec + 2];
/* .....ODDZIELENIE PRZYPADKU, GDY KTORYS Z TYPOW SAM JEST PARAMETREM PF */
/*     LUB APROT */
    if (blank_1.ipmem[blank_1.tlbas - 2] == mpi2_1.pf) {
	goto L1000;
    }
/* 	--SKOK GDY TYP W MODULE FORMALNYM JEST WLASNYM PARAMETREM TEGO MODULU */
    if (azw != 6) {
	goto L2000;
    }
/* 	--SKOK GDY TYP W MODULE AKTUALNYM NIE JEST FORMALNY */
    if (blank_1.ipmem[blank_1.trbas - 2] == mpi2_1.aprot) {
	goto L1000;
    }
    if (mpi2_1.aform) {
	goto L2000;
    }
    if (mprfsq_(&blank_1.ipmem[blank_1.trbas - 2], &mpi2_1.aprot) == 1) {
	goto L1000;
    }
/* 	--SKOK GDY TYP W MODULE AKTUALNYM JEST WLASNYM PARAMETREM MODULU */
    goto L2000;

/* ***************************** */
/*     W CO NAJMNIEJ JEDNYM MODULE TYP JEST WLASNY W DRUGIM TEZ POWINIEN */
/*     BYC WLASNYM PARAMETREM I OBA POWINNY SOBIE  ODPOWIADAC */
L1000:
    if (blank_1.tlbas != blank_1.nruniv) {
	goto L1100;
    }
    if (blank_1.tldim <= blank_1.trdim) {
	return 0;
    }
    goto L9100;
L1100:
    if (blank_1.trbas != blank_1.nruniv) {
	goto L1200;
    }
    if (blank_1.tldim >= blank_1.trdim) {
	return 0;
    }
    goto L9100;
/* .....ZADEN TYP NIE JEST UNIWERSALNY, OBYDWA POWINNY BYC WLASNE I SOBIE */
/*     ODPOWIADAJACE */
L1200:
    if (azw != 6) {
	goto L9100;
    }
    if (blank_1.ipmem[blank_1.trbas - 2] == mpi2_1.aprot) {
	goto L1300;
    }
    if (mpi2_1.aform) {
	goto L9100;
    }
    if (mprfsq_(&blank_1.ipmem[blank_1.trbas - 2], &mpi2_1.aprot) != 1) {
	goto L9100;
    }
    if (blank_1.ipmem[blank_1.tlbas - 2] != mpi2_1.pf) {
	goto L9100;
    }
    if (blank_1.tldim != blank_1.trdim) {
	goto L9100;
    }
/* .....OBYDWA TYPY SA WLASNE I MAJA ROWNE WYMIARY, */
/*     SPRAWDZENIE ODPOWIEDNIOSCI */
    azw = blank_1.lpmf + 1;
L1300:
    if (blank_1.ipmem[azw - 1] == blank_1.tlbas) {
	goto L1400;
    }
    azw += 2;
    goto L1300;
L1400:
    blank_1.tlbas = blank_1.ipmem[azw];
    if (blank_1.tlbas == blank_1.trbas) {
	return 0;
    }
    goto L9100;

/* **************************************************** */
/* *******TYPY NIE SA WLASNYMI PARAMETRAMI MODULOW */
/* .....EWENTUALNA MODYFIKACJA TLBAS W OPARCIU O DUZY REKORD KONTROLI */
L2000:
    mreptp_(&blank_1.tldim, &blank_1.tlbas, &blank_1.objl);
    fzw = blank_1.ipmem[blank_1.tlbas - 1] & 15;
    if (blank_1.tldim != 0 || blank_1.trdim != 0) {
	goto L3000;
    }

/* ********************* */
/*     TYPY NIETABLICOWE */
    if (blank_1.trbas == blank_1.nruniv || blank_1.tlbas == blank_1.nruniv) {
	return 0;
    }
/* .....ODDZIELENIE TYPOW PRYMITYWNYCH */
    if (fzw >= 8) {
	goto L2200;
    }
    if (azw >= 8) {
	goto L2200;
    }
/* .....ZADEN TYP NIE JEST PRYMITYWNY */
/* .....ODDZILENIE TYPOW FORMALNYCH */
    if (fzw == 6) {
	goto L2300;
    }
    if (azw == 6) {
	goto L9300;
    }
/* 	--TEN SKOK GDY TYP W MODULE FORMALNYM JEST STATYCZNIE OKRESLONY, */
/* 	  NATOMIAST W MODULE AKTUALNYM JEST FORMALNY */
/*     **OBYDWA TYPY SA STATYCZNIE OKRESLONE - KLASOWE LUB SYSTEMOWE */
    if (blank_1.tlbas == blank_1.trbas) {
	goto L2100;
    }
    if (mprfsq_(&blank_1.tlbas, &blank_1.trbas) == -1) {
	goto L9200;
    }
/* 	--TYPY MAJA ROZLACZNE SEKWENCJE PREFIKSOWE - SKOK DO */
/* 	  SYGNALIZACJI BLEDU */
    if (mpi2_1.dclass) {
	*dcontr = TRUE_;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	*dcontr = TRUE_;
    }
    return 0;
/* 	    DODATKOWA KONTROLA JEST POTRZEBNA GDY MODUL AKTUALNY NIE JEST */
/* 	    RZECZYWISTY */
L2100:
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0 && mpi2_1.dclass) {
	*dcontr = TRUE_;
    }
/* 	    TYPY BYLY ROWNE - DODATKOWA KONTROLA DYNAMICZNA JEST */
/* 	    POTRZEBNA GDY JEDNOCZESNIE MODUL WYWOLYWANY BYL WIRTUALNY */
/* 	    ORAZ MODUL AKTUALNY NIE BYL RZECZYWISTY */
    return 0;

/*     **CO NAJMNIEJ JEDEN TYP JEST PRYMITYWNY, DRUGI POWINIEN BYC MU ROWNY */
L2200:
    if (blank_1.tlbas == blank_1.trbas) {
	return 0;
    }
    goto L9100;

/*     **CO NAJMNIEJ TYP TLBAS JEST FORMALNY */
/* 	TRBAS MOZE BYC WOWCZAS KLASOWY, SYSTEMOWY LUB FORMALNY */
L2300:
    if (azw == 6) {
	goto L2400;
    }
/*     ...TYLKO TLBAS JEST FORMALNY - POTRZEBNA KONTROLA DYNAMICZNA */
L2350:
    *dcontr = TRUE_;
    return 0;
/*     ...OBYDWA TYPY SA FORMALNE */
/* 	KONTROLA DYNAMICZNA JEST ZAWSZE KONIECZNA, GDY WYWOLYWANY MODUL JEST */
/* 	WIRTUALEM */
L2400:
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	goto L2350;
    }
/*     ...KONTROLI DYNAMICZNEJ NIE MA, GDY TYP JEST TEN SAM I ZAWSZE */
/* 	 POCHODZI Z TEGO SAMEGO OBIEKTU */
    mtpc_1.prfxr = mpi2_1.aob;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) == 1) {
	return 0;
    }
    *dcontr = TRUE_;
    return 0;


/* **************************************** */
/*     TYPY TABLICOWE */
L3000:
    if ((i__1 = blank_1.tldim - blank_1.trdim) < 0) {
	goto L3100;
    } else if (i__1 == 0) {
	goto L3200;
    } else {
	goto L3300;
    }

/* .....TLDIM<TRDIM */
/*     MOZE BYC POPRAWNE JEDYNIE GDY TLBAS JEST FORMALNY LUB UNIWERSALNY */
/*     GDY TYPY SA TYM SAYM TYPEM FORMALNYM, TO POPRAWNE GDY POCHODZA Z */
/*     ROZNYCH OBIEKTOW LUB APROT ALBO PROTOTYP WYWOLYWANY SA WIRTUALNE */
L3100:
    if (blank_1.tlbas == blank_1.nruniv) {
	return 0;
    }
    if (fzw != 6) {
	goto L9100;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	goto L3150;
    }
    if (bit_test(blank_1.ipmem[mpi2_1.aprot - 1],11)) {
	goto L3150;
    }
    mtpc_1.prfxr = mpi2_1.aob;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) == 1) {
	goto L9100;
    }
L3150:
    *dcontr = TRUE_;
    return 0;

/* .....TLDIM=TRDIM */
/*     POPRAWNE, GDY OBYDWA TYPY SA STATYCZNIE OKRESLONE I ROWNE LUB */
/*     TLBAS JEST FORMALNY LUB */
/*     TLBAS, TRBAS JEST UNIWERSALNY LUB */
/*     OBYDWA SA FORMALNE - WTEDY GDY PROTOTYP WYWOLYWANY NIE JEST WIRTUALNY */
/*     ANI MODUL AKTUALNY NIE JEST WIRTUALNY, TO KONTROLA DYNAMICZNA NIE JEST */
/*     POTRZEBNA O ILE TYPY SA ROWNE I ZAWSZE POCHODZA Z TEGO SAMEGO OBIEKTU */
L3200:
    if (blank_1.tlbas == blank_1.nruniv || blank_1.trbas == blank_1.nruniv) {
	return 0;
    }
    if (fzw == 6) {
	goto L3210;
    }
    if (blank_1.tlbas == blank_1.trbas) {
	return 0;
    }
    if (azw == 6) {
	goto L9300;
    }
    goto L9100;
/*     ...TYP TLBAS JEST FORMALNY */
L3210:
    if (azw == 6) {
	goto L3230;
    }
L3220:
    *dcontr = TRUE_;
    return 0;
/*     ...OBYDWA TYPY SA FORMALNE */
L3230:
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	goto L3220;
    }
    if (bit_test(blank_1.ipmem[mpi2_1.aprot - 1],11)) {
	goto L3220;
    }
    mtpc_1.prfxr = mpi2_1.aob;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) != 1) {
	goto L3220;
    }
    return 0;

/* .....TLDIM>TRDIMCPOPRAWNE JEDYNIE, GDY OBYDWA TYPY SA FORMALNE LUB */
/*     UNIWERSALNE */
L3300:
    if (blank_1.trbas == blank_1.nruniv) {
	return 0;
    }
    if (azw != 6) {
	goto L9100;
    }
    if (blank_1.tlbas == blank_1.nruniv) {
	return 0;
    }
    if (fzw != 6) {
	goto L9300;
    }
/*     ...OBYDWA TYPY SA FORMALNE */
    *dcontr = TRUE_;
    mtpc_1.prfxr = mpi2_1.aob;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) != 1) {
	return 0;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	return 0;
    }
    if (bit_test(blank_1.ipmem[mpi2_1.aprot - 1],11)) {
	return 0;
    }
    goto L9100;

/* *************************************** */
/*     SYGNALIZACJE BLEDOW */
L9100:
    merr_(&c__628, &mpi2_1.aid);
    return 0;
/*     BADANIE OKRESLONOSCI TYPOW */
L9200:
    if (blank_1.tlbas != blank_1.nrcor && (blank_1.trbas == blank_1.nrcor || 
	    blank_1.trbas == blank_1.nrproc)) {
	goto L9300;
    }
    merr_(&c__629, &mpi2_1.aid);
    return 0;
L9300:
    merr_(&c__634, &mpi2_1.aid);
    return 0;
} /* mpio2_ */

#undef staler
#undef stack


/* DECK MPARIO */
integer mpario_(integer *atdim, integer *atbase, integer *id, integer *aob)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer z__, pf, fob, fbas, fdim;
#define stack ((integer *)&blank_1 + 302)
    static logical fnform;
#define staler ((real *)&blank_1 + 302)
    extern /* Subroutine */ int mreptp_(integer *, integer *, integer *);
    extern integer msubst_(integer *);

/* -------------BADA ZGODNOSC TYPU PARAMETRU AKTUALNEGO (ATDIM, ATBASE) */
/* 	      Z TYPEM PARAMETRU FORMALNEGO (INPUT/OUTPUT). */
/* 	      ID - IDENTYFIKATOR UZYWANY W SYGNALIZACJI BLEDOW (NP. NAZWA */
/* 		   ZMIENNEJ, FUNKCJI) */
/* 	      AOB - OBIEKT W CIAGU SL, Z KTOREGO BRANY JEST PARAMETR */
/* 		   AKTUALNY, LUB 0 - GDY NIE JEST DOSTEPNY PRZEZ */
/* 		    DISPLAY */
/* 	      / WARTOSC FUNKCJI INFORMUJE O KONWERSJI LUB KONTROLI */
/* 		DYNAMICZNEJ - TAK JAK W  MSUBST. */
/* 		ODPOWIEDNIOSC JEST NASTEPUJACA: */
/* 		  - PARAMETR INPUT */
/* 		      LEWA STRONA - PARAMETR FORMALNY */
/* 		      PRAWA STRONA - PARAMETR AKTUALNY */
/* 		  - PARAMETR OUTPUT */
/* 		      LEWA STRONA - PARAMETR AKTUALNY */
/* 		      PRAWA STRONA - PARAMETR FORMALNY */
/* 	      DODATKOWE UWAGI KONTEKSTOWE: */
/* 		- W PRZYPADKU FUNKCJI I PROCEDUR WIRTUALNYCH - TYPY FOR- */
/* 		  MALNE SA ZAWSZE ZGODNE (ROZNICA W DZIALANIU MSUBST), */
/* 		  WYMAGANA JEST JEDNAK ZAWSZE KONTROLA DYNAMICZNA */
/* 		- GDY FUN/PROC JEST WIRTULNA LUB FORMALNA - TYPY KLASOWE SA */
/* 		  ZGODNE JESLI SA WE WSPOLNEJ SEKWENCJI PREFIKSOWEJ- KONTRO- */
/* 		  LA DYNAMICZNA ROWNIEZ ZAWSZE POTRZEBNA */

/* 	  SYGNALIZOWANE BLEDY */
/* 	      Z PROCEDURY  MSUBST */
/* 	      609 - NIEZGODNE TYPY */
/* 	      610 - ROZLACZNE SEKWENCJE PREFIKSOWE */

/* 	      OPIS W DOKUMENTACJI:	    ?3.6.2 */
/* 	      WERSJA Z DNIA:		    19.01.82 */
/* 	      DLUGOSC KODU:	   519 */
/* ............................................................................. */

/* 	 FNFORM MA WARTOSC .TRUE. GDY PARAMETR FORMALNY NIE JEST */
/* 	 TYPU FORMALNEGO */
/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */


    fnform = TRUE_;
    ret_val = 0;
/* ...... KONTROLA WYWOLANIA UNIWERSALNEGO */
    if (mcalls_1.unicll) {
	return ret_val;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 0) {
	return ret_val;
    }

/* ------POBRANIE TYPU PARAMETRU FORMALNEGO */
    pf = blank_1.ipmem[mcalls_1.cllrec + 4];
    pf = blank_1.ipmem[pf - 1];
/* 	  ... PF OPIS PARAMETRU FORMALNEGO */
    fdim = blank_1.ipmem[pf - 5];
    fbas = blank_1.ipmem[pf - 4];
/* 	  ...FDIM, FBAS - NIEZMODYFIKOWANY TYP PARAMETRU FORM. */

    fob = blank_1.ipmem[mcalls_1.cllrec + 2];
/* 	  PARAMETR FORMALNY "POCHODZI" Z TEGO SAMEGO OBIEKTU, CO OBIEKT */
/* 	  WYWOLYWANY */

/* ------BADANIE RODZAJU OBIEKTU WYWOLYWANEGO */

    if (blank_1.ipmem[mcalls_1.cllrec + 1] != 0) {
	goto L1000;
    }

/* ------ WYWOLYWANY ZWYKLY OBIEKT */
/* ...... MODYFIKACJA TYPU PARAMETRU FORMALNEGO */
    if ((blank_1.ipmem[fbas - 1] & 15) == 6) {
	fnform = FALSE_;
    }
    mreptp_(&fdim, &fbas, &fob);
/* ......BADANIE RODZAJU PARAMETRU FORMALNEGO */
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 6) {
	goto L95;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 2) {
	goto L100;
    }
/*     --- KONTROLA PARAMETRU INPUT */
    blank_1.tldim = fdim;
    blank_1.tlbas = fbas;
    blank_1.objl = fob;
    blank_1.idl = *id;
    blank_1.trdim = *atdim;
    blank_1.trbas = *atbase;
    blank_1.idr = *id;
    blank_1.objr = *aob;

    ret_val = msubst_(&z__);
/* 	   Z - SLEPY PARAMETR */
    if (fnform) {
	return ret_val;
    }
/* ....ZMIANA INFORMACJI O KONTROLI DYNAMICZNEJ GDY PARAMETR */
/*     FORMALNY JEST TYPU FORMALNEGO */
L90:
    if (ret_val == 3 || ret_val == 5) {
	++ret_val;
    }
    return ret_val;
/*     ---KONTROLA 'INOUT' - JAK OUTPUT PRZY PIERWSZYM WYWOLANIU, INPUT PRZY */
/* 	 DRUGIM */
L95:
    blank_1.ipmem[mcalls_1.cllrec + 6] = -6;
/*     --- KONTROLA PARAMETRU OUTPUT */
L100:
    blank_1.tldim = *atdim;
    blank_1.tlbas = *atbase;
    blank_1.idl = *id;
    blank_1.objl = *aob;
    blank_1.trbas = fbas;
    blank_1.trdim = fdim;
    blank_1.idr = *id;
    blank_1.objr = fob;

    ret_val = msubst_(&z__);
    if (fnform) {
	return ret_val;
    }
L110:
    if (ret_val == 3 || ret_val == 4) {
	ret_val += 2;
    }
    return ret_val;

/* ------ OBIEKTY FORMALNE I WIRTUALNE */
/* 	  ---UWAGA: OBIEKTY WIRTUALNE NIGDY NIE SA DOSTEPNE PRZEZ DISPLAY */
L1000:
    if (blank_1.ipmem[mcalls_1.cllrec + 1] == 1) {
	fob = 0;
    }
/* ...... MODYFIKACJA TYPU PARAMETRU FORMALNEGO */
    if ((blank_1.ipmem[fbas - 1] & 15) == 6) {
	fnform = FALSE_;
    }
    mreptp_(&fdim, &fbas, &fob);
/* ...... BADANIE RODZAJU PARAMETRU FORMALNEGO */
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 2) {
	goto L1100;
    }
/*     --- KONTROLA PARAMETRU INPUT */
    blank_1.tldim = fdim;
    blank_1.tlbas = fbas;
    blank_1.idl = *id;
    blank_1.objl = fob;
    blank_1.trdim = *atdim;
    blank_1.trbas = *atbase;
    blank_1.idr = *id;
    blank_1.objr = *aob;

    ret_val = msubst_(&z__);
    if (fnform) {
	goto L1200;
    }
    goto L90;
/*     --- KONTROLA PARAMETRU OUTPUT */
L1100:
    blank_1.tldim = *atdim;
    blank_1.tlbas = *atbase;
    blank_1.idl = *id;
    blank_1.objl = *aob;
    blank_1.trdim = fdim;
    blank_1.trbas = fbas;
    blank_1.idr = *id;
    blank_1.objr = fob;

    ret_val = msubst_(&z__);
/* ...... SPRAWDZENIE, CZY NIE SA TO TYPY KLASOWE- DLA NICH ZAWSZE */
/*      KONTROLA DYNAMICZNA */
    if (! fnform) {
	goto L110;
    }
L1200:
    if (ret_val != 0) {
	return ret_val;
    }
/* 	  ... PF - OPIS PARAMETRU FORMALNEGO */
    if (blank_1.ipmem[pf - 5] != 0) {
	return ret_val;
    }
    pf = blank_1.ipmem[pf - 4];
/*     ..PF - OPIS TYPU PARAMETRU */
    pf = blank_1.ipmem[pf - 1] & 15;
    if (pf >= 8) {
	return ret_val;
    }
    ret_val = 3;
    return ret_val;
} /* mpario_ */

#undef staler
#undef stack


/* DECK MSUBST */
integer msubst_(integer *x)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer z__, tpl, tpr;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern integer mtpcon_(integer *), mprfsq_(integer *, integer *);

/* 		 X - SLEPY PARAMETR */

/* -------------PROCEDURA BADA POPRAWNOSC INSTRUKCJI PODSTAWIENIA. */
/* 	      JEST ROWNIEZ WYWOLYWANA W PROCEDURZE KONTROLI */
/* 	      TYPOW PARAMETROW FORMALNYCH I AKTUALNYCH. */
/* 	      ZNACZENIE  : */
/* 	       - TLDIM, TLBAS - TYP LEWEJ STRONY INSTRUKCJI PODSTAWIENIA, */
/* 		 OBJL - PROTOTYP, Z KTOREGO POCHODZI, LUB 0 - NIEDOSTEPNA */
/* 		 PRZEZ DISPLAY */
/* 		 IDL - IDENTYFIKATOR LEWEJ STRONY (DO SYGNALIZACJI */
/* 		 BLEDOW), */
/* 	       - ANALOGICZNIE DLA PRAWEJ STRONY - TRDIM, TRBAS, */
/* 		 OBJR . */
/* 	      // WARTOSC FUNKCJI OKRESLA RODZAJ KONWERSJI LUB KONTROLI */
/* 		 DYNAMICZNEJ : */
/* 		0 - OBIE STRONY SA TEGO SAMEGO TYPU, */
/* 		1 - INTEGER := REAL */
/* 		2 - REAL := INTEGER */
/* 		DYNAMICZNA KONTROLA TYPOW */
/* 		3 - OBA TYPY OKRESLONE (STATYCZNIE) */
/* 		4 - TYP LEWEJ STRONY FORMALNY, PRAWEJ OKRESLONY */
/* 		5 - TYP LEWEJ STRONY OKRESLONY, PRAWEJ FORMALNY */
/* 		6 - TYPY OBYDWU STRON FORMALNE */
/* 	  ----SYGNALIZOWANE BLEDY */
/* 	      609 - NIEZGODNE TYPY W PODSTAWIENIU */
/* 	      610 - TYPY W PODSTAWIENIU MAJA ROZLACZNE SEKWENCJE PREFI- */
/* 		    KSOWE */
/* 	      636 - NIEDOZWOLONE UZYCIE SEMAFORA */

/* 	      OPIS W DOKUMENTACJI:	    ?2.7 */
/* 	      WERSJA Z DNIA:		    19.01.82 */
/* 	      DLUGOSC KODU:	    617 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL MTPC */
/* ......BLOK KOMUNIKACJI Z PROCEDURA  MTPCON */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MTPC FROM LOGLAN.14  !! */

/* 	INICJOWANA WARTOSC MSUBST - 3 ODPOWIADAJACA KONTROLI DYNAMICZNEJ */
    ret_val = 3;
    if (blank_1.tldim == 0 && blank_1.tlbas == blank_1.nruniv) {
	return ret_val;
    }
    if (blank_1.trdim == 0 && blank_1.trbas == blank_1.nruniv) {
	return ret_val;
    }
/* 	POWROTY - GDY JEDEN Z TYPOW JEST UNIWERSALNY */

    tpl = blank_1.ipmem[blank_1.tlbas - 1] & 15;
    tpr = blank_1.ipmem[blank_1.trbas - 1] & 15;
/* 	TPL I TPR - POLA T Z OPISU TYPOW TLBAS I TRBAS */
    if (blank_1.tldim != 0 || blank_1.trdim != 0) {
	goto L1000;
    }
/* 	  SKOK DO BADANIA PODSTAWIEN DLA TYPOW TABLICOWYCH */
/* ------ TYPY NIETABLICOWE - ZADEN Z NICH NIE JEST JUZ UNIWERSALNY */

    switch (tpl) {
	case 1:  goto L9000;
	case 2:  goto L100;
	case 3:  goto L100;
	case 4:  goto L9500;
	case 5:  goto L100;
	case 6:  goto L200;
	case 7:  goto L100;
	case 8:  goto L300;
	case 9:  goto L9100;
	case 10:  goto L400;
	case 11:  goto L500;
	case 12:  goto L400;
	case 13:  goto L9000;
	case 14:  goto L9000;
    }

/* ...... TPL JEST TYPEM KLASOWYM LUB SYSTEMOWYM */
L100:
    switch (tpr) {
	case 1:  goto L9000;
	case 2:  goto L110;
	case 3:  goto L110;
	case 4:  goto L9500;
	case 5:  goto L110;
	case 6:  goto L150;
	case 7:  goto L110;
	case 8:  goto L9000;
	case 9:  goto L9100;
	case 10:  goto L9000;
	case 11:  goto L9000;
	case 12:  goto L9000;
	case 13:  goto L9000;
	case 14:  goto L130;
    }
/*     ... TPR JEST ROWNIEZ TYPEM KLASOWYM LUB SYSTEMOWYM */
/* 	  SPRAWDZENIE PREFIKSOWANIA */
L110:
    if ((i__1 = mprfsq_(&blank_1.tlbas, &blank_1.trbas)) < 0) {
	goto L120;
    } else if (i__1 == 0) {
	goto L130;
    } else {
	goto L140;
    }
/* 	  SEKWENCJE PREFIKSOWE ROZLACZNE - PODSTAWIENIE MOZE BYC POPRAW- */
/* 	  NE JEDYNIE GDY JEDEN Z TYPOW JEST SYSTEMOWY */
L120:
    if (blank_1.trbas == blank_1.nrcor || blank_1.tlbas == blank_1.nrcor) {
	return ret_val;
    }
    if (blank_1.trbas == blank_1.nrproc || blank_1.tlbas == blank_1.nrproc) {
	return ret_val;
    }
    merr_(&c__610, &blank_1.idl);
    return ret_val;

/* 	  TPL JEST PREFIKSEM TPR - KONTROLA DYNAMICZNA NIE JEST */
/* 	  POTRZEBNA, TPR MOZE BYC ROWNIEZ  NONE */
L130:
    ret_val = 0;
    return ret_val;

/* 	  TPR JEST PREFIKSEM TPL - KONTROLA DYNAMICZNA JEST POTRZEBNA */
/* 	  KONTEKSTOWO SYTUACJA JEST POPRAWNA */
L140:
    return ret_val;
/*     ... TPR JEST FORMALNY */
L150:
    ret_val = 5;
    return ret_val;


/* ...... TPL JEST TYPEM FORMALNYM - TPR MUSI BYC TYPEM FORMALNYM, KLASO- */
/* 	WYM, SYSTEMOWYM LUB  NONE */
L200:
    ret_val = 4;
    switch (tpr) {
	case 1:  goto L9000;
	case 2:  goto L210;
	case 3:  goto L210;
	case 4:  goto L9500;
	case 5:  goto L210;
	case 6:  goto L220;
	case 7:  goto L210;
	case 8:  goto L9000;
	case 9:  goto L9100;
	case 10:  goto L9000;
	case 11:  goto L9000;
	case 12:  goto L9000;
	case 13:  goto L9000;
	case 14:  goto L210;
    }
/*     ...TPR - KLASOWY, SYSTEMOWY LUB  NONE */
L210:
    return ret_val;
/*     ... TPR - FORMALNY */
L220:
    ret_val = 6;
    mtpc_1.prfxr = blank_1.objr;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) == 1) {
	ret_val = 0;
    }
    return ret_val;


/* ...... TPL JEST ARYTMETYCZNY, TPR TEZ MUSI BYC ARYTMETYCZNY */
L300:
    if (blank_1.trbas != blank_1.nrint && blank_1.trbas != blank_1.nrre) {
	goto L9000;
    }
    ret_val = 0;
    if (blank_1.tlbas == blank_1.trbas) {
	return ret_val;
    }
/* 	  TU - TYPY ROZNE - POTRZEBNA KONWERSJA */
    ret_val = 2;
    if (blank_1.tlbas == blank_1.nrint) {
	ret_val = 1;
    }
    return ret_val;

/* ...... TPL - INNY PRYMITYWNY, TPR MUSI BYC MU ROWNE */
L400:
    ret_val = 0;
    if (blank_1.tlbas == blank_1.trbas) {
	return ret_val;
    }
    goto L9000;
/* .......TPL - FILE, TPR MUSI BYC FILE LUB NONE */
L500:
    ret_val = 0;
    if (blank_1.tlbas == blank_1.trbas || blank_1.trbas == blank_1.nrnone) {
	return ret_val;
    }
    goto L9000;


/* ------ CO NAJMNIEJ JEDEN TYP JEST TABLICOWY */

L1000:
    if ((i__1 = blank_1.tldim - blank_1.trdim) < 0) {
	goto L2000;
    } else if (i__1 == 0) {
	goto L3000;
    } else {
	goto L4000;
    }
/* ...... PRZYPADEK  TLDIM < TRDIM */
/* 	WOWCZAS PODSTAWIENIE JEST POPRAWNE JEDYNIE, GDY TLBAS JEST FOR- */
/* 	MALNY LUB UNIWERSALNY. W PRZYPADKU, GDY OBA TYPY SA TYM SAMYM */
/* 	TYPEM FORMALNYM - MUSZA POCHODZIC Z ROZNYCH OBIEKTOW. */
L2000:
    if (tpl == 4) {
	return ret_val;
    }
/* 	      POWROT DLA TYPU UNIWERSALNEGO */
    if (tpl != 6) {
	goto L9000;
    }
/* 	  SKOK DO SYGNALIZACJI BLEDU DLA TYPU NIEFORMALNEGO */
    ret_val = 4;
    if (tpr == 6) {
	ret_val = 6;
    }
    goto L8000;

/* ......PRZYPADEK  TLDIM = TRDIM */
/* 	POPRAWNE, GDY */
/* 	  - OBA TYPY BAZOWE SA ROWNE */
/* 	  - CO NAJMNIEJ JEDEN JEST FORMALNY LUB UNIWERSALNY */
L3000:
    if (tpl == 4 || tpr == 4) {
	return ret_val;
    }
/* 	  POWROT - GDY JEDEN Z TYPOW JEST UNIWERSALNY */

    if (tpl == 6 && tpr == 6) {
	goto L3300;
    }
    if (tpl == 6) {
	goto L3100;
    }
    if (tpr == 6) {
	goto L3200;
    }
/* 	       SKOKI ROZDZIELAJACE PRZYPADKI TYPOW FORMALNYCH */
/* 	  ... PRZYPADEK, GDY TYPY NIE SA FORMALNE */
    ret_val = 0;
    if (blank_1.tlbas == blank_1.trbas) {
	return ret_val;
    }
/* 	  TU - NIEROWNE TYPY NIEFORMALNE - SKOK DO SYGNALIZACJI BLEDOW */
    goto L9000;

/*     ... TLBAS JEST FORMALNY, TRBAS NIE */
L3100:
    ret_val = 4;
    return ret_val;
/*     ... TRBAS JEST FORMALNY, TLBAS NIE */
L3200:
    ret_val = 5;
    return ret_val;
/*     ... TLBAS I TRBAS SA FORMALNE, SPRAWDZENIE,CZY SA ROWNE I LOKALNE */
/* 	  (WTEDY NIE MA KONTROLI DYNAMICZNEJ) */
L3300:
    ret_val = 6;
    mtpc_1.prfxr = blank_1.objr;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) == 1) {
	ret_val = 0;
    }
    return ret_val;

/* ...... PRZYPADEK  TLDIM > TRDIM */
/* 	  POPRAWNE,GDY: */
/* 	   - TYP NONE Z PRAWEJ STRONY */
/* 	   - TRBAS JEST FORMALNY LUB UNIWERSALNY, W PRZYPADKU GDY OBA */
/* 	     TYPY SA TYM SAMYM TYPEM FORMALNYM CO NAJMNIEJ JEDEN Z NICH */
/* 	     MUSI BYC NIELOKALNY */
L4000:
    ret_val = 0;
    if (tpr == 4) {
	return ret_val;
    }
/* 	  POWROT DLA TYPU UNIWERSALNEGO Z PRAWEJ STRONY */
    if (tpr == 14 && blank_1.trdim == 0) {
	return ret_val;
    }
/* 	  POWROT DLA STALEJ  NONE */
    if (tpr != 6) {
	goto L9000;
    }
/* 	  SKOK DO SYGNALIZACJI BLEDU DLA TYPU NIEFORMALNEGO */
    ret_val = 5;
    if (tpl == 6) {
	ret_val = 6;
    }
/* 	GOTO  8000 - PRZEJSCIE DO BADANIA TYPOW TABLICOWYCH */


/* ------ BADANIE ZGODNOSCI FORMALNYCH TYPOW TABLICOWYCH */

L8000:
    mtpc_1.prfxr = blank_1.objr;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) == 1) {
	goto L9000;
    }
    return ret_val;



/* ------SYGNALZACJA BLEDOW */
L9000:
    if (tpr == 9) {
	goto L9100;
    }
    merr_(&c__609, &blank_1.idl);
L9500:
    return ret_val;
L9100:
    if (tpl == 9) {
	merr_(&c__636, &blank_1.idl);
    }
    if (tpr == 9) {
	merr_(&c__636, &blank_1.idr);
    }
    return ret_val;
} /* msubst_ */

#undef staler
#undef stack


/* DECK MEQUAL */
/* Subroutine */ int mequal_(integer *case__)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer z__, tpl, tpr;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)
    extern integer mtpcon_(integer *), mprfsq_(integer *, integer *);

/* -------------PROCEDURA BADA ZGODNOSC ARGUMENTOW RELACJI  =  I	=/= . */
/* 	      TYPY PRAWEGO I LEWEGO ARGUMENTU PRZEKAZANE SA PRZEZ */
/* 	      BLOK  /SEMANT/ , SA TO : */
/* 		TLDIM, TLBAS - DLA LEWEGO ARGUMENTU */
/* 		TRDIM, TRBAS - DLA PRAWEGO ARGUMENTU. */
/* 	      ZMIENNE OBJL, OBJR - NUMERY PROTOTYPOW OBIEKTOW, KTORYCH */
/* 	      ATRYBUTAMI SA ODPOWIEDNIO LEWY I PRAWY ARGUMENT OPERACJI. */
/* 		SA ONE ROWNE ZERU, GDY ARGUMENTY NIE SA DOSTEPNE PRZEZ */
/* 		DISPLAY. */
/* 	      ZMIENNE  IDL ORAZ IDR  SLUZA DO IDENTYFIKACJI BLEDOW - SA */
/* 	      TO IDENTYFIKATORY LEWEGO I PRAWEGO ARGUMENTU. */
/* 	      // WARTOSCI PARAMETRU CASE PRZY WYJSCIU OKRESLAJA : */
/* 		1 - OBA ARGUMENTY SA INTEGER */
/* 		2 - CO NAJMNIEJ JEDEN ARGUMENT JEST TYPU REAL, DRUGI */
/* 		    MUSI BYC ARYTMETYCZNY. ZMIENNE  CONVL I CONVR  OKRE- */
/* 		   SLAJA EWENTUALNA KONWERSJE */
/* 		3 - OBA ARGUMENTY SA BOOLOWSKIE */
/* 		4 - OBA ARGUMENTY SA TYPU  CHAR */
/* 		5 - OBA ARGUMENTY SA TYPU REFERENCYJNEGO (ROWNIEZ */
/* 		    TABLICOWEGO, TEGO SAMEGO FORMALNEGO I PLIKOWEGO) */
/* 		       - ZGODNE STATYCZNIE */
/* 		6 - J.W. - CO NAJMNIEJ JEDEN JEST FORMALNY I WYMAGANA */
/* 		   DYNAMICZNA KONTROLA ZGODNOSCI */
/* 	  ----SYGNALIZOWANE BLEDY: */
/* 	      606 - RODZAJE TYPOW WYSTEPUJACYCH W POROWNANIU SA NIEZGO- */
/* 		    DNE */
/* 	      607 - W POROWNANIU BIORA UDZIAL TYPY KLASOWE Z ROZLACZNA */
/* 		    SEKWENCJA PREFIKSOWA */
/* 	      608 - POROWNYWANY JEST TYP  STRING */
/* 	      636 - NIEDOZWOLONE UZYCIE SEMAFORA */

/* 	      OPIS W DOKUMENTACJI:	    ?2.6 */
/* 	      WERSJA Z DNIA:		    13.05.83 (FRIDAY) */
/* 	      DLUGOSC KODU:	   664 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL MTPC */
/* ......BLOK KOMUNIKACJI Z PROCEDURA  MTPCON */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MTPC FROM LOGLAN.14  !! */

    blank_1.convl = 0;
    blank_1.convr = 0;
    tpl = blank_1.ipmem[blank_1.tlbas - 1] & 15;
    tpr = blank_1.ipmem[blank_1.trbas - 1] & 15;
/* 	TPL,TPR - POLA T  TYPOW BAZOWYCH  LEWEJ I PRAWEJ STRONY */
    if (blank_1.tldim != 0 || blank_1.trdim != 0) {
	goto L1000;
    }
/* 	  SKOK DO POROWNYWANIA TYPOW TABLICOWYCH */

    switch (tpl) {
	case 1:  goto L9000;
	case 2:  goto L100;
	case 3:  goto L100;
	case 4:  goto L200;
	case 5:  goto L100;
	case 6:  goto L300;
	case 7:  goto L100;
	case 8:  goto L400;
	case 9:  goto L9100;
	case 10:  goto L500;
	case 11:  goto L800;
	case 12:  goto L700;
	case 13:  goto L9000;
	case 14:  goto L300;
    }

/* -----TPL JEST TYPEM KLASOWYM LUB SYSTEMOWYM */
L100:
    *case__ = 5;
    switch (tpr) {
	case 1:  goto L9000;
	case 2:  goto L110;
	case 3:  goto L110;
	case 4:  goto L120;
	case 5:  goto L110;
	case 6:  goto L130;
	case 7:  goto L110;
	case 8:  goto L9000;
	case 9:  goto L9100;
	case 10:  goto L9000;
	case 11:  goto L9000;
	case 12:  goto L9000;
	case 13:  goto L9000;
	case 14:  goto L120;
    }
/* ....... TPR JEST TEZ TYPEM KLASOWYM LUB SYSTEMOWYM */
L110:
    if (blank_1.trbas == blank_1.nrcor || blank_1.tlbas == blank_1.nrcor) {
	return 0;
    }
    if (blank_1.trbas == blank_1.nrproc || blank_1.tlbas == blank_1.nrproc) {
	return 0;
    }
/* 	  PRZYPADEK, GDY OBA TYPY SA TYPAMI KLASOWYMI - WOWCZAS ICH */
/* 	  SEKWENCJE PREFIKSOWE NIE MOGA BYC ROZLACZNE */
    if (mprfsq_(&blank_1.trbas, &blank_1.tlbas) >= 0) {
	return 0;
    }
/* 	  ROZLACZNE SEKWENCJE PREFIKSOWE PONIZEJ */
    merr_(&c__607, &blank_1.idl);
    return 0;

/* ....... TPR JEST TYPEM UNIWERSALNYM LUB TYPEM	NONE */
L120:
    return 0;

/* ....... TPR JEST TYPEM FORMALNYM */
L130:
    *case__ = 6;
    return 0;


/* ----- TPL JEST TYPEM UNIWERSALNYM, WTEDY POROWNANIE JEST ZAWSZE */
/* 	POPRAWNE - O ILE TPR NIE JEST TYPEM TEKSTOWYM */
L200:
    *case__ = 5;
    if (blank_1.trbas == blank_1.nrtext) {
	goto L700;
    }
    return 0;

/* ----- TPL  JEST TYPEM FORMALNYM LUB TYPEM NONE - BY ZACHODZILA ZGODNOSC */
/*     TO  TPR  MUSI BYC TYPEM FORMALNYM, KLASOWYM, SYSTEMOWYM, UNIWER- */
/*     SALNYM LUB NONE */
L300:
    *case__ = 6;
    if (tpl == 14 || tpr == 14) {
	*case__ = 5;
    }
/* -----JESLI POROWNANIE NONE Z FILE */
    if (tpl == 14 && tpr == 11) {
	return 0;
    }
    if (tpr >= 13) {
	return 0;
    }
    if (tpr >= 8) {
	goto L9000;
    }
    if (tpr == 6) {
	goto L8000;
    }
    if (tpr >= 1) {
	return 0;
    }
    goto L9000;

/* ----- TPL JEST TYPEM ARYTMETYCZNYM, WTEDY TPR TEZ MUSI BYC ARYTMETYCZNE */
/* 	(LUB UNIWERSALNE) */
L400:
    if (blank_1.trbas != blank_1.nrint && blank_1.trbas != blank_1.nrre && 
	    blank_1.trbas != blank_1.nruniv) {
	goto L9000;
    }
    *case__ = 2;
/* dsw      IF ((TPR .EQ.TPL) .AND. (TRBAS .EQ.NRINT)) CASE = 1 */
    if (blank_1.trbas == blank_1.tlbas && blank_1.trbas == blank_1.nrint) {
	*case__ = 1;
    }
    blank_1.convl = 0;
    blank_1.convr = 0;
    if (*case__ == 1) {
	return 0;
    }
    if (blank_1.tlbas == blank_1.nrint) {
	blank_1.convl = 1;
    }
    if (blank_1.trbas == blank_1.nrint) {
	blank_1.convr = 1;
    }
    return 0;

/* -----TPL  JEST TYPEM BOOLEAN LUB CHARACTER, WTEDY TPR MUSI BYC ROWNIEZ */
/* 	BOOLEAN LUB CHARACTER (LUB UNIWERSALNY) */
L500:
    if (blank_1.trbas == blank_1.nrchr || blank_1.tlbas == blank_1.nrchr) {
	goto L600;
    }
    *case__ = 3;
    if (blank_1.trbas == blank_1.nrbool || blank_1.trbas == blank_1.nruniv) {
	return 0;
    }
    goto L9000;

/* -----TPL  JEST TYPEM  CHAR, WTEDY  TPR MUSI BYC BADZ  CHAR BADZ UNIWER- */
/*     SALNY */
L600:
    *case__ = 4;
    if (blank_1.trbas == blank_1.nrchr || blank_1.trbas == blank_1.nruniv) {
	return 0;
    }
    goto L9000;

/* -----TPL JEST TYPEM TEKSTOWYM, NIEZALEZNIE OD TPR JEST TO BLAD */
L700:
    *case__ = 5;
    merr_(&c__608, &blank_1.idl);
    if (blank_1.trbas == blank_1.nrtext) {
	merr_(&c__608, &blank_1.idr);
    }
    return 0;

/* -----TPL - FILE. TPR MUSI BYC FILE LUB UNIWERSALNY LUB NONE */
L800:
    *case__ = 5;
    if (tpr == 11 || blank_1.trbas == blank_1.nruniv || blank_1.trbas == 
	    blank_1.nrnone) {
	return 0;
    }
    goto L9000;


/* ----- POROWNYWANIE TYPOW TABLICOWYCH */
L1000:
    *case__ = 5;
    if ((i__1 = blank_1.tldim - blank_1.trdim) < 0) {
	goto L2000;
    } else if (i__1 == 0) {
	goto L3000;
    } else {
	goto L4000;
    }
/* ...... PRZYPADEK  TLDIM < TRDIM */
/* 	WOWCZAS POPRAWNE JEDYNIE, GDY TLBAS JEST FORMALNY, UNIWERSALNY */
/* 	LUB NONE */
/* 	W PRZYPADKU, GDY OBA TYPY SA TYM SAMYM TYPEM FORMALNYM MUSZA */
/* 	POCHODZIC Z ROZNYCH OBIEKTOW */
L2000:
    if (tpl == 4 || tpl == 14) {
	return 0;
    }
    if (tpl != 6) {
	goto L9000;
    }
/* 	KONTROLA, GDY CO NAJMNIEJ JEDENz JEST FORMALNY */
    goto L8500;

/* ...... PRZYPADEK  TLDIM = TRDIM */
/* 	POPRAWNE, GDY : */
/* 	  - OBA TYPY BAZOWE SA ROWNE */
/* 	LUB - CO NAJMNIEJ JEDEN Z NICH JEST FORMALNY LUB UNIWERSALNY */
L3000:
    if (tpr == 4 || tpl == 4) {
	return 0;
    }
    if (tpr == 6 || tpl == 6) {
	goto L8000;
    }
/* 	  SKOK, GDY CO NAJMNIEJ JEDEN TYP BAZOWY JEST FORMALNY */
    if (blank_1.trbas == blank_1.tlbas) {
	return 0;
    }
    goto L9000;

/* ...... PRZYPADEK  TLDIM > TRDIM */
/* 	POPRAWNE GDY  TRBAS  JEST FORMALNY, UNIWERSALNY LUB NONE - */
/* 	DALSZE UWAGI JAK PRZY  TLDIM < TRDIM */
L4000:
    if (tpr == 4 || tpr == 14) {
	return 0;
    }
    if (tpr != 6) {
	goto L9000;
    }
    goto L8500;


/* ------ USTALENIE RODZAJU ZGODNOSCI TYPOW REFERENCYJNYCH, GDY CO */
/* 	NAJMNIEJ JEDEN Z NICH JEST TYPEM FORMALNYM */

L8000:
    *case__ = 6;
    mtpc_1.prfxr = blank_1.objr;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) <= 0) {
	goto L8200;
    } else {
	goto L8100;
    }
/* 	    MTPCON PRZYJMUJE NASTEPUJACE WARTOSCI */
/* 	      -1 - TYP TEN SAM Z ROZNYCH OBIEKTOW */
/* 	       0 - TYPY ROZNE */
/* 	      +1 - TYP TEN SAM Z TEGO SAMEGO OBIEKTU */

L8100:
    *case__ = 5;
L8200:
    return 0;

/* ...... UZTALENIE ZGODNOSCI TYPOW TABLICOWYCH - JEDEN Z NICH */
/* 	JEST FORMALNY */

L8500:
    *case__ = 6;
    mtpc_1.prfxr = blank_1.objr;
    mtpc_1.prfxl = blank_1.objl;
    if (mtpcon_(&z__) != 1) {
	return 0;
    }
/* 	      WPP - SYGNALIZACJA BLEDOW - NIE MA PODSTAWIENIA UNIFIKU- */
/* 		    JACEGO */



/* ------ SYGNALIZOWANIE BLEDOW */
L9000:
    *case__ = 5;
    if (tpr == 9) {
	goto L9100;
    }
    if (blank_1.trdim == 0 && blank_1.trbas == blank_1.nrtext) {
	merr_(&c__608, &blank_1.idr);
    }
    merr_(&c__606, &blank_1.idl);
    return 0;
/* --- SYGNALIZACJA BLEDOW - NIEDOZWOLONE UZYCIE SEMAFORA */
L9100:
    *case__ = 5;
    if (tpl == 9) {
	merr_(&c__636, &blank_1.idl);
    }
    if (tpr == 9) {
	merr_(&c__636, &blank_1.idr);
    }
    return 0;
} /* mequal_ */

#undef staler
#undef stack


/* DECK MPKIND */
integer mpkind_(integer *attrad)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer zw;
#define stack ((integer *)&blank_1 + 302)
    extern logical mnopf_(integer *);
#define staler ((real *)&blank_1 + 302)

/* -------------FUNKCJA OKRESLAJACA RODZAJ KOLEJNEGO PARAMETRU */
/* 	      FORMALNEGO */
/* 	      / WARTOSCIA PARAMETRU ATTRAD JEST IDENTYFIKATOR */
/* 		(INDEKS W IPMEM) OPISU TEGO PARAMETRU */
/* 	      / ZMIENNA  NRPAR (Z BLOKU /SEMANT/) MA WARTOSC ROWNA */
/* 		NUMEROWI PARAMETRU WEWNATRZ LISTY PARAMETROW FORMAL- */
/* 		NYCH (0,1,2,...) */
/* 	      / WARTOSC FUNKCJI OKRESLA RODZAJ PARAMETRU FORMALNEGO */
/* 		 0 - UNIWERSALNY */
/* 		 1 - INPUT */
/* 		 2 - OUTPUT */
/* 		 3 - TYP */
/* 		 4 - FUNKCJA */
/* 		 5 - PROCEDURA */
/* 	      // FUNKCJA KORZYSTA Z PROCEDURY  MNOPF */
/* 	  SYGNALIZOWANY BLAD */
/* 	      622 (Z MNOPF) - ZA KROTKA LISTA PF */

/* 	      OPIS W DOKUMENTACJI:	     ?3.4.3.2 */
/* 	      WERSJA Z DNIA:		     19.01.82 */
/* 	      DLUGOSC KODU:	    141 */
/* ............................................................................. */

/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */


    ret_val = 0;
    *attrad = blank_1.nruniv;
    if (mnopf_(&c__0)) {
	return ret_val;
    }

/* ***************************************************************************** */
/* 	PARAMETR ZOSTAL POBRANY */
    *attrad = blank_1.ipmem[mcalls_1.cllrec + 4];
    *attrad = blank_1.ipmem[*attrad - 1];
    blank_1.nrpar = blank_1.ipmem[mcalls_1.cllrec + 3];
/* ------ ROZPOZNANIE BIEZACEGO PARAMETRU */
/* 	  ZW - SLOWO ZEROWE OPISU PARAMETRU */
    zw = blank_1.ipmem[*attrad - 1];
    zw = (lbit_shift(zw, (ftnlen)-4) & 15) + 1;
    switch (zw) {
	case 1:  goto L1000;
	case 2:  goto L100;
	case 3:  goto L200;
	case 4:  goto L300;
	case 5:  goto L1000;
	case 6:  goto L400;
	case 7:  goto L500;
	case 8:  goto L1000;
	case 9:  goto L1000;
	case 10:  goto L600;
    }

/* ...... TYP FORMALNY */
L100:
    ret_val = 3;
    goto L1000;

/* ...... FUNKCJA */
L200:
    ret_val = 4;
    goto L1000;

/* ...... PROCEDURA */
L300:
    ret_val = 5;
    goto L1000;

/* ...... INPUT */
L400:
    ret_val = 1;
    goto L1000;

/* ...... OUTPUT */
L500:
    ret_val = 2;
    goto L1000;

/* .....INOUT */
L600:
    ret_val = 6;

/* ***************************************************************************** */
/* ------ ZAKONCZENIE */
L1000:
    blank_1.ipmem[mcalls_1.cllrec + 6] = ret_val;
    return ret_val;
} /* mpkind_ */

#undef staler
#undef stack


/* DECK MPARTP */
/* Subroutine */ int mpartp_(integer *atdim, integer *atbase, integer *ob, 
	integer *idbase)
{
    /* Local variables */
    static integer k, pf;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    extern integer mgetm_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* -------------PRZETWARZANIE PARAMETRU AKTUALNEGO BEDACEGO TYPEM */
/* 	      DO REKORDU KONTROLI WPISUJE SIE INFORMACJE O TYPIE */
/* 	      AKTUALNYM ZASTEPUJACYM TYP-PARAMETR FORMALNY. */
/* 	      ATDIM, ATBASE - LICZBA ARRAY OF I TYP BAZOWY AKTUALNY */
/* 	      OB - NUMER OBIEKTU Z CIAGU SL, Z KTOREGO JEST POBIERANY */
/* 		 LUB ZERO, GDY NIE JEST DOSTEPNY PRZEZ DISPLAY */
/* 	      IDBASE - NAZWA ZE SCANNERA TYPU BAZOWEGO (DO SYGNALIZACJI */
/* 		   BLEDOW) */

/* 	  SYGNALIZOWANE BLEDY */
/* 	      624 - TYP AKTUALNY NIE JEST REFERENCYJNY */
/* 	      625 - ATBASE NIE JEST TYPEM */
/* 	    637 - 'SEMAPHORE' NIE MOZE BYC TYPEM AKTUALNYM */

/* 	      /PROCEDURA TWORZY NOWA CZWORKE TYPOW DO MODYFIKACJI */

/* 	      OPIS W DOKUMENTACJI:	       ?3.5 */
/* 	      WERSJA Z DNIA:		       19.01.82 */
/* 	      DLUGOSC KODU:	    207 */
/* ............................................................................. */

/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */


/* ...... POWROTY DLA WYWOLANIA NIEKONTROLOWANEGO */
    if (mcalls_1.unicll) {
	return 0;
    }
    if (blank_1.ipmem[mcalls_1.cllrec + 6] == 0) {
	return 0;
    }

/* ------UTWORZENIE NOWEJ CZWORKI W REKORDZIE KONTROLI */
    blank_1.insys = TRUE_;
    k = mgetm_(&c__4, &c__0);
    blank_1.insys = FALSE_;
/* ...... ZAPIS NUMERU TYPU FORMALNEGO */
    pf = blank_1.ipmem[mcalls_1.cllrec + 4];
    blank_1.ipmem[k - 1] = blank_1.ipmem[pf - 1];
/* ...... ZAPIS INFORMACJI O TYPIE AKTUALNYM */
    blank_1.ipmem[k] = *atdim;
    blank_1.ipmem[k + 1] = *atbase;
    blank_1.ipmem[k + 2] = *ob;
/* ...... KONTROLA, CZY TYP AKTUALNY JEST DOPUSZCZALNY */
/* L100: */
    pf = blank_1.ipmem[*atbase - 1];
    pf &= 15;
/* 	   PF - POLE  T  Z OPISU TYPU ATBASE */
    if (pf == 1) {
	goto L200;
    }
/* 	  ... ATBASE NIE JEST TYPEM */
    if (pf == 9) {
	goto L210;
    }
    if (*atdim != 0) {
	return 0;
    }
/* 	  ---TYPY TABLICOWE SA REFERENCYJNE */
    if (pf <= 7) {
	return 0;
    }
/* 	  ---POWROT DLA POZOSTALYCH TYPOW REFERENCYJNYCH */

/* ------SYGNALIZACJA BLEDU - TYP AKTUALNY NIE JEST REFERENCYJNY */
    merr_(&c__624, idbase);
    blank_1.ipmem[k + 1] = blank_1.nruniv;
    return 0;
/* ------SYGNALIZACJA BLEDU- PARAMETR ATBASE NIE JEST TYPEM */
L200:
    merr_(&c__625, idbase);
L205:
    blank_1.ipmem[k] = 0;
    blank_1.ipmem[k + 1] = blank_1.nruniv;
    return 0;
/* -----PARAMETREM JEST TYP 'SEMAPHORE' - BLAD */
L210:
    merr_(&c__637, &c__0);
    goto L205;
} /* mpartp_ */

#undef staler
#undef stack


/* DECK MREPTP */
/* Subroutine */ int mreptp_(integer *tdim, integer *tbas, integer *ob)
{
    /* Local variables */
    static integer k, l;
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* -------------PROCEDURA MODYFIKUJE TYP (TDIM, TBAS) PRZEZ */
/* 	      ZASTAPIENIE EWENTUALNEGO TYPU FORMALNEGO TYPEM AKTUALNYM */
/* 	      JEMU ODPOWIADAJACYM. */
/* 	      TDIM, TBAS - OKRESLA ROWNIEZ TYP PO MODYFIKACJI */
/* 	      DANE DOTYCZACE DOSTEPNOSCI : OB */
/* 	      /PROCEDURA UZYWANA JEDYNIE, GDY WYWOLANIE JEST KONTROLO- */
/* 	      WANE */

/* 	      OPIS W DOKUMENTACJI:	    ?3.6.1 */
/* 	      WERSJA Z DNIA:		    19.01.82 */
/* 	      DLUGOSC KODU:	   112 */
/* ............................................................................. */

/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */

/* 	      K - INDEKS PIERWSZEJ PIATKI TYPOW ZASTEPOWANYCH */
/* 	      L - INDEKS OSTATNIEJ PIATKI TYPOW ZASTEPOWANYCH */
    l = blank_1.lpml - 4;
    k = mcalls_1.cllrec + 8;
/* ...... SPRAWDZENIE, CZY LISTA TYPOW NIE JEST PUSTA */
    if (k > l) {
	return 0;
    }
/* ------ SZUKANIE W NIEPUSTEJ LISCIE */

L10:
    if (blank_1.ipmem[k - 1] == *tbas) {
	goto L20;
    }
/* 	  ---SKOK, GDY TYP JEST ODNALEZIONY */
    if (k == l) {
	return 0;
    }
/* 	  ---POWROT, GDY TYP NIE WYSTEPUJE W LISCIE */
    k += 4;
    goto L10;

/* ------ TYP ODNALEZIONY */
L20:
    *tdim += blank_1.ipmem[k];
    *tbas = blank_1.ipmem[k + 1];
    *ob = blank_1.ipmem[k + 2];
    return 0;
} /* mreptp_ */

#undef staler
#undef stack


/* DECK MCALLO */
/* Subroutine */ int mcallo_(integer *nrprot, integer *idprot, integer *ob, 
	integer *kind)
{
    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer zp;
#define stack ((integer *)&blank_1 + 302)
    extern integer mgetm_(integer *, integer *);
    static integer record;
#define staler ((real *)&blank_1 + 302)

/* -------------PROCEDURA OTWIERA REKORD KONTROLI STATYCZNEJ NOWEGO */
/* 	      WYWOLANIA (WKLADAJAC NA STOS), INICJUJE TEN REKORD */
/* 	      PARAMETRY WEJSCIOWE */
/* 		NRPROT - NUMER WYWOLYWANEGO PROTOTYPU */
/* 		IDPROT - NAZWA ZE SCANNERA WYWOLYWANEGO PROTOTYPU */
/* 		OB - NUMER OBIEKTU Z CIAGU  SL, Z KTOREGO WYWOLYWANY */
/* 		      PROTOTYP POCHODZI */
/* 	      PARAMETR WYJSCIOWY */
/* 		KIND - WARTOSCI */
/* 		       = 0  ZWYKLY PROTOTYP */
/* 		       = 1  WIRTUALNY */
/* 		       = 2  FORMALNY */

/* 	      OPIS W DOKUMENTACJI:	   ?3.4.2 */
/* 	      WERSJA Z DNIA:		   19.01.82 */
/* 	      DLUGOSC KODU:	   262 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */
/* CALL MID */

/* ------ UTWORZENIE REKORDU DLA WYWOLANIA UNIWERSALNEGO */
    *kind = 0;
    mcalls_1.unicll = TRUE_;
    ++mid_1.checks;
    blank_1.insys = TRUE_;
    record = mgetm_(&c__2, &c__0);
    blank_1.ipmem[record - 1] = mcalls_1.cllrec;
    mcalls_1.cllrec = record + 1;
    blank_1.insys = FALSE_;
    if (*nrprot == blank_1.nruniv) {
	return 0;
    }
/* ------ UTWORZENIE REKORDU DLA WYWOLANIA KONTROLOWANEGO */
    blank_1.insys = TRUE_;
    mcalls_1.unicll = FALSE_;
    record = mgetm_(&c__7, &c__0);
    blank_1.insys = FALSE_;
/* ...... INICJALIZACJA SLOW REKORDU */
/* 	RECORD - ZEROWE SLOWO WYWOLYWANEGO REKORDU */
    record = blank_1.ipmem[*nrprot - 1];
    blank_1.ipmem[mcalls_1.cllrec - 1] = *nrprot;
    blank_1.ipmem[mcalls_1.cllrec] = *idprot;
/* ...... ZBADANIE, CZY TO JEST PROTOTYP WIRTUALNY */
    *kind = 1;
    if (bit_test(record,11)) {
	goto L100;
    }
/* ...... ZBADANIE, CZY TO PROTOTYP FORMALNY */
/* 	  (PRZY POMOCY POLA  ZP) */
    *kind = 0;
    zp = lbit_shift(record, (ftnlen)-4) & 15;
    if (zp != 0) {
	*kind = 2;
    }
/*  --- ZBADANIE, CZY TO NIE JEST SYGNAL */
    if (zp == 11) {
	*kind = 0;
    }
L100:
    blank_1.ipmem[mcalls_1.cllrec + 1] = *kind;
/* ...... INICJALIZACJA DALSZYCH SLOW */
    blank_1.ipmem[mcalls_1.cllrec + 2] = *ob;
/* ...... WYPELNIENIE INFORMACJI O LISCIE PARAMETROW */
    blank_1.ipmem[mcalls_1.cllrec + 3] = -1;
    blank_1.ipmem[mcalls_1.cllrec + 4] = blank_1.ipmem[*nrprot + 2] - 1;
    blank_1.ipmem[mcalls_1.cllrec + 5] = blank_1.ipmem[mcalls_1.cllrec + 4] + 
	    blank_1.ipmem[*nrprot + 3];
/* ...... SKROCENIE LISTY PF DLA FUNKCJI - OSTATNI ELEMENT JEST */
/* 	ZMIENNA RESULT */
    record = lbit_shift(record, (ftnlen)-8) & 7;
    if (record == 2) {
	--blank_1.ipmem[mcalls_1.cllrec + 5];
    }
    return 0;
} /* mcallo_ */

#undef staler
#undef stack


/* DECK MCALLC */
/* Subroutine */ int mcallc_(void)
{
    /* Local variables */
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* -------------ZAKONCZENIE KONTROLI WYWOLANIA, ZBADANIE */
/* 	      ZGODNOSCI LICZBY PARAMETROW FORMALNYCH I PARAME- */
/* 	      TROW AKTUALNYCH */
/* 	      ZDJECIE REKORDU KONTROLI ZE STOSU */
/* 	  SYGNALIZOWANY BLAD */
/* 	      623 - LISTA PF JEST DLUZSZA OD LISTY PARAMETROW */
/* 		     AKTUALNYCH */

/* 	      OPIS W DOKUMENTACJI:	  ?3.4.4.2 */
/* 	      WERSJA Z DNIA:		  19.01.82 */
/* 	      DLUGOSC KODU:	   89 */
/* ............................................................................. */



/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */
/* CALL MID */


    --mid_1.checks;
    if (mcalls_1.unicll) {
	goto L1000;
    }

/* ****** KONTROLA DLUGOSCI LIST PF I PA */
    if (blank_1.ipmem[mcalls_1.cllrec + 4] == blank_1.ipmem[mcalls_1.cllrec + 
	    5]) {
	goto L1000;
    }
/* 	  --- SYGNALIZACJA BLEDU */
    merr_(&c__623, &blank_1.ipmem[mcalls_1.cllrec]);

/* ****** ZDJECIE REKORDU ZE SZCZYTU STOSU */
L1000:
    blank_1.lpml = mcalls_1.cllrec - 1;
    mcalls_1.cllrec = blank_1.ipmem[mcalls_1.cllrec - 2];
    mcalls_1.unicll = FALSE_;
    if (blank_1.ipmem[mcalls_1.cllrec - 1] == 0) {
	mcalls_1.unicll = TRUE_;
    }
    return 0;
} /* mcallc_ */

#undef staler
#undef stack


/* DECK MNOPF */
logical mnopf_(integer *x)
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer zw;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    extern /* Subroutine */ int municl_(void);
#define staler ((real *)&blank_1 + 302)

/* -------------FUNKCJA SLUZY DO POBRANIA NOWEGO PARAMETRU */
/* 	      KONTROLUJE, CZY JEST TO MOZLIWE */
/* 	      //PRZYJMUJE WARTOSC .TRUE. GDY LISTA PF JEST PUSTA, */
/* 		SYGNALIZUJE WOWCZAS (O ILE WYWOLYWANY PROTOTYP NIE */
/* 		MIAL USZKODZONEJ LISTY) BLAD */
/* 		ZMIENIA WYWOLANIE NA NIEKONTROLOWANE */
/* 	      //GDY LISTA PF NIE JEST PUSTA */
/* 		AKTUALIZUJE SLOWA  5 I 6  W REKORDZIE KONTROLI */
/* 	      //// X - PARAMETR NIEISTOTNY */
/* 	  SYGNALIZOWANY BLAD */
/* 	      622 - LISTA PF KROTSZA OD LISTY PARAMETROW AKTUALNYCH */

/* 	      OPIS W DOKUMENTACJI:	     ?3.4.3.1 */
/* 	      WERSJA Z DNIA:		     19.01.82 */
/* 	      DLUGOSC KODU:	   168 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */

    ret_val = TRUE_;
    if (mcalls_1.unicll) {
	return ret_val;
    }
    ret_val = FALSE_;

/* ****** MODYFIKACJA NUMEROW PARAMETRU FORMALNEGO I ELEMENTU LISTY */
    ++blank_1.ipmem[mcalls_1.cllrec + 3];
    ++blank_1.ipmem[mcalls_1.cllrec + 4];
/* ------ KONTROLA DLUGOSCI LISTY PF I PA */
    if (blank_1.ipmem[mcalls_1.cllrec + 4] <= blank_1.ipmem[mcalls_1.cllrec + 
	    5]) {
	return ret_val;
    }

/* ****** PRZYPADEK, GDY NIE MA JUZ POTRZEBNEGO PF */
/* 	  -SYGNALIZACJA BLEDU, GDY WYWOLYWANY PROTOTYP NIE JEST */
/* 	      USZKODZONY */
/* 	  -SKROCENIE REKORDU KONTROLI STATYCZNEJ DO WYWOLANIA UNIWERSAL- */
/* 	      NEGO */

    ret_val = TRUE_;

/* 	ZW - SLOWO ZEROWE PROTOTYPU */
    zw = blank_1.ipmem[mcalls_1.cllrec - 1];
    zw = blank_1.ipmem[zw - 1];
/* 	  ---SKOK DLA USZKODZONEJ LISTY */
    if (bit_test(zw,13)) {
	goto L100;
    }

/* ------ SYGNALIZACJA BLEDU */
    merr_(&c__622, &blank_1.ipmem[mcalls_1.cllrec]);
/* ------ SKROCENIE REKORDU KONTROLI */
L100:
    municl_();
    return ret_val;
} /* mnopf_ */

#undef staler
#undef stack


/* DECK MUNICL */
/* Subroutine */ int municl_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* -------------PROCEDURA ZASTEPUJACA WYWOLANIE KONTROLOWANE */
/* 	      WYWOLANIEM OBIEKTU UNIWERSALNEGO */
/* 	      / JEST WYKONYWANA, GDY W WYWOLANIU BYLY BLEDY UNIE- */
/* 	      MOZLIWIAJACE DALSZA POPRAWNA ANALIZE */

/* 	      OPIS W DOKUMENTACJI:	   ?3.4.4.1 */
/* 	      WERSJA Z DNIA:		   19.01.82 */
/* 	      DLUGOSC KODU:	   31 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL STCON */
/* ...... */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK STCON FROM LOGLAN.14  !! */

    blank_1.lpml = mcalls_1.cllrec + 1;
    mcalls_1.unicll = TRUE_;
    blank_1.ipmem[mcalls_1.cllrec - 1] = 0;
    return 0;
} /* municl_ */

#undef staler
#undef stack


/* DECK MTPCON */
integer mtpcon_(integer *x)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    static integer slobl, obtpl, slobr, obtpr;
    extern /* Subroutine */ int mobjfd_(void);
#define staler ((real *)&blank_1 + 302)

/* 		     X - "SLEPY" PARAMETR */
/* -------------POMOCNICZA FUNKCJA DO KONTROLI TYPOW FORMALNYCH. */
/* 	       OKRESLA, CZY TYPY  TRBAS  I  TLBAS  ATRYBUTOW POCHODZACYCH */
/* 	       Z OBIEKTOW/WARSTW  PRFXR I PRFXL (DOSTEPNYCH PRZEZ DISPLAY */
/* 	       ODPOWIEDNIO TE WARTOSCI SA WIEKSZE OD ZERA) SA TYM SAMYM */
/* 	       TYPEM FORMALNYM. */
/* 	      /WARTOSCI : */
/* 		-1 - TYP TEN SAM, Z ROZNYCH OBIEKTOW */
/* 		 0 - TYPY ROZNE */
/* 		+1 - TYP TEN SAM Z TEGO SAMEGO OBIEKTU */

/* 	      OPIS W DOKUMENTACJI:	 ?2.2.3 */
/* 	      WERSJA Z DNIA:		 19.01.82 */
/* 	      DLUGOSC KODU:	   362 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL MTPC */
/* ......BLOK KOMUNIKACJI Z PROCEDURA  MTPCON */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MTPC FROM LOGLAN.14  !! */
/*     *CALL MOB */
/* ......KOMUNIKACJA Z PROCEDURA	MOBJFD */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MOB FROM LOGLAN.14	!! */

/* ******************************************* */
/*     WARUNKI DOSTATECZNE NA TO BY TYP POCHODZIL Z TEGO */
/*     SAMEGO OBIEKTU: */
/* 	- OBYDWA ATRYBUTY SA DOSTEPNE PRZEZ DISPLAY */
/*     ORAZ JEDEN Z PONIZSZYCH */
/* 	(A) POCHODZA Z TEJ SAMEJ WARSTWY (TEN SAM NUMER */
/* 	    W DISPLAY-U) */
/* 	(B) OBIEKTY W CIAGU SL DLA PROTOTYPU AKTUALNEGO, */
/* 	    Z KTORYCH POCHODZA TYPY, SA ROWNE DLA OBYDWU */
/* 	    ATRYBUTOW ORAZ W LANCUCHU SL OD PROTOTYPU */
/* 	    AKTUALNEGO DO TEGO OBIEKTU NIE WYSTEPUJA ZADNE */
/* 	    KLASY (NATOMIAST SAME OBIEKTY MOGA BYC KLASAMI) */
/* 	(C) WYSTARCZY, BY ATRYBUTY BYLY WLASNE W OBIEKTACH */
/* 	    W CIAGU SL DLA PROTOTYPU AKTUALNEGO ORAZ POMIEDZY */
/* 	    TYMI OBIEKTAMI NIE WYSTEPUJA ZADNE KLASY ( ORAZ */
/* 	    OBIEKT Z TYPEM JEST TEN SAM) */
/* 	(D) ATRYBUTY SA LOKALNE W PROTOTYPIE AKTUALNYM */
/* 	(E) TYP NIE JEST ATRYBUTEM KLASY */
/* ******************************************** */

    ret_val = 0;
    if (blank_1.trbas != blank_1.tlbas) {
	return ret_val;
    }
    ret_val = -1;
    if (mtpc_1.prfxr <= 0 || mtpc_1.prfxl <= 0) {
	return ret_val;
    }
/* ******************************************** */
/* 	  BADANIE WARUNKOW  (A) - (E) */
    ret_val = 1;
    if (mtpc_1.prfxr == mtpc_1.prfxl) {
	return ret_val;
    }
/* 	  --POWROT DLA PRZYPADKU (A) */
    slobr = blank_1.ipmem[blank_1.trbas - 2];
    if (blank_1.ipmem[slobr - 1] > 15) {
	return ret_val;
    }
/* 	  --POWROT DLA PRZYPADKU (E) */
/* ......ODNALEZIENIE W LANCUCHU SL DLA PROTOTYPU AKTUALNEGO */
/* 	P  OBIEKTOW "PREFIKSOWANYCH" PRZEZ PROTOTYPY  PRFXL I */
/* 	PRFXR */
    mob_1.stob = blank_1.p;
    mob_1.prfx1 = mtpc_1.prfxr;
    mob_1.prfx2 = mtpc_1.prfxl;
    mobjfd_();
    slobr = mob_1.slob1;
    slobl = mob_1.slob2;
/* 	  SLOB - OBIEKTY W LANCUCHU SL */
/* 	  WCL1 = .TRUE. GDY POMIEDZY P A DRUGIM Z TYCH OBIEKTOW */
/* 	  WYSTEPUJE KLASA */
/* 	  WCL2 = .TRUE. GDY POMIEDZY TYMI OBIEKTAMI WYSTEPUJE */
/* 	  KLASA */
    if (slobr == blank_1.p && slobl == blank_1.p) {
	return ret_val;
    }
/* 	  --POWROT DLA PRZYPADKU (D) */

    ret_val = -1;
    if (mob_1.wcl2) {
	return ret_val;
    }
/* 	  --POMIEDZY OBIEKTAMI WYSTAPILA KLASA */

/* ......TESTOWANIE PRZYPADKU (C) */
    if (mtpc_1.prfxr != slobr || mtpc_1.prfxl != slobl) {
	goto L100;
    }
    mob_1.stob = slobr;
    mob_1.prfx1 = blank_1.ipmem[blank_1.trbas - 2];
    mob_1.prfx2 = 0;
    mobjfd_();
    obtpr = mob_1.slob1;

    mob_1.stob = slobl;
    mob_1.prfx1 = blank_1.ipmem[blank_1.tlbas - 2];
    mob_1.prfx2 = 0;
    mobjfd_();
    obtpl = mob_1.slob1;
    if (obtpr != obtpl) {
	return ret_val;
    }
    ret_val = 1;
    return ret_val;
/* ......TESTOWANIE PRZYPADKU (B) */
/* 	  ODSZUKANIE OBIEKTOW, Z KTORYCH BRANY JEST TYP, GDY */
/* 	  OTOCZENIAMI SA SLOB */
L100:
    if (mob_1.wcl1) {
	return ret_val;
    }
    if ((blank_1.ipmem[blank_1.p - 1] & 15) != 1) {
	return ret_val;
    }
/* 	BY TYP NA PEWNO POCHODZIL Z TEGO SAMEGO OBIEKTU - P NIE MOZE BYC */
/* 	KLASA */
    mob_1.stob = slobr;
    mob_1.prfx1 = blank_1.ipmem[blank_1.trbas - 2];
    mob_1.prfx2 = 0;
    mobjfd_();
    obtpr = mob_1.slob1;
    if (mob_1.wcl1 && slobr != obtpr) {
	return ret_val;
    }
    mob_1.stob = slobl;
    mob_1.prfx1 = blank_1.ipmem[blank_1.tlbas - 2];
    mob_1.prfx2 = 0;
    mobjfd_();
    obtpl = mob_1.slob1;
    if (mob_1.wcl1 && slobl != obtpl) {
	return ret_val;
    }
    if (obtpl != obtpr) {
	return ret_val;
    }
/* 	  --TYP BRANY Z ROZNYCH OBIEKTOW */
    ret_val = 1;
    return ret_val;
} /* mtpcon_ */

#undef staler
#undef stack


/* DECK MDISTP */
logical mdistp_(integer *vsl, integer *nrprot, integer *nrdis)
{
    /* Initialized data */

    static integer mdishx = 4095;

    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer tob;
    static logical wcl;
    static integer vob;
    static logical vwcl;
    static integer tpsl;
    extern logical bpref_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    static integer tobpr;
    extern /* Subroutine */ int mobjfd_(void);
#define staler ((real *)&blank_1 + 302)

/* -------------FUNKCJA SPRAWDZA, CZY TYP FORMALNY OBIEKTU DOSTEPNEGO */
/* 	      PRZEZ DISPLAY Z PROTOTYPU AKTUALNEGO JEST ROWNIEZ */
/* 	      DOSTEPNY PRZEZ DISPLAY */
/* 	      VSL - NUMER PROTOTYPU Z DEKLARACJA OBIEKTU */
/* 	      NRPROT - NUMER PROTOTYPU TYPU FORMALNEGO */
/* 	      /WYNIKI : NRDIS IDENTYFIKATOR PROTOTYPU, KTOREGO */
/* 	      NUMER W DISPLAY-U TWORZY ADRES NRPROT */
/* 	      /WARTOSCI */
/* 	       - .TRUE. - TYP ZAWSZE DOSTEPNY PRZEZ DISPLAY */
/* 	       - .FALSE. - TYP NIE JEST LUB NIE ZAWSZE JEST DOSTEPNY */
/* 		 PRZEZ DISPLAY */

/* 	      OPIS W DOKUMENTACJI:	  ?1.4.4 */
/* 	      WERSJA Z DNIA:		  19.01.82 */
/* 	      DLUGOSC KODU:	  314 */
/* ............................................................................. */


/* dsw  DATA MDISTPHX /Z0FFF/ */

/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL MOB */
/* ......KOMUNIKACJA Z PROCEDURA	MOBJFD */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MOB FROM LOGLAN.14	!! */

/* dsw  --------------------- */
/* dsw  ----------------------- */
    tpsl = blank_1.ipmem[(1208 + (0 + (*nrprot - 1 - 1 << 2)) - 1208) / 4];
    *nrdis = tpsl;
/* 	   WARSTWA, Z KTOREJ POCHODZI TYP NRPROT */
    ret_val = TRUE_;
    if (*vsl == tpsl) {
	return ret_val;
    }
    if ((blank_1.ipmem[tpsl - 1] & mdishx) > 15) {
	return ret_val;
    }
/* 	 OBYDWIE WIELKOSCI POCHODZA Z TEJ SAMEJ WARSTWY LUB TYP NIE */
/* 	 JEST ATRYBUTEM KLASY */
    ret_val = FALSE_;
/* ......ZNALEZIENIE W LANCUCHU SL PROTOTYPU AKTUALNEGO */
/*     OBIEKTU Z WARSTWA VSL */
    mob_1.stob = blank_1.p;
    mob_1.prfx1 = *vsl;
    mob_1.prfx2 = 0;
    mobjfd_();
    vob = mob_1.slob1;
    vwcl = mob_1.wcl2;
/* ......ZNALEZIENIE W LANCUCHU SL PROTOTYPU AKTUALNEGO */
/*     OBIEKTU Z WARSTWA TPSL */
    mob_1.stob = blank_1.p;
    mob_1.prfx1 = tpsl;
    mobjfd_();
    tob = mob_1.slob1;
    wcl = mob_1.wcl2;
    if (tob == vob) {
	goto L100;
    }
    if (vwcl) {
	return ret_val;
    }
    if (wcl) {
	return ret_val;
    }
/* ......ZNALEZIENIE W LANCUCHU SL PROTOTYPU VOB OBIEKTU */
/*     Z WARSTWA  TPSL */
    mob_1.stob = vob;
    mob_1.prfx1 = tpsl;
    mobjfd_();
    tobpr = mob_1.slob1;
    wcl = mob_1.wcl2;
    if (tob != tobpr) {
	goto L300;
    }
    if (! wcl) {
	goto L200;
    }
    *nrdis = vob;
    if (vob != tob) {
	return ret_val;
    }
    ret_val = TRUE_;
    return ret_val;
L100:
    ret_val = TRUE_;
    *nrdis = *vsl;
    return ret_val;
L200:
    *nrdis = tobpr;
    ret_val = TRUE_;
    return ret_val;
L300:
    if ((blank_1.ipmem[vob - 1] & 15) != 1) {
	return ret_val;
    }
    if (wcl) {
	return ret_val;
    }
    if ((blank_1.ipmem[blank_1.p - 1] & 15) != 1) {
	return ret_val;
    }
    if ((blank_1.ipmem[tobpr - 1] & 15) == 1) {
	goto L200;
    }
    if (bpref_(&tob, &blank_1.ipmem[tobpr - 7])) {
	return ret_val;
    }
    goto L200;
/* 	JESLI P I VOB NIE SA KLASAMI ORAZ TOB NIE JEST ROWN TOBPR A TALZE */
/* 	POMIEDZY VOB A TOBPR NIE MA KLAS - TYP JEST WIDOCZNY PRZEZ DISPLAY */
/* 	DODATKOWY WARUNEK: TOB NIE MOZE BYC PREFIKSOWANE PRZEZ TOBPR */
} /* mdistp_ */

#undef staler
#undef stack


/* DECK MOBJFD */
/* Subroutine */ int mobjfd_(void)
{
    /* Initialized data */

    static integer mobjhx = 4095;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static logical nocl1, nocl2;
    static integer prfn1, prfn2, actob;
    extern logical bpref_(integer *, integer *);
    static logical wclpr;
    static integer zword;

/* 	       POMOCNICZA PROCEDURA PRZY KONTROLI TYPOW. */
/* 	       WYSZUKUJE W LANCUCHU  SL  OBIEKTU  STOB	OBIEKTY */
/* 	       "PREFIKSOWANE" (LUB ROWNE) PRZEZ PRFX1 I PRFX2 */
/* 	       (JESLI PRFX2=0 TO TYLKO PRFX1) */
/* 	       SLOB1 - OBIEKT ZAWIERAJACY WARSTWE  PRFX1 */
/* 	       SLOB2 - OBIEKT ZAWIERAJACY WARSTWE  PRFX2 */
/* 	       WCL1 = .TRUE. JESLI POMIEDZY STOB A TYMI OBIEKTAMI */
/* 		    WYSTEPUJE KLASA */
/* 	       WCL2 = .TRUE. JESLI POMIEDZY TYMI OBIEKTAMI WYSTE- */
/* 		    PUJE KLASA */

/* 	      OPIS W DOKUMENTACJI:	  ?1.4.3 */
/* 	      WERSJA Z DNIA:		  19.01.82 */
/* 	      DLUGOSC KODU:	   548 */
/* ............................................................................. */

/* dsw  DATA MOBJFDHX /Z0FFF/ */
/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */
/*     *CALL MOB */
/* ......KOMUNIKACJA Z PROCEDURA	MOBJFD */

/*     !!!!!! END OF SUBSTITUTION OF COMDECK MOB FROM LOGLAN.14	!! */

/* dsw  ------------------- */
/* dsw  --------------------- */
/* ......INICJALIZACJA */
    actob = mob_1.stob;
/* 	  -OBIEKT AKTUALNY W LANCUCHU SL */
    mob_1.wcl1 = FALSE_;
    mob_1.wcl2 = FALSE_;
    wclpr = FALSE_;
/* ......SPRAWDZENIE, CZY PRFX SA KLASAMI JESLI TAK TO POBRANIE */
/* 	  ICH NUMEROW W SENSIE ZBIOROW PREFIKSOW */
    nocl1 = TRUE_;
    nocl2 = TRUE_;
    zword = blank_2.ipmem[mob_1.prfx1 - 1] & 15;
    if (zword >= 15 || zword == 1) {
	goto L100;
    }
    nocl1 = FALSE_;
    prfn1 = blank_2.ipmem[mob_1.prfx1 - 7];
/* 	  --PRFN1 - NUMER W SENSIE PREFXSET */

L100:
    if (mob_1.prfx2 == 0) {
	goto L3000;
    }
/* 	  --SKOK DO WYSZUKIWANIA PROTOTYPU Z WARSTWA  PRFX1 */


    if (blank_2.ipmem[mob_1.prfx2 - 1] >= 15 || blank_2.ipmem[mob_1.prfx2 - 1]
	     == 1) {
	goto L200;
    }
    nocl2 = FALSE_;
    prfn2 = blank_2.ipmem[mob_1.prfx2 - 7];

L200:
    if (mob_1.prfx1 == mob_1.prfx2) {
	goto L3100;
    }

/* ************WYSZUKIWANIE BLIZSZEGO OBIEKTU */
L1000:
    if (actob == mob_1.prfx1) {
	goto L2000;
    }
    if (actob == mob_1.prfx2) {
	goto L3000;
    }
    if (blank_2.ipmem[actob - 1] == 1) {
	goto L1600;
    }
    if ((lbit_shift(blank_2.ipmem[actob - 1], (ftnlen)-8) & 7) == 7) {
	goto L1600;
    }
/* 	  --OMINIECIE BLOKU ZWYKLEGO I HANDLERA */
    if (nocl1) {
	goto L1100;
    }
    if (bpref_(&actob, &prfn1)) {
	goto L2000;
    }
L1100:
    if (nocl2) {
	goto L1500;
    }
    if (bpref_(&actob, &prfn2)) {
	goto L3000;
    }
/* ......POBRANIE KOLEJNEGO OBIEKTU Z LANCUCHA SL (PRZY */
/* 	  JEDNOCZESNYM SPRAWDZENIU, CZY NIE JEST TO KLASA) */
L1500:
    if (actob == mob_1.stob) {
	goto L1600;
    }
    if ((blank_2.ipmem[actob - 1] & mobjhx) <= 15) {
	mob_1.wcl1 = TRUE_;
    }
L1600:
    actob = blank_2.ipmem[actob - 2];
    goto L1000;


/* ******WYSZUKIWANIE DRUGIEGO OBIEKTU, W PRZYPADKU GDY */
/* 	  PIERWSZYM JEST ODPOWIADAJACY	PRFX1 */
L2000:
    mob_1.slob1 = actob;
    if (blank_2.ipmem[actob - 1] <= 15 && blank_2.ipmem[actob - 1] != 1) {
	wclpr = TRUE_;
    }
/* 	  ***BADANIE KOLEJNYCH OBIEKTOW */
L2100:
    if (actob == mob_1.prfx2) {
	goto L2500;
    }
    if (blank_2.ipmem[actob - 1] == 1) {
	goto L2300;
    }
    if ((lbit_shift(blank_2.ipmem[actob - 1], (ftnlen)-8) & 7) == 7) {
	goto L2300;
    }
    if (nocl2) {
	goto L2200;
    }
    if (bpref_(&actob, &prfn2)) {
	goto L2500;
    }
L2200:
    if (actob == mob_1.slob1) {
	goto L2300;
    }
    if ((blank_2.ipmem[actob - 1] & mobjhx) <= 15) {
	mob_1.wcl2 = TRUE_;
    }
L2300:
    actob = blank_2.ipmem[actob - 2];
    goto L2100;


/* 	  ***OBIEKT DRUGI ODNALEZIONY */
L2500:
    mob_1.slob2 = actob;
    if (mob_1.slob1 == mob_1.slob2) {
	return 0;
    }
    mob_1.wcl1 = mob_1.wcl1 || mob_1.wcl2 || wclpr;
    return 0;


/* ******WYSZUKIWANIE DRUGIEGO OBIEKTU W PRZYPADKU, GDY PIERWSZYM */
/* 	  JEST ODPOWIADAJACY PRFX2 (ROWNIEZ, GDY SZUKAMY JEDNEGO */
/* 	  OBIEKTU) */
L3000:
    mob_1.slob2 = actob;
    zword = blank_2.ipmem[actob - 1] & mobjhx;
    if (zword <= 15 && zword != 1) {
	wclpr = TRUE_;
    }
/* 	  ***BADANIE KOLEJNYCH OBIEKTOW W CIAGU SL */
L3100:
    if (actob == mob_1.prfx1) {
	goto L3500;
    }
    if (blank_2.ipmem[actob - 1] == 1) {
	goto L3300;
    }
    if (nocl1) {
	goto L3200;
    }
    if (bpref_(&actob, &prfn1)) {
	goto L3500;
    }
L3200:
    if (actob == mob_1.slob2) {
	goto L3300;
    }
    if ((blank_2.ipmem[actob - 1] & mobjhx) <= 15) {
	mob_1.wcl2 = TRUE_;
    }
L3300:
    actob = blank_2.ipmem[actob - 2];
    goto L3100;


/* 	  ***ODNALEZIONY DRUGI OBIEKT */
L3500:
    mob_1.slob1 = actob;
    if (mob_1.prfx1 != mob_1.prfx2) {
	goto L3600;
    }
    mob_1.wcl2 = FALSE_;
    mob_1.slob2 = actob;
L3600:
    if (mob_1.slob1 == mob_1.slob2) {
	return 0;
    }
/* 	    GDY OBA PREFIKSY PREFIKSUJA PIERWSZA NAPOTKANA */
/* 	    KLASE TO NIE TRAKTUJEMY JEJ JAKO KLASY (TZN. */
/* 	    WCL1 I WCL2 SA .FALSE. */
    mob_1.wcl1 = mob_1.wcl1 || mob_1.wcl2 || wclpr;
    return 0;
} /* mobjfd_ */

/* DECK MARITH */
/* Subroutine */ int marith_(integer *op)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer tl, tr;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* -------------PROCEDURA BADA POPRAWNOSC ARGUMENTOW OPERACJI ARYTME- */
/* 	      TYCZNYCH. */
/* 	      TYPY LEWEGO I PRAWEGO ARGUMENTU DANE SA W BLOKU /SEMANT/ */
/* 	      PRZEZ ZMIENNE  TLDIM, TLBAS ORAZ	TRDIM,TRBAS . */
/* 	      ZMIENNE  IDL I IDR  (W /SEMANT/) SA IDENTYFIKATORAMI LEWE- */
/* 	      GO I PRAWEGO ARGUMENTU (DO SYGNALIZACJI BLEDOW). */
/* 	      PARAMETR	OP  OKRESLA RODZAJ OPERACJI: */
/* 		OP = 1 - DLA  +,-,* ORAZ RELACJI <,>,<=,>= */
/* 		OP = 2 - DLA  DIV  I  MOD */
/* 		OP = 3 - DLA  /  (WYNIK ZAWSZE REAL) */
/* 	      NA ZMIENNA TRESLT  W  /SEMANT/  PODSTAWIANY JEST TYP */
/* 	      WYNIKU OPERACJI . */
/* 	      PROCEDURA PRZEKAZUJE INFORMACJE O KONWERSJI LEWEGO (CONVL) */
/* 	      I PRAWEGO (CONVR) ARGUMENTU. WARTOSCI TYCH ZMIENNYCH */
/* 	      OZNACZAJA : */
/* 		0 - BEZ KONWERSJI */
/* 		1 - INTEGER DO REAL */
/* 	  ----SYGNALIZOWANE BLEDY : */
/* 	      604 - TYP ARGUMENTU OPERACJI LUB RELACJI NIE JEST ARYTME- */
/* 		    TYCZNY, */
/* 	      605 - TYP ARGUMENTU  DIV	LUB  MOD  NIE JEST INTEGER */

/* 	      OPIS W DOKUMENTACJI:	   ?2.4 */
/* 	      WERSJA Z DNIA:		   19.01.82 */
/* 	      DLUGOSC KODU:	   295 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */


/* ------ KONTROLA TYPU LEWEGO ARGUMENTU */
    tl = blank_1.tlbas;
    if (blank_1.tldim != 0) {
	goto L100;
    }
/* 	  SKOK - GDY JEST TO TYP TABLICOWY */
    if (blank_1.tlbas == blank_1.nrint || blank_1.tlbas == blank_1.nrre || 
	    blank_1.tlbas == blank_1.nruniv) {
	goto L200;
    }

/* ...... TYP LEWEJ STRONY NIE JEST ARYTMETYCZNY */
L100:
    tl = blank_1.nruniv;
    merr_(&c__604, &blank_1.idl);

/* ------KONTROLA TYPU PRAWEJ STRONY */
L200:
    tr = blank_1.trbas;
    if (blank_1.trdim != 0) {
	goto L300;
    }
    if (blank_1.trbas == blank_1.nrint || blank_1.trbas == blank_1.nrre || 
	    blank_1.trbas == blank_1.nruniv) {
	goto L400;
    }

/* ......TYP PRAWEJ STRONY NIE JEST ARYTMETYCZNY */
L300:
    tr = blank_1.nruniv;
    merr_(&c__604, &blank_1.idr);


/* ------ SPRAWDZENIE ZALEZNE OD RODZAJU OPERACJI, USTALENIE KONWERSJI */
L400:
    if ((i__1 = *op - 2) < 0) {
	goto L500;
    } else if (i__1 == 0) {
	goto L600;
    } else {
	goto L700;
    }

/* ..... OP = 1 - OPERACJE  +,-,*  ORAZ RELACJE */
L500:
    blank_1.treslt = blank_1.nrre;
/* 	  TYP REAL JEST SILNIEJSZY OD INTEGER. PRZYJMUJE WIEC, ZE JEST */
/* 	  TO TYP WYNIKU. */
    if (tl == tr) {
	blank_1.treslt = tl;
    }
    if (tr == blank_1.nruniv || tl == blank_1.nruniv) {
	blank_1.treslt = blank_1.nruniv;
    }
/* 	  TYP WYNIKU JEST JUZ USTALONY */
/* 	  PODANIE INFORMACJI O KONWERSJI */
    blank_1.convl = 0;
    if (tl != blank_1.treslt) {
	blank_1.convl = 1;
    }
    blank_1.convr = 0;
    if (tr != blank_1.treslt) {
	blank_1.convr = 1;
    }
    return 0;

/* ..... OP = 2 - OPERACJE  DIV  I  MOD */
L600:
    blank_1.treslt = blank_1.nrint;
    blank_1.convl = 0;
    blank_1.convr = 0;
/* 	SPRAWDZENIE, CZY TYPY ARGUMENTOW NIE SA REAL */
    if (tl == blank_1.nrre) {
	merr_(&c__605, &blank_1.idl);
    }
    if (tr == blank_1.nrre) {
	merr_(&c__605, &blank_1.idr);
    }
    return 0;

/* ...... OP = 3 - OPERACJA  / */
/* 	  WYNIK MUSI BYC TYPU REAL, ARGUMENTY PODLEGAJA EWENTUALNEJ */
/* 	  KONWERSJI */
L700:
    blank_1.treslt = blank_1.nrre;
    blank_1.convl = 0;
    blank_1.convr = 0;
    if (tl == blank_1.nrint) {
	blank_1.convl = 1;
    }
    if (tr == blank_1.nrint) {
	blank_1.convr = 1;
    }
    return 0;
} /* marith_ */

#undef staler
#undef stack


/* DECK MLOCTP */
logical mloctp_(integer *tp, integer *prot)
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer sltp;
    extern logical bpref_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* -------------FUNKCJA SPRAWDZA, CZY TYP TP JEST LOKALNYM ATRYBUTEM */
/* 	      PROTOTYPU  PROT */

/* 	      OPIS W DOKUMENTACJI:	  ?1.4.2 */
/* 	      WERSJA Z DNIA:		  19.01.82 */
/* 	      DLUGOSC KODU:	    107 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
    ret_val = TRUE_;

    sltp = blank_1.ipmem[*tp - 2];
/* 	SLTP - MIEJSCE DEKLARACJI  TP */
    if (sltp == *prot) {
	return ret_val;
    }
    ret_val = FALSE_;
    if ((blank_1.ipmem[sltp - 1] & 15) == 1) {
	return ret_val;
    }
/* 	  POWROT Z WARTOSCIA .FALSE. O ILE SLTP NIE MOZE PREFIKSOWAC */
/* 	  PROTOTYPU  PROT */
    if (blank_1.ipmem[*prot - 1] == 1) {
	return ret_val;
    }
    if ((lbit_shift(blank_1.ipmem[*prot - 1], (ftnlen)-8) & 7) == 7) {
	return ret_val;
    }
/* 	--HANDLER */
    if (bpref_(prot, &blank_1.ipmem[sltp - 7])) {
	ret_val = TRUE_;
    }
    return ret_val;
} /* mloctp_ */

#undef staler
#undef stack


/* DECK MAQUAB */
integer maquab_(integer *idb)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer igt;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    extern integer mident_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer mprfsq_(integer *, integer *);

/* -------------FUNKCJA BADA POPRAWNOSC KONSTRUKCJI   QUA IDB . */
/* 	      TLDIM I TLBAS OKRESLAJA TYP WYRAZENIA PRZED QUA. IDL JEST */
/* 	      NAZWA TEGO WYRAZENIA UZYWANA PRZY SYGNALIZACJI BLEDOW. */
/* 	      IDB JEST NAZWA ZE SCANNERA WYSTEPUJACA PO  QUA . */
/* 	      // WARTOSCIA FUNKCJI JEST PROTOTYP ODPOWIADAJACY	IDB */
/* 	      LUB  NRUNIV  W PRZYPADKU BLEDOW. */
/* 	      NAZWA  IDB  JEST WYSZUKIWANA W OTOCZENIU PROTOTYPU */
/* 	      AKTUALNEGO (P  Z BLOKU /SEMANT/). */
/* 	  ----SYGNALIZOWANE BLEDY */
/* 	      600 (Z PROCEDURY	MIDENT) - NIEDOSTEPNY IDENTYFIKATOR IDB */
/* 		     PODOBNIE  619 I 620 */
/* 	      615 - TYP PRZED QUA NIE JEST KLASA UOGOLNIONA ANI TYPEM */
/* 		    FORMALNYM */
/* 	      616 - IDENTYFIKATOR PO QUA NIE JEST TYPEM */
/* 	      617 - IDENTYFIKATOR PO QUA NIE JEST TYPEM KLASOWYM */
/* 	      618 - TYP PO QUA NIE JEST W SEKWENCJI PREFIKSOWEJ Z TLBAS */


/* 	      OPIS W DOKUMENTACJI:	  ?1.5.2 */
/* 	      WERSJA Z DNIA:		  19.01.82 */
/* 	      DLUGOSC KODU:	  238 */
/* ............................................................................. */

/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */

/*     ODSZUKIWANIE IDENTYFIKATORA */
    ret_val = mident_(idb);

/* ......SPRAWDZENIE, CZY  IDB  JEST TYPEM KLASOWYM */
    igt = blank_1.ipmem[ret_val - 1] & 15;
    switch (igt) {
	case 1:  goto L1000;
	case 2:  goto L100;
	case 3:  goto L100;
	case 4:  goto L2000;
	case 5:  goto L100;
	case 6:  goto L200;
	case 7:  goto L100;
	case 8:  goto L200;
	case 9:  goto L200;
	case 10:  goto L200;
	case 11:  goto L200;
	case 12:  goto L200;
	case 13:  goto L200;
	case 14:  goto L200;
    }

/*     ...IDB JEST KLASA LUB TYPEM SYSTEMOWYM - GDY TO TYP SYSTEMOWY */
/* 	  TO BLAD */
L100:
    if (ret_val != blank_1.nrcor && ret_val != blank_1.nrproc) {
	goto L2000;
    }
/* 	SKOK - GDY JEST TO ZWYKLY TYP KLASOWY */

/*     ...IDB NIE JEST TYPEM KLASOWYM */
L200:
    merr_(&c__617, idb);
    ret_val = blank_1.nruniv;
    goto L2000;

/*     ...IDB NIE JEST TYPEM */
L1000:
    merr_(&c__616, idb);
    ret_val = blank_1.nruniv;

/* ......BADANIE TYPU PRZED  QUA */
L2000:
    if (blank_1.tldim != 0) {
	goto L3000;
    }
/* 	SKOK - GDY PRZED QUA TYP TABLICOWY */
    igt = blank_1.ipmem[blank_1.tlbas - 1] & 15;
    switch (igt) {
	case 1:  goto L3000;
	case 2:  goto L2100;
	case 3:  goto L2100;
	case 4:  goto L4000;
	case 5:  goto L2100;
	case 6:  goto L2200;
	case 7:  goto L2100;
	case 8:  goto L3000;
	case 9:  goto L3000;
	case 10:  goto L3000;
	case 11:  goto L3000;
	case 12:  goto L3000;
	case 13:  goto L3000;
	case 14:  goto L3000;
    }

/*     ...PRZED QUA TYP KLASOWY LUB SYSTEMOWY */
L2100:
    if (ret_val == blank_1.nruniv) {
	return ret_val;
    }
    if (blank_1.tlbas == blank_1.nrcor || blank_1.tlbas == blank_1.nrproc) {
	return ret_val;
    }
    if (mprfsq_(&blank_1.tlbas, &ret_val) >= 0) {
	return ret_val;
    }
/* 	      TU - GDY SEKWENCJE PREFIKSOWE TYPOW KLASOWYCH SA ROZLACZNE */
    merr_(&c__618, idb);
    ret_val = blank_1.nruniv;
    return ret_val;

/*     ...TYP PRZED QUA JEST FORMALNY */
L2200:
    return ret_val;

/*     ...TYP PRZED  QUA NIE JEST ODPOWIEDNI */
L3000:
    merr_(&c__615, &blank_1.idl);
    ret_val = blank_1.nruniv;
L4000:
    return ret_val;
} /* maquab_ */

#undef staler
#undef stack


/* DECK MTHIS */
integer mthis_(integer *id)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer igt;
    extern /* Subroutine */ int merr_(integer *, integer *);
    static integer prot;
    extern logical bpref_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    static integer nrprf, zword;
    extern integer mident_(integer *);
#define staler ((real *)&blank_1 + 302)

/* -------------FUNKCJA BADA POPRAWNOSC KONSTRUKCJI  THIS ID, GDZIE */
/* 	      ID  JEST NAZWA ZE SCANNERA. KONSTRUKCJA WYSTEPUJE W MODU- */
/* 	      LE O PROTOTYPIE AKTUALNYM  P (Z BLOKU /SEMANT/). */
/* 	      // WARTOSCIA FUNKCJI JEST  PROTOTYP  ID */
/* 	      W PRZYPADKU BLEDU - WARTOSCIA JEST PROTOTYP UNIWERSALNY. */
/* 	  ----SYGNALIZOWANE BLEDY */
/* 	      600 (Z PROCEDURY MIDENT) - NIEDOSTEPNY IDENTYFIKATOR  ID */
/* 		PODOBNIE  619 I 620 */
/* 	      612 - ID NIE WYSTEPUJE W SEKWENCJI PREFIKSOWEJ ZADNEGO */
/* 		    MODULU OBEJMUJACEGO  P */
/* 	      613 - ID	NIE JEST NAZWA	KLASY UOGOLNIONEJ */
/* 	      614 - ID NIE JEST NAZWA TYPU */

/* 	      OPIS W DOKUMENTACJI:	    ?1.5.1 */
/* 	      WERSJA Z DNIA:		    19.01.82 */
/* 	      DLUGOSC KODU:	   182 */
/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */


    ret_val = mident_(id);
    if (ret_val == blank_1.nruniv) {
	return ret_val;
    }

    igt = blank_1.ipmem[ret_val - 1] & 15;
    switch (igt) {
	case 1:  goto L9000;
	case 2:  goto L100;
	case 3:  goto L100;
	case 4:  goto L9000;
	case 5:  goto L100;
	case 6:  goto L8000;
	case 7:  goto L100;
	case 8:  goto L8000;
	case 9:  goto L8000;
	case 10:  goto L8000;
	case 11:  goto L8000;
	case 12:  goto L8000;
	case 13:  goto L8000;
	case 14:  goto L8000;
    }

/* -----PRZYPADEK, GDY  ID  JEST NAZWA TYPU KLASOWEGO LUB SYSTEMOWEGO */
/* 	      PRZEJSCIE PO SL-ACH W POSZUKIWANIU MODULU PREFIKSOWANEGO */
/* 	      PRZEZ  ID */
/* 	      PROT - PROTOTYP BADANY */
L100:
    prot = blank_1.p;
    nrprf = blank_1.ipmem[ret_val - 7];
/* 	  NRPRF - NUMER PROTOTYPU W SENSIE ZBIORU PREFIKSOW */
L200:
    zword = blank_1.ipmem[prot - 1];
/* 	  ZWORD - SLOWO ZEROWE PROTOTYPU  PROT - DO KONTROLI, CZY NIE */
/* 	  JEST TO BLOK ZWYKLY, W POZOSTALYCH PRZYPADKACH BADAMY WARUNEK */
/* 	  PREFIKSOWANIA */
    if (zword == 1) {
	goto L250;
    }
/* 	      SKOK - OMIJA BLOK ZWYKLY */
    if ((lbit_shift(zword, (ftnlen)-8) & 7) == 7) {
	goto L250;
    }
/* 	    SKOK - OMIJA PROTOTYP HANDLERA */
    if (bpref_(&prot, &nrprf)) {
	return ret_val;
    }
/* 	  POWROT JESLI PROT JEST PREFIKSOWANY PRZEZ  ID */
L250:
    prot = blank_1.ipmem[prot - 2];
    if (prot != blank_1.nblsys) {
	goto L200;
    }
/* 	  ITEROWANIE - GDY NIE DOSZLISMY DO BLOKU SYSTEMOWEGO */
/* .....ID NIE WYSTAPILO W SEKWENCJI PREFIKSOWEJ */
    merr_(&c__612, id);
    ret_val = blank_1.nruniv;
    return ret_val;
/* .....ID WYSTAPILO JAKO PREFIKS PROTOTYPU  PROT */

/* -----ID NIE JEST NAZWA KLASY UOGOLNIONEJ */
L8000:
    merr_(&c__613, id);
    ret_val = blank_1.nruniv;
    return ret_val;


/* -----ID NIE JEST TYPEM */
L9000:
    merr_(&c__614, id);
    ret_val = blank_1.nruniv;
    return ret_val;
} /* mthis_ */

#undef staler
#undef stack


/* DECK MDOT */
integer mdot_(integer *tdim, integer *tbas, integer *ida, integer *id)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer tp, nre, prid;
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    extern integer memprf_(integer *);
    extern logical minscp_(integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer insert_(integer *, integer *, integer *);

/* -------------FUNKCJA BADAJACA POPRAWNOSC WYRAZENIA KROPKOWANEGO */
/* 	      TDIM, TBAS - TYP WYRAZENIA PRZED KROPKA, */
/* 	      IDA - IDENTYFIKATOR WYRAZENIA PRZED KROPKA (DO SYGNALIZA- */
/* 		    CJI BLEDOW), */
/* 	      ID - NAZWA ZE SCANNERA IDENTYFIKATORA PO KROPCE. */
/* 		JESLI ATRYBUT JEST DOSTEPNY - WARTOSCIA  MDOT  JEST JEGO */
/* 	      OPIS. */
/* 		JESLI ATRYBUT JEST NIEDOSTEPNY (NIEZADEKLAROWANY LUB */
/* 	      "CLOSE") - WARTOSCIA (PO ZASYGNALIZOWANIU BLEDU) JEST */
/* 	      ATRYBUT UNIWERSALNY. JESLI ATRYBUT BYL NIEZADEKLAROWANY */
/* 	      - JEST ON WPROWADZANY. */
/* 	  ----SYGNALIZOWANE BLEDY */
/* 	      601 - BLEDNY TYP PRZED KROPKA (PRYMITYWNY, FORMALNY, */
/* 		    SYSTEMOWY LUB TABLICOWY), */
/* 	      602 - IDENTYFIKATOR PO KROPCE JEST "CLOSE", HIDDEN LUB NIE JEST */
/* 		   TAKEN, */
/* 	      603 - IDENTYFIKATOR PO KROPCE NIE JEST ZADEKLAROWANY, */
/* 	      611 - PO KROPCE WYSTEPUJE IDENTYFIKATOR STALEJ "CONST". */
/* 	      621 - PO KROPCE WYSTEPUJE IDENTYFIKATOR HIDDEN LUB SPOZA */
/* 		   LISTY  TAKEN */

/* 	      OPIS W DOKUMENTACJI:	    ?1.6.1 */
/* 	      WERSJA Z DNIA:		   19.01.82 */
/* 	      DLUGOSC KODU:	  382 */
/* ............................................................................. */

/* 	FUNKCJA POMOCNICZA DO BADANIA, CZY JESTESMY W ZASIEGU DEKLARACJI */

/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/*     *CALL MEM */
/* ..... */
/*     KOMUNIKACJA Z PROCEDURA MEMPRF */
/*     !!!!!! END OF SUBSTITUTION OF COMDECK MEM FROM LOGLAN.14 !! */


    if (*tdim != 0) {
	goto L1000;
    }

/* ------ TU TYPY NIETABLICOWE */
    tp = blank_1.ipmem[*tbas - 1] & 15;
/* 	  TP - POLE T Z OPISU TYPU TBAS */

    switch (tp) {
	case 1:  goto L1000;
	case 2:  goto L100;
	case 3:  goto L100;
	case 4:  goto L500;
	case 5:  goto L400;
	case 6:  goto L1000;
	case 7:  goto L400;
	case 8:  goto L1000;
	case 9:  goto L1000;
	case 10:  goto L1000;
	case 11:  goto L1000;
	case 12:  goto L1000;
	case 13:  goto L1000;
	case 14:  goto L1000;
	case 15:  goto L1000;
    }

/* ------ TYPY POSIADAJACE ATRYBUTY (TZN. TYPY KLASOWE) */
L100:
    mem_1.nm = *id;
    mem_1.nh = (lbit_shift(mem_1.nm, (ftnlen)-1) & 7) + 1;
    ret_val = memprf_(tbas);
    if (ret_val != 0) {
	goto L200;
    }
/* ------ TU - IDENTYFIKATOR NIEZADEKLAROWANY */
    merr_(&c__603, id);
    ret_val = insert_(id, &blank_1.ipmem[*tbas + 9], &c__0);
    ret_val = blank_1.nruniv;
    return ret_val;
/* ------ TU - GDY IDENTYFIKATOR WYSTEPUJE (LUB BYL DODEKLAROWANY) */
L200:
    if (blank_1.ipmem[ret_val] == 0) {
	goto L220;
    }
/* 	SKOK - IDENTYFIKATOR JEST DOSTEPNY I NIE JEST CHRONIONY */
    if (blank_1.ipmem[ret_val] == 1) {
	goto L300;
    }
/* 	  SKOK - JESLI IDENTYFIKATOR JEST "CLOSE" */
    if (blank_1.ipmem[ret_val] == 4) {
	goto L250;
    }
/* 	SKOK - JESLI IDENTYFIKATOR JEST 'NOT TAKEN' */
/* 	---TU IDENTYFIKATOR JEST 'HIDDEN' */
    if (! blank_1.own) {
	goto L250;
    }
/*     ---TERAZ NALEZY SPRAWDZIC, CZY IDENTYFIKATOR NIE BYL 'CLOSE' JUZ */
/* 	 W PREFIKSIE */
    if (blank_1.ipmem[*tbas + 18] == 0) {
	goto L210;
    }
/*     ---TBAS JEST NIEPREFIKSOWANY */
    i__1 = *tbas + 19;
    prid = memprf_(&i__1);
    if (prid == 0) {
	goto L210;
    }
    if (blank_1.ipmem[prid + 1] != blank_1.ipmem[ret_val + 1]) {
	goto L210;
    }
/*     ---IDENTYFIKATOR NIE BYL DEKLAROWANY W PREFIKSIE */
    if (blank_1.ipmem[prid] == 1) {
	goto L250;
    }
/*     ---SKOK - IDENTYFIKATOR BYL 'CLOSE' JUZ W PREFIKSIE */
/* ---SPRAWDZENIE, CZY JESTESMY W ZASIEGU DEKLARACJI MODULU CHRONIACEGO ATRYBUT */
L210:
    if (! minscp_(tbas)) {
	goto L250;
    }
L220:
    ret_val = blank_1.ipmem[ret_val + 1];
    return ret_val;

/* ------ TU IDENTYFIKATORY "HIDDEN" LUB "NOT TAKEN" */
L250:
    merr_(&c__621, id);
    if (! blank_1.own) {
	nre = insert_(id, &blank_1.ipmem[*tbas + 9], &c__0);
    }
    if (blank_1.own && blank_1.ipmem[ret_val] < 4) {
	goto L255;
    }
    blank_1.ipmem[ret_val] = 0;
    blank_1.ipmem[ret_val + 1] = blank_1.nruniv;
L255:
    ret_val = blank_1.nruniv;
    return ret_val;


/* ------ TU IDENTYFIKATORY "CLOSE" LUB STALE "CONST" */
L300:
    nre = 602;
    mem_1.nm = blank_1.ipmem[ret_val + 1];
    if (mem_1.nm == blank_1.nruniv) {
	goto L350;
    }
/* 	--BADANIE, CZY TO STALA 'CONST' */
    mem_1.nm = lbit_shift(blank_1.ipmem[mem_1.nm - 1], (ftnlen)-4);
    mem_1.nm &= 15;
    if (mem_1.nm != 8) {
	goto L350;
    }
    nre = 611;
    goto L360;
L350:
    if (! blank_1.own) {
	goto L360;
    }
    if (minscp_(tbas)) {
	goto L220;
    }
L360:
    merr_(&nre, id);
    if (! blank_1.own) {
	nre = insert_(id, &blank_1.ipmem[*tbas + 9], &c__0);
    }
    ret_val = blank_1.nruniv;
    return ret_val;

/* ------OBIEKTY COROUTINE LUB PROCESS */
L400:
    if (*tbas != blank_1.nrcor && *tbas != blank_1.nrproc) {
	goto L100;
    }

/* ------NIEPOPRAWNY TYP PRZED KROPKA */
L1000:
    merr_(&c__601, ida);
/* ------ TYP PRZED KROPKA JEST UNIWERSALNY */
L500:
    ret_val = blank_1.nruniv;
    return ret_val;
} /* mdot_ */

#undef staler
#undef stack


/* DECK MINSCP */
logical minscp_(integer *t)
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer pr;
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* -----------------FUNKCJA BADA,CZY PROTOTYP AKTUALNY JEST WEWENATRZ */
/* 		  DEKLARACJI MODULU T, TZN. CZY T LEZY W LANCUCHU SL */
/* 		  PROTOTYPU P */

/* .................................................................... */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */

    ret_val = TRUE_;
    pr = blank_1.p;
L100:
    if (pr == *t) {
	return ret_val;
    }
    if (pr == blank_1.nblsys) {
	goto L200;
    }
    pr = blank_1.ipmem[pr - 2];
    goto L100;
L200:
    ret_val = FALSE_;
    return ret_val;
} /* minscp_ */

#undef staler
#undef stack


/* DECK MPROTO */
/* Subroutine */ int mproto_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
    extern integer mgetm_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)

/* ---------------------------------PROCEDURA POMOCNICZA - OTWIERA POMOCNICZA */
/* 			  STRUKTURE DANYCH PRZY WEJSCIU DO INSTRUKCJI NOWEGO */
/* 			  PROTOTYPU */

/* ............................................................................ */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/* CALL MID */


    mid_1.checks = 0;
    blank_1.insys = TRUE_;
    mid_1.pstart = mgetm_(&c__8, &c__0);
    blank_1.insys = FALSE_;
    return 0;
} /* mproto_ */

#undef staler
#undef stack


/* DECK MPROTC */
/* Subroutine */ int mprotc_(void)
{
    /* Local variables */
#define stack ((integer *)&blank_1 + 302)
#define staler ((real *)&blank_1 + 302)

/* ---------------------------------PROCEDURA POMOCNICZA - ZAMYKA POMOCNICZA */
/* 			  STRUKTURE DANYCH PRZY WYJSCIU Z PROTOTYPU */

/* ........................................................................ */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/* CALL MID */


    blank_1.lpml = mid_1.pstart;
    return 0;
} /* mprotc_ */

#undef staler
#undef stack


/* DECK MIDENT */
integer mident_(integer *id)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer nh;
    extern integer midb_(integer *);
    static integer nadr;
#define stack ((integer *)&blank_1 + 302)
    extern integer mgetm_(integer *, integer *), member_(integer *, integer *)
	    ;
#define staler ((real *)&blank_1 + 302)

/* -------------------------------FUNKCJA WYSZUKUJE W PROTOTYPIE AKTUALNYM P */
/* 			  I JEGO OTOTCZENIU NAZWE ID (HASH ZE SCANNERA). */
/* 			  WYSZUKIWANIE ODBYWA SIE NAJPIERW W STRUKTURZE */
/* 			  POMOCNICZEJ */

/* ............................................................................. */


/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */
/* CALL MID */


/* *****SZUKANIE NAZWY W LOKALNEJ STRUKTURZE DANYCH */
    ret_val = member_(id, &blank_1.ipmem[mid_1.pstart - 1]);
    if (ret_val == 0) {
	goto L100;
    }
/*     ----NAZWA ODNALEZIONA - NA PEWNO JEST POPRAWNA, NIE TRZEBA SYGNALIZOWAC */
/* 	  ZADNYCH BLEDOW */
/* 	  NALEZY JEDYNIE USTAWIC ZMIENNE INFORMUJACE O DOSTEPIE */
    blank_1.object = blank_1.ipmem[ret_val];
    blank_1.local = blank_1.ipmem[ret_val + 3];
    ret_val = blank_1.ipmem[ret_val + 1];
    blank_1.own = blank_1.local < 0;
    if (blank_1.own) {
	blank_1.local = -blank_1.local - 1;
    }
    return ret_val;
/*     ----NAZWA NIE ZOSTALA ODNALEZIONA - SZUKANIE PRZY POMOCY MIDB */
L100:
    ret_val = midb_(id);
/*     ----JESLI MOZEMY WSTAWIAC DO LISTY POMOCNICZEJ, TO WSTAWIAMY, WPP POWROT */
    if (blank_1.lpml + 5 > blank_1.lpmf) {
	++mid_1.checks;
    }
    if (mid_1.checks > 0) {
	goto L200;
    }
    blank_1.insys = TRUE_;
    nadr = mgetm_(&c__5, &c__0);
    blank_1.insys = FALSE_;
    ret_val = blank_1.ipmem[ret_val + 1];
    blank_1.ipmem[nadr - 1] = *id;
    blank_1.ipmem[nadr] = blank_1.object;
    blank_1.ipmem[nadr + 1] = ret_val;
    blank_1.ipmem[nadr + 3] = blank_1.local;
    if (blank_1.own) {
	blank_1.ipmem[nadr + 3] = -(blank_1.local + 1);
    }
    nh = (lbit_shift(*id, (ftnlen)-1) & 7) + mid_1.pstart;
    blank_1.ipmem[nadr + 2] = blank_1.ipmem[nh - 1];
    blank_1.ipmem[nh - 1] = nadr;
    return ret_val;
L200:
    ret_val = blank_1.ipmem[ret_val + 1];
    return ret_val;
} /* mident_ */

#undef staler
#undef stack


/* DECK MIDB */
integer midb_(integer *id)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    extern /* Subroutine */ int merr_(integer *, integer *);
#define stack ((integer *)&blank_1 + 302)
    extern integer memsl_(integer *, integer *);
#define staler ((real *)&blank_1 + 302)
    extern integer insert_(integer *, integer *, integer *);

/* -------------FUNKCJA WYSZUKUJE W PROTOTYPIE AKTUALNYM	P  ( /SEMANT/) */
/* 	      I JEGO OTOCZENIU NAZWE  ID  (HASH ZE SCANNERA). */
/* 	      (.) JESLI NAZWA TA JEST DOSTEPNA, TO : */
/* 		  -NADAJE ZMIENNEJ  LOCAL  WARTOSC */
/* 		    WYSTAPIENIA IDENTYFIKATORA), */
/* 		  -WARTOSCIA FUNKCJI JEST INDEKS OPISU TEGO IDENTYFIKA- */
/* 		    TORA . */
/* 	      (.) JESLI NAZWA NIE JEST DOSTEPNA LUB JEST NIEZADEKLAROWA- */
/* 		   NA - DODEKLAROWUJE JA, SYGNALIZUJE BLAD I NADAJE WAR- */
/* 		   TOSC ATRYBUTU UNIWERSALNEGO. */
/* 	  ----SYGNALIZOWANE BLEDY: */
/* 	      600 - NIEZADEKLAROWANY (LUB NIEDOSTEPNY) IDENTYFIKATOR */
/* 	      619 - UZYCIE IDENTYFIKATORA  HIDDEN */
/* 	      620 - UZYCIE IDENTYFIKATORA SPOZA LISTY  TAKEN */


/* 	      OPIS W DOKUMENTACJI:	   ?1.4.1 */
/* 	      WERSJA Z DNIA:		   19.01.82 */
/* 	      DLUGOSC KODU:	  155 */
/* ............................................................................. */

/*     *CALL BLANKSEM */
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


/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANKSEM FROM LOGLAN.14 !! */


    ret_val = memsl_(id, &blank_1.p);
/* 	  MEMSL MA WARTOSC ZERO, JESLI NAZWA NIE ZOSTALA ODNALEZIONA */
/* 	  LUB JEST INDEKSEM W LISCIE HASH-U. */
/* 	  OWN MA WARTOSC .TRUE. - GDY IDENTYFIKATOR ZOSTAL ZNALEZIONY */
/* 	 BEZPOREDNIOW PROTOTYPIE (A NIE JEGO PREFIKSIE) - MOZE BYC */
/* 	 WTEDY HIDDEN . */
    if (ret_val == 0) {
	goto L1000;
    }
/* ------TU PRZYPADEK NAZWY ODNALEZIONEJ */
/* ...... SPRAWDZENIE DOSTEPNOSCI IDENTYFIKATORA */
    if (blank_1.ipmem[ret_val] >= 4) {
	goto L1200;
    }
/* 		IDENTYFIKATOR NIE JEST NA LISCIE TAKEN */
    if (blank_1.ipmem[ret_val] >= 2 && ! blank_1.own) {
	goto L1300;
    }
/* 	     IDENTYFIKATOR JEST  HIDDEN  W KTORYMS Z PREFIKSOW */
    return ret_val;

/* ------TU PRZYPADEK NAZWY NIEODNALEZIONEJ */
L1000:
    merr_(&c__600, id);
/* 	 DODEKLAROWANIE NAZWY - ELEMENTU LISTY HASH-U */
L1100:
    ret_val = insert_(id, &blank_1.ipmem[blank_1.p + 9], &c__0);
    blank_1.local = 2;
    return ret_val;

/* ...... SYGNALIZACJE BLEDOW DLA NIEDOSTEPNYCH ATRYBUTOW */
L1200:
    merr_(&c__620, id);
    if (! blank_1.own) {
	goto L1100;
    }
    blank_1.ipmem[ret_val] = 0;
    blank_1.ipmem[ret_val + 1] = blank_1.nruniv;
    return ret_val;
L1300:
    merr_(&c__619, id);
    goto L1100;

} /* midb_ */

#undef staler
#undef stack


/* NEWDECK MEMSL */
integer memsl_(integer *name__, integer *idprot)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer isl;
    extern integer memprf_(integer *);

/* -------------WYSZUKUJE NAZWE  NAME  W PROTOTYPIE IDENTYFIKOWANYM PRZEZ */
/* 	      IDPROT  ORAZ JEGO OTOCZENIU (PO SL-ACH). WARTOSCIA JEST */
/* 	      ELEMENT LISTY HASH-U Z TA NAZWA  LUB  0 - GDY TEJ NAZWY */
/* 	      NIE BYLO. */
/* 	      / JESLI NAZWA WYSTAPILA BEZPOSREDNIO W  IDPROT  LUB JEGO */
/* 		PREFIKSACH - WARTOSCIA */
/* 	      ZMIENNEJ	LOCAL  Z BLOKU // JEST 2, WPP 0 LUB 1 */
/* 	      / PO ODNALEZIENIU NAZWY ELEMENT PRZESUWANY NA POCZATEK */
/* 	      LISTY HASH-U. */
/* 	       / OWN MA WARTOSC .TRUE. JESLI NAZWA ODNALEZIONA JEST */
/* 		 BEZPOSREDNIO W PROTOTYPIE A NIE W PREFIKSIE. */
/* 		 TO ZNACZY TAM WYSTEPUJE W LISCIE - DO KONTROLI PROTEKCJI. */
/* 	     /OBJECT - PROTOTYP OBIEKTU, W KTORYM ODNALEZIONO ATRYBUT O */
/* 		       NAZWIE NAME */

/* 	      OPIS W DOKUMENTACJI:	 B.III.2.4 */
/* 	      WERSJA Z DNIA:		 19.01.82 (MJL) */
/* 	      DLUGOSC KODU:	  117 */
/* ....................................................................... */


/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */
/*     *CALL MEM */
/* ..... */
/*     KOMUNIKACJA Z PROCEDURA MEMPRF */
/*     !!!!!! END OF SUBSTITUTION OF COMDECK MEM FROM LOGLAN.14 !! */

    mem_1.nm = *name__;
    mem_1.nh = (lbit_shift(*name__, (ftnlen)-1) & 7) + 1;
/* 	 NH - WARTOSC FUNKCJI HASZUJACEJ DLA SZUKANEJ NAZWY */

    blank_2.local = 2;
    isl = *idprot;
/* 	 ISL - IDENTYFIKATOR KOLEJNYCH PROTOTYPOW */

/* ***** */

/*      WYSZUKUJEMY W PREFIKSACH PROTOTYPU  ISL */
L10:
    ret_val = memprf_(&isl);
    if (ret_val != 0) {
	goto L20;
    }
/* 		POWROT, GDY NAZWA JUZ ODNALEZIONA */

/* ..... NAZWA NIEODNALEZIONA W PROTOTYPIE ISL - POBRANIE NOWEGO PROTOTY- */
/* 	PU */
    if (isl == blank_2.nblsys) {
	goto L1000;
    }
/* 	 SKOK - JESLI DOSZLISMY DO BLOKU SYSTEMOWEGO NIE ZNAJDUJAC */
/* 	 NAZWY - BEDZIE TO POWROT */
    isl = blank_2.ipmem[isl - 2];
    blank_2.local = 1;
    goto L10;
/* ***** */
/* .... NAZWA ODNALEZIONA */
L20:
    if (isl == blank_2.nblus) {
	blank_2.local = 0;
    }
    return ret_val;

/* .... NAZWA NIEODNALEZIONA */
L1000:
    ret_val = 0;
    return ret_val;
} /* memsl_ */

/* DECK MEMPRF */
integer memprf_(integer *idprot)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i__, j, ipr;
    extern integer member_(integer *, integer *);

/* -------------WYSZUKUJE NAZWE  NM  W PROTOTYPIE IDENTYFIKOWANYM PRZEZ */
/* 	      IDPROT  ORAZ JEGO PREFIKSACH. WARTOSCIA JEST */
/* 	      ELEMENT LISTY HASH-U Z TA NAZWA  LUB  0 - GDY TEJ NAZWY */
/* 	      NIE BYLO. */
/* 	      / JESLI NAZWA WYSTAPILA BEZPOSREDNIO W  IDPROT   WARTOSCIA */
/* 	      / ZMIENNEJ OWN JEST .TRUE., JESLI W PREFIKSACH - .FALSE. */
/* 	      //PO ODNALEZIENIU NAZWY ELEMENT PRZESUWANY NA POCZATEK */
/* 	      LISTY HASH-U. */
/* 	      OPIS W DOKUMENTACJI:	  B.III.2.3 */
/* 	      WERSJA Z DNIA:		  19.01.82 (MJL) */
/* 	      DLUGOSC KODU:	  261 */
/* ....................................................................... */



/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */
/*     *CALL MEM */
/* ..... */
/*     KOMUNIKACJA Z PROCEDURA MEMPRF */
/*     !!!!!! END OF SUBSTITUTION OF COMDECK MEM FROM LOGLAN.14 !! */


    ipr = *idprot;
    blank_2.object = *idprot;
    blank_2.own = TRUE_;
/* 	 IPR - IDENTYFIKATOR KOLEJNYCH PROTOTYPOW */

    if (blank_2.ipmem[ipr - 1] == 1) {
	goto L500;
    }
    if ((lbit_shift(blank_2.ipmem[ipr - 1], (ftnlen)-4) & 15) != 0) {
	goto L500;
    }
/*     SKOK, GDY BYL TO ZWYKLY BLOK LUB PROTOTYP FORMALNY, NIE MA */
/*     WTEDY PRZEJSCIA PO PREFIKSACH */
    if ((lbit_shift(blank_2.ipmem[ipr - 1], (ftnlen)-8) & 7) == 7) {
	goto L500;
    }
/*     SKOK - GDY BYL TO PROTOTYP HANDLERA, NIE MA PRZEJSCIA PO PREFIKSACH */
/* 	 I,J - WSKAZNIKI PRZECHODZENIA PO LISCIE HASH-U - J  AKTUALNY, */
/* 	     I POPRZEDNI */
/* ***** */
L10:
    j = ipr + mem_1.nh + 9;
    j = blank_2.ipmem[j - 1];
    i__ = -1;
/* ..... SZUKANIE W PROTOTYPIE IPR */
L20:
    if (j == 0) {
	goto L25;
    }
/* 	   SKOK - NAZWA NIEODNALEZIONA - POBIERAMY KOLEJNY PROTOTYP */

    if (blank_2.ipmem[j - 1] == mem_1.nm) {
	goto L100;
    }
/* 	   SKOK - NAZWA ODNALEZIONA */

    i__ = j;
    j = blank_2.ipmem[j + 2];
    goto L20;
/* ..... */
/*      NAZWA NIEODNALEZIONA W PREFIKSIE  IPR - POBRANIE NOWEGO */
/* 	   PREFIKSU */

L25:
    blank_2.own = FALSE_;
/*     PRZEJSCIE DO PREFIKSU */
    ipr = blank_2.ipmem[ipr + 20];
    if (ipr != 0) {
	goto L10;
    }
    goto L1000;

/* ***** */

/* ..... NAZWA ODNALEZIONA */
L100:
    ret_val = j;
    blank_2.object = blank_2.ipmem[j + 1];
/* 	MIEJSCE DEKLARACJI */
    blank_2.object = blank_2.ipmem[blank_2.object - 2];
    if (i__ != -1) {
	goto L110;
    }
    return ret_val;
/* 	   PRZESUNIECIE ELEMENTU NA POCZATEK LISTY */
L110:
    blank_2.ipmem[i__ + 2] = blank_2.ipmem[j + 2];
    i__ = ipr + mem_1.nh + 9;
    blank_2.ipmem[j + 2] = blank_2.ipmem[i__ - 1];
    blank_2.ipmem[i__ - 1] = j;
    return ret_val;

/* .....BLOKI ZWYKLE, HANDLERY I PROTOTYPY FORMALNE */
L500:
    ret_val = member_(&mem_1.nm, &blank_2.ipmem[ipr + 9]);
    return ret_val;


/* .... NAZWA NIEODNALEZIONA */
L1000:
    ret_val = 0;
    return ret_val;
} /* memprf_ */

/* DECK INSERT */
integer insert_(integer *name__, integer *thash, integer *nrovf)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer nh;
    extern integer mgetm_(integer *, integer *);

/* -------------WPROWADZA NOWY ELEMENT O KLUCZU NAME  DO TABLICY HASH-U */
/* 	      THASH. DZIALA POPRAWNIE POD WARUNKIEM, ZE W TABLICY ELE- */
/* 	      MENT TAKI JESZCZE NIE WYSTAPIL. */
/* 	      WARTOSCIA  INSERT  JEST IDENTYFIKATOR TEGO ELEMENTU. */
/* 	      / WARTOSCI POCZATKOWE UTWORZONEGO ELEMENTU */
/* 		 POLE NAZWY - NAME */
/* 		 BITY HIDDEN, CLOSE, NOT TAKEN - 0 */
/* 		 IDENTYFIKATOR ATRYBUTU - NRUNIV */
/* 	     / NROVF - NUMER SYGNALIZOWANEGO PRZEPELNIENIA */

/* 	      OPIS W DOKUMENTACJI:	   B.III.2.1 */
/* 	      WERSJA Z DNIA:	    19.01.82 (MJL) */
/* 	      DLUGOSC KODU:    95 */
/* ....................................................................... */


/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */

/* ..... REZERWACJA PAMIECI NA ELEMENT LISTY HASH-U */
    /* Parameter adjustments */
    --thash;

    /* Function Body */
    ret_val = mgetm_(&c__4, nrovf);

/* ..... NADANIE WARTOSCI POCZATKOWYCH I DOLACZENIE DO LISTY HASH-1 */
    blank_2.ipmem[ret_val - 1] = *name__;
    blank_2.ipmem[ret_val + 1] = blank_2.nruniv;
    nh = (lbit_shift(*name__, (ftnlen)-1) & 7) + 1;
    blank_2.ipmem[ret_val + 2] = thash[nh];
    thash[nh] = ret_val;
    return ret_val;
} /* insert_ */

/* DECK MEMBER */
integer member_(integer *name__, integer *thash)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i__, j, nh;

/* -------------SPRAWDZA, CZY W TABLICY HASH-U  THASH  WYSTEPUJE NAZWA */
/* 	      NAME. JESLI TAK - WARTOSCIA JEST IDENTYFIKATOR ELEMENTU */
/* 	      LISTY HASH-U Z TA NAZWA. JESLI NIE - WARTOSCIA JEST  0 . */
/* 	      / JESLI NAZWA WYSTAPILA - ELEMENT JEJ ODPOWIADAJACY JEST */
/* 	      PRZESUWANY NA POCZATEK LISTY. */

/* 	      OPIS W DOKUMENTACJI:	  B.III.2.2 */
/* 	      WERSJA Z DNIA:		  19.01.82 (MJL) */
/* 	      DLUGOSC KODU:	   155 */
/* ...................................................................... */


/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */
    /* Parameter adjustments */
    --thash;

    /* Function Body */
    nh = (lbit_shift(*name__, (ftnlen)-1) & 7) + 1;
/* 	 NH - WARTOSC FUNKCJI HASZUJACEJ - INDEKS W TABLICY THASH  SLOWA */
/* 	 ZAWIERAJACEGO POCZATEK LISTY */

/* 	 I,J - WSKAZNIKI PORUSZANIA SIE PO LISCIE */
/* 	   J - WSKAZNIK AKTUALNY, I - POPRZEDNI */
    i__ = -1;
    j = thash[nh];

L10:
    if (j == 0) {
	goto L200;
    }
/* 	 SKOK - JESLI ATRYBUT NIE ZOSTAL ODNALEZIONY */

    if (blank_2.ipmem[j - 1] == *name__) {
	goto L100;
    }
/* 	    SKOK - JESLI ATRYBUT ODNALEZIONY */
    i__ = j;
    j = blank_2.ipmem[j + 2];
    goto L10;

/* ..... NAZWA ODNALEZIONA */
L100:
    ret_val = j;
    if (i__ != -1) {
	goto L110;
    }
    return ret_val;
/* 	   PRZESUNIECIE ELEMENTU LISTY NA POCZATEK LISTY */
L110:
    blank_2.ipmem[i__ + 2] = blank_2.ipmem[j + 2];
    blank_2.ipmem[j + 2] = thash[nh];
    thash[nh] = j;
    return ret_val;

/* ..... NAZWA NIEODNALEZIONA */
L200:
    ret_val = 0;
    return ret_val;
} /* member_ */

/* DECK MGETM */
integer mgetm_(integer *isize, integer *nrovf)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer i__, j, x;
    extern /* Subroutine */ int mdrop_(integer *);

/* -------------REZERWUJE W PAMIECI  IPMEM  ISIZE KOMOREK. WAROSCIA MGETM */
/* 	      JEST INDEKS PIERWSZEJ Z TYCH KOMOREK. */
/* 	      REZERWACJA JEST DOKONYWANA W CZESCI SYSTEMOWEJ JESLI WAR- */
/* 	      TOSC ZMIENNEJ INSYS (BLOK //)  JEST .TRUE., W PRZE- */
/* 	      CIWNYM PRZYPADKU - W CZESCI UZYTKOWNIKA. */
/* 	      /// GDY REZERWACJA TA NIE JEST MOZLIWA - WYWOLYWANA JEST */
/* 	      PROCEDURA MDROP PRZERYWAJACA PROCES KOMPILACJI */
/* 	      NROVF - NUMER SYGNALIZOWANEGO PRZEPELNIENIA */

/* 	      OPIS W DOKUMENTACJI:	B.III.1 */
/* 	      WERSJA Z DNIA:		19.01.82 (MJL) */
/* 	      DLUGOSC KODU:	  145 */
/* ........................................................................... */

/* 	      ZAREZERWOWANA PAMIEC JEST WYZEROWANA */


/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */

    if (blank_2.lpml + *isize > blank_2.lpmf) {
	goto L1000;
    }
/* 	      SKOK - GDY WOLNY OBSZAR JEST ZA MALY */
    if (blank_2.insys) {
	goto L100;
    }

/* ..... PRZYDZIAL PAMIECI W CZESCI UZYTKOWNIKA */
    blank_2.lpmf -= *isize;
    i__1 = *isize;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = blank_2.lpmf + i__;
	blank_2.ipmem[j - 1] = 0;
/* L50: */
    }
    ret_val = blank_2.lpmf + 1;
    goto L500;

/* ..... PRZYDZIAL PAMIECI W CZESCI SYSTEMOWEJ */
L100:
    ret_val = blank_2.lpml;
    i__1 = *isize;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = blank_2.lpml + i__;
	blank_2.ipmem[j - 2] = 0;
/* L150: */
    }
    blank_2.lpml += *isize;
/* .....SPRAWDZENIE WYKORZYSTANIA PAMIECI */
L500:
    x = blank_2.lpmf - blank_2.lpml;
    if (x < blank_2.com[3]) {
	blank_2.com[3] = x;
    }
    return ret_val;


/* ..... BRAK MIEJSCA W PAMIECI */
L1000:
    mdrop_(nrovf);

    return ret_val;
} /* mgetm_ */

/* DECK MPRFSQ */
integer mprfsq_(integer *idpr1, integer *idpr2)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer k1, k2;
    extern logical bpref_(integer *, integer *);

/* -------------BADA RODZAJ PREFIKSOWANIA TYPOW IDPR1 I IDPR2 */
/* 	      WARTOSCI */
/* 		-1 - ROZLACZNE SEKWENCJE PREFIKSOWE */
/* 		 0 - IDPR1 PREFIKSUJE IPR2 */
/* 		+1 - IDPR2 PREFIKSUJE IDPR1 */
/* 	      OBA TYPY MOGA BYC TYPAMI UNIWERSALNYMI */

/* 	      OPIS W DOKUMENTACJI:	    B.III.4.3 */
/* 	      WERSJA Z DNIA:		    19.01.82 (MJL) */
/* 	      DLUGOSC KODU:	   79 */
/* ........................................................................ */


/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */

    k1 = blank_2.ipmem[*idpr1 - 7];
    k2 = blank_2.ipmem[*idpr2 - 7];
/* 	 K1,K2 - NUMERY TYPOW W SENSIE PREFIXSET */
    if (bpref_(idpr2, &k1)) {
	goto L20;
    }
    if (bpref_(idpr1, &k2)) {
	goto L30;
    }

/* ..... ROZLACZNE SEKWENCJE PREFIKSOWE */
    ret_val = -1;
    return ret_val;
/* ..... IDPR1 PREFIKSUJE IDPR2 */
L20:
    ret_val = 0;
    return ret_val;
/* ..... IDPR2 PREFIKSUJE IDPR1 */
L30:
    ret_val = 1;
    return ret_val;

} /* mprfsq_ */

/* DECK BPREF */
logical bpref_(integer *idprot, integer *nrpref)
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer k, l, idl, ipr, prfx;

/* -------------BPREF SPRAWDZA, CZY TYP IDENTYFIKOWANY PRZEZ IDPROT JEST */
/* 	      PREFIKSOWANY PRZEZ KLASE, KTOREJ NUMER W SENSIE PREFIXSET */
/* 	      JEST ROWNY NRPREF. */
/* 	      WARTOSC .TRUE. - JEST PREFIKSOWANY */


/* 	      OPIS W DOKUMENTACJI:	    B.III.4.1 */
/* 	      WERSJA Z DNIA:		    19.03.82 (MJL) */
/* 	      DLUGOSC KODU:	   255 */
/* ......................................................................... */


/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */

    if (*nrpref > 47) {
	goto L300;
    }
    k = *nrpref / 16;
    if ((blank_2.ipmem[*idprot - 1] & 15) != 1) {
	goto L100;
    }
    ret_val = FALSE_;
    if (blank_2.ipmem[*idprot + 20] == 0) {
	return ret_val;
    }
    k = blank_2.ipmem[*idprot + 20] - 3 - k;
    goto L200;
L100:
    k = *idprot - 3 - k;
L200:
    k = blank_2.ipmem[k - 1];
/* 	 K SLOWO W PREFIXSET, W KTORYM NALEZY ZBADAC BIT ODPOWIADAJACY */
/* 		 NRPREF */

    l = *nrpref & 15;
/* 	 L - NUMER TESTOWANEGO BITU -	L = IMOD(NRPREF,16) */

    ret_val = bit_test(k,l);
    return ret_val;
L300:
    ret_val = TRUE_;
    ipr = *idprot;
    if ((blank_2.ipmem[ipr - 1] & 15) == 1) {
	ipr = blank_2.ipmem[ipr + 20];
    }
    if (ipr == 0) {
	goto L500;
    }
    if (ipr == blank_2.nruniv) {
	return ret_val;
    }
    idl = blank_2.ipmem[ipr + 22];
    ipr = blank_2.ipmem[ipr + 21];
L400:
    prfx = blank_2.ipmem[ipr - 1];
    if (blank_2.ipmem[prfx - 7] == *nrpref) {
	return ret_val;
    }
    --idl;
    ++ipr;
    if (idl != 0) {
	goto L400;
    }
L500:
    ret_val = FALSE_;
    return ret_val;
} /* bpref_ */

/* Subroutine */ int mdrop_(integer *nrovfl)
{
    extern /* Subroutine */ int ml2_(void), merr_(integer *, integer *), 
	    mess_(void);

/* -------------PROCEDURA PRZERYWA DZIALANIE MODULU. */
/* 	      WYWOLYWANA JEST W PRZYPADKU PRZEPELNIEN JAKIEJKOLWIEK TAB- */
/* 	      LICY KOMPILATORA. */
/* 	      NROVFL - NUMER PRZEPELNIENIA (INFORMACJA O TABLICY) */
/* 	      //WYWOLUJE PROCEDURE  MERR , BUFORY STRUMIENI PRZESYLA DO */
/* 	      OBSZARU KOMUNIKACYJNEGO W BLOKU //. */
/* 	      USTAWIA FLAGE "DROPOWANIA". */

/* 	      OPIS W DOKUMENTACJI:	 B.I.2 */
/* 	      WERSJA Z DNIA:		 19.01.82 (MJL) */
/* 	      DLUGOSC KODU:	  101 */
/* ...................................................................... */


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

/* 	      ERRFLG - FLAGA BLEDOW */

/*     SYGNALIZOWANIE BLEDU */
    stream_1.line = 9999;
    merr_(nrovfl, &c__0);

    blank_3.dropfg = TRUE_;
/*     ERRFG = .TRUE. */
    blank_3.iop[0] += 7;
    mess_();
    ml2_();
    return 0;
} /* mdrop_ */

/* Subroutine */ int merr_(integer *nre, integer *id)
{
    static integer poz;
    extern /* Subroutine */ int put_(integer *, integer *), openf_(integer *, 
	    integer *);

/* --------------PROCEDURA WPISUJACA SYGNALIZACJE BLEDOW NA STRUMIEN  2 */
/* 	      NRE - NUMER BLEDU */
/* 	      ID - IDENTYFIKACJA BLEDU, TO ZNACZY */
/* 		 -IDENTYFIKATOR ZE SCANNERA, */
/* 		 -ZANEGOWANY ZNAK W PRAWYM BAJCIE, */
/* 		 -ZERO OZNACZAJACE BRAK IDENTYFIKATORA. */
/* 	      //PROCEDURA W RAZIE POTRZEBY NISZCZY DOTYCHCZASOWY */
/* 	      ZAPIS ZNAJDUJACY SIE NA STRUMIENIU SO (KOD DLA ASSEMBLERA) */
/* 	      ORAZ USTAWIA FLAGE BLEDOW  ERRFLG. */

/* 	      OPIS W DOKUMENTACJI:    B.I.1 */
/* 	      WERSJA Z DNIA:	      19.01.82 (MJL) */
/* 	      DLUGOSC KODU:	  146 */
/* ................................................................. */


/*     *CALL STREAM */
/* 	      ERRFLG - FLAGA BLEDOW */
/*     !!!!!! END OF SUBSTITUTION OF COMDECK STREAM FROM LOGLAN.14  !! */
/*     *CALL MJLMSG */
/*     !!!!!! END OF SUBSTITUTION OF COMDECK MJLMSG FROM LOGLAN.14 !! */
/* deb --------------------- added =---------------- */
/* deb --------------------------------------- */


/* ----- ZBADANIE, CZY JEST TO PIERWSZY SYGNALIZOWANY BLAD */
    if (stream_1.errflg) {
	goto L100;
    }
/* ..... PRZYPADEK, GDY BLAD JEST SYGNALIZOWANY PO RAZ PIERWSZY */
    stream_1.errflg = TRUE_;
/* ---  L-CODE WRITTEN DIRECTLY IN THE SIEMENS VERSION */
/* --- IN THE SIEMENS VERSION OF THE COMPILER IBUF2 IS USED ONLY */
/* --- TO LOCATE THERE INFORMATION ABOUT ERRORS. SO NOW IT IS THE */
/* --- PROPER TIME TO						    OPEN IT */
/* deb */
    debug_1.deb = FALSE_;
/* deb */
/* ---  unit 19 (ibuf2) - do bledow (direct) */
    openf_(stream_1.ibuf2, &c__19);
/*     OD TEJ PORY BUFOR ZACZYNA ODPOWIADAC STRUMIENIOWI O DOSTEPIE */
/*     BEZPOSREDNIM . JEGO BUDOWA: */
/* 	SLOWA 1-7 -BUFOR DLA PROCEDUR ZAPISU I ODCZYTU (OPIS STRUMIENIA) */
/* 	SLOWO 8 -NUMER AKTUALNIE ZAPISYWANEGO BLOKU */
/* 	SLOWO 9 -INDEKS PIERWSZEJ WOLNEJ POZYCJI BLOKU AKTUALNIE TWORZO- */
/* 	      NEGO */
/* 	SLOWO 10 -LICZBA TROJEK WPISANYCH DO BLOKU */
/* 	SLOWA 10-265 -AKTUALNIE TWORZONY BLOK (TROJKI ZAPISYWANE OD SLO- */
/* 	      WA 11) */

    stream_1.ibuf2[7] = 0;
    stream_1.ibuf2[8] = 11;

/* -----WPISANIE SYGNALIZACJI BLEDU */
L100:
    ++mjlmsg_1.ierc;
    poz = stream_1.ibuf2[8];
/* 	POZ - AKTUALNA POZYCJA DO WYPELNIENIA */
/*     ZAPISANIE NUMERU LINII, NUMERU BLEDU I IDENTYFIKACJI */
    stream_1.ibuf2[poz - 1] = stream_1.line;
    stream_1.ibuf2[poz] = *nre;
    stream_1.ibuf2[poz + 1] = *id;
/*     MODYFIKACJA BUFORA */
    poz += 3;
    stream_1.ibuf2[8] = poz;
    if (poz <= 263) {
	return 0;
    }
/*     ..... JESLI BLOK ZOSTAL ZAPELNIONY, ZAPISANIE GO NA DYSK */
    ++stream_1.ibuf2[7];
    stream_1.ibuf2[8] = 11;
    stream_1.ibuf2[9] = 85;
    put_(stream_1.ibuf2, &stream_1.ibuf2[9]);
    return 0;
} /* merr_ */

/* Subroutine */ int madatr_(integer *idatr, integer *idprot, integer *nrovf)
{
    static integer iact, iost;
    extern integer mgetm_(integer *, integer *);

/* -------------WPROWADZA ATRYBUT O IDENTYFIKATORZE IDATR DO LISTY ATRYBU- */
/* 	      TOW PROTOTYPU  IDPROT. W OPISIE ATRYBUTU NADAJE WARTOSC */
/* 	      POLOM  DECLPLACE/SL  ORAZ  NUMERU ATRYBUTU */
/* 	      // NROVF - NUMER SYGNALIZOWANEGO PRZEPELNIENIA */

/* 	      OPIS W DOKUMENTACJI:	    B.III.3 */
/* 	      WERSJA Z DNIA:		    19.01.82 (MJL) */
/* 	      DLUGOSC KODU:	   99 */
/* ......................................................................... */


/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */

    iact = mgetm_(&c__2, nrovf);
    blank_2.ipmem[iact - 1] = *idatr;
    iost = blank_2.ipmem[*idprot + 6];
/* 	 IOST - OSTATNI ELEMENT LISTY ATRYBUTOW */
/* ..... DOLACZENIE  IACT  DO LISTY ATRYBUTOW */
    blank_2.ipmem[iost] = iact;
    blank_2.ipmem[*idprot + 6] = iact;
/* ..... NADANIE WARTOSCI  SL  ORAZ  NUMERU ATRYBUTU */
    iost = blank_2.ipmem[iost - 1];
/* 	 IOST - OSTATNI ATRYBUT - INDEKS OPISU */
    blank_2.ipmem[*idatr - 2] = *idprot;
    blank_2.ipmem[*idatr - 3] = blank_2.ipmem[iost - 3] + 1;
    return 0;
} /* madatr_ */

/* Subroutine */ int msetb_(integer *idprot, integer *nrpref)
{
    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer k, l;

/* -------------W ZBIORZE PREFIXSET TYPU IDENTYFIKOWANEGO PRZEZ IDPROT */
/* 	      USTAWIA BIT  NRPREF  NA 1 */

/* 	      OPIS W DOKUMENTACJI:	 B.III.4.2 */
/* 	      WERSJA Z DNIA:		 19.03.82 (MJL) */
/* 	      DLUGOSC KODU:	   87 */
/* ....................................................................... */


/*     *CALL BLANK */
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

/*     !!!!!! END OF SUBSTITUTION OF COMDECK BLANK FROM LOGLAN.14  !! */

    if (*nrpref > 47) {
	return 0;
    }
    k = *nrpref / 16;
    k = *idprot - 3 - k;
/* 	 K - INDEKS MODYFIKOWANEGO ELEMENTU PREFIXSET */

    l = *nrpref & 15;
/* 	 L - NUMER ZAPALANEGO BITU */
    l = lbit_shift((ftnlen)1, l);

    blank_2.ipmem[k - 1] |= l;
    return 0;
} /* msetb_ */

