# Thomas Tridiagonal Matrix Algorithm (TDMA) Linear Solver in C11 (`tridiagonal_thomas_c11`)

> Category: **Numerical Linear Algebra** | Language: **C11**

## Overview

Solves strictly diagonally dominant n x n tridiagonal systems Ax = d in O(n) scalar operations via forward elimination and back substitution without full LU memory footprint.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(N) scratch / O(1) extra for preallocated workspace` |

## Mathematical & Safety Invariants

- Solved vector x satisfies ||Ax - d||_inf < 1e-10 across non-uniform diagonally dominant matrices.
- Zero pivots are strictly rejected with ERR_INVALID.

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
