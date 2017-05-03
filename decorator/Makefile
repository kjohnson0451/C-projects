all: decorator
	rm -f *.o

decorator: decorator.o
	g++ decorator.o -o decorator

decorator.o: decorator.cpp
	g++ -c decorator.cpp

clean:
	rm -f decorator
