# Makefile for List module - by Alex Vincent / Chris Dilday

store : store.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o store store.o List.o

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o Listdr Listdr.o List.o
	
List.o : List.h List.c
	gcc -c -ansi -Wall -Wextra -pedantic List.c

store.o : List.h store.c
	gcc -c -ansi -Wall -Wextra -pedantic store.c

Listdr.o : List.h Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic Listdr.c	

clean :
	rm store store.o List.o Listdr Listdr.o output.txt
