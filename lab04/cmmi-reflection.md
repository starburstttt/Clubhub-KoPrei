# CMMI Reflection - Team KoPrei

## Where we are today: Level 1 (Initial), with some Level 2 habits

Level 2 (Managed) means work is planned, tracked and controlled in the same way every time. We do some of that, but not consistently, so we place ourselves at Level 1 moving toward Level 2.

Evidence from our repository (156 commits across lab-01 to lab-04):

- **Documented analysis:** `lab04/` holds `fundamental-activities.md`, `reuse-inventory.md`, `iteration-plan.md` and `v-model-trace.md`, so our planning and analysis are written down and checkable.
- **Automated verification:** CMake builds our GoogleTest tests (`csv_smoke_test.cpp`, `cancellation_rule_test.cpp`), so basic checks run without anyone remembering to do them.
- **Inconsistent commits:** only 22 of our 122 non-merge commits use the "Lab-NN" prefix. Many are clear ("Lab-04 Task5: FetchContent GoogleTest and rapidcsv, smoke test"), but others say only "name", "kk" or "dd".
- **Merges:** six merges came from pull requests (#4 to #7 for labs 1 and 2). Later work was often merged directly with "Merge branch ..." commits, and git history cannot show whether a second person approved anything.
- **Traceability:** REQ-12 appears in `CancellationPolicy.hpp`, the test header, `CMakeLists.txt` and one commit message, but it is the only requirement id we trace this way.
- **No review aid:** the repository has no `.github` folder, so there is no pull request template or review checklist.

We are not Level 3 (Defined), because we have no shared standard for reviews or branching, and each member works in their own way.

## The practice area we adopt now: Peer Reviews

We chose **Peer Reviews** (CMMI Verification) over Configuration Management or Estimating for three reasons. It is the cheapest to start, because GitHub already supports it. It addresses our clearest weakness, which is that work often reaches `main` without a second reader. And our requirements contain boundary rules that one reader easily gets wrong.

The 24-hour cancellation rule shows this. `CancellationPolicy.hpp` line 10 still carries the comment "TODO: confirm with the client that exactly 24 h is still allowed". A second reader would have forced that question earlier, and would also catch a wrong comparison (`>` instead of `>=`) before it reaches the client.

## Three concrete actions

1. **Repository Owner (starburstttt):** enable branch protection on `main`, so every merge needs a pull request with one approval from someone other than the author, starting Sprint 1 day 1. Only an admin can change this setting.
2. **CHENG Varyroitanak (Product Owner):** add `.github/pull_request_template.md` with a short checklist (requirement id linked, tests added, boundary values checked), by the end of Sprint 1 week 1.
3. **Whole team:** review each pull request within 24 hours, label any problem found as "defect" in the comments, and use the "Lab-NN task: what changed" commit format. The Scrum Master counts reviews at the end of each week.

## Measurement and when we check

- **Metric:** percentage of merged pull requests to `main` that had at least one approval from a non-author before merging.
- **Target:** 100% in Sprint 1.
- **Baseline:** the pull requests we have merged so far, counted from the GitHub pull request list.
- **Check:** at the Sprint 1 retrospective we present the count and decide whether to keep, tighten or change the practice.