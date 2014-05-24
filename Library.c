/* this is where the actual Library is created and used
*  using the Hash Table and two List ADTs I've created*/
#include "HashTable.h"
#include "myinclude.h"


int main (int argc, char *argv[])
{
	int numBooks;
	int numSlots;
	char buffer[100000];
	char *pbuff;
	char *tempName;
	int i;
	int tempID;
	FILE *file;
	char fileName[1000];
	argc = argc;
	file = fopen (argv[1], "r");
	/*read in numbers from first file input*/
	fgets(buffer, sizeof buffer, file);
	pbuff = buffer;
	sscanf(pbuff, "%d %d", &numBooks, &numSlots);

	HashTableHndl Library;
	Library = NULL;
	Library = NewHashTable(numSlots);
	
	/*insert everything from file 1 into the hash table*/
	for(i = 0; i < numBooks && fgets(buffer, sizeof buffer, file); i++)
	{
		pbuff = buffer;
		sscanf(pbuff, "%d %[^\n]", &tempID, buffer);
		pbuff = buffer;
		pbuff += 2;
		printf("%d %s\n", tempID, pbuff);
		insertIntoHashTable(Library, pbuff, tempID);
		printTableElement (Library, pbuff);

	}
	/*close file one and open file 2*/
	fclose(file);
	file = fopen (argv[2], "r");
	printf("\n");
	fgets(buffer, sizeof buffer, file);
	pbuff = buffer;
	sscanf(pbuff, "%d", &numBooks); /*reusing numbooks for the number of inputs in file 2 because why not*/
	
	for(i = 0; i < numBooks && fgets(buffer, sizeof buffer, file); i++)
	{
		pbuff = buffer;
		sscanf(pbuff, "%[^\n]", buffer);
		pbuff = buffer;
		printf("%s\n", pbuff);
		printTableElement (Library, pbuff);
	}
	
	return 0;
}
