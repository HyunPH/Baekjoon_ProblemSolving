#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXlLEN 20

int main()
{
	char s1[MAXlLEN], s2[MAXlLEN], s3[MAXlLEN], s4[MAXlLEN];
	int n1, n2, n3, n4;
	long long A, B;
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

	/* 숫자를 문자열로 바꾸기 */
	_itoa(n1, s1, 10);
	_itoa(n2, s2, 10);
	_itoa(n3, s3, 10);
	_itoa(n4, s4, 10);

	/* 문자열 두개를 합치기 */
	strcat(s1, s2);
	strcat(s3, s4);

	/* 문자열을 숫자로 바꾸고 저장 */
	A = atoll(s1); 
	B = atoll(s3); 
	printf("%lld\n", A+B);
	return 0;
}
