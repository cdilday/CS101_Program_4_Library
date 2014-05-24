/* Here will go the prototype functions for the BookList ADT 
*  This is identical to the List ADT file Alex Vincent and
*  I used for Program 2 since none of it needs to be changed*/
#include "ListInt.h"
#include <stdio.h>


/*Declaration of the ListHandle empty pointer. Set it to null
 *when you first use it! */
typedef struct BookListStruct * BookListHndl;

/* This function will allocate memory for a new list, returning
 *a POINTER to the thing allocated */
BookListHndl NewBookList ();

/* This function ACCEPTS a pointer to a ListHandle and will free
 * every Node in the list, as well as the list itself. */
void freeBookList (BookListHndl* L); /*Pre condition -> L was made with NewList*/

/* This checks to see whether the BookListStruct points to any struct nodes. 
 * If it points to anything NOT null, it will return 1. 
 * If it all it points to are NULL things, it will return 0. */
int isBookListEmpty (BookListHndl L);

/*Returns 0 if the current pointer is not on the list (aka pointing to null) */
int offEndBookList (BookListHndl L);

/* Returns 0 if the curr pointer is pointing to first, also !offEnd() */
int atFirstBookList(BookListHndl L);

/* Return 0 if the curr pointer is pointing to last, also !offEnd() */
int atLastBookList(BookListHndl L);

/* Returns the data (book title) from the node without altering the function */
char * getTitleFirst(BookListHndl L);
char * getTitleLast(BookListHndl L);
char * getTitleCurrent(BookListHndl L);

/* Returns the data (ID list) from the node without altering the function */
IntListHndl * getIDsFirst(BookListHndl L);
IntListHndl * getIDsLast(BookListHndl L);
IntListHndl * getIDsCurrent(BookListHndl L);

/* Inserts something into the beginning of the list, curr stays the same! */
void insertBookAtFront(BookListHndl L, char * title, int id);

/*Inserts something into the end of the list, curr stays the same! */
void insertBookAtBack(BookListHndl L, char * title, int id);

/* Prints out the entire list to STDOUT, 
 * make sure to change it to print to a file - special case when list is empty*/
void printBookList(BookListHndl L);

/* Prints entire list to A FILE*/
void printBookListFile(BookListHndl L, FILE *file);

/*Makes the list empty by going through and freeing nodes. Sets first, curr, and last to null*/
void makeBookListEmpty(BookListHndl L);

/*points the curr pointer to the first element*/
void moveFirstBookList(BookListHndl L);

/*points the curr pointer to the last element*/
void moveLastBookList(BookListHndl L);

/*Moves the current marker to the previous element*/
void movePrevBookList(BookListHndl L);

/*Moves the current marker to the next element*/
void moveNextBookList(BookListHndl L);

/*Inserts a new node before the current node*/
void insertBookBeforeCurrent(BookListHndl L, char * title, int id);

/*Deletes the first element in the list*/
void deleteFirstBook(BookListHndl L);

/*Deletes the last element in the list*/
void deleteLastBook(BookListHndl L);

/*Deletes the current element in the list and leaves curr = NULL*/
void deleteCurrentBook(BookListHndl L);
