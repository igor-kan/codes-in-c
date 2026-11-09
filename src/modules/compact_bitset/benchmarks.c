/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for 64-Bit Word Compact Bitset with Popcount.
 * Module: compact_bitset
 */

#include <stdint.h>

#define COMPACT_BITSET_BENCH_SAMPLES 100000

typedef struct compact_bitset_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} compact_bitset_bench_stats_t;
