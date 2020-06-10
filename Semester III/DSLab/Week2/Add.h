#include <stdio.h>
void addarr(int n, double arr[])
{
double sum = 0.0;
int i;
for(i = 0 ; i < n ; i++)
{
sum = sum + arr[i];
}
printf("\nThe Sum of The Elements of the Array is : %lf \n",sum);
}