# Lab-04 · Software Development Processes · Team KoPrei - V2.0

## Files of this lab
| File                          | Task | Description                          |
|-------------------------------|------|--------------------------------------|
| fundamental-activities.md     | 1    | How specification, design and implementation, validation and evolution happen in Club Hub: who leads, weeks, artifact and done-when criterion, with ISO/IEC/IEEE 12207 mapping and loops |
| scores/*.md                   | 2    | individual scores, one per member    |
| process-comparison.md         | 2    | Weighted comparison of waterfall, incremental and Scrum-style development on five criteria, with sensitivity check and conclusion |
| process-decision.md, process.mmd | 3 | PDR-001 (context, options, decision, tailoring table, consequences) and the Mermaid process diagram |
| iteration-plan.md             | 4    | Mermaid Gantt chart for weeks 5 to 14 and the iteration goals table with sprint capacity |
| reuse-inventory.md            | 5    | Make-or-reuse table of 8 needs, licence check, and build verification with CTest output |
| ../CMakeLists.txt             | 5    | FetchContent: googletest v1.17.0, rapidcsv v8.90 |
| ../tests/csv_smoke_test.cpp, ../tests/data/events.csv | 5 | Smoke test: reads two events through rapidcsv and checks a title and a capacity |

## Inputs reused
| Input               | File                              | Version (commit) |
|---------------------|-----------------------------------|------------------|
| Team charter        | lab01/team-charter.md             | 1ebbe37          |
| Problem statement   | lab01/problem-statement.md        | 593be76          |
| Application type    | lab02/adr-001-application-type.md | 6950744          |
| Repository licence  | LICENSE                           | cae8176          |

## Dependencies added
| Dependency | Version | Licence      | Use                         |
|------------|---------|--------------|-----------------------------|
| GoogleTest | v1.17.0 (upgraded from v1.14.0 in Lab-03) | BSD-3-Clause | unit tests |
| rapidcsv   | v8.90   | BSD-3-Clause | reading the CSV event data  |

## Task 3: approvals of PDR-001 (every member reviews and approves)
| Member               | Approved? (Yes/No) | Date   |
|----------------------|--------------------|--------|
| CHENG Varyroitanak   | Yes             | 19/11/2026|
| PHO Phatsophal       | Yes             | 19/11/2026|
| SOUNGHAN Sethaleaph  | Yes             | 19/11/2026 |
| YEN Chhavorn         | Yes          | 19/11/2026 |
| TANG Hengly          | Yes          | 19/11/2026 |

## Change log
| Date       | Change                                               | By     |
|------------|------------------------------------------------------|--------|
| 2026-11-17 | Lab-04 task 5: reuse inventory, FetchContent GoogleTest and rapidcsv, smoke test | CHENG Varyroitanak |
| 2026-11-13 | Lab-04 task 1: fundamental activities for Club Hub                               | Team KoPrei |
| 2026-11-18 | Lab-04 task 2: scored process comparison                             | Yen Chhavorn, Team KoPrei |
| 2026-11-18 | Lab-04 task 3: Completed process-comparison.md and process.mmd                              | Pho Phatsophal|
| 2026-11-18 | Lab-04 task 4: Added and Completed iteration-plan.md                               | Tang Hengly |
| 2026-11-18 | Lab-04 Challenge: Did the entire challenge | Sounghan Sethaleaph |