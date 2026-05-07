#include <stdio.h>

void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    printf("Inside swap_by_value: a = %d, b = %d\n", a, b);
}

void swap_by_reference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    printf("Inside swap_by_reference: *a = %d, *b = %d\n", *a, *b);
}

int main(void) {
    int x = 10;
    int y = 20;

    printf("Before swap_by_value: x = %d, y = %d\n", x, y);
    swap_by_value(x, y);
    printf("After swap_by_value: x = %d, y = %d\n", x, y);

    printf("\nBefore swap_by_reference: x = %d, y = %d\n", x, y);
    swap_by_reference(&x, &y);
    printf("After swap_by_reference: x = %d, y = %d\n", x, y);

    return 0;
}