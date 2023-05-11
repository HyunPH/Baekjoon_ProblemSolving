#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* 최대공약수 */
int Euclidean(int a, int b) {
	if (a % b == 0)
		return b;
	else
		return Euclidean(b, a % b);
}
/* 최소공배수 */
int Euclidean_2(int a, int b) {
	return a * b / Euclidean(a, b); /* 최소공배수는 한 수 곱하기 다른 한 수를 최대공약수로 나눈 수. */
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		printf("%d\n", Euclidean_2(n1, n2)); /* 최소공배수 구하기 */
	}
	return 0;
}
