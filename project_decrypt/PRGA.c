#include "RC4.h"
void rc4_prga(
  unsigned char S[N], 
  unsigned char *keystream, 
  int out_len) 
  {
    unsigned int i = 0, j = 0;
    for (int n = 0; n < out_len; ++n) {
        i = (i + 1) % N;
        j = (j + S[i]) % N;
        swap(&S[i], &S[j]);
        unsigned int t = (S[i] + S[j]) % N;
        keystream[n] = S[t];
    }
}
