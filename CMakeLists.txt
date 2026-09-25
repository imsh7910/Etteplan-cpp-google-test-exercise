cmake_minimum_required(VERSION 3.20)
project(temperature_validator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(temperature_validator src/temperature_validator.cpp)
target_include_directories(temperature_validator PUBLIC include)
if(MSVC)
    target_compile_options(temperature_validator PRIVATE /W4)
else()
    target_compile_options(temperature_validator PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(temperature_validator_tests tests/temperature_validator_test.cpp)
target_link_libraries(temperature_validator_tests PRIVATE temperature_validator GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(temperature_validator_tests DISCOVERY_MODE PRE_TEST)
