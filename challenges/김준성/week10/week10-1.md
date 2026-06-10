pwndbg> checksec
File:     /home/snirn/week9_1
Arch:     amd64
RELRO:      Partial RELRO
Stack:      No canary found
NX:         NX enabled
PIE:        No PIE (0x400000)
SHSTK:      Enabled
IBT:        Enabled
Stripped:   No
Debuginfo:  Yes
pwndbg> disassemble main
Dump of assembler code for function main:
   0x0000000000401190 <+0>:     endbr64
   0x0000000000401194 <+4>:     push   rbp
   0x0000000000401195 <+5>:     mov    rbp,rsp
   0x0000000000401198 <+8>:     mov    eax,0x0
   0x000000000040119d <+13>:    call   0x401170 <vuln>
   0x00000000004011a2 <+18>:    mov    eax,0x0
   0x00000000004011a7 <+23>:    pop    rbp
   0x00000000004011a8 <+24>:    ret
End of assembler dump.
pwndbg> stack
stack: The program is not being run.
pwndbg> break main
Breakpoint 1 at 0x401198: file week9_1.c, line 11.
pwndbg> run
Starting program: /home/snirn/week9_1
Downloading separate debug info for system-supplied DSO at 0x7ffff7fc3000
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at week9_1.c:11
11          vuln();
LEGEND: STACK | HEAP | CODE | DATA | WX | RODATA
────────────────────────────────────────────────────[ LAST SIGNAL ]─────────────────────────────────────────────────────
Breakpoint hit at 0x401198
─────────────────────────────────[ REGISTERS / show-flags off / show-compact-regs off ]─────────────────────────────────
 RAX  0x401190 (main) ◂— endbr64
 RBX  0x7fffffffe128 —▸ 0x7fffffffe3ba ◂— '/home/snirn/week9_1'
 RCX  0x403e00 (__do_global_dtors_aux_fini_array_entry) —▸ 0x401120 (__do_global_dtors_aux) ◂— endbr64
 RDX  0x7fffffffe138 —▸ 0x7fffffffe3ce ◂— 'SHELL=/bin/bash'
 RDI  1
 RSI  0x7fffffffe128 —▸ 0x7fffffffe3ba ◂— '/home/snirn/week9_1'
 R8   0
 R9   0x7ffff7fca380 (_dl_fini) ◂— endbr64
 R10  0x7fffffffdd20 ◂— 0x800000
 R11  0x203
 R12  1
 R13  0
 R14  0x403e00 (__do_global_dtors_aux_fini_array_entry) —▸ 0x401120 (__do_global_dtors_aux) ◂— endbr64
 R15  0x7ffff7ffd000 (_rtld_global) —▸ 0x7ffff7ffe2e0 ◂— 0
 RBP  0x7fffffffe000 —▸ 0x7fffffffe0a0 —▸ 0x7fffffffe100 ◂— 0
 RSP  0x7fffffffe000 —▸ 0x7fffffffe0a0 —▸ 0x7fffffffe100 ◂— 0
 RIP  0x401198 (main+8) ◂— mov eax, 0
──────────────────────────────────────────[ DISASM / x86-64 / set emulate on ]──────────────────────────────────────────
b► 0x401198 <main+8>     mov    eax, 0     EAX => 0
   0x40119d <main+13>    call   vuln                        <vuln>

   0x4011a2 <main+18>    mov    eax, 0                 EAX => 0
   0x4011a7 <main+23>    pop    rbp
   0x4011a8 <main+24>    ret

   0x4011a9              add    byte ptr [rax], al
   0x4011ab              add    bl, dh


───────────────────────────────────────────────────[ SOURCE (CODE) ]────────────────────────────────────────────────────
In file: /home/snirn/week9_1.c:11
    1 void secret() {
    2     printf("secret function called!\n");
    3 }
    4
    5 void vuln() {
    6     char buf[16];
    7     gets(buf);
    8 }
    9
   10 int main() {
 ► 11     vuln();
   12     return 0;
   13 }
───────────────────────────────────────────────────────[ STACK ]────────────────────────────────────────────────────────
00:0000│ rbp rsp 0x7fffffffe000 —▸ 0x7fffffffe0a0 —▸ 0x7fffffffe100 ◂— 0
01:0008│+008     0x7fffffffe008 —▸ 0x7ffff7c2a1ca (__libc_start_call_main+122) ◂— mov edi, eax
02:0010│+010     0x7fffffffe010 —▸ 0x7fffffffe050 —▸ 0x403e00 (__do_global_dtors_aux_fini_array_entry) —▸ 0x401120 (__do_global_dtors_aux) ◂— endbr64
03:0018│+018     0x7fffffffe018 —▸ 0x7fffffffe128 —▸ 0x7fffffffe3ba ◂— '/home/snirn/week9_1'
04:0020│+020     0x7fffffffe020 ◂— 0x100400040 /* '@' */
05:0028│+028     0x7fffffffe028 —▸ 0x401190 (main) ◂— endbr64
06:0030│+030     0x7fffffffe030 —▸ 0x7fffffffe128 —▸ 0x7fffffffe3ba ◂— '/home/snirn/week9_1'
07:0038│+038     0x7fffffffe038 ◂— 0xaed2b64a6185239b
─────────────────────────────────────────────────────[ BACKTRACE ]──────────────────────────────────────────────────────
 ► 0         0x401198 main+8
   1   0x7ffff7c2a1ca __libc_start_call_main+122
   2   0x7ffff7c2a28b __libc_start_main+139
   3         0x401095 _start+37
────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
pwndbg> nearpc
b► 0x401198 <main+8>     mov    eax, 0     EAX => 0
   0x40119d <main+13>    call   vuln                        <vuln>

   0x4011a2 <main+18>    mov    eax, 0                 EAX => 0
   0x4011a7 <main+23>    pop    rbp
   0x4011a8 <main+24>    ret

   0x4011a9              add    byte ptr [rax], al
   0x4011ab              add    bl, dh
pwndbg> stack
00:0000│ rbp rsp 0x7fffffffe000 —▸ 0x7fffffffe0a0 —▸ 0x7fffffffe100 ◂— 0
01:0008│+008     0x7fffffffe008 —▸ 0x7ffff7c2a1ca (__libc_start_call_main+122) ◂— mov edi, eax
02:0010│+010     0x7fffffffe010 —▸ 0x7fffffffe050 —▸ 0x403e00 (__do_global_dtors_aux_fini_array_entry) —▸ 0x401120 (__do_global_dtors_aux) ◂— endbr64
03:0018│+018     0x7fffffffe018 —▸ 0x7fffffffe128 —▸ 0x7fffffffe3ba ◂— '/home/snirn/week9_1'
04:0020│+020     0x7fffffffe020 ◂— 0x100400040 /* '@' */
05:0028│+028     0x7fffffffe028 —▸ 0x401190 (main) ◂— endbr64
06:0030│+030     0x7fffffffe030 —▸ 0x7fffffffe128 —▸ 0x7fffffffe3ba ◂— '/home/snirn/week9_1'
07:0038│+038     0x7fffffffe038 ◂— 0xaed2b64a6185239b
pwndbg> disassemble
Dump of assembler code for function main:
   0x0000000000401190 <+0>:     endbr64
   0x0000000000401194 <+4>:     push   rbp
   0x0000000000401195 <+5>:     mov    rbp,rsp
=> 0x0000000000401198 <+8>:     mov    eax,0x0
   0x000000000040119d <+13>:    call   0x401170 <vuln>
   0x00000000004011a2 <+18>:    mov    eax,0x0
   0x00000000004011a7 <+23>:    pop    rbp
   0x00000000004011a8 <+24>:    ret
End of assembler dump.
pwndbg>
