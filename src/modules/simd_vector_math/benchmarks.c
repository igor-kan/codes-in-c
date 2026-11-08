/**
 * Microbenchmark harness and cycle latency profiling for Vectorized Float64 Dot Product and Euclidean Norm.
 * Module: simd_vector_math
 */

#ifndef BENCH_SIMD_VECTOR_MATH_H
#define BENCH_SIMD_VECTOR_MATH_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct simd_vector_math_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} simd_vector_math_bench_metrics_t;

#endif /* BENCH_SIMD_VECTOR_MATH_H */
