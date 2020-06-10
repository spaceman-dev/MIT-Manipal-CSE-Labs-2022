#include <stdio.h>
#include <stdlib.h>
int count = 0;
void swap (int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
int partition (int *arr, int start, int end) 
{
	int pivot = *(arr + end);
	int i = start, j;
	for (j = start; j < end; ++j) 
	{
		if (*(arr + j) <= pivot) 
		{
			count = count + 1;
			swap(arr + i, arr + j);
			i++;
		}
	}
	swap(arr + i, arr + end);
	return i;
}
void quickSort (int *arr, int start, int end) 
{
	if (start < end) 
	{
		int p = partition(arr, start, end);
		quickSort(arr, start, p - 1);
		quickSort(arr, p + 1, end);
	}
}
void main () 
{   
	int n, i;
	printf("Enter the Number of Elements of the Array : \n");
	scanf(" %d", &n);
	int *arr = (int *)calloc(n, sizeof(int));   
	printf("Enter the Elements of the Array : \n");
	for (i = 0; i < n; ++i)
		scanf(" %d", (arr + i));
	quickSort(arr, 0, n - 1);
	printf("The Sorted Array is : \n");
	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	printf("Count is %d\n", count);
}
