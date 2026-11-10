/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct hazard_pointer_domain_sync_counter {
    volatile uint64_t count;
} hazard_pointer_domain_sync_counter_t;

static inline void hazard_pointer_domain_sync_inc(hazard_pointer_domain_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
