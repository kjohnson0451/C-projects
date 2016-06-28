all: mutex
	rm -f *.o

mutex: mutex.o
	g++ mutex.o -o mutex

mutex.o: mutex.cpp
	g++ -c mutex.cpp

clean:
	rm -f mutex
