#include <stdio.h>

int main() {
    int sum_for = 0, sum_while = 0, sum_do_while = 0;
    int i;

    // 3. do-while 문
    i = 1;
    do {
        sum_do_while += i;
        i++;
    } while (i <= 10);

    printf("Result: %d\n", sum_do_while);
    return 0;
}