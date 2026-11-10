/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

#include <stdint.h>

#define SIMD_SPMV_ELLPACK_BENCH_SAMPLES 100000

typedef struct simd_spmv_ellpack_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} simd_spmv_ellpack_bench_stats_t;
