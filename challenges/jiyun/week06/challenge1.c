#include <stdio.h>

int main(void) {
    int num = 10;
    int *ptr = &num;

    printf("num value: %d\n", num);
    printf("num address (&num): %p\n", (void *)&num);

    printf("ptr value: %p\n", (void *)ptr);
    printf("value pointed by ptr (*ptr): %d\n", *ptr);

    printf("\nChange num using pointer...\n");
    *ptr = 20;

    printf("num value after change: %d\n", num);
    printf("value pointed by ptr after change: %d\n", *ptr);

    printf("\nsize of ptr: %zu bytes\n", sizeof(ptr));
    printf("address of ptr (&ptr): %p\n", (void *)&ptr);

    return 0;
}