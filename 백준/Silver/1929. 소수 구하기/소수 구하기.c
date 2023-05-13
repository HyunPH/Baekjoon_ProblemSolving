#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Eratos(int bottom, int top) {
	int* is_prime = (int*)malloc((top + 1) * sizeof(int));
	for (int i = 2; i <= top; i++)
		is_prime[i] = 1;

	for (int i = 2; i <= top; i++) {
		if (is_prime[i]) {
			if(i >= bottom) /* 소수이고 조건안에 있으면 */
				printf("%d\n", i);
			
			for (int j = i + i; j <= top; j += i) /* 소수의 배수는 모두 소수가 아님 */
				is_prime[j] = 0;
		}
	}
	free(is_prime); 
}

int main()
{
	int bottom, top;
	scanf("%d %d", &bottom, &top);
	
	Eratos(bottom, top);

	return 0;
}
