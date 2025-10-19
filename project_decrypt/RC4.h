#ifndef RC4_H
#define RC4_H
#include <stddef.h>

#define N 256

void rc4_init_ST(
    unsigned char S[N],
    unsigned char T[N],
    const unsigned char *key,
    int keylen
);  

void rc4_ksa(
    unsigned char S[N],
    const unsigned char T[N]
);

void rc4_prga(
    unsigned char S[N],
    unsigned char *keystream,
    int out_len
);

void rc4_decrypt(
    const unsigned char *ciphertext,
    int len,
    const unsigned char *key,
    int keylen,
    unsigned char *plain_out
);

void swap(unsigned char *a, unsigned char *b);

int binary_string_to_bytes(
    const char *bin_str, 
    unsigned char *out
);

#endif
