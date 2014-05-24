# Makefile for Library and drivers for IntList, BookList, and Hashtable modules - by Chris Dilday

ListIntdr : ListIntdr.o ListInt.o
	gcc -ansi -Wall -Wextra -pedantic -o ListIntdr ListIntdr.o ListInt.o
	
ListBookdr : ListBookdr.o ListBook.o ListInt.o
	gcc -ansi -Wall -Wextra -pedantic -o ListBookdr ListBookdr.o ListBook.o ListInt.o
	
HashTabledr : HashTabledr.o ListBook.o ListInt.o HashTable.o
	gcc -ansi -Wall -Wextra -pedantic -o HashTabledr HashTabledr.o ListBook.o ListInt.o HashTable.o
	
HashTable.o : HashTable.h HashTable.c ListBook.h ListBook.c ListInt.h ListInt.c
	gcc -c -ansi -Wall -Wextra -pedantic ListBook.c ListInt.c HashTable.c
	
ListInt.o : ListInt.h ListInt.c
	gcc -c -ansi -Wall -Wextra -pedantic ListInt.c
	
ListBook.o : ListBook.h ListBook.c ListInt.h ListInt.c
	gcc -c -ansi -Wall -Wextra -pedantic ListBook.c ListInt.c

ListIntdr.o : ListInt.h ListIntdr.c
	gcc -c -ansi -Wall -Wextra -pedantic ListIntdr.c	

ListBookdr.o : ListBook.h ListInt.h ListBookdr.c
	gcc -c -ansi -Wall -Wextra -pedantic ListBookdr.c	

clean :
	rm ListInt.o ListIntdr ListIntdr.o ListBook.o ListBookdr ListBookdr.o HashTabledr HashTable.o
