# We recommend you to read an online manual before making changes
# to this Makefile:
#
# http://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_mono/make.html

CC = gcc
CFLAGS = -Wall -Wshadow
CFILES = linklist.c stack.c maze.c main.c solver.c
OBJFILES = linklist.o stack.o maze.o main.o solver.o
EXECUTABLE = ipa3

main: $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJFILES)

.o: $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

cleanall:
	rm $(OBJFILES) $(EXECUTABLE) *~

clean:
	rm $(OBJFILES) *~