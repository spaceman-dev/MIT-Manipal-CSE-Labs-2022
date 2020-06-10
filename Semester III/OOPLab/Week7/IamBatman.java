import java.util.*;
interface Callable
{
void makeAudioCall(String cellNum);
void makeVideoCall(String cellNum);
}
class Phone implements Callable
{
String brand;
int memCapacity;
}
class BasicPhone extends Phone
{
void makeAudioCall(String cellNum)
{
System.out.println("You have made a AudioCall with the number : '"+cellNum+"' With the Brand : '"+brand+"' and the Capacity :'"+memCapacity+"' on a Basic Phone");
}
}
class SmartPhone extends Phone
{
void makeAudioCall(String cellNum)
{
System.out.println("You have made a AudioCall with the number : '"+cellNum+"' With the Brand : '"+brand+"' and the Capacity :'"+memCapacity+"' on a Smart Phone");
}
void makeVideoCall(String cellNum)
{
System.out.println("You have made a VideoCall with the number : '"+cellNum+"' With the Brand : '"+brand+"' and the Capacity :'"+memCapacity+"' on a Smart Phone");
}
}
class PhoneMain
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter Cell number : ");
String cn = sc.next();
System.out.println("Enter Brand : ");
String br = sc.next();
System.out.println("Enter memCapacity : ");
int mem = sc.next();
Phone sp = new SmartPhone();
}
}