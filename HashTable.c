/* Here will go the implementation of the HashTable ADT. */

#include "ListBook.h"
#include "HashTable.h"
#include "myinclude.h"
#include <assert.h>

typedef struct HashTableStruct 
{
	BookListHndl *table;
	int size;
} HashTableStruct;

/* CONSTRUCTORS / DESTRUCTORS */

HashTableHndl NewHashTable (int size) 
{
	HashTableHndl tempHndl;
	tempHndl->table = NULL;
	int i;
	printf("1\n");
	tempHndl->size = size;
	printf("%d\n", tempHndl->size);
	BookListHndl tempTable[size];
	printf("2\n");
	for( i = 0; i < size; i++)
	{
		tempTable[i] = NewBookList();
		printf("%d\n", i);
	}
	printf("3\n");
	tempHndl->table = malloc ( sizeof(tempTable) );
	printf("4\n");
	tempHndl->table = &tempTable;
	
	printf("5\n");
	return tempHndl;
}

void freeHashTable (HashTableHndl H)
{
	int i;
	assert(H != NULL);

	for( i = 0; i < H->size; i++)
	{
		freeBookList(H->table[i]);
	}
	free(H);
	H = NULL;
	/*printf( "Freed the Table! \n" );*/
}

/* HASHTABLE METHODS */

void insertIntoHashTable (HashTableHndl H, char * title, int id)
{
	assert (H != NULL);
	unsigned int hash = 5381;
	int c;

	while (c = *title++)
		hash = ((hash << 5) + hash) + c;

	hash = hash % H->size;
	printf("%d\n", hash);
	
	insertBookAtFront(&(H->table)[hash], title, id);
	printf("%s\n", getTitleFirst(H->table[hash]));
}

void printTableElement (HashTableHndl H, char * title)
{
	assert (H != NULL);
	unsigned int hash = 5381;
	int c;

	while (c = *title++)
		hash = ((hash << 5) + hash) + c;

	hash = hash % H->size;
	printf("%d\n", hash);
	
	printBookList(&(H->table[hash]));
}