#include <stdio.h>

int main() {
    printf("=== Basic Type Sizes ===\n");
    printf("char: %zu bytes\n", sizeof(char));
    printf("short: %zu bytes\n", sizeof(short));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long: %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    printf("long double: %zu bytes\n", sizeof(long double));

    printf("\n=== Signed / Unsigned Integer Type Sizes ===\n");
    printf("signed char: %zu bytes\n", sizeof(signed char));
    printf("unsigned char: %zu bytes\n", sizeof(unsigned char));
    printf("signed short: %zu bytes\n", sizeof(signed short));
    printf("unsigned short: %zu bytes\n", sizeof(unsigned short));
    printf("signed int: %zu bytes\n", sizeof(signed int));
    printf("unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("signed long: %zu bytes\n", sizeof(signed long));
    printf("unsigned long: %zu bytes\n", sizeof(unsigned long));
    printf("signed long long: %zu bytes\n", sizeof(signed long long));
    printf("unsigned long long: %zu bytes\n", sizeof(unsigned long long));

    return 0;
}