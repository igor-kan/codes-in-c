#ifndef XXHASH64_STREAMING_INTERFACE_H
#define XXHASH64_STREAMING_INTERFACE_H

#include "types.h"
#include "errors.h"

void xxhash64_streaming_reset(xxhash64_state_t* st, uint64_t seed);
xxhash64_streaming_err_t xxhash64_streaming_update(xxhash64_state_t* st, const void* data, size_t len);
uint64_t xxhash64_streaming_digest(const xxhash64_state_t* st);
uint64_t xxhash64_streaming_oneshot(const void* data, size_t len, uint64_t seed);
xxhash64_streaming_err_t xxhash64_streaming_validate(const xxhash64_state_t* st, const void* data, size_t len);
uint64_t xxhash64_streaming_fast_aligned(const uint8_t* data, size_t len, uint64_t seed);
xxhash64_streaming_err_t xxhash64_streaming_batch_mt(const uint8_t** bufs, const size_t* lens, uint64_t* out_hashes, size_t n_items, uint64_t seed, size_t num_threads);
xxhash64_streaming_err_t xxhash64_streaming_check_invariants(const uint8_t* data, size_t len, uint64_t seed);

#endif /* XXHASH64_STREAMING_INTERFACE_H */
