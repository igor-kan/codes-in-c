#ifndef UTF8_DFA_VALID_C11_D57_INTERFACE_H
#define UTF8_DFA_VALID_C11_D57_INTERFACE_H

#include "types.h"
#include "errors.h"

int utf8_count_codepoints(const uint8_t *buf, size_t len, size_t *out_count);

utf8_dfa_valid_c11_d57_err_t utf8_dfa_valid_c11_d57_validate_len(size_t n);
uint64_t utf8_dfa_valid_c11_d57_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t utf8_dfa_valid_c11_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
utf8_dfa_valid_c11_d57_err_t utf8_dfa_valid_c11_d57_verify_guard(bool cond);

#endif /* UTF8_DFA_VALID_C11_D57_INTERFACE_H */
