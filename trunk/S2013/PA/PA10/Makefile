GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = tree.o pa10.o
HDRS = tree.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

pa10: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

gentree: tree.o pa10.o tree.h
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: $(HDRS)
	$(GCC) $(CFLAGS) -c $*.c
	
grade:
	perl grader.pl 4 2 12

test0: pa10
	@$(VALGRIND) --log-file=outputs/memoutput0 ./pa10 inputs/input0 > outputs/output0
	diff -w outputs/output0 expected/expected0

test1: pa10
	@$(VALGRIND) --log-file=outputs/memoutput1 ./pa10 inputs/input1 > outputs/output1
	diff -w outputs/output1 expected/expected1

test2: pa10
	@$(VALGRIND) --log-file=outputs/memoutput2 ./pa10 inputs/input2 > outputs/output2
	diff -w outputs/output2 expected/expected2

test3: pa10
	@$(VALGRIND) --log-file=outputs/memoutput3 ./pa10 inputs/input3 > outputs/output3
	diff -w outputs/output3 expected/expected3

test4: pa10
	@$(VALGRIND) --log-file=outputs/memoutput4 ./pa10 inputs/input4 > outputs/output4
	diff -w outputs/output4 expected/expected4

test5: pa10
	@$(VALGRIND) --log-file=outputs/memoutput5 ./pa10 inputs/input5 > outputs/output5
	diff -w outputs/output5 expected/expected5

test6: pa10
	@$(VALGRIND) --log-file=outputs/memoutput6 ./pa10 inputs/input6 > outputs/output6
	diff -w outputs/output6 expected/expected6

test7: pa10
	@$(VALGRIND) --log-file=outputs/memoutput7 ./pa10 inputs/input7 > outputs/output7
	diff -w outputs/output7 expected/expected7

test8: pa10
	@$(VALGRIND) --log-file=outputs/memoutput8 ./pa10 inputs/input8 > outputs/output8
	diff -w outputs/output8 expected/expected8

test9: pa10
	@$(VALGRIND) --log-file=outputs/memoutput9 ./pa10 inputs/input9 > outputs/output9
	diff -w outputs/output9 expected/expected9

test10: pa10
	@$(VALGRIND) --log-file=outputs/memoutput10 ./pa10 inputs/input10 > outputs/output10
	diff -w outputs/output10 expected/expected10

test11: pa10
	@$(VALGRIND) --log-file=outputs/memoutput11 ./pa10 inputs/input11 > outputs/output11
	diff -w outputs/output11 expected/expected11
	
clean:
	rm -f pa10 $(OBJS) outputs/*
