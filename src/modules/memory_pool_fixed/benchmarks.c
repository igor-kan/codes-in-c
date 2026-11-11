/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

#include <stdint.h>

#define MEMORY_POOL_FIXED_BENCH_SAMPLES 100000

typedef struct memory_pool_fixed_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} memory_pool_fixed_bench_stats_t;
