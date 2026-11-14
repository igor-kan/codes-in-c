/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for In-Place LU Decomposition Matrix Inversion with Solve.
 * Module: matrix_inversion_lu
 */

#include <stdint.h>

#define MATRIX_INVERSION_LU_BENCH_ITERATIONS 100000

typedef struct matrix_inversion_lu_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} matrix_inversion_lu_bench_metrics_t;
