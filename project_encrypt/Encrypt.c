// Encrypt.c - Thực hiện toàn bộ quá trình mã hóa RC4

#include "RC4.h"
#include <stdlib.h>

static void rc4_process(
    const unsigned char *in,
    int len,
    const unsigned char *key,
    int keylen,
    unsigned char *out
) 
{
    unsigned char S[N];
    unsigned char T[N];

    rc4_init_ST(S, T, key, keylen);
    rc4_ksa(S, T);
    unsigned char *ks = (unsigned char*)malloc(len);
    if (!ks) return; 
    rc4_prga(S, ks, len);
    for (int i = 0; i < len; ++i) {
        out[i] = in[i] ^ ks[i];
    }
    free(ks);
}

void rc4_encrypt(
    const unsigned char *plaintext,
    int len,
    const unsigned char *key,
    int keylen,
    unsigned char *cipher_out
) 
{
    rc4_process(plaintext, len, key, keylen, cipher_out);
}
