#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

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
	int N, input_num;
	char input[10];
	scanf(" %d", &N);
	while (N--)
	{
		scanf("%s", input); // 명령 입력

		if (strcmp(input, "push") == 0) // 문자열 비교함수 strcmp, 문자열은 그냥 비교연산이 안됨. 배열과 문자이기 때문.
		{
			scanf("%d", &input_num);
			push(input_num);
		}
		else if (strcmp(input, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(input, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(input, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(input, "front") == 0)
		{
			printf("%d\n", front());
		}
		else if (strcmp(input, "back") == 0)
		{
			printf("%d\n", back());
		}
	}

	return 0;
}
