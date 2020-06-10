#include <stdio.h>
#include <stdlib.h>
#include "dequeue.h"
void main()
{
int i;
String x;
int flag = 1;
int ch;
int n;
dequeue q;
char s[100];
initialize(&q);
while(flag == 1)
{
printf("................................................\n");
printf("Enter :\n1.Create\n2.Insert Rear\n3.Insert Front\n4.Delete Front\n");
printf("5.Print\n6.Exit\n");
printf("................................................\n");
printf("Enter your Choice : \n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the Number of Elements : \n");
scanf("%d",&n);
initialize(&q);
printf("Enter the Data : \n");
for(i = 0 ; i < n ; i++)
{
scanf("%s",s);
if(full(&q))
{
printf("Queue is Full !!\n");
}
enqueueR(&q,s);
}
break;
case 2:
printf("Enter Data to be Inserted : \n");
scanf("%s",s);
if(full(&q))
{
printf("Queue is Full !!\n");
}
enqueueR(&q,s);
break;
case 3:
printf("Enter Data to be inserted : \n");
scanf("%s",s);
if(full(&q));
{
printf("Queue is Full !!\n");
}
enqueueF(&q,s);
break;
case 4:
/*
if(empty(&q))
{
printf("Queue is Empty !!\n");
}
*/
printf("Deleted Element is : %s",dequeueF(&q));
break;
case 5:
print(&q);
break;
default:
print(&q);
flag = 0;
break;
}
}
}