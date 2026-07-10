# Challenge4. gdb로 반복문 뜯어보기

#### 문제

- 리눅스에 gdb 설치
- Challenge2 혹은 Challenge3에서 만든 코드 중 하나를 골라 gdb로 디버깅
- 아래 기본 명령어를 직접 사용해보기
    - `break`, `run`, `next`, `step`, `info registers`, `x/`

#### 풀이

1. 대상 코드: challenge2_for.c
    - 브레이크포인트 설정
        
        ```bash
        (gdb) b main
        Breakpoint 1 at 0x1155: file challenge2_for.c, line 4.
        ```
        
    - 프로그램 실행
        
        ```bash
        (gdb) r
        Breakpoint 1, main () at challenge2_for.c:4
        warning: Source file is more recent than executable.
        4           int sum_for = 0;
        ```
        
    - 코드 한 줄 실행
        
        ```bash
        (gdb) n
        8           for (i = 1; i <= 10; i++) {
        ```
        
        ```bash
        (gdb) n
        9               sum_for += i;
        ```
        
    - 변수 값 확인
        
        ```bash
        (gdb) x/d &i
        0x7fffffffe1bc: 1
        (gdb) x/d &sum_for
        0x7fffffffe1b8: 0
        ```
        
    - 덧셈 실행
        
        ```bash
        (gdb) n
        8           for (i = 1; i <= 10; i++) {
        (gdb) x/d &sum_for
        0x7fffffffe1b8: 1
        ```
        
    - CPU 레지스터 확인
        
        ```bash
        (gdb) i r
        rax            0x1                 1
        rbx            0x7fffffffe2e8      140737488347880
        rcx            0x555555557dc0      93824992247232
        rdx            0x7fffffffe2f8      140737488347896
        rsi            0x7fffffffe2e8      140737488347880
        rdi            0x1                 1
        rbp            0x7fffffffe1c0      0x7fffffffe1c0
        rsp            0x7fffffffe1b0      0x7fffffffe1b0
        r8             0x0                 0
        r9             0x7ffff7fca380      140737353917312
        r10            0x7fffffffdee0      140737488346848
        r11            0x203               515
        r12            0x1                 1
        r13            0x0                 0
        r14            0x555555557dc0      93824992247232
        r15            0x7ffff7ffd000      140737354125312
        rip            0x55555555516b      0x55555555516b <main+34>
        eflags         0x202               [ IF ]
        cs             0x33                51
        ss             0x2b                43
        ds             0x0                 0
        es             0x0                 0
        fs             0x0                 0
        gs             0x0                 0
        k0             0x40004000          1073758208
        k1             0x2200000           35651584
        k2             0x0                 0
        k3             0x81000010          2164260880
        k4             0x0                 0
        k5             0x0                 0
        k6             0x0                 0
        k7             0x0                 0
        fs_base        0x7ffff7fad740      140737353799488
        gs_base        0x0                 0
        ```
        
    - 두 번째 반복 확인
        
        ```bash
        (gdb) n
        9               sum_for += i;
        (gdb) x/d &i
        0x7fffffffe1bc: 2
        (gdb) n
        8           for (i = 1; i <= 10; i++) {
        (gdb) x/d &sum_for
        0x7fffffffe1b8: 3
        ```
        
    - 디버깅 종료
        
        ```bash
        (gdb) q
        A debugging session is active.
        
                Inferior 1 [process 2373] will be killed.
        
        Quit anyway? (y or n) y
        ```