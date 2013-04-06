GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = pa12.o bmp.o
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose --show-reachable=yes

pa12: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@ -lpthread
	
correct:
	perl grader.pl 4 2 8 1
	
perform:
	perl grader.pl 4 2 15 2

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o pa12 outputs/*
	
corrtest0: pa12
	$(VALGRIND) --log-file=outputs/memoutput0 ./pa12 /home/shay/a/ece264z7/PA12/inputs/image01.bmp  outputs/outputs01.bmp 1
	diff expected/expected01.bmp  outputs/outputs01.bmp

corrtest1: pa12
	$(VALGRIND) --log-file=outputs/memoutput1 ./pa12 /home/shay/a/ece264z7/PA12/inputs/image02.bmp  outputs/outputs02.bmp 2
	diff expected/expected02.bmp  outputs/outputs02.bmp

corrtest2: pa12
	$(VALGRIND) --log-file=outputs/memoutput2 ./pa12 /home/shay/a/ece264z7/PA12/inputs/image03.bmp  outputs/outputs03.bmp 4
	diff expected/expected03.bmp  outputs/outputs03.bmp

corrtest3: pa12
	$(VALGRIND) --log-file=outputs/memoutput3 ./pa12 /home/shay/a/ece264z7/PA12/inputs/image04.bmp  outputs/outputs04.bmp 6
	diff expected/expected04.bmp  outputs/outputs04.bmp
	
corrtest4: pa12
	$(VALGRIND) --log-file=outputs/memoutput4 ./pa12 /home/shay/a/ece264z7/PA12/inputs/image05.bmp  outputs/outputs05.bmp 8
	diff expected/expected05.bmp  outputs/outputs05.bmp

corrtest5: pa12
	$(VALGRIND) --log-file=outputs/memoutput5 ./pa12 /home/shay/a/ece264z7/PA12/inputs/image06.bmp  outputs/outputs06.bmp 11
	diff expected/expected06.bmp  outputs/outputs06.bmp
	
corrtest6: pa12
	$(VALGRIND) --log-file=outputs/memoutput6 ./pa12 /home/shay/a/ece264z7/PA12/inputs/image07.bmp  outputs/outputs07.bmp 13
	diff expected/expected07.bmp  outputs/outputs07.bmp

corrtest7: pa12
	$(VALGRIND) --log-file=outputs/memoutput7 ./pa12 /home/shay/a/ece264z7/PA12/inputs/image08.bmp  outputs/outputs08.bmp 16
	diff expected/expected08.bmp  outputs/outputs08.bmp
	
perftest0: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image01.bmp  /dev/null 4 > outputs/timeinfo0

perftest1: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image02.bmp  /dev/null 10 > outputs/timeinfo1

perftest2: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image03.bmp  /dev/null 20 > outputs/timeinfo2

perftest3: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image04.bmp  /dev/null 8 > outputs/timeinfo3

perftest4: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image05.bmp  /dev/null 16 > outputs/timeinfo4

perftest5: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image06.bmp  /dev/null 32 > outputs/timeinfo5

perftest6: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image07.bmp  /dev/null 2 > outputs/timeinfo6

perftest7: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image08.bmp  /dev/null 16 > outputs/timeinfo7

perftest8: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image11.bmp  /dev/null 64 > outputs/timeinfo8

perftest9: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image12.bmp  /dev/null 40 > outputs/timeinfo9

perftest10: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image13.bmp  /dev/null 24 > outputs/timeinfo10

perftest11: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image14.bmp  /dev/null 30 > outputs/timeinfo11

perftest12: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image15.bmp  /dev/null 56 > outputs/timeinfo12

perftest13: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image16.bmp  /dev/null 48 > outputs/timeinfo13

perftest14: pa12
	./pa12 /home/shay/a/ece264z7/PA12/inputs/image17.bmp  /dev/null 32 > outputs/timeinfo14

