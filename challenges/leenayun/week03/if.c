#include <stdio.h>

int main() {
    int num;

    printf("숫자 입력: ");
    scanf("%d", &num);

    (num > 0) ? printf("양수\n") :
    (num < 0) ? printf("음수\n") :
                printf("0\n");

    return 0;
}