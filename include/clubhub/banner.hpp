// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors

#pragma once

#include <string>
#include <string_view>

namespace clubhub
{

    // The team name printed at start-up. TODO: your team name.
    inline constexpr std::string_view kTeamName = "KoPrei";

    // Returns the start-up banner, one line per row, ending in '\n'.
    [[nodiscard]] std::string banner(std::string_view teamName);

} // namespace clubhub