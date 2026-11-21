#ifndef CRC32C_CASTAGNOLI_C11_INTERFACE_H
#define CRC32C_CASTAGNOLI_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t crc32c_compute(const uint8_t *buf, size_t len);

crc32c_castagnoli_c11_err_t crc32c_castagnoli_c11_validate_len(size_t n);
uint64_t crc32c_castagnoli_c11_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t crc32c_castagnoli_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
crc32c_castagnoli_c11_err_t crc32c_castagnoli_c11_verify_guard(bool cond);

#endif /* CRC32C_CASTAGNOLI_C11_INTERFACE_H */
