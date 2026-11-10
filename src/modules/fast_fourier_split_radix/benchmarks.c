/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

#include <stdint.h>

#define FAST_FOURIER_SPLIT_RADIX_BENCH_SAMPLES 100000

typedef struct fast_fourier_split_radix_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} fast_fourier_split_radix_bench_stats_t;
