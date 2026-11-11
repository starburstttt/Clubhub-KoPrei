# Retention rules · ITC Club Hub
Version 0.1 · 2026-11-11 · Author: Suonghan Sethaleaph

| Field | Trigger | Action | Who / what runs it | How to verify |
|-------|---------|--------|--------------------|---------------|
| studentId | 6 months after graduation | delete | `clubhub purge`, monthly | purge dry-run lists 0 expired IDs; grep students.csv for the ID |
| name | 6 months after graduation | delete | `clubhub purge`, monthly | same dry-run; row no longer in students.csv |
| email | 6 months after graduation | delete | `clubhub purge`, monthly | same dry-run; email absent from students.csv |
| phone | consent withdrawn, or 6 months after graduation | delete | `withdrawSmsConsent()` at once; `clubhub purge` for graduates | test: phone() is empty after withdrawal; column empty in students.csv |
| emailReminders flag | account deleted | delete | `clubhub purge`, monthly | flag gone with the student row |
| clubMemberships | membership ends or student leaves club | delete | club leader action; `clubhub purge` | memberships.csv has no row for that pair |
| attendance | 1 academic year after the event | aggregate (keep counts only) | `clubhub purge`, monthly | registrations.csv has no studentId for old events; only counts remain |