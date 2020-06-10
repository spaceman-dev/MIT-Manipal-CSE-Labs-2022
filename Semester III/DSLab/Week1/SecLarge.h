#include <stdio.h>
void SLarge(int arr[],int n)
{
int min = arr[0] ,max = arr[0],i,smax;
for(i = 0 ; i < n ; i++)
{
if(max<arr[i])
max = arr[i];
if(min>arr[i])
min = arr[i];
}
for(i = 0 ; i < n ; i++)
{
if(max == arr[i])
arr[i] = min;
}
smax = min;
for(i = 0 ; i < n ; i++)
{
if(smax < arr[i])
smax = arr[i];
}
printf("Second Largest Element in the Array = %d \n",smax);
}