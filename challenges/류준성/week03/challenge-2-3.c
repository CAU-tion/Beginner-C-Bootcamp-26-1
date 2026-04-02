#include <stdio.h>

int main()
{
	int k;
	int sum = 0;
	
	k = 1;

	do
	{
		sum = sum + k;
		k++;
	} while (k <= 10);

	printf("%d\n", sum);
}