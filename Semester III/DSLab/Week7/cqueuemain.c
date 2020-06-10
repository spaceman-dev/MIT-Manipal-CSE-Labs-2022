#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cqueue.h"
void main()
{
CQueue cq;
//cq->front = -1;
//cq->rear = -1;
int i;
int ch,flag = 1;
String x;
initcq(&cq);
while(flag == 1)
{
printf("\n.........MENU.........\n1. Insert in Circular Queue \n2. Delete from Circular Queue\n3. Exit\n....................\n");
printf("Enter your choice : \n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the Element to be inserted : \n");
scanf("%s",x);
insertcq(&cq,x);
break;
case 2:
//x = deletecq(&cq);
printf("Removed '%s' from the Circular Queue\n",deletecq(&cq));
break;
case 3:
flag = 0;
break;
default:
printf("Wrong Choice! Try Again!!\n");
}
//for (i = cq.front; i != cq.rear; i = (i+1)%Max)
//printf("\t%s", *(cq.data+ i));
//printf("\t%s\n", *(cq.data + i));
}
}