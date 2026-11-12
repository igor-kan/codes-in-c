/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Knuth-Morris-Pratt (KMP) Longest Prefix Search.
 * Module: knuth_morris_pratt
 */

#include <stdint.h>

#define KNUTH_MORRIS_PRATT_BENCH_CYCLES 100000

typedef struct knuth_morris_pratt_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} knuth_morris_pratt_profile_results_t;
