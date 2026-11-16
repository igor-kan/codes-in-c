# Power-of-Two Unsigned-Index Byte-Stream kfifo Ring Buffer (`kfifo_power2_ring`)

> Category: **Lock-Free & Kernel Buffers** | Language: **C11**

## Overview

Implements a Linux-kernel-style power-of-two byte ring buffer storing unmasked unsigned head/tail counters so full (cap == in - out) vs empty (in == out) requires zero sentinel slots.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) amortized memcpy wraparound` |
| **Space Complexity** | `O(Capacity = 2^K)` |

## Mathematical & Safety Invariants

- 0 <= (in - out) <= mask + 1 holds through unsigned 32-bit index wraparound.
- Stream read after arbitrary chunked wrap-around writes reconstructs input FIFO bytes identically.

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
