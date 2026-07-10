challenge 1  
```  
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 정수 1개 동적 할당
    int *num = (int *)malloc(sizeof(int));

    // int형 배열 5개 동적 할당
    int *arr = (int *)malloc(sizeof(int) * 5);

    // malloc 실패 확인
    if (num == NULL || arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 값 저장
    *num = 100;

    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    // 값 출력
    printf("num 값: %d\n", *num);

    printf("arr 값들: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 주소 출력
    printf("num 주소: %p\n", (void *)num);
    printf("arr 주소: %p\n", (void *)arr);

    // 메모리 해제
    free(num);
    free(arr);
    return 0;
}
```
결과  
```  
num 값: 100
arr 값들: 0 10 20 30 40
num 주소: 0x5e8d08df02a0
arr 주소: 0x5e8d08df02c0
```  
free()를 사용하지않으면 메모리가 계속 늘어나 메모리 누수가 생길 수 있음  

challenge 2  
```  
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    *ptr = 1234;

    printf("free 전 값: %d\n", *ptr);
    printf("주소: %p\n", (void *)ptr);

    // 메모리 해제
    free(ptr);

    printf("free 후 접근 시도\n");

    // Dangling Pointer 접근
    printf("읽기: %d\n", *ptr);

    *ptr = 7777;

    printf("쓰기 후 값: %d\n", *ptr);

    return 0;
}
```
결과
```  
free 전 값: 1234
주소: 0x5e3407b492a0
free 후 접근 시도
읽기: -482313399
쓰기 후 값: 7777
```
free()는 메모리를 반납하게 되는데 포인터 변수는 반납 이전 주소를 계속 가지고 있어서 이상해진다  
따라서 free() 이후 포인터 변수를 ptr = NULL 등으로 초기화 시켜줘야 한다
