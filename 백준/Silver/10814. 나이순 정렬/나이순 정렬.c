#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int age;
	char name[101];
}Member;

int compare(const void* a, const void* b)
{
	Member A = *(Member*)a, B = *(Member*)b;

	if (A.age > B.age)
		return 1;
	else if (A.age < B.age)
		return -1;
	else
		return -1;
}


int main()
{
	int N;
	scanf("%d", &N);

	// 구조체 배열 선언, 입력.
	Member* people_arr = (Member*)malloc(sizeof(Member) * N);
	for (int i = 0; i < N; i++)
		scanf("%d %s", &people_arr[i].age, people_arr[i].name);


	// 정렬
	qsort(people_arr, N, sizeof(Member), compare);
	

	// 출력
	for (int i = 0; i < N; i++)
		printf("%d %s\n", people_arr[i].age, people_arr[i].name);

    free(people_arr);
	return 0;
}
