/* Here will go the implementation of the List ADT. 
*  This ADT is an altered version of the List ADT I
*  with Alex Vincent for Program 2. We are not working
*  together again, but that is why, if ours are similar,
*  they are so.*/

#include "List.h"
#include "myinclude.h"
#include <assert.h>

typedef struct NodeStruct * NodePtr;

typedef struct NodeStruct 
{
	void * data;
	struct NodeStruct* next;
	struct NodeStruct* prev;
} NodeStruct;

typedef struct ListStruct 
{
	NodePtr first;
	NodePtr last;
	NodePtr curr;
} ListStruct;

/* CONSTRUCTORS / DESTRUCTORS */

ListHndl NewList () 
{
	ListHndl tempList;
	tempList = malloc ( sizeof(ListStruct) );
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->curr = NULL;
	/*printf(" New List created! \n ");*/
	return tempList;
}

void freeList (ListHndl * L)
{
	NodePtr tempCurr;
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

int isEmpty(ListHndl L) 
{
	assert (L != NULL);
	return (L->first == NULL);
}

int offEnd(ListHndl L) 
{
	assert (L != NULL);
	return (L->curr == NULL);
}

int atFirst(ListHndl L)
{
	assert (L != NULL);
	return ( (L->curr == L->first) && offEnd(L) == 1 );
}

int atLast(ListHndl L)
{
	assert (L != NULL);
	return ( (L-> curr == L->last) && offEnd(L) == 1 );
}

long getFirst(ListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	return (L->first->data);
}

long getLast(ListHndl L)
{
	assert (L != NULL);
	assert (L->last != NULL);
	return (L->last->data);
}
long getCurrent(ListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	return (L->curr->data);
}

void insertAtFront(ListHndl L, long data)
{
	NodePtr tempNode;
	assert (L != NULL);
	tempNode = malloc ( sizeof(NodeStruct) );

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

void insertAtBack (ListHndl L, long data)
{
	NodePtr tempNode;
	assert (L != NULL);
	tempNode = malloc ( sizeof(NodeStruct) );
	
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

void printList(ListHndl L)
{
	NodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	while(tempCurr != NULL)
	{
		printf("%lu ", tempCurr->data);
		tempCurr = tempCurr->next;
	}
	printf("\n");
}

void printListFile(ListHndl L, FILE *file)
{
	NodePtr tempCurr;
	assert (L != NULL);
	tempCurr = L->first;
	while(tempCurr != NULL)
	{
		fprintf(file, "%lu ", tempCurr->data);
		tempCurr = tempCurr->next;
	}
	fprintf(file, "\n");
}  	

void makeEmpty(ListHndl L)
{
	NodePtr tempCurr;
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

void moveFirst(ListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr = L->first;
}

void moveLast(ListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr = L->last;
}

void movePrev(ListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	L->curr = L->curr->prev;
} 

void moveNext(ListHndl L)
{
	assert (L != NULL);
	assert (L->curr != NULL);
	L->curr = L->curr->next;
}

void insertBeforeCurrent(ListHndl L, long data)
{
	NodePtr tempNode;
	assert (L != NULL);
	assert (L->curr != NULL);
	
	tempNode = malloc ( sizeof(NodeStruct) );
	
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

void deleteFirst(ListHndl L)
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
		NodePtr tempCurr;
		tempCurr = L->first->next;
		free(L->first);
		L->first = tempCurr;
	}
	L->first->prev = NULL;
}

void deleteLast(ListHndl L)
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
		NodePtr tempCurr;
		tempCurr = L->last->prev;
		free(L->last);
		L->last = tempCurr;
	}
	L->last->next = NULL;
}

void deleteCurrent(ListHndl L)
{
	assert (L != NULL);
	assert (L->first != NULL);
	L->curr->prev->next = L->curr->next;
	L->curr->next->prev = L->curr->prev;
	free (L->curr);
}
