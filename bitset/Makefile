all: bitset
	rm -f *.o

bitset: bitset.o
	g++ bitset.o -o bitset

bitset.o: bitset.cpp
	g++ -c bitset.cpp

clean:
	rm -f bitset
