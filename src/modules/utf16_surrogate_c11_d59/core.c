#include "interface.h"
#include <math.h>
#include <string.h>

int cp_to_utf16(uint32_t cp, uint16_t out[2], size_t *n_units) {
    if (cp > 0x10FFFFu || (cp >= 0xD800u && cp <= 0xDFFFu)) return -1;
    if (cp <= 0xFFFFu) { out[0] = (uint16_t)cp; *n_units = 1; return 0; }
    uint32_t u = cp - 0x10000u;
    out[0] = (uint16_t)(0xD800u + (u >> 10));
    out[1] = (uint16_t)(0xDC00u + (u & 0x3FFu));
    *n_units = 2;
    return 0;
}

int utf16_to_cp(const uint16_t *in, size_t n_units, uint32_t *cp) {
    if (n_units == 0) return -1;
    uint16_t w1 = in[0];
    if (w1 < 0xD800u || w1 > 0xDFFFu) { *cp = w1; return 0; }
    if (w1 >= 0xDC00u || n_units < 2) return -1;
    uint16_t w2 = in[1];
    if (w2 < 0xDC00u || w2 > 0xDFFFu) return -1;
    *cp = 0x10000u + ((((uint32_t)w1 - 0xD800u) << 10) | ((uint32_t)w2 - 0xDC00u));
    return 0;
}
