#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int alpabet[26] = { 0, };
	char s[101];
	int len;
	scanf("%s", s); 
	len = strlen(s);

	for (int i = 0; i < len; i++){
		alpabet[s[i]-'a']++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alpabet[i]);
	}
	return 0;
}
