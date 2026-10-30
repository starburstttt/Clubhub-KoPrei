# Lab-02 · Quality attribute scenarios for ITC Club Hub

Version 1.0 · 2026-10-27 · Reviewed by Cheng Varyroitanak (10-27-2026) -- [Pls update this to Version 2.0 IF you update this file]

---

## QAS-01 · Availability · written by CHENG Varyroitanak

| Part | Content |
|------|---------|
| **Source** | A student |
| **Stimulus** | Opens Club Hub and registers for an event the moment registrations open |
| **Environment** | Friday 18:00-21:00, normal operation, peak traffic (up to 3,000 students), mobile data |
| **Artifact** | Registration service and web front end |
| **Response** | The registration is processed and the confirmation is shown. If a server process crashes, it restarts automatically and requests keep being served. |
| **Response measure** | Availability >= **99.5%** per month, which allows 0.5% x 30 days x 24 h x 60 min = **216 min** of downtime per month. In the Friday 18:00-21:00 window it is >= **99.9%**, which allows 180 min x 0.1% = **about 11 s** of downtime per window. |

## QAS-02 · Performance of check-in at the door · written by CHENG Varyroitanak

| Part | Content |
|------|---------|
| **Source** | An organiser at the door |
| **Stimulus** | Scans the QR code of arriving students: 200 arrivals in 10 minutes at one entrance (600 s / 200 = one scan every **3 s** on average) |
| **Environment** | Amphi A, Wi-Fi weak or down, one phone running the PWA, peak arrival period |
| **Artifact** | PWA check-in screen and the local check-in queue |
| **Response** | The check-in is stored on the phone and the green tick is shown without waiting for the network. The queue syncs when the network is back. |
| **Response measure** | Green tick within **1 s** for >= **95%** of scans, even with 0 network. Sustained rate >= **20 scans/min** per phone (200 / 10 min). All queued check-ins uploaded within **30 s** after the network returns. |

## QAS-03 · Usability · written by Hengly


| Part | Content |
|------|---------|
| **Source** | A newly onboarded student club executive |
| **Stimulus** | Attempts to create a new event, configure registration fields, and publish the event listing |
| **Environment** | First-time use during normal operations, desktop browser, without prior training or consulting documentation|
| **Artifact** | Club administration interface and event creation workflow |
| **Response** | The interface guides the user through required fields with inline validation, clear error feedback, and pre-filled defaults |
| **Response measure** | Task completion rate >= 90% on the first attempt without external assistance; total time to configure and publish an event <= 5 minutes; user error rate <= 1 critical error per session |

## QAS-04 · Security · written by __


| Part | Content |
|------|---------|
| **Source** | |
| **Stimulus** | |
| **Environment** | |
| **Artifact** | |
| **Response** | |
| **Response measure** | |

## QAS-05 · Modifiability · written by __


| Part | Content |
|------|---------|
| **Source** | A system developer / maintainer |
| **Stimulus** | Requests the integration of a new third-party payment/ticketing gateway for paid campus events |
| **Environment** | Development and staging environments during a scheduled maintenance/feature release window |
| **Artifact** | Registration and payment backend module architecture |
| **Response** | The developer adds the new payment provider implementation using existing abstraction interfaces without modifying core event registration logic or breaking existing APIs. |
| **Response measure** | Implementation and unit test coverage completed within <= 2 person-days; 0 changes required in core registration components; all automated regression tests pass on the first CI/CD run. |

## QAS-06 · Portability · written by __


| Part | Content |
|------|---------|
| **Source** | |
| **Stimulus** | |
| **Environment** | |
| **Artifact** | |
| **Response** | |
| **Response measure** | |

---

## Priorities

| Scenario | Business importance | Technical risk | Protects | First? |
|----------|:---:|:---:|----------|:---:|
| QAS-01 Availability | H | M | Students (Friday peak) | |
| QAS-02 Check-in performance | H | H | Organisers (door, no Wi-Fi) | |
| QAS-03 Usability | | | | |
| QAS-04 Security | | | | |
| QAS-05 Modifiability | | | | |
| QAS-06 Portability | | | | |
>>>>>>> ff7c612895ea31d6fc204e85c20f483564ef87b1
