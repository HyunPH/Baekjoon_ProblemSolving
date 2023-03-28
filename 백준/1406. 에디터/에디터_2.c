#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char input[500000][2];
char arr1[100001], arr2[100001];

int main()
{
	int M;
	int top1, top2;

	scanf("%s", arr1);
	top1 = strlen(arr1) - 1; // top은 cursor의 위치.
	top2 = -1;

	scanf(" %d", &M);
	
	for(int i = 0; i < M ;i++)
	{
		scanf(" %c", &input[i][0]); // 입력버퍼 공백제거를 위해 띄어쓰기함.
		switch (input[i][0])
		{
		case 'L':
		{
			if (top1 == -1) // 커서가 문장의 맨 앞이면 무시됨.
				break;

			arr2[++top2] = arr1[top1--]; // arr1 pop, arr2 push

			break;
		}
		case 'D':
		{
			if (top2 == -1) // 커서가 문장의 맨 뒤이면 무시됨.
				break;

			arr1[++top1] = arr2[top2--]; // arr2 pop, arr1 push

			break;
		}
		case 'B':
		{
			if (top1 == -1) // 커서가 문장의 맨 앞이면 무시됨
				break;
			
			arr1[top1--] = 0; // arr1 pop

			break;
		}
		case 'P':
		{
			scanf(" %c", &input[i][1]);
			arr1[++top1] = input[i][1]; // arr1 x push

			break;
		}
		default:
			break;
		}
		

		/*for (int i = 0; i <= top1; i++)
			printf("%c", arr1[i]);
		printf(" ");
		for (int i = top2; i >= 0; i--)
			printf("%c", arr2[i]);
		printf("\n");*/

	}

	// 최종 출력
	for (int j = 0; j <= top1; j++)
		printf("%c", arr1[j]);
	for (int j = top2; j >= 0; j--)
		printf("%c", arr2[j]);
	printf("\n");

	return 0;
}
