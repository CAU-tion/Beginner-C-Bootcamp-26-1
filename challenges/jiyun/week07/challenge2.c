#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));

    if (p == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    *p = 1234;

    printf("[Before free]\n");
    printf("p address: %p\n", p);
    printf("p value: %d\n", *p);

    free(p);

    printf("\n[After free]\n");
    printf("p address: %p\n", p);
    printf("p value after free: %d\n", *p);

    *p = 5678;
    printf("p value after write: %d\n", *p);

    return 0;
}