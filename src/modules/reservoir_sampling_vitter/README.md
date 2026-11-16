# Vitter Algorithm R Single-Pass Uniform Streaming Reservoir Sampler (`reservoir_sampling_vitter`)

> Category: **Randomized & Streaming Algorithms** | Language: **C11**

## Overview

Maintains an unbiased uniform random sample of exact size K over unbounded data streams of unknown length N in constant per-item amortized work.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) single pass` |
| **Space Complexity** | `O(K)` |

## Mathematical & Safety Invariants

- After seeing N items (N >= K), reservoir holds K items drawn from the exact stream history.
- If N <= K, every stream element is retained in its arrival order.

## Module Architecture

| File | Lifecycle Role |
| :--- | :--- |
| `types.h` | Stage 01 |
| `errors.h` | Stage 02 |
| `interface.h` | Stage 03 |
| `core.c` | Stage 04 |
| `validation.c` | Stage 05 |
| `fast_path.c` | Stage 06 |
| `concurrent.c` | Stage 07 |
| `invariants.c` | Stage 08 |
| `unit_tests.c` | Stage 09 |
| `property_tests.c` | Stage 10 |
| `benchmark.c` | Stage 11 |
| `README.md` | Stage 12 |

## Verification & Execution Example

```text
gcc -std=c11 -O2 -Wall -Wextra -Werror -pthread core.c validation.c fast_path.c concurrent.c invariants.c unit_tests.c -lm -o test_bin && ./test_bin
```

---
© 2026 Igor Kan
