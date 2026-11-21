# LEB128 Unsigned & ZigZag Variable Integer Codec (`leb128_varint_codec_c11`)

> Category: **Binary Serialization** | Language: **C11**

## Overview

Encodes and decodes 64-bit unsigned values using continuation-bit 7-bit LEB128 groups and signed values via branchless ZigZag bijection.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(bits / 7)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- encode -> decode identity holds across boundary magnitudes 0, 127, 128, and large integers.

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
