#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void copystr(char *s1 , char *s2 , int index);
void copystr(char *s1,char *s2,int index)
{
printf("s1 = %s, s2 = %s,index = %d \n",s1,s2,index);
if(s1[index] == '\0')
return;
s2[index] = s1[index];
copystr(s1,s2,index+1);
}
void main()
{
int n;
int index = 0;
printf("Enter the maximum size of the String :\n");
scanf("%d",&n);
char *s1;
char *s2;
s1 = (char *)calloc(n,sizeof(char));
s2 = (char *)calloc(n,sizeof(char));
printf("Enter a String : \n");
scanf("%s",s1);
copystr(s1,s2,0);
printf("The Copied Value of the String is : %s\n",s2);
free(s1);
free(s2);
}
