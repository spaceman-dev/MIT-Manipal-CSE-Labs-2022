#include <stdio.h>
#include <stdlib.h>
void main()
{
int a,b,c,i,j,s=1;
b = 0;
while(s == 1)
{
while(b == 0)
{
c = rand();
if(c>100 || c<-100)
b = 1;
}
printf("Random number = %d\n",c);
}
printf("Do you want to try again?\n");
scanf("%d",&s);
}