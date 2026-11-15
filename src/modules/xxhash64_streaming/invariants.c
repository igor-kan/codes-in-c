#include "interface.h"

xxhash64_streaming_err_t xxhash64_streaming_check_invariants(const uint8_t* data, size_t len, uint64_t seed) {
    if (len > 0 && !data) return XXHASH64_STREAMING_ERR_NULL;
    uint64_t one = xxhash64_streaming_oneshot(data, len, seed);
    xxhash64_state_t st;
    xxhash64_streaming_reset(&st, seed);
    size_t off = 0;
    while (off < len) {
        size_t step = (off % 2 == 0) ? 7 : 19;
        if (off + step > len) step = len - off;
        xxhash64_streaming_update(&st, data + off, step);
        off += step;
    }
    uint64_t stream_h = xxhash64_streaming_digest(&st);
    return (one == stream_h) ? XXHASH64_STREAMING_OK : XXHASH64_STREAMING_ERR_INVARIANT;
}
