#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Access using arr[i]\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, address = %p\n", i, arr[i], (void *)&arr[i]);
    }

    printf("\nAccess using *(ptr + i)\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d, address = %p\n", i, *(ptr + i), (void *)(ptr + i));
    }

    printf("\nPointer address movement\n");
    printf("ptr     = %p\n", (void *)ptr);
    printf("ptr + 1 = %p\n", (void *)(ptr + 1));
    printf("ptr + 2 = %p\n", (void *)(ptr + 2));

    printf("\nptr++ and ptr-- test\n");
    printf("current ptr: %p, value: %d\n", (void *)ptr, *ptr);

    ptr++;
    printf("after ptr++: %p, value: %d\n", (void *)ptr, *ptr);

    ptr--;
    printf("after ptr--: %p, value: %d\n", (void *)ptr, *ptr);

    return 0;
}