#include <stdio.h>
#include "SecLarge.h"
void main()
{
int n,i,ele;
int arr[100];
printf("Enter the number of elements in the array : ");
scanf("%d",&n);
printf("\nEnter the elements of the array : \n");
for(i = 0 ; i < n ; i++)
scanf("%d",&arr[i]);
SLarge(arr,n);
}
