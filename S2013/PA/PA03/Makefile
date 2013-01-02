GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer03.o pa03.o
HDRS = pa03.h

pa03: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	./pa03 3 > output033
	./pa03 4 > output034
	./pa03 5 > output035
	./pa03 6 > output036
	./pa03 7 > output037
	./pa03 8 > output038
	valgrind --leak-check=full --verbose ./pa03 6

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa03 $(OBJS) output03*





