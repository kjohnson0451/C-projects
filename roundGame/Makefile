all: roundGame
	rm -f *.o

roundGame: roundGame.o dict.o
	gcc roundGame.o dict.o -o roundGame

roundGame.o: roundGame.c
	gcc -g -c roundGame.c

dict.o: dict.c
	gcc -g -c dict.c

clean:
	rm -f roundGame
