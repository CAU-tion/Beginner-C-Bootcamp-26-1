#include <stdio.h>
#include <stdlib.h>

int main() {
    // 힙 메모리 할당 (tcache 크기인 16바이트)
    int *ptr = (int *)malloc(16);
    if (ptr == NULL) return 1;
    
    printf("[+] First Free: %p\n", (void*)ptr);
    free(ptr); // 첫 번째 해제

    printf("[+] Second Free (Double Free!): %p\n", (void*)ptr);
    free(ptr); // [조건] 동일한 포인터를 연달아 두 번 해제

    printf("[+] Successfully passed double free?\n");
    return 0;
}
