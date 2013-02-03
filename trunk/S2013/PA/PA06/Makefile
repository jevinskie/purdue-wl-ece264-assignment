GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer06.o pa06.o
HDRS = pa06.h
VALGRIND = valgrind --leak-check=full --verbose

pa06: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

test: pa06
	./pa06 inputs/input01 outputs/output01ID outputs/output01Name
	./pa06 inputs/input02 outputs/output02ID outputs/output02Name
	./pa06 inputs/input03 outputs/output03ID outputs/output03Name
	./pa06 inputs/input04 outputs/output04ID outputs/output04Name
	diff -w outputs/output01ID expected/expected01ID
	diff -w outputs/output02ID expected/expected02ID
	diff -w outputs/output03ID expected/expected03ID
	diff -w outputs/output04ID expected/expected04ID
	diff -w outputs/output01Name expected/expected01Name
	diff -w outputs/output02Name expected/expected02Name
	diff -w outputs/output03Name expected/expected03Name
	diff -w outputs/output04Name expected/expected04Name
	$(VALGRIND) ./pa06 inputs/input07 outputs/output07ID outputs/output07Name

clean:
	rm -f pa06 $(OBJS) outputs/*





