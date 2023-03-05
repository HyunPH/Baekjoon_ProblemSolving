#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T;
	scanf(" %d", &T);

	while (T--)
	{
		int x1, x2, y1, y2, n, enter_leave_count = 0;
		

		scanf(" %d %d %d %d %d", &x1, &y1, &x2, &y2, &n);

		for (int i = 0; i < n; i++)
		{
			int Cx, Cy, r;
			scanf(" %d %d %d", &Cx, &Cy, &r);
			
			// 진입 이탈 회수 계산
			// 원이 출발점을 포함할 때
			if ((Cx - x1) * (Cx - x1) + (Cy - y1) * (Cy - y1) < r * r)
			{
				// 원이 도착점만 포함하지 않을 때
				if ((Cx - x2) * (Cx - x2) + (Cy - y2) * (Cy - y2) >= r * r)
					enter_leave_count++;
                
			}
			// 원이 도착점만 포함할 때
			else if ((Cx - x2) * (Cx - x2) + (Cy - y2) * (Cy - y2) < r * r)
				enter_leave_count++;
			
		}

		printf("%d\n", enter_leave_count);
	}

	return 0;
}