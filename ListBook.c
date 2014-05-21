/* Here will go the implementation of the List ADT. 
*  This ADT is an altered version of the List ADT I
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
	int data;
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

BookListHndl NewList () 
{
	BookListHndl tempList;
	tempList = malloc ( sizeof(BookListStruct) );
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->curr = NULL;
	/*printf(" New List created! \n ");*/
	return tempList;
}

void freeList (BookListHndl * L)
{
	BookNodePtr tempCurr;
	assert((*L) != NULL);
	/*FREE THE NODES! */
	tempCurr = (*(L))->first;
	(*(L))->curr = (*(L))->first;
	while((*(L))->curr != NULL)
	{
		tempCurr = (*(L))->curr->next;
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

int isEmpty(BookListHndl L) 
{
	assert (L != NULL);
	return (L->first == NULL);
}

int offEnd(BookListHndl L) 
{
	assert (L != NULL);
	return (L->curr == NULL);
}

int atFirst(BookListHndl L)
{
	assert (L != NULL);
	return ( (L->curr == L->first) && offEnd(L) == 1 );
}

int atLast(BookListHndl L)
{
	assert (L != NULL);
	return ( (L-> curr == L->last) && offEnd(L) == 1 );
}

int getFirst(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	return (L->first->data);
}

int getLast(BookListHndl L)
{
	assert (L != NULL);
	assert (L->last != NULL);
	return (L->last->data);
}
int getCurrent(BookListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	return (L->curr->data);
}

void insertAtFront(BookListHndl L, int data)
{
	BookNodePtr tempNode;
	assert (L != NULL);
	tempNode = malloc ( sizeof(struct BookNodeStruct) );

	tempNode->data = data;
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

	/*printf("Successfully inserted a new node in the front \n");*/
}

void insertAtBack (BookListHndl L, int data)
{
	BookNodePtr tempNode;
	assert (L != NULL);
	tempNode = malloc ( sizeof(struct BookNodeStruct) );
	
	tempNode->data = data;
	tempNode->next = NULL;
	tempNode->prev = L->last;
	
	if(L->last == NULL)
	/*this means we're adding the first element, meaning L needs to have curr, first, & last assigned.*/
	{
		L->last = tempNode;
		L->first = tempNode;
		L->curr = tempNode;
	}
	else
	{
		L->last->next = tempNode;
		L->last = tempNode;
	}

	/*printf("Successfully inserted a new node into the back \n");*/
}

void printList(BookListHndl L)
{
	BookNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	while(tempCurr != NULL)
	{
		printf("%d ", tempCurr->data);
		tempCurr = tempCurr->next;
	}
	printf("\n");
}

void printListFile(BookListHndl L, FILE *file)
{
	BookNodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	while(tempCurr != NULL)
	{
		fprintf(file, "%d ", tempCurr->data);
		tempCurr = tempCurr->next;
	}
	fprintf(file, "\n");
}  	

void makeEmpty(BookListHndl L)
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

void moveFirst(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr = L->first;
}

void moveLast(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr = L->last;
}

void movePrev(BookListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	L->curr = L->curr->prev;
} 

void moveNext(BookListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	L->curr = L->curr->next;
}

void insertBeforeCurrent(BookListHndl L, int data)
{
	BookNodePtr tempNode;
	assert (L != NULL);
	assert (L->curr != NULL);
	
	tempNode = malloc ( sizeof(struct BookNodeStruct) );
	
	tempNode->data = data;
	tempNode->next = L->curr;
	tempNode->prev = L->curr->prev;

	L->curr->prev = tempNode;
	if(L->first == L->curr)
	{
		L->first = tempNode;
	}
	else
	{
		tempNode->prev->next = tempNode;
	}

	/*printf("Successfully inserted a new node before the current node\n");*/
	
}

void deleteFirst(BookListHndl L)
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

void deleteLast(BookListHndl L)
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

void deleteCurrent(BookListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr->prev->next = L->curr->next;
	L->curr->next->prev = L->curr->prev;
	free (L->curr);
}
