import java.util.Scanner;
class Armstrong_num
{
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter a number : ");
int n = sc.nextInt();
if(isArmstrong(n)==true)
	System.out.println(n+" is Armstrong");
else
	System.out.println(n+"is not Armstrong");
}
public static boolean isArmstrong(int n)
{
int n1 = n;
int arm = 0;
while(n>0)
{
int dig = n%10;
arm = arm + dig*dig*dig;
n = n/10;
}
if(n1 == arm)
	return true;
else
	return false;
}
}