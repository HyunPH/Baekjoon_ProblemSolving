#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n, M, N_arr[100];
	scanf(" %d %d", &n, &M);

	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &N_arr[i]);
	}

	// 3장을 고르는 것이기 때문에 3중 반복문을 구현.
	int sum_max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i)
			{
				continue;
			}

			for (int k = 0; k < n; k++)
			{
				if (k == i || k == j)
				{
					continue;
				}
				
				if ((N_arr[i] + N_arr[j] + N_arr[k] <= M) && (N_arr[i] + N_arr[j] + N_arr[k] > sum_max))
				{
					sum_max = N_arr[i] + N_arr[j] + N_arr[k];
				}

			}
		}
	}

	printf("%d\n", sum_max);
	return 0;
}
