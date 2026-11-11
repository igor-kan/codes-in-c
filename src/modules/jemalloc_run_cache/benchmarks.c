/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Thread-Cached Run Allocator with Slab Bitmap Binning.
 * Module: jemalloc_run_cache
 */

#include <stdint.h>

#define JEMALLOC_RUN_CACHE_BENCH_SAMPLES 100000

typedef struct jemalloc_run_cache_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} jemalloc_run_cache_bench_stats_t;
