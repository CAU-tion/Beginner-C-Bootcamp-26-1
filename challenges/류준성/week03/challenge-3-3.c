#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int k = 0;
	scanf("%d", &k);

	switch (k>0)
	{
	 case 1 :
		 printf("양수");
		 break;
	 case 0 :
		 if (k == 0)
		 {
			 printf("제로다용");
			 break;
		 }
		 else
		 {
			 printf("음수");
			 break;
		 }
	}

}