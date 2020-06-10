#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
typedef char* String;
typedef struct{
	String data[Max];
	int front;
	int rear;
}CQueue;
void initcq(CQueue *cq);
void insertcq(CQueue *cq,String item);
String deletecq(CQueue *cq);

void initcq(CQueue *cq)
{
cq->front = -1;
cq->rear = -1;
}
void insertcq(CQueue *cq , String item)
{
int i;
(cq->rear) = ((cq->rear)+1)%Max;
if((cq->front) == (cq->rear))
exit(0);
//(cq->data[cq->rear]) = item;
for(i = 0 ; i < strlen(item) ; i++)
(cq->data[i][cq->rear] = *(item+i));
}
String deletecq(CQueue *cq)
{
String item;
if((cq->front) == (cq->rear))
return ("Circular Queue Empty!");
else
{
(cq->front) = ((cq->front) + 1)%Max;
return (cq->data[cq->front]);
}
}