package p1;
import java.util.*;
class Maximum
{
public int max(int a , int b , int c)
{
int intmaxabc = (a > b) ? ( (a > c) ? a : c) : ((b > c) ? b : c);
return intmaxabc;
}
public float max(float a , float b , float c)
{
float floatmaxabc = (a > b) ? ( (a > c) ? a : c) : ((b > c) ? b : c);
return floatmaxabc;
}
public int max(int arr[])
{
int intmaxarr = arr[0];
for(int i = 0 ; i < arr.length ; i++)
{
if(intmaxarr < arr[i])
intmaxarr = arr[i];
}
return intmaxarr;
}
public int max(int matrix[][])
{
int intmaxmatrix = matrix[0][0];
for(int i = 0 ; i < matrix.length ; i++)
{
for(int j = 0 ; j < matrix[i].length ; j++)
{
if(intmaxmatrix < matrix[i][j])
intmaxmatrix = matrix[i][j];
}
}
return intmaxmatrix;
}
}
class Maximum1
{
public static void main(String arg[])
{
Scanner sc = new Scanner(System.in);
Maximum m1 = new Maximum();
System.out.println("Enter Three Integer Numbers : ");
int ai = sc.nextInt();
int bi = sc.nextInt();
int ci = sc.nextInt();
System.out.println("Maximum of '"+ai+"' , '"+bi+"' , '"+ci+"' = "+m1.max(ai,bi,ci));
System.out.println("Enter Three Floating Point Numbers : ");
float af = sc.nextFloat();
float bf = sc.nextFloat();
float cf = sc.nextFloat();
System.out.println("Maximum of '"+af+"' , '"+bf+"' , '"+cf+"' = "+m1.max(af,bf,cf));
System.out.println("Enter the Number of Elements in the Array : ");
int narr = sc.nextInt();
int arr[]= new int[narr];
System.out.println("Enter the Elements in the Array : ");
for(int i = 0 ; i < narr ; i++)
{
System.out.println("Enter the '"+(i+1)+"' Element of the Array : ");
arr[i] = sc.nextInt();
}
System.out.println("The Largest Element in the Array is = "+m1.max(arr));
System.out.println("Enter the Number of Rows in the Matrix : ");
int nmatrix = sc.nextInt();
System.out.println("Enter the Number of Columns in the Matrix : ");
int mmatrix = sc.nextInt();
int matrix[][] = new int[nmatrix][mmatrix];
System.out.println("Enter the Elements in the Matrix : ");
for(int i = 0 ; i < nmatrix ; i++)
{
for(int j = 0 ; j < mmatrix ; j++)
{
System.out.println("Enter the Element of the '"+(i+1)+"' Row and '"+(j+1)+"' Column of the Matrix : ");
matrix[i][j] = sc.nextInt();
}
}
System.out.println("The Largest Element in the Matrix = "+m1.max(matrix));
}
}