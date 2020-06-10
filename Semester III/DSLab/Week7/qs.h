#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct 
{
	int a[MAX];
	int rear;
	int front;
}QUEUE;

void initialise(QUEUE* q)
{
	q->rear=-1;
	q->front=-1;
}
int isFull(QUEUE* q)
{
	if ((q->rear+1)%MAX==q->front)
		return 1;return 0;
}

int isEmpty(QUEUE* q)
{
	if(q->rear==-1 && q->front==-1)
		return 1;return 0;
}

void insertcq(QUEUE* q, int ele)
{
	if (isFull(q))
		{printf("QUEUE overflow!!\n");
			return;}

	if (isEmpty(q))
		{ 	q->front=0;
		}
		
		q->rear=((q->rear)+1)%MAX;
		q->a[q->rear]=ele;
	
}

int deletecq(QUEUE* q)
{
	if(isEmpty(q))
		{
			printf("QUEUE Underflow !!\n");
		}
	
	else
	{
		int ele =q->a[q->front];
		if (q->rear==q->front)
			q->front=q->rear=-1;
		else
			q->front=((q->front)+1)%MAX;
		return ele;
	}
}

void disp(QUEUE* q)
{	int i;
	if(isEmpty(q))
		printf("QUEUE isEmpty!!\n");
	else
	{
		for (i = q->front; i !=q->rear; i=(i+1)%MAX)
			printf(" %d\n",q->a[i]);
		printf(" %d\n",q->a[i]);
	}
}