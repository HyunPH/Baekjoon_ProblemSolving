#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int Paper[100][100] = { 0 }, paper_num;
	scanf(" %d", &paper_num); // 종이 개수 입력

	// 검은색 종이 위치 입력
	for (int i = 0; i < paper_num; i++)
	{
		int x, y;
		scanf(" %d %d", &x, &y);
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				Paper[x + j][y + k] = 1;
			}
		}
	}

	// 면적 계산
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (Paper[i][j] == 1)
				count++;
		}
	}

	// 면적 출력
	printf("%d", count);

	return 0;
}