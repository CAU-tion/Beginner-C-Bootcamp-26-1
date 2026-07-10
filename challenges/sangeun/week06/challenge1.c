#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;

    printf("num value: %d\n", num);
    printf("num address: %p\n", (void*)&num);

    printf("address stored in ptr: %p\n", (void*)ptr);
    printf("value pointed by ptr: %d\n", *ptr);

    *ptr = 20;

    printf("num value after changing by pointer: %d\n", num);

    printf("size of pointer ptr: %zu bytes\n", sizeof(ptr));
    printf("address of pointer variable ptr: %p\n", (void*)&ptr);

    return 0;
}