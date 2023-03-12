#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int N, M, count = 0, min_count = 3000;
	char start;
	char board[50][51];

	scanf(" %d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", &board[i]);


	for (int eight_i = 8; eight_i <= N; eight_i++)
	{
		for (int eight_j = 8; eight_j <= M; eight_j++)
		{
			// 시작 짝,홀 일때 두번
			for (int k = 0; k < 2; k++) 
			{
				// 짝수, 홀수 시작 결정.
				if (k == 0) start = 'W';
				else if (k == 1) start = 'B';
				
				// 8*8 배열 검사.
				count = 0;
				for (int i = eight_i - 8; i < eight_i; i++)
				{
					for (int j = eight_j - 8; j < eight_j; j++)
					{
						if ((i + j) % 2 == 1 && board[i][j] == start)
							count++;
						else if ((i + j) % 2 == 0 && board[i][j] != start)
							count++;
					}
				}
				//printf("k:%d eight_i:%d eight_j:%d count:%d\n", k, eight_i-8, eight_j-8, count);

				// 최소값 찾기
				if (count < min_count)
					min_count = count;
			}
		}
	}
	
	printf("%d\n", min_count);
	return 0;
}
