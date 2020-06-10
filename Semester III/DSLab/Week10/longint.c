#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define SIZE 250

typedef enum { NO, YES } BOOL;

typedef struct Node {
	int value;
	struct Node * next;
	struct Node * prev;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode () {
	NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
	temp->value = 0;
	temp->prev = temp;
	temp->next = temp;
	return temp;
}

void insert (NODE_p_t list, int val) {
	NODE_p_t temp = createNode();
	
	NODE_p_t p = list->next;
	
	temp->value = val;
	temp->next = p;
	temp->prev = list;
	
	list->next = temp;
	p->prev = temp;
	
	(list->value)++;
}

void inputLongInteger (NODE_p_t li) {
	
	int i;
	char * longint = (char *)malloc(SIZE * sizeof(char));
	scanf(" %s", longint);
	
	for (i = (int)strlen(longint) - 1; i >= 0; --i)
		insert(li, *(longint + i) - '0');
	
}

NODE_p_t createAndInputLongInteger () {
	NODE_p_t li = createNode();
	inputLongInteger(li);
	return li;
}

NODE_p_t addLongIntegers (NODE_p_t lia, NODE_p_t lib) {
	NODE_p_t lic = createNode();
	
	int carry = 0, sum = 0;
	NODE_p_t tempa = lia->prev;
	NODE_p_t tempb = lib->prev;
	
	while (tempa != lia && tempb != lib) {
		sum = tempa->value + tempb->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(lic, sum);
		tempa = tempa->prev;
		tempb = tempb->prev;
	}
	while (tempa != lia) {
		sum = tempa->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(lic, sum);
		tempa = tempa->prev;
	}
	while (tempb != lib) {
		sum = tempb->value + carry;
		carry = sum / 10;
		sum = sum % 10;
		insert(lic, sum);
		tempb = tempb->prev;
	}
	if (carry != 0)
		insert(lic, carry);
	
	return lic;
}

void displayLongInteger (NODE_p_t longInteger, int maxSize) {
	int size;
	for (size = maxSize; size > longInteger->value; --size)
		printf("  ");
	
	NODE_p_t temp = longInteger->next;
	while (temp != longInteger) {
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

int max (int a, int b, int c) {
	return (a>b?((a>c)?a:c):(b>c)?b:c);
}

int main (int argc, const char * argv []) {
	
	printf("\n\tEnter A: ");
	NODE_p_t lia = createAndInputLongInteger();
	printf("\n\tEnter B: ");
	NODE_p_t lib = createAndInputLongInteger();
	
	NODE_p_t lic = addLongIntegers(lia, lib);
	
	int maxSize = max(lia->value, lib->value, lic->value);
	
	printf("\n\t    A =   ");
	displayLongInteger(lia, maxSize);
	printf("\n\t    B = + ");
	displayLongInteger(lib, maxSize);
	
	printf("\n\tA + B =   ");
	displayLongInteger(lic, maxSize);
	
	printf("\n\n");
	return 0;
}