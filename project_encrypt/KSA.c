#include "RC4.h"
void rc4_ksa(
    unsigned char S[N],
    const unsigned char T[N]
) {
    unsigned int j = 0;
    for (unsigned int i = 0; i < N; ++i) {
        j = (j + S[i] + T[i]) % N;          // Tính chỉ số j và hoán vị
        swap(&S[i], &S[j]);
    }
}