# In-Place MSD American Flag Radix Sort in C11 (`radix_sort_msd_c11`)

> Category: **Sorting** | Language: **C11**

## Overview

Implements in-place Most-Significant-Digit 256-way American Flag radix sort on 32-bit unsigned integers with insertion-sort cutoff for small subarrays.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N * W/8) cache-local non-comparative` |
| **Space Complexity** | `O(256 * 4) stack buckets` |

## Mathematical & Safety Invariants

- Output uint32_t array is sorted in non-decreasing unsigned order.
- XOR and algebraic sum of elements are preserved as a permutation check.

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
