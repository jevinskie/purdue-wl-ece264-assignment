GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = tree.o pa09.o helper.o
HDRS = tree.h helper.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

pa09: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: $(HDRS)
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa09 $(OBJS) outputs/*

