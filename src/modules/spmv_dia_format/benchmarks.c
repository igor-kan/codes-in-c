/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Diagonal (DIA) Sparse Matrix-Vector Multiply for Banded.
 * Module: spmv_dia_format
 */

#include <stdint.h>

#define SPMV_DIA_FORMAT_BENCH_ITERATIONS 100000

typedef struct spmv_dia_format_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} spmv_dia_format_bench_metrics_t;
