import java.util.*;
import java.io.*;
import java.lang.*;
class MulTableThread extends Thread
{
int n;
public MulTableThread(int n)
{
this.n = n;
start();
}
synchronized public void run()
{
System.out.println("................");
System.out.println(getName());
for(int i = 1 ; i < 11 ;i++)
	System.out.println(getName()+" "+n+" * "+i+" = "+(n*i));
System.out.println("................................");
}
}
class Tables
{
public static void main(String args[])
{
MulTableThread m1 = new MulTableThread(5);
MulTableThread m2 = new MulTableThread(7);
}
}