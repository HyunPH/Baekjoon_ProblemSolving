#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_DEQUE_SIZE 10000
typedef int element;
typedef struct {
	element data[MAX_DEQUE_SIZE + 1];
	int front;
	int rear;
}Dequetype;

//: 덱 초기화
void init_deque(Dequetype* q) {
	q->front = q->rear = 0;
}
//: 정수 X를 덱의 앞에 넣는다.
void push_front(Dequetype* q, element item) {
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}
//: 정수 X를 덱의 뒤에 넣는다.
void push_back(Dequetype* q, element item) {
	q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
	q->data[q->rear] = item;
}
//: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int pop_front(Dequetype*q) {
	if (empty(q)) {
		return -1;
	}
	q->front = (q->front + 1) % MAX_DEQUE_SIZE;
	return q->data[q->front];
}
//: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int pop_back(Dequetype* q) {
	if (empty(q)) {
		return -1;
	}
	int temp = q->rear;
	q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return q->data[temp];
}
//: 덱에 들어있는 정수의 개수를 출력한다.
int size(Dequetype* q) {
	if (q->rear < q->front){
		return q->rear - q->front + MAX_DEQUE_SIZE;
	}
	return q->rear - q->front;
}
//: 덱이 비어있으면 1을, 아니면 0을 출력한다.
int empty(Dequetype* q) {
	if (q->front == q->rear){
		return 1;
	}
	return 0;
}
//: 덱의 가장 앞에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int front(Dequetype* q) {
	if (empty(q)) {
		return -1;
	}
	return q->data[(q->front + 1) % MAX_DEQUE_SIZE] ;
}
//: 덱의 가장 뒤에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
int back(Dequetype* q) {
	if (empty(q)) {
		return -1;
	}
	return q->data[q->rear];
}


int main()
{
	Dequetype D;
	init_deque(&D);

	char input[12];
	int N, input_item;
	scanf(" %d", &N);

	while (N--)
	{
		scanf("%s", input);
		if (!strcmp(input, "push_front")) {
			scanf("%d", &input_item);
			push_front(&D, input_item);
		}
		else if (!strcmp(input, "push_back")) {
			scanf("%d", &input_item);
			push_back(&D, input_item);
		}
		else if (!strcmp(input, "pop_front")) {
			printf("%d\n", pop_front(&D));
		}
		else if (!strcmp(input, "pop_back")) {
			printf("%d\n", pop_back(&D));
		}
		else if (!strcmp(input, "size")) {
			printf("%d\n", size(&D));
		}
		else if (!strcmp(input, "empty")) {
			printf("%d\n", empty(&D));
		}
		else if (!strcmp(input, "front")) {
			printf("%d\n", front(&D));
		}
		else if (!strcmp(input, "back")) {
			printf("%d\n", back(&D));
		}
	}
	return 0;
}
