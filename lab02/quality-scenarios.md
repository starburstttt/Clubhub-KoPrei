# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-23-10 · Reviewed by (Scrum Master): Hengly

## QAS-01 · Availability · written by Hengly
| Part | Content |
|---|---|
| Source | Cloud hosting infrastructure / Hardware failure |
| Stimulus | Primary database or API application container crashes |
| Environment | Friday 18:00, registration opens, 500 active concurrent student sessions on a 4G mobile network |
| Artifact | ITC Club Hub core backend application & main database service |
| Response | System automatically detects failure via health check, routes traffic to a failover replica, and restores full service |
| Response measure | Target availability: 99.9% monthly uptime. Downtime limit: (1 - 0.999) x 30 x 24 x 60 = 43.2 minutes/month. Maximum Recovery Time Objective (RTO) < 30 seconds per incident. |

## QAS-02 · Performance of check-in at the door · written by Hengly
| Part | Content |
|---|---|
| Source | Event Organiser / Door Staff |
| Stimulus | Organiser scans a student's digital check-in QR code at the entrance |
| Environment | Event doorway during peak arrival window: 200 student arrivals in 10 minutes (20 scans/min) on campus Wi-Fi |
| Artifact | Check-in scanner module and API endpoint |
| Response | System validates ticket signature, updates attendance status in DB, and displays confirmation badge to organiser |
| Response measure | Latency p95 <= 1.5 seconds per check-in scan. 0% duplicate entry processing errors allowed across all 200 attendees. |

## QAS-03 · Usability · written by Hengly
| Part | Content |
|---|---|
| Source | First-time student user |
| Stimulus | User attempts to find a specific club and submit a membership registration form |
| Environment | Mobile web browser (Chrome on Android / Safari on iOS) on 3G network without prior training or user manual |
| Artifact | Club discovery directory & registration workflow interface |
| Response | System provides clear navigation, pre-filled student ID fields, and instant input validation feedback |
| Response measure | Completed in <= 3 taps from homepage to submission form. 90% of first-time users complete registration in <= 90 seconds without triggering validation errors. |

## QAS-04 · Security · written by Hengly
| Part | Content |
|---|---|
| Source | Unauthenticated malicious student / Unauthorized external actor |
| Stimulus | Attacker attempts SQL injection / IDOR endpoint manipulation to access private student phone numbers and attendance records |
| Environment | Production environment during normal web operation over HTTPS connection |
| Artifact | User authentication service, API gateway, and Postgres database holding PII (student IDs, full names, phone numbers) |
| Response | System blocks unauthorized request via parameter sanitization and JWT validation, logs security alert, and hides PII |
| Response measure | 0 records leaked or exposed. Unauthorized API request returns HTTP 403/401 within <= 100 ms. Security audit log entry created in <= 1 second. |

## QAS-05 · Modifiability · written by Hengly
| Part | Content |
|---|---|
| Source | Software Developer / Maintainer |
| Stimulus | Developer receives a request to add a new "Telegram notification" feature for event updates |
| Environment | Development environment during sprint cycle, codebase using modular architecture |
| Artifact | Event notification service and webhooks integration layer |
| Response | Developer adds Telegram API integration without altering core database schema or event core modules |
| Response measure | Changes isolated to <= 3 files altered. Total development and verification effort <= 2 days of work (16 person-hours). Regression test suite maintains 100% pass rate. |

## QAS-06 · Portability · written by Hengly
| Part | Content |
|---|---|
| Source | System Administrator / QA Engineer |
| Stimulus | Deploying and verifying web application compatibility across target client browsers and mobile OS platforms |
| Environment | Target browser matrices: Chrome v115+, Safari v16+, Firefox v115+ on iOS 16+, Android 12+, and macOS/Windows 11 |
| Artifact | Frontend single-page application assets and responsive UI layout |
| Response | Web app renders responsively without layout breakages, console JS errors, or feature loss across tested devices |
| Response measure | 100% pass rate across standard automated browser matrix tests. Zero broken layouts or unhandled JS exceptions across all 6 targeted browser/OS combinations. |

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01 | High | High | General users & event continuity | Yes |
| QAS-02 | High | High | Event organizers & entry flow | Yes |
| QAS-03 | Medium | Low | First-time student users | No |
| QAS-04 | High | Medium | Student personal data (PII) | No |
| QAS-05 | Low | Medium | Development team & maintainability | No |
| QAS-06 | Medium | Low | Cross-platform student user base | No |