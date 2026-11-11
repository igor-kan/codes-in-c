/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct circular_work_stealing_deque_sync_counter {
    volatile uint64_t count;
} circular_work_stealing_deque_sync_counter_t;

static inline void circular_work_stealing_deque_sync_inc_v47(circular_work_stealing_deque_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
