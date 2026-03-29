#include <stdio.h>
#include <limits.h>

int main(void) {
    int s = INT_MAX;
    unsigned int u = UINT_MAX;

    printf("=== Signed Overflow Test ===\n");
    printf("INT_MAX = %d\n", s);
    printf("INT_MAX + 1 = %d\n", s + 1);

    printf("\n=== Unsigned Overflow Test ===\n");
    printf("UINT_MAX = %u\n", u);
    printf("UINT_MAX + 1 = %u\n", u + 1);

    return 0;
}
