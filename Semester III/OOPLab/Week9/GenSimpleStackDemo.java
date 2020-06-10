class Student{
int rNo;
String name;
Student(int r,String n){
rNo=r;
name=n;
}
public String toString(){
return("name:"+name + ";\t RollNo: "+rNo +"\n");
}
}
//Only Student given here also do for employee
// A generic interface for a simple stack.
 interface IGenSimpleStack<T> {

  // Push an item onto the stack.
  void push(T item) throws StackFullException;

  // Pop an item from the stack.
  T pop() throws StackEmptyException;

  // Return true if the stack is empty.
  boolean isEmpty();

  // Return true if the stack is full.
  boolean isFull();
}

// An exception for stack-full errors.
class StackFullException extends Exception {
  int size;

  StackFullException(int s) {
    super("Stack Full");
    size = s;
  }

  public String toString() {
    return "\nStack is full. Maximum size is " + size;
  }
}

// An exception for stack-empty errors.
class StackEmptyException extends Exception {

  StackEmptyException() {
    super("Stack Empty");
  }

  public String toString() {
    return "\nStack is empty.";
  }
}

// A simple generic fixed-length stack.
class GenSimpleStack<T> implements IGenSimpleStack<T> {
  private T data[]; // this array holds the stack
  private int tos; // index of top of stack

  // Construct an empty stack with the given array as storage.
 GenSimpleStack(T[] arrayRef) {
    data = arrayRef ;
    tos = 0;
  }

  // Push an item onto the stack.
  public void push(T obj) throws StackFullException {
    if(isFull())
      throw new StackFullException(data.length);

    data[tos] = obj;
    tos++;
  }

  // Pop an item from the stack.
  public T pop() throws StackEmptyException {
    if(isEmpty())
      throw new StackEmptyException();

    tos--;
    return data[tos];
  }

  // Return true if the stack is empty.
  public boolean isEmpty() {
    return tos==0;
  }

  // Return true if the stack is full.
  public boolean isFull() {
    return tos==data.length;
  }
}

/*
    Try This 14-1

    Demonstrate a simple generic stack class.
*/

class GenSimpleStackDemo {
  public static void main(String[] args) {
    int i;
    //Integer[] nums = new Integer[5];
    //String[] strs = new String[3];
    Student[] st =new Student[3];


GenSimpleStack<Student> stck = new GenSimpleStack<Student>(st);

    System.out.println("\nDemonstrating Student stack.");

    // now, use strStack
    try {

      System.out.println("Pushing: Student");

      // push strings onto strStack
      stck.push(new Student(5,"anand"));
      stck.push(new Student(6,"anu"));
      stck.push(new Student(7,"anil"));

      // pop Strings off strStack
      System.out.print("Popping: ");
      while(!stck.isEmpty())
        System.out.print(stck.pop() + " ");

      System.out.println();
    } catch (StackFullException exc) {
      System.out.println(exc);
    } catch (StackEmptyException exc) {
      System.out.println(exc);
    }    System.out.println();
  }
}
