public class JoinEx1 extends Thread
{
public void run()
{
System.out.println("I am Batman1 ");
try 
{
Thread.sleep(500);
}
catch(InterruptedException ie)
{ 
}
System.out.println("I am Batman2 ");
}
public static void main(String[] args)
{
JoinEx1 t1 = new JoinEx1();
JoinEx1 t2 = new JoinEx1();
t1.start();
try
{
t1.join();	
}
catch(InterruptedException ie)
{
}
t2.start();
}
}