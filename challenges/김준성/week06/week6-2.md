#include <stdio.h>

int main(){
        int arr[3]= {4,67,35};
        int *ptr = arr ;

        printf("접근방식 비교\n");
        for ( int i=0; i<3 ; i++){
                printf("인덱스 %d arr [%d] = %d  *(ptr +%d) = %d\n",i,i,arr[i],i,*(ptr+i));
        }
        for(int i=0; i<3; i++){
                printf("\nptr++=%p ptr--=%p\n",ptr+i,ptr-i);
        }
        return 0;
}

접근방식 비교
인덱스 0 arr [0] = 4  *(ptr +0) = 4
인덱스 1 arr [1] = 67  *(ptr +1) = 67
인덱스 2 arr [2] = 35  *(ptr +2) = 35

ptr++=0x7ffc8fe7152c ptr--=0x7ffc8fe7152c

ptr++=0x7ffc8fe71530 ptr--=0x7ffc8fe71528

ptr++=0x7ffc8fe71534 ptr--=0x7ffc8fe71524

배열의 이름은 배열 시작점을 나타내는 주소값으로 자동 변환되며, arr[i] 연산은 내부적으로 포인터 역참조 방식인 *(arr + i)로 처리되기 때문에 포인터와 동일하게 동작한다 

