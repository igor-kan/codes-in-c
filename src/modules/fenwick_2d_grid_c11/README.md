# 2D Binary Indexed Tree for Submatrix Sum & Point Update (`fenwick_2d_grid_c11`)

> Category: **Spatial & Range Structures** | Language: **C11**

## Overview

Maintains a 2D Fenwick tree over a bounded grid supporting logarithmic point increments and inclusion-exclusion submatrix sum queries.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log R * log C) point add and submatrix sum query` |
| **Space Complexity** | `O(R * C)` |

## Mathematical & Safety Invariants

- Submatrix sum [r1..r2, c1..c2] equals exact sum of updated grid cells.

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
