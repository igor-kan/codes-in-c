#include "interface.h"
#include <math.h>
#include <string.h>

uint32_t crc32c_update_d60(uint32_t init, const uint8_t* data, size_t len) {
    uint32_t crc = ~init;
    for (size_t i = 0; i < len; ++i) {
        crc ^= data[i];
        for (int b = 0; b < 8; ++b) {
            uint32_t mask = -(crc & 1U);
            crc = (crc >> 1) ^ (0x82f63b78U & mask);
        }
    }
    return ~crc;
}
uint32_t crc32c_finalize_d60(uint32_t state) {
    return state;
}
