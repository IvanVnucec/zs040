cmake_minimum_required(VERSION 3.15)

set(namespace "zs040")
project("zs040"
    VERSION 1.0.1
    DESCRIPTION "ZS040 library"
)

# Determine if ZS040 is built as a subproject (using add_subdirectory)
# or if it is the master project.
if (NOT DEFINED ZS040_MASTER_PROJECT)
    set(ZS040_MASTER_PROJECT OFF)
    if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        set(ZS040_MASTER_PROJECT ON)
        message(STATUS "CMake version: ${CMAKE_VERSION}")
    endif ()
endif ()

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED OFF)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/zs040.c
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(CMAKE_COMPILER_IS_GNUCXX)
    # compile options for this target only
    # treat warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror)
endif()

option(ZS040_TEST "Generate the test target." ${ZS040_MASTER_PROJECT})

if (ZS040_TEST)
    enable_testing()
    add_subdirectory(tests)
endif ()
