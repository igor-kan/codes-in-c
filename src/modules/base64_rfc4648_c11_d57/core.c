#include "interface.h"
#include <math.h>
#include <string.h>

static const uint8_t B64_ALPHA[64] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f',
    'g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
    'w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'
};

static int b64_val(uint8_t c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    return -1;
}

size_t b64_encode(const uint8_t *src, size_t len, uint8_t *dst) {
    size_t i = 0, o = 0;
    while (i < len) {
        size_t rem = len - i;
        uint32_t a = src[i];
        uint32_t b = rem > 1 ? src[i + 1] : 0;
        uint32_t c = rem > 2 ? src[i + 2] : 0;
        uint32_t tri = (a << 16) | (b << 8) | c;
        dst[o++] = B64_ALPHA[(tri >> 18) & 63u];
        dst[o++] = B64_ALPHA[(tri >> 12) & 63u];
        dst[o++] = rem > 1 ? B64_ALPHA[(tri >> 6) & 63u] : (uint8_t)'=';
        dst[o++] = rem > 2 ? B64_ALPHA[tri & 63u] : (uint8_t)'=';
        i += 3;
    }
    return o;
}

int b64_decode(const uint8_t *src, size_t len, uint8_t *dst, size_t *out_len) {
    if ((len & 3u) != 0) return -1;
    size_t o = 0;
    for (size_t i = 0; i < len; i += 4) {
        int v0 = b64_val(src[i]), v1 = b64_val(src[i + 1]);
        if (v0 < 0 || v1 < 0) return -1;
        int pad2 = (src[i + 2] == '=');
        int pad3 = (src[i + 3] == '=');
        int v2 = pad2 ? 0 : b64_val(src[i + 2]);
        int v3 = pad3 ? 0 : b64_val(src[i + 3]);
        if (v2 < 0 || v3 < 0 || (pad2 && !pad3)) return -1;
        uint32_t tri = ((uint32_t)v0 << 18) | ((uint32_t)v1 << 12) | ((uint32_t)v2 << 6) | (uint32_t)v3;
        dst[o++] = (uint8_t)((tri >> 16) & 0xFFu);
        if (!pad2) dst[o++] = (uint8_t)((tri >> 8) & 0xFFu);
        if (!pad3) dst[o++] = (uint8_t)(tri & 0xFFu);
    }
    *out_len = o;
    return 0;
}
