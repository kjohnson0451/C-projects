all: wordRank
	rm -f *.o

wordRank: wordRank.o
	gcc wordRank.o -o wordRank

wordRank.o: wordRank.c
	gcc -c wordRank.c

clean:
	rm -f wordRank
