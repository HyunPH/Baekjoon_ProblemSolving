#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n1, n2, min=0, max=0;
	scanf("%d %d", &n1, &n2);
	for (int i = n1; i >= 1;i--) {
		if (n1 % i == 0 && n2 % i == 0) { /* 최대공약수 */
			min = i;
			break;
		}
	}
	for (int j = n1; j <= n1 * n2; j++) {
		if (j % n1 == 0 && j % n2 == 0) { /* 최소공배수 */
			max = j;
			break;
		}
	}
	printf("%d\n%d", min, max);
	return 0;
}
