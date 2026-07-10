#include <stdio.h>

int main()
{
	int k;
	int sum = 0;

	k = 1;

	while (k <= 10)
	{
		sum = sum + k;
		k++;
	}

	printf("%d\n", sum);

}