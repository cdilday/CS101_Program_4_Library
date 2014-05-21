/* This will test the list ADT */
#include "ListInt.h"
#include "myinclude.h"

int main ()
{
	int testData = 98;
	int testData2 = 97;
	int testData3 = 99;

	/* List creation */
	ListHndl TheList;
	TheList = NULL;
	TheList = NewList();
	
	if(isEmpty(TheList)) printf("The list is empty \n");

	insertAtFront(TheList, testData);
	insertAtBack(TheList, testData2);
	insertAtBack(TheList, testData3);
	insertAtBack(TheList, testData2);
	insertAtFront(TheList, testData);
	insertAtBack(TheList, testData2);
	insertAtFront(TheList, testData);
	insertAtFront(TheList, testData3);
	
	printf("Current is %d\n", getCurrent(TheList));
	moveLast(TheList);
	printf("Current is %d\n", getCurrent(TheList));
	moveFirst(TheList);
	printf("Current is %d\n", getCurrent(TheList));
	moveNext(TheList);
	printf("Current is %d\n", getCurrent(TheList));
	movePrev(TheList);
	printf("Current is %d\n", getCurrent(TheList));

	insertBeforeCurrent(TheList, testData2);
	printf("Inserted %d before %d, which means %d is before %d\n", testData2, testData3, getFirst(TheList), getCurrent(TheList));
	
	printf("Printing the entire list.. ");
	printList(TheList);
	
	deleteFirst(TheList);
	deleteLast(TheList);
	printf("Printing the entire list after deleting first & last.. ");
	printList(TheList);
	moveNext(TheList);
	moveNext(TheList);
	moveNext(TheList);
	movePrev(TheList);
	printf("Printing the entire list after deleting current: %d.. ", getCurrent(TheList));
	deleteCurrent(TheList);
	printList(TheList);
	
	moveFirst(TheList);
	if(isEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 
	
	printf("Printing FIRST, CURRENT, LAST... ");
	printf("%d, %d, %d \n", getFirst(TheList), getCurrent(TheList), getLast(TheList));
	
	
	printf("Printing the entire list.. ");
	printList(TheList);
	
	if(isEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 
	
	makeEmpty(TheList);
	
	if(isEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 

	freeList(&TheList);
	
	return(0);
}
