
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3
#define UNDERFLOW_CHAR '\0'

#define initString(size) (String)malloc(size * sizeof(char))

/// Boolean type, just for readability

typedef enum { NO, YES } BOOL;

typedef char * String;

typedef struct CircularQueue {
	String *arr;
	int front;
	int rear;
} CQUEUE_t, *CQUEUE_p_t;

CQUEUE_p_t initQueue (int size) {
	CQUEUE_p_t queue = (CQUEUE_p_t)calloc(SIZE, sizeof(CQUEUE_t));
	queue->arr = (String *)calloc(SIZE, sizeof(String));
	queue->front = queue->rear = -1;
	return queue;
}

// Queue methods

BOOL isFullQueue (CQUEUE_t queue) {
	if ((queue.rear + 1)%SIZE == queue.front)
		return YES;
	return NO;
}

BOOL isEmptyQueue (CQUEUE_t queue) {
	if (queue.front == -1)
		return YES;
	return NO;
}

void insert (CQUEUE_p_t queue, String item) {
	if (isFullQueue(*queue)) {
		printf("\n\tQUEUE OVERFLOW!\n\n");
		return;
	}
	
	if (isEmptyQueue(*queue))
		queue->front = queue->rear = 0;
	else
		queue->rear = (queue->rear + 1)%SIZE;
	
	*(queue->arr + queue->rear) = item;
}

String delete (CQUEUE_p_t queue) {
	if (isEmptyQueue(*queue)) {
		printf("\n\tQUEUE UNDERFLOW!\n\n");
		return UNDERFLOW_CHAR;
	}
	
	String item = *(queue->arr + queue->front);
	
	if (queue->front == queue->rear)
		queue->front = queue->rear = -1;
	else
		queue->front = (queue->front + 1)%SIZE;
	
	return item;
}

void display (CQUEUE_t queue) {
	if (isEmptyQueue(queue))
		printf("\n\tEMPTY QUEUE!\n");
	else {
		printf("\n | Current Queue : ");
		int i;
		for (i = queue.front; i != queue.rear; i = (i+1)%SIZE)
			printf("\t%s", *(queue.arr + i));
		printf("\t%s\n", *(queue.arr + i));
	}
}


int main(int argc, const char * argv[]) {
	
	CQUEUE_p_t queue = initQueue(SIZE);
	
	char choice;
	int flag = 1;
	//do {
	while(flag == 1)
	{
		printf("\n------------------------------------------------------------\n | 1. Insert\n | 2. Delete\n | 3. Display Queue.\n | Q. Quit\n | Enter choice : ");
		scanf(" %c", &choice);
		
		String item = initString(SIZE);
		
		if (choice == '1') {
			printf("\n | Enter item to be inserted: ");
			scanf("%s", item);
			insert(queue, item);
		}
		else if (choice == '2') {
			item = delete(queue);
			if (item != UNDERFLOW_CHAR)
				printf("\n | Deleted item: '%s'.\n", item);
		}
		else if(choice == 'Q')
			flag = 0;
		display(*queue);
		}
	//}while(choice == '1' || choice == '2' || choice == '3');
	}
