/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Hardware-Accelerated CRC32-C Checksum Engine.
 * Module: crc32c_hardware
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct crc32c_hardware_sync_counter {
    volatile uint64_t count;
} crc32c_hardware_sync_counter_t;

static inline void crc32c_hardware_sync_inc(crc32c_hardware_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
