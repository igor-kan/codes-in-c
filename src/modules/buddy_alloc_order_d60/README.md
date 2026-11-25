# Binary Buddy Block Split & XOR-Coalesce Allocator (`buddy_alloc_order_d60`)

> Category: **Memory Management** | Language: **C11**

## Overview

Tracks power-of-two blocks across binary tree levels supporting exact buddy address computation via index ^ (1 << order).

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) order split and coalesce` |
| **Space Complexity** | `O(N) bitmap blocks` |

## Mathematical & Safety Invariants

- Freeing all allocated blocks restores the full top-order free root block.

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
