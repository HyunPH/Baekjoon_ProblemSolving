#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A[100][100], B[100][100], N, M;
	scanf(" %d %d", &N, &M);
	
	// A 입력
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < M; k++)
		{
			scanf(" %d", &A[j][k]);
		}
	}
	// B 입력
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < M; k++)
		{
			scanf(" %d", &B[j][k]);
		}
	}

	// 합 출력
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < M; k++)
		{
			printf("%d ", A[j][k] +	B[j][k]);
		}
		printf("\n");
	}

	return 0;
}