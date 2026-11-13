/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter
 */

#include <stdint.h>

#define BITWISE_BLOOM_FILTER_BENCH_ITERATIONS 100000

typedef struct bitwise_bloom_filter_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} bitwise_bloom_filter_bench_metrics_t;
