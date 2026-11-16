#ifndef KFIFO_POWER2_RING_INTERFACE_H
#define KFIFO_POWER2_RING_INTERFACE_H

#include "types.h"
#include "errors.h"

kfifo_power2_ring_err_t kfifo_init(kfifo_t* q, uint8_t* backing, size_t power2_cap);
size_t kfifo_len(const kfifo_t* q);
size_t kfifo_avail(const kfifo_t* q);
size_t kfifo_in(kfifo_t* q, const uint8_t* src, size_t len);
size_t kfifo_out(kfifo_t* q, uint8_t* dst, size_t len);
kfifo_power2_ring_err_t kfifo_validate(const kfifo_t* q);
size_t kfifo_peek(const kfifo_t* q, uint8_t* dst, size_t len);
kfifo_power2_ring_err_t kfifo_mt_test_batches(size_t trials);
kfifo_power2_ring_err_t kfifo_verify_invariants(const kfifo_t* q);

#endif /* KFIFO_POWER2_RING_INTERFACE_H */
