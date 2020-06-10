#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct 
{
int real;
int imag;
}Complex;

Complex addComp(Complex a, Complex b);
Complex subtractComp(Complex a, Complex b);
Complex multComp(Complex a, Complex b);
void main()
{
Complex a,b,sum,subtract,prod;
printf("Enter the Real Part of the First Complex Number : \n");
scanf("%d",&a.real);
printf("Enter the Imaginary Part of the First Complex Number : \n");
scanf("%d",&a.imag);
printf("Enter the Real Part of the Second Complex Number : \n");
scanf("%d",&b.real);
printf("Enter the Imaginary Part of the Second Complex Number : \n");
scanf("%d",&b.imag);
sum = addComp(a,b);
subtract = subtractComp(a,b);
prod = multComp(a,b);
printf("The Sum of the Complex Numbers is : %d + i %d\n",sum.real,sum.imag);
printf("The Subtraction of the Complex Numbers is : %d + i %d\n",subtract.real,subtract.imag);
printf("The Product of the Complex Numbers is : %d + i %d\n",prod.real,prod.imag);
}
Complex addComp(Complex a, Complex b)
{
Complex sum;
sum.real = a.real + b.real;
sum.imag = a.imag + b.imag;
return sum;
}
Complex subtractComp(Complex a, Complex b)
{
Complex subtract;
subtract.real = a.real - b.real;
subtract.imag = a.imag - b.imag;
return subtract;
}
Complex multComp(Complex a, Complex b)
{
Complex prod;
prod.real = (a.real * b.real) - (a.imag * b.imag);
prod.imag = (a.imag * b.real) + (a.real * b.imag);
return prod;
}
