# Four-Ary Array Heap Priority Queue with Sift-Up and Sift-Down (`dary_heap_c11_d61`)

> Category: **Priority Queues** | Language: **C11**

## Overview

Stores a four-ary min-heap in a flat array where children of slot i occupy slots 4i+1 through 4i+4, reducing tree height relative to a binary heap.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log_4 N) push and O(4 log_4 N) extract-min comparisons` |
| **Space Complexity** | `O(N) contiguous array` |

## Mathematical & Safety Invariants

- The array prefix is always a valid min-heap by key.
- Repeated extraction yields keys in non-decreasing order.

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
