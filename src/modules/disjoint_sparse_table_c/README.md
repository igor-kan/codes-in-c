# Disjoint Sparse Table for O(1) Associative Range Products (`disjoint_sparse_table_c`)

> Category: **Range Query Structures** | Language: **C11**

## Overview

Precomputes midpoint-centered prefix and suffix aggregates across binary tree levels to answer arbitrary associative range sum/product queries in O(1) time.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N log N) build + O(1) range associative query without idempotence` |
| **Space Complexity** | `O(N log N)` |

## Mathematical & Safety Invariants

- Answers range queries in O(1) using at most one combine operation.

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
