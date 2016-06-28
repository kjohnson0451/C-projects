all: bitwise
	rm -f *.o

bitwise: bitwise.o 
	gcc bitwise.o -o bitwise

bitwise.o: bitwise.c
	gcc -c bitwise.c

clean:
	rm -f bitwise
