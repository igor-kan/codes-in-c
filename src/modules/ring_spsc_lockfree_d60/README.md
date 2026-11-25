# Bounded Power-of-Two SPSC FIFO Queue with Acquire/Release Indices (`ring_spsc_lockfree_d60`)

> Category: **Lock-Free Queues** | Language: **C11**

## Overview

Implements a fixed-size power-of-two single-producer single-consumer queue with wrap-safe modular distance arithmetic.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) push and pop without dynamic allocation` |
| **Space Complexity** | `O(N) circular ring` |

## Mathematical & Safety Invariants

- FIFO ordering holds across arbitrary interleaved enqueue/dequeue operations.

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
