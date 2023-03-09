#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

static int count;

int recursion(const char* s, int l, int r) {
	
	count++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	int T;
	scanf(" %d", &T);

	while (T--)
	{
		int S[1001];
		count = 0;
		scanf("%s", S);

		printf("%d ", isPalindrome(S));
		printf("%d\n", count);
	}
	return 0;
}
