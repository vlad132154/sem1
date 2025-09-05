cmake_minimum_required(VERSION 3.15)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(ClassroomProject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Main project
add_executable(${PROJECT_NAME} src/main.cpp)

# Tests settings
enable_testing()

# GTest find
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# Executable file of tests
add_executable(tests tests/unit_tests.cpp)

# Correct GTest linking
target_link_libraries(tests PRIVATE
    GTest::GTest
    GTest::Main
    Threads::Threads
)

# Add  test
add_test(NAME unit_tests COMMAND tests)

# Code coverage (only for Clang)
option(CODE_COVERAGE "Enable coverage" OFF)
if(CODE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options(tests PRIVATE -fprofile-instr-generate -fcoverage-mapping)
        target_link_options(tests PRIVATE -fprofile-instr-generate)
    endif()
endif()