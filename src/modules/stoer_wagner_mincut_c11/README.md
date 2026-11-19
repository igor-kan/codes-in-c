# Stoer-Wagner Maximum-Adjacency Global Min-Cut in C11 (`stoer_wagner_mincut_c11`)

> Category: **Graph Cuts** | Language: **C11**

## Overview

Finds the global minimum cut of an undirected weighted graph via Stoer-Wagner vertex merging phases without external allocations.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(V^3) maximum-adjacency phase contraction` |
| **Space Complexity** | `O(V^2) static matrix` |

## Mathematical & Safety Invariants

- Global minimum cut weight <= every individual vertex weighted degree.

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
