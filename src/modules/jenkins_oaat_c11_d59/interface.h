#ifndef JENKINS_OAAT_C11_D59_INTERFACE_H
#define JENKINS_OAAT_C11_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t jenkins_oaat32(const uint8_t *key, size_t len);

jenkins_oaat_c11_d59_err_t jenkins_oaat_c11_d59_validate_len(size_t n);
uint64_t jenkins_oaat_c11_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t jenkins_oaat_c11_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
jenkins_oaat_c11_d59_err_t jenkins_oaat_c11_d59_verify_guard(bool cond);

#endif /* JENKINS_OAAT_C11_D59_INTERFACE_H */
