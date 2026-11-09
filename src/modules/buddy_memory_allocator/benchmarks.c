/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Power-of-Two Buddy Memory Pool Allocator.
 * Module: buddy_memory_allocator
 */

#include <stdint.h>

#define BUDDY_MEMORY_ALLOCATOR_BENCH_SAMPLES 100000

typedef struct buddy_memory_allocator_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} buddy_memory_allocator_bench_stats_t;
