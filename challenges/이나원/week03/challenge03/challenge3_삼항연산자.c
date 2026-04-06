#include <stdio.h>

int main() {
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    // 2. 삼항 연산자
    printf("%s\n", (num > 0) ? "양수입니다." : ((num < 0) ? "음수입니다." : "0입니다."));

    return 0;
}