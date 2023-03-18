#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int xpos;
	int ypos;
}Point;


// 비교함수. 문제에 맞춰서 변형시킴.
int compare(const void* a, const void* b)
{
	Point A = *(Point*)a;
	Point B = *(Point*)b;
	
	if (A.xpos > B.xpos)
		return 1;
	else if (A.xpos < B.xpos)
		return -1; // -1출력은 자리를 안바꾸겠다. 1은 바꾸겠다.
	else
	{
		if (A.ypos > B.ypos)
			return 1;
		else
			return -1;
	}
}


int main()
{
	int N;
	scanf(" %d", &N);
	Point* point;
	point = (Point*)malloc(sizeof(Point) * N);
	
	for (int i = 0; i < N; i++)
		scanf(" %d %d", &point[i].xpos, &point[i].ypos);

	// 정렬 오름차순.
	qsort(point, N, sizeof(Point), compare);

	for (int i = 0; i < N; i++)
		printf("%d %d\n", point[i].xpos, point[i].ypos);
	
	free(point);
	return 0;
}
