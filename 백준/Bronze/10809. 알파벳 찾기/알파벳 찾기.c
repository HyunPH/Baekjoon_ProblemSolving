#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int alpabet[26] = { -1, };
	for (int i = 0; i < 26; i++) { // alphabet 초기화
		alpabet[i] = -1;
	}
	char s[101];
	int len;
	scanf("%s", s); 
	len = strlen(s);

	for (int i = 0; i < len; i++){
		if (alpabet[s[i]-'a'] > -1)
			continue;
		alpabet[s[i]-'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alpabet[i]);
	}
	return 0;
}
