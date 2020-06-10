#include <stdio.h>
#include <stdlib.h>
typedef struct bst* bstptr;
typedef struct bst
{
int data;
bstptr lchild;
bstptr rchild;
}bst;
bstptr root = NULL;
bstptr insert(int element, bstptr node)
{
bstptr temp;
if(node == NULL)
{
temp = (bstptr) malloc(sizeof(bst));
temp->data = element;
temp->lchild = NULL;
temp->rchild = NULL;
if(root == NULL)
	root = temp;
return temp;
}
else if(element < node->data)
{
node->lchild = insert(element, node->lchild);
return node;
}
else if(element > node->data)
{
node->rchild = insert(element, node->rchild);
return node;
}
else
{
printf("Duplicate Element found while inserting!\n");
return NULL;
}
}
void inorder(bstptr node)
{
if(node == NULL)
	return;
inorder(node->lchild);
printf("%d ",node->data);
inorder(node->rchild);
}
void preorder(bstptr node)
{
if(node == NULL)
	return;
printf("%d ",node->data);
preorder(node->lchild);
preorder(node->rchild);
}
void postorder(bstptr node)
{
if(node == NULL)
	return;
postorder(node->lchild);
postorder(node->rchild);
printf("%d ",node->data);
}
void search(int key,bstptr node)
{
if(node==NULL)
{
printf("Key not found!!\n");
node = insert(key,root);
return;
}
else
{
if(key == node->data)
{
printf("Key , '%d' found!\n",key);
return;
}
else if(key>node->data)
	search(key,node->rchild);
else if(key<node->data)
	search(key,node->lchild);
}
}
void main()
{
int element;
int key;
int ch = 1;
while(ch == 1)
{
printf("Enter Element to Insert in Binary Search Tree : \n");
scanf("%d", &element);
insert(element, root);
printf("Enter 1 to Insert in Binary Search Tree else Enter 0 to Stop : \n");
scanf("%d", &ch);
}
printf("..........PREORDER.......... : \n");
preorder(root);
printf("\n...........POSTORDER......... : \n");
postorder(root);
printf("\n............INORDER............ : \n");
inorder(root);
printf("\nEnter Element to Search in Binary Search Tree : \n");
scanf("%d", &key);
search(key,root);
}