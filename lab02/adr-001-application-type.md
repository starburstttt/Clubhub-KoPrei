# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-10-23 · Status: Proposed (ACCEPTED!) · Deciders: KoPrei

## Context
Club events at ITC are announced in scattered chat groups. About 3,000 students on Android or iPhone need to browse and register, organisers need to check people in at doors with weak Wi-Fi, and 2-3 administrators need desktop reports and club approvals. We are a team of 4-5 with one semester.git g

## User groups
| Group          | Device | Where | Connectivity | How often | Must never fail |
|----------------|--------|-------|--------------|-----------|-----------------|
| Students (~3,000) | Android / iPhone | anywhere on campus, at home | mobile data, often weak | a few times a week; peak Friday evening when registration opens | registering for an event without double booking or exceeding capacity |
| Organisers (club leaders + helpers) | 1-2 phones per door | room or hall entrance | weak or overloaded Wi-Fi | each event (5-15 per week), 200 arrivals in 10 min | check-in at the door, even with no network |
| Administrators (2-3 staff) | desktop PC | student affairs office | stable office network | monthly reports, club approvals | accurate monthly activity report and approvals |

## Options
A. Native apps (Android + iOS)
B. Cross-platform app (one codebase, installed from the stores)
C. PWA for students and organisers, same web app on desktop for administrators
D. Responsive web app only (no offline support)

## Weighted comparison (score 1-5 x weight)
| Criterion (weight) | why this weight | A native | B cross-platform | C PWA + web | D web only |
|---|---|---|---|---|---|
| Cost for our team in one semester (3) | 5 people, 15 weeks, and the C++ core must be built too | 1 x 3 = 3 | 3 x 3 = 9 | 4 x 3 = 12 | 5 x 3 = 15 |
| Reach (3) | 3,000 students on two platforms; no install friction means more registrations | 3 x 3 = 9 | 3 x 3 = 9 | 5 x 3 = 15 | 5 x 3 = 15 |
| Offline check-in at the door (3) | the door has weak Wi-Fi and a 10-minute peak; this is the riskiest need | 5 x 3 = 15 | 4 x 3 = 12 | 4 x 3 = 12 | 1 x 3 = 3 |
| Reminders (2) | important, but e-mail is a fallback | 5 x 2 = 10 | 5 x 2 = 10 | 3 x 2 = 6 | 2 x 2 = 4 |
| Admin reports and approvals on desktop (1) | only 2-3 users, once a month | 1 x 1 = 1 | 2 x 1 = 2 | 4 x 1 = 4 | 5 x 1 = 5 |
| **Total (max 60)** | | 3+9+15+10+1 = **38** | 9+9+12+10+2 = **42** | 12+15+12+6+4 = **49** | 15+15+3+4+5 = **42** |

Deal-breaker check: "check-in must work without Wi-Fi". D fails it. C passes only if we add a service worker and a local queue that stores check-ins on the phone and syncs later (see the challenge). So we keep C and make that offline queue a must-have.

## Decision
We choose option C: one PWA for students and organisers, with an offline check-in queue, and the same web app on desktop for administrators. Reminders go by e-mail for everyone, plus push where the platform allows it.

## Consequences
+ One codebase for all three user groups, which fits one semester.
+ Students open a link, with no store install, so reach is highest.
+ Check-in keeps working through Wi-Fi drops thanks to the local queue.
+ Administrators need nothing installed; reports are just web pages.
- iPhone users get push reminders only after adding the PWA to the home screen, so e-mail stays the main reminder channel.
- The offline queue brings sync conflicts (same student scanned at two doors, retries), which we must design and test.
- A PWA has less access to device features than a native app, for example for QR scanning performance on old phones.

## Rejected options
A. Native apps: two front ends (plus an admin one) is too much for a 5-person team in one semester.
B. Cross-platform app: still needs store publishing and installs, so reach and cost are worse than a PWA, and we gain only slightly on reminders.
D. Responsive web only: fails the deal-breaker, because check-in stops when the Wi-Fi drops.

## How the front ends reach the C++ core
In production the core (`include/clubhub/`, `src/`) would sit behind an HTTP API (REST + JSON), and the PWA would call that API. In this course there is no web front end, so the C++ CLI (`src/cli/`) calls the core directly. Because the core never prints and never opens files by name, adding the HTTP layer later means a new executable that links the same core library.