#include <stdio.h>
#include <stdlib.h>

// 1. Data 영역: 초기화된 전역변수
int global_init_var = 100; 

// 2. BSS 영역: 초기화되지 않은 전역변수
int global_uninit_var;     

int main() {
    // 3. Stack 영역: 지역변수
    int local_var = 200;   

    // 4. Heap 영역: malloc()으로 할당한 변수
    int *heap_var = (int *)malloc(sizeof(int)); 
    *heap_var = 300;

    // 5. Text(Code) 영역: 문자열 리터럴 (Read-Only Data)
    char *text_literal = "Hello BCB!"; 

    // 각 변수의 주소 출력 (%p는 포인터 주소를 16진수로 출력)
    printf("\n[ 메모리 영역별 주소 확인 ]\n");
    printf("1. Data (초기화된 전역변수)       : %p\n", &global_init_var);
    printf("2. BSS (초기화되지 않은 전역변수) : %p\n", &global_uninit_var);
    printf("3. Stack (지역변수)               : %p\n", &local_var);
    printf("4. Heap (malloc()으로 할당)       : %p\n", heap_var); // 주의: 포인터 자체가 가리키는 힙 공간의 주소
    printf("5. Text (문자열 리터럴)           : %p\n", text_literal); // 주의: 문자열 리터럴이 존재하는 곳의 주소

    free(heap_var); // 동적 할당 해제
    
    // GDB에서 메모리 맵을 확인하기 위해 프로그램이 바로 종료되지 않도록 무한루프나 입력 대기를 걸어줌
    // 여기서는 getchar()를 사용해 입력을 기다리게 합니다.
    printf("\nGDB에서 'info proc mappings'를 확인하세요. 계속하려면 Enter를 누르세요.\n");
    getchar();

    return 0;
}