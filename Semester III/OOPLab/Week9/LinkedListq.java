import java.util.*;

class LinkedListNode<T> 
{
	private T value;
	private LinkedListNode<T> next;

	public LinkedListNode(T value) 
	{
		this.value = value;
	}

	public void setNext(LinkedListNode<T> next) 
	{
		this.next = next;
	}

	public LinkedListNode<T> getNext() 
	{
		return next;
	}

	public T getValue() 
	{
		return value;
	}
}

public class LinkedListq<T> 
{

	private LinkedListNode<T> first = null;

	public void insert(LinkedListNode<T> node) 
	{
		node.setNext(first);
		first = node;
	}
	public void remove()
	{
		if(first.getNext()!=null)
			first = first.getNext();
		else first = null;
	}
	private void printList(LinkedListNode<T> node) 
	{
		System.out.println("Node is " + node.getValue());
		if(node.getNext()!=null) 
			printList(node.getNext());
	}

	public void print()
	{
		printList(first);
	}
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		LinkedListq<Integer> list = new LinkedListq<Integer>();
		System.out.println("Integer LL:");
		list.insert(new LinkedListNode<Integer>(1));
		list.insert(new LinkedListNode<Integer>(2));
		list.print();
		list.remove();
		System.out.println("After removing the head..");
		list.print();
		System.out.print("Enter integer to insert: ");
		int a=sc.nextInt();
		list.insert(new LinkedListNode<Integer>(a));
		System.out.println("After insertion:");
		list.print();
		LinkedListq<Double> list1 = new LinkedListq<Double>();
		System.out.println("\nDouble LL:");
		list1.insert(new LinkedListNode<Double>(1.1));
		list1.insert(new LinkedListNode<Double>(2.2));
		list1.print();
		list1.remove();
		System.out.println("After removing the head..");
		list1.print();
	}
}
