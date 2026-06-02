#include "common.hpp"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <string_view>

namespace {

int print_usage() {
    std::cerr << "usage: mini-grep -e PATTERN FILE\n";
    return 2;
}

} // namespace

int main(int argc, char** argv) {
    if (argc < 4) {
        return print_usage();
    }
    std::string_view flag = argv[1];
    if (flag != "-e") {
        return print_usage();
    }
    const std::string pattern = argv[2];
    const std::string path = argv[3];

    std::ifstream in(path);
    if (!in) {
        std::cerr << "mini-grep: cannot open '" << path << "'\n";
        return 1;
    }

    std::regex re;
    try {
        re = std::regex(pattern);
    } catch (const std::regex_error& e) {
        std::cerr << "mini-grep: bad regex: " << e.what() << "\n";
        return 2;
    }

    std::string line;
    int matched = 0;
    while (std::getline(in, line)) {
        if (std::regex_search(line, re)) {
            std::cout << line << "\n";
            ++matched;
        }
    }
    return matched > 0 ? 0 : 1;
}
