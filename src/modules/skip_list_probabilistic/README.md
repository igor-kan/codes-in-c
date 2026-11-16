# Multi-Level Ordered Skip List Dictionary (XORShift32 Seeded) (`skip_list_probabilistic`)

> Category: **Ordered Search Structures** | Language: **C11**

## Overview

Implements a dynamic multi-level ordered dictionary supporting O(log N) key-value lookup, replacement, deletion, and strict ascending key-chain invariant verification.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) expected search, insert, delete` |
| **Space Complexity** | `O(N) expected (<= 2N pointers)` |

## Mathematical & Safety Invariants

- Level-0 forward links form a strictly ascending sorted key sequence.
- Every higher level k > 0 is a strict subsequence of level k - 1.
- Destroy cleanly frees every allocated multi-level node with zero leaks.

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
