import java.util.*;
import java.io.*;
class SeatsFilledException extends Exception
{
public SeatsFilledException()
{
}
public String toString()
{
return "Excess Students!!Seats Full!!";
}
}
class Student
{
int rgno;
String name;
short sem;
float gpa;
float cgpa;
int year;
int month;
int dayOfMonth;
String months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
GregorianCalendar gcal = new GregorianCalendar(year,month,dayOfMonth);
public Student()
{
rgno = 0;
name = null;
sem = 0;
gpa = 0;
cgpa = 0;
year = 2000;
month = 0;
dayOfMonth = 0;
}
public Student(int r, String n, int y, int m, int d, short s, float g, float c)
{
rgno = r;
name = n;
year = y;
month = m;
dayOfMonth = d;
sem = s;
gpa = g;
cgpa = c;
}
public void disp()
{
System.out.println("...........................");
System.out.println("Registration Number : "+rgno);
System.out.println("Name : "+name);
System.out.println("Date of Joining : "+ months[gcal.get(Calendar.MONTH)] +" "+ gcal.get(Calendar.DATE) + ", "+ gcal.get(Calendar.YEAR));
System.out.println("Semester : "+sem);
System.out.println("GPA : "+gpa);
System.out.println("CGPA : "+cgpa);
}
}
class Student1
{
public static void main(String args[])throws SeatsFilledException
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter the number of Student Records : ");
int n = sc.nextInt();
Student s[] = new Student[n];
for(int i = 0 ; i < n ; i++)
{
if(i>25)
throw(new SeatsFilledException());
s[i] = new Student();
System.out.println("Enter the Student Records of the '"+(i+1)+"' Student :");
System.out.println("Enter Name : ");
s[i].name = sc.next();
System.out.println("Enter Date of Joining : ");
System.out.println("Enter Day : ");
s[i].dayOfMonth = sc.nextInt();
System.out.println("Enter Month : ");
s[i].month = sc.nextInt();
System.out.println("Enter Year : ");
s[i].year = sc.nextInt();
String rg = (s[i].year-2000)+""+(i+1);
s[i].rgno = Integer.parseInt(rg);
System.out.println("Enter Semester : ");
s[i].sem = sc.nextShort();
System.out.println("Enter GPA : ");
s[i].gpa = sc.nextFloat();
System.out.println("Enter CGPA : ");
s[i].cgpa = sc.nextFloat();
}
Student temp = new Student();
System.out.println("................MENU...................");
System.out.println("Enter 1 to Sort the Student Records With Respect to the Semester");
System.out.println("Enter 2 to Sort the Student Records With Respect to the CGPA");
System.out.println("Enter 3 to Sort the Student Records With Respect to the Name");
System.out.println("Enter Your Choice : ");
int ch = sc.nextInt();
switch(ch)
{
case 1:
for(int i = 0 ; i < n ; i ++)
{
for(int j = 0 ; j < n-1 ; j++)
{
if(s[j].sem<s[j+1].sem)
{
temp = s[j];
s[j] = s[j+1];
s[j+1] = temp;
}
}
}
System.out.println("Sorting Student Records With Respect to Semester...");
for(int i = 0 ; i < n ; i++)
s[i].disp();
break;
case 2:
for(int i = 0 ; i < n ; i ++)
{
for(int j = 0 ; j < n-1 ; j++)
{
if(s[j].cgpa<s[j+1].cgpa)
{
temp = s[j];
s[j] = s[j+1];
s[j+1] = temp;
}
}
}
System.out.println("Sorting Student Records With Respect to CGPA...");
for(int i = 0 ; i < n ; i++)
s[i].disp();
break;
case 3:
for(int i = 0 ; i < n ; i ++)
{
for(int j = 0 ; j < n-1 ; j++)
{
if(s[j].name.compareTo(s[j+1].name)<0)
{
temp = s[j];
s[j] = s[j+1];
s[j+1] = temp;
}
}
}
System.out.println("Sorting Student Records With Respect to Name...");
for(int i = 0 ; i < n ; i++)
s[i].disp();
break;
default :
System.out.println("WRONG CHOICE");
}
System.out.println("..............MENU............");
System.out.println("Enter 1 to List all Students Whose Name Starts With a Particular Character");
System.out.println("Enter 2 to List all Students Whose Names Contain a Particular Sub String");
System.out.println("Enter 3 to Change All Student Names to initials");
System.out.println("Enter Your Choice : ");
int ch1 = sc.nextInt();
switch(ch1)
{
case 1:
System.out.println("Enter a Character : ");
String c = sc.next();
for(int i = 0 ; i < n ; i++)
{
if(s[i].name.startsWith(c))
	System.out.println(s[i].name);
}
break;
case 2:
System.out.println("Enter a Substring :");
String s1 = sc.next();
for(int i = 0 ; i < n ; i++)
{
if(s[i].name.indexOf(s1)!=-1)
    System.out.println(s[i].name);
}
break;
case 3:
for(int i = 0 ; i < n ; i++)
{
int x = s[i].name.indexOf(' ');
System.out.print(s[i].name.charAt(0)+".");
System.out.print(s[i].name.charAt(x+1)+".");
x = s[i].name.lastIndexOf(' ');
System.out.println(s[i].name.substring(x+1));
}
break;
default:
System.out.println("Wrong Choice !");
}
for(int i = 0 ; i < n ; i++)
s[i].disp();
}
}
