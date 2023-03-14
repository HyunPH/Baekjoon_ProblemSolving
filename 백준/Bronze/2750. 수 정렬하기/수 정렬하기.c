#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, arr[1000];
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &arr[i]);
	}

	// 버블 정렬 시작
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}
