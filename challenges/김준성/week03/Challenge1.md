snirn@LAPTOP-V9INSQP0:~$ ./vuln "%x %x %x %x"
915be5b8 915be5d0 b47afdc

snirn@LAPTOP-V9INSQP0:~$ ./vuln "%p %d %s"
0x7ffdc9621fb8 -916316208

snirn@LAPTOP-V9INSQP0:~$ ./vuln "%x %x %x %x"
%x %x %x %xsnirn@LAPTOP-V9INSQP0:~$

printf 함수의 첫 번째 인자는 포맷 스트링(형식 지정자) 자리입니다. 여기에 사용자의 입력을 직접 넣으면, 사용자가 %p, %x, %n 같은 특수 문자를 섞어 넣었을 때 printf가 이를 시스템 명령으로 오해하여 메모리 값을 읽거나 변조하게 됩니다. 이를 방지하
려면 항상 %s 같은 형식 지정자를 명시하여 사용자의 입력을 '데이터' 영역에 가둬야 합니다.
