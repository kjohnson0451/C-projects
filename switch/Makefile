all: switch
	rm -f *.o

switch: switch.o
	gcc switch.o -o switch

switch.o: switch.c
	gcc -c switch.c

clean:
	rm -f switch
