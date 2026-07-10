# Challenge2. 반복문 3종 비교

#### 문제

- 동일한 동작(1부터 10까지 합산하는 코드)을 for / while / do-while 각각으로 구현
- 세 가지 코드를 모두 gcc -g -O0으로 컴파일
- 코드 상의 차이점과 각 반복문을 언제 쓰는 게 적절한지 정리

#### 풀이

1. 코드 작성
    - for문
        
        ```bash
        #include <stdio.h>
        
        int main() {
            int sum_for = 0;
            int i;
        
            // 1. for 문
            for (i = 1; i <= 10; i++) {
                sum_for += i;
            }
        
            printf("Result: %d\n", sum_for);
            return 0;
        }
        ```
        
    - while문
        
        ```bash
        #include <stdio.h>
        
        int main() {
            int sum_while = 0;
            int i;
        
            // 2. while 문
            i = 1;
            while (i <= 10) {
                sum_while += i;
                i++;
            }
        
            printf("Result: %d\n", sum_while);
            return 0;
        }
        ```
        
    - do-while문
        
        ```bash
        #include <stdio.h>
        
        int main() {
            int sum_for = 0, sum_while = 0, sum_do_while = 0;
            int i;
        
            // 3. do-while 문
            i = 1;
            do {
                sum_do_while += i;
                i++;
            } while (i <= 10);
        
            printf("Result: %d\n", sum_do_while);
            return 0;
        }
        ```
        
2. 반복문 비교 및 적절한 사용
    - for: 반복 횟수가 명확하게 정해져 있을 때
    - while: 반복 횟수보다는 특정 조건이 참일 때 계속 실행해야 할 때
    - do-while: 조건과 관계없이 최소 1번은 무조건 실행해야 할 때