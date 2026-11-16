# Byte-Stream PackBits Run-Length Encoder & Bounds-Safe Decoder (`rle_packbits_codec`)

> Category: **Data Compression** | Language: **C11**

## Overview

Implements TIFF/Apple PackBits byte-stream RLE using signed header control bytes (0..127 literal, -1..-127 run repeat, -128 noop) with overflow-checked decode bounds.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N)` |
| **Space Complexity** | `O(1) extra state` |

## Mathematical & Safety Invariants

- decode(encode(raw)) equals raw byte-for-byte for repetitive, incompressible, and alternating streams.
- Malformed truncated headers fail gracefully with ERR_INVALID.

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
