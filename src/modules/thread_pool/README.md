# Work-Stealing POSIX Thread Pool Engine (`thread_pool`)

## Overview

The `thread_pool` module provides high-performance, mathematically rigorous operations for `codes-in-c`.

### Component Artifacts

- **Type Definitions**: [`types.c`](./types.c)
- **Computational Core**: [`core.c`](./core.c)
- **Deterministic Unit Tests**: [`tests.c`](./tests.c)
- **SIMD Optimizations**: [`perf_simd.c`](./perf_simd.c)
- **Microbenchmarks**: [`benchmarks.c`](./benchmarks.c)
- **Boundary Validation**: [`boundary.c`](./boundary.c)
- **Property Fuzzing**: [`fuzz_invariants.c`](./fuzz_invariants.c)

### Computational Invariant

$$f(x) = x \left(1 + \frac{1}{2}x - \frac{1}{8}x^2\right)$$

Maintained under strict continuous integration, sanitizer checks, and memory bounds verification.
