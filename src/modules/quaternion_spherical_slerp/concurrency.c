/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_spherical_slerp
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct quaternion_spherical_slerp_sync_counter {
    volatile uint64_t count;
} quaternion_spherical_slerp_sync_counter_t;

static inline void quaternion_spherical_slerp_sync_inc_v47(quaternion_spherical_slerp_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
