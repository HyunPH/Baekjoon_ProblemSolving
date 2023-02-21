#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, box = 0;
	scanf("%d", &N);

	while (1) {
		if (N % 5 == 0) {
			box += N / 5;
			printf("%d\n", box);
			break;
		}

		N -= 3;
		box += 1;

		if (N < 0) {
			printf("%d\n", -1);
			break;
		}

	}
	return 0;
}