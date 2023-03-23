#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int len, flag = 1; // flag 참이라고 시작.
		char PS[51], is_VPS[51]; // 스택을 이용할 배열 is_VPS
		int top = -1; // 스택에서 top
		scanf("%s", PS);
		len = strlen(PS);

		for (int i = 0; i < len; i++)
		{
			char ch = PS[i]; // 임시 변수
			switch (ch)
			{
			case '(':
			{
				is_VPS[++top] = ch;
				break;
			}
			case ')':
				if (top == -1)
				{
					flag = 0;
					break;
				}
				else
				{
					if (ch == ')' && is_VPS[top--] != '(')
					{
						flag = 0;
						break;
					}
				}
			}
		}

		// 괄호가 올바르다면 push, pop 을 모두 사용해서 배열안에 남아있는 요소가 없다.
		// 하지만 남아있다면 만족하지 못한다.
		if (top != -1)
			flag = 0;


		// flag 확인
		if (flag == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
