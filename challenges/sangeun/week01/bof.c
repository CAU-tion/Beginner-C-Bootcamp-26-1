#include <stdio.h>

void secret() {
    printf("보안 돌파 성공! secret function called!\n");
}

void vuln() {
    char buf[16];
    printf("문자열을 입력하세요: ");
    gets(buf); // 여기서 오버플로우 발생!
}

int main() {
    vuln();
    return 0;
}
