# Castagnoli CRC-32C Bitwise Packet Checksum (`crc32c_castagnoli_c11`)

> Category: **Error Detection** | Language: **C11**

## Overview

Computes reflected Castagnoli CRC-32C digests (polynomial 0x82F63B78) over raw byte buffers without mutable lookup tables.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(8 * N) deterministic polynomial reduction` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Standard IEEE/iSCSI test vector '123456789' yields exact 0xE3069283.

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
