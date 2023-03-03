#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int min, x, y, w, h;
	scanf(" %d %d %d %d", &x, &y, &w, &h);

	min = x;
	if (y < min)
		min = y;
	if (w - x < min)
		min = w - x;
	if (h - y < min)
		min = h - y;
	
	printf("%d", min);
	
	return 0;
}