/* Here will go the implementation of the List ADT. 
*  This ADT is an altered version of the List ADT I
*  with Alex Vincent for Program 2. We are not working
*  together again, but that is why, if ours are similar,
*  they are so.*/

#include "ListBook.h"
#include "ListInt.h"
#include "HashTable.h"
#include "myinclude.h"
#include <assert.h>

typedef struct HashTableStruct 
{
	BookListHndl (*table)[];
	int size;
} HashTableStruct;

/* CONSTRUCTORS / DESTRUCTORS */

HashTableHndl NewHashTable (int size) 
{
	HashTableHndl tempHndl;
	int i;
	BookListHndl (*tempTable)[size];
	tempTable = malloc ( sizeof(tempTable) );
	for( i = 0; i < size; i++)
	{
		tempTable[i] = NewBookList();
	}
	
	tempHdnle->table = tempTable;
	tempHndle->size = size;
	/*printf(" New List created! \n ");*/
	return tempTable;
}

void freeHashTable (HashTableHndl * H)
{
int i;
	assert((*H) != NULL);
	/*FREE THE TABLE ELEMENTS! */

	for( i = 0; i < (*H)->size; i++)
	{
		freeBookList(*H)->table[i];
	}
	free((*H));
	(*H) = NULL;
	/*printf( "Freed the Table! \n" );*/
}

