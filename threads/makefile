all: threads threads_args
	rm -f *.o

threads: threads.o
	g++ threads.o -o threads -lpthread

threads.o: threads.cpp
	g++ -c threads.cpp -lpthread

threads_args: threads_args.o
	g++ threads_args.o -o threads_args -lpthread

threads_args.o: threads_args.cpp
	g++ -c threads_args.cpp -lpthread

clean:
	rm -f threads threads_args
