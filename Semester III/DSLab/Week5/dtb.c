#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
int empty(stack *s)
{
if(s->top==-1)
return(1);
else
return(0);
}
int full(stack *s)
{
if(s->top==MAX-1)
return(1);
else
return(0);
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
int main()
{
stack s;
int num;
s.top=-1;
printf("\nEnter a decimal number : \n");
scanf("%d",&num);
while((num!=0))
{
if(full(&s)!=1)
{
push(&s,num%2);
num=num/2;
}
else
{
printf("\nStack overflow!\n");
exit(0);
}
}
printf("\nThe Binary Converted Decimal Number is : \n");
while(empty(&s)!=1)
{
num=pop(&s);
printf("%d",num);
}
printf("\n");
return 0;
}