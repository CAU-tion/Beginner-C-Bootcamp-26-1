#include <stdio.h>

void print_banner();
void encode(char *str, int shift);
int get_shift();

int main() {

    int n = 0;
    char str[100];

    print_banner();
    printf("enter string: ");
    scanf("%s", str);

    n = get_shift();

    encode(str, n);

    printf("result: %s\n", str);

    return 0;
}

void print_banner() {
    printf("caesar cipher\n");
}

void encode(char *str, int n) {

    for (int i = 0 ; str[i] != '\0'; i++) {

        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 'a' + n) % 26 + 'a';

        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i] - 'A' + n) % 26 + 'A';
    }
}

int get_shift() {
    int a = 0;
    printf("enter shift: ");
    scanf("%d", &a);

    return a;
}