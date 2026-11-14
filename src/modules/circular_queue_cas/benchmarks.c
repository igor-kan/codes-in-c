/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and latency profiling for Atomic CAS-Based Lock-Free Circular Queue Buffer.
 * Module: circular_queue_cas
 */

#include <stdint.h>

#define CIRCULAR_QUEUE_CAS_BENCH_ITERATIONS 100000

typedef struct circular_queue_cas_bench_metrics {
    uint64_t tsc_cycles;
    double ops_per_sec;
} circular_queue_cas_bench_metrics_t;
