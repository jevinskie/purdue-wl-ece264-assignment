# create the executable file, type "make"
# 
# delete the executable, type "make clean"
# When you use a different machine, please type "make clean" to remove
# existing object files first.
#
# test the program, type "make test"
#
# detect memory leak, type "make memory"
# 
# type "make cleanall" before submission. This will remove all test inputs.
#

CC = gcc -g -Wall -Wshadow
VALGRIND = valgrind --leak-check=yes

ipa2: ipa2.c student.c
	$(CC) ipa2.c student.c -I. -o ipa2

test: ipa2
	./ipa2 input1 > output1
	./ipa2 input2 > output2
	./ipa2 input3 > output3
	./ipa2 input4 > output4
	./ipa2 input5 > output5

memory: ipa2
	$(VALGRIND) --log-file=vallog1 ./ipa2 input1 > leakoutput1 
	$(VALGRIND) --log-file=vallog2 ./ipa2 input2 > leakoutput2
	$(VALGRIND) --log-file=vallog3 ./ipa2 input3 > leakoutput3
	$(VALGRIND) --log-file=vallog4 ./ipa2 input4 > leakoutput4
	$(VALGRIND) --log-file=vallog5 ./ipa2 input5 > leakoutput5

clean:
	/bin/rm -f ipa2
	/bin/rm -f output*
	/bin/rm -f vallog*
	/bin/rm -f leakoutput*

cleanall: clean
	/bin/rm -f input?
