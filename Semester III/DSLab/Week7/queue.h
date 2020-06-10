#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 100
typedef struct{
	int data[Max];
	int front;
	int rear;
}Queue;
void insertq(Queue *q , int ele)
{
if(q->rear == Max)
printf("Queue Overflow !!\n");
else
{
q->data[++q->rear] = ele;
if(q->front == -1)
q->front = 0;
}
}
int deleteq(queue *q)
{
int x;
if(q->front == -1)
{
printf("Queue Underflow !!\n");
return;
}
else if(q->front == q->rear)
{
x = q->data[q->front];
q->front = q->rear = -1;
return x;
}
else
return q->data[q->front++];
}
void displayq(queue q)
{
int i;
if(q.front == -1 && q.rear == -1)
printf("Queue is Empty !!\n");
else
{
printf("Queue is : \n");
for(i = q.front ; i <= q.rear ; i++)
printf("%d ",q.data[i]);
}
}