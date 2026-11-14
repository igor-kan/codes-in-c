/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c
 */

#include <stdint.h>

#define SIPHASH_ROUND_C_BENCH_ITERATIONS 100000

typedef struct siphash_round_c_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} siphash_round_c_bench_metrics_t;
