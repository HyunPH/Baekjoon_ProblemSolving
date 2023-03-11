#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int N, People_arr[50][2];
	int rank = 0;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %d %d", &People_arr[i][0], &People_arr[i][1]);
	}

	// 각 인덱스마다, 자신보다 큰 값이 몇개 있는지 세보면 됨.
	for (int i = 0; i < N; i++)
	{
		rank = 0;
		for (int j = 0; j < N; j++)
		{
			if (People_arr[i][0] < People_arr[j][0] && People_arr[i][1] < People_arr[j][1])
			{
				rank++;
			}
		}
		printf("%d ", rank + 1);
	}
	
	return 0;
}
