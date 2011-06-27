#define GRAPH_CMD_POINT 1
#define GRAPH_CMD_END   2
#define GRAPH_CMD_LINE  3

#define GRAPH_COL_BACK	0
#define GRAPH_COL_BOARD	1
#define GRAPH_COL_OK	2
#define GRAPH_COL_ERROR	3

#ifndef NO_PROTOTYPES
void graph_on( int x, int y, char *title );
void graph_off( void );
void graph_point( int x, int color );
void graph_board( int size );
#else
void graph_on();
void graph_off();
void graph_point();
void graph_board();
#endif
