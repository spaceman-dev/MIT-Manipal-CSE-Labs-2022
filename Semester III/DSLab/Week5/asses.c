#include <stdio.h>
#include <stdlib.h>
void NoOfOccurence(int *arr,int n , int *c ,int x)
{
int c1=0;
int i;
for(i = 0 ; i < n ;i++)
{
if(x==*(arr+i))
c1++;
}
*c=c1;
}
void main()
{
int n;
int *arr;
int i;
int x;
int *c;
printf("Enter the Number of Array Elements : \n");
scanf("%d",&n);
arr = (int *)calloc(n,sizeof(int));
printf("Enter the Elements in the Array : \n");
for(i = 0 ; i < n ; i++)
scanf("%d",(arr+i));
printf("Enter the Number whose occurences you wish to know : \n");
scanf("%d",&x);
NoOfOccurence(arr,n,c,x);
printf("Occurence = %d",*c);
}