/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Coordinate List (COO) Sparse Matrix-Vector Multiply.
 * Module: spmv_coo_format
 */

#include <stdint.h>

#define SPMV_COO_FORMAT_BENCH_CYCLES 100000

typedef struct spmv_coo_format_profile_results {
    uint64_t start_tsc;
    uint64_t end_tsc;
    double ops_per_second;
} spmv_coo_format_profile_results_t;
