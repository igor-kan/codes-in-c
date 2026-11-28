# Pointer-XOR Compressed Doubly Linked List Over a Node Arena (`xor_linked_list_d61`)

> Category: **Linked Structures** | Language: **C11**

## Overview

Stores each node's predecessor and successor addresses XORed into one word so a doubly linked list traverses in both directions with a single pointer field per node.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) tail append and O(N) forward traversal` |
| **Space Complexity** | `O(N) arena nodes` |

## Mathematical & Safety Invariants

- Forward traversal visits every node exactly once in insertion order.
- The XOR link of the tail equals the address of its predecessor.

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
