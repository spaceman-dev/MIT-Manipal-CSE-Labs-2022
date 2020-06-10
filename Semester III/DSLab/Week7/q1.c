#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct 
{
	char arr[5];
	int front;
	int rear;
	int count;
}Queue;
void insertq(Queue *q,char ele)
{
	if(q->count==5)
		printf("QUEUE FULL\n");
	else
	{
		q->rear=(q->rear+1)%5;
		q->arr[q->rear]=ele;
		q->count++;
	}
}
void deleteq(Queue *q)
{
	if(q->count==0)
		printf("QUEUE EMPTY\n");
	else
		{
			q->front=(q->front+1)%5;
			q->count--;
		}
}
void displayq(Queue *q)
{
	if(q->count==0)
		printf("QUEUE EMPTY\n");
	else
	{
		for(int i=1,f=q->front;i<=q->count;i++)
		{
			printf("%c\n",q->arr[f] );
			f=(f+1)%5;			
		}
	}
}
void main()
{
	Queue q1,*q;
	q=&q1;
	q->front=0;
	q->rear=-1;
	int j,ch;
	q->count=0;
	char ele;
	for(;;)
	{
		printf("Enter choice 1)INSERT 2)DELETE 3)DISPLAY 4)EXIT\n");
		scanf("%d",&ch);
		if(ch==1)
			{
				printf("Enter char\n");
				scanf(" %c",&ele);
				insertq(q,ele);
			}
		else if(ch==2)
				deleteq(q);
				
		else if(ch==3)
				displayq(q);
		else
			exit(0);
				
	}
}
