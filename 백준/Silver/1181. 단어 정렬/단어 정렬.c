#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{	
	if (strlen((const char*)a) > strlen((const char*)b))
		return 1;
	else if (strlen((const char*)a) < strlen((const char*)b))
		return -1;
	else
		return strcmp((char*)a, (char*)b);
}


int main()
{
	int N;
	char str_arr[20000][51] = { 0 };
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%s", str_arr[i]);


	// 정렬
	qsort(str_arr, N, sizeof(str_arr[0]), compare);


	// 출력
	for (int i = 0; i < N; i++)
	{
		if (strcmp(str_arr[i], str_arr[i + 1]) != 0 || i == N - 1)
		{
			printf("%s\n", str_arr[i]);
		}
	}

	return 0;
}
