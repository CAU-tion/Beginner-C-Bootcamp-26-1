# Challenge2. gdb로 스택 프레임 관찰

#### 문제

- 스택 프레임이 무엇인지 조사하기
- Challenge1에서 만든 코드를 gcc -g -O0으로 컴파일 후 gdb로 디버깅
- 함수 호출 전후로 다음 항목 관찰하고 간단히 정리
    - rsp, rbp 값의 변화
- call 명령어 실행 시 ret address가 스택에 쌓이는 것 확인
- leave / ret 명령어 실행 후 스택 복원 확인
- (힌트) info frame, x/16gx $rsp 명령어 활용

#### 풀이

```bash
# main 함수 디스어셈블
(gdb) disassemble main
Dump of assembler code for function main:
   0x00005555555554a9 <+0>:     endbr64
   0x00005555555554ad <+4>:     push   %rbp
   0x00005555555554ae <+5>:     mov    %rsp,%rbp
   0x00005555555554b1 <+8>:     sub    $0x320,%rsp
   0x00005555555554b8 <+15>:    mov    %fs:0x28,%rax
=> 0x00005555555554c1 <+24>:    mov    %rax,-0x8(%rbp)
   0x00005555555554c5 <+28>:    xor    %eax,%eax
   0x00005555555554c7 <+30>:    call   0x555555555249 <print_banner>
   0x00005555555554cc <+35>:    call   0x555555555290 <get_shift>
   0x00005555555554d1 <+40>:    mov    %eax,-0x314(%rbp)
   
# call 직전에 break 설정 
(gdb) break *0x5555555554c7
Breakpoint 5 at 0x5555555554c7: file challenge01.c, line 74.

# 실행
(gdb) r
Breakpoint 5, main () at challenge01.c:74
74          print_banner();

# call 직전 상태 확인
(gdb) info registers rsp rbp
rsp            0x7fffffffd940      0x7fffffffd940
rbp            0x7fffffffdc60      0x7fffffffdc60
(gdb) x/8gx $rsp
0x7fffffffd940: 0x0963cf85f7fc5d60      0x00007ffff7c9f66c
0x7fffffffd950: 0x0000000000000001      0x79daee5f187f7200
0x7fffffffd960: 0x0000000000000000      0x0000000000000001
0x7fffffffd970: 0x00007fffffffd9b0      0x00007ffff7d85596

# call 실행
(gdb) si
print_banner () at challenge01.c:9
9       {

# call 실행 후 상태 확인
(gdb) info registers rsp rbp
rsp            0x7fffffffd938      0x7fffffffd938  # ←  rsp 8 감소
rbp            0x7fffffffdc60      0x7fffffffdc60
(gdb) x/8gx $rsp
0x7fffffffd938: 0x00005555555554cc      0x0963cf85f7fc5d60 # ← return address
0x7fffffffd948: 0x00007ffff7c9f66c      0x0000000000000001
0x7fffffffd958: 0x79daee5f187f7200      0x0000000000000000
0x7fffffffd968: 0x0000000000000001      0x00007fffffffd9b0

# return address 확인 
(gdb) x/i 0x5555555554cc
0x5555555554cc <main+35>:    call   0x555555555290 <get_shift>
```

- 스택 프레임
    - 함수 하나가 실행되는 동안 사용하는 스택 메모리 영역
    - 레지스터
        - rsp: 스택의 맨 위
        - rbp: 현재 함수의 기준점