/* Here will go the prototype functions for the List ADT 
*  This is identical to the List ADT file Alex Vincent and
*  I used for Program 2 since none of it needs to be changed*/
#include <stdio.h>


/*Declaration of the ListHandle empty pointer. Set it to null
 *when you first use it! */
typedef struct ListStruct * ListHndl;

/* This function will allocate memory for a new list, returning
 *a POINTER to the thing allocated */
ListHndl NewList ();

/* This function ACCEPTS a pointer to a ListHandle and will free
 * every Node in the list, as well as the list itself. */
void freeList (ListHndl* L); /*Pre condition -> L was made with NewList*/

/* This checks to see whether the ListStruct points to any struct nodes. 
 * If it points to anything NOT null, it will return 1. 
 * If it all it points to are NULL things, it will return 0. */
int isEmpty (ListHndl L);

/*Returns 0 if the current pointer is not on the list (aka pointing to null) */
int offEnd (ListHndl L);

/* Returns 0 if the curr pointer is pointing to first, also !offEnd() */
int atFirst(ListHndl L);

/* Return 0 if the curr pointer is pointing to last, also !offEnd() */
int atLast (ListHndl L);

/* Returns the data (number) from the node without altering the function */
int getFirst(ListHndl L);
int getLast(ListHndl L);
int getCurrent(ListHndl L);

/* Inserts something into the beginning of the list, curr stays the same! */
void insertAtFront(ListHndl L, int data);

/*Inserts something into the end of the list, curr stays the same! */
void insertAtBack(ListHndl L, int data);

/* Prints out the entire list to STDOUT, 
 * make sure to change it to print to a file - special case when list is empty*/
void printList(ListHndl L);

/* Prints entire list to A FILE*/
void printListFile(ListHndl L, FILE *file);
/*Makes the list empty by going through and freeing nodes. Sets first, curr, and last to null*/
void makeEmpty(ListHndl L);

/*points the curr pointer to the first element*/
void moveFirst(ListHndl L);

/*points the curr pointer to the last element*/
void moveLast(ListHndl L);

/*Moves the current marker to the previous element*/
void movePrev(ListHndl L);

/*Moves the current marker to the next element*/
void moveNext(ListHndl L);

/*Inserts a new node before the current node*/
void insertBeforeCurrent(ListHndl L, int data);

/*Deletes the first element in the list*/
void deleteFirst(ListHndl L);

/*Deletes the last element in the list*/
void deleteLast(ListHndl L);

/*Deletes the current element in the list and leaves curr = NULL*/
void deleteCurrent(ListHndl L);
