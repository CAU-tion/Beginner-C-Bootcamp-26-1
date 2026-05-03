snirn@LAPTOP-V9INSQP0:~$ ./secret
efjiefjojisajfieofjosfojeiojfoi
Segmentation fault (core dumped)

snirn@LAPTOP-V9INSQP0:~$ ./secret
fjeifojeioaf


(gdb) p &buf
$1 = (char (*)[16]) 0x7fffffffdf40
 rip = 0x55555555518f in vuln (secret.c:7); saved rip = 0x5555555551b5
 Saved registers:
  rbp at 0x7fffffffdf50, rip at 0x7fffffffdf58

(gdb) n
jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
8       }
 rip = 0x5555555551a0 in vuln (secret.c:8); saved rip = 0x6a6a6a6a6a6a6a6a
 Saved registers:
  rbp at 0x7fffffffdf50, rip at 0x7fffffffdf58


strcpy(dst, src)    src 길이 확인 없이 복사

strcat(dst, src)    dst 남은 공간 확인 없이 이어붙임

scanf("%s", buf)    공백 전까지 길이 제한 없이 읽음
