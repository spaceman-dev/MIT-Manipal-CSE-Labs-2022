#include <stdio.h>
#include "LinSearch.h"
void main()
{
int n,i,ele;
int arr[100];
printf("Enter the number of elements in the array : ");
scanf("%d",&n);
printf("\nEnter the elements of the array : \n");
for(i = 0 ; i < n ; i++)
scanf("%d",&arr[i]);
printf("Enter the element that you want to search : ");
scanf("%d",&ele);
Lsearch(arr,n,ele);
}
