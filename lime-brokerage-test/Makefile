all: bracesClosing
	rm -f *.o

bracesClosing: bracesClosing.o
	g++ bracesClosing.o -o bracesClosing

bracesClosing.o: bracesClosing.cpp
	g++ -c bracesClosing.cpp

clean:
	rm -f bracesClosing
