/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Bit-Parallel Myers Levenshtein Edit Distance.
 * Module: simd_levenshtein
 */

#include <stdint.h>

#define SIMD_LEVENSHTEIN_BENCH_SAMPLES 100000

typedef struct simd_levenshtein_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_levenshtein_bench_stats_t;
