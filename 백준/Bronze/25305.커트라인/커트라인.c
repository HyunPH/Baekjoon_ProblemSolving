#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, k, N_arr[1000];
	scanf(" %d %d", &N, &k);

	for (int i = 0; i < N; i++)
		scanf(" %d", &N_arr[i]);
	

	// 버블 정렬(내림차순으로)
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (N_arr[i] < N_arr[j])
			{
				int temp = N_arr[i];
				N_arr[i] = N_arr[j];
				N_arr[j] = temp;
			}
		}
	}

	// 출력
	for (int i = 0; i < N; i++)
	{
		if (k == i + 1)
		{
			printf("%d\n", N_arr[i]);
            break;
		}
	}
	
	return 0;
}
