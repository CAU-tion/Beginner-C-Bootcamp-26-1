#include <stdio.h>

int main() {
    // 1. 변수 선언 및 포인터 선언
    int num = 10;
    int *ptr = &num; // num의 주소를 ptr에 저장

    // 2. 주소와 값 출력 (&, * 연산자 활용)
    printf("--- [기본 정보] ---\n");
    printf("변수 num의 값: %d\n", num);
    printf("변수 num의 주소 (&num): %p\n", (void*)&num);
    printf("포인터 ptr이 가리키는 주소 (ptr): %p\n", (void*)ptr);
    printf("포인터 ptr을 통한 값 접근 (*ptr): %d\n\n", *ptr);

    // 3. 포인터를 통한 원본 값 변경
    *ptr = 20;
    printf("--- [값 변경 후] ---\n");
    printf("포인터를 통해 변경된 num의 값: %d\n\n", num);

    // 4. 포인터 변수 자체의 정보 출력
    printf("--- [포인터 자체 정보] ---\n");
    printf("포인터 변수 ptr의 크기: %zu 바이트\n", sizeof(ptr));
    printf("포인터 변수 ptr의 자체 주소: %p\n", (void*)&ptr);

    return 0;


--- [기본 정보] ---
변수 num의 값: 10
변수 num의 주소 (&num): 0x7ffe3632d06c
포인터 ptr이 가리키는 주소 (ptr): 0x7ffe3632d06c
포인터 ptr을 통한 값 접근 (*ptr): 10

--- [값 변경 후] ---
포인터를 통해 변경된 num의 값: 20

--- [포인터 자체 정보] ---
포인터 변수 ptr의 크기: 8 바이트
포인터 변수 ptr의 자체 주소: 0x7ffe3632d070
