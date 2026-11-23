# IEEE 802.3 Standard Bitwise CRC-32 Checksum (`crc32_ieee8023_c11_d58`)

> Category: **Error Detection** | Language: **C11**

## Overview

Computes reflected Ethernet/gzip IEEE 802.3 CRC-32 digests (polynomial 0xEDB88320) over raw byte slices without heap tables.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(8 * N)` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Standard vector '123456789' yields exact 0xCBF43926 digest.

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
