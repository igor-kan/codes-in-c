# Deterministic 64-Bit Miller-Rabin Primality Engine (`miller_rabin_det64_d60`)

> Category: **Number Theory** | Language: **C11**

## Overview

Tests exact 64-bit integers for primality using the proven deterministic 7-base witness set {2, 325, 9375, 28178, 450775, 9780504, 1795265022}.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(k log^3 N) exact __uint128_t witness modular exponentiation` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Zero false positives or negatives across all 64-bit unsigned integers.

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
