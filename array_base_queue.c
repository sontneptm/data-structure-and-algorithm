#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct arrayBaseQueue {
	element arr[MAX_QUEUE_SIZE];
	int front;
	int rear;
}queue;

void QInit(queue*);
int QIsEmpty(queue*);
void enqueue(queue*, element);
element dequeue(queue*);
element QPeek(queue*);

void main() {
	queue que1;

	QInit(&que1);

	enqueue(&que1, 1);
	enqueue(&que1, 3);
	enqueue(&que1, 5);
	enqueue(&que1, 7);

	while (!QIsEmpty(&que1))
		printf("%d ", dequeue(&que1));
}

void QInit(queue *que) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		que->arr[i] = 0;
	}
	que->front = 0;
	que->rear = 0;
}

int QIsEmpty(queue *que) {
	if (que->front%MAX_QUEUE_SIZE == que->rear%MAX_QUEUE_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue(queue *que, element data) {
	que->rear = (que->rear + 1) % MAX_QUEUE_SIZE;

	if ((que->rear) % MAX_QUEUE_SIZE == (que->front) % MAX_QUEUE_SIZE) {
		printf("Å¥°¡ °¡µæ Ã¡½À´Ï´Ù. \n");
	}
	else {
		que->arr[que->rear] = data;
	}
}

element dequeue(queue *que) {
	element tmp;

	que->front = (que->front + 1) % MAX_QUEUE_SIZE;
	tmp = que->arr[que->front];
	que->arr[que->front] = 0;
	return tmp;
}



