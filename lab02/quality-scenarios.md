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

## QAS-03 · Usability · written by Suonghan Sethaleaph


| Part | Content |
|------|---------|
| **Source** |A first-time student user (has never used Club Hub) |
| **Stimulus** |Wants to find a club event and register for it, without a tutorial or help from anyone |
| **Environment** |Normal operation, on a mobile phone (screen width 360-412 px), mobile data, during the first week of the semester |
| **Artifact** |Event browsing and registration pages of the web front end |
| **Response** |The student finds the event from the home page, registers in a few clear steps, and sees a confirmation message. If they make a mistake (e.g., an empty required field), the system shows a clear error message next to the field and keeps the data already entered. |
| **Response measure** |In a usability test with at least 10 first-time students: >= **90%** complete registration without help, in <= **60 s** on average and <= **4 steps** from the home page to confirmation. Error rate is <= **1 error per registration**, and the average satisfaction score is >= **4/5** (or SUS >= 70). |

## QAS-04 · Security · written by Suonghan Sethaleaph


| Part | Content |
|------|---------|
| **Source** |An unauthorized external user (an attacker, or a student trying to act as another student) |
| **Stimulus** |Attempts to access or change another student's registration data, by guessing passwords (brute force) or by changing the ID in a request URL |
| **Environment** |Normal operation, public internet, during the Friday 18:00-21:00 peak window, with up to 3,000 legitimate students online |
| **Artifact** |Authentication module, registration service, and the database holding student data |
| **Response** |The system checks the identity and permissions of every request, and denies access to data that does not belong to the requester. After repeated failed logins, it locks the account temporarily and notifies the user. All attempts are logged, and the administrator is alerted. Data is encrypted in transit (HTTPS) and passwords are stored hashed. |
| **Response measure** |In a security test: **100%** of unauthorized access attempts are blocked, with **0** records exposed. The account is locked after **5** failed logins within 10 minutes. Suspicious attempts appear in the log within **1 min** and the admin is alerted within **5 min**. No critical or high-severity vulnerabilities remain in the OWASP Top 10 scan before release. |

## QAS-05 · Modifiability · written by Hengly


| Part | Content |
|------|---------|
| **Source** | A system developer / maintainer |
| **Stimulus** | Requests the integration of a new third-party payment/ticketing gateway for paid campus events |
| **Environment** | Development and staging environments during a scheduled maintenance/feature release window |
| **Artifact** | Registration and payment backend module architecture |
| **Response** | The developer adds the new payment provider implementation using existing abstraction interfaces without modifying core event registration logic or breaking existing APIs. |
| **Response measure** | Implementation and unit test coverage completed within <= 2 person-days; 0 changes required in core registration components; all automated regression tests pass on the first CI/CD run. |

## QAS-06 · Portability · written by Pho Phatsophal 


| Part | Content |
|------|---------|
| **Source** |Students and club organizers using different devices and operating systems |
| **Stimulus** |A student registers for an event on a phone, an organizer checks in attendees on a phone, or an administrator accesses reports on a desktop computer. |
| **Environment** |Friday 18:00, registration opens; 200 arrivals within 10 minutes; approximately 3,000 students use Android or iPhone devices, organizers use phones at entrances with weak or unavailable Wi-Fi, and 2–3 administrators use desktop PCs on a stable office network. |
| **Artifact** |Club Hub PWA, responsive user interface, service worker, local offline check-in queue, and desktop administration interface. |
| **Response** |The PWA works on supported Android and iPhone browsers without requiring installation from an app store. The desktop interface supports administrative reports and club approvals. Organizers can record check-ins while offline, store them locally, and synchronise them when connectivity returns. |
| **Response measure** |100% of compatibility test cases pass on the agreed Android and iPhone browser configurations and desktop browser configurations. Verify event browsing, registration, and confirmation on mobile; administrative reports and approvals on desktop; and offline check-in with successful synchronization after reconnection. Complete 20 consecutive offline check-ins without network access, then reconnect and verify that all 20 records synchronize correctly, with 0 lost records and 0 duplicate attendance records. |

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
