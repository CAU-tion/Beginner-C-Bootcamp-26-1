#include <stdio.h>
#include <stdlib.h>

int global_init = 10;          // Data 영역
int global_uninit;             // BSS 영역

int main() {
    int stack_var = 20;        // Stack 영역
    char *heap_var = (char *)malloc(16); // Heap 영역
    char *text_var = "Hello";  // Text 영역

    printf("--- Memory Layout Check ---\n");
    printf("Text (Literal): %p\n", (void*)text_var);
    printf("Data (Global): %p\n", (void*)&global_init);
    printf("BSS (Global):  %p\n", (void*)&global_uninit);
    printf("Heap:          %p\n", (void*)heap_var);
    printf("Stack:         %p\n", (void*)&stack_var);

    free(heap_var);
    return 0;
}

