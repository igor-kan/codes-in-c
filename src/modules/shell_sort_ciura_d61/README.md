# Shell Sort with Ciura's Empirically Optimal Gap Sequence (`shell_sort_ciura_d61`)

> Category: **Sorting** | Language: **C11**

## Overview

Sorts an integer array by repeated gapped insertion sort over the classic Ciura gap sequence 1750, 701, 301, 132, 57, 23, 10, 4, 1.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^1.25) practical gap-shrinking insertion passes` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Output is non-decreasing and is a permutation of the input multiset.
- Each gap pass preserves the multiset of stored values.

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
