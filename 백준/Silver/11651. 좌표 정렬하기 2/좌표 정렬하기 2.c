#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int xpos;
	int ypos;
}Point;


int compare(const void* a, const void* b)
{
	Point A = *(Point*)a;
	Point B = *(Point*)b;

	if (A.ypos > B.ypos)
		return 1;
	else if (A.ypos < B.ypos)
		return -1;
	else
	{
		if (A.xpos > B.xpos)
			return 1;
		else
			return -1;
	}
}


int main()
{
	int N;
	scanf(" %d", &N);

	// 좌표 변수 동적할당, 입력
	Point* arr = (Point*)malloc(sizeof(Point) * N);
	for (int i = 0; i < N; i++)
		scanf(" %d %d", &arr[i].xpos, &arr[i].ypos);
	
	// 정렬
	qsort(arr, N, sizeof(Point), compare);

	// 출력
	for (int i = 0; i < N; i++)
		printf("%d %d\n", arr[i].xpos, arr[i].ypos);

	return 0;
}
