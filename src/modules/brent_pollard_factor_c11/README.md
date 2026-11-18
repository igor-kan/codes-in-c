# Brent Cycle-Accelerated Pollard Rho Integer Factorizer (`brent_pollard_factor_c11`)

> Category: **Number Theory** | Language: **C11**

## Overview

Finds non-trivial divisors of composite 64-bit integers using Brent's power-of-two teleporting tortoise and batched modular product GCDs.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^(1/4)) expected power-of-two cycle detection with batched GCD` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Returned factor d satisfies 1 < d < n and n % d == 0.

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
