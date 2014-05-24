/* This will test the HashTable ADT */
#include "ListBook.h"
#include "HashTable.h"
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

	printf("Making the table\n");
	HashTableHndl TheTable;
	TheTable = NULL;
	printf("Instantiating the table\n");
	TheTable = NewHashTable(20);

	printf("inserting into the Table\n");
	insertIntoHashTable (TheTable, testTitle1, testData);
	insertIntoHashTable (TheTable, testTitle1, testData);
	insertIntoHashTable (TheTable, testTitle1, testData);
	
	insertIntoHashTable (TheTable, testTitle2, testData);
	insertIntoHashTable (TheTable, testTitle2, testData2);
	insertIntoHashTable (TheTable, testTitle2, testData3);
	printf("Printing the table element\n");
	printTableElement (TheTable, testTitle1);
	
	printTableElement (TheTable, testTitle2);

	return(0);
}
