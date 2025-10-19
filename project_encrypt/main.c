// main.c - Chương trình chính: nhập dữ liệu, mã hóa, in kết quả

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RC4.h"

static void print_binary(const unsigned char *buf, int len) {
    for (int i = 0; i < len; ++i) {
        for (int bit = 7; bit >= 0; --bit) {
            putchar((buf[i] & (1 << bit)) ? '1' : '0');
        }
        putchar(' '); 
    }
}

void print_hex(const unsigned char *data, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}


int main(void) {
    unsigned char plaintext[256];
    unsigned char key[256];

    printf("Plaintext: ");
    fgets((char*)plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn((char*)plaintext, "\n")] = 0;

    printf("Key: ");
    fgets((char*)key, sizeof(key), stdin);
    key[strcspn((char*)key, "\n")] = 0;

    int plen = strlen((char*)plaintext);
    int klen = strlen((char*)key);

    unsigned char *cipher = malloc(plen);

    rc4_encrypt(plaintext, plen, key, klen, cipher);

    printf("Cipher (binary): ");
    print_binary(cipher, plen);

    printf("\nCipher (hex): ");
    print_hex(cipher, plen);

    free(cipher);
    return 0;
}
