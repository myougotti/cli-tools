#pragma once

#include <cctype>
#include <cstddef>
#include <istream>
#include <sstream>
#include <string>
#include <string_view>

namespace cli {

// Counts newline-terminated lines in the stream. If the final line has no
// trailing newline it is still counted. Restores the stream's read position.
inline std::size_t count_lines(std::istream& in) {
    std::size_t lines = 0;
    std::string buf;
    while (std::getline(in, buf)) {
        ++lines;
    }
    return lines;
}

// Counts whitespace-separated tokens.
inline std::size_t count_words(std::istream& in) {
    std::size_t words = 0;
    std::string tok;
    while (in >> tok) {
        ++words;
    }
    return words;
}

// Counts every byte read from the stream.
inline std::size_t count_bytes(std::istream& in) {
    std::size_t bytes = 0;
    char c = 0;
    while (in.get(c)) {
        ++bytes;
    }
    return bytes;
}

// Returns a view with leading/trailing ASCII whitespace removed.
inline std::string_view trim(std::string_view s) {
    auto is_ws = [](unsigned char c) { return std::isspace(c) != 0; };
    while (!s.empty() && is_ws(static_cast<unsigned char>(s.front()))) {
        s.remove_prefix(1);
    }
    while (!s.empty() && is_ws(static_cast<unsigned char>(s.back()))) {
        s.remove_suffix(1);
    }
    return s;
}

} // namespace cli
