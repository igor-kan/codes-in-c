# LZ77 Sliding-Window Lossless Token Compressor (`lz77_sliding_codec`)

> Category: **Data Compression** | Language: **C11**

## Overview

Lossless sliding-window LZ77 encoder and decoder emitting (offset, length, literal) tokens supporting overlapping self-referential RLE copies.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N * W)` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- decode(encode(input)) equals input byte-for-byte for every finite byte buffer.
- Token offsets never exceed the active lookback window or current decoded cursor.
- Zero out-of-bounds reads or writes on empty or incompressible inputs.

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
