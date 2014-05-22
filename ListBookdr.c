/* This will test the list ADT */
#include "ListBook.h"
#include "myinclude.h"

int main ()
{
	int testData = 98;
	int testData2 = 97;
	int testData3 = 99;
	char testString[] ="Hello World";
	char testString2[] ="How are you?";
	char testString3[] ="Fine thanks";
	char * testTitle1;
	char * testTitle2; 
	char * testTitle3; 
	testTitle1 = testString;
	testTitle2 = testString2; 
	testTitle3 = testString3; 

	/* List creation */
	BookListHndl TheList;
	TheList = NULL;
	TheList = NewBookList();
	
	if(isBookListEmpty(TheList)) printf("The list is empty \n");

	insertBookAtFront(TheList, testTitle1,  testData);
	insertBookAtBack(TheList, testTitle2, testData2);
	insertBookAtBack(TheList, testTitle3, testData3);
	insertBookAtBack(TheList, testTitle2, testData2);
	insertBookAtFront(TheList, testTitle1, testData);
	insertBookAtBack(TheList, testTitle2, testData2);
	insertBookAtFront(TheList, testTitle1, testData);
	insertBookAtFront(TheList, testTitle3, testData3);
	
	printf("Current is %s\n", getTitleCurrent(TheList));
	moveLastBookList(TheList);
	printf("Current is %s\n", getTitleCurrent(TheList));
	moveFirstBookList(TheList);
	printf("Current is %s\n", getTitleCurrent(TheList));
	moveNextBookList(TheList);
	printf("Current is %s\n", getTitleCurrent(TheList));
	movePrevBookList(TheList);
	printf("Current is %s\n", getTitleCurrent(TheList));

	insertBookBeforeCurrent(TheList, testTitle2, testData);
	printf("Inserted %s before %s, which means %s is before %s", testTitle2, testTitle3, getTitleFirst(TheList), getTitleCurrent(TheList));
	
	printf("Printing the entire list.. ");
	printBookList(TheList);
	
	deleteFirstBook(TheList);
	deleteLastBook(TheList);
	printf("Printing the entire list after deleting first & last.. \n");
	printBookList(TheList);
	moveNextBookList(TheList);
	moveNextBookList(TheList);
	moveNextBookList(TheList);
	movePrevBookList(TheList);
	printf("Printing the entire list after deleting current: %s.. \n", getTitleCurrent(TheList));
	deleteCurrentBook(TheList);
	printBookList(TheList);
	
	moveFirstBookList(TheList);
	if(isBookListEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 
	
	printf("Printing FIRST, CURRENT, LAST... \n");
	printf("%s, %s, %s", getTitleFirst(TheList), getTitleCurrent(TheList), getTitleLast(TheList));
	printf("Printing the entire list.. ");
	printBookList(TheList);
	
	if(isBookListEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 
	
	makeBookListEmpty(TheList);
	
	if(isBookListEmpty(TheList)) 
		printf("The list is empty \n");
	else
		printf("The list is NOT empty \n"); 

	freeBookList(&TheList);
	
	return(0);
}
