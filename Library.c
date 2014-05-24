/* this is where the actual Library is created and used
*  using the Hash Table and two List ADTs I've created*/
#include "myinclude.h"


int main (int argc, char *argv[])
{
	int numBooks;
	int numSlots;
	char buffer[100000];
	char *pbuff;
	int i;
	int tempID;
	FILE *file;
	char fileName[1000];
	argc = argc;
	printf("1\n");
	file = fopen (argv[1], "r");
	printf("2\n");
	fgets(buffer, sizeof buffer, file);
	printf("3\n");
	pbuff = buffer;
	printf("4\n");
	sscanf (pbuff, "%d %d", numBooks, numSlots);
	printf("5\n");
	printf("%d books with %d slots", numBooks, numSlots);
	
	/*HashTableHndl Library;
	Library = NULL;
	Library = NewHashTable(20);
	 
	for(i = 0; i < numBooks && fgets(buffer, sizeof buffer, file); i++) 
	{
		pbuff = buffer;
		tempID = atoi(pbuff);
		pbuff = buffer;
		tempName = 
		
	}*/

	return 0;
}
