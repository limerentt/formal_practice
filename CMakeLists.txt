cmake_minimum_required(VERSION 3.21)
project(formal_practice)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS --coverage)

add_executable(main_test tests/local_test.cpp src/Max_substring.cpp
            src/Max_substring.h)

add_executable(unit_tests tests/tests.cpp src/Max_substring.cpp
        src/Max_substring.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
enable_testing()

target_link_libraries(
        unit_tests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
