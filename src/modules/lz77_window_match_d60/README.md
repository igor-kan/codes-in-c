# Sliding-Window LZ77 Longest Prefix Token Codec (`lz77_window_match_d60`)

> Category: **Data Compression** | Language: **C11**

## Overview

Compresses arbitrary byte buffers into (distance, length, next_literal) tokens and reconstructs the original byte sequence losslessly.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N * W) greedy longest back-reference search` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Round-trip decompression reproduces every input byte verbatim.

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
