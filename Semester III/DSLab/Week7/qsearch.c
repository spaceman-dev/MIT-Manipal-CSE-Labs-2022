#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#include "qs.h"


int searchQ(QUEUE* q, int key)
{
	QUEUE* tempQ = malloc(sizeof(QUEUE));
	initialise(tempQ);

	int found = 0, temp1;

	while (!isEmpty(q))
	{
		temp1 = deletecq(q);
		if (temp1 == key) {found = 1;}
		insertcq(tempQ, temp1);
	}

	while (!isEmpty(tempQ))
	{
		temp1 = deletecq(tempQ);
		insertcq(q, temp1);
	}

	return (found);
}


int main(int argc, char const *argv[])
{
	QUEUE* q = malloc(sizeof(QUEUE));
	initialise(q);

	int choice = 0, key, n, i;

	printf("no. of elements to insert : ");
	scanf("%d", &n);

	printf("enter elemets : ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &key);
		insertcq(q, key);
	}

	printf("enter element to search : ");
	scanf("%d", &key);

	if (searchQ(q, key) == 1) 
		printf("found\n");
	else
		printf("not found\n");
	disp(q);

	return 0;
}
