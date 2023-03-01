#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, num, count = 0;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &num);

		// 소수 검사.
		if (num == 2)
		{
			count++;
			continue;
		}
		else if (num == 1)
		{
			continue;
		}


		int flag = 1;
		for (int j = 2; j < num; j++)
		{
			if (num % j == 0)
				flag = 0;
		}
		if (flag == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}