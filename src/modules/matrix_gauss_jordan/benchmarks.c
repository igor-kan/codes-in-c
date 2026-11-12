/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan
 */

#include <stdint.h>

#define MATRIX_GAUSS_JORDAN_BENCH_CYCLES 100000

typedef struct matrix_gauss_jordan_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} matrix_gauss_jordan_profile_results_t;
