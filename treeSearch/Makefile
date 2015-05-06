all: treeSearch
	rm -f *.o

treeSearch: treeSearch.o
	g++ treeSearch.o -o treeSearch

treeSearch.o: treeSearch.cpp
	g++ -c treeSearch.cpp

clean:
	rm -f treeSearch
