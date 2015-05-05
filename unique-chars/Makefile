all: unique-chars
	rm -f *.o

unique-chars: unique-chars.o
	gcc unique-chars.o -o unique-chars

unique-chars.o: unique-chars.c
	gcc -c unique-chars.c

clean:
	rm -f unique-chars
