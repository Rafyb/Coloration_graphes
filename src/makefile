CC = gcc -Wall -Werror -W 

test : test.o
	$(CC) -o test test.o

test.o : test.c
	$(CC) -c test.c


clean:
	rm -f *.o
