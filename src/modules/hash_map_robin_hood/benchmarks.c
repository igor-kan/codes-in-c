/**
 * Microbenchmark harness and cycle latency profiling for Robin Hood Open Addressing Cache-Friendly Hash Table.
 * Module: hash_map_robin_hood
 */

#ifndef BENCH_HASH_MAP_ROBIN_HOOD_H
#define BENCH_HASH_MAP_ROBIN_HOOD_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct hash_map_robin_hood_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} hash_map_robin_hood_bench_metrics_t;

#endif /* BENCH_HASH_MAP_ROBIN_HOOD_H */
