import java.util.*;
import java.io.*;
import java.lang.*;
class Gen<T>
{
Gen(int x, int y, T ...ob)
{
for(int i = 0 ; i < ob.length ; i++)
{
if(i == (int)Math.min(x,y))
{
T temp = ob[i];
ob[i] = ob[y];
ob[y] = temp;
}
}
for(int i = 0 ; i < ob.length ; i++)
System.out.println(ob[i]);
}
}
class GenDemo
{
public static void main(String args[])
{
Gen<Integer>iOb;
iOb = new Gen<Integer>(1,2,3,4,5,6,7);
}
}