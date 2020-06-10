#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 30
typedef char* String;
typedef struct
{
String data[Max];
int rear;
int front;
}dequeue;
void initialize(dequeue *q);
int empty(dequeue *q);
int full(dequeue *q);
void enqueueR(dequeue *q , String x);
void enqueueF(dequeue *q , String x);
String dequeueF(dequeue *q);
String dequeueR(dequeue *q);
void print(dequeue *q);

void initialize(dequeue *q)
{
q->rear = -1;
q->front = -1;
}
int empty(dequeue *q)
{
if(q->rear = -1)
return 1;
return 0;
}
int full(dequeue *q)
{
if((q->rear+1)%Max == q->front)
return 1;
return 0;
}
void enqueueR(dequeue *q , String x)
{
if(empty(q))
{
q->rear = 0;
q->front = 0;
q->data[0] = x;
}
else
{
q->rear = (q->rear + 1)%Max;
q->data[q->rear] = x;
}
}
void enqueueF(dequeue *q,String x)
{
if(empty(q))
{
q->rear = 0;
q->front = 0;
q->data[0] = x;
}
else
{
q->front = (q->front-1+Max)%Max;
q->data[q->front] = x;
}
}
String dequeueF(dequeue *q)
{
String x;
x = q->data[q->front];
if(q->rear = q->front)
initialize(q);
else
q->front = (q->front+1)%Max;
return x;
}
String dequeueR(dequeue *q)
{
String x;
x = q->data[q->rear];
if(q->rear = q->front)
initialize(q);
else
q->rear = (q->rear - 1 + Max)%Max;
return x;
}
void print(dequeue *q)
{
/*
if(empty(q))
{
printf("Queue is Empty !!\n");
exit(0);
}
*/
int i;
i = q->front;
while(i!=q->rear)
{
printf("%d\t",q->data[q->rear]);
i = (i+1)%Max;
}
printf("\n%d\n",q->data[q->rear]);
}