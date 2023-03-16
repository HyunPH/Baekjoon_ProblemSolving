#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, temp, N_cnt[10001] = { 0 };
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &temp);
		N_cnt[temp]++;
	}

	// 출력
	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < N_cnt[i]; j++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
