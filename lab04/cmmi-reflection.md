# CMMI reflection · Team KoPrei

## Where we are today (level 2, Managed, partially)
Our team plans and tracks work at project level, but practices are not yet consistent.
Evidence from our repository:
- We have a structured lab04 folder with fundamental-activities.md, reuse-inventory.md and v-model-trace.md, so planning and analysis are documented.
- CMake and googletest tests exist (csv_smoke_test.cpp, cancellation_rule_test.cpp), so basic verification is automated.
- [Write what you see in git log: are commits small and descriptive, or just "update"?]
- [Write whether you use pull requests and whether anyone reviews before merging]
- [Write whether requirement ids like REQ-12 appear in commits or tests]
We are not yet level 3 (Defined): there is no shared team standard for reviews or branching, and each member works in their own way.

## The practice area we adopt now and why
**Peer Reviews** (CMMI Verification). Our requirements contain business rules with boundary values, such as the 24-hour cancellation rule. The TODO in canCancel shows that ambiguities survive when only one person looks at the code. A second reader catches wrong comparisons (> vs >=) and unclear requirements before they reach the client.

## Three actions (who, from when)
1. **[Member name]**: enable branch protection on main so every merge needs a pull request with one approval, from Sprint 1 day 1.
2. **[Member name]**: add a pull request template with a short checklist (requirement id linked, tests added, boundary values checked), by the end of Sprint 1 week 1.
3. **Whole team**: review each pull request within 24 hours, and label found problems "defect" in the comments, starting Sprint 1 day 2.

## How we measure it (metric, target) and when we check
- **Metric:** percentage of merged pull requests that had at least one review before merging.
- **Target:** 100% of pull requests to main, and at least one defect or clarification found per five reviews, which shows the reviews are real.
- **Check:** Sprint 1 retrospective. We will count from the GitHub pull request list and decide whether to keep, tighten or change the practice.