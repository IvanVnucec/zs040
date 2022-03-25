set(EXAMPLE_PROJECT_NAME "example")

add_executable(${EXAMPLE_PROJECT_NAME})

target_sources(${EXAMPLE_PROJECT_NAME} PRIVATE example.c)

target_link_libraries(${EXAMPLE_PROJECT_NAME} PRIVATE zs040)
