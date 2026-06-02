#include "common.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace {

struct Counts {
    std::size_t lines = 0;
    std::size_t words = 0;
    std::size_t bytes = 0;
};

Counts count_stream(std::istream& in) {
    Counts c;
    std::string line;
    bool in_word = false;
    char ch = 0;
    while (in.get(ch)) {
        ++c.bytes;
        if (ch == '\n') {
            ++c.lines;
        }
        bool ws = (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v');
        if (!ws && !in_word) {
            ++c.words;
            in_word = true;
        } else if (ws) {
            in_word = false;
        }
    }
    return c;
}

void print(const Counts& c, const std::string& name) {
    std::cout << "  " << c.lines << "  " << c.words << "  " << c.bytes;
    if (!name.empty()) {
        std::cout << " " << name;
    }
    std::cout << "\n";
}

} // namespace

int main(int argc, char** argv) {
    if (argc < 2) {
        Counts c = count_stream(std::cin);
        print(c, "");
        return 0;
    }

    Counts total;
    for (int i = 1; i < argc; ++i) {
        std::ifstream in(argv[i]);
        if (!in) {
            std::cerr << "mini-wc: cannot open '" << argv[i] << "'\n";
            return 1;
        }
        Counts c = count_stream(in);
        print(c, argv[i]);
        total.lines += c.lines;
        total.words += c.words;
        total.bytes += c.bytes;
    }
    if (argc > 2) {
        print(total, "total");
    }
    return 0;
}
