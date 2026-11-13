/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three
 */

#include <stdint.h>

#define QUICKSORT_MEDIAN_THREE_BENCH_ITERATIONS 100000

typedef struct quicksort_median_three_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} quicksort_median_three_bench_metrics_t;
