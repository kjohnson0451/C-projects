all: polymorphism
	rm -f *.o

polymorphism: polymorphism.o
	g++ polymorphism.o -o polymorphism

polymorphism.o: polymorphism.cpp
	g++ -c polymorphism.cpp

clean:
	rm -f polymorphism
