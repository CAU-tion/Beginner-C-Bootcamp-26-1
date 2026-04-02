#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int k = 0;
	scanf("%d", &k);

	k > 0 ? printf("양수") : k == 0 ? printf("제로다용") : printf("음수");

}