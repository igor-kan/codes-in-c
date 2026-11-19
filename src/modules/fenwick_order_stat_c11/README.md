# Binary-Lifted Fenwick Tree K-th Order Statistic Query (`fenwick_order_stat_c11`)

> Category: **Order-Statistic Trees** | Language: **C11**

## Overview

Answers K-th smallest element order-statistic queries over dynamic multisets in a single O(log N) binary-lifting pass over a Fenwick frequency table.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) single-pass binary lifting lower_bound` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Returned index is strictly the smallest index with prefix sum >= k.

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
