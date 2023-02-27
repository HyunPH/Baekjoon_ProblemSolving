#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N_box[100], N, M;
	scanf(" %d %d", &N, &M);

	// N번까지 바구니 채우기
	for (int i = 0; i < N; i++)
	{
		N_box[i] = i + 1;
	}

	// M번 반복
	for (int m = 0; m < M; m++)
	{
		int i, j, k, temp_arr[100];
		scanf(" %d %d %d", &i, &j, &k);
		
		// 예외처리.
		if (i == k)
			continue;


		// begin ~ mid -1 를 임시 배열에 저장
		int begin_mid = k - i;
		for (int idx = 0; idx < begin_mid; idx++)
		{
			temp_arr[idx] = N_box[i - 1];
			i++;
		}

		// mid ~ end 를 왼쪽으로 옯기기.
		int mid_end = j - k + 1;
		for (int idx = 0; idx < mid_end; idx++)
		{
			N_box[k - begin_mid - 1] = N_box[k - 1];
			k++;
		}

		// 임시저장된 값들을 끝에 채우기
		for (int idx = 0; idx < begin_mid; idx++)
		{
			N_box[idx + mid_end + i - begin_mid - 1] = temp_arr[idx];
		}

		//// 점검.
		//for (int i = 0; i < N; i++)
		//{
		//	printf("%d ", N_box[i]);
		//}
		//printf("\ni: %d, j: %d, k: %d, begin_mid: %d, mid_end: %d\n", i, j, k, begin_mid, mid_end);
	}

	// 배열 출력
	for (int i = 0; i < N; i++)
	{
		printf("%d ", N_box[i]);
	}
	
	return 0;
}