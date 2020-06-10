import java.util.Scanner;
class Largest3_num_1
{
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter the first number : ");
int a = sc.nextInt();
System.out.println("Enter the second number : ");
int b = sc.nextInt();
System.out.println("Enter the third number : ");
int c = sc.nextInt();
int largestnum = largest(a,b,c);
System.out.println("Largest of "+a+", "+b+", "+c+" = "+largestnum);
}
public static int largest(int a, int b, int c)
{
if(a>b)
{
if(a>c)
{
return a;
}
else
{
return c;
}
}
else 
{
if(b>c)
{
return b;
}
else
{
return c;
}
}
}
}