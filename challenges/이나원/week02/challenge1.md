# Challenge1. 자료형 크기 확인하기

#### 문제

- sizeof 연산자를 이용해 C의 기본 자료형(char, short, int, long, long long, float, double 등)의 크기를 출력하는 프로그램 작성
- signed/unsigned 차이도 함께 출력해보기
- 출력 결과를 정리하고, 왜 이런 크기인지 간단히 설명

#### 풀이

1. 프로그램 코드(challenge1.c)
    
    ```powershell
    #include <stdio.h>
    
    int main() {
        printf("[Data Type Sizes]\n");
        printf("char      : %zu byte\n", sizeof(char));
        printf("short     : %zu bytes\n", sizeof(short));
        printf("int       : %zu bytes\n", sizeof(int));
        printf("long      : %zu bytes\n", sizeof(long));
        printf("long long : %zu bytes\n", sizeof(long long));
        printf("float     : %zu bytes\n", sizeof(float));
        printf("double    : %zu bytes\n", sizeof(double));
    
        printf("\n[Difference of Signed&Unsigned]\n");
        printf("signed int   : %zu bytes\n", sizeof(signed int));
        printf("unsigned int : %zu bytes\n", sizeof(unsigned int));
        
        return 0;
    }
    ```
    
2. 실행 결과
    
    ```powershell
    [Data Type Sizes]
    char      : 1 byte
    short     : 2 bytes
    int       : 4 bytes
    long      : 8 bytes
    long long : 8 bytes
    float     : 4 bytes
    double    : 8 bytes
    
    [Difference between Signed & Unsigned]
    signed int   : 4 bytes
    unsigned int : 4 bytes
    ```
    
3. 자료형 크기 결정 원리
    - 컴퓨터 구조의 효율성: CPU가 한 번에 처리할 수 있는 데이터 단위(Word)에 최적화되어 있다.
4. 기타
    - z: 출력할 데이터가 시스템의 메모리 주소 체계(32/64비트)에 맞춘 size_t 타입임을 컴파일러에게 알려주는 크기 수정자(Size Modifier)