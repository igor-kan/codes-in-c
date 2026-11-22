#ifndef XXHASH32_AVALANCHE_D57_INTERFACE_H
#define XXHASH32_AVALANCHE_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t xxhash32_compute(const uint8_t *buf, size_t len, uint32_t seed);

xxhash32_avalanche_d57_err_t xxhash32_avalanche_d57_validate_len(size_t n);
uint64_t xxhash32_avalanche_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t xxhash32_avalanche_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
xxhash32_avalanche_d57_err_t xxhash32_avalanche_d57_verify_guard(bool cond);

#endif /* XXHASH32_AVALANCHE_D57_INTERFACE_H */
