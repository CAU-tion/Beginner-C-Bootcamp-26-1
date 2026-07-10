#include <stdio.h>

int main()
{
	int k;
	int sum = 0;	
	
	k = 1;

	for (k; k <= 10; k++)
	{
		sum = sum + k;
	}

	printf("%d\n", sum);
}