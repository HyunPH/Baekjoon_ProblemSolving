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


int main()
{
	int N, * arr, cnt[8001] = { 0 };
	double avg = 0;
	scanf(" %d", &N);
	arr = (int*)calloc(N, sizeof(int));


	// 입력
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &arr[i]);
		avg += arr[i];
		cnt[arr[i] + 4000]++;
	}

	// 오름차순 정렬
	qsort(arr, N, sizeof(int), compare);


	// 평균. -0이 나오는 것을 방지.
	if (avg / N < 0)
		avg += 1;
	printf("%0.lf\n", avg / N);
	printf("%d\n", arr[N / 2]);


	// 가장 많이 나온 숫자 찾기.
	int max = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > max)
			max = cnt[i];
	}
	// 최빈값 찾기. 두 번째로 작은숫자
	int max_idx = 0, count_2min = 0;
	for (int i = 0; i < 8001; i++)
	{

		if (cnt[i] == max)
		{
			if (count_2min == 0)
			{
				max_idx = i;
				count_2min++;
			}
			else if (count_2min == 1)
			{
				max_idx = i;
				break;
			}
		}
	}
	printf("%d\n", max_idx - 4000);


	// 범위
	printf("%d\n", arr[N - 1] - arr[0]);

	return 0;
}
