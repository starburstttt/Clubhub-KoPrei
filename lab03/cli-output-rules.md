1. **Never colour alone.**
   Why : colour-blind users and plain-text logs lose the meaning.
   bad : `E-017  Git Workshop` (shown in red)
   good: `E-017  Git Workshop      [CANCELLED]`

2. **Honour NO_COLOR and --no-color.**
   Why : piped output and screen readers choke on escape codes.
   bad : always prints `\033[31m...`
   good: `NO_COLOR=1 clubhub list` prints plain text

3. **Say what failed, why, and the next step.**
   Why : the user can fix it without reading the source.
   bad : `ERR_CAP`
   good: `Error: cannot register for E-017: the event is full (40 of 40 seats).`
         `Next step: clubhub waitlist E-017`

4. **Non-zero exit code on error.**
   Why : scripts and CI depend on it to detect failure.
   bad : prints "Error: ..." and exits 0
   good: prints the error and exits 1

5. **Prompts state the expected format.**
   Why : guessing the format causes input errors.
   bad : `Date?`
   good: `Event date (YYYY-MM-DD HH:MM, e.g. 2026-10-14 17:30):`

6. **Unambiguous dates.**
   Why : 10/11 means different days in different countries.
   bad : `14/10/26`
   good: `2026-10-14 17:30`