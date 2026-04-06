snirn@LAPTOP-V9INSQP0:~$ gdb -q ./for_sum
Reading symbols from ./for_sum...
(gdb) list
1       #include <stdio.h>
2
3       int main() {
4           int sum = 0;
5           // 초기식; 조건식; 증감식 한 곳에 모여 있음
6           for (int i = 1; i <= 10; i++) {
7               sum += i;
8           }
9           printf("For Sum: %d\n", sum);
10          return 0;
(gdb) break
No default breakpoint address now.
(gdb) break main
Breakpoint 1 at 0x1155: file for_sum.c, line 4.
(gdb) break 7
Breakpoint 2 at 0x1165: file for_sum.c, line 7.
(gdb) run
Starting program: /home/snirn/for_sum
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".


(gdb) i r
rax            0x555555555149      93824992235849
rbx            0x7fffffffe158      140737488347480
rcx            0x555555557dc0      93824992247232
rdx            0x7fffffffe168      140737488347496
rsi            0x7fffffffe158      140737488347480
rdi            0x1                 1
rbp            0x7fffffffe030      0x7fffffffe030
rsp            0x7fffffffe020      0x7fffffffe020
r8             0x0                 0
r9             0x7ffff7fca380      140737353917312
r10            0x7fffffffdd50      140737488346448
r11            0x203               515
r12            0x1                 1
r13            0x0                 0
r14            0x555555557dc0      93824992247232
r15            0x7ffff7ffd000      140737354125312
rip            0x555555555165      0x555555555165 <main+28>
eflags         0x293               [ CF AF SF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
fs_base        0x7ffff7fb5740      140737353832256
gs_base        0x0                 0
(gdb) s
6           for (int i = 1; i <= 10; i++) {
1: sum = 1
(gdb) s
7               sum += i;
1: sum = 1
(gdb) i r
rax            0x1                 1
rbx            0x7fffffffe158      140737488347480
rcx            0x555555557dc0      93824992247232
rdx            0x7fffffffe168      140737488347496
rsi            0x7fffffffe158      140737488347480
rdi            0x1                 1
rbp            0x7fffffffe030      0x7fffffffe030
rsp            0x7fffffffe020      0x7fffffffe020
r8             0x0                 0
r9             0x7ffff7fca380      140737353917312
r10            0x7fffffffdd50      140737488346448
r11            0x203               515
r12            0x1                 1
r13            0x0                 0
r14            0x555555557dc0      93824992247232
r15            0x7ffff7ffd000      140737354125312
rip            0x555555555165      0x555555555165 <main+28>
eflags         0x293               [ CF AF SF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
fs_base        0x7ffff7fb5740      140737353832256
gs_base        0x0                 0

(gdb) x/5i $rip
=> 0x555555555165 <main+28>:    mov    -0x4(%rbp),%eax
   0x555555555168 <main+31>:    add    %eax,-0x8(%rbp)
   0x55555555516b <main+34>:    addl   $0x1,-0x4(%rbp)
   0x55555555516f <main+38>:    cmpl   $0xa,-0x4(%rbp)
   0x555555555173 <main+42>:    jle    0x555555555165 <main+28>
(gdb) x/4wd $rbp-16
0x7fffffffe020: -7920   32767   45      10
(gdb) x/4gx $rsp
0x7fffffffe020: 0x00007fffffffe110      0x0000000a0000002d
0x7fffffffe030: 0x00007fffffffe0d0      0x00007ffff7c2a1ca
(gdb)

