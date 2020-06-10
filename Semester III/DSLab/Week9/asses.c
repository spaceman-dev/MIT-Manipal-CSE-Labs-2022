#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
typedef char* String;
/*void init(stack *s);
void init(stack *s)
{
s->top = -1;
}*/
void main()
{
char str[100];
stack *s;
s = calloc(5000,sizeof(stack));
int i;
printf("Enter the Sentence : \n");
scanf("%s",str);
//s->top = -1;
init(s);
int l = strlen(str);
int count = 0;
char x[100];
/*for(i = 0 ; i < 100 ; i++)
x[i] = '/0';*/
int a = 0;
//printf("%s\n",x);
for(i = 0 ; i < l ; i++)
{
//strcpy(x,str);
x[a] = str[i];
//printf("%c ",x[a]);
a++;
if(str[i] == ' ')
{
//printf("Word = %s\n",x);
push(s,x);
count++;
a = 0;
}
}
printf("\nThe Reversed String is : \n");
for(i = 0 ; i < count ; i++)
{
printf("%s",pop(s));
}
}
