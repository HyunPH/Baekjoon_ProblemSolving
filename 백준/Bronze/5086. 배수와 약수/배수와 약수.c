#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n1, n2;
	
	do
	{
		scanf(" %d %d", &n1, &n2);
		
		if (n1 == 0 || n2 == 0)
		{
			break;
		}

		if (n2 >= n1)
		{
			if (n2 % n1 == 0)
			{
				printf("factor\n");
			}
			else
				printf("neither\n");
		}
		
		else 
		{
			if (n1 % n2 == 0)
			{
				printf("multiple\n");
			}
			else
				printf("neither\n");
		}

	} while (1);

	return 0;
}