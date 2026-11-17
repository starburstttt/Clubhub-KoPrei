cmake_minimum_required(VERSION 3.28)
project(clubhub VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Core: domain model and rules (Lab 2 event core) + console output (Lab 3)
add_library(clubhub_core
    src/event.cpp
    src/event_csv.cpp
    src/ConsoleOutput.cpp)
target_include_directories(clubhub_core PUBLIC include)
target_compile_definitions(clubhub_core
    PRIVATE CLUBHUB_VERSION="${PROJECT_VERSION}")
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Executable: the command-line front end (Lab 2 CLI path)
add_executable(clubhub src/cli/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)

# Reused libraries (Lab 4): both declared BEFORE MakeAvailable
include(FetchContent)

# Reuse 1: GoogleTest (BSD-3-Clause), unit-test framework.
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Reuse 2: rapidcsv (BSD-3-Clause), header-only CSV reader.
FetchContent_Declare(rapidcsv
    GIT_REPOSITORY https://github.com/d99kris/rapidcsv.git
    GIT_TAG        v8.90
    GIT_SHALLOW    TRUE)

FetchContent_MakeAvailable(googletest rapidcsv)

# Tests (Lab 3)
enable_testing()
include(GoogleTest)

add_executable(console_output_tests tests/ConsoleOutputTest.cpp)
target_link_libraries(console_output_tests PRIVATE clubhub_core GTest::gtest_main)
gtest_discover_tests(console_output_tests)

# add Student.cpp to the library, not the executable
target_sources(clubhub_core PRIVATE src/Student.cpp)
target_include_directories(clubhub_core PUBLIC include)

# new test executable
add_executable(student_privacy_tests tests/StudentPrivacyTest.cpp)
target_link_libraries(student_privacy_tests PRIVATE clubhub_core GTest::gtest_main)
gtest_discover_tests(student_privacy_tests)

# Smoke test (Lab 4): proves the reused CSV library is fetched, built and linked
add_executable(csv_smoke_test tests/csv_smoke_test.cpp)
target_link_libraries(csv_smoke_test PRIVATE rapidcsv GTest::gtest_main)
gtest_discover_tests(csv_smoke_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})