#ifndef CRC32C_CASTAGNOLI_D60_INTERFACE_H
#define CRC32C_CASTAGNOLI_D60_INTERFACE_H

#include "types.h"
#include "errors.h"

uint32_t crc32c_update_d60(uint32_t init, const uint8_t* data, size_t len);
uint32_t crc32c_finalize_d60(uint32_t state);

crc32c_castagnoli_d60_err_t crc32c_castagnoli_d60_validate_len(size_t n);
uint64_t crc32c_castagnoli_d60_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t crc32c_castagnoli_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
crc32c_castagnoli_d60_err_t crc32c_castagnoli_d60_verify_guard(bool cond);

#endif /* CRC32C_CASTAGNOLI_D60_INTERFACE_H */
