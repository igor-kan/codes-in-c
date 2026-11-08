/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for High-Order Barycentric Rational Interpolator.
 * Module: barycentric_interpolation
 */

#include <stdint.h>

#define BARYCENTRIC_INTERPOLATION_BENCH_ITERATIONS 100000

typedef struct barycentric_interpolation_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} barycentric_interpolation_bench_result_t;
