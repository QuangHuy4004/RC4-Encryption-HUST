#include <stdio.h>
#include <string.h>
#include "RC4.h"

int binary_string_to_bytes(const char *bin_str, unsigned char *out) {
    int count = 0, bits = 0;
    unsigned char val = 0;

    for (; *bin_str; ++bin_str) {
        if (*bin_str == ' ' || *bin_str == '\t' || *bin_str == '\n' || *bin_str == '\r')
            continue;  

        if (*bin_str != '0' && *bin_str != '1')
            continue;

        val = (val << 1) | (*bin_str == '1');
        bits++;

        if (bits == 8) {
            out[count++] = val;
            bits = 0;
            val = 0;
        }
    }
    return count;
}
