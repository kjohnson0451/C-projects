all: printVectorCombinations
	rm -f *.o

printVectorCombinations: printVectorCombinations.o
	g++ printVectorCombinations.o -o printVectorCombinations

printVectorCombinations.o: printVectorCombinations.cpp
	g++ -c printVectorCombinations.cpp

clean:
	rm -f printVectorCombinations
