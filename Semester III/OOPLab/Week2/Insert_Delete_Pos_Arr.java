import java.util.Scanner;
class Insert_Delete_Pos_Arr
{
public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter length of array : ");
int n = sc.nextInt();
int arr[] = new int[n+1];
for(int i = 0 ; i < n ; i++)
{
System.out.println("Enter Element at position : "+i);
arr[i] = sc.nextInt();
}
System.out.println("Enter 0 to Insert Element. Enter 1 to Delete Element. : ");
int choice = sc.nextInt();
if(choice == 0)
{
System.out.println("Enter the Element to be Added : ");
int ele = sc.nextInt();
System.out.println("Enter the Position of the Element to be Added : ");
int pos = sc.nextInt();
for(int i = n-1 ; i >= (pos-1); i--)
	arr[i+1] = arr[i];
arr[pos] = ele;
System.out.println("The Array is : ");
for(int i = 0 ; i < n ; i++)
System.out.print(arr[i]+", ");
System.out.println(arr[n]+". ");
}
else if(choice == 1)
{
System.out.println("Enter the Position of the Element to be Deleted : ");
int po = sc.nextInt();
for(int i = po ; i < n-1 ; i++)
	arr[i] = arr[i+1];
System.out.println("The Array is : ");
for(int i = 0 ; i < n-2 ; i++)
System.out.print(arr[i]+", ");
System.out.println(arr[n-1]+". ");
}
}
}
