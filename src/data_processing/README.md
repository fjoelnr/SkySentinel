# Data Processing

This directory contains the lightweight data-processing helpers used by the firmware.

- `ring_buffer.*`: shared rolling storage for sampled values
- `data_processing.*`: higher-level helpers built on top of the ring buffer

These components are intentionally small so they can be reused on resource-constrained boards.
