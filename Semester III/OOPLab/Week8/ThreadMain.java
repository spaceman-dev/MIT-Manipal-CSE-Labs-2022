import java.util.*;
import java.io.*;
import java.lang.*;
class ThreadDemoPriority extends Thread
{
public void run(ThreadDemoPriority T)
{
System.out.println("Inside the Run Method with the Thread '"+T+"'.");
}
}
class ThreadMain
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter the Number of Threads : ");
int n = sc.nextInt();
ThreadDemoPriority t[] = new ThreadDemoPriority[n];
for(int i = 0 ; i < n ; i++)
	t[i] = new ThreadDemoPriority();
for(int i = 0 ; i < n ; i++)
	System.out.println("The Thread '"+(i+1)+"' has a priority of '"+t[i].getPriority()+"'");
for(int i = 0 ; i < n ; i++)
{
System.out.println("Enter the Priority you wish to assign to the Thread '"+(i+1)+"' : ");
t[i].setPriority(sc.nextInt());
}
for(int i = 0 ; i < n ; i++)
	System.out.println("The Thread '"+(i+1)+"' has a priority of '"+t[i].getPriority()+"'");
ThreadDemoPriority x = new ThreadDemoPriority();
for(int i = 0 ; i < n ; i++)
	x.run(t[i]);
System.out.println("The Main Thread : ");
System.out.println(Thread.currentThread().getName());
System.out.println("The Main Thread Priority = "+Thread.currentThread().getPriority());
System.out.println("Enter the Priority you wish to assign to the Main Thread : ");
Thread.currentThread().setPriority(sc.nextInt());
System.out.println("The new Main Thread Priority = "+Thread.currentThread().getPriority());
System.out.println("END");
}
}