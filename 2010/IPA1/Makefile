# do not change this file
#
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

ipa1: ipa1.c
	$(CC) ipa1.c -o ipa1

test: ipa1
	./ipa1 input1 > output1
	./ipa1 input2 > output2
	./ipa1 input3 > output3
	./ipa1 input4 > output4
	./ipa1 input5 > output5

memory: ipa1
	$(VALGRIND) --log-file=vallog1 ./ipa1 input1 > leakoutput1 
	$(VALGRIND) --log-file=vallog2 ./ipa1 input2 > leakoutput2
	$(VALGRIND) --log-file=vallog3 ./ipa1 input3 > leakoutput3
	$(VALGRIND) --log-file=vallog4 ./ipa1 input4 > leakoutput4
	$(VALGRIND) --log-file=vallog5 ./ipa1 input5 > leakoutput5

clean:
	/bin/rm -f ipa1
	/bin/rm -f output*
	/bin/rm -f vallog*
	/bin/rm -f leakoutput*

cleanall: clean
	/bin/rm -f input?
