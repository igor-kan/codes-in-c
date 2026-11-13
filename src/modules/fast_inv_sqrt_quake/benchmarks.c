/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake
 */

#include <stdint.h>

#define FAST_INV_SQRT_QUAKE_BENCH_ITERATIONS 100000

typedef struct fast_inv_sqrt_quake_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} fast_inv_sqrt_quake_bench_metrics_t;
