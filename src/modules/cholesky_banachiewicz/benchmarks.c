/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Row-by-Row Cholesky-Banachiewicz Matrix Factorization.
 * Module: cholesky_banachiewicz
 */

#include <stdint.h>

#define CHOLESKY_BANACHIEWICZ_BENCH_SAMPLES 100000

typedef struct cholesky_banachiewicz_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} cholesky_banachiewicz_bench_stats_t;
