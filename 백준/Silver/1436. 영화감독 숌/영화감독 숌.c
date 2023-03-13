#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int N, len, i = 666, cnt = 0;
	scanf(" %d", &N);


	while (cnt < N)
	{
		char arr[1000000]; // 임시배열 생성
		sprintf(arr, "%d", i); // 숫자를 문자열로

		// 문자열 안에 '666'이 있는지 검사.
		len = strlen(arr);
		for (int i = 0; i < len; i++)
		{
			if (arr[i] == '6' && arr[i+1] == '6' && arr[i+2] == '6')
			{
				cnt++;
				break;
			}
		}

		// N번째 수 일 때, 비교
		if (cnt == N)
			printf("%d\n", i);

		i++; // 666부터 순서대로 검사.
	}
	
	return 0;
}
