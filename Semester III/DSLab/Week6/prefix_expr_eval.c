#include <stdio.h>
#include <string.h>
#include "stack.h"
void main()
{
stack s;
char x;
int op1,op2,val,i;
init(&s);
char expr[100];
printf("Enter the Prefix Expression (Eg. +*593 = 5*9+3)\nUse single digit operands and operators only ! :\n");
scanf("%s",expr);
for(i = strlen(expr)-1; i >= 0 ; i--)
{
x = expr[i];
if(isdigit(x))
	push(&s,x-'0');
else
{
op2 = pop(&s);
op1 = pop(&s);
val = evaluate(x,op1,op2);
push(&s,val);
}
}
val = pop(&s);
printf("Value of Expression '%s' = %d\n",expr,val);
}