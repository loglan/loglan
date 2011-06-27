#define	PORT 		3963
#define DATA_PIECE	64

typedef struct { 
   unsigned long req;
   char data[DATA_PIECE];
} msg;

#define HEAD (sizeof(msg)-DATA_PIECE)


#define RQ_FILE_SIZE	1
#define RQ_FILE		2

