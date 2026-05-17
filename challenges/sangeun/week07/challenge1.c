#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. 정수 1개 할당 및 NULL 체크
    int *p_num = (int *)malloc(sizeof(int));
    if (p_num == NULL) {
        fprintf(stderr, "Memory allocation failed for p_num\n");
        return 1;
    }

    // 2. 배열(int 5개) 할당 및 NULL 체크
    int *p_arr = (int *)malloc(sizeof(int) * 5);
    if (p_arr == NULL) {
        fprintf(stderr, "Memory allocation failed for p_arr\n");
        free(p_num); 
        return 1;
    }

    // 3. 할당된 메모리에 값 저장
    *p_num = 42;
    for (int i = 0; i < 5; i++) {
        p_arr[i] = (i + 1) * 10;
    }

    // 4. 값과 주소 출력 (Heap 영역인지 확인용)
    printf("[+] p_num Address: %p | Value: %d\n", (void*)p_num, *p_num);
    for (int i = 0; i < 5; i++) {
        printf("[+] p_arr[%d] Address: %p | Value: %d\n", i, (void*)&p_arr[i], p_arr[i]);
    }

    // 5. 사용 후 free()로 해제
    free(p_num);
    free(p_arr);

    return 0;
}
