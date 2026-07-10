#include <stdio.h>

int main() {
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);

    // 3. switch문
    // (num > 0)은 참이면 1, 거짓이면 0을 반환
    int condition = (num > 0) - (num < 0); 
    
    switch (condition) {
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