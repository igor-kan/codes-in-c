#ifndef BASE58_BTC_D61_INTERFACE_H
#define BASE58_BTC_D61_INTERFACE_H

#include "types.h"
#include "errors.h"

size_t base58_encode(const uint8_t* data, size_t n, base58_string_t* out);
size_t base58_decode(const char* text, size_t n, uint8_t* out, size_t cap);

base58_btc_d61_err_t base58_btc_d61_validate_len(size_t n);
uint64_t base58_btc_d61_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t base58_btc_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
base58_btc_d61_err_t base58_btc_d61_verify_guard(bool cond);

#endif /* BASE58_BTC_D61_INTERFACE_H */
