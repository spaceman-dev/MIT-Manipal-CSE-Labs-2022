#include <stdio.h>
#include <stdlib.h>
#include "Add.h"
void main()
{
int n,i;
double *arr;
printf("Enter the number of elements in the array : ");
scanf("%d",&n);
arr = (double *)calloc(n+1,sizeof(double));
printf("\nEnter the elements of the array : \n");
for(i = 0 ; i < n ; i++)
scanf("%lf",&arr[i]);
addarr(n,arr);
free(arr);
}