// SPDX-License-Identifier: MIT
// Copyright (c) 2026 ITC Club Hub contributors

#include <iostream>

#include "clubhub/banner.hpp"

int main()
{
    std::cout << clubhub::banner(clubhub::kTeamName);
    std::cout << "Commands arrive in a later lab. Bye!\n";
    return 0;
}