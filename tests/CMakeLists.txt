include(FetchContent)
FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest.git
  GIT_TAG v2.4.11
)
FetchContent_MakeAvailable(doctest)

add_executable(test_common test_common.cpp)
target_link_libraries(test_common PRIVATE cli_common doctest)
add_test(NAME test_common COMMAND test_common)
