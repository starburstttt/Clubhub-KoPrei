| SC | Name | Principle | Level | Screen | How we meet it | How we test it |
|----|------|-----------|-------|--------|----------------|----------------|
| 1.1.1 | Non-text Content | Perceivable | A | event list | logos/icons have alt text, decorative ones empty alt | screen reader pass |
| 1.3.1 | Info and Relationships | Perceivable | A | registration form | every input has a visible label, errors linked via aria-describedby | inspect DOM, run axe |
| 1.4.1 | Use of Color | Perceivable | A | event list / CLI | status shown as text tag, e.g. [CANCELLED] | grayscale mode view |
| 1.4.3 | Contrast (Minimum) | Perceivable | AA | both | text ≥ 4.5:1, large text ≥ 3:1 | WebAIM contrast checker |
| 1.4.11 | Non-text Contrast | Perceivable | AA | registration form | borders/buttons ≥ 3:1 | WebAIM contrast checker |
| 2.1.1 | Keyboard | Operable | A | both | everything reachable by Tab/Enter/Space | unplug mouse, finish a registration |
| 2.4.7 | Focus Visible | Operable | AA | both | 2px focus outline on all controls | tab through every control |
| 2.4.11 | Focus Not Obscured (Minimum) | Operable | AA | event list | scroll-padding so sticky header never hides focus | tab down list with header showing |
| 2.5.7 | Dragging Movements | Operable | AA | event list | no drag-only actions, buttons instead | check each gesture has a click alternative |
| 2.5.8 | Target Size (Minimum) | Operable | AA | registration form | buttons/checkboxes ≥ 24×24 px (aim 44) | measure in dev tools |
| 3.1.1 | Language of Page | Understandable | A | both | lang attribute set | axe check |
| 3.2.6 | Consistent Help | Understandable | A | both | help link in same place on every screen | compare screens side by side |
| 3.3.1 | Error Identification | Understandable | A | registration form | error names the field and the problem | submit empty form |
| 3.3.7 | Redundant Entry | Understandable | A | registration form | name/student ID prefilled, never asked twice | do two registrations in a row |
| 3.3.8 | Accessible Authentication (Minimum) | Understandable | AA | login | paste + password manager allowed, no CAPTCHA | paste into password field |
| 4.1.2 | Name, Role, Value | Robust | A | both | native elements first, ARIA only if needed | axe + screen reader |
| 4.1.3 | Status Messages | Robust | AA | registration form | confirmation uses role="status" | screen reader announces without focus move |