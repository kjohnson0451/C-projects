all: uniqueChars
	rm -f *.o

uniqueChars: uniqueChars.o
	gcc uniqueChars.o -o uniqueChars

uniqueChars.o: uniqueChars.c
	gcc -c uniqueChars.c

clean:
	rm -f uniqueChars
