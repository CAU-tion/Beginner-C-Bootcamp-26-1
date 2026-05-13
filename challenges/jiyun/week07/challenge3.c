#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));

    if (p == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    *p = 777;

    printf("p address: %p\n", p);
    printf("p value: %d\n", *p);

    printf("\n[First free]\n");
    free(p);

    printf("[Second free]\n");
    free(p);

    return 0;
}