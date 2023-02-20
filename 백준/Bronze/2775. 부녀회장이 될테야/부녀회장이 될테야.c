#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	//호 배열 생성
	int N[14] = { 0, }; 
	
	for (int i = 0; i < T; i++) // T번 반복.
	{
		int k, n;
		scanf(" %d %d", &k, &n);

		// 0층 초기화. 1 2 3 4 5 6 ...
		for (int j = 0; j < n; j++)
		{
			N[j] = j + 1;
		}

		// 1이상 층 채우기.
		for (int j = 0; j < k; j++)
		{
			for (int l = 1; l < n; l++)
			{
				N[l] += N[l - 1]; 
			}
		}

		printf("%d\n", N[n - 1]);
	}
	return 0;
}