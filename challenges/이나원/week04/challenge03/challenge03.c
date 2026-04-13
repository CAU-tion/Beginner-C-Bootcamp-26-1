#include <stdio.h>

/*
 * 7개 인자를 받는 함수
 * rdi=a, rsi=b, rdx=c, rcx=d, r8=e, r9=f
 * g는 스택으로 전달됨 (rsp+8 위치, ret addr 다음)
 */
int sum_seven(int a, int b, int c, int d, int e, int f, int g)
{
    return a + b + c + d + e + f + g;
}

int main(void)
{
    int result = sum_seven(1, 2, 3, 4, 5, 6, 7);
    printf("sum = %d\n", result);  
    return 0;
}