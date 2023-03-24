#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	int* input_arr = (int*)malloc(N * sizeof(int));
	int* stack_arr = (int*)malloc(N * sizeof(int));
	char* resurt_arr = (int*)calloc(N * 2, sizeof(char)); // pop push가 가장 많이 나올 수 있는 경우가 n*2 일때임.
	int resurt_idx = 0;
	int input_idx = 0; // 비교할 때 사용
	int top = -1, num = 0; // num : 스택에 추가할 원소: 값은 무조건 1 2 3 ... 1씩 커지기만 한다.

	for (int i = 0; i < N; i++)
		scanf(" %d", &input_arr[i]);


	while (1)
	{
		// push
		if (top == -1 || stack_arr[top] < input_arr[input_idx])
		{
			stack_arr[++top] = ++num;
			resurt_arr[resurt_idx++] = '+';
		}
		// pop
		else if (stack_arr[top] == input_arr[input_idx])
		{
			stack_arr[top] = 0;
			top--;
			input_idx++;
			resurt_arr[resurt_idx++] = '-';
		}
		// 오류
		else if (stack_arr[top] > input_arr[input_idx])
		{
			printf("NO\n");
			break;
		}

		// 스택 내부 확인
		if (num == N && top == -1)
		{
			for (int i = 0; i < resurt_idx; i++)
				printf("%c\n", resurt_arr[i]);
			break;
		}
	}
	
	free(input_arr);
	free(stack_arr);
	free(resurt_arr);

	return 0;
}
