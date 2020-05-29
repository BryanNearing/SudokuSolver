CC = gcc
CFLAGS= -ggdb -Wall -pedantic -std=c11

solver : solver.c
	gcc -o solver solver.c

clean:
	rm *.o source core
