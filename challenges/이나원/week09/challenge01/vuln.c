#include <stdio.h>

void secret() {
    printf("secret function called!\n");
    fflush(stdout);
}

void vuln() {
    char buf[16];
    gets(buf);
}

int main() {
    vuln();
    return 0;
}