# Challenge1. Format String Bug 실습

#### 문제

- 2주차에서 조사했던 Format String을 이번엔 직접 손으로 터뜨려보기

```c
//취약한 코드
  int main(int argc, char *argv[]) {
    printf(argv[1]);  // ← 인자를 포맷 스트링으로 직접 전달
}
```

- 아래 순서로 실습 진행
    1. 위 코드를 `gcc -g -O0`으로 컴파일
    2. `./vuln "%x %x %x %x"` 형태로 실행해서 출력값 관찰
    3. `%p, %d, %s` 등 다양한 포맷 지정자로 바꿔가며 어떤 값이 나오는지 확인
    4. 안전한 코드(`printf("%s", argv[1])`)와 비교 실행해서 차이 확인
    5. 취약한 코드 vs. 안전한 코드를 비교하고, 이러한 현상이 발생하는 이유 정리하기

#### 풀이

1. 취약한 코드 컴파일
    
    ```bash
    #컴파일
    $ gcc -g -O0 challenge1.c -o challenge1
    
    #컴파일 결과
    challenge1.c: In function ‘main’:
    challenge1.c:3:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
        3 |     printf(argv[1]);  // ← 인자를 포맷 스트링으로 직접 전달
          |     ^~~~~~
    challenge1.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
      +++ |+#include <stdio.h>
        1 | //취약한 코드
    challenge1.c:3:5: warning: incompatible implicit declaration of built-in function ‘printf’ [-Wbuiltin-declaration-mismatch]
        3 |     printf(argv[1]);  // ← 인자를 포맷 스트링으로 직접 전달
          |     ^~~~~~
    challenge1.c:3:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
    challenge1.c:3:5: warning: format not a string literal and no format arguments [-Wformat-security]
    ```
    
    - -O0: 최적화 없음 (코드가 그대로 유지)
    - -g: 디버깅 정보 포함
2. 취약한 코드 실행
    
    ```bash
    입력: ./challenge1 "%x %x %x %x"
    출력: 19017cd8 19017cf0 56f75dc0 0
    ```
    
    - %x: 스택에 있는 값을 16진수로 출력
    
    ```bash
    입력: ./challenge1 "%p %p %p %p"
    출력: 0x7fffd909c4c8 0x7fffd909c4e0 0x62347efa7dc0 (nil)
    ```
    
    - %p: 포인터 값을 출력
    
    ```bash
    입력: ./challenge1 "%d %d %d %d"
    출력: -281516808 -281516784 7945664 0
    ```
    
    - %d: 값을 10진수 정수로 출력
    
    ```bash
    입력: ./challenge1 "%s %s %s %s"
    출력: ���� 9����  (null)
    ```
    
    - %s: 주소를 받아서 그 위치의 문자열을 읽음
3. 안전한 코드 ↔ 취약한 코드 
    - 취약한 코드
        - printf 함수는 첫 번째 인자로 포맷 스트링을 받고, 그 안에 %x, %p 등이 있으면 스택이나 레지스터에서 그 개수만큼 다음 인자들을 꺼내서 출력
        - printf(argv[1])처럼 사용하면, 사용자가 악의적으로 %x를 넣었을 때 프로그램은 인자가 실제로 전달되지 않았음에도 메모리에서 값을 무작정 꺼내어 읽어버림
    - 안전한 코드
        - printf("%s", argv[1])는 포맷 스트링이 "%s"로 고정되어 있음
        - 따라서, 사용자가 argv[1]에 %x를 넣더라도, 단순히 %x라는 문자 자체로 취급하여 문자열로 출력할 뿐 메모리를 읽어오지 않음