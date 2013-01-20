GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer04.o pa04.o
HDRS = pa04.h

pa04: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

testc: pa04
	./pa04 c inputs/input_article0 outputs/output_c0
	./pa04 c inputs/input_article1 outputs/output_c1
	./pa04 c inputs/input_article2 outputs/output_c2
	./pa04 c inputs/input_article3 outputs/output_c3
	diff -w outputs/output_c0 expected/expected_c0
	diff -w outputs/output_c1 expected/expected_c1
	diff -w outputs/output_c2 expected/expected_c2
	diff -w outputs/output_c3 expected/expected_c3

tests: pa04
	./pa04 s inputs/input_article0 outputs/output_str00 Aa
	./pa04 s inputs/input_article0 outputs/output_str01 bB
	./pa04 s inputs/input_article1 outputs/output_str10 Elec
	./pa04 s inputs/input_article1 outputs/output_str11 eng
	./pa04 s inputs/input_article1 outputs/output_str12 ing
	./pa04 s inputs/input_article1 outputs/output_str13 USA
	./pa04 s inputs/input_article2 outputs/output_str20 ing
	./pa04 s inputs/input_article2 outputs/output_str21 circuit
	./pa04 s inputs/input_article3 outputs/output_str30 computer
	./pa04 s inputs/input_article3 outputs/output_str31 int
	diff -w  outputs/output_str00 expected/expected_str00
	diff -w  outputs/output_str01 expected/expected_str01
	diff -w  outputs/output_str10 expected/expected_str10
	diff -w  outputs/output_str11 expected/expected_str11
	diff -w  outputs/output_str12 expected/expected_str12
	diff -w  outputs/output_str13 expected/expected_str13
	diff -w  outputs/output_str20 expected/expected_str20
	diff -w  outputs/output_str21 expected/expected_str21
	diff -w  outputs/output_str30 expected/expected_str30
	diff -w  outputs/output_str31 expected/expected_str31

testp: pa04
	./pa04 p inputs/input_pal0 outputs/output_pal0
	./pa04 p inputs/input_pal1 outputs/output_pal1
	./pa04 p inputs/input_pal2 outputs/output_pal2
	./pa04 p inputs/input_pal3 outputs/output_pal3
	diff -w  outputs/output_pal0 expected/expected_pal
	diff -w  outputs/output_pal1 expected/expected_pal
	diff -w  outputs/output_pal2 expected/expected_pal
	diff -w  outputs/output_pal3 expected/expected_pal
	./pa04 p inputs/input_nonpal0 outputs/output_nonpal0
	./pa04 p inputs/input_nonpal1 outputs/output_nonpal1
	./pa04 p inputs/input_nonpal2 outputs/output_nonpal2
	./pa04 p inputs/input_nonpal3 outputs/output_nonpal3
	diff -w  outputs/output_nonpal0 expected/expected_nonpal
	diff -w  outputs/output_nonpal1 expected/expected_nonpal
	diff -w  outputs/output_nonpal2 expected/expected_nonpal
	diff -w  outputs/output_nonpal3 expected/expected_nonpal

clean:
	rm -f pa04 $(OBJS) outputs/*





