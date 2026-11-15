#include "interface.h"
#include <string.h>

size_t utf8_dfa_decoder_ascii_fast(const uint8_t* data, size_t len) {
    if (!data) return 0;
    size_t i = 0;
    while (i + 8 <= len) {
        uint64_t w = 0;
        memcpy(&w, data + i, 8);
        if (w & 0x8080808080808080ULL) break;
        i += 8;
    }
    while (i < len && data[i] < 0x80U) i++;
    return i;
}
