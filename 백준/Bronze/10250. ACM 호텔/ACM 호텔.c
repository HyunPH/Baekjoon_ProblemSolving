#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int n = 0; n < T; n++)
	{
		int H, W, N, count = 0;
		scanf(" %d %d %d", &H, &W, &N);

		for (int i = 1; i <= W; i++)
		{
			for (int j = 1; j <= H; j++)
			{
				count++;
				if (count == N)
				{
					printf("%d%02d", j, i);
				}
			}
		}
		printf("\n");
	}

	return 0;
}