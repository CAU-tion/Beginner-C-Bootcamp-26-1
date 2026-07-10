#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. 메모리 할당 후 값 저장
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) return 1;
    
    *ptr = 1337;
    printf("[+] Before free: ptr Address = %p | Value = %d\n", (void*)ptr, *ptr);

    // 2. free()로 메모리 해제
    free(ptr);
    printf("[+] After free (Dangling Pointer): ptr Address = %p\n", (void*)ptr);

    // 3. [위험] 해제된 포인터로 값을 다시 읽고 쓰기 시도
    printf("[+] Reading after free: %d\n", *ptr); 
    
    *ptr = 9999;
    printf("[+] Writing after free. New Value: %d\n", *ptr);

    return 0;
}
