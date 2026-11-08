/**
 * Microbenchmark harness and cycle latency profiling for Clenshaw Recurrence Chebyshev Series Evaluator.
 * Module: chebyshev_eval
 */

#ifndef BENCH_CHEBYSHEV_EVAL_H
#define BENCH_CHEBYSHEV_EVAL_H

#include <stdint.h>

#define BENCH_WARMUP_ITERATIONS 1000
#define BENCH_SAMPLE_ITERATIONS 100000

typedef struct chebyshev_eval_bench_metrics {
    uint64_t total_cycles;
    uint64_t elapsed_nanoseconds;
    double throughput_elements_per_sec;
} chebyshev_eval_bench_metrics_t;

#endif /* BENCH_CHEBYSHEV_EVAL_H */
