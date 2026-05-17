#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//challnge 1
 /*int main()
{
	int* myarray = (int*)malloc(sizeof(int) * 5);
	int* mynum = (int*)malloc(sizeof(int));

	for (int k = 0; k < 5; k++) {
		myarray[k] = k + 1;
	}
	*mynum = 1;
	printf("my num address is %p \n", mynum);
	for (int k = 0; k < 5; k++)
	{
		printf("my array[%d] address is %p\n", k, &myarray[k]);
	}
	free(myarray);
	free(mynum);
}*/



 //challenge 2
  int main()
 {
 		int* myarray = (int*)malloc(sizeof(int) * 5);
 		int* mynum = (int*)malloc(sizeof(int));
 	
 		for (int k = 0; k < 5; k++) {
 			myarray[k] = k + 1;
 		}
 		*mynum = 1;
 		printf("my num is %d\n", *mynum);
 		for (int k = 0; k < 5; k++)
 		{
 			printf("my array [%d] is %d\n", k, myarray[k]);
 		}
 		free(myarray);free(myarray);
 		free(mynum);
        *mynum = 1;
 		printf("after free my num is %d\n", *mynum);
 		
        for (int k = 0; k < 5; k++) {
            myarray[k] = k + 1;
        }
        
        for (int k = 0; k < 5; k++)
 		{
 			printf("after free my array [%d] is %d\n", k, myarray[k]);
 		}
 }


  //challenge 3
  //int main()
  //{
  //    int* myarray = (int*)malloc(sizeof(int) * 5);
  //    int* mynum = (int*)malloc(sizeof(int));

  //    for (int k = 0; k < 5; k++) {
  //        myarray[k] = k + 1;
  //    }
  //    *mynum = 1;
  //    printf("my num is %d\n", *mynum);
  //    for (int k = 0; k < 5; k++)
  //    {
  //        printf("my array [%d] is %d\n", k, myarray[k]);
  //    }
  //    free(myarray);free(myarray);
  //    free(mynum);
  //    *mynum = 1;
  //    printf("after free my num is %d\n", *mynum);

  //    for (int k = 0; k < 5; k++) {
  //        myarray[k] = k + 1;
  //    }

  //    for (int k = 0; k < 5; k++)
  //    {
  //        printf("after free my array [%d] is %d\n", k, myarray[k]);
  //    }
  //    free(myarray);free(myarray);
  //    free(mynum);
  //}