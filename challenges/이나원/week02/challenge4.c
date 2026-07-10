#include <stdio.h>

int main() {
    int secret_num = 65;             
    char *secret_str = "Hello"; 

    printf("[1. 정상적인 포맷 출력]\n");
    printf("Decimal (%%d): %d\n", secret_num);
    printf("Hex     (%%x): %x\n", secret_num);
    printf("Char    (%%c): %c\n", secret_num);
    printf("Address (%%p): %p\n", &secret_num);

    printf("\n[2. 잘못된 포맷 사용 실험]\n");
    printf("Integer as String (%%s): ");
    fflush(stdout); 
    
    printf("%s\n", secret_num); 

    return 0;
}