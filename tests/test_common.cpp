#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "common.hpp"

#include <sstream>

TEST_CASE("count_lines counts every newline-terminated line") {
    std::istringstream in("one\ntwo\nthree\n");
    CHECK(cli::count_lines(in) == 3);
}

TEST_CASE("count_lines counts final unterminated line") {
    std::istringstream in("one\ntwo\nthree");
    CHECK(cli::count_lines(in) == 3);
}

TEST_CASE("count_lines returns zero for empty input") {
    std::istringstream in("");
    CHECK(cli::count_lines(in) == 0);
}

TEST_CASE("count_words splits on whitespace") {
    std::istringstream in("  alpha   beta\tgamma\ndelta ");
    CHECK(cli::count_words(in) == 4);
}

TEST_CASE("count_bytes returns total byte count") {
    std::istringstream in("hello");
    CHECK(cli::count_bytes(in) == 5);
}

TEST_CASE("trim strips leading and trailing whitespace") {
    CHECK(cli::trim("   hello   ") == "hello");
    CHECK(cli::trim("\t\nhello world\n") == "hello world");
    CHECK(cli::trim("nostrip") == "nostrip");
    CHECK(cli::trim("   ").empty());
    CHECK(cli::trim("").empty());
}
