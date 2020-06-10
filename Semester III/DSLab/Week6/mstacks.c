#define MEMORY_SIZE 20/* size of memory */
#define MAX_STACK_SIZE 2
              /* max number of stacks plus 1 */
/* global memory declaration */
element memory[MEMORY_SIZE];
int top[MAX_STACKS];
int boundary[MAX_STACKS];
int n; /* number of stacks entered by the user */


top[0] = boundary[0] = -1;
for (i = 1; i < n; i++)
  top[i] =boundary[i] =(MEMORY_SIZE/n)*i;
boundary[n] = MEMORY_SIZE-1;
void push(int i, element item)
{
    /* add an item to the ith stack */
    if (top[i] == boundary [i+1])
        stack_full(i);     may have unused storage
        memory[++top[i]] = item;
}
//*Program 3.12:Add an item to the stack stack-no (p.129)

element pop(int i)
{
    /* remove top element from the ith stack */
    if (top[i] == boundary[i])
       return stack_empty(i);
    return memory[top[i]--];
} 