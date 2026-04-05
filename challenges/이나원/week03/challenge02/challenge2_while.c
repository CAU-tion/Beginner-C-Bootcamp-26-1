#include <stdio.h>

int main() {
    int sum_while = 0;
    int i;

    // 2. while 문
    i = 1;
    while (i <= 10) {
        sum_while += i;
        i++;
    }

    printf("Result: %d\n", sum_while);
    return 0;
}