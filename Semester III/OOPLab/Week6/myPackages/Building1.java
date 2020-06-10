package com.course.structure;
import java.util.*;
class Building
{
private double sqftg;
private int stories;
public void setsqftg(double x)
{
sqftg = x;
}
public void setstories(int x)
{
stories = x;
}
public double getsqftg()
{
return sqftg;
}
public int getstories()
{
return stories;
}
}
class House extends Building
{
private int bed;
private int bath;
public void setbed(int x)
{
bed = x;
}
public void setbath(int x)
{
bath = x;
}
public double getbed()
{
return bed;
}
public int getbath()
{
return bath;
}
}
class School extends Building
{
private int noclass;
private String gradelevel;
public void setnoclass(int x)
{
noclass = x;
}
public void setgradelevel(String x)
{
gradelevel = x;
}
public int getnoclass()
{
return noclass;
}
public String getgradelevel()
{
return gradelevel;
}
}
class Building1
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
Building b1 = new Building();
House h1 = new House();
School s1 = new School();
System.out.println("Enter Square Footage Area of Building : ");
double sq = sc.nextDouble();
b1.setsqftg(sq);
System.out.println("Enter Number of Stories of Building : ");
int st = sc.nextInt();
b1.setstories(st);
System.out.println("Enter Number of BedRooms in House : ");
int bd = sc.nextInt();
h1.setbed(bd);
System.out.println("Enter Number of BathRooms in House : ");
int bt = sc.nextInt();
h1.setbath(bt);
System.out.println("Enter Number of ClassRooms in School : ");
int cr = sc.nextInt();
s1.setnoclass(cr);
System.out.println("Enter the Grade Level of School : ");
String gl = sc.next();
s1.setgradelevel(gl);
System.out.println("Square Footage of Building = "+b1.getsqftg());
System.out.println("Number of Stories of Building = "+b1.getstories());
System.out.println("Number of BedRooms in House = "+h1.getbed());
System.out.println("Number of BathRooms in House = "+h1.getbath());
System.out.println("Number of ClassRooms in School = "+s1.getnoclass());
System.out.println("Grade Level of School = "+s1.getgradelevel());
}
}