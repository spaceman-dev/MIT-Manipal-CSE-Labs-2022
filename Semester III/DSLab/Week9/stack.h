#include <stdio.h>
#define MAX 5000
typedef char* String;
typedef struct
{
String data[MAX];
int top;
}stack;
void init(stack *s)
{
s->top = -1;
}
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
void push(stack *s,String x)
{
s->top=s->top+1;
s->data[s->top]=x;
}
String pop(stack *s)
{
String x;
x=s->data[s->top];
s->top=s->top-1;
return(x);
}