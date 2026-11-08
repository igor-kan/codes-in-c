/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for AVX2 Cacheline-Aligned Matrix Transposition.
 * Module: simd_matrix_transpose
 */

#include <stdint.h>

#define SIMD_MATRIX_TRANSPOSE_BENCH_ITERATIONS 100000

typedef struct simd_matrix_transpose_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} simd_matrix_transpose_bench_result_t;
