#include <stdio.h>
void Lsearch(int arr[],int n,int ele)
{
int i,flag=0;
for(i = 0 ; i < n ; i++)
{
if(ele==arr[i])
{
printf("\nElement '%d', found at position '%d'\n",ele,i);
flag = 1;
}
}
if(flag == 0)
printf("\nERROR, Element '%d' not found\n",ele);
}