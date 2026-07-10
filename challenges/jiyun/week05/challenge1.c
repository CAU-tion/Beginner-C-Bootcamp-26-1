#include <stdio.h>
#include <stdlib.h>

int global_init = 10;      // Data
int global_uninit;         // BSS

int main() {
    int local = 20;        // Stack
    char *heap = malloc(10); // Heap
    char *str = "Hello";   // Text

    printf("global_init: %p\n", &global_init);
    printf("global_uninit: %p\n", &global_uninit);
    printf("local: %p\n", &local);
    printf("heap: %p\n", heap);
    printf("str: %p\n", str);

    return 0;
}