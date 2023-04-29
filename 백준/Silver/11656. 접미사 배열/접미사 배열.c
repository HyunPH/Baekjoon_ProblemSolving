#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000

int getline_(char* s, int maxlen) {
	int c, i = 0;
	while (--maxlen && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i] = '\0';
	return i;
}
int make_arr_pointer(char* arr[], char* s, int maxline) {
	int i;
	for (i = 0; i < maxline; i++) {
		arr[i] = s++; /* s문자열의 주소들만 추가하면서 저장해주면 새로운 공간이 안필요함 */
	}
	return i;
}
void swap(char* v[], int i, int j) {
	char* temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void qsort_(char* v[], int left, int right) {
	int last = left;
	if (left >= right) /* 재귀함수 종료조건 */
		return;
	for (int i = left + 1; i <= right; i++) {
		if (strcmp(v[i], v[left]) < 0) /* 기준left보다 검사 원소들이 더 작을 때 */
			swap(v, ++last, i);
	}
	swap(v, left, last); /* 기준과 마지막으로 작은 수 교환 */

	qsort_(v, left, last - 1); /* 기준의 왼쪽 */
	qsort_(v, last + 1, right); /* 기준의 오른쪽 */
}
int main()
{
	int len, nlines;
	char str[MAXLEN + 1];
	char* arr[MAXLEN];
	len = getline_(str, MAXLEN + 1); /* 문자열 str 입력 */
	nlines = make_arr_pointer(arr, str, len); /* str로 접미사를 pointer 배열로 생성 */
	qsort_(arr, 0, nlines - 1); /* pointer 배열들 정렬 */

	for (int i = 0; i < nlines; i++) { /* 결과 출력 */
		printf("%s\n", arr[i]);
	}

	return 0;
}
