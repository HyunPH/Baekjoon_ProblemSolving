#include <stdio.h>
#include <ctype.h>
#define MAXLEN 10001

int main() {
	char c;
	int i, line, smal, big, num, empty;
	i = line = smal = big = num = empty = 0;
	while ((c = getchar()) != EOF) { // 문자열 하나만 가지고 이용하는 방식
		if (c >= 'a' && c <= 'z') // 소문자
			smal++;
		else if (c >= 'A' && c <= 'Z') // 대문자
			big++;
		else if (c >= '0' && c <= '9') // 숫자
			num++;
		else if (c == ' ') // 공백
			empty++;
		else if(c == '\n'){ // 하나의 줄이 끝났을 때.
			printf("%d %d %d %d\n", smal, big, num, empty);
			line = smal = big = num = empty = 0;
		}
	}
}
