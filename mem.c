#include <stdio.h>
#include <stdlib.h>

int a = 10;
int b;
char *msg = "hello";

int main() {
    int c = 20;

    int *d;
    d = malloc(sizeof(int));
    *d = 30;

    printf("a 주소: %p\n", &a);
    printf("b 주소: %p\n", &b);
    printf("c 주소: %p\n", &c);
    printf("d 주소: %p\n", d);
    printf("msg 주소: %p\n", msg);

    return 0;
}