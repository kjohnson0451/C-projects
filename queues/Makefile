all: queues
	rm -f *.o

queues: queues.o
	g++ queues.o -o queues

queues.o: queues.cpp
	g++ -c queues.cpp

clean:
	rm -f queues
