#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void reverse(char str[], int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}


int main()
{
	char M[10002] = { 0 }, N[10002] = { 0 }, res[10003] = { 0 };
	scanf("%s %s", &M, &N);

	int M_len = strlen(M), N_len = strlen(N);
	int max_len = (M_len > N_len) ? M_len : N_len;
	int att = 0;

	// 뒤집기.
	reverse(M, M_len);
	reverse(N, N_len);


	for (int i = 0; i < max_len; i++)
	{
		// 각 자리수의 합.
		int sum = (M[i] - '0') + (N[i] - '0') + att;
		
		// 0을 '0'으로 바꿔주기 위해
		if (M[i] == 0)
		{
			sum += '0';
		}
		if (N[i] == 0)
		{
			sum += '0';
		}

		// 십의자리
		att = sum / 10;

		// 일의자리를 배열요소에 추가
		res[i] = sum % 10  + '0';

	}
	// 예외처리
	if (att == 1)
		res[max_len] = '1';
	reverse(res, strlen(res));
	printf("%s\n", res);

	return 0;
}