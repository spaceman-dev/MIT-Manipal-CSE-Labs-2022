package p1;
import java.util.*;
import java.lang.*;
abstract class Figure
{
int dim1 , dim2 , dim3;
abstract public double area(int dim1 , int dim2 , int dim3);
}
class Rectangle extends Figure
{
public double area(int length , int breadth , int dim3)
{
return (length*breadth);
}
}
class Square extends Figure
{
public double area(int side , int dim2 , int dim3)
{
return (side*side);
}
}
class Triangle extends Figure
{
public double area(int a , int b , int c)
{
double s = (a+b+c)/2.00;
return (Math.pow((s*(s-a)*(s-b)*(s-c)),0.5));
}
}
class Figure1
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
Figure r1 = new Rectangle();
Figure s1 = new Square();
Figure t1 = new Triangle();
System.out.println("Enter length of Rectangle : ");
int length = sc.nextInt();
System.out.println("Enter Breadth of Rectangle : ");
int breadth = sc.nextInt();
System.out.println("The Area of the Rectangle = "+r1.area(length,breadth,0));
System.out.println("Enter the Side of the Square : ");
int side = sc.nextInt();
System.out.println("The Area of the Square = "+s1.area(side,0,0));
System.out.println("Enter the Three Sides of the Triangle : ");
int a = sc.nextInt();
int b = sc.nextInt();
int c = sc.nextInt();
System.out.println("The Area of the Triangle = "+t1.area(a,b,c));
}
}