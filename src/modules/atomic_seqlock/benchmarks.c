/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Sequential Lock for High-Frequency Concurrent Reads.
 * Module: atomic_seqlock
 */

#include <stdint.h>

#define ATOMIC_SEQLOCK_BENCH_SAMPLES 100000

typedef struct atomic_seqlock_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} atomic_seqlock_bench_stats_t;
