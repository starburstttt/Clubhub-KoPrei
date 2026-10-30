# Lab-02 · Classification of five applications

Version 1.0 · 2026-10-27 · Team: KoPrei

| # | Application | Kind | Type(s) | Where the code runs, how it is delivered | Architecture | Top 3 qualities (why) | Filled by |
|---|-------------|------|---------|------------------------------------------|--------------|-----------------------|-----------|
| 1 | **Mobile banking app: ABA Mobile** | Application | Mobile native<br>Enterprise (financial) | **Phone:** app store<br>**Servers:** bank data centre (API + core banking) | Client-server, three-tier<br>*App only displays; balances and transfers live on the server* | **1. Security:** if an account is hijacked, money is stolen<br>**2. Availability:** if down, users cannot pay or transfer<br>**3. Usability:** if confusing, users send money to the wrong account | Pho Phatsophal |
| 2 | **Telegram** | Application | Mobile native + desktop + web<br>Cloud SaaS (messaging) | **Phone, PC:** store or installer<br>**Browser:** URL<br>**Servers:** Telegram data centres | Client-server<br>*Chats sync across devices because the server holds the state* | **1. Availability:** if down, people cannot reach each other<br>**2. Performance:** if messages arrive late, chat feels broken<br>**3. Security:** if private chats leak, users lose trust | Tang Hengly |
| 3 | **ABS controller in a car** | System software | Embedded real-time | **ECU in the car:** installed at the factory<br>**Updates:** at a dealer or over the air | Embedded control loop<br>*Wheel-speed sensors → ECU → brake valves, many times per second* | **1. Safety:** if it fails, wheels lock and the car skids<br>**2. Performance (timing):** if the reaction is late, it cannot prevent the skid<br>**3. Availability:** must work on every brake press, falls back to normal braking | Suonghan Sethaleaph |
| 4 | **Moodle at ITC** | Application | Web MPA<br>Enterprise (LMS) | **Browser:** URL<br>**Server:** ITC web server + database | Three-tier<br>*Browser → web server → database* | **1. Availability:** if down during an online quiz, students cannot submit<br>**2. Performance:** if slow when hundreds submit at once, answers get lost<br>**3. Security:** if grades can be changed, results are not trustworthy | Yen chhavorn |
| 5 | **Game: Mobile Legends: Bang Bang** | Application | Game<br>Mobile native<br>Online multiplayer | **Phone:** app store<br>**Servers:** game servers run the matches | Client-server<br>*Server connects the 10 players of a match, so it needs a connection* | **1. Performance:** if lag spikes, you lose the match<br>**2. Availability:** if servers are down, nobody can play ranked<br>**3. Security:** if an account is stolen, you lose skins and rank | CHENG Varyroitanak |

## Biggest difference we found

The ABS controller has hard deadlines and a safety risk, so a late answer is a failure that can hurt people. Telegram, Moodle and the game tolerate a slow or lost moment and can just retry, so they are much more forgiving.

## Quadrant chart

See [app-quadrant.mmd](app-quadrant.mmd).