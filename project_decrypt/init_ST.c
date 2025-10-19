#include "RC4.h"
void rc4_init_ST(
  unsigned char S[N], 
  unsigned char T[N], 
  const unsigned char *key, 
  int keylen) 
  {
    for (int i = 0; i < N; ++i) {
        S[i] = (unsigned char)i;
        T[i] = key[i % keylen];
    }
}
