#include <stdio.h>
#include <stdlib.h>
void main()
{
int k;
for(k = 0 ; k < 10 ; k++)
{
int n, arr[100], i, j, temp, flag, count = 0;
//printf("Enter the Number of Elements in the Array : \n");
scanf("%d", &n);
//printf("Enter the Elements in the Array : \n");
for(i = 0 ; i < n ; i++)
	scanf("%d", &arr[i]);
for(i = 0 ; i < n-1 ; i++)
{
flag = 0;
for(j = 0 ; j < n-i-1 ;j++)
{
count++;
if(arr[j] > arr[j+1])
{
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
flag =  1;
}
}
if(flag == 0)
	break;
}
//printf("The Sorted Array is : \n");
/*for(i = 0 ; i < n-1 ; i++)
	printf("%d, ", arr[i]);
printf("%d\n", arr[n-1]);
*/
//printf("The Number of Elements vs Count is : \n");
printf(" %d		%d \n",n,count);
}
}