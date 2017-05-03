all: builder
	rm -f *.o

builder: builder.o
	g++ builder.o -o builder

builder.o: builder.cpp
	g++ -c builder.cpp

clean:
	rm -f builder
