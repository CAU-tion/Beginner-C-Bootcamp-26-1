challenge1  
```
pwndbg> checksec
```
보호 기법 확인  
```
File:       /mnt/c/Users/user/vuln
Arch:       amd64
RELRO:      Partial RELRO
Stack:      No canary found
NX:         NX enabled
PIE:        No PIE (0x400000)
SHSTK:      Enabled
IBT:        Enabled
Stripped:   No
Debuginfo:  Yes
```
```
pwndbg> stack
```
현재 스택 확인  
```
00:0000│ rsp 0x7fffffffdf80 {buf} ◂— 0
01:0008│-008 0x7fffffffdf88 {buf+0x8} —▸ 0x7ffff7fe5af0 (dl_main) ◂— endbr64
02:0010│ rbp 0x7fffffffdf90 —▸ 0x7fffffffdfa0 —▸ 0x7fffffffe040 —▸ 0x7fffffffe0a0 ◂— 0
03:0018│+008 0x7fffffffdf98 —▸ 0x4011a2 (main+18) ◂— mov eax, 0
04:0020│+010 0x7fffffffdfa0 —▸ 0x7fffffffe040 —▸ 0x7fffffffe0a0 ◂— 0
05:0028│+018 0x7fffffffdfa8 —▸ 0x7ffff7c2a1ca (__libc_start_call_main+122) ◂— mov edi, eax
06:0030│+020 0x7fffffffdfb0 —▸ 0x7fffffffdff0 —▸ 0x403e00 (__do_global_dtors_aux_fini_array_entry) —▸ 0x401120 (__do_global_dtors_aux) ◂— endbr64
07:0038│+028 0x7fffffffdfb8 —▸ 0x7fffffffe0c8 —▸ 0x7fffffffe35d ◂— '/mnt/c/Users/user/vuln'
```
```
pwndbg> nearpc
```
주변 어셈블리 확인  
```
b► 0x40117c <vuln+12>    lea    rax, [rbp - 0x10]     RAX => 0x7fffffffdf80 {buf} ◂— 0
   0x401180 <vuln+16>    mov    rdi, rax              RDI => 0x7fffffffdf80 {buf}
   0x401183 <vuln+19>    mov    eax, 0                EAX => 0
   0x401188 <vuln+24>    call   gets@plt                    <gets@plt>

   0x40118d <vuln+29>    nop
   0x40118e <vuln+30>    leave
   0x40118f <vuln+31>    ret

   0x401190 <main>       endbr64
   0x401194 <main+4>     push   rbp
   0x401195 <main+5>     mov    rbp, rsp
```
```
pwndbg> disassemble
```
기계어를 어셈블리로 확인  
```
Dump of assembler code for function vuln:
   0x0000000000401170 <+0>:     endbr64
   0x0000000000401174 <+4>:     push   rbp
   0x0000000000401175 <+5>:     mov    rbp,rsp
   0x0000000000401178 <+8>:     sub    rsp,0x10
=> 0x000000000040117c <+12>:    lea    rax,[rbp-0x10]
   0x0000000000401180 <+16>:    mov    rdi,rax
   0x0000000000401183 <+19>:    mov    eax,0x0
   0x0000000000401188 <+24>:    call   0x401060 <gets@plt>
   0x000000000040118d <+29>:    nop
   0x000000000040118e <+30>:    leave
   0x000000000040118f <+31>:    ret
End of assembler dump.
```

challenge2  
https://dreamhack.io/wargame/challenges/3
