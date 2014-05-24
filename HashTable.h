/* Here will go the prototype functions for the HashTable ADT */
#include "ListBook.h"
#include <stdio.h>


/*Declaration of the HashTableHndl empty pointer. Set it to null
 *when you first use it! */
typedef struct HashTableStruct * HashTableHndl;

/* makes the new hash table and puts an array of BookListHndls
*  of size size in the actual table */
HashTableHndl NewHashTable (int size);

/* frees the hash table and all structures within it*/
/* Pre: H is not NULL*/
void freeHashTable (HashTableHndl H);

/* Hashes based on the string and inserts it into the slot in the table*/
/* Pre: H is not NULL*/
void insertIntoHashTable (HashTableHndl H, char * title, int id);

/* uses the hash function to look up the right element, then prints it if 
* it is found*/
/* Pre: H is not NULL*/
void printTableElement (HashTableHndl H, char * title);