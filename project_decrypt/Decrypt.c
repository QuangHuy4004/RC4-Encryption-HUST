#include "RC4.h"
#include <stdlib.h>

void rc4_decrypt(
    const unsigned char *ciphertext,
    int len,
    const unsigned char *key,
    int keylen,
    unsigned char *plain_out
) {
    unsigned char S[N];
    unsigned char T[N];

    rc4_init_ST(S, T, key, keylen);
    rc4_ksa(S, T);

    unsigned char *ks = (unsigned char*)malloc(len);
    if (!ks) return;

    rc4_prga(S, ks, len);
    for (int i = 0; i < len; ++i) {
        plain_out[i] = ciphertext[i] ^ ks[i];
    }

    free(ks);
}
