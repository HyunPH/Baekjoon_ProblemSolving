#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	if (*(int *)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	
	return 0;
}


int bin_search(int *arr, int key, int len)
{
	int begin = 0, end = len - 1, mid ;

	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (arr[mid] == key)
			return 1;
		
		if (key < arr[mid])
			end = mid - 1;
		else if (key > arr[mid])
			begin = mid + 1;	
	}
	// 없을 경우
	return 0;
}

int main()
{
	int N, M;
	//int people_num[501], integer_num[501];
	int *people_num, *integer_num;

	// 상근 카드 입력
	scanf(" %d", &N);
	people_num = (int*)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
		scanf(" %d", &people_num[i]);
	
	// 정수 입력
	scanf(" %d", &M);
	integer_num = (int*)calloc(M, sizeof(int));
	for (int i = 0; i < M; i++)
		scanf(" %d", &integer_num[i]);


	// 오름차순 정렬
	qsort(people_num, N, sizeof(int), compare);


	// 결과 출력
	for (int i = 0; i < M; i++)
		printf("%d ", bin_search(people_num, integer_num[i], N));

	free(people_num);
	free(integer_num);
	return 0;
}
