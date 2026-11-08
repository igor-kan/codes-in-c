/**
 * Microbenchmark harness and cycle latency profiling for Lock-Free SPSC Circular Ring Buffer.
 * Module: ring_buffer
 */

#ifndef BENCH_RING_BUFFER_H
#define BENCH_RING_BUFFER_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct ring_buffer_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} ring_buffer_bench_metrics_t;

#endif /* BENCH_RING_BUFFER_H */
