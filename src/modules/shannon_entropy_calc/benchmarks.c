/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

#include <stdint.h>

#define SHANNON_ENTROPY_CALC_BENCH_ITERATIONS 100000

typedef struct shannon_entropy_calc_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} shannon_entropy_calc_bench_metrics_t;
