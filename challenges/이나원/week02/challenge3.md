# Challenge3. Integer Overflow 실험

#### 문제

- int 범위의 최댓값(INT_MAX)에 1을 더하면 어떻게 되는지 확인하는 코드 작성
- signed / unsigned 각각 실험해보기
- 실험 결과와 원인을 정리 ([README.md](http://readme.md/), Text 파일 등 원하는 방식)

#### 풀이

1. 프로그램 코드(challenge3.c)
    
    ```powershell
    #include <stdio.h>
    #include <limits.h>
    
    int main() {
    
        printf("1. Signed Overflow\n");
        printf("Signed Max: %d\n", INT_MAX);
        printf("Signed Max + 1: %d\n", INT_MAX + 1);
    
        printf("\n2. Unsigned Overflow\n");
        printf("Unsigned Max: %u\n", UINT_MAX);
        printf("Unsigned Max + 1: %u\n", UINT_MAX + 1);
    
        return 0;
    }
    ```
    
2. 실행 결과
    
    ```powershell
    1. Signed Overflow
    Signed Max: 2147483647
    Signed Max + 1: -2147483648
    
    2. Unsigned Overflow
    Unsigned Max: 4294967295
    Unsigned Max + 1: 0
    ```
    
3. 실험 결과 및 원인 
    - Signed Overflow
        - 결과: 2147483647 → -2147483648
        - 원인:
            - INT_MAX는 비트로 0111...111
            - 여기에 1을 더하면 비트 올림이 발생해 1000...000
            - 컴퓨터는 맨 앞 비트가 1이면 음수로 해석하므로, 가장 작은 음수인 INT_MIN으로 되돌아가는 Wrap-around 현상이 발생
    - Unsigned Overflow
        - 결과: 4294967295 → 0
        - 원인
            - UINT_MAX는 비트 1111...111
            - 여기에 1을 더하면 모든 비트가 0이 되고, 범위를 벗어난 마지막 올림수(Carry)는 버려짐
            - 따라서 다시 0부터 시작