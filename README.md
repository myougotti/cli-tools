# cli-tools

A small collection of POSIX-style command-line utilities reimplemented in
modern C++20: `mini-grep`, `mini-wc`, and `mini-tree`. The point is to
exercise argument parsing, file I/O, regex, and `std::filesystem` end-to-end
while sharing a small header-only utility library across binaries.

## Build & run

```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Binaries land in `build/src/`:

```sh
./build/src/mini-grep -e 'TODO' src/common.hpp
./build/src/mini-wc src/common.hpp
./build/src/mini-tree .
```

## Status

Scaffold only — implementation in progress. Functionality is intentionally
minimal: `mini-grep` does fixed-flag `-e PATTERN FILE`, `mini-wc` matches
`wc -lwc`, `mini-tree` is a simple recursive lister. Future work: globs,
color output, `-r`, large-file handling, fuzz tests.

## Skills demonstrated

- Idiomatic modern C++20 (RAII, `std::string_view`, `std::filesystem`)
- Multi-binary CMake project with a shared header-only library
- Unit tests via [doctest](https://github.com/doctest/doctest) wired through
  `FetchContent` and `ctest`
- Cross-compiler CI (gcc + clang) via GitHub Actions
- Regex with `std::regex`

## Relevant libraries (awesome-cpp)

- [CLI](https://github.com/fffaraz/awesome-cpp/blob/master/README.md#cli)
- [Regular Expression](https://github.com/fffaraz/awesome-cpp/blob/master/README.md#regular-expression)

## License

MIT — see [LICENSE](LICENSE)
