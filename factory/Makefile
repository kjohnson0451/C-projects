all: factory
	rm -f *.o

factory: factory.o
	g++ factory.o -o factory

factory.o: factory.cpp
	g++ -c factory.cpp

clean:
	rm -f factory
