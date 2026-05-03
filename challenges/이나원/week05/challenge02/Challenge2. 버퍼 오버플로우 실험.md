# Challenge2. 버퍼 오버플로우 실험

# 문제

- 아래 취약한 코드를 직접 작성하고 `gcc -g -O0 -fno-stack-protector`로 컴파일
    
    ```c
    #include <stdio.h>
    
    void secret() {
        printf("secret function called!\n");
    }
    
    void vuln() {
        char buf[16];
        // gets()는 입력 길이를 검사하지 않아 버퍼 오버플로우 취약점이 발생
        gets(buf); 
    }
    
    int main() {
        vuln();
        return 0;
    }
    ```
    
- 정상 입력 / 16바이트 초과 입력 각각 실행해서 어떤 차이가 있는지 관찰
    - gdb로 `vuln()` 호출 시 스택 구조 확인
    - buf의 위치, ret address의 위치 확인
    - 긴 입력을 넣었을 때 ret address가 덮이는지 관찰
- `gets()` 이외에도 버퍼오버플로우에 취약한 함수 조사

# 풀이

#### 프로그램 실행

```bash
# 정상 입력 실행
입력: hello
결과: (아무 메시지 없이 종료)

# 긴 입력 실행
입력: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
결과: Segmentation fault (core dumped)
```

- 원인
    - `buf` 크기는 16바이트인데 `gets()`는 길이 제한 없이 입력을 복사
- 과정:
    - buf 넘침
    - saved frame pointer 덮침
    - return address 손상 가능
    - 함수 복귀 시 크래시

#### 디버깅

```bash
# vuln() 함수에 브레이크 설정
break vuln

# 프로그램 실행
run

# 결과(현재 실행 위치)
Breakpoint 1, vuln () at challenge02.c:10
10          gets(buf); 

# vuln() 함수 디스어셈블
disassemble vuln

# 결과
Dump of assembler code for function vuln:
   0x0000555555555183 <+0>:     endbr64
   # 이전 함수(main)의 기준점 저장
   0x0000555555555187 <+4>:     push   %rbp    
   # 현재 함수(vuln)의 기준점 생성
   0x0000555555555188 <+5>:     mov    %rsp,%rbp   
   # 16바이트 스택 공간 확보
   0x000055555555518b <+8>:     sub    $0x10,%rsp
   # buf 주소 계산
=> 0x000055555555518f <+12>:    lea    -0x10(%rbp),%rax
   0x0000555555555193 <+16>:    mov    %rax,%rdi
   0x0000555555555196 <+19>:    mov    $0x0,%eax
   # gets 실행
   0x000055555555519b <+24>:    call   0x555555555070 <gets@plt>
   0x00005555555551a0 <+29>:    nop
   # 함수 종료 코드
   0x00005555555551a1 <+30>:    leave
   0x00005555555551a2 <+31>:    ret

# buf 시작(buf[0]) 주소 확인
p &buf

# 결과
$1 = (char (*)[16]) 0x7fffffffe1d0

# rsp 기준으로 32바이트 메모리 덤프
x/32bx $rsp

# 결과
0x7fffffffe1d0: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffffe1d8: 0xf0    0x5a    0xfe    0xf7    0xff    0x7f    0x00    0x00
0x7fffffffe1e0: 0xf0    0xe1    0xff    0xff    0xff    0x7f    0x00    0x00
0x7fffffffe1e8: 0xb5    0x51    0x55    0x55    0x55    0x55    0x00    0x00

# 현재 함수의 stack frame 구조 설명
info frame

# 결과
 Saved registers:
  rbp at 0x7fffffffe1e0, rip at 0x7fffffffe1e8
```

```bash
# 이어서 진행
c

#입력
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

# 결과: 세그멘테이션 폴트(즉, 잘못된 메모리 접근)
Program received signal SIGSEGV, Segmentation fault.
0x00005555555551a2 in vuln () at challenge02.c:11
11      }

# 레지스터 확인
info registers

# 결과: 원래 스택 주소여야하는 rbp가 AAAAAAAA로 덮인 것을 확인
rbp            0x4141414141414141  0x4141414141414141
```

#### 버퍼오버플로우에 취약한 함수

- strcpy(dest, src)
    - 원본 문자열이 널(NULL) 문자로 끝날 때까지 무조건 복사
    - 대안: strncpy
- strcat(dest, src)
    - 두 문자열을 이어 붙일 때, 목적지 버퍼에 남은 공간이 충분한지 확인하지 않음
    - 대안: strncat
- sprintf(buf, format, ...)
    - 포맷에 맞춰 문자열을 만들 때 버퍼 크기를 무시
    - 대안:  snprintf
- scanf("%s", buf)
    - 띄어쓰기 전까지의 모든 입력을 무제한으로 받아들임
    - 대안: scanf("%15s", buf)처럼 길이 제한을 명시하는 대체 방법을 사용