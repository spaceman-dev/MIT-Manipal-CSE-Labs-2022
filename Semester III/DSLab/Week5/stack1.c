#include<stdio.h>
#include<stdlib.h>
#define MAX 20	
int top=-1,stack[MAX];
void push();
void pop();
void display();
int isEmpty(int top);
int isFull(int top);
int main()
{
int ch;	
int x=1;
while(x==1)	
{
printf("\n*** Stack Menu ***\n");
printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
printf("\n\nEnter your choice(1,2,3,4):\n");
scanf("%d",&ch);
switch(ch)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: 
printf("Exiting....");
x=0;
break;
default: 
printf("Wrong Choice! Try Again later :)");
exit(0);
}
}
return 0;
}
void push()
{
int val;
if(isFull(top)==1)
printf("\nStack is Full!\n");
else
{
printf("\nEnter element to push:\n");
scanf("%d",&val);
top=top+1;
stack[top]=val;
}
}
void pop()
{
if(isEmpty(top)==1)
printf("\nStack is Empty!\n");
else
{
printf("\nDeleted element is %d\n",stack[top]);
top=top-1;
}
}
void display()
{
int i;
if(isEmpty(top)==1)
printf("\nStack is Empty!\n");
else
{
printf("\nStack is...\n");
for(i=top;i>=0;--i)
printf("%d\n",stack[i]);
}
}
int isEmpty(int top)
{
if(top==-1)
return 1;
else
return 0;
}
int isFull(int top)
{
if(top==MAX-1)
return 1;
else
return 0;
}