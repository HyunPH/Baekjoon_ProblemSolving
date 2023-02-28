#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char word[5][16] = { 0 ,}; // 초기화

	// 입력
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", word[i]);

	}

	// 출력
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (word[j][i] == '\0') // 0 
			{
				printf("");
				continue;
			}
			printf("%c", word[j][i]);
		}
	}

	return 0;
}