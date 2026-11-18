#ifndef RABIN_FINGERPRINT_GEAR_C_INTERFACE_H
#define RABIN_FINGERPRINT_GEAR_C_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t gear_cdc_split(const uint8_t* buf, size_t n, size_t min_len, size_t max_len, uint64_t mask, cdc_chunk_t* out, size_t max_chunks);

rabin_fingerprint_gear_c_err_t rabin_fingerprint_gear_c_validate_len(size_t n);
uint64_t rabin_fingerprint_gear_c_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t rabin_fingerprint_gear_c_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
rabin_fingerprint_gear_c_err_t rabin_fingerprint_gear_c_verify_guard(bool cond);

#endif /* RABIN_FINGERPRINT_GEAR_C_INTERFACE_H */
