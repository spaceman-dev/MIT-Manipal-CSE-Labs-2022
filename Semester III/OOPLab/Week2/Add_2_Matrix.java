import java.util.Scanner;
class Add_2_Matrix
{
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter Row and Column Dimension of Matrix : ");
int m = sc.nextInt();
int n = sc.nextInt();
int a[][] = new int[m][n];
int b[][] = new int[m][n];
int c[][] = new int[m][n];
System.out.println("Enter the Elements in the First Matrix");
for(int i = 0 ; i < m ; i++)
{
for(int j = 0 ; j < n ; j++)
	a[i][j] = sc.nextInt();
}
System.out.println("Enter the Elements in the Second Matrix");
for(int i = 0 ; i < m ; i++)
{
for(int j = 0 ; j < n ; j++)
	b[i][j] = sc.nextInt();
}
c = AddMat(a,b,m,n);
System.out.println("After Addition the Result is : ");
for(int i = 0 ; i < m ; i++)
{
for(int j = 0 ; j < n ; j++)
	System.out.print(c[i][j] + "  ");
System.out.println();
}
}
public static int[][] AddMat(int a[][] , int b[][] , int m , int n)
{
int c[][] = new int[m][n];
for(int i = 0 ; i < m ; i++)
{
for(int j = 0 ; j < n ; j++)
	c[i][j] = a[i][j]+b[i][j];
}
return c;
}
}
