#include <stdio.h>
#define MAX 100
typedef struct
{
int data[MAX];
int top;
}stack;
int isEmpty(stack *s)
{
if(s->top==-1)
return 1;
else
return 0;
}
int isFull(stack *s)
{
if(s->top==MAX-1)
return 1;
else
return 0;
}
void push(stack *s,int x)
{
s->top=s->top+1;
s->data[s->top]=x;
}
int pop(stack *s)
{
int x;
x=s->data[s->top];
s->top=s->top-1;
return(x);
}