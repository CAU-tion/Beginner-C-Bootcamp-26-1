# Challenge4. Format String 맛보기

#### 문제

- printf의 포맷 스트링(%d, %x, %s, %p 등)을 활용해 동일한 변수를 여러 포맷으로 출력해보기
- 포맷 지정자를 잘못 사용했을 때(예: int를 %s로 출력) 어떤 일이 일어나는지 실험하고 원하는 방식으로 정리
- (힌트) 이게 왜 보안 취약점이 될 수 있는지 간단히 조사해보기

#### 풀이

1. 프로그램 코드(challenge4.c)
    
    ```powershell
    #include <stdio.h>
    
    int main() {
        int secret_num = 65;             
        char *secret_str = "Hello"; 
    
        printf("[1. 정상적인 포맷 출력]\n");
        printf("Decimal (%%d): %d\n", secret_num);
        printf("Hex     (%%x): %x\n", secret_num);
        printf("Char    (%%c): %c\n", secret_num);
        printf("Address (%%p): %p\n", &secret_num);
    
        printf("\n[2. 잘못된 포맷 사용 실험]\n");
        printf("Integer as String (%%s): ");
        fflush(stdout); 
        
        printf("%s\n", secret_num); 
    
        return 0;
    }
    ```
    
2. 실행 결과
    
    ```powershell
    [1. 정상적인 포맷 출력]
    Decimal (%d): 65
    Hex     (%x): 41
    Char    (%c): A
    Address (%p): 0x7ffc557fe51c
    
    [2. 잘못된 포맷 사용 실험]
    Integer as String (%s): Segmentation fault (core dumped)
    ```
    
3. 보안 취약점
    - 취약점 원인
        - 사용자의 입력값을 printf의 첫 번째 인자(포맷 스트링 그 자체)로 직접 사용할 때 발생
    - 취약점
        - 정보 유출
            - 공격자가 %p %p %p와 같은 입력을 넣으면, printf는 스택(Stack) 메모리에 있는 값들을 순차적으로 보여줌
            - 예시
                
                ```powershell
                char user_input[100];
                scanf("%s", user_input); // 사용자가 "%p %p %p"라고 입력함
                
                printf(user_input);      // 여기서 user_input이 '첫 번째 인자'가 됨
                ```
                
        - 임의 메모리 쓰기
            - %n 지정자는 지금까지 출력된 글자 수를 특정 주소에 저장하는 기능을 가짐
            - 이를 악용하면 공격자가 프로그램의 변수 값을 조작하거나, 실행 흐름을 바꿔 악성 코드를 실행(RCE)할 수 있음