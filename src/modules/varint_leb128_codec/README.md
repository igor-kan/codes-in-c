# LEB128 Unsigned & ZigZag Signed Variable-Length Integer Codec (`varint_leb128_codec`)

> Category: **Binary Serialization** | Language: **C11**

## Overview

Implements DWARF/Protobuf-compatible 7-bit continuation-bit ULEB128 and ZigZag SLEB128 variable-length integer encoders/decoders with shift-overflow protection on malformed 10-byte frames.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) <= 10 bytes` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Every 64-bit unsigned integer encodes in [1, 10] bytes and decodes losslessly.
- ZigZag maps signed integers near zero (-1 -> 1, 1 -> 2, -2 -> 3) to minimal byte widths.
- Malformed non-terminating >10-byte payloads or shift overflows fail deterministically.

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
