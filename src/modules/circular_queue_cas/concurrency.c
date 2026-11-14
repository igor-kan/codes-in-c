/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Atomic CAS-Based Lock-Free Circular Queue Buffer.
 * Module: circular_queue_cas
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct circular_queue_cas_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} circular_queue_cas_sync_state_t;

static inline void circular_queue_cas_sync_increment(circular_queue_cas_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
