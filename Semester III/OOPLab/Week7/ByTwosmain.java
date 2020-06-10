import java.util.*;
interface Series
{
int getNext(int v);
int reset();
int setStart();
}
class ByTwos implements Series
{
int start;
ByTwos()
{
start=0;
}
public int getNext(int v)
{
return v+2;
}
public int setStart(){
Scanner sc=new Scanner(System.in);
System.out.println("Enter new start"); 
start=sc.nextInt(); 
return start;
}
public int reset()
{
System.out.println();
return start;
}
}
public class ByTwosmain
{
public static void main(String []args)
{
Scanner sc=new Scanner(System.in);
Series s=new ByTwos();
boolean flag=true;
int sw;
int ele=0;
ele=s.setStart();
while(flag)
{
System.out.println("\n...........MENU...........\n1:setStart\n2:getNext\n3:reset\n4:Exit");
System.out.println("Enter choice"); 
sw=sc.nextInt();
switch(sw)
{
case 1: 
ele=s.setStart(); 
break;
case 2:
ele=s.getNext(ele);
System.out.println(ele+" "); 
break;
case 3:
ele=s.reset();
System.out.println(ele);
break;
case 4:
System.out.println("................BYE................");
flag=false;
break;
default:
System.out.println("Wrong Choice!!");
}
}
}
}