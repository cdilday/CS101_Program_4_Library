/* Here will go the implementation of the BookList ADT. 
*  This ADT is an altered version of the List ADT I made
*  with Alex Vincent for Program 2. We are not working
*  together again, but that is why, if ours are similar,
*  they are so.*/

#include "ListBook.h"
#include "ListInt.h"
#include "myinclude.h"
#include <assert.h>

typedef struct BookNodeStruct * BookNodePtr;

typedef struct BookNodeStruct 
{
	char * title;
	IntListHndl bookIDs;
	struct BookNodeStruct* next;
	struct BookNodeStruct* prev;
} BookNodeStruct;

typedef struct BookListStruct 
{
	BookNodePtr first;
	BookNodePtr last;
	BookNodePtr curr;
} BookListStruct;

/* CONSTRUCTORS / DESTRUCTORS */

BookListHndl NewBookList () 
{
	BookListHndl tempList;
	tempList = malloc ( sizeof(BookListStruct) );
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->curr = NULL;
	/*printf(" New List created! \n ");*/
	return tempList;
}

void freeBookList (BookListHndl * L)
{
	BookNodePtr tempCurr;
	assert((*L) != NULL);
	/*FREE THE NODES! */
	tempCurr = (*(L))->first;
	(*(L))->curr = (*(L))->first;
	while((*(L))->curr != NULL)
	{
		tempCurr = (*(L))->curr->next;
		freeList(&((*L)->curr->bookIDs));
		free((*(L))->curr); 
		(*(L))->curr = tempCurr;
	}
	(*(L))->first = NULL;
	(*(L))->curr = NULL;
	(*(L))->last = NULL;
	free((*L));
	(*L) = NULL;
	/*printf( "Freed the list! \n" );*/
}

int isBookListEmpty(BookListHndl L) 
{
	assert (L != NULL);
	return (L->first == NULL);
}

int offEndBookList(BookListHndl L) 
{
	assert (L != NULL);
	return (L->curr == NULL);
}

int atFirstBookList(BookListHndl L)
{
	assert (L != NULL);
	return ( (L->curr == L->first) && offEndBookList(L) == 1 );
}

int atLastBookList(BookListHndl L)
{
	assert (L != NULL);
	return ( (L-> curr == L->last) && offEndBookList(L) == 1 );
}

char * getTitleFirst(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	return (L->first->title);
}

char * getTitleLast(BookListHndl L)
{
	assert (L != NULL);
	assert (L->last != NULL);
	return (L->last->title);
}
char * getTitleCurrent(BookListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	return (L->curr->title);
}

IntListHndl * getIDsFirst(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	return (L->first->bookIDs);
}

IntListHndl * getIDsLast(BookListHndl L)
{
	assert (L != NULL);
	assert (L->last != NULL);
	return (L->last->bookIDs);
}
IntListHndl * getIDsCurrent(BookListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	return (L->curr->bookIDs);
}

void insertBook(BookListHndl L, char * title, int id)
{

	BookNodePtr tempNode;
	char * tempTitle;
	assert (L != NULL);
	tempTitle = malloc(sizeof(char) * 50);
	
	strcpy(tempTitle, title);
	
	if(L->first != NULL)
	{
		L->curr = L->first;
		while (L->curr != NULL)
		{
		/*printf("comparing %s and %s, which gives %d\n", L->curr->title, title, strcmp(L->curr->title, tempTitle) );*/
			if(strcmp(L->curr->title, tempTitle) == 0)
			{
				insertID(L, id);
				L->curr = L->first;
				return;
			}
			L->curr = L->curr->next;
		}
	}
	L->curr = L->first;
	
	tempNode = malloc ( sizeof(struct BookNodeStruct) );

	tempNode->title = malloc ( sizeof(char) * 50 );
	strcpy(tempNode->title, tempTitle);
	tempNode->bookIDs = NewList();
	insertAtFront(tempNode->bookIDs, id);
	tempNode->next = L->first;
	tempNode->prev = NULL;

	if(L->first == NULL)
	/*this means we're adding the first element, meaning L needs to have curr, first, & last assigned.*/
	{ 
		L->first = tempNode;
		L->last = tempNode;
		L->curr = tempNode;
	}
	else
	{
		L->first->prev = tempNode;
		L->first = tempNode;
	}
	L->curr = L->first;
	/*printf("Successfully inserted a new node in the front \n");*/
}

void insertID(BookListHndl L, int id)
{
	assert (L != NULL);
	insertAtBack(L->curr->bookIDs, id);
}

void printBookList(BookListHndl L)
{
	BookNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	while(tempCurr != NULL)
	{
		printList(tempCurr->bookIDs);
		tempCurr = tempCurr->next;
	}
	printf("\n");
}

void printBookListFile(BookListHndl L, FILE *file)
{
	BookNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	while(tempCurr != NULL)
	{
		fprintf(file, "%s ", tempCurr->title);
		printListFile(tempCurr->bookIDs, file);
		tempCurr = tempCurr->next;
	}
	fprintf(file, "\n");
}  	

void printCurrentIDs(BookListHndl L)
{
	assert (L != NULL);
	printList(L->curr->bookIDs);
}

void makeBookListEmpty(BookListHndl L)
{
	BookNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	L->curr = L->first;
	while(L->curr != NULL)
	{
		tempCurr = L->curr->next;
		free(L->curr); 
		L->curr = tempCurr;
	}
	L->first = NULL;
	L->curr = NULL;
	L->last = NULL;
	
	/*printf("The list is now empty\n");*/
}

void moveFirstBookList(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr = L->first;
}

void moveLastBookList(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr = L->last;
}

void movePrevBookList(BookListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	L->curr = L->curr->prev;
} 

void moveNextBookList(BookListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	L->curr = L->curr->next;
}

void deleteFirstBook(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	
	if(L->curr == L->first)
	{
		L->curr = L->first->next;
		free (L->first);
		L->first = L->curr;
	}
	else
	{
		BookNodePtr tempCurr;
		tempCurr = L->first->next;
		free(L->first);
		L->first = tempCurr;
	}
	L->first->prev = NULL;
}

void deleteLastBook(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	
	if(L->curr == L->last)
	{
		L->curr = L->last->prev;
		free (L->last);
		L->last = L->curr;
	}
	else
	{
		BookNodePtr tempCurr;
		tempCurr = L->last->prev;
		free(L->last);
		L->last = tempCurr;
	}
	L->last->next = NULL;
}

void deleteCurrentBook(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr->prev->next = L->curr->next;
	L->curr->next->prev = L->curr->prev;
	free (L->curr);
}
