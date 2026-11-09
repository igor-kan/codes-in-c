/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for In-Place Dense LU Factorization with Pivoting.
 * Module: dense_lu_factor
 */

#include <stdint.h>

#define DENSE_LU_FACTOR_BENCH_SAMPLES 100000

typedef struct dense_lu_factor_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} dense_lu_factor_bench_stats_t;
