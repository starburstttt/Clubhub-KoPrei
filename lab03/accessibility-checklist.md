# Accessibility checklist · ITC Club Hub

Target: WCAG 2.2 level AA · Version 0.2 · 2026-11-10 · Authors: Cheng Varyroitanak

We wrote this before the web and mobile screens exist, so it is a plan and not a test report. The point is to decide now what "accessible" means for Club Hub, because fixing a low-contrast button after it is built costs more than choosing a better colour today. Rows marked 🆕 are new in WCAG 2.2. We did not know several of those before this lab.

**P** = Perceivable · **O** = Operable · **U** = Understandable · **R** = Robust

## 1. Criteria we will meet

| SC | Name | Principle | Level | Screen | How we meet it | How we test it |
|----|------|-----------|-------|--------|----------------|----------------|
| 1.1.1 | Non-text Content | P | A | event list | Club logos get alt text with the club name. Decorative icons get empty alt so screen readers skip them. | Go through the list with a screen reader (NVDA on laptop, TalkBack on phone) |
| 1.3.1 | Info and Relationships | P | A | registration form | Every input has a visible label. Error messages are linked to their field with `aria-describedby`. | Inspect the DOM and run axe |
| 1.4.1 | Use of Color | P | A | event list, CLI | Status is always a word, like `[CANCELLED]` or "Full". Colour only repeats it. | Switch the screen to grayscale and check we can still read every status |
| 1.4.3 | Contrast (Minimum) | P | AA | event list, registration form | Text is at least 4.5:1, large text at least 3:1. Real numbers are in section 2. | WebAIM contrast checker |
| 1.4.11 | Non-text Contrast | P | AA | registration form | Input borders, buttons and the focus outline are at least 3:1 against the background. | WebAIM contrast checker |
| 2.1.1 | Keyboard | O | A | event list, registration form | Everything works with Tab, Enter and Space. | Unplug the mouse and register for an event |
| 2.4.7 | Focus Visible | O | AA | event list, registration form | A 2px outline on every control that can take focus. | Tab through every control and look for the outline |
| 2.4.11  | Focus Not Obscured (Minimum) | O | AA | event list | The sticky header uses `scroll-padding`, so the focused event is never hidden behind it. | Tab down a long list with the header showing |
| 2.5.7  | Dragging Movements | O | AA | event list | No action needs dragging or swiping. Everything has a button. | List every gesture and check it has a click alternative |
| 2.5.8  | Target Size (Minimum) | O | AA | registration form | Buttons and checkboxes are at least 24×24 px. We aim for 44 px because students use phones. | Measure in the browser dev tools |
| 3.1.1 | Language of Page | U | A | event list, registration form | `lang="en"` on the page, and `lang="km"` on Khmer text. | Run axe |
| 3.2.6 | Consistent Help | U | A | event list, registration form | The "Help / contact the organiser" link is in the same place on every screen. | Put screenshots of the screens side by side |
| 3.3.1 | Error Identification | U | A | registration form | An error names the field and says what is wrong, for example "Email needs an @". | Submit an empty form and read the messages |
| 3.3.7  | Redundant Entry | U | A | registration form | Name and student ID are prefilled from the profile. We never ask twice. | Register for two events in a row |
| 3.3.8  | Accessible Authentication (Minimum) | U | AA | login | Pasting and password managers are allowed. No CAPTCHA puzzles or memory tests. | Paste into the password field and try a password manager |
| 4.1.2 | Name, Role, Value | R | A | event list, registration form | Use native HTML elements first. Add ARIA only where HTML can't do the job. | Run axe, then try it with a screen reader |
| 4.1.3 | Status Messages | R | AA | registration form | "You are registered" uses `role="status"`. | Check that a screen reader reads it out without moving focus |

## 2. Two screens in detail

We picked the **event list** and the **registration form**. Students will use both every time, and they cover the two main risks: reading information (the list) and entering it (the form).

Required ratios: **4.5:1** for normal text, **3:1** for large text and UI components. We calculated all ratios with the WCAG formula.

### Screen A: Event list

**Decisions**

1. **Status is a word, and colour only repeats it.** A student who can't tell red from green should still read `CANCELLED`. This is also rule 1 in our CLI output rules.
2. **Dates are written in full**, like `2026-10-14 17:30`. "Tomorrow" is wrong the day after, and `10/11` means different dates in different countries.
3. **The whole event row is clickable and at least 44 px tall.** Small tap targets are hard on a phone, and a row is easier to hit than a tiny link.

| Element | Text | Background | Ratio | Needs | Pass |
|---------|------|------------|-------|-------|------|
| Body text | `#1F2937` | `#FFFFFF` | 14.68:1 | 4.5:1 | ✅ |
| Secondary text | `#595959` | `#FFFFFF` | 7.00:1 | 4.5:1 | ✅ |
| OPEN badge | `#166534` | `#FFFFFF` | 7.13:1 | 4.5:1 | ✅ |
| FULL badge | `#B45309` | `#FFFFFF` | 5.02:1 | 4.5:1 | ✅ |
| CANCELLED badge | `#B91C1C` | `#FFFFFF` | 6.47:1 | 4.5:1 | ✅ |

The FULL badge is the closest to the limit at 5.02. We kept it because a lighter orange fails the 4.5 line.

### Screen B: Registration form

**Decisions**

1. **Labels sit above the inputs and stay visible.** Placeholder text disappears when you type, so it can't be the only label.
2. **Errors show next to the field and in a summary at the top**, with text and an icon. Red alone would break the colour rule.
3. **Name and student ID are prefilled** from the profile. Typing the same details twice is tiring and easy to get wrong.

| Element | Colour | Background | Ratio | Needs | Pass |
|---------|--------|------------|-------|-------|------|
| Button text | `#FFFFFF` | `#1D4ED8` | 6.70:1 | 4.5:1 | ✅ |
| Input border | `#767676` | `#FFFFFF` | 4.54:1 | 3:1 | ✅ |
| Focus outline | `#1D4ED8` | `#FFFFFF` | 6.70:1 | 3:1 | ✅ |
| Error text | `#B91C1C` | `#FFFFFF` | 6.47:1 | 4.5:1 | ✅ |

## 3. What we are unsure about

- We don't have a login screen in our plan yet. The 3.3.8 row is there so we don't forget it if one is added.
- We haven't tested how Khmer text looks at 200 % zoom. Khmer script is taller than Latin text, so we'd check it before we build.
- All of this is checked on paper. Once a prototype exists, we'd run axe and a keyboard-only test and update this file.

## 4. Acceptance checklist

- [x] 17 criteria covering all four POUR principles
- [x] All six WCAG 2.2 additions included, each with a test method
- [x] Two screens with three design decisions each
- [x] Contrast ratios recorded, and every one meets AA
- [ ] Ratios re-checked in the WebAIM contrast checker