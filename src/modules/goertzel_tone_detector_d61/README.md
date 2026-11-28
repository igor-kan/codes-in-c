# Goertzel Single-Frequency DFT Bin Detector (`goertzel_tone_detector_d61`)

> Category: **Signal Processing** | Language: **C11**

## Overview

Evaluates one discrete Fourier coefficient with the Goertzel second-order recurrence, producing exact bin power without computing the full spectrum and selecting the dominant non-negative frequency bin up to the Nyquist limit.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) per target bin and O(N * B) for a B-bin scan` |
| **Space Complexity** | `O(1) recurrence state` |

## Mathematical & Safety Invariants

- A pure cosine at an integer bin concentrates its power in that bin.
- The bin powers obey Parseval's identity and real-signal conjugate symmetry.

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
