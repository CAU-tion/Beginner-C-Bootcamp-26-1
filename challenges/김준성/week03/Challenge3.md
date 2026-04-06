1.if_else.c
#include <stdio.h>

int main() {
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    if (num > 0) {
        printf("양수입니다.\n");
    } else if (num < 0) {
        printf("음수입니다.\n");
    } else {
        printf("0입니다.\n");
    }
    return 0;
}

2.ternary.c
#include <stdio.h>

int main() {
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    // (조건) ? 참일때 : 거짓일때
    printf("%s\n", (num > 0) ? "양수입니다." : (num < 0) ? "음수입니다." : "0입니다.");
    return 0;
}

3.switch_case.c
#include <stdio.h>

int main() {
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    // 비교 연산의 결과(1 또는 0)를 이용한 트릭
    switch ((num > 0) - (num < 0)) {
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
