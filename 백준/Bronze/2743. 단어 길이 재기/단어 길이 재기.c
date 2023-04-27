#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int str_len(char* s) {
	int i = 0;
	while (s[i] != '\0') i++;
	return i;
}
int main()
{
	char arr[101];
	scanf("%s", arr);
	printf("%d\n", str_len(arr));
	return 0;
}
