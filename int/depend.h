/*     Loglan82 Compiler&Interpreter
     Copyright (C) 1993 Institute of Informatics, University of Warsaw
     Copyright (C)  1993, 1994 LITA, Pau
     
     This program is free software; you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation; either version 2 of the License, or
     (at your option) any later version.
     
     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
     
             You should have received a copy of the GNU General Public License
             along with this program; if not, write to the Free Software
             Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 contacts:  Andrzej.Salwicki@univ-pau.fr

or             Andrzej Salwicki
                LITA   Departement d'Informatique
                Universite de Pau
                Avenue de l'Universite
                64000 Pau   FRANCE
		 tel.  ++33 59923154	fax. ++33 59841696

=======================================================================
*/

#if MSDOS
#undef UNIX
#undef OS2
#elif UNIX
#undef OS2
#elif OS2
#undef UNIX
#else
#error Define one of MSDOS/OS2/UNIX
#endif

#if WORD_16BIT
#undef DWORD_16BIT
#undef WORD_32BIT
#elif DWORD_16BIT
#undef WORD_32BIT
#elif WORD_32BIT
#undef DWORD_16BIT
#else
#error Define one of WORD_16BIT/DWORD_16BIT/WORD_32BIT
#endif


#include <stdio.h>
#include <malloc.h>
#include <setjmp.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
                char opcode;
                char args[ 3 ];
               } extopcode;

typedef char *lword;	/* max(word, char *) but in every case was char* */

#define BINARYREAD	"rb"
#define BINARYWRITE	"wb"
#define DIRECTOLD	"r+b"
#define DIRECTNEW	"w+b"


#if WORD_16BIT

typedef int word;
typedef float real;
typedef word *memory;

#if UNIX
extern char *calloc(int,int);
#endif

#define mallocate(n)	((memory) (char /*|||huge*/ *) calloc((n),sizeof(word)))
#define ballocate(n)	((char /*|||huge*/ *) calloc((n),1))

#define MAXINTEGER   0x7FFF
#define DEFMEMSIZE   0x7FF0		/* 32K words = 64K bytes */
#define MAXMEMSIZE   0x7FF0		/* 32K words = 64K bytes */

#endif



#if DWORD_16BIT

typedef long word;
typedef double real;
typedef word huge *memory;

#if UNIX

extern char *calloc(int,int);

#define mallocate(n)   (((n)<60000)?(memory) calloc((n),sizeof(word)):abort())
#define ballocate(n)   (calloc((n),1))

#define MAXINTEGER   0x7FFFFFFFL
#define DEFMEMSIZE   0x13C00L	/* 79K words = 316K bytes */
#define MAXMEMSIZE   0x400000L	/*  4M words =  16M bytes */

#elif OS2

extern char huge *halloc();

#define mallocate(n)	((memory) halloc((long) (n), sizeof(word)))
#define ballocate(n)	(halloc((long) (n),1L))

#define MAXINTEGER   0x7FFFFFFFL
#define DEFMEMSIZE   0x13C00L	/* 79K words = 316K bytes */
#define MAXMEMSIZE   0x400000L	/*  4M words =  16M bytes */

#define INCL_DOSINFOSEG

#include <os2.h>        

#elif MSDOS && TURBOC

extern char far *farcalloc();

#define mallocate(n)	((memory) farcalloc((long) (n), (long) sizeof(word)))
#define ballocate(n)	(farcalloc((long) (n),1L))

#define MAXINTEGER   0x7FFFFFFFL
#define DEFMEMSIZE   0x14000L	/* 80K words = 320K bytes */
#define MAXMEMSIZE   0x28000L	/* 160K words = 640K bytes */

#elif MSDOS

extern void huge *halloc();
#define mallocate(n)   ((memory) halloc((long) (n), sizeof(word)))
#define ballocate(n)   (halloc((long) (n),1))

#define MAXINTEGER   0x7FFFFFFFL
#define DEFMEMSIZE   0xF000L	/* 60K words = 120K bytes */
#define MAXMEMSIZE   0x28000L	/* 160K words = 640K bytes */

#else
#error Allocation macros not defined.
#endif

#endif



#if WORD_32BIT

typedef int word;
typedef float real;
typedef word *memory;

#define mallocate(n)	((memory) (char *) calloc((n),sizeof(word)))
#define ballocate(n)	((char *) calloc((n),1))

/* printf("|%d*4|",(n)),getchar(),\ */

#define MAXINTEGER   0x7FFFFFFFL
#define DEFMEMSIZE   0x13C00L	/* 79K words = 316K bytes */
#define MAXMEMSIZE   0x400000L	/*  4M words =  16M bytes */

#endif


