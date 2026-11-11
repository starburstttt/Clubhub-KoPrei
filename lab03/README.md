# Lab-03 · Record of what changed

| File | Task | Status |
|------|------|--------|
| lab03/accessibility-checklist.md | 4 | new |
| lab03/cli-output-rules.md | 4 | new |
| lab03/data-inventory.md | 1 | new |
| include/clubhub/ConsoleOutput.h | 4 | new |
| include/clubhub/Student.h | 2 | new |
| src/ConsoleOutput.cpp | 4 | new |
| src/Student.cpp | 2 | new |
| tests/ConsoleOutputTest.cpp | 4 | new |
| tests/StudentPrivacyTest.cpp | 2 | new |
| LICENSE | 3 | new |

## Lab-03 Repository Structure & Deliverables (What we did in Lab-03)

itc-club-hub/
├── lab01/                            # Lab-01 deliverables (read-only reference)
├── lab02/                            # Lab-02 deliverables (read-only reference)
├── LICENSE                            # Task 3: Repository licence (MIT / SPDX headers)
├── THIRD_PARTY_NOTICES.md             # Task 3: Third-party notices (GoogleTest BSD-3-Clause)
├── licenses/
│   └── googletest-LICENSE.txt         # Task 3: Raw GoogleTest licence text
├── CMakeLists.txt                     # Tasks 2 & 4: Root build script adding Student & ConsoleOutput
├── include/
│   └── clubhub/
│       ├── Student.h                  # Task 2: C++ Student header (data minimisation & redacted log safe)
│       └── ConsoleOutput.h            # Task 4: Accessible CLI formatting header (NO_COLOR, error handling)
├── src/
│   ├── Student.cpp                    # Task 2: Student implementation, input checks & maskId() helper
│   └── ConsoleOutput.cpp              # Task 4: Console output formatting & status labels implementation
├── tests/
│   ├── StudentPrivacyTest.cpp         # Task 2: Unit tests for privacy, optional consents & redaction
│   └── ConsoleOutputTest.cpp          # Task 4: Unit tests for CLI status text & structured errors
└── lab03/
    ├── data-inventory.md              # Task 1: Personal data inventory, retention, & phone lifecycle diagram
    ├── privacy-notice.md              # Task 2: Plain-language privacy notice (<300 words)
    ├── consent-flow.mmd               # Task 2: Mermaid flowchart for CLI/web consent & withdrawal path
    ├── retention-rules.md             # Task 2: Storage retention schedules per kept inventory field
    ├── licence-decision.md            # Task 3: Licence evaluation matrix (MIT/Apache/GPL) & team agreement
    ├── accessibility-checklist.md     # Task 4: WCAG 2.2 Level AA matrix (12 criteria across POUR) & contrast ratios
    ├── cli-output-rules.md            # Task 4: 6+ rules for accessible terminal outputs with good/bad examples
    ├── ethics-cases.md                # Task 5: 7-step decision framework analysis for Scenarios A & B
    ├── README.md                      # Task 5: Master record of files, reused hashes, changelog & client questions
    └── ai-feature-proposal.md         # Challenge: AI event recommendation go/no-go proposal & bias evaluation

## Inputs reused
| Input | File | Version / commit |
|-------|------|------------------|
| Team charter | lab01/team-charter.md | b33ebef |
| Application decision | lab02/architecture.md | a21062c |

## Change log
| Date | Change | Author |
|------|--------|--------|
| 2026-11-11 | Lab-03: accessibility review, CLI rules, console output, and student privacy modules | The whole team |

## Open questions for the client
* Should Khmer script rendering be tested at 200% zoom specifically for mobile web layouts, or desktop first?
* Are there any specific institutional single sign-on (SSO) providers we should prioritize for the login screen's accessible authentication criteria?
* Are club leaders allowed to access attendance records from other clubs?
* Do students need to give permission before their attendance information is shared?
* Who is authorized to view and manage attendance reports?
* Should cancelled registrations be excluded from monthly attendance reports?
* Should cancellations within 24 hours be accepted or rejected?