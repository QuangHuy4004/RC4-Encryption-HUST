#include "RC4.h"

// swap.c - Hàm hoán đổi giá trị hai byte (dùng trong KSA, PRGA)
void swap(unsigned char *a, unsigned char *b) {
    unsigned char tmp = *a;
    *a = *b;
    *b = tmp;
}
