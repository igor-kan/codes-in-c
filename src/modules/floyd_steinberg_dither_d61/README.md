# Floyd-Steinberg Integer Error-Diffusion Dithering (`floyd_steinberg_dither_d61`)

> Category: **Image Processing** | Language: **C11**

## Overview

Converts a grayscale buffer into a binary image by diffusing each quantization residual to the right, lower-left, lower, and lower-right neighbors with the classic 7/16, 3/16, 5/16, and 1/16 weights.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(W * H) single raster pass with 7/3/5/1 error weights` |
| **Space Complexity** | `O(W * H) signed error buffer` |

## Mathematical & Safety Invariants

- Every output pixel is exactly black or white.
- The mean output intensity tracks the mean input intensity within the diffusion error bound.

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
