#include <stdio.h>
#include <stdlib.h>

int main() {
        
        int *a = (int*)malloc(sizeof(int));
        int *b = (int*)malloc(5*sizeof(int));

        *a = 10;
        b[0]=1;
        b[1]=2;
        b[2]=3;
        b[3]=4;
        b[4]=5;

        printf("a=%d\n",*a);
        for(int i=0;i<5;i++)
                printf("b[%d]=%d\n",i,*(b+i));

        free(a);
        free(b);

        return 0;
}




a=10
b[0]=1
b[1]=2
b[2]=3
b[3]=4
b[4]=5
(gdb)
주소a=0x5555555592a0
주소b[0]=0x5555555592c0
주소b[1]=0x5555555592c4
주소b[2]=0x5555555592c8
주소b[3]=0x5555555592cc
주소b[4]=0x5555555592d0

          Start Addr           End Addr       Size     Offset  Perms  objfile
      0x555555559000     0x55555557a000    0x21000        0x0  rw-p   [heap]


if(a == NULL){
    printf("메모리할당실패");
    return 1;
}

Memory Leak
동적으로 할당된 메모리가 사용 후에 해제되지 않아 프로그램 실행 중 메모리 사용량이 지속적으로 증가한다
