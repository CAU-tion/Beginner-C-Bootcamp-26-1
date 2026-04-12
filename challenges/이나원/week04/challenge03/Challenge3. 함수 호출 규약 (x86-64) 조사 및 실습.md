# Challenge3. 함수 호출 규약 (x86-64) 조사 및 실습

#### 문제

- x86-64 Linux의 함수 호출 규약(System V AMD64 ABI) 조사
- 인자가 레지스터로 전달되는 순서 (rdi, rsi, rdx, rcx, r8, r9) 정리
- 인자가 6개를 초과하면 어떻게 전달되는지 확인
- 인자를 7개 이상 받는 함수를 직접 작성하고 gdb로 스택/레지스터 전달 방식 비교

#### 풀이

- 인자 전달 순서(System V AMD64 ABI)
    
    
    | 순서 | 레지스터 |
    | --- | --- |
    | 1번째 | `rdi` |
    | 2번째 | `rsi` |
    | 3번째 | `rdx` |
    | 4번째 | `rcx` |
    | 5번째 | `r8` |
    | 6번째 | `r9` |
    | 7번째~ | 스택 |
- 예제 코드
    
    ```bash
    #include <stdio.h>
    
    /*
     * 7개 인자를 받는 함수
     * rdi=a, rsi=b, rdx=c, rcx=d, r8=e, r9=f
     * g는 스택으로 전달됨 (rsp+8 위치, ret addr 다음)
     */
    int sum_seven(int a, int b, int c, int d, int e, int f, int g)
    {
        return a + b + c + d + e + f + g;
    }
    
    int main(void)
    {
        int result = sum_seven(1, 2, 3, 4, 5, 6, 7);
        printf("sum = %d\n", result);  
        return 0;
    }
    ```
    
- 결과
    
    ```bash
    # sum_seven 앞 break 설정 및 실
    (gdb) break sum_seven
    (gdb) r
    
    # 레지스터 확인
    (gdb) info registers rdi rsi rdx rcx r8 r9
    rdi            0x1                 1
    rsi            0x2                 2
    rdx            0x3                 3
    rcx            0x4                 4
    r8             0x5                 5
    r9             0x6                 6
    
    # 7번째 인자 확인
    (gdb) x/gx $rsp+16
    0x7fffffffdc38: 0x0000000000000007
    ```