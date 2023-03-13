#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, i = 666, cnt = 0;
	scanf(" %d", &N);


	while (cnt < N)
	{
		// 숫자 i 안에 '666'이 있는지 검사.
		int temp = i;
		int count_6 = 0;
		while (temp > 0)
		{
			int digit = temp % 10;
			if (digit == 6)
				count_6++;
			else // 6이 나오다가 갑자기 안나오면 초기화
				count_6 = 0;

			if (count_6 == 3)
			{
				cnt++;
				break;
			}

			temp /= 10;
		}


		// N번째 수 일 때, 비교
		if (cnt == N)
			printf("%d\n", i);

		i++; // 666부터 순서대로 검사.
	}
	
	return 0;
}
