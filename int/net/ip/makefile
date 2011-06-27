SHELL = /bin/sh


#### SCO ####
CFLAGS=-g -W1
socket=-lsocket

#### HP  ####
#CFLAGS=-g -DNO_PROTOTYPES -DNO_MWM -DBZERO
#socket=



PROD = cli srv graph time timediff

install all: $(PROD)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

cli: cli.o graph.o sock.o sockcrc.o
	$(CC) $(CFLAGS) -o cli cli.o graph.o sock.o sockcrc.o -lX11 $(socket)

srv: srv.o sock.o sockcrc.o
	$(CC) $(CFLAGS) -o srv srv.o sock.o sockcrc.o $(socket)

graph: graphsrv.o
	$(CC) $(CFLAGS) -o graph graphsrv.o -lX11 $(socket)

time: time.o sock.o
	$(CC) $(CFLAGS) -o time time.o sock.o $(socket)

timediff: timediff.o sock.o
	$(CC) $(CFLAGS) -o timediff timediff.o sock.o $(socket)

clean:
	-rm -f $(PROD)
	-rm -f *.o
	-rm -f srv.log

