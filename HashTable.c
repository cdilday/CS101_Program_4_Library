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
	tempHndl = malloc(sizeof(HashTableStruct));
	int i;
	tempHndl->size = size;
	tempHndl->table = malloc(size * sizeof(BookListHndl));
	for( i = 0; i < size; i++)
	{
		tempHndl->table[i] = NewBookList();
	}
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

	if(!isEmpty((H->table)[hash]))
	{
		moveFirstBookList((H->table)[hash]);
		while (!offEndBookList((H->table)[hash]))
		{
			if(strcmp(getTitleCurrent((H->table)[hash]), title) == 0)
			{
				insertID((H->table)[hash], id);
				return;
			}
			moveNextBookList((H->table)[hash]);
		}
	}
	
	insertBookAtFront((H->table)[hash], title, id);
	moveFirstBookList((H->table)[hash]);
}

void printTableElement (HashTableHndl H, char * title)
{
	assert (H != NULL);
	unsigned int hash = 5381;
	int c;

	while (c = *title++)
		hash = ((hash << 5) + hash) + c;

	hash = hash % H->size;
	if(!(isBookListEmpty((H->table)[hash])))
	{	
		moveFirstBookList((H->table)[hash]);
		while (!offEndBookList((H->table)[hash]))
		{
			if(strcmp(getTitleCurrent((H->table)[hash]), title) == 0)
			{
				printCurrentIDs((H->table)[hash]);
				moveFirstBookList((H->table)[hash]);
				return;
			}
			moveNextBookList((H->table)[hash]);
		}
	}
	moveFirstBookList((H->table)[hash]);
	printf("\n");
}
