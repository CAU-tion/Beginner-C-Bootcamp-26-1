#include <stdio.h>
#include <stdlib.h>

int main() {
    int *num;
    int *arr;

    num = (int *)malloc(sizeof(int));
    if (num == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    arr = (int *)malloc(sizeof(int) * 5);
    if (arr == NULL) {
        printf("malloc failed\n");
        free(num);
        return 1;
    }

    *num = 100;

    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("num address: %p\n", num);
    printf("num value: %d\n", *num);

    printf("arr address: %p\n", arr);
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, address = %p\n", i, arr[i], &arr[i]);
    }

    free(num);
    free(arr);

    return 0;
}