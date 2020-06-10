#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
int ex;
struct node *llink;
struct node *rlink;
};
typedef struct node *Node;
Node add(Node head , int n , int e)
{
Node temp,last;
temp = (Node)malloc(sizeof(struct node));
temp-> data = n;
temp->ex = e;
last = head->llink;
temp->llink = last;
last->rlink = temp;
temp->rlink = head;
head->llink = temp;
return head;
}
Node sum(Node h1 , Node h2 , Node h3)
{
Node one,two;
one = h1->rlink;
two = h2->rlink;
while(one!= h1 && two!=h2)
{
if(one->ex == two->ex)
{
h3 = add(h3,(one->data)+(two->data),one->ex);
one = one->rlink;
two = two->rliink;
}
else if(one->ex > two->ex)
{
h3 = add(h3,one->data,oe->ex);
one = one->rlink;
}
else
{
h3 = add(h3,two->data,two->ex);
two = two->rlink;
}
}
while(two != h2)
{
h3 = add(h3,two->data,two->ex);
two = two->rlink;
}
while(one != h1)
{
h3 = add(h3,one->data,one->ex);
one = one->rlink;
}
return h3;
}
void display(Node Head)
{
printf("The Contents of the List are : \n");
Node temp = Null;
temp = head->rlink;
while(temp != head)
{
printf("%d %d ",temp->data , temp->ex);
temp = temp->rlink;
}
}