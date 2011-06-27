SHELL=/bin/sh

all : srvr clnt stop

LIBS = -lrpc -lsocket
SRVR_LIBS = -lrpcsvc $(LIBS)

clean :
	rm -f srvr clnt stop *.o a.out errs core

srvr : srvr.c
	cc -o srvr srvr.c $(SRVR_LIBS)

clnt : clnt.c
	cc -o clnt clnt.c $(LIBS)

stop : stop.c
	cc -o stop stop.c $(LIBS)
