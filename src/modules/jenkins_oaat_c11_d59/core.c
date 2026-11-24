#include "interface.h"
#include <math.h>
#include <string.h>

uint32_t jenkins_oaat32(const uint8_t *key, size_t len) {
    uint32_t h = 0;
    for (size_t i = 0; i < len; ++i) {
        h += key[i];
        h += h << 10;
        h ^= h >> 6;
    }
    h += h << 3;
    h ^= h >> 11;
    h += h << 15;
    return h;
}
