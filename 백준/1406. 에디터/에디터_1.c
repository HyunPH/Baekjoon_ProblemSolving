#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int M;
	char input, editor[1000], P_input;
	scanf("%s", editor);

	int len = strlen(editor);
	int cursor = len;

	scanf(" %d", &M);
	
	while(M--)
	{
		scanf(" %c", &input); // 입력버퍼 공백제거를 위해 띄어쓰기함.
		switch (input)
		{
		case 'L':
		{
			cursor--;
			if (cursor < 0)
				cursor = 0;
			break;
		}
		case 'D':
		{
			cursor++;
			if (cursor > len)
				cursor = len;
			break;
		}case 'B':
		{
			if (cursor == 0)
				break;
			for (int i = cursor--; i <= len; i++)
				editor[i - 1] = editor[i];
			len--;

			break;
		}case 'P':
		{
			scanf(" %c", &P_input);
			for (int i = len++; i >= cursor; i--)
			{
				editor[i + 1] = editor[i];
			}
			editor[cursor++] = P_input;

			break;
		}
		default:
			break;
		}
	}
	
	printf("%s\n", editor);

	
	return 0;
}
