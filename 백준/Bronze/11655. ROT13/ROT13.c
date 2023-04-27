#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void decode(char* s, int len) {
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = (s[i] - 'a' + 13) % 26 + 'a';
		else if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = (s[i] - 'A' + 13) % 26 + 'A';
		else
			continue;
	}
}

int main()
{
	char arr[101];
	int len;
	scanf("%[^\n]s", arr); // 입력
	len = strlen(arr);

	decode(arr, len); // 코드화

	printf("%s\n", arr); // 출력

	return 0;
}
