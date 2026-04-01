#include <stdio.h>

int main() {
    int num;
    int state;

    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    if (num > 0) {
        state = 1;
    } else if (num < 0) {
        state = -1;
    } else {
        state = 0;
    }

    switch (state) {
        case 1:
            printf("양수입니다.\n");
            break;
        case -1:
            printf("음수입니다.\n");
            break;
        case 0:
            printf("0입니다.\n");
            break;
    }

    return 0;
}