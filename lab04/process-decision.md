# PDR-001 · Development process for ITC Club Hub
Status: Proposed | Accepted | Superseded by PDR-001
Date: 2026-11-18        Deciders: <all members>

## Context
1. **Team size and weekly hours:** The project is developed by a small team of 5 members. The team's available working hours are 2 hours together weekly. However, each team member completes theri own task individually with their spare time. (source: lab01/team-charter.md)
2. **Client availability:** The client is available for consultation and feedback. (source: project brief)
3. **Fixed milestones:** The project has two important milestones: Checkpoint 1 in Week 8 and final submission in Week 14. (source: project brief)
4. **Requirements clarity:** The initial requirements are clear. Some requirements may need clarification during development. (source: problem statement)
5. **Technical experience:** The team has experience with C++, CMake, Git, and collaborative software development. The team's experience with iterative development and automated testing may vary. (source: team feedback)

## Options considered
| Option                       | Weighted score (Task 2) | Pro | Con |
|------------------------------|------------------------:|-----|-----|
| A. Waterfall                 |4.25                     | Provides clear development phases, structured documentation, and predictable planning for the Week 14 deadline. | Less flexible when requirements change after a development phase has been completed. |
| B. Incremental delivery      |3.85                     | Delivers working features in smaller parts, allowing earlier testing and feedback. | Requires careful planning and integration between increments. |
| C. Scrum-style iterative     |3.55                     | Encourages teamwork, frequent feedback, and continuous improvement through regular reviews. | Requires frequent meetings and coordination, which may be difficult with the team's available time and experience. |
| D. No defined process        | n/a                     | Provides flexibility and requires little process documentation. | Can lead to unclear responsibilities, poor coordination, inconsistent progress, and missed deadlines. |

## Decision
We will use the **Waterfall development model** because it received the highest weighted score in Task 2, with **4.25/5**. Waterfall is suitable for ITC Club Hub because the project has fixed milestones in Week 8 and Week 14, and the team needs clear requirements, documentation, and a planned development schedule.

Although Waterfall is less flexible when requirements change, we will reduce this risk by discussing requirements with the client early and reviewing important deliverables at each checkpoint.

| Element | Reference practice | Our tailoring | Reason |
|---------|--------------------|---------------|--------|
| Up-front work | Gather and document requirements before development begins. | Define and confirm the main requirements during Weeks 5–6. | Reduces misunderstandings and gives the team a clear direction. |
| Iteration length | Development proceeds through sequential phases rather than short sprints. | Follow semester-based phases, with progress reviewed at the Week 8 checkpoint. | Matches the fixed academic milestones. |
| Meetings | Meetings are held at important project stages and milestones. | Hold regular short team meetings and client discussions when clarification is needed. | Keeps everyone informed without spending too much time in meetings. |
| Roles | Team members have responsibilities based on project activities. | Product Owner manages requirements and priorities; Scrum Master coordinates team progress; developers implement features; testers verify the system. | Makes responsibilities clear and avoids duplicated work. |
| Documents | Each phase produces documented outputs before moving to the next phase. | Maintain requirements, design, meeting notes, test results, and decision records in the GitHub repository. | Keeps project information organized and makes changes traceable. |
| Definition of Done | A phase is complete when its planned deliverables satisfy the agreed requirements and are reviewed. | A task is Done when its requirements are met, the work is tested where applicable, reviewed by the team, and committed to GitHub. | Helps maintain consistent quality and prevents unfinished work from being treated as complete. |
| Hardening | Final testing, defect fixing, and preparation take place before release. | Reserve Week 13 for integration, bug fixing, testing, and documentation checks before the Week 14 submission. | Provides time to improve reliability before the deadline. |
## Consequences
Positive:
1. **Clear development structure:** The team follows organized phases, making it easier to understand what needs to be completed at each stage.
2. **Better documentation:** Requirements, design decisions, and testing results are recorded, helping team members understand the project.
3. **Easier progress monitoring:** The Week 8 checkpoint and Week 14 deadline provide clear milestones for measuring progress.
4. **More organized testing:** Testing and hardening are planned before submission, helping the team identify and fix problems.
Negative / risks (with mitigation):
1. **Limited flexibility when requirements change:** Waterfall makes major changes more difficult after a phase is completed.  
   **Mitigation:** Discuss requirements with the client early and review important requirements before implementation begins.
2. **Late discovery of defects:** Some problems may only become clear during integration or testing.  
   **Mitigation:** Conduct code reviews and test individual features during implementation instead of waiting until the final testing phase.
3. **Delayed client feedback:** If the client is unavailable, unclear requirements may remain unresolved.  
   **Mitigation:** Arrange client discussions early and record confirmed decisions so the team has a reliable reference.
4. **Integration difficulties:** Features developed separately may not work correctly when combined.  
   **Mitigation:** Agree on interfaces and coding conventions early, and integrate completed components regularly.