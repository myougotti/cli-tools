# Header-only common utility library
add_library(cli_common INTERFACE)
target_include_directories(cli_common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# mini-grep
add_executable(mini-grep grep/main.cpp)
target_link_libraries(mini-grep PRIVATE cli_common)

# mini-wc
add_executable(mini-wc wc/main.cpp)
target_link_libraries(mini-wc PRIVATE cli_common)

# mini-tree
add_executable(mini-tree tree/main.cpp)
target_link_libraries(mini-tree PRIVATE cli_common)
