/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#include <stdint.h>

#define SIMD_BIT_MATRIX_TRANSPOSE_BENCH_SAMPLES 100000

typedef struct simd_bit_matrix_transpose_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_bit_matrix_transpose_bench_stats_t;
