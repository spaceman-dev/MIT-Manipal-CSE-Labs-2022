import java.util.*;
import static java.lang.System.*;

class Q1
{ 
	
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		//Integer[] arr ={
		//for(int i = 0 ; i < 4 ; i++)
			//.nextInt();};
		//for(int i = 0 ; i < 6 ; i++)
		//	arr[i] = i;
		Integer[] intarr={1,2,3,4,5};
		out.println("Array int:");
		print(intarr);
		out.println("Enter positions to exchange");
		int a=sc.nextInt();
		int b=sc.nextInt();
		swap(intarr,a,b);

		Character[] chararr={'h','e','l','l','o'};
		out.println("Array char:");
		print(chararr);
		out.println("Enter positions to exchange");
		int c=sc.nextInt();
		int d=sc.nextInt();
		swap(chararr,c,d);
	}
	public static <E> void print(E[] input)
	{
		for(E ele:input)
			out.printf("%s ",ele);
		out.println();
	}
	public static <E> void swap(E[]input,int a,int b)
	{
		E temp;
		temp=input[a];
		input[a]=input[b];
		input[b]=temp;
		out.println("Swapped:");
		print(input);
	}
}