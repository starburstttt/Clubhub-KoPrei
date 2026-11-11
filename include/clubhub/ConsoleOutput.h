// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors

#pragma once

#include <string>
#include <string_view>

namespace clubhub {

// Not defined elsewhere in the repo, so it is declared here.
enum class RegistrationStatus { Registered, Cancelled, CheckedIn, Waitlisted };

// Upper-case word for a status: "REGISTERED", "CHECKED IN", ...
std::string_view statusLabel(RegistrationStatus s);

// false when the --no-color flag is set or NO_COLOR exists (no-color.org)
bool colourEnabled(bool noColorFlag);

// "[CANCELLED]", wrapped in ANSI colour codes only if colour is true
std::string formatStatus(RegistrationStatus s, bool colour);

// "Error: <what>: <why>.\nNext step: <next>"
std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next);

}  // namespace clubhub