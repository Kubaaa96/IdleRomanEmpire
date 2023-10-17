cmake_minimum_required(VERSION 3.16)

set(CONAN_SYSTEM_INCLUDES ON)
include(${CMAKE_SOURCE_DIR}/cmake/CMakeUtils.cmake)

project(IdleRomanEmpire VERSION 0.0.1 DESCRIPTION "" LANGUAGES CXX)

initialize_conan()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("NOT RELEASE mode - testing enabled, benchmarks disabled")
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
else ()
    message("RELEASE mode - testing disabled, benchmarks enabled")
    add_subdirectory(benchmarks)
endif ()
