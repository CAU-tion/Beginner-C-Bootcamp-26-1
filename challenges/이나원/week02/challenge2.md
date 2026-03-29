# Challenge2. 비트 연산 프로그램 작성

#### 문제

- 두 정수를 입력받아 AND(&), OR(|), XOR(^), NOT(~), left shift(<<), right shift(>>) 연산 결과를 출력하는 프로그램 작성
- 각 연산의 결과를 2진수로도 함께 출력해보기 (직접 구현 or printf 포맷 활용)

#### 풀이

1. 프로그램 코드(challenge2.c)
    
    ```powershell
    #include <stdio.h>
    #include <string.h>
    
    void print_centered(int num, int width) {
        char buf[32];
        int len = sprintf(buf, "%d", num); // 숫자를 문자열로 변환하여 길이 측정
        int padding = (width - len) / 2;    // 앞쪽 공백 계산
        
        if (padding < 0) padding = 0; // 예외 방지
    
        printf("%*s%s%*s", padding, "", buf, width - len - padding, "");
    }
    
    void Decimal_to_Binary(int n) {
        for (int i = 31; i >= 0; i--) {
            printf("%d", (n >> i) & 1);
            if (i % 8 == 0 && i != 0) printf(" "); 
        }
    }
    
    int main() {
        int a, b;
        printf("Put two integers: ");
        if (scanf("%d %d", &a, &b) != 2) return 1; 
    
        printf("\n %-18s | %-12s | %s\n", "Operation", "  Decimal", "Binary (32-bit)");
        printf("--------------------------------------------------------------------------\n");
    
        // 중간 정렬을 포함한 결과 출력 매크로
        #define PRINT_RES(name, res) \
            printf(" %-18s | ", name); \
            print_centered(res, 12); \
            printf(" | "); \
            Decimal_to_Binary(res); \
            printf("\n")
    
        PRINT_RES("AND (&)", a & b);
        PRINT_RES("OR  (|)", a | b);
        PRINT_RES("XOR (^)", a ^ b);
        PRINT_RES("NOT (~a)", ~a);
        PRINT_RES("Left Shift (<<1)", a << 1);
        PRINT_RES("Right Shift (>>1)", a >> 1);
    
        return 0;
    }
    ```
    
2. 실행 결과
    
    ```powershell
    Put two integers: 83 29
    
     Operation          |   Decimal    | Binary (32-bit)
    --------------------------------------------------------------------------
     AND (&)            |      17      | 00000000 00000000 00000000 00010001
     OR  (|)            |      95      | 00000000 00000000 00000000 01011111
     XOR (^)            |      78      | 00000000 00000000 00000000 01001110
     NOT (~a)           |     -84      | 11111111 11111111 11111111 10101100
     Left Shift (<<1)   |     166      | 00000000 00000000 00000000 10100110
     Right Shift (>>1)  |      41      | 00000000 00000000 00000000 00101001
    ```