#include <stdio.h>
#include <stdlib.h>
void main()
{
int m,n,t,count=0,i;
//printf("Enter the First Number : \n");
//printf("Enter the Second Number : \n");
for(i = 0 ; i < 5 ; i++)
{
scanf("%d", &m);
scanf("%d", &n);
for(t = (m <= n) ? m : n ; t>0 ; t--)
{
count++;
if(m%t == 0 && n%t == 0)
{
//printf("The GCD of '%d' and ' %d' = '%d'\n",m,n,t);
printf("%d	%d\n",t,count);
break;
}
}
//printf("Count = '%d'\n",count);
}
}