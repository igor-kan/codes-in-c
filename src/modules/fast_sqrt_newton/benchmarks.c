/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Fixed-Point Newton-Raphson Square Root Iteration.
 * Module: fast_sqrt_newton
 */

#include <stdint.h>

#define FAST_SQRT_NEWTON_BENCH_ITERATIONS 100000

typedef struct fast_sqrt_newton_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} fast_sqrt_newton_bench_metrics_t;
