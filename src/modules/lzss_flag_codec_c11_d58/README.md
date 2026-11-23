# Flag-Tagged Lossless Byte LZSS Match Codec (`lzss_flag_codec_c11_d58`)

> Category: **Lossless Compression** | Language: **C11**

## Overview

Encodes compressible byte runs into explicit literal vs (offset, len) tagged structs and reconstructs original slices losslessly.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N * W)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Encode -> decode recovers source buffer byte-for-byte cleanly.

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
