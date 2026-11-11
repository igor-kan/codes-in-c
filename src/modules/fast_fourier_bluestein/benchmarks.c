/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Bluestein Chirp-Z Algorithm for Arbitrary-Size FFT.
 * Module: fast_fourier_bluestein
 */

#include <stdint.h>

#define FAST_FOURIER_BLUESTEIN_BENCH_SAMPLES 100000

typedef struct fast_fourier_bluestein_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} fast_fourier_bluestein_bench_stats_t;
