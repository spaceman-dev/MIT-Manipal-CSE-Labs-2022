import java.io.*;
import java.util.Scanner;
class IOSc
{
public static void main(String[] args)throws IOException
{
InputStreamReader i1 = new InputStreamReader(System.in);
BufferedReader br = new BufferedReader(i1);
Scanner sc = new Scanner(System.in);
System.out.println("Enter number: ");
int size=sc.nextInt();
System.out.println("Enter number: ");
int size1=Integer.parseInt(br.readLine());
System.out.println(size+" "+size1);
}
}
