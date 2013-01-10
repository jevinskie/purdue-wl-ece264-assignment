GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer03.o pa03.o
HDRS = pa03.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

.PHONY : clean test0 test1 test2 test3 test4 test5
pa03: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	perl grader.pl 5 2

test0:
	@$(VALGRIND) --log-file=memoutput0 ./pa03 3 > output033
	./pa03 3 > output033
	diff -w expected033 output033

test1:
	@$(VALGRIND) --log-file=memoutput1 ./pa03 4 > output034
	./pa03 4 > output034
	diff -w expected034 output034

test2:
	@$(VALGRIND) --log-file=memoutput2 ./pa03 5 > output035
	./pa03 5 > output035
	diff -w expected035 output035
	
test3:
	@$(VALGRIND) --log-file=memoutput3 ./pa03 6 > output036
	./pa03 6 > output036
	diff -w expected036 output036
	
test4:
	@$(VALGRIND) --log-file=memoutput4 ./pa03 7 > output037
	./pa03 7 > output037
	diff -w expected037 output037
	
test5:
	@$(VALGRIND) --log-file=memoutput5 ./pa03 8 > output038
	./pa03 8 > output038
	diff -w expected038 output038

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa03 $(OBJS) output03*





