1.for_sum.c
#include <stdio.h>

int main() {
    int sum = 0;
    // 초기식; 조건식; 증감식 한 곳에 모여 있음
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    printf("For Sum: %d\n", sum);
    return 0;
}

2.while_sum.c
#include <stdio.h>

int main() {
    int sum = 0;
    int i = 1; // 초기식
    while (i <= 10) { // 조건식
        sum += i;
        i++; // 증감식
    }
    printf("While Sum: %d\n", sum);
    return 0;
}

3.dowhile_sum.c
#include <stdio.h>

int main() {
    int sum = 0;
    int i = 1;
    do {
        sum += i;
        i++;
    } while (i <= 10); // 세미콜론(;) 주의!
    printf("Do-While Sum: %d\n", sum);
    return 0;
}

snirn@LAPTOP-V9INSQP0:~$ gcc -g -O0 -o for_sum for_sum.c
snirn@LAPTOP-V9INSQP0:~$ gcc -g -O0 -o while_sum while_sum.c
snirn@LAPTOP-V9INSQP0:~$ gcc -g -O0 -o dowhile_sum dowhile_sum.c
snirn@LAPTOP-V9INSQP0:~$ ./for_sum
For Sum: 55
snirn@LAPTOP-V9INSQP0:~$ ./while_sum
While Sum: 55
snirn@LAPTOP-V9INSQP0:~$ ./dowhile_sum
Do-While Sum: 55

for 반복 횟수가 정해져 있을 때
while 반복 횟수가 불명확하고 조건에 따라 끝날 때
do-while 최소 한 번의 실행이 보장되어야 할 때
