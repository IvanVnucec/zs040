include(CheckCXXCompilerFlag)

add_subdirectory(gtest)

set(TEST_MAIN_SRC test_main.cc)
add_library(test_main STATIC ${TEST_MAIN_SRC})
target_include_directories(test_main PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_link_libraries(test_main gtest zs040)

function(add_zs040_executable name)
    add_executable(${name} ${ARGN})
endfunction()

# Adds a test.
# Usage: add_zs040_test(name srcs...)
function(add_zs040_test name)
    cmake_parse_arguments(ADD_ZS040_TEST "HEADER_ONLY;MODULE" "" "" ${ARGN})

    set(sources ${name}.cc ${ADD_ZS040_TEST_UNPARSED_ARGUMENTS})
    set(libs test_main zs040)
    add_zs040_executable(${name} ${sources})
    target_link_libraries(${name} ${libs})

    add_test(NAME ${name} COMMAND ${name})
endfunction()

add_zs040_test(test_zs040_init)
