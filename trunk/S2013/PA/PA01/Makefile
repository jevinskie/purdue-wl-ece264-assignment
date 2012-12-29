GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer01.o pa01.o
HDRS = pa01.h

pa01: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@
	valgrind --leak-check=full --verbose ./pa01 input0 > output0
	./pa01 input0 > output0
	diff output0 expected0
	./pa01 input1 > output1
	diff output1 expected1
	./pa01 input2 > output2
	diff output2 expected2
	./pa01 input3 > output3
	diff output3 expected3
	./pa01 input4 > output4
	diff output4 expected4
	./pa01 input5 > output5
	diff output5 expected5
	./pa01 input6 > output6
	diff output6 expected6
	./pa01 input7 > output7
	diff output7 expected7
	./pa01 input8 > output8
	diff output8 expected8
	./pa01 input9 > output9
	diff output9 expected9
	./pa01 input10 > output10
	diff output10 expected10
	./pa01 input11 > output11
	diff output11 expected11
	./pa01 input12 > output12
	diff output12 expected12
	./pa01 input13 > output13
	diff output13 expected13
	./pa01 input14 > output14
	diff output14 expected14
	./pa01 input15 > output15
	diff output15 expected15
	./pa01 input16 > output16
	diff output16 expected16
	./pa01 input17 > output17
	diff output17 expected17
	./pa01 input18 > output18
	diff output18 expected18
	./pa01 input19 > output19
	diff output19 expected19

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

gen: inputgen.c
	$(GCC) $(CFLAGS) inputgen.c -o inputgen
	./inputgen

clean:
	rm -f pa01 inputgen $(OBJS) output*



