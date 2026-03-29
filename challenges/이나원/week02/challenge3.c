#include <stdio.h>
#include <limits.h>

int main() {

    printf("1. Signed Overflow\n");
    printf("Signed Max: %d\n", INT_MAX);
    printf("Signed Max + 1: %d\n", INT_MAX + 1);

    printf("\n2. Unsigned Overflow\n");
    printf("Unsigned Max: %u\n", UINT_MAX);
    printf("Unsigned Max + 1: %u\n", UINT_MAX + 1);

    return 0;
}
