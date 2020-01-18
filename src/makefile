target : main \
		 	 	 clean

CC = gcc -Wall -Werror -W

main : main.o Graphe_c.o utils_c.o graphe/Coloration_c.o
	$(CC) -o main main.o Graphe_c.o utils_c.o graphe/Coloration_c.o

main.o : test/main.c graphe/Graphe_h.h
	$(CC) -c test/main.c

Graphe_c.o : graphe/Graphe_c.c graphe/Graphe_h.h
	$(CC) -c graphe/Graphe_c.c

utils_c.o : liste/utils_c.c liste/utils_h.h
		$(CC) -c liste/utils_c.c

Coloration_c.o : graphe/Coloration_c.c graphe/Coloration_h.h liste/utils_h.h graphe/Graphe_h.h
		$(CC) -c graphe/Coloration_c.c



clean:
	rm -f *.o
