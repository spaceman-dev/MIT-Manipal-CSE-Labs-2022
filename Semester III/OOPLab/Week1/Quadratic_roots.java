import java.io.*;
import java.lang.Math;
import java.util.Scanner;
class Quadratic_roots
{
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter the coefficient of the equation corresponding to x^2 : ");
int a = sc.nextInt();
System.out.println("Enter the coefficient of the equation corresponding to x : ");
int b = sc.nextInt();
System.out.println("Enter the coefficient of the equation corresponding to 1 : ");
int c = sc.nextInt();
int D = (b*b - 4*a*c);
int flag;
double x1,x2;
String imm1;
String imm2;
if(D>0)
flag = 1;
else if(D==0)
flag = 2;
else
flag = 3;
switch(flag)
{
case 1:
x1 = ((-b+Math.sqrt(D))/(2.00*a));
x2 = ((-b-Math.sqrt(D))/(2.00*a));
System.out.println("The Roots of the Quadratic equation, "+a+" (x^2)+"+b+" x+"+c+" = "+x1+", "+x2);
break;
case 2:
x1 = -b/(2.00*a);
System.out.println("The Roots of the Quadratic equation, "+a+" (x^2)+"+b+" x+"+c+" = "+x1);
break;
case 3:
//imm = Math.sqrt(Math.abs(D));
x1 = ((-b+Math.sqrt(Math.abs(D)))/(2.00*a));
x2 = ((-b-Math.sqrt(Math.abs(D)))/(2.00*a));
//int x = -b;
//imm1 = ""+"("+x+"+"+imm+"i"+")"+"/"+(2.00*a)+"";
//imm2 = ""+"("+x+"-"+imm+"i"+")"+"/"+(2.00*a)+"";
System.out.println("The Roots of the Quadratic equation, "+a+" (x^2)+"+b+" x+"+c+" = "+x1+", "+x2);
}
}
}