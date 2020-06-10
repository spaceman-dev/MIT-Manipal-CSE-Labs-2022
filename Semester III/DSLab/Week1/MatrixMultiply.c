#include <stdio.h>
#include "MatrixMult.h"
void main()
{
int a[100][100],b[100][100];
int m1,n1,m2,n2,i,j;
printf("Enter the number of Elements in the Row of the First Matrix : ");
scanf("%d",&m1);
printf("\nEnter the number of Elements in the Column of the First Matrix : ");
scanf("%d",&n1);
printf("\nEnter the number of Elements in the Row of the Second Matrix : ");
scanf("%d",&m2);
printf("\nEnter the number of Elements in the Column of the Second Matrix : ");
scanf("%d",&n2);
printf("\nEnter the Elements in the First Matrix : ");
for(i = 0 ; i < m1 ; i++)
{
for(j = 0 ; j < n1 ; j++)
scanf("%d",&a[i][j]);
}
printf("\nEnter the Elements in the Second Matrix : ");
for(i = 0 ; i < m2 ; i++)
{
for(j = 0 ; j < n2 ; j++)
scanf("%d",&b[i][j]);
}
printf("\nThe First Matrix is :\n");
for(i = 0 ; i < m1 ; i++)
{
for(j = 0 ; j < n1 ; j++)
printf("%d  ",a[i][j]);
printf("\n");
}
printf("\nThe Second Matrix is :\n");
for(i = 0 ; i < m2 ; i++)
{
for(j = 0 ; j < n2 ; j++)
printf("%d  ",b[i][j]);
printf("\n");
}
printf("\n");
MMult(a,b,m1,n1,m2,n2);
}