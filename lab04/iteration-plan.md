# Task 4: Iteration Plan for Week 5-14

## Step 1: Mermaid Gantt Chart

```mermaid
gantt
    title Project Iteration Plan (Week 5 - Week 14)
    dateFormat  YYYY-MM-DD
    axisFormat  %d %b
    todayMarker on

    section Requirements
    Requirements gathering & analysis (W5-6) :req, 2026-11-23, 14d
    Requirements baseline approved            :milestone, m1, 2026-12-06, 0d

    section Models
    Modeling - use case, class, ERD (W7)      :model, 2026-12-07, 7d

    section Checkpoint
    Checkpoint 1 review (W8)                  :crit, chk1, 2026-12-14, 7d
    Checkpoint 1 deadline                     :milestone, m2, 2026-12-20, 0d

    section Sprint 1
    Sprint 1 - core features (W9-10)          :s1, 2026-12-21, 14d
    Sprint 1 demo                             :milestone, m3, 2027-01-03, 0d

    section Sprint 2
    Sprint 2 - remaining features (W11-12)    :s2, 2027-01-04, 14d
    Sprint 2 demo                             :milestone, m4, 2027-01-17, 0d

    section Hardening
    Testing, bug fixing, polish (W13)         :hard, 2027-01-18, 7d

    section Submission
    Final report & submission (W14)           :crit, sub, 2027-01-25, 7d
    Final deadline                            :milestone, m5, 2027-01-31, 0d

    section Labs
    Weekly labs (W5-14)                       :labs, 2026-11-23, 70d
```

## Step 2: Iteration Goal Table

| Iteration | Weeks | Goal | Features | Capacity | Exit Criterion |
|---|---|---|---|---|---|
| Requirements | 5 - 6 | Understand and document what the system must do | Stakeholder analysis, user stories, functional and non-functional requirements | 48 h | Requirements document reviewed and approved by the team/supervisor |
| Modeling | 7 | Turn requirements into design models | Use case diagram, class diagram, ERD, sequence diagrams | 24 h | All models consistent with requirements and reviewed |
| Checkpoint 1 | 8 | Show progress and get feedback | Requirements + models presentation, initial prototype or mockups | 24 h | Checkpoint 1 passed; feedback items logged |
| Sprint 1 | 9 - 10 | Deliver the core working system | Highest-priority features (e.g. login, main CRUD, core workflow) | 48 h | Core features working, tested and demoed |
| Sprint 2 | 11 - 12 | Deliver remaining features | Secondary features, reports, integration, feedback fixes | 48 h | All planned features implemented and demoed |
| Hardening | 13 | Make the system stable | Testing, bug fixes, UI polish, documentation | 24 h | No critical bugs; test cases pass |
| Submission | 14 | Finalize and hand in | Final report, slides, source code, demo | 24 h | Everything submitted before the deadline |


## Step 3: Calculate Sprint Capacity

```
Capacity = Members x Hours per week x 2 weeks x 0.8
```

Our team:

```
Members = 5 (Cheng Varyroitanak, Suonghan Sethaleap, Yen Chavorn, Pho Phatsophal, Tang Hengly)
Hours per week = 6
Capacity = 5 x 6 x 2 x 0.8 = 48 hours
```