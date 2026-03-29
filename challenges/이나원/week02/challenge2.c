#include <stdio.h>
#include <string.h>

void print_centered(int num, int width) {
    char buf[32];
    int len = sprintf(buf, "%d", num); 
    int padding = (width - len) / 2;  
    
    if (padding < 0) padding = 0; 

    printf("%*s%s%*s", padding, "", buf, width - len - padding, "");
}

void Decimal_to_Binary(int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" "); 
    }
}

int main() {
    int a, b;
    printf("Put two integers: ");
    if (scanf("%d %d", &a, &b) != 2) return 1; 

    printf("\n %-18s | %-12s | %s\n", "Operation", "  Decimal", "Binary (32-bit)");
    printf("--------------------------------------------------------------------------\n");

    #define PRINT_RES(name, res) \
        printf(" %-18s | ", name); \
        print_centered(res, 12); \
        printf(" | "); \
        Decimal_to_Binary(res); \
        printf("\n")

    PRINT_RES("AND (&)", a & b);
    PRINT_RES("OR  (|)", a | b);
    PRINT_RES("XOR (^)", a ^ b);
    PRINT_RES("NOT (~a)", ~a);
    PRINT_RES("Left Shift (<<1)", a << 1);
    PRINT_RES("Right Shift (>>1)", a >> 1);

    return 0;
}