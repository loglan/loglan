#define MAXMARKER       MAXINTEGER  /* maximum special value of mark */
#define MAXAPPT         MAXINTEGER  /* maximum appetite (easily extensible ?) */
#define MAXTRACNT       13      /* maximum number of trace messages in line */
#define MAXHDLEN        40      /* maximum length of formal procedure header */
#define MAXSYSSN        62      /* maximum number of a system signal */
#define MAXPARAM        10      /* maximum number of params to standard proc */
#define IOBLOCK         0x4000  /* size of I/O transfer block in bytes */

/* Object structure : */

/* Offsets from the beginning : */
#define PROTNUM         1       /* prototype number */
#define SHORTLINK       1       /* link to same size list (killed only) */
#define LONGLINK        2       /* link to other size list (killed only) */

/* Files : */
/*      appetite        0       */
/*      prot number     1       always FILEOBJECT */
#define FSTAT           2       /* file status */
#define FTEMP           3       /* flag to tell if file is temporary */
#define FTYPE           4       /* file type */
#define FNAME           5       /* file name pointer */
#define FFILE           (FNAME+sizeof(char *)/sizeof(word)) /*file handle */
#define APFILE          (FFILE+sizeof(FILE *)/sizeof(word)) /*appetite of file*/
							    /* object */

/* Offsets from the first address after object : */
#define SL              -2      /* static link */
#define DL              -4      /* dynamic link */
#define LSC             -5      /* local control */
#define STATSL          -6      /* number of times the object occurs in SL */
#define SIGNR           -7      /* signal number (handlers only) */
#define RPCDL           -8      /* remote dynamic link (procedures only) */
#define CL              -8      /* coroutine link (coroutine only) */
#define CHD             -10     /* coroutine head (process only) */
#define VIRTSC          -12     /* virtual scratch  (process only) */

/* Virtual address (also formal type) : */

typedef struct {
		word addr;      /* address of dictionary item */
				/* (node and process index for processes) */
				/* (or for formal types - number of arrayof) */
		word mark;      /* address mark */
				/* (negative for processes) */
				/* (or for formal types - actual type) */
	       } virtaddr;

#define loadvirt(v, a)  { word ta;              \
			  ta = (a);             \
			  (v).addr = M[ ta++ ]; \
			  (v).mark = M[ ta ]; }
#define storevirt(v, a) { word ta;              \
			  ta = (a);             \
			  M[ ta++ ] = (v).addr; \
			  M[ ta ] = (v).mark; }
			
#define MF(a)           (*( (FILE **) (M+(a)) ))
#define MN(a)           (*( (char **) (M+(a)) ))
#define MR(a)            *( (real *) (M+(a)) )


#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#define min(x, y)       ((x) < (y) ? (x) : (y))
#define max(x, y)       ((x) > (y) ? (x) : (y))
#define absolute(x)     ((x) >= 0 ? (x) : -(x))

/* LOGLAN's booleans : */
#define LFALSE          ((word)0)
#define LTRUE           (~LFALSE)
#define lbool(b)        ( (b) ? LTRUE : LFALSE )

/* Type of files : */
#define TEXTF           1       /* text file */
#define CHARF           2       /* file of char */
#define INTF            3       /* file of integer */
#define REALF           4       /* file of real */
#define DIRECT          5       /* direct access file */

/* File status : */
#define READING         0       /* sequential file opened for read */
#define WRITING         1       /* sequential file opened for write */
#define UPDATING        2       /* direct access file */
#define UNKNOWN         3       /* file not opened */

/* Run time error types : */

#define RTESLCOF        0       /* SL chain cut off */
#define RTEUNSTP        1       /* unimplemented standard procedure */
#define RTEILLAT        2       /* illegal attach */
#define RTEILLDT        3       /* illegal detach */
#define RTECORTM        4       /* coroutine terminated */
#define RTECORAC        5       /* coroutine active */
#define RTEINVIN        6       /* array index error */
#define RTEILLAB        7       /* incorrect array bounds */
#define RTEINCQA        8       /* improper QUA */
#define RTEINCAS        9       /* illegal assignment */
#define RTEFTPMS        10      /* formal type missing */
#define RTEILLKL        11      /* illegal kill */
#define RTEILLCP        12      /* illegal copy */
#define RTEINCHS        13      /* incompatible headers */
#define RTEHNDNF        14      /* handler not found */
#define RTEMEMOV        15      /* memory overflow */
#define RTEFHTLG        16      /* formal header too long */
#define RTEILLRT        17      /* illegal return */
#define RTEREFTN        18      /* reference to NONE */
#define RTEDIVBZ        19      /* division by zero */
#define RTESYSER        20      /* system error */
#define RTEILLIO        21      /* illegal I/O operation */
#define RTEIOERR        22      /* I/O error */
#define RTECNTOP        23      /* Cannot open file */
#define RTEBADFM        24      /* Input data format bad */
#define RTEILLRS        25      /* illegal resume */
#define RTETMPRC        26      /* too many processes on one machine */
#define RTEINVND        27      /* invalid node number */
#define RTENEGST        28      /* negative step value */
#define RTENONGL        29      /* only process may be global */

union value {
		unsigned int xint;
		word xword;
		real xreal;
		virtaddr xvirt;
		word xbool;
	    };

/* Variables : */

extern memory M;                /* main memory for code and data */
extern union value *param;      /* pointer to standard proc. param list */
extern int offset[];            /* offset conversion table for compact. */
extern int scot[];              /* signal to number conversion table */
extern int primapet[];          /* appetites of primitive types */
extern word ic;                 /* instruction counter */
extern word lastic;             /* previous ic for redecoding after comp. */
extern int opcode;              /* opcode of L-code instruction */
extern word a1, a2, a3;         /* arguments of L-code instruction */

/* kernel variables for the running system */

extern word memorysize;         /* size of memory array for code and data */
extern word dispoff;            /* DISPLAY offset in process object */
extern word disp2off;           /* indirect DISPLAY offset in process object */
extern word display;            /* DISPLAY address - physical addresses */
extern word display2;           /* DISPLAY address - indirect addresses */
extern word c1, c2;             /* pointers to current object */
extern word mainprog;           /* main block object */
extern word mnoff;              /* offset of variable main */


extern bool infmode;            /* TRUE if compactification message printed */
extern bool debug;              /* TRUE if trace is printed */
extern FILE *tracefile;         /* output file for trace */

extern jmp_buf contenv;         /* for continue execution */



