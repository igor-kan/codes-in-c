# Kuhn Augmenting-Path Maximum Bipartite Matching in C11 (`kuhn_bipartite_match_c11`)

> Category: **Graph Matching** | Language: **C11**

## Overview

Computes maximum cardinality bipartite matching via iterative vertex-by-vertex DFS alternating augmenting path exploration.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(V * E) DFS alternating augmenting path search` |
| **Space Complexity** | `O(V + E)` |

## Mathematical & Safety Invariants

- Every matched edge pairs distinct left and right vertices without conflict.

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
