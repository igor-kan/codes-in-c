# Segmented Sieve of Eratosthenes Prime Enumerator (`segmented_sieve_c11_d61`)

> Category: **Number Theory** | Language: **C11**

## Overview

Enumerates every prime in an arbitrary closed interval by sieving the base primes up to sqrt(H) once and then marking composites block by block inside the target range.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O((H - L) log log H) segmented marking over base primes` |
| **Space Complexity** | `O(sqrt(H) + block)` |

## Mathematical & Safety Invariants

- Every emitted value is prime and no prime in the interval is skipped.
- All markers stay inside the requested closed interval.

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
