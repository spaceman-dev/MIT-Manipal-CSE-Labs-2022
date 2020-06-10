import java.util.*;
class Phone
{
String brand; int memCap;
Phone()
{
brand=null;
memCap=0;
}
Phone(String b,int m)
{
brand=b;
memCap=m;
}
public interface Callable
{
public void makeAudioCall(String cellNum);
public void makeVideoCall(String cellNum);
}
}
class BasicPhone extends Phone implements Phone.Callable
{
BasicPhone()
{
super();
}
BasicPhone(String s,int m)
{
super(s,m);
}
public void makeAudioCall(String cellNum)
{
System.out.println("Calling "+cellNum);
}
public void makeVideoCall(String cellNum)
{
System.out.println("Video Call not available in this device");
}
}
class SmartPhone extends Phone implements Phone.Callable
{
SmartPhone()
{
super();
}
SmartPhone(String s,int m)
{
super(s,m);
}
public void makeAudioCall(String cellNum)
{
System.out.println("Calling "+cellNum);
}
public void makeVideoCall(String cellNum)
{
System.out.println("Calling "+cellNum);
}
}
class Phonemain
{
public static void main(String arg[])
{
System.out.println("Enter cellNumber to call to: ");
Scanner sc=new Scanner(System.in);
String s=sc.next();
int p;
System.out.println("Enter\n1:BasicPhone\n2:SmartPhone");
p=sc.nextInt();
System.out.println("Enter\n1:makeAudioCall\n2:makeVideoCall");
int call=sc.nextInt();
System.out.println("Enter brand and Memory Capacity");
String br=sc.next(); 
int memCap=sc.nextInt();
switch(p)
{
case 1:
BasicPhone bp=new BasicPhone(br,memCap);
switch(call)
{
case 1: bp.makeAudioCall(s); break;
case 2: bp.makeVideoCall(s); break;
default: System.out.println("Invalid Input");
}
break;
case 2:
SmartPhone sp=new SmartPhone(br,memCap);
switch(call)
{
case 1: sp.makeAudioCall(s); break;
case 2: sp.makeVideoCall(s); break;
default: System.out.println("Invalid Input");
}
break;
default: System.out.println("Invalid");
}
}
}