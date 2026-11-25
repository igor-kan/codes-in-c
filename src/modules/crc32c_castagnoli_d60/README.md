# Tableless Bit-Reflected CRC-32C Castagnoli Checksum (`crc32c_castagnoli_d60`)

> Category: **Checksums & Coding** | Language: **C11**

## Overview

Computes IEEE/iSCSI CRC-32C using reflected polynomial 0x82f63b78 over arbitrary byte payloads without lookup tables.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) 8-bits-per-byte Castagnoli polynomial division` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Matches RFC 3720 check value 0xe3069283 for ASCII 123456789.

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
