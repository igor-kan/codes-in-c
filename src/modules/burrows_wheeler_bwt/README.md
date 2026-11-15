# Burrows-Wheeler Transform & LF-Mapping Inverse Codec (`burrows_wheeler_bwt`)

> Category: **Data Compression** | Language: **C11**

## Overview

Reversible block-sorting Burrows-Wheeler Transform paired with Last-to-First (LF) character rank permutation inversion and Move-To-Front coding.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^2 log N) sort / O(N) inverse` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Inverse BWT reconstructs original string iff primary_index < length.
- Character histogram of BWT output matches original input histogram identically.
- Move-To-Front round-trip is exact bijection on unsigned byte blocks.

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
