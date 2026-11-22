#include "interface.h"
#include <math.h>
#include <string.h>

int utf8_count_codepoints(const uint8_t *buf, size_t len, size_t *out_count) {
    size_t i = 0, cnt = 0;
    while (i < len) {
        uint8_t b0 = buf[i];
        if (b0 <= 0x7Fu) { ++i; ++cnt; continue; }
        size_t need = 0;
        uint32_t cp = 0, min_cp = 0;
        if ((b0 & 0xE0u) == 0xC0u) { need = 1; cp = b0 & 0x1Fu; min_cp = 0x80u; }
        else if ((b0 & 0xF0u) == 0xE0u) { need = 2; cp = b0 & 0x0Fu; min_cp = 0x800u; }
        else if ((b0 & 0xF8u) == 0xF0u) { need = 3; cp = b0 & 0x07u; min_cp = 0x10000u; }
        else return -1;
        if (i + need >= len) return -1;
        for (size_t k = 1; k <= need; ++k) {
            uint8_t bx = buf[i + k];
            if ((bx & 0xC0u) != 0x80u) return -1;
            cp = (cp << 6) | (bx & 0x3Fu);
        }
        if (cp < min_cp || cp > 0x10FFFFu || (cp >= 0xD800u && cp <= 0xDFFFu)) return -1;
        i += need + 1;
        ++cnt;
    }
    *out_count = cnt;
    return 0;
}
