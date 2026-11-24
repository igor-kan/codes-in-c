# Chunked Wraparound Byte Stream FIFO Buffer (`ring_spsc_bytes_c11_d59`)

> Category: **IO Buffering** | Language: **C11**

## Overview

Buffers variable-length byte slices inside a fixed 64-byte circular buffer cleanly checking remaining free capacity and FIFO byte order.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(L) slice write and read` |
| **Space Complexity** | `O(64)` |

## Mathematical & Safety Invariants

- Writing then reading chunks conserves exact stream order across wraparound.

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
