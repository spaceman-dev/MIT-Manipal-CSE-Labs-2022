#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
void main()
{
stack s;
int flag;
s.top = -1;
char s1[100];
//char revs[100] = Null;
int i;
printf("Enter a String to Check if it is a Palindrome or not : \n");
scanf("%s",s1);
for(i = 0 ; i < strlen(s1) ; i++)
{
push(&s,s1[i]);
}
for(i = 0 ; i < strlen(s1) ; i++)
{
if(pop(&s)!=s1[i])
{
flag = 0;
break;
}
else
flag = 1;
}
if(flag==1)
printf("Palindrome !\n");
else
printf("Not a Palindrome !\n");
}