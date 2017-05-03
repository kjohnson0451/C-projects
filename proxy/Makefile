all: proxy
	rm -f *.o

proxy: proxy.o
	g++ proxy.o -o proxy

proxy.o: proxy.cpp
	g++ -c proxy.cpp

clean:
	rm -f proxy
