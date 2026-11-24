#ifndef UTF16_SURROGATE_C11_D59_INTERFACE_H
#define UTF16_SURROGATE_C11_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

int cp_to_utf16(uint32_t cp, uint16_t out[2], size_t *n_units);
int utf16_to_cp(const uint16_t *in, size_t n_units, uint32_t *cp);

utf16_surrogate_c11_d59_err_t utf16_surrogate_c11_d59_validate_len(size_t n);
uint64_t utf16_surrogate_c11_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t utf16_surrogate_c11_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
utf16_surrogate_c11_d59_err_t utf16_surrogate_c11_d59_verify_guard(bool cond);

#endif /* UTF16_SURROGATE_C11_D59_INTERFACE_H */
