#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int queue[10000];
int top = -1, bottom = 0;

void push(int key)
{
	queue[++top] = key;
}
int pop()
{
	if (empty())
		return -1;

	return queue[bottom++];
}
int size()
{
	return top + 1 - bottom;
}
int empty()
{
	if (top + 1 == bottom)
		return 1;
	return 0;
}
int front()
{
	if (empty())
		return -1;
	return queue[bottom];
}
int back()
{
	if (empty())
		return -1;
	return queue[top];
}

int main()
{
	int N, K;
	scanf(" %d %d", &N, &K);
	
	// 배열 생성 push 
	for (int i = 0; i < N; i++)
		push(i + 1);
	
	// 결과 출력
	printf("<");
	while (bottom <= top)
	{
		int resurt = K % (top - bottom + 1) - 1; // 원소개수 < K 일 때 앞으로 돌아와서 개수를 세야 하므로, 나머지의 값을 만듦.
		if (K == top - bottom + 1) // K가 원소의 개수와 같으면 0으로 결정이 되기 때문에. resurt를 K로 할당해줌.
			resurt = K - 1;

		// K번째 원소 빼기
		if (bottom == top) { // 마지막 원소 하나 남았을 때
			printf("%d", queue[bottom]); // bottom 위치 출력
			break;
		}
		printf("%d, ", queue[bottom + resurt]); 

		// pop원소로 push
		for (int i = 0; i < K - 1; i++)
			push(pop(queue[bottom + i]));
		
		bottom++; // 뺀 원소를 뛰어넘고 시작되기 때문에 1추가
	}
	printf(">\n");

	return 0;
}
