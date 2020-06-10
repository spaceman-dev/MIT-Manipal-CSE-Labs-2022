#include<stdio.h> 
#include<stdlib.h> 
int *arr; 
int size; 
int top1, top2;
void twoStacksinit(int n);
void push1(int x);
void push2(int x);
int pop1();
int pop2();
void twoStacksinit(int n)  // initializer 
{ 
size = n; 
arr[n]; 
top1 = -1; 
top2 = size; 
} 
// Method to push an element x to stack1 
void push1(int x) 
{ 
// There is at least one empty space for new element 
if (top1 < top2 - 1) 
{ 
top1++; 
arr[top1] = x; 
} 
else
{ 
printf("Stack Overflow"); 
exit(0); 
} 
} 
// Method to push an element x to stack2 
void push2(int x) 
{ 
// There is at least one empty space for new element 
if (top1 < top2 - 1) 
{ 
top2--; 
arr[top2] = x; 
} 
else
{ 
printf("Stack Overflow"); 
exit(0); 
} 
} 
// Method to pop an element from first stack 
int pop1() 
{ 
if (top1 >= 0 ) 
{ 
int x = arr[top1]; 
top1--; 
return x; 
} 
else
{ 
printf("Stack UnderFlow"); 
exit(0); 
} 
} 
// Method to pop an element from second stack 
int pop2() 
{ 
if (top2 < size) 
{ 
int x = arr[top2]; 
top2++; 
return x; 
} 
else
{ 
printf("Stack UnderFlow"); 
exit(0); 
} 
} 
/* Driver program to test twStacks class */
int main() 
{ 
twoStacksinit(100);
push1(5); 
push2(10); 
push2(15); 
push1(11); 
push2(7); 
printf("Popped element from stack1 is %d\n",pop1()); 
push2(40); 
printf("\nPopped element from stack2 is %d\n",pop2()); 
return 0; 
} 
