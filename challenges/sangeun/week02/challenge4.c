#include <stdio.h>

int main(void) {
    int num = 65;
    char ch = 'A';
    char *str = "Hello";

    printf("=== 다양한 포맷 출력 ===\n");

    printf("num (%%d) : %d\n", num);
    printf("num (%%x) : %x\n", num);
    printf("num (%%o) : %o\n", num);
    printf("num (%%c) : %c\n", num);

    printf("\nch (%%c) : %c\n", ch);
    printf("ch (%%d) : %d\n", ch);

    printf("\nstr (%%s) : %s\n", str);
    printf("str (%%p) : %p\n", (void*)str);

    printf("\n=== 잘못된 포맷 예시 ===\n");
    printf("int를 %%s로 출력하면 이상한 값 or 오류 발생 가능\n");

    
    // printf("%s\n", num);

    return 0;
}
