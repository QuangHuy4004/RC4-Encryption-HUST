#include "RC4.h"
void rc4_init_ST(
    unsigned char S[N],
    unsigned char T[N],
    const unsigned char *key,
    int keylen
) {
    for (int i = 0; i < N; ++i) {
        S[i] = (unsigned char)i;        // Khởi tạo S theo thứ tự 0..255
    }
    for (int i = 0; i < N; ++i) {
        T[i] = key[i % keylen];         // lặp lại khoá K để tạo T 
    }
}
