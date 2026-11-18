# Patience Sorting Longest Increasing Subsequence Reconstructor (`patience_lis_reconstruct_c`)

> Category: **Dynamic Programming** | Language: **C11**

## Overview

Computes the exact length and lexicographically earliest indices of a strictly increasing subsequence of maximum length in O(N log N) time.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N log N) binary-searched pile tails with parent predecessor links` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Reconstructed subsequence is strictly increasing and has maximal length.

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
