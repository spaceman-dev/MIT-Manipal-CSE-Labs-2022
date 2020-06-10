import java.util.Scanner;
class Sum_dig
{
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter a number : ");
int n = sc.nextInt();
System.out.println("Sum of digits of "+n+" = "+findSum(n));
}
public static int findSum(int n)
{
int sum = 0;
while(n>0)
{
int dig = n%10;
sum = sum + dig;
n = n/10;
}
return sum;
}
}