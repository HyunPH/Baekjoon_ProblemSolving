#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_QUEUE_SIZE 5000
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE + 1];
	int front;
	int rear;
	int size;
}QueueType;

void init_queue(QueueType* q) {
	q->front = q->rear = q->size = 0;
}
void add_rear(QueueType* q, element item) {
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
	q->size++;
}
int delete_front(QueueType* q) {
	q->size--;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main()
{
	QueueType q;
	init_queue(&q);
	int N, K;
	scanf(" %d %d", &N, &K);

	for (int i = 0; i < N; i++)
		add_rear(&q, i + 1);
	
	printf("<");
	while(q.size != 0)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j == K) {
				if (q.size == 1) {
					printf("%d", delete_front(&q));
				}
				else
					printf("%d, ", delete_front(&q));
			}
			else
				add_rear(&q, delete_front(&q));
		}
	}
	printf(">");

	return 0;
}
