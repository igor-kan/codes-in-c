# LZ77 Bounded Sliding Window Match Tokenizer (`lz77_sliding_match_c11`)

> Category: **Data Compression** | Language: **C11**

## Overview

Emits exact back-reference (offset, match_len, next_literal) tokens using a bounded lookback window and reconstructs the original byte buffer.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N * W)` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Lossless reconstruction matches original buffer byte-for-byte.

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
