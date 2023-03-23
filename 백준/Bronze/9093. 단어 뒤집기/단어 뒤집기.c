#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 문자열을 뒤집는 함수
void Reverse_word(char str[], int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (getchar() != '\n'); // 입력버퍼 enter 전까지 비우기

	while (T--)
	{
		char arr[1001];
		scanf("%[^\n]s", arr); // enter 입력받기 전까지 계속 입력받음.
		int len = strlen(arr);

		char word[21] = { 0 }; // 단어 배열 선언.
		for (int i = 0, word_i = 0; i <= len; i++)
		{
			if (arr[i] == ' ' || arr[i] == 0)
			{
				// 단어 결과 출력
				Reverse_word(word, word_i); // 문자열 뒤집기 함수
				printf("%s ", word);

				// word 초기화
				for (int j = 0; j < word_i; j++)
					word[j] = 0;
				word_i = 0;
			}

			else if (arr[i] != ' ')
				word[word_i++] = arr[i];
		}
		printf("\n");

		while (getchar() != '\n'); // 입력버퍼 enter 전까지 비우기
	}
	return 0;
}
