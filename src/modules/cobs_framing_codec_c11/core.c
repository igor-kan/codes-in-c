#include "interface.h"
#include <math.h>
#include <string.h>

size_t cobs_encode(const uint8_t *src, size_t len, uint8_t *dst) {
    size_t read_idx = 0;
    size_t write_idx = 1;
    size_t code_idx = 0;
    uint8_t code = 1;
    while (read_idx < len) {
        if (src[read_idx] == 0) {
            dst[code_idx] = code;
            code = 1;
            code_idx = write_idx++;
            read_idx++;
        } else {
            dst[write_idx++] = src[read_idx++];
            code++;
            if (code == 0xFF) {
                dst[code_idx] = code;
                code = 1;
                code_idx = write_idx++;
            }
        }
    }
    dst[code_idx] = code;
    return write_idx;
}

int cobs_decode(const uint8_t *src, size_t len, uint8_t *dst, size_t *out_len) {
    if (len == 0) { *out_len = 0; return -1; }
    size_t read_idx = 0;
    size_t write_idx = 0;
    while (read_idx < len) {
        uint8_t code = src[read_idx];
        if (code == 0 || read_idx + code > len) return -1;
        read_idx++;
        for (uint8_t i = 1; i < code; ++i) {
            uint8_t b = src[read_idx++];
            if (b == 0) return -1;
            dst[write_idx++] = b;
        }
        if (code < 0xFF && read_idx < len) {
            dst[write_idx++] = 0;
        }
    }
    *out_len = write_idx;
    return 0;
}
