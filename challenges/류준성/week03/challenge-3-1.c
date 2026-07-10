#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int k = 0;
	scanf("%d", &k);

	if (k > 0)
	{
		printf("양수");
	}
	else if (k < 0)
	{
		printf("음수");
	}
	else
	{
		printf("제로다요");
	}

}