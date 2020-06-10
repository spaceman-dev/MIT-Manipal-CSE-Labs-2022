import java.util.Scanner;
import java.lang.*;
import java.io.*;
class Time1
{
int hr;
int min;
int sec;
public void input(int hr,int min, int sec)
{
this.hr = hr;
this.min = min;
this.sec = sec;
}
public void add(Time1 obj1, Time1 obj2)
{
Time1 ob = new Time1();
ob.hr = obj1.hr+obj2.hr;
ob.min = obj1.min+obj2.min;
ob.sec = obj1.sec+obj2.sec;
if(ob.sec>=60)
{
ob.min = ob.min+1;
ob.sec = ob.sec-60;
}
if(ob.min>=60)
{
ob.hr = ob.hr+1;
ob.min = ob.min-60;
}
if(ob.hr>=24)
{
ob.hr = ob.hr-24;
}
display(ob);
}
public void subtract(Time1 obj1,Time1 obj2) 
{
Time1 ob = new Time1();
ob.hr = (int) Math.abs(obj1.hr-obj2.hr);
ob.min = (int) Math.abs(obj1.min-obj2.min);
ob.sec = (int) Math.abs(obj1.sec-obj2.sec);
display(ob);
}
public void display(Time1 ob)
{
System.out.println(ob.hr+":"+ob.min+":"+ob.sec);
}
}
public class Time
{
public static void main(String[] args)
{
Time1 obj1 = new Time1();
Time1 obj2 = new Time1();
Time1 ob = new Time1();
obj1.input(2,59,59);
obj2.input(3,5,6);
ob.add(obj1,obj2);
ob.subtract(obj1,obj2);
}
}