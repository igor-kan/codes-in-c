/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Kernel-Style Slab Cache Memory Pool Allocator.
 * Module: slab_cache_allocator
 */

#include <stdint.h>

#define SLAB_CACHE_ALLOCATOR_BENCH_ITERATIONS 100000

typedef struct slab_cache_allocator_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} slab_cache_allocator_bench_result_t;
