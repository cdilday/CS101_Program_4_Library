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
	int i;
	HashTableHndl tempHndl;
	tempHndl = malloc(sizeof(HashTableStruct));
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
		freeBookList(&(H->table[i]));
	}
	free(H);
	H = NULL;
	/*printf( "Freed the Table! \n" );*/
}

/* HASHTABLE METHODS */

void insertIntoHashTable (HashTableHndl H, char * title, int id)
{
	assert (H != NULL);
	unsigned int hash;
	int c;
	char * tempTitle1;
	char * tempTitle2;
	tempTitle1 = malloc(sizeof(char) * 50);
	tempTitle2 = malloc(sizeof(char) * 50);
	
	strcpy(tempTitle1, title);
	strcpy(tempTitle2, tempTitle1);
	/*printf("trying to insert %s\n", title);
	//printf("with tempTitle %s\n", tempTitle);*/
	
	hash = 5381;
	while (c = *tempTitle2++)
		hash = ((hash << 5) + hash) + c;

	hash = hash % H->size;
	/*printf("trying to insert %s\n", title);*/
	insertBook((H->table)[hash], tempTitle1, id);
}

void printTableElement (HashTableHndl H, char * title)
{
	assert (H != NULL);
	unsigned int hash;
	int c;
	char * tempTitle1;
	char * tempTitle2;
	tempTitle1 = malloc(sizeof(char) * 50);
	tempTitle2 = malloc(sizeof(char) * 50);
	
	strcpy(tempTitle1, title);
	strcpy(tempTitle2, tempTitle1);

	hash = 5381;
	while (c = *tempTitle2++)
		hash = ((hash << 5) + hash) + c;

	hash = hash % H->size;
	if(!(isBookListEmpty((H->table)[hash])))
	{	
		moveFirstBookList((H->table)[hash]);
		while (!offEndBookList((H->table)[hash]))
		{
			if(strcmp(getTitleCurrent((H->table)[hash]), tempTitle1) == 0)
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
