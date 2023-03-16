#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int N_arr[1000000];

int main()
{
	int N;
	scanf(" %d", &N);

	for (int i = 0; i < N; i++)
		scanf(" %d", &N_arr[i]);
	
	// (정렬할 배열, 요소 개수, 요소 크기, 비교 함수)
	qsort(N_arr, N, sizeof(int), compare);
	
	// 출력
	for (int i = 0; i < N; i++)
		printf("%d\n", N_arr[i]);
	
	return 0;
}
