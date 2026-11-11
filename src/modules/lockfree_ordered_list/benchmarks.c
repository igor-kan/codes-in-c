/**
 * @file benchmarks.c
 * @brief Microbenchmark harness and cycle timing for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#include <stdint.h>

#define LOCKFREE_ORDERED_LIST_BENCH_SAMPLES 100000

typedef struct lockfree_ordered_list_bench_stats {
    uint64_t cycles;
    double throughput_ops_sec;
} lockfree_ordered_list_bench_stats_t;
