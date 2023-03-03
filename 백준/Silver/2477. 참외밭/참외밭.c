#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int crops, direction_length[6][2], direction_cnt[4], M_area = 1, m_area = 1;

int main()
{
	
	scanf(" %d", &crops);
	for (int i = 0; i < 6; i++)
	{
		scanf(" %d %d", &direction_length[i][0], &direction_length[i][1]);
		direction_cnt[direction_length[i][0]]++;
	}
	for (int i = 0; i < 6; i++)
	{
		if (direction_cnt[direction_length[i][0]] == 1)
		{
			M_area *= direction_length[i][1];
			continue;
		}

		int n = (i + 1) % 6; // i의 다음꺼
		int nn = (i + 2) % 6; // i의 다다음꺼
		if (direction_length[i][0] == direction_length[nn][0])
		{
			m_area *= direction_length[n][1];
		}
	}

	printf("%d", crops * (M_area - m_area));

	return 0;
}