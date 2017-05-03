all: negative
	rm -f *.o

negative: negative.o
	g++ negative.o -o negative

negative.o: negative.cpp
	g++ -c negative.cpp

clean:
	rm -f negative
