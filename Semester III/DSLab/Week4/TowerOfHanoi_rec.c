#include <stdio.h>
#include <stdlib.h>
void towerOfHanoi(int n, char *source, char *dest, char *temp) 
{ 
printf("n = %d, Source = %s, Destination = %s, Temp = %s\n",n,source,dest,temp);
if (n == 1) 
{ 
printf("Move disk 1 from rod %s to rod %s \n", source, dest); 
return; 
} 
towerOfHanoi(n-1, source, temp, dest); 
printf("Move disk %d from rod %s to rod %s\n", n, source, dest); 
towerOfHanoi(n-1, temp, source, dest); 
} 
void main()
{
char source[100];
char dest[100];
char temp[100];
int n;
printf("Enter the number of Disks : \n");
scanf("%d",&n);
printf("Enter the Name of the Source Rod :\n");
scanf("%s",source);
printf("Enter the Name of the Destination Rod :\n");
scanf("%s",dest);
printf("Enter the Name of the Temporary Rod :\n");
scanf("%s",temp);
towerOfHanoi(n,source,dest,temp);
}
