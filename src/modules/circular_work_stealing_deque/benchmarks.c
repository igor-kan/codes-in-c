/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#include <stdint.h>

#define CIRCULAR_WORK_STEALING_DEQUE_BENCH_SAMPLES 100000

typedef struct circular_work_stealing_deque_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} circular_work_stealing_deque_bench_stats_t;
