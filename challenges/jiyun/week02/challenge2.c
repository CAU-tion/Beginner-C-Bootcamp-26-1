#include <stdio.h>

void print_binary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
}

int main() {
    int a, b;

    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &a, &b);

    printf("\n=== Decimal ===\n");
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    printf("~a = %d\n", ~a);
    printf("a << 1 = %d\n", a << 1);
    printf("a >> 1 = %d\n", a >> 1);

    printf("\n=== Binary ===\n");

    printf("a      = "); print_binary(a); printf("\n");
    printf("b      = "); print_binary(b); printf("\n");
    printf("a & b  = "); print_binary(a & b); printf("\n");
    printf("a | b  = "); print_binary(a | b); printf("\n");
    printf("a ^ b  = "); print_binary(a ^ b); printf("\n");
    printf("~a     = "); print_binary(~a); printf("\n");
    printf("a << 1 = "); print_binary(a << 1); printf("\n");
    printf("a >> 1 = "); print_binary(a >> 1); printf("\n");

    return 0;
}
