#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
int i, j, n, m, flag=0, count=0;
char text[100], pattern[100];
printf("Enter the Text: \n");
scanf("%s", text);
printf("Enter the Pattern: \n");
scanf("%s", pattern);
n = strlen(text);
m = strlen(pattern);
for(i = 0 ; i <= n-m ; i++)
{
j = 0;
while(j < m && pattern[j] == text[j+i])
{
count++;
j++;
}
if(j == m)
{
flag = 1;
break;
} 
}
if(flag == 1)
	printf("Pattern Found at Position: %d \n",i);
else
	printf("Pattern not Found! \n");
printf("Count is : %d\n", count);
}