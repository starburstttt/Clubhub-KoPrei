# Fundamental activities · Team KoPrei · v2.0 (2026-11-13)

| Activity                  | What happens in Club Hub | Who leads (role, name) | Weeks | Artifact | Done when |
|---------------------------|--------------------------|------------------------|-------|----------|-----------|
| Specification             | Interview the client and club officers about registering and cancelling; write user stories for register, cancel and "seats left"; define the capacity, duplicate and 24 h cancellation rules as testable requirements | Product Owner, CHENG Varyroitanak | 5-6 | lab05/srs.md, product backlog (GitHub issues) | the TA approved the SRS by email and every Must story has acceptance criteria |
| Design and implementation | Design the architecture, data model and screens for register, cancel and “seats left”; implement the capacity, duplicate and 24 h cancellation rules as code; build Sprint 1 and Sprint 2 stories through pull requests that a teammate reviews                     | Scrum Master, Tang Hengly | 7-12 | design document (lab06/design.md), source code in the GitHub repo, merged pull requests | every Must story is merged to main through a reviewed pull request, the build passes, and the design document matches the code |
| Validation                | Write GoogleTest unit tests for capacity, duplicate registration and 24 h cancellation rules; perform integration testing for registering and cancelling; conduct peer reviews of pull requests; demonstrate the register, cancel and "seats left" features during sprint reviews.               | Scrum Master, PHO Phatsophal                 | 9 - 12  | tests/CI run history     | Every story must pass the tests in CI, all rules are followed strictly and correctly, and the TA accepts the demonstration      |
| Evolution                 | Triage change requests from sprint reviews (e.g. "seats left" in the event list); update the SRS, code and tests for each accepted change; fix bugs found in the final demo; record every change and tag the release | Developer, Sounghan Sethaleaph | 11-16 | CHANGELOG.md, issues labelled change-request, git tag v1.0 | each accepted change is in CHANGELOG.md with updated tests, and v1.0 is tagged and demoed to the TA |
## Sub-activities and ISO/IEC/IEEE 12207 processes
- Specification: elicitation, analysis, specification, validation of requirements · 12207: Stakeholder needs and requirements definition, System/software requirements definition
- Design and implementation: architectural design, detailed design (data model, screens, business rules), coding, unit testing, code review · 12207: Architecture definition, Design definition, Implementation

- Validation: Unit testing, Integration testing, system testing, acceptance testing, verification
- Evolution: change-request triage, impact analysis, modification with regression testing, release and tagging · 12207: Maintenance, Transition


## Overlaps and loops
1. Week 10: the Sprint 1 review shows the client wants "seats left" in the event list -> new story US-21 -> specification again in week 11.
2. Weeks 9-12: design and validation interleave daily: each pull request contains code and its tests, reviewed before merge.
3. Weeks 12-13: a bug found in the demo (e.g. a 24 h cancellation edge case) goes back to evolution as a change request, then to implementation and validation again with a new regression test.