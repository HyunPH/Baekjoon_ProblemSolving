#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int N, arr[10000] = { 0 };
	char input_command[10];
	int arr_len = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", input_command);


		if (strcmp(input_command, "push") == 0) // push와 input이 같다면
		{
			arr_len++;
			scanf(" %d", &arr[arr_len - 1]);
		}

		else if (strcmp(input_command, "pop") == 0) 
		{
			if (arr_len <= 0)
			{
				arr_len = 0;
				printf("-1\n");
			}
			else
			{
				printf("%d\n", arr[arr_len - 1]);
				arr[arr_len - 1] = 0;
				arr_len--;
			}
		}

		else if (strcmp(input_command, "size") == 0)
		{
			if (arr_len <= 0)
			{
				printf("0\n");
			}
			else 
				printf("%d\n", arr_len);
		}

		else if (strcmp(input_command, "empty") == 0)
		{
			if (arr_len == 0)
			{
				printf("1\n");
			}
			else
				printf("0\n");
		}

		else if (strcmp(input_command, "top") == 0)
		{
			if (arr_len == 0)
			{
				printf("-1\n");
			}
			else
				printf("%d\n", arr[arr_len - 1]);
		}
	}
	return 0;
}
