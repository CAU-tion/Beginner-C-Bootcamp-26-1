#include <stdio.h>
#include <limits.h>

int main() {
    int s = INT_MAX;
    unsigned int u = UINT_MAX;

    printf("=== Signed ===\n");
    printf("INT_MAX = %d\n", INT_MAX);
    printf("Before: %d\n", s);
    s = s + 1;
    printf("After: %d\n", s);

    printf("\n=== Unsigned ===\n");
    printf("UINT_MAX = %u\n", UINT_MAX);
    printf("Before: %u\n", u);
    u = u + 1;
    printf("After: %u\n", u);

    return 0;
}
