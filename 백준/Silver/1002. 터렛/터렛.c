#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int T;
	scanf(" %d", &T);

	while (T--)
	{
		int x1, y1, r1, x2, y2, r2, sum_r, diff_r;
		double Pos_distance;
		scanf(" %d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		Pos_distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		sum_r = r1 + r2;
		diff_r = abs(r1 - r2);
		
		//교점 무한대
		//좌표와 r 일치
		if (Pos_distance == 0 && diff_r == 0)
			printf("-1\n");

		//교점 0 :
		//중심 사이의 거리가 r의 합보다 길 때
		else if (Pos_distance > sum_r)
			printf("0\n");
		//원 안에 원이 있을 때, 중심 사이의 거리가 거리의 차보다 짧을 때
		else if (Pos_distance < diff_r)
			printf("0\n");

		//교점 1:
		//중심 사이의 거리와 r의 합과 같을 때
		else if (Pos_distance == sum_r)
			printf("1\n");
		//원 안에 원이 접할 때, 중심 사이의 거리가 거리의 차와 같을 때
		else if (Pos_distance == diff_r)
			printf("1\n");

		//교점 2 :
		//중심 사이의 거리가 r의 합보다 크고, r의 차보다 작을 때
		else // (Pos_distance > sum_r && Pos_distance < diff_r)
			printf("2\n");

	}
	return 0;
}