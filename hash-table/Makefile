all: test_dict
	rm -f *.o

test_dict: test_dict.o dict.o
	gcc test_dict.o dict.o -o test_dict

test_dict.o: test_dict.c
	gcc -g -c test_dict.c

dict.o: dict.c
	gcc -g -c dict.c

clean:
	rm -f test_dict
