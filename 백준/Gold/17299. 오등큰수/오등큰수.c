#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cnt[1000001] = { 0, };

typedef struct {
	int* stack;
	int top;
}Stack_idx;

int is_empty(Stack_idx* s) {
	return (s->top == -1);
}
void push_stack(Stack_idx* s, int idx) {
	s->stack[++s->top] = idx;
}
int pop_stack(Stack_idx* s) {
	return s->stack[s->top--];
}
int get_top(Stack_idx* s) {
	return s->stack[s->top];
}

int main()
{
	int N;
	scanf("%d", &N);
	
	Stack_idx S;
	S.stack = (int*)malloc(N*sizeof(int)); // 스택 크기 동적할당
	S.top = -1;

	int* arr = (int*)malloc(N * sizeof(int)); /*입력 배열*/
	int* resurt = (int*)malloc(N * sizeof(int)); /*출력할 배열*/

	for (int i = 0; i < N; i++) {
		scanf(" %d", &arr[i]);
		cnt[arr[i]]++; // 입력 받을 때마다 각 숫자에 해당하는 개수 추가
		resurt[i] = -1; /* 초기화 */
	}
	for (int i = 0; i < N; i++) {
		while (!is_empty(&S) && cnt[arr[i]] > cnt[arr[get_top(&S)]]) { /*스택에 원소가 있고, 검사할 원소의 개수가 top위치에 있는 요소의 개수보다 클 때:즉 개수가 큰 조건이 만족할 때*/
			//printf("i:%d, cnt[arr%d]:%d, cnt[top%d]:%d, resurt[top]:%d\n", i, arr[i], cnt[arr[i]], get_top(&S), cnt[get_top(&S)], arr[i]);
			resurt[pop_stack(&S)] = arr[i]; /* 결과 배열에 원소 추가 */
		}
		push_stack(&S, i); // 데이터, 인덱스위치 전달
		//printf("top:%d\n", get_top(&S));
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", resurt[i]);
	}

	free(S.stack);
	free(arr);
	free(resurt);
	return 0;
}
