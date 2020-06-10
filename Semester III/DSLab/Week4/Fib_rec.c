#include <stdio.h>
int Fib(int n);
void main()
{
int n,i;
printf("Enter the number of terms of the Fibbonacci Series : \n");
scanf("%d",&n);
printf("The Fibbonacci series is : \n");
for(i = 0 ; i < n ; i++)
{
printf("%d ",Fib(i));
}
printf("\n");
}
int Fib(int n)
{
printf("Fibbonacci Term : %d \n",n);
if(n==0)
return 0;
else if(n==1)
return 1;
else
return (Fib(n-1)+Fib(n-2));
}