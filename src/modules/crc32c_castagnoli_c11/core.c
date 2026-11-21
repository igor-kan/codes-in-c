#include "interface.h"
#include <math.h>
#include <string.h>

uint32_t crc32c_compute(const uint8_t *buf, size_t len) {
    uint32_t crc = 0xFFFFFFFFu;
    for (size_t i = 0; i < len; ++i) {
        crc ^= (uint32_t)buf[i];
        for (int b = 0; b < 8; ++b) {
            uint32_t mask = (uint32_t)-(int32_t)(crc & 1u);
            crc = (crc >> 1) ^ (0x82F63B78u & mask);
        }
    }
    return crc ^ 0xFFFFFFFFu;
}
