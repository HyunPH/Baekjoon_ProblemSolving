#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, K, count = 0;
	scanf(" %d %d", &N, &K);

	for (int i = 1; i <= N; i++)
	{
		if (N%i == 0)
		{
			count++;
			if (K == count)
			{
				printf("%d", i);
			}
		}
	}

	if (K > count)
	{
		printf("%d", 0);
	}
	return 0;
}