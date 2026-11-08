/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

#include <stdint.h>

#define ATOMIC_MPMC_QUEUE_BENCH_ITERATIONS 100000

typedef struct atomic_mpmc_queue_bench_result {
    uint64_t total_cycles;
    double throughput_ops_sec;
} atomic_mpmc_queue_bench_result_t;
