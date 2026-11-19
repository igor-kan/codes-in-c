# Linear-Time Z-Box Array Pattern Search & Period Finder (`z_algorithm_lcp_c11`)

> Category: **String Matching** | Language: **C11**

## Overview

Computes Z[i] (the longest common prefix between s[0..] and s[i..]) in O(N) time and locates all pattern occurrences in a text without extra dynamic allocation.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) Z-box mirror reuse with right-most Z-boundary` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Every index i with z[m + 1 + i] == m satisfies memcmp(text + i, pat, m) == 0.

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
