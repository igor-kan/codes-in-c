/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Lock-Free Treiber Stack Freelist with ABA Version Tagging.
 * Module: lockfree_freelist
 */

#include <stdint.h>

#define LOCKFREE_FREELIST_BENCH_SAMPLES 100000

typedef struct lockfree_freelist_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} lockfree_freelist_bench_stats_t;
