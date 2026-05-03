#include <stdio.h>

void secret() {
    printf("secret function called!\n");
}

void vuln() {
    char buf[16];
    // gets()는 입력 길이를 검사하지 않아 버퍼 오버플로우 취약점이 발생
    gets(buf); 
}

int main() {
    vuln();
    return 0;
}