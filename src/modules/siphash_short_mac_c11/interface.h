#ifndef SIPHASH_SHORT_MAC_C11_INTERFACE_H
#define SIPHASH_SHORT_MAC_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

uint64_t siphash24(uint64_t k0, uint64_t k1, const uint8_t *msg, size_t len);

siphash_short_mac_c11_err_t siphash_short_mac_c11_validate_len(size_t n);
uint64_t siphash_short_mac_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t siphash_short_mac_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
siphash_short_mac_c11_err_t siphash_short_mac_c11_verify_guard(bool cond);

#endif /* SIPHASH_SHORT_MAC_C11_INTERFACE_H */
