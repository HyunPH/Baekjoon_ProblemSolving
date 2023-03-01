#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	
	while (1)
	{
		int num, sum = 0, num_arr[100], j = 0, len = 0;
		scanf(" %d", &num);
		
		// 예외처리
		if (num == -1)
			break;


		// 약수 더하기, 약수들배열에 저장
		for (int i = 1; i < num; i++)
		{
			if (num % i == 0)
			{
				sum += i;
				num_arr[j++] = i;
				len++;
			}
		}

		// 결과 출력
		if (sum == num)
		{
			printf("%d = 1", num);
			for (int i = 1; i < len; i++)
			{
				printf(" + %d", num_arr[i]);
			}
		}
		else
			printf("%d is NOT perfect.", num);
		printf("\n");
	}

	return 0;
}