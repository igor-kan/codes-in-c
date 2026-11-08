/**
 * Microbenchmark harness and cycle latency profiling for Cooley-Tukey In-Place Radix-2 FFT Engine.
 * Module: fast_fourier_radix2
 */

#ifndef BENCH_FAST_FOURIER_RADIX2_H
#define BENCH_FAST_FOURIER_RADIX2_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct fast_fourier_radix2_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} fast_fourier_radix2_bench_metrics_t;

#endif /* BENCH_FAST_FOURIER_RADIX2_H */
