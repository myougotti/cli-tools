#include "common.hpp"

#include <filesystem>
#include <iostream>
#include <string>
#include <system_error>

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    const std::string root = (argc >= 2) ? argv[1] : ".";

    std::error_code ec;
    if (!fs::exists(root, ec) || !fs::is_directory(root, ec)) {
        std::cerr << "mini-tree: not a directory: '" << root << "'\n";
        return 1;
    }

    std::cout << root << "\n";
    fs::recursive_directory_iterator it(root, fs::directory_options::skip_permission_denied, ec);
    if (ec) {
        std::cerr << "mini-tree: " << ec.message() << "\n";
        return 1;
    }
    for (auto end = fs::recursive_directory_iterator(); it != end; it.increment(ec)) {
        if (ec) {
            std::cerr << "mini-tree: " << ec.message() << "\n";
            ec.clear();
            continue;
        }
        const int depth = it.depth();
        for (int i = 0; i <= depth; ++i) {
            std::cout << "  ";
        }
        std::cout << it->path().filename().string();
        if (it->is_directory(ec)) {
            std::cout << "/";
        }
        std::cout << "\n";
    }
    return 0;
}
