#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPalin(char *s , int leftindex , int rightindex);
void main()
{
int l;
int leftindex;
int rightindex;
char s[100];
printf("Enter the String : \n");
scanf("%s",s);
l = strlen(s);
leftindex = 0;
rightindex = l-1;
if(isPalin(s,0,l-1)==1)
printf("%s , is a Palindrome!\n",s);
else
printf("%s, is NOT a Palindrome!\n",s);
}
int isPalin(char *s , int leftindex , int rightindex)
{
printf("left = %d, right = %d\n",leftindex,rightindex);
if(leftindex >= rightindex)
{
return 1;
}
else if(s[leftindex]==s[rightindex])
{
return isPalin(s,leftindex+1,rightindex-1);
}
else
{
return 0;
}
}