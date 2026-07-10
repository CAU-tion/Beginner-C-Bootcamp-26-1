#include <stdio.h>

int main() {
    int sum_for = 0;
    int i;

    // 1. for 문
    for (i = 1; i <= 10; i++) {
        sum_for += i;
    }

    printf("Result: %d\n", sum_for);
    return 0;
}