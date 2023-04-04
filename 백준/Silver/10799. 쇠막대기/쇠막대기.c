#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100001];
	int brecket_count = 0, sum = 0, len;
	
	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(') {
			brecket_count++;
		}
		else if (str[i] == ')') {
			brecket_count--;
			if (str[i] == str[i - 1])
				sum += 1;
			else
				sum += brecket_count;
		}
	}
	printf("%d\n", sum);
	return 0;
}
