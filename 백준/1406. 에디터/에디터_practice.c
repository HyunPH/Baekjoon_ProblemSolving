#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char arr[100] = "qwer";
	printf("%s\n", arr);

	int len = strlen(arr);
	int cursor = len;
	
	// 0 인덱스 왼쪽에 x추가
	cursor = 0;
	for (int i = len++; i >= cursor; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[cursor] = 'x';
	printf("%s\n", arr);

	// 2 인덱스 왼쪽에 y 추가
	cursor = 2;
	for (int i = len++; i >= cursor; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[cursor] = 'y';
	printf("%s\n", arr);

	// 3 인덱스 왼쪽에 원소삭제
	cursor = 3;
	for (int i = cursor; i <= len; i++)
	{
		arr[i - 1] = arr[i];
	}
	len--;
	printf("%s\n", arr);
  
  return 0;
  
}
