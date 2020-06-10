
#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node* left;
struct Node* right;
};
typedef struct Node Node;
Node* getNode(int data)
{
Node* t = (Node*)malloc(sizeof(Node));
t->data = data;
t->left = t->right = NULL;
return t;
}
int getNum(Node* t)
{
if(t == NULL)
    return 0;
else
    return 1 + getNum(t->left) + getNum(t->right);
}
void main()
{
Node* root = getNode(5);
root->right = getNode(10);
root->left = getNode(3);
root->right->left = getNode(7);
root->right->right = getNode(12);
root->left->right = getNode(4);
root->left->left = getNode(2);
printf("The Number of Nodes of the Binary Tree is : %d\n", getNum(root));
}