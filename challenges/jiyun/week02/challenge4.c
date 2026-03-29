#include <stdio.h>

int main() {
    int num = 65;
    char ch = 'A';
    char str[] = "Hello";
    int *ptr = &num;

    printf("=== Correct Format ===\n");
    printf("num as %%d: %d\n", num);
    printf("num as %%x: %x\n", num);
    printf("num as %%c: %c\n", num);

    printf("\nch as %%c: %c\n", ch);
    printf("ch as %%d: %d\n", ch);

    printf("\nstr as %%s: %s\n", str);
    printf("ptr as %%p: %p\n", (void *)ptr);

    printf("\n=== Wrong Format ===\n");
    printf("num as %%c: %c\n", num);
    printf("str as %%p: %p\n", (void *)str);

    return 0;
}
