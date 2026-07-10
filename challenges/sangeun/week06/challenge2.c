#include <stdio.h>

int main() {

    int arr[5] = {10, 20, 30, 40, 50};

    int *ptr = arr;

    printf("Using arr[i]\n");

    for(int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\nUsing *(ptr + i)\n");

    for(int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }

    printf("\nPointer address movement\n");

    printf("Current ptr address: %p\n", (void*)ptr);

    ptr++;

    printf("After ptr++ address: %p\n", (void*)ptr);

    ptr--;

    printf("After ptr-- address: %p\n", (void*)ptr);

    return 0;
}