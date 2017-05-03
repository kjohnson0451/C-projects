all: singleton
	rm -f *.o

singleton: singleton.o
	g++ singleton.o -o singleton

singleton.o: singleton.cpp
	g++ -c singleton.cpp

clean:
	rm -f singleton
