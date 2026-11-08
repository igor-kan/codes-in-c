/**
 * Microbenchmark harness and cycle latency profiling for Cache-Blocked Matrix GEMM with Loop Tiling.
 * Module: matrix_blocked_gemm
 */

#ifndef BENCH_MATRIX_BLOCKED_GEMM_H
#define BENCH_MATRIX_BLOCKED_GEMM_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct matrix_blocked_gemm_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} matrix_blocked_gemm_bench_metrics_t;

#endif /* BENCH_MATRIX_BLOCKED_GEMM_H */
