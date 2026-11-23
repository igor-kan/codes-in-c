#ifndef CRC32_IEEE8023_C11_D58_INTERFACE_H
#define CRC32_IEEE8023_C11_D58_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t crc32_ieee_compute(const uint8_t *buf, size_t len);

crc32_ieee8023_c11_d58_err_t crc32_ieee8023_c11_d58_validate_len(size_t n);
uint64_t crc32_ieee8023_c11_d58_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t crc32_ieee8023_c11_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
crc32_ieee8023_c11_d58_err_t crc32_ieee8023_c11_d58_verify_guard(bool cond);

#endif /* CRC32_IEEE8023_C11_D58_INTERFACE_H */
