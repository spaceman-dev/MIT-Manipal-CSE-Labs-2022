import java.util.Scanner;
class NCR
{
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter n : ");
int n = sc.nextInt();
System.out.println("Enter r : ");
int r = sc.nextInt();
int ncr = fact(n)/((fact(n-r))*fact(r));
System.out.println(n+"C"+r+" = "+ncr);
}
public static int fact(int n)
{
int f = 1;
for(int i = 1 ; i <= n ; i++)
{
f = f*i;
}
return f;
}
}