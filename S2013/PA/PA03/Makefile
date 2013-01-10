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
	@sort output033 > output033sorted
	@sort expected033 > expected033sorted
	@diff -w expected033sorted output033sorted

test1:
	@$(VALGRIND) --log-file=memoutput1 ./pa03 4 > output034
	@sort output034 > output034sorted
	@sort expected034 > expected034sorted
	@diff -w expected034sorted output034sorted

test2:
	@$(VALGRIND) --log-file=memoutput2 ./pa03 5 > output035
	@sort output035 > output035sorted
	@sort expected035 > expected035sorted
	@diff -w expected035sorted output035sorted
	
test3:
	@$(VALGRIND) --log-file=memoutput3 ./pa03 6 > output036
	@sort output036 > output036sorted
	@sort expected036 > expected036sorted
	@diff -w expected036sorted output036sorted
	
test4:
	@$(VALGRIND) --log-file=memoutput4 ./pa03 7 > output037
	@sort output037 > output037sorted
	@sort expected037 > expected037sorted
	@diff -w expected037sorted output037sorted
	
test5:
	@$(VALGRIND) --log-file=memoutput5 ./pa03 8 > output038
	@sort output038 > output038sorted
	@sort expected038 > expected038sorted
	@diff -w expected038sorted output038sorted

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa03 $(OBJS) output03* memoutput* *sorted





