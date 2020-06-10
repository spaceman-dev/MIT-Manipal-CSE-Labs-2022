#include <stdio.h>
#include <stdlib.h>
#include "btree_rec.h"
void main()
{
int n,x,ch;
Node root;
root = NULL;
while(1)
{
printf("\n....................\n\n");
printf("<<<<<<<<<<<MENU>>>>>>>>>\n");
printf("Enter : \n1.Insert\n2.All traversals\n3.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter Node : \n");
scanf("%d",&x);
root = CreateBT();
break;
case 2:
printf("\nInorder Traversal : \n");
inorder(root);
printf("\nPreorder Traversal : \n");
preorder(root);
printf("\nPostorder Traversal : \n");
postorder(root);
printf("\n\n.......................");
break;
default:
exit(0);
}
}
}