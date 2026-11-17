# V-model trace · REQ-12 · ITC Club Hub · Team KoPrei

**REQ-12:** A student can cancel a registration until 24 hours before the start of the event.
Business rule: cancellation allowed if (start − now) ≥ 24 h; exactly 24 h is allowed (to confirm with client).

| Level | Left side (defines) | Right side (tests) |
|---|---|---|
| Requirement | REQ-12 (above) | AT-12: two Gherkin scenarios (section 2), run at sprint review |
| System specification | SYS-12: the system rejects a cancellation when less than 24 h remain, keeps status "Registered" and shows "Cancellation closed"; otherwise sets "Cancelled" and frees one seat | ST-12a: cancel request at start − 24 h -> accepted, seat count +1. ST-12b: request at start − 24 h + 1 s -> rejected, status unchanged, seat count unchanged |
| Architecture design | ARCH-12: `RegistrationService::cancel()` asks `CancellationPolicy::canCancel()`, then updates `Registration` status and `Event` seat count | IT-12a: service + policy + in-memory repo, now = start − 24 h -> status Cancelled, seats +1. IT-12b: now = start − 24 h + 1 s -> status Registered, seats unchanged |
| Module design | MOD-12: `canCancel(now, start)` in include/clubhub/CancellationPolicy.hpp | UT-12a: now = start − 24 h -> true. UT-12b: now = start − 24 h + 1 s -> false (boundary). UT-12c: now = start − 7 days -> true. UT-12d: now = start + 1 h -> false |

Boundary values: exactly 24 h (allowed) and one second less (rejected).
Open question for client: is "exactly 24 h" allowed? (Code currently says yes.)