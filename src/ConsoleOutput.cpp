// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors

#include "clubhub/ConsoleOutput.h"

#include <cstdlib>
#include <string>

namespace clubhub {

std::string_view statusLabel(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered: return "REGISTERED";
        case RegistrationStatus::Cancelled:  return "CANCELLED";
        case RegistrationStatus::CheckedIn:  return "CHECKED IN";
        case RegistrationStatus::Waitlisted: return "WAITLISTED";
    }
    return "UNKNOWN";
}

bool colourEnabled(bool noColorFlag) {
    if (noColorFlag) return false;
    const char* env = std::getenv("NO_COLOR");
    // no-color.org: any non-empty value disables colour
    return !(env != nullptr && env[0] != '\0');
}

namespace {
const char* ansiCode(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered: return "\033[32m";  // green
        case RegistrationStatus::Cancelled:  return "\033[31m";  // red
        case RegistrationStatus::CheckedIn:  return "\033[36m";  // cyan
        case RegistrationStatus::Waitlisted: return "\033[33m";  // yellow
    }
    return "";
}
}  // namespace

std::string formatStatus(RegistrationStatus s, bool colour) {
    std::string text = "[" + std::string(statusLabel(s)) + "]";
    if (!colour) return text;
    return std::string(ansiCode(s)) + text + "\033[0m";
}

std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next) {
    std::string out = "Error: ";
    out += what;
    out += ": ";
    out += why;
    out += ".\nNext step: ";
    out += next;
    return out;
}

}  // namespace clubhub