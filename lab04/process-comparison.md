# Process comparison · Team <Clubhub-koprei> · v1.0

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

| Criterion               | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-------------------------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability  |     15 |         5 |           4 |           4 | Requirements may change during development |
| Client availability     |     25 |         5 |           5 |           4 | Client feedback helps clarify project requirements |
| Team experience         |     25 |         4 |           3 |           3 | Team knowledge affects development efficiency |
| Deadline (week 14)      |     20 |         4 |           4 |           3 | The project must be completed on time |
| Risk                    |     15 |         3 |           3 |           4 | Risk management helps prevent project failure |
| **Weighted score**      |    100 |        20 |          19 |          18 |                               |

## Why these weights

- Requirements stability (15): Requirements may change during development
- Client availability (25): Client feedback helps clarify project requirements
- Team experience (25): Team knowledge affects development efficiency
- Deadline (20): The project must be completed on time
- Risk (15): Risk management helps prevent project failure

## Calculation for Waterfall

(5*15+ 5*25 + 4*25 + 4*20 + 3*15)/100 = 425/100 = 4.25

## Calculation for Incremental

(4*15+ 5*25 + 3*25 + 4*20 + 3*15)/100 = 385/100 = 3.85

## Calculation for Scrum-style

(4*15+ 4*25 + 3*25 + 3*20 + 4*15)/100 = 355/100 = 3.55

## Sensitivity check

We move 10 points from client availability(15) to Risk(25). After recalculate: Waterfall(4.05), Incremental(3.65) and Srum-style(3.55).
The winner still WaterFall.

## Conclusion

Based on our weighted comparison, Waterfall is the most suitable development model for the Club Hub project, achieving the highest score of 4.25, followed by Incremental at 3.85 and Scrum-style at 3.55.
However, Waterfall's main weakness is its limited flexibility when project requirements change during development, so our team must carefully plan requirements and communicate with the client before starting each development stage. The sensitivity check also shows that Waterfall remains the winner after adjusting the weights, indicating that our decision is relatively stable. Although a hybrid approach combining Waterfall's structured planning with Incremental's step-by-step development could offer additional benefits, our team would need to evaluate whether it provides better flexibility without affecting the project deadline.