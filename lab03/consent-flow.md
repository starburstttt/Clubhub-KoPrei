# Consent Flow · ITC Club Hub
clubhub register ──┐
                   ├─> Enter ID, name, email + notice link
Web form ──────────┘            │
                                v
                   Email reminders? (default: no)
                      │yes                │no
                      v                   │
           setEmailReminders(true)        │
                      └────────┬──────────┘
                               v
                   SMS reminders? (default: no)
                      │yes                │no
                      v                   │
          Ask phone -> giveSmsConsent()   │
                      └────────┬──────────┘
                               v
                        Account created
                               ┆
                               v
        Withdraw (clubhub consent withdraw / web settings)
              │                              │
              v                              v
   withdrawSmsConsent()           setEmailReminders(false)
      (phone erased)                         │
              └──────────────┬───────────────┘
                             v
                  Account still active