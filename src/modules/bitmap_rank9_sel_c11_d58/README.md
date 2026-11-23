# 64-Bit Word Popcount Rank & k-th Set-Bit Select (`bitmap_rank9_sel_c11_d58`)

> Category: **Succinct Bit Vectors** | Language: **C11**

## Overview

Computes exact prefix set-bit rank and finds the 0-indexed position of the k-th set bit inside 64-bit bitmap words cleanly.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) per 64-bit word rank and select` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Select(mask, Rank(mask, bit_idx)) recovers set bit positions cleanly.

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
