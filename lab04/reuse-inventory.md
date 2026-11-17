# Reuse inventory · ITC Club Hub · Team KoPrei

Repository licence (Lab-03): MIT. Decisions: **Reuse** = add as a dependency now, **Build** = write ourselves, **Defer** = decide in a later lab.

## Make-or-reuse table

| Need | Options considered | Decision | Reason | Licence | Pinned version | Last release (maintenance evidence) |
|------|--------------------|----------|--------|---------|----------------|-------------------------------------|
| Unit testing | GoogleTest, Catch2, doctest | Reuse | Already used in Lab-03 (ConsoleOutput and StudentPrivacy tests); native CTest integration through `gtest_discover_tests` | BSD-3-Clause | v1.17.0 | v1.17.0 tagged 2025-04-30 |
| File storage (CSV) | rapidcsv, hand-written parser, SQLite | Reuse | CSV was chosen in Lab-02; rapidcsv is header-only, needs one include, and handles quoting and line endings that a hand-written parser would have to get right. Our own `event_csv.cpp` can move to it in a later lab | BSD-3-Clause | v8.90 | v8.90 tagged 2025-10-18 (GitHub release page) |
| Date and time (24-hour rule) | `std::chrono` (C++20), Howard Hinnant date library | Reuse | `std::chrono` is part of the C++20 standard we already compile with, so there is no new dependency; it is enough for the 24-hour cancellation rule | Part of the C++ standard library | C++20 | n/a (standard) |
| CLI input handling | CLI11, cxxopts, plain `std::getline` menu | Defer | The interface is not final; a simple text menu may be enough, so we avoid a dependency until the need is clear | n/a | n/a | n/a |
| Registration rules | none fits our rules | Build | Unique to Club Hub, graded, and must be covered by our own tests | ours (MIT) | n/a | n/a |
| Reminders | OS scheduler, scheduling library, check-at-startup in our own code | Defer | Depends on the date logic and on whether Club Hub runs continuously; not needed for the core | n/a | n/a | n/a |
| Monthly report | own code over the CSV data, template library | Build | Small and specific to our data; needs the role restriction from Ethics issue #9 | ours (MIT) | n/a | n/a |
| Logging | spdlog, `std::cerr` | Defer | Not needed before the core exists; revisit when we need log levels or log files | n/a | n/a | n/a |

## Licence check

Our repository is MIT. Both reused libraries are BSD-3-Clause, which is permissive and compatible with MIT: we may use, copy and modify them, and combine them with MIT code. We must keep their copyright notice and licence text (FetchContent downloads them together with their LICENSE files), and we must not use the authors' names to promote Club Hub. `std::chrono` is part of the compiler's standard library and adds no licence of its own.

| Library | Licence | Compatible with MIT repo? | What we must do |
|---------|---------|---------------------------|-----------------|
| GoogleTest v1.17.0 | BSD-3-Clause | Yes | Keep the notice if we redistribute it; it is only used for tests |
| rapidcsv v8.90 | BSD-3-Clause | Yes | Keep the notice if we redistribute the header |

A GPL library would be different: if we distributed Club Hub linked with it, the whole combined work would have to be released under the GPL, which conflicts with our MIT licence unless the team deliberately relicenses. That is why we avoid GPL libraries here.

## Verification

Clean build, run from the repository root:

```
rm -rf build
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=/c/msys64/ucrt64/bin/gcc.exe -DCMAKE_CXX_COMPILER=/c/msys64/ucrt64/bin/g++.exe && cmake --build build && ctest --test-dir build --output-on-failure
```

Environment of this run: CMake 4.1.0, g++ 15.2.0 (MSYS2 UCRT64), C++20, Windows.

```
Test project C:/codingfiles/SEClubHub/Clubhub-AIECS/build
      Start  1: ConsoleOutput.StatusIsReadableWithoutColour
 1/11 Test  #1: ConsoleOutput.StatusIsReadableWithoutColour .......   Passed    0.02 sec
      Start  2: ConsoleOutput.ColourOnlyRepeatsTheWord
 2/11 Test  #2: ConsoleOutput.ColourOnlyRepeatsTheWord ............   Passed    0.02 sec
      Start  3: ConsoleOutput.ErrorSaysWhatWhyAndNextStep
 3/11 Test  #3: ConsoleOutput.ErrorSaysWhatWhyAndNextStep .........   Passed    0.02 sec
      Start  4: StudentPrivacy.RedactedHidesPersonalData
 4/11 Test  #4: StudentPrivacy.RedactedHidesPersonalData ..........   Passed    0.02 sec
      Start  5: StudentPrivacy.OptionalConsentsStartOff
 5/11 Test  #5: StudentPrivacy.OptionalConsentsStartOff ...........   Passed    0.02 sec
      Start  6: StudentPrivacy.WithdrawingSmsConsentErasesPhone
 6/11 Test  #6: StudentPrivacy.WithdrawingSmsConsentErasesPhone ...   Passed    0.02 sec
      Start  7: StudentPrivacy.RejectsEmailWithoutAt
 7/11 Test  #7: StudentPrivacy.RejectsEmailWithoutAt ..............   Passed    0.02 sec
      Start  8: StudentPrivacy.RejectsPhoneWithLetters
 8/11 Test  #8: StudentPrivacy.RejectsPhoneWithLetters ............   Passed    0.03 sec
      Start  9: StudentPrivacy.MaskIdHidesShortIdsCompletely
 9/11 Test  #9: StudentPrivacy.MaskIdHidesShortIdsCompletely ......   Passed    0.02 sec
      Start 10: StudentPrivacy.RejectsEmptyIdOrName
10/11 Test #10: StudentPrivacy.RejectsEmptyIdOrName ...............   Passed    0.02 sec
      Start 11: CsvSmokeTest.ReadsEventTitlesAndCapacities
11/11 Test #11: CsvSmokeTest.ReadsEventTitlesAndCapacities ........   Passed    0.02 sec

100% tests passed, 0 tests failed out of 11

Total Test time (real) =   0.26 sec
```

The 11 tests are the 10 tests from Lab-03 plus the new `CsvSmokeTest`, which reads two events through rapidcsv. GoogleTest was upgraded from v1.14.0 (Lab-03) to v1.17.0 and the Lab-03 tests still pass. The smoke test first crashed because an old MinGW runtime (GCC 6.3) was found first on PATH; putting `/c/msys64/ucrt64/bin` first fixed it.