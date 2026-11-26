# Process comparison · Team KoPrei · v1.2

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.
Team scores are the average of the five individual score files in lab04/scores/ (one decimal). "Scrum-style" uses the Agile row of those files.

| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     15 |       3.6 |         3.6 |         3.6 | Requirements are still being clarified in weeks 5-6, so models that absorb change fit better; members disagreed most on waterfall here. |
| Client availability     |     25 |       2.8 |         4.2 |         4.0 | The TA is free about 30 min a week, enough for a review after each increment or sprint; waterfall shows the client nothing until the end. |
| Team experience         |     25 |       4.0 |         3.6 |         4.0 | We know waterfall from class; incremental and sprints are newer to most of us. |
| Deadline (week 14)      |     20 |       3.2 |         4.2 |         3.6 | Incremental delivery gives a working demo after each increment, the safest way to have something to show in week 14. |
| Risk                    |     15 |       3.0 |         2.8 |         3.4 | Sprint reviews and retrospectives catch problems fastest; incremental can hide integration problems until late. |
| **Weighted score**      |    100 |  **3.33** |    **3.75** |    **3.77** |                               |

## Why these weights
- Requirements stability (15): the SRS is written in weeks 5-6, so requirements are partly stable, and the fixed milestones limit how much can change.
- Client availability (25): the client is the TA, about 30 minutes a week (case-study brief), so how often we get feedback matters a lot.
- Team experience (25): a model we cannot run well will fail regardless of how well it fits on paper.
- Deadline (20): submission and demo are fixed in week 14 (brief).
- Risk (15): important, but the scope is small (core in C++20 with CSV storage).

## Calculation for Waterfall
(15×3.6 + 25×2.8 + 25×4.0 + 20×3.2 + 15×3.0) / 100 = 333 / 100 = 3.33

## Calculation for Incremental
(15×3.6 + 25×4.2 + 25×3.6 + 20×4.2 + 15×2.8) / 100 = 375 / 100 = 3.75

## Calculation for Scrum-style
(15×3.6 + 25×4.0 + 25×4.0 + 20×3.6 + 15×3.4) / 100 = 377 / 100 = 3.77

## Sensitivity check
We move 10 points from client availability (25 → 15) to risk (15 → 25). New scores: Waterfall 3.35, Incremental 3.61, Scrum-style 3.71. Scrum-style stays first and waterfall stays last, but the gap between Scrum-style and Incremental is small in both cases.

## Conclusion
Scrum-style (3.77) and incremental delivery (3.75) are practically tied, and waterfall is clearly last (3.33) because it gives the client no feedback before the end. Incremental is stronger on client availability and the week 14 deadline, while Scrum-style is stronger on risk. The weakness we must manage with incremental delivery is risk (2.8): late integration problems, which we will reduce with a review and demo after each increment and tests running in CI on every pull request. A hybrid fits Club Hub best: a plan-driven start (requirements in weeks 5-6, models in week 7, checkpoint in week 8) followed by two incremental deliveries.