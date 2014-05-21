# Makefile for List module - by Alex Vincent / Chris Dilday

#store : store.o List.o
#	gcc -ansi -Wall -Wextra -pedantic -o store store.o List.o

ListIntdr : ListIntdr.o ListInt.o
	gcc -ansi -Wall -Wextra -pedantic -o ListIntdr ListIntdr.o ListInt.o
	
ListInt.o : ListInt.h ListInt.c
	gcc -c -ansi -Wall -Wextra -pedantic ListInt.c

#store.o : List.h store.c
#	gcc -c -ansi -Wall -Wextra -pedantic store.c

ListIntdr.o : ListInt.h ListIntdr.c
	gcc -c -ansi -Wall -Wextra -pedantic ListIntdr.c	

clean :
	rm store store.o ListInt.o ListIntdr ListIntdr.o output.txt
