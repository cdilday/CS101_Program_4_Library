#include "List.h"
#include "myinclude.h"

void insertionSort(ListHndl L, long data)
{
	long insertData = data;
	
	if(isEmpty(L)) 
	{
		insertAtFront(L, insertData);
		return;
	}
	else
	{
		moveFirst(L);
		while(!offEnd(L))
		{
			if(insertData < getCurrent(L))
			{	 
				insertBeforeCurrent(L, insertData);
				return;
			}
			moveNext(L);
		}
		insertAtBack(L, insertData);
	}
}

void printHistory(ListHndl h[], long numCust)
{
	int i;
	printf("Customer#\tBooks Purchased\n");
	for(i = 0; i < numCust; i++)
	{
		printf("%d\t\t", i+1);
		printList(h[i]);
	}
}
void printHistoryFile(ListHndl h[], long numCust, FILE *file)
{
	int i;
	fprintf(file, "Customer#\tBooks Purchased\n");
	for(i = 0; i< numCust; i++)
	{
		fprintf(file, "%d\t\t", i+1);
		printListFile(h[i], file);
	}
}

int main (int argc, char **argv)
{
	char buffer[100000];
	char *pbuff;
	long numCustomers;
	long numBooks;
	long currCust;
	long data;
	int i;
	FILE *file;
	char fileName[1000];
	/*FILE *fileOut;*/
	argc = argc;

	/*Get the filename to be read*/
	printf("Enter a file name to be read:\n");
	scanf("%s", fileName);
	file = fopen(fileName, "r");

	if(file == NULL)
	{
		printf("ERROR: Could not find file in directory. Closing program.\n");
		exit(1);
	}
	/*fileOut = fopen("output.txt", "w");*/
	
	/*reads in the number of customers and purchases*/
	for(i = 0; i < 2 && fgets(buffer, sizeof buffer, file); i++) 
	{
		pbuff = buffer;
		if(i == 0)
		{
			numCustomers = strtol(pbuff, &pbuff, 10);
		}
		if(i == 1)
		{
			numBooks = strtol(pbuff, &pbuff, 10);
			/*printf("Num Books read is: %lu", numBooks);*/
		}
	}
	
	ListHndl history[numCustomers];
	for(i = 0; i < numCustomers; i++)
	{
		history[i] = NULL;
		history[i] = NewList();
	}
	/*reads in the purchases and bookID's*/
	for(i = 0; i < numBooks && fgets(buffer, sizeof buffer, file); i++) 
	{
		pbuff = buffer;
		currCust = strtol(pbuff, &pbuff, 10);
		data = strtol(pbuff, &pbuff, 10);
		currCust -=1;
		insertionSort(history[currCust],data);
	
	}
	printHistory(history, numCustomers);
	/*printHistoryFile(history, numCustomers, fileOut);*/
	/*freeing the array of lists*/
	for(i = 0; i < numCustomers; i++)
	{
		freeList(&history[i]);
	}
	fclose(file);
	/*fclose(fileOut);*/
	return 0;
}
