#include "interface.h"

xxhash64_streaming_err_t xxhash64_streaming_validate(const xxhash64_state_t* st, const void* data, size_t len) {
    if (!st) return XXHASH64_STREAMING_ERR_NULL;
    if (len > 0 && !data) return XXHASH64_STREAMING_ERR_NULL;
    if (st->memsize >= XXH64_STRIPE_SIZE) return XXHASH64_STREAMING_ERR_BOUNDS;
    return XXHASH64_STREAMING_OK;
}
