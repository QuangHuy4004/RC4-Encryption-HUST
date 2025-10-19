#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RC4.h"

int main(void) {
    char bin_input[4096];
    unsigned char key[256];

    printf("Cipher: ");
    fgets(bin_input, sizeof(bin_input), stdin);
    bin_input[strcspn(bin_input, "\n")] = 0;

    printf("Key: ");
    fgets((char*)key, sizeof(key), stdin);
    key[strcspn((char*)key, "\n")] = 0;

    unsigned char ciphertext[2048];
    int cipher_len = binary_string_to_bytes(bin_input, ciphertext);
    if (cipher_len <= 0) {
        fprintf(stderr, "Error reading binary cipher!\n");
        return 1;
    }

    int keylen = strlen((char*)key);
    unsigned char *decrypted = malloc(cipher_len);
    if (!decrypted) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    rc4_decrypt(ciphertext, cipher_len, key, keylen, decrypted);

    printf("Decrypted text: %.*s\n", cipher_len, decrypted);

    free(decrypted);
    return 0;
}
