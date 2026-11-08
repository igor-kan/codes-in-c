/**
 * Microbenchmark harness and cycle latency profiling for 64-Byte Aligned Bump Arena Memory Allocator.
 * Module: arena_allocator
 */

#ifndef BENCH_ARENA_ALLOCATOR_H
#define BENCH_ARENA_ALLOCATOR_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct arena_allocator_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} arena_allocator_bench_metrics_t;

#endif /* BENCH_ARENA_ALLOCATOR_H */
