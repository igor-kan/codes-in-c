/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct lockfree_ordered_list_sync_counter {
    volatile uint64_t count;
} lockfree_ordered_list_sync_counter_t;

static inline void lockfree_ordered_list_sync_inc_v47(lockfree_ordered_list_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
