#ifndef RING_SPSC_BYTES_C11_D59_INTERFACE_H
#define RING_SPSC_BYTES_C11_D59_INTERFACE_H

#include "types.h"
#include "errors.h"

void br64_init(byte_ring64_t *r);
int br64_write(byte_ring64_t *r, const uint8_t *src, size_t n);
size_t br64_read(byte_ring64_t *r, uint8_t *dst, size_t n);

ring_spsc_bytes_c11_d59_err_t ring_spsc_bytes_c11_d59_validate_len(size_t n);
uint64_t ring_spsc_bytes_c11_d59_fast_fold_u64(const uint64_t* xs, size_t n);
uint64_t ring_spsc_bytes_c11_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb);
ring_spsc_bytes_c11_d59_err_t ring_spsc_bytes_c11_d59_verify_guard(bool cond);

#endif /* RING_SPSC_BYTES_C11_D59_INTERFACE_H */
