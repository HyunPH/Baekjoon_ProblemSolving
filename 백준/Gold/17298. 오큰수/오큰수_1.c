#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, flag;
	scanf("%d", &N);
	int* arr = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
		scanf(" %d", &arr[i]);

	for (int i = 0; i < N; i++){
		flag = 1;
		for (int j = i + 1; j < N; j++) {
			if (arr[i] < arr[j]) {
				printf("%d ", arr[j]);
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			printf("-1 ");
		}
	}

	return 0;
}
