#include <stdio.h>
#include <stdlib.h>
void main()
{
int *arr,*pwalk,*plast;
int n,i;
printf("Enter the Number of Elements in the Array : \n");
scanf("%d",&n);
arr = (int *)calloc(n,sizeof(int));
printf("Enter the Elements in the Array : \n");
for(i = 0 ; i < n ; i++)
scanf("%d",&arr[i]);
printf("Printing in Forward Direction : \n");
pwalk = arr;
plast = arr + n - 1;
//for(i = 0 ; i < n ; i++)
    //printf("%d ",*(arr+i));
//printf("\n");
while(pwalk <= plast)
{
printf("%d ",*(pwalk));
pwalk++;
}
printf("\n");
pwalk = arr + n - 1;
plast = arr;
printf("Printing in Backward Direction : \n");
//for(i = 0 ; i < n ; i++)
    //printf("%d ",*(arr+n-i-1));
//printf("\n");
while(pwalk >= plast)
{
printf("%d ",*(pwalk));
pwalk--;
}
printf("\n");
}