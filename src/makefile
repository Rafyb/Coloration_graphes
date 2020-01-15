CC = gcc -Wall -Werror -W

test : test.o Graphe_c.o
	$(CC) -o test test.o Graphe_c.o

test.o : test.c Graphe_h.h
	$(CC) -c test.c

Graphe_c.o : Graphe_c.c Graphe_h.h
	$(CC) -c Graphe_c.c


clean:
	rm -f *.o
