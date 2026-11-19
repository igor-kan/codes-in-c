#ifndef Z_ALGORITHM_LCP_C11_INTERFACE_H
#define Z_ALGORITHM_LCP_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

void build_z_array(const char* s, size_t n, size_t* z);
size_t z_find_occurrences(const char* pat, const char* text, size_t* out, size_t max_out);

z_algorithm_lcp_c11_err_t z_algorithm_lcp_c11_validate_len(size_t n);
uint64_t z_algorithm_lcp_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t z_algorithm_lcp_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
z_algorithm_lcp_c11_err_t z_algorithm_lcp_c11_verify_guard(bool cond);

#endif /* Z_ALGORITHM_LCP_C11_INTERFACE_H */
