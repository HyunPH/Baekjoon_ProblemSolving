#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	int idx;
}StackElement;

int top = -1; // 스택 초기화, 전역변수

int is_empty(StackElement* s) {
	return (top == -1);
}
void push_stack(StackElement* s, int item, int idx) {
	s[++top].data = item;
	s[top].idx = idx;
}
int pop_stack(StackElement* s) {
	return s[top--].data;
}


int main()
{
	int N;
	scanf("%d", &N);
	
	StackElement* stack = (StackElement*)malloc(N * sizeof(StackElement));
	
	int* arr = (int*)malloc(N * sizeof(int)); /*입력 배열*/
	int* resurt = (int*)malloc(N * sizeof(int)); /*출력할 배열*/

	for (int i = 0; i < N; i++) {
		scanf(" %d", &arr[i]);
		resurt[i] = -1; /* 초기화 */

	}
	for (int i = 0; i < N; i++) {
		while (!is_empty(stack) && arr[i] > stack[top].data) { /*스택이 비어있고, 검사할 원소가 top보다 클 때 즉 큰 조건이 만족할 때*/
			resurt[stack[top].idx] = arr[i]; /* 결과 배열에 원소 추가 */
			//printf("arr[i]:%d, resurt[%d]:%d\n", arr[i], stack[top].idx, resurt[stack[top].idx]);
			pop_stack(stack);
		}
		//printf("%d\n", arr[i]);
		push_stack(stack, arr[i], i); // 데이터, 인덱스위치 전달
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", resurt[i]);
	}

	free(stack);
	free(arr);
	free(resurt);
	return 0;
}
