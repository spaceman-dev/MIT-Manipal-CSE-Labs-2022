#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define UNDERFLOW_CHAR '\0'
typedef struct Node {
	int data;
	struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;
NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->next = temp;
	temp->data = 0;;
	return temp;
}

void insert (NODE_p_t list, int item) {
	NODE_p_t temp = createNode();
	NODE_p_t p;
	
	temp->data = item;
	temp->next = list;
	
	if (list->next == list)
		list->next = temp;
	
	else {
		p = list->next;
		
		while (p->next != list)
			p = p->next;
		p->next = temp;
		
	}
}

NODE_p_t removedup(NODE_p_t first)
{
NODE_p_t temp,temp1,prev,ptr;
ptr = first;
while(ptr)
{
temp = ptr->next;
while(temp)
{
temp1 = temp;
prev = first;
while(prev)
{
if(prev->next == temp)
break;
prev = prev->next;
}
if(temp->data == ptr->data)
{
temp1 = temp;
prev->next = temp->next;
free(temp1);
}
temp = temp->next;
}
ptr = ptr->next;
}
return first;
}
void display (NODE_p_t list) {
	NODE_p_t temp = list->next;
	
	if (temp != list)  {
		while (temp->next != list) {
			printf(" %d ->", temp->data);
			temp = temp->next;
		}
		printf(" %d", temp->data);
		temp = temp->next;
	}
}
int main () {
	
	NODE_p_t list1 = createNode();
	int i, n;
	int item;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	printf("Enter List elements: ");
	for (i = 0; i < n; i++) {
		printf("Enter %d Ele :\n",i);
		scanf("%d", &item);
		insert(list1, item);
	}
	display(list1);
	list1 = removedup(list1);
	display(list1);
	return 0;
	}