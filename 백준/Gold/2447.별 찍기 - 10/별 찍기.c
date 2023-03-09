#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void star_print(int N, int x, int y)
{
	
	if ((x / N) % 3 == 1 && (y / N) % 3 == 1)
	{
		printf(" ");
	}
	else
	{
		if (N/3 == 0)
		{
			printf("*");
		}
		else
		{
			star_print(N / 3, x, y);
		}
	}
}

int main()
{
	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			star_print(N, i, j);
		}
		printf("\n");
	}
	

	return 0;
}
