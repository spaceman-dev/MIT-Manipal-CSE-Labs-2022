#include <stdio.h>
#include <stdlib.h>
void reversearrptr(int * arr , int n)
{
int *temp;
int i = 0;
for(i = 0 ; i < n/2 ; i++)
{
*temp = *(arr+i);
*(arr+i) = *(arr+n-i-1);
*(arr+n-i-1) = *temp;
}
printf("The Reverse of the Array is : \n");
for(i = 0 ; i < n ; i++)
printf("%d ",arr[i]);
printf("\n");
}
void main()
{
int i,n;
int *arr;
printf("Enter the Number of Elements in the Array : \n");
scanf("%d",&n);
arr = (int *)calloc(n,sizeof(int));
printf("Enter the Elements of the Array : \n");
for(i = 0 ; i < n ; i++)
scanf("%d",&arr[i]);
reversearrptr(arr,n);
free(arr);
}