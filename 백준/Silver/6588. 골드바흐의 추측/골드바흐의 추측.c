#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int main()
{
	/* 모든 소수 판별해놓기 */
	int* is_prime = (int*)malloc((MAX + 1) * sizeof(int));
	for (int i = 0; i < MAX + 1; i++) is_prime[i] = 1;
	for (int i = 2; i <= MAX; i++) {
		if (is_prime[i]) {
			for (int j = i + i; j <= MAX; j += i) /* 소수의 배수는 모두 소수가 아님 */
				is_prime[j] = 0;
		}
	}
	int num;
	while (1) {
		scanf("%d", &num);
		if (!num) break; /* 0일 때 */
		else if ((num % 2 == 1) || num < 6) /* 홀수이고, 범위가 아닐 때 */
			printf("Goldbach's conjecture is wrong.\n");
		
		/* num보다 작은 두 소수 홀수 찾기 */
		for (int i = 3; i <= num / 2; i += 2) { /* num의 절반보다 작은 소수찾기, 하나씩 검사해서 가장 작은 소수가 나오면 멈추고, 나머지는 정해짐 */
			/* 소수 검사 */
			if (is_prime[i] && is_prime[num - i]) { /* 두 수 모두 홀수이고 짝수일 때 */
				printf("%d = %d + %d\n", num, i, num - i);
				break;
			}
		}
	}
	free(is_prime);
	return 0;
}
