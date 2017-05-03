all: intToDouble
	rm -f *.o

intToDouble: intToDouble.o
	g++ intToDouble.o -o intToDouble

intToDouble.o: intToDouble.cpp
	g++ -c intToDouble.cpp

clean:
	rm -f intToDouble
