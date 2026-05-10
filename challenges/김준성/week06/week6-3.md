#include <stdio.h>

// 1. Call by Value: 값을 복사해서 전달 (원본 수정 불가)
void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Call by Reference: 주소를 전달 (원본 수정 가능)
void swap_by_reference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;

    printf("--- [초기 상태] ---\n");
    printf("x = %d, y = %d\n\n", x, y);

    // [테스트 1] Call by Value
    swap_by_value(x, y);
    printf("--- [swap_by_value 호출 후] ---\n");
    printf("x = %d, y = %d (값이 바뀌지 않음)\n\n", x, y);

    // [테스트 2] Call by Reference
    swap_by_reference(&x, &y); // x와 y의 '주소'를 넘김
    printf("--- [swap_by_reference 호출 후] ---\n");
    printf("x = %d, y = %d (값이 바뀜!)\n", x, y);

    return 0;
}

--- [초기 상태] ---
x = 10, y = 20

--- [swap_by_value 호출 후] ---
x = 10, y = 20 (값이 바뀌지 않음)

--- [swap_by_reference 호출 후] ---
x = 20, y = 10 (값이 바뀜!)


값에 의한 호출 (Call by Value): 함수 호출 시 변수의 값을 복사하여 전달한다. 함수 내부에서 매개변수를 변경하더라도 원본 변수에는 영향을 주지 않아 데이터의 독립성이 보장된다.

참조에 의한 호출 (Call by Reference): 포인터를 이용해 변수의 메모리 주소를 전달한다. 함수 내부에서 포인터를 통해 원본 데이터에 직접 접근하므로, 함수 내의 변경 사항이 호출 측의 원본 변수에 그대로 반영된다.

Call by Value가 유리한 상황:
원본 데이터의 수정 없이 단순히 값을 참조하여 계산 결과만을 얻고자 할 때 적합하다.
크기가 작은 기본 자료형(int, char 등)을 다룰 때 복사 과정이 단순하여 안전하게 사용할 수 있다.

Call by Reference가 유리한 상황:
swap 함수와 같이 함수 외부의 원본 데이터를 직접 수정해야 하는 로직에 필수적이다.
배열이나 대규모 구조체처럼 크기가 큰 데이터를 전달할 때, 전체 복사로 인한 메모리 낭비와 속도 저하를 방지하고 주소값만 전달하여 효율을 극대화할 수 있다.
한 번의 함수 호출로 여러 개의 변수 값을 동시에 갱신해야 할 때 효과적으로 활용된다.

