#ifndef RC4_H
#define RC4_H
#include <stddef.h> 

#define N 256

// Hàm khởi tạo mảng S và T từ khóa 
void rc4_init_ST(
    unsigned char S[N],
    unsigned char T[N],
    const unsigned char *key,
    int keylen
);

//  Thuật toán Key Scheduling Algorithm (KSA) 
void rc4_ksa(
    unsigned char S[N],
    const unsigned char T[N]
);

//  Thuật toán Pseudo-Random Generation Algorithm (PRGA) 
void rc4_prga(
    unsigned char S[N],
    unsigned char *keystream,
    int out_len
);

//  Hàm mã hóa RC4 (Encrypt) 
void rc4_encrypt(
    const unsigned char *plaintext,
    int len,
    const unsigned char *key,
    int keylen,
    unsigned char *cipher_out
);

//  Hàm hoán đổi hai byte 
void swap(unsigned char *a, unsigned char *b);

#endif 
