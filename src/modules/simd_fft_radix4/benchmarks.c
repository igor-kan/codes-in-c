/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for AVX2 Radix-4 Fast Fourier Transform Kernel.
 * Module: simd_fft_radix4
 */

#include <stdint.h>

#define SIMD_FFT_RADIX4_BENCH_SAMPLES 100000

typedef struct simd_fft_radix4_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_fft_radix4_bench_stats_t;
