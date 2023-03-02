#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_prime(int n)
{
	int flag = 1;

	if (n == 1)
		return 0;

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	
	return 1;
}


int main()
{
	int cnt;
	scanf(" %d", &cnt);

	while (cnt--)
	{
		int num, half;
		scanf(" %d", &num);

		half = num / 2;
		while (half <= num)
		{
			if (is_prime(half) == 1 && is_prime(num - half) == 1)
			{
				printf("%d %d\n", num - half, half);
				break;
			}
			half++;
		}
	}
	return 0;
}