# include	<stdio.h>
# include	<string.h>
#ifndef NO_PROTOTYPES
# include	<stdlib.h>
#endif
# include	<sys/types.h>
# include	<signal.h>
# include	<sys/socket.h>
# include	<sys/time.h>
# include	<netinet/in.h>
# include	<netdb.h>
# include	<errno.h>


#define AS_CLIENT 0
#define AS_SERVER 1


#ifndef NO_PROTOTYPES
int  sock_open( int socket_type, char *protocol,
                char *host, char *service, int port,
                int as_server );
int  sock_cli_send( int sock, void *m, int size );
int  sock_cli_recv( int sock, void *m, int size );
int  sock_srv_recv( int sock, void *m, int size,
                    struct sockaddr_in *addr, int *namelen );
int  sock_srv_send( int sock, void *m, int size,
                    struct sockaddr_in *addr, int  namelen );
void set_cli_recv_timeout( int miliseconds );
void set_srv_send_delay  ( int miliseconds );
int  poll_socket( int sock, int miliseconds );
#else
int  sock_open();
int  sock_cli_send();
int  sock_cli_recv();
int  sock_srv_recv();
int  sock_srv_send();
void set_cli_recv_timeout();
void set_srv_send_delay  ();
int  poll_socket();
#endif


#ifndef NO_PROTOTYPES
int  sock_cli_crc_send( int sock, void *m, int size );
int  sock_cli_crc_recv( int sock, void *m, int size );
int  sock_srv_crc_recv( int sock, void *m, int size,
                        struct sockaddr_in *addr, int *namelen );
int  sock_srv_crc_send( int sock, void *m, int size,
                        struct sockaddr_in *addr, int  namelen );
#else
int  sock_cli_crc_send();
int  sock_cli_crc_recv();
int  sock_srv_crc_recv();
int  sock_srv_crc_send();
#endif

