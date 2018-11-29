INCPATH = inc/
SRCPATH = src/
UNITTESTPATH = Unittest/

CC = gcc
CFLAGS = -Wall -c

proj2: main.o help.o addbuff.o rembuff.o addchar.o resize.o remchar.o stat.o
	$(CC) $(CFALGS) main.o help.o addbuff.o rembuff.o addchar.o remchar.o stat.o resize.o -o proj2

main.o: $(SRCPATH)main.c $(INCPATH)main.h
	$(CC) $(CFLAGS) $(SRCPATH)main.c -I$(INCPATH)

help.o: $(SRCPATH)help.c $(INCPATH)help.h
	$(CC) $(CFLAGS) $(SRCPATH)help.c -I$(INCPATH)

addbuff.o: $(SRCPATH)addbuff.c $(INCPATH)addbuff.h
	$(CC) $(CFLAGS) $(SRCPATH)addbuff.c -I$(INCPATH)

rembuff.o: $(SRCPATH)rembuff.c $(INCPATH)rembuff.h
	$(CC) $(CFLAGS) $(SRCPATH)rembuff.c -I$(INCPATH)

addchar.o: $(SRCPATH)addchar.c $(INCPATH)addchar.h
	$(CC) $(CFLAGS) $(SRCPATH)addchar.c -I$(INCPATH)

remchar.o: $(SRCPATH)remchar.c $(INCPATH)remchar.h
	$(CC) $(CFLAGS) $(SRCPATH)remchar.c -I$(INCPATH)

stat.o: $(SRCPATH)stat.c $(INCPATH)stat.h
	$(CC) $(CFLAGS) $(SRCPATH)stat.c -I$(INCPATH)

resize.o: $(SRCPATH)resize.c $(INCPATH)resize.h
	$(CC) $(CFLAGS) $(SRCPATH)resize.c -I$(INCPATH)

clean:
	rm proj2 main.o help.o addbuff.o rembuff.o addchar.o remchar.o stat.o resize.o

unit:
	$(CC) -Wall -o unit $(UNITTESTPATH)unittest.c addbuff.o rembuff.o addchar.o remchar.o resize.o -lcunit

uclean:
	rm unit
