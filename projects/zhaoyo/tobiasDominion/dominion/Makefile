CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

unittest1: dominion.o unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	gcov unittest1.c >> coverageReport.out

unittest2: dominion.o unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	gcov unittest2.c >> coverageReport.out

unittest3: dominion.o unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	gcov unittest3.c >> coverageReport.out

unittest4: dominion.o unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	gcov unittest4.c >> coverageReport.out

unittest5: dominion.o unittest5.c
	gcc -o unittest5 unittest5.c -g dominion.o rngs.o $(CFLAGS)
	gcov unittest5.c >> coverageReport.out

rand1: dominion.o randomtestcard1.c
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	gcov randomtestcard1 >> coverageReport.out

rand2: dominion.o randomtestcard2.c
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	gcov randomtestcard2 >> coverageReport.out

rand3: dominion.o randomtestcard3.c
	gcc -o randomtestcard3 randomtestcard3.c -g dominion.o rngs.o $(CFLAGS)
	gcov randomtestcard3 >> coverageReport.out

alltest: unittest1 unittest2 unittest3 unittest4 unittest4 unittest5 randomtestcard1 randomtestcard2 randomtestcard3

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 unittest5 randomtestcard1 randomtestcard2 randomtestcard3
