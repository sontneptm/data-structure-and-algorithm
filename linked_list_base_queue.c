#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct linked_list {
	element data;
	struct linked_list* link;
}list;

typedef struct linked_list_base_queue {
	list* front;
	list* rear;
}queue;

void QInit(queue*);
int QIsEmpty(queue* que);
int QIsFull(queue* que);
void enqueue(queue *que, element);
element dequeue(queue*);
element QPeek(queue*);

void main() {
	queue que1;

	QInit(&que1);

	enqueue(&que1, 1);
	enqueue(&que1, 3);
	enqueue(&que1, 5);
	enqueue(&que1, 7);
	enqueue(&que1, 9);

	while (!QIsEmpty(&que1)) {
		printf("%d ",dequeue(&que1));
	}
}

void QInit(queue* que) {
	que->front = NULL;
	que->rear = NULL;
}

int QIsEmpty(queue* que) {
	if (que->front == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue(queue* que, element data) {
	list *new = (list*)malloc(sizeof(list));
	new->data = data;
	new->link = NULL;

	if (que->front == NULL) {
		que->front = new;
		que->rear = new;
	}
	else {
		que->rear->link = new;
		que->rear = que->rear->link;
	}
}

element dequeue(queue* que) {
	element tmp;

	if (que->front == NULL) {
		return -109;
	}
	else {
		tmp = que->front->data;
		que->front = que->front->link;
		return tmp;
	}
}