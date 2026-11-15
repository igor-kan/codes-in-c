#include "interface.h"
#include <string.h>

uint64_t xxhash64_streaming_fast_aligned(const uint8_t* data, size_t len, uint64_t seed) {
    if (!data && len > 0) return 0;
    return xxhash64_streaming_oneshot(data, len, seed);
}
