import java.util.Scanner;
class Prime_num
{
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter a number : ");
int n = sc.nextInt();
for(int i = 1 ; i <= n ; i++)
{
boolean res = isPrime(i);
if(res == true)
{
System.out.println(n+" is a Prime Number");
}
//else
//{
//System.out.println(n+" is not a Prime Number");
//}
}
}
public static boolean isPrime(int n)
{
int count = 0;
for(int i = 1 ; i <= n ; i++)
{
if(n%i == 0)
	count++;
}
if(count == 2)
    return true;
else
	return false;
}
}