all: inheritance
	rm -f *.o

inheritance: inheritance.o
	g++ inheritance.o -o inheritance

inheritance.o: inheritance.cpp
	g++ -c inheritance.cpp

clean:
	rm -f inheritance
