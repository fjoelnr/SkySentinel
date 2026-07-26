# AGENTS.md

## Purpose

This repository contains firmware for modular ESP32 weather stations.
It combines sensor reading, network transport, display output, and lightweight local data processing.

## Repository Map

- `src/sensors/` sensor integrations such as the BME280
- `src/network/` Wi-Fi and MQTT communication
- `src/visualization/` display rendering
- `src/data_processing/` ring buffer and weather processing helpers
- `test/` PlatformIO unit tests
- `doc/` generated Doxygen output

## Context Hierarchy

1. `AGENTS.md`
2. `.agents/context-index.md`
3. repo-level docs such as `README.md`, `SETUP.md`, `STATUS.md`, and `ROADMAP.md`
4. local README files near the code being changed
5. `.agents/workflows/feature-development.md`
6. `.agents/guardrails/architecture-rules.md`

## Working Rules

- Keep hardware-facing logic small and easy to reason about.
- Do not mix transport concerns with sensor drivers unless there is a clear need.
- Preserve reproducibility for PlatformIO builds.
- Update docs when setup, topics, or board behavior changes.
