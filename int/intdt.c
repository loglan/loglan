#include	"depend.h"
#include	"genint.h"
#include	"int.h"
#include	"process.h"
#include	"intproto.h"

/* Variables common with generator : */

protdescr *prototype[ MAXPROT+1 ]; /* prototypes */
word ipradr;			/* address of primitive types descriptions */
word temporary;			/* address of global temporary variables */
word strings;			/* base for string constants */
word lastprot;			/* the last used prototype number */
word freem;			/* first free cell in M */
word currfile = 2;		/* current file virtual address */

/* Interpreter own variables : */

memory M;			/* main memory for code and data */
union value *param;		/* for comunication with standard procs */

/* offset conversion table for compactification */
int offset[] = { DUMMY, SL, DL, CL, CHD, VIRTSC };

/* signal to number conversion table */
/* -1 stands for an unrecoverable error which cannot be serviced by handler */

int scot[] =
{
		20,		/* RTESLCOF */
		20,		/* RTEUNSTP */
		20,		/* RTEILLAT */
		20,		/* RTEILLDT */
		20,		/* RTECORTM */
		20,		/* RTECORAC */
		23,		/* RTEINVIN */
		23,		/* RTEILLAB */
		21,		/* RTEINCQA */
		24,		/* RTEINCAS */
		20,		/* RTEFTPMS */
		20,		/* RTEILLKL */
		20,		/* RTEILLCP */
		24,		/* RTEINCHS */
		-1,		/* RTEHNDNF */
		22,		/* RTEMEMOV */
		22,		/* RTEFHTLG */
		-1,		/* RTEILLRT */
		21,		/* RTEREFTN */
		01,		/* RTEDIVBZ */
		02,		/* RTESYSER */
		02,		/* RTEILLIO */
		02,		/* RTEIOERR */
		02,		/* RTECNTOP */
		02,		/* RTEBADFM */
		20,		/* RTEILLRS */
		02,		/* RTETMPRC */
		02,		/* RTEINVND */
                23,		/* RTENEGST */
                -1		/* RTENONGL */
};

/* Primitive type appetites for moveparams() : */

int primapet[] =
{
		APINT,		/* INTEGER */
		APREAL,		/* REAL */
		APINT,		/* BOOLEAN */
		APINT,		/* CHAR */
		APREF,		/* COROUTINE */
		APREF,		/* PROCESS */
		APINT		/* STRING */
};

word ic; 			/* instruction counter */
word lastic;			/* previous ic for redecoding after compact. */
int opcode;			/* opcode of L-code instruction */
word a1, a2, a3;		/* arguments of L-code instructions */

/* kernel variables for the running system: */

word memorysize = DEFMEMSIZE;	/* code and data memory size */
word c1, c2;			/* pointers to current object */
word dispoff;			/* DISPLAY offset in process object */
word disp2off;			/* indirect DISPLAY offset in process object */
word display;           	/* DISPLAY address - physical addresses */
word display2; 		        /* DISPLAY address - indirect addresses */
word mainprog;           	/* main block object */
word mnoff;			/* offset of variable main */


bool infmode = FALSE;		/* default: no compactification message */
bool debug = FALSE;             /* TRUE if trace is printed */
FILE *tracefile;                /* output file for trace */

jmp_buf contenv;		/* for continue execution */
