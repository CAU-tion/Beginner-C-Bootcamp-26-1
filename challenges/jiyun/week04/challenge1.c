#include <stdio.h>

void print_banner();
int get_shift();
void encode(char *str, int shift);
void decode(char *str, int shift);

int main() {
    char str[100];
    int shift;
    int choice;

    print_banner();

    printf("문자열 입력: ");
    scanf("%s", str);

    shift = get_shift();

    printf("1. encode\n2. decode\n선택: ");
    scanf("%d", &choice);

    if(choice == 1) {
        encode(str, shift);
        printf("암호화 결과: %s\n", str);
    } else if(choice == 2) {
        decode(str, shift);
        printf("복호화 결과: %s\n", str);
    } else {
        printf("잘못된 선택입니다.\n");
    }

    return 0;
}

void print_banner() {
    printf("=== Caesar Cipher Program ===\n");
}

int get_shift() {
    int shift;
    printf("shift 값 입력: ");
    scanf("%d", &shift);
    return shift;
}

// 🔐 인코더
void encode(char *str, int shift) {
    for(int i = 0; str[i] != '\0'; i++) {

        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' + shift) % 26) + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' + shift) % 26) + 'A';
        }
    }
}

// 🔓 디코더
void decode(char *str, int shift) {
    for(int i = 0; str[i] != '\0'; i++) {

        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' - shift + 26) % 26) + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' - shift + 26) % 26) + 'A';
        }
    }
}