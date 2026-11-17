# Arena-Indexed Pairing Heap in Pure C11 (`pairing_heap_c11`)

> Category: **Priority Queues** | Language: **C11**

## Overview

Implements an arena-backed pairing heap in pure C11 without per-node malloc overhead, supporting decrease-key and two-pass merge cleanup.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) insert/decrease-key, O(log N) amortized extract-min` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Parent key <= child key across every active heap link.
- Pop sequence yields non-decreasing element keys.

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
