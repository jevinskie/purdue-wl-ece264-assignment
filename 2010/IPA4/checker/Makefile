CC = gcc
CFLAGS = -g -Wall -Wshadow
CHECKERFLAGS = -L. -lllist
CHECKERSRC = checker.c
CHECKER = ipa4check

checker:
	$(CC) $(CFLAGS) -static $(CHECKERSRC) $(CHECKERFLAGS) -o $(CHECKER)

clean: FORCE
	rm *.o *~ $(CHECKER)

FORCE: