#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 숫자값과, 인덱스를 저장하는 구조체
typedef struct
{
	int num;
	int idx;
}Point;

// 퀵소트 정렬에 사용되는 비교함수. 구조체변수를 이용하여 숫자값만 비교함.
int compare(const void* a, const void* b)
{
	Point *A = (Point*)a;
	Point *B = (Point*)b;

	if (A->num > B->num)
		return 1;
	else if (A->num < B->num)
		return -1;
	else
		return 0;
}


int main()
{
	int N;
	scanf("%d", &N);

	// 구조체변수 동적할당 선언
	Point* arr = (Point*)malloc(sizeof(Point) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i].num);
		arr[i].idx = i;
	}


	// 정렬
	qsort(arr, N, sizeof(Point), compare);
	

	// 결과출력 배열
	int* resurt = (int*)malloc(sizeof(int) * N);
	resurt[arr[0].idx] = 0; // 0번째 인덱스 수는 가장 작은 수이기 때문에, 0으로 초기화.
	for (int i = 1, cnt = 0; i < N; i++)  // 1번째 인덱스부터 비교, cnt 순위변수
	{
		if (arr[i].num != arr[i-1].num) // 자신보다 앞선 수가 같지 않다면, cnt 플러스.
			cnt++; // 순위는 쌓이면서 증가하기 때문에 증가만 함.
		resurt[arr[i].idx] = cnt;
	}


	// 출력
	for (int i = 0; i < N; i++)
		printf("%d ", resurt[i]);


	// 동적할당 제거
	free(arr);
	free(resurt);

	return 0;
}
