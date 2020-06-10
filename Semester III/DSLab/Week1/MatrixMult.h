#include <stdio.h>
#include <stdlib.h>
void MMult(int a[][100],int b[][100],int m1,int n1,int m2,int n2)
{
int i,j,k,c[100][100];
if(n1 != m2)
{
printf("\nError Matrices cannot be Multiplied!\n");
exit(0);
}
for(i = 0 ; i < m1 ; i++)
{
for(j = 0 ; j < n2 ; j++)
c[i][j] = 0;
}
for(i = 0 ; i < m1 ; i++)
{
for(j = 0 ; j < n2 ; j++)
{
for(k = 0 ; k < n1 ; k++)
c[i][j] = c[i][j] + (a[i][k]*b[k][j]);
}
}
printf("The Resultant Matrix after the Multiplication is :\n");
for(i = 0 ; i < m1 ; i++)
{
for(j = 0 ; j < n2 ; j++)
printf("%d  ",c[i][j]);
printf("\n");
}
}