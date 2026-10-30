# SE-Project
# Lab 02: Types of Application & Quality Attributes

**Team:** KoPrei  
**Version:** 2.0  
**Date:** 2026-10-30  

---

## Overview

This directory contains the deliverables, specifications, diagrams, and core C++ implementations for Lab 02 of the ITC Club Hub project. The objectives of this lab are to classify application timing and availability demands, select and justify the optimal application architecture via an Architectural Decision Record (ADR), formulate six measurable Quality Attribute Scenarios (QAS), model the system context and 3-tier architecture using Mermaid, and decouple core C++20 business logic from standard user interfaces.

---

## Lab-02 Repository Structure & Deliverables

```text
itc-club-hub/
├── lab01/                            # Lab-01 deliverables (read-only reference)
├── lab02/
│   ├── app-classification.md         # Task 1: Application classification & demand analysis
│   ├── app-quadrant.mmd              # Task 1: Demand quadrant diagram (Mermaid)
│   ├── adr-001-application-type.md   # Task 2: ADR for application type selection
│   ├── quality-scenarios.md          # Task 3: 6 Quality Attribute Scenarios & priority matrix
│   ├── context-diagram.mmd           # Task 4: System context diagram (+ generated .png)
│   ├── architecture.mmd              # Task 4: 3-Tier architecture diagram (+ generated .png)
│   ├── README.md                     # Task 5: Detailed record of lab tasks and changes
│   └── challenge/
│       └── offline-checkin.md        # Challenge: Offline check-in architectural design
├── include/
│   └── clubhub/
│       ├── event.hpp                 # Task 5: Core event domain entity declaration
│       ├── event_csv.hpp             # Task 5: CSV parsing & repository interface
│       └── queued_checkin.hpp        # Challenge: Offline queue data structure header
├── src/
│   ├── event.cpp                     # Task 5: Domain logic implementation
│   ├── event_csv.cpp                 # Task 5: CSV persistence implementation
│   └── cli/
│       └── main.cpp                  # Task 5: CLI entry point / presentation interface
├── data/
│   └── events.csv                    # Task 5: Sample event dataset
└── CMakeLists.txt                    # Task 5: Root CMake build configuration
```

---

## Deliverables Summary

| Task / File | Description | Author / Contributor |
| :--- | :--- | :--- |
| [`app-classification.md`](lab02/app-classification.md) | Analyzes application timing vs. availability demands across 5 real-world benchmark systems. | Pho Phatsophal, Tang Hengly, Suonghan Sethaleaph, Yen Chhavorn, CHENG Varyroitanak |
| [`app-quadrant.mmd`](lab02/app-quadrant.mmd) | Visualizes Club Hub's positioning on a 2D demand quadrant diagram relative to benchmarks like ABA Mobile and Telegram. | Team KoPrei |
| [`adr-001-application-type.md`](lab02/adr-001-application-type.md) | Evaluates Native, PWA, Responsive Web, and Cross-Platform options using a weighted decision matrix and deal-breaker criteria. | Team KoPrei |
| [`quality-scenarios.md`](lab02/quality-scenarios.md) | Formulates 6 Quality Attribute Scenarios (Availability, Performance, Usability, Security, Modifiability, Portability) and a priority matrix. | CHENG Varyroitanak, Suonghan Sethaleaph, Hengly |
| [`context-diagram.mmd`](lab02/context-diagram.mmd) | Maps external actors (Students, Organisers, Club Leaders, Admins) and external system integrations (E-mail, ITC Directory). | Team KoPrei |
| [`architecture.mmd`](lab02/architecture.mmd) | Models the 3-Tier system structure (Presentation Tier, Logic Tier, Data Tier). | Team KoPrei |
| [`offline-checkin.md`](lab02/challenge/offline-checkin.md) | *(Challenge)* Details client-side ServiceWorker & IndexedDB local queuing for zero-network check-ins. | Team KoPrei |

---

## Build & Execution Instructions

1. **Configure CMake:**
   ```bash
   cmake -S . -B build
   ```

2. **Build Executable:**
   ```bash
   cmake --build build
   ```

3. **Run CLI Application:**
   * **Windows:**
     ```cmd
     .\build\Debug\clubhub.exe list-events data/events.csv
     ```
   * **Linux / macOS:**
     ```bash
     ./build/clubhub list-events data/events.csv
     ```

---

## Inputs Reused & Change Log

* **Inputs Reused:**
  * CMake C++20 root build framework from Lab 01.
  * System requirements and stakeholder definitions established in Lab 01.
* **Change Log (Version 2.0):**
  * Created and classified 5 applications on the timing vs. availability quadrant diagram (`app-classification.md`, `app-quadrant.mmd`).
  * Formulated ADR-001 selecting PWA architecture based on weighted scoring and offline deal-breaker analysis (`adr-001-application-type.md`).
  * Completed six Quality Attribute Scenarios with exact quantitative response metrics and populated the priority matrix (`quality-scenarios.md`).
  * Modeled system context and 3-tier architecture with Mermaid charts (`context-diagram.mmd`, `architecture.mmd`).
  * Decoupled core domain logic in C++ (`event.cpp`, `event_csv.cpp`) from standard CLI I/O streams (`src/cli/main.cpp`).